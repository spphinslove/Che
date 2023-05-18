// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_CharacterMovementComponent.h"
#include "TDRL_PhysicsDoor.h"
#include "TDRL_GameplayTypes.h"

#include "NiagaraFunctionLibrary.h"

#include "GameFramework/Character.h"
#include "GameFramework/InputSettings.h"
#include "GameFramework/PlayerController.h"

#include "Engine/World.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

#include "Net/UnrealNetwork.h"
#include "TimerManager.h"

UTDRL_CharacterMovementComponent::UTDRL_CharacterMovementComponent()
	: Super()
{
	// Override default values
	DashRequired = false;
	AlternativeWalkRequired = false;
	BrakingFriction = 1.0f;
	AirControl = 0.45f;
	RotationRate = FRotator(0.0f, 1280.0f, 0.0f);
	bUseControllerDesiredRotation = true;
	GetNavAgentPropertiesRef().bCanCrouch = true;
	bCanWalkOffLedgesWhenCrouching = true;
	bUseSeparateBrakingFriction = true;
	GravityScale = 4.0f;
	DashEffects = FDashEffect();
}

FNetworkPredictionData_Client* UTDRL_CharacterMovementComponent::GetPredictionData_Client() const
{
	if (ClientPredictionData == nullptr)
	{
		// Return our custom client prediction class instead
		UTDRL_CharacterMovementComponent* MutableThis = const_cast<UTDRL_CharacterMovementComponent*>(this);
		MutableThis->ClientPredictionData = new FNetworkPredictionData_Client_My(*this);
	}

	return ClientPredictionData;
}

void UTDRL_CharacterMovementComponent::OnRep_WantsToDash(const bool OldValue)
{
	if (WantsToDash)
	{
		if (GetOwnerRole() == ENetRole::ROLE_SimulatedProxy)
		{
			SpawnDashEffects();
		}
	}
}

float UTDRL_CharacterMovementComponent::GetRemainingDashCD() const
{
	if (DashTimerHandle.IsValid())
	{
		return GetWorld()->GetTimerManager().GetTimerRemaining(DashTimerHandle);
	}
	return 0.0f;
}

float UTDRL_CharacterMovementComponent::GetRemainingDashCDPercent() const
{
	if (DashTimerHandle.IsValid())
	{
		return GetWorld()->GetTimerManager().GetTimerElapsed(DashTimerHandle) / DashCountdown;
	}
	return 1.0f;
}

void UTDRL_CharacterMovementComponent::SetAlternativeWalk(const bool Enable)
{
	if (IsDashing())
	{
		return;
	}

	AlternativeWalkRequired = Enable;
}

void UTDRL_CharacterMovementComponent::Dash(const bool Enable)
{
	if (Enable)
	{
		if (IsFalling() || IsCrouching() || DashCount >= MaxDash || MovementMode == MOVE_Custom)
		{
			return;
		}

		if (DashPast > 0.0f)
		{
			return;
		}
	}
	else
	{
		DashPast = 0.0f;
	}

	DashRequired = Enable;
}

void UTDRL_CharacterMovementComponent::DashCDReset()
{
	DashCount = 0;

	if (DashTimerHandle.IsValid())
	{
		GetWorld()->GetTimerManager().ClearTimer(DashTimerHandle);
		DashTimerHandle.Invalidate();
	}
}

FVector UTDRL_CharacterMovementComponent::FindDashDirection() const
{
	return Acceleration.GetSafeNormal();
}

bool UTDRL_CharacterMovementComponent::IsCustomMovementMode(uint8 custom_movement_mode) const
{
	return MovementMode == EMovementMode::MOVE_Custom && CustomMovementMode == custom_movement_mode;
}

void UTDRL_CharacterMovementComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UTDRL_CharacterMovementComponent::OnComponentDestroyed(bool bDestroyingHierarchy)
{
	Super::OnComponentDestroyed(bDestroyingHierarchy);
}

void UTDRL_CharacterMovementComponent::SpawnDashEffects()
{
	if (DashEffects.NiagaraEffect)
	{
		UNiagaraFunctionLibrary::SpawnSystemAttached(
			DashEffects.NiagaraEffect,
			GetPawnOwner()->GetRootComponent(),
			FName(),
			GetPawnOwner()->GetActorLocation(),
			GetPawnOwner()->GetActorRotation(),
			EAttachLocation::KeepWorldPosition,
			true,
			true);
	}

	if (DashEffects.ParticleEffect)
	{
		UGameplayStatics::SpawnEmitterAttached(
			DashEffects.ParticleEffect,
			GetPawnOwner()->GetRootComponent(),
			FName(),
			GetPawnOwner()->GetActorLocation(),
			GetPawnOwner()->GetActorRotation(),
			EAttachLocation::KeepWorldPosition,
			true,
			EPSCPoolMethod::None,
			true);
	}

	if (DashEffects.SoundEffect)
	{
		UGameplayStatics::SpawnSoundAttached((USoundBase*)DashEffects.SoundEffect, GetPawnOwner()->GetRootComponent());
	}
}

void UTDRL_CharacterMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType,
                                                     FActorComponentTickFunction* ThisTickFunction)
{
	if (WantsToDash)
	{
		if (!IsCustomMovementMode(ECustomMovementMode::CMOVE_Dash) && !FindDashDirection().IsNearlyZero(.1f))
		{
			// Set the movement mode to wall running. UE4 will handle replicating this change to all connected clients.
			SetMovementMode(EMovementMode::MOVE_Custom, ECustomMovementMode::CMOVE_Dash);
		}
	}
	else
	{
		if (IsCustomMovementMode(ECustomMovementMode::CMOVE_Dash))
		{
			// Set the movement mode back to falling
			SetMovementMode(EMovementMode::MOVE_Falling);
		}
	}

	// Peform local only checks
	if (GetPawnOwner()->IsLocallyControlled())
	{
		WantsToAlternativeWalk = AlternativeWalkRequired;
		WantsToDash = DashRequired;
	}

	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTDRL_CharacterMovementComponent::UpdateFromCompressedFlags(uint8 Flags)
{
	Super::UpdateFromCompressedFlags(Flags);

	/*  There are 4 custom move flags for us to use. Below is what each is currently being used for:
		FLAG_Custom_0		= 0x10, // Walk
		FLAG_Custom_1		= 0x20, // Dash
		FLAG_Custom_2		= 0x40, // Unused
		FLAG_Custom_3		= 0x80, // Unused
	*/

	// Read the values from the compressed flags
	WantsToAlternativeWalk = (Flags & FSavedMove_Character::FLAG_Custom_0) != 0;
	WantsToDash = (Flags & FSavedMove_Character::FLAG_Custom_1) != 0;
}

void UTDRL_CharacterMovementComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UTDRL_CharacterMovementComponent, WantsToDash, COND_SimulatedOnly,
	                               REPNOTIFY_OnChanged);
}

void UTDRL_CharacterMovementComponent::OnMovementModeChanged(EMovementMode PreviousMovementMode,
                                                             uint8 PreviousCustomMode)
{
	if (MovementMode == MOVE_Custom)
	{
		switch (CustomMovementMode)
		{
		// Did we just start dashing
		case ECustomMovementMode::CMOVE_Dash:
			{
				DashDirection = FindDashDirection();
				DashCount += 1;

				if (GetOwnerRole() != ENetRole::ROLE_SimulatedProxy)
				{
					SpawnDashEffects();
				}
			}
			break;
		}
	}

	if (PreviousMovementMode == MOVE_Custom)
	{
		switch (PreviousCustomMode)
		{
		// Did we just finish dashing?
		case ECustomMovementMode::CMOVE_Dash:
			{
				DashRequired = false;
			}
			break;
		}
	}

	Super::OnMovementModeChanged(PreviousMovementMode, PreviousCustomMode);
}

void UTDRL_CharacterMovementComponent::PhysCustom(float deltaTime, int32 Iterations)
{
	// Phys* functions should only run for characters with ROLE_Authority or ROLE_AutonomousProxy. However, Unreal calls PhysCustom in
	// two seperate locations, one of which doesn't check the role, so we must check it here to prevent this code from running on simulated proxies.
	if (GetOwner()->GetLocalRole() == ROLE_SimulatedProxy)
		return;

	switch (CustomMovementMode)
	{
	case ECustomMovementMode::CMOVE_Dash:
		{
			DashAction(deltaTime, Iterations);
			break;
		}
	}

	// Not sure if this is needed
	Super::PhysCustom(deltaTime, Iterations);
}

void UTDRL_CharacterMovementComponent::DashAction(float deltaTime, int32 Iterations)
{
	// IMPORTANT NOTE: This function (and all other Phys* functions) will be called on characters with ROLE_Authority and ROLE_AutonomousProxy
	// but not ROLE_SimulatedProxy. All movement should be performed in this function so that is runs locally and on the server. UE4 will handle
	// replicating the final position, velocity, etc.. to the other simulated proxies.


	//FHitResult GroundTraceHit(1.f);
	FHitResult ForwardGroundTraceHit(1.f);
	FHitResult ObstructionCheck(1.f);
	FCollisionQueryParams QParam;
	TArray<AActor*> Ignoring;
	GetOwner()->GetAttachedActors(Ignoring);
	Ignoring.Add(GetOwner());
	QParam.AddIgnoredActors(Ignoring);

	FCollisionObjectQueryParams QOParam = FCollisionObjectQueryParams::DefaultObjectQueryParam;

	for (auto Iter = DashGroundTestChannels.CreateConstIterator(); Iter; ++Iter)
	{
		const ECollisionChannel& Channel = UCollisionProfile::Get()->ConvertToCollisionChannel(false, *Iter);
		QOParam.AddObjectTypesToQuery(Channel);
	}

	GetWorld()->LineTraceSingleByObjectType(ForwardGroundTraceHit,
	                                        GetActorFeetLocation() + (DashDirection * DashSpeed * deltaTime *
		                                        FVector(1.0f, 1.0f, 0.0f)) + FVector(0.0f, 0.0f, MaxStepHeight * 2.0f),
	                                        GetActorFeetLocation() + (DashDirection * DashSpeed * deltaTime *
		                                        FVector(1.0f, 1.0f, 0.0f)) - FVector(0.0f, 0.0f, MaxStepHeight * 2.0f),
	                                        QOParam, QParam);

	FVector NewDir = DashDirection;
	if (ForwardGroundTraceHit.bBlockingHit &&
		!ForwardGroundTraceHit.bStartPenetrating &&
		FMath::Abs(ForwardGroundTraceHit.ImpactNormal.Z) > GetWalkableFloorAngle() / 90.0f)
	{
		NewDir = UKismetMathLibrary::GetDirectionUnitVector(GetActorFeetLocation(),
		                                                    ForwardGroundTraceHit.Location + FVector(0.0f, 0.0f, 5.0f));
		if (bShowVisualDebug)
		{
			DrawDebugSphere(GetWorld(), ForwardGroundTraceHit.Location, 16.0f, 6, FColor::Blue, false, 10.0f);
		}

		Velocity = NewDir * DashSpeed;
	}
	else
	{
		DashPast = 0.0f;
		Dash(false);
		return;
	}

	const FVector Adjusted = Velocity * deltaTime;

	if (GetPawnOwner()->GetLocalRole() == ENetRole::ROLE_Authority)
	{
		TArray<FHitResult> HitByDash = TArray<FHitResult>();
		QParam = FCollisionQueryParams::DefaultQueryParam;
		QOParam = FCollisionObjectQueryParams();

		for (auto Iter = TraceForActorsPushChannels.CreateConstIterator(); Iter; ++Iter)
		{
			const ECollisionChannel& Channel = UCollisionProfile::Get()->ConvertToCollisionChannel(false, *Iter);
			QOParam.AddObjectTypesToQuery(Channel);
		}

		TArray<AActor*> PushIgnore = TArray<AActor*>{GetOwner()};
		GetOwner()->GetAttachedActors(PushIgnore, false, true);
		QParam.AddIgnoredActors(PushIgnore);

		GetWorld()->SweepMultiByObjectType(HitByDash, GetActorLocation(), GetActorLocation() + Adjusted,
		                                   FQuat::Identity, QOParam,
		                                   FCollisionShape::MakeCapsule(
			                                   GetPawnCapsuleExtent(EShrinkCapsuleExtent::SHRINK_None)), QParam);

		if (bShowVisualDebug)
		{
			DrawDebugCapsule(GetWorld(), GetActorLocation() + Adjusted,
			                 GetPawnCapsuleExtent(EShrinkCapsuleExtent::SHRINK_None).Z,
			                 GetPawnCapsuleExtent(EShrinkCapsuleExtent::SHRINK_None).X, FQuat::Identity,
			                 FColor::Magenta, false, 1.0f);
			DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + Adjusted, FColor::Magenta, false, 1.0);
		}

		for (int32 i = 0; i < HitByDash.Num(); i++)
		{
			if (HitByDash[i].bBlockingHit)
			{
				ATDRL_PhysicsDoor* PhysDoor = Cast<ATDRL_PhysicsDoor>(HitByDash[i].GetActor());

				if (PhysDoor)
				{
					if (PhysDoor->GetIsOpen() && PhysDoor->GetDoorMesh()->IsSimulatingPhysics())
					{
						if (PhysDoor->GetDoorMesh() == HitByDash[i].GetComponent())
						{
							PhysDoor->AddImpulseAtLocation_Multicast(NewDir * DashForce, HitByDash[i].Location);
						}
					}
				}
				else
				{
					if (HitByDash[i].GetComponent()->IsSimulatingPhysics(HitByDash[i].BoneName))
					{
						HitByDash[i].GetComponent()->AddImpulseAtLocation(
							NewDir * DashForce, HitByDash[i].Location, HitByDash[i].BoneName);
					}
				}
			}
		}
	}

	// GetPawnOwner()->GetLocalRole() == ENetRole::ROLE_SimulatedProxy;

	FHitResult Hit(1.f);
	SafeMoveUpdatedComponent(Adjusted, UpdatedComponent->GetComponentQuat(), true, Hit);

	DashPast = DashPast + deltaTime;

	// Make sure the required wall run keys are still down
	if (DashPast >= DashLength)
	{
		Dash(false);
		DashPast = 0.0f;
		return;
	}

	if (DashPast == deltaTime && DashRequired)
	{
		if (true)
		{
			GetWorld()->GetTimerManager().SetTimer(DashTimerHandle, this,
			                                       &UTDRL_CharacterMovementComponent::DashCDReset, DashCountdown, false,
			                                       -1.0f);
		}
	}
}

float UTDRL_CharacterMovementComponent::GetMaxSpeed() const
{
	switch (MovementMode)
	{
	case MOVE_Walking:
	case MOVE_NavWalking:
		{
			if (IsCrouching())
			{
				return MaxWalkSpeedCrouched;
			}
			else
			{
				if (WantsToAlternativeWalk)
				{
					return SpeedB;
				}

				return SpeedA;
			}
		}
	case MOVE_Falling:
		return SpeedA;
	case MOVE_Swimming:
		return MaxSwimSpeed;
	case MOVE_Flying:
		return MaxFlySpeed;
	case MOVE_Custom:
		return MaxCustomMovementSpeed;
	case MOVE_None:
	default:
		return 0.f;
	}
}

float UTDRL_CharacterMovementComponent::GetMaxAcceleration() const
{
	if (IsMovingOnGround())
	{
		if (WantsToAlternativeWalk)
		{
			return AccelerationB;
		}
		else
		{
			if (MovementMode == MOVE_Custom && CustomMovementMode == ECustomMovementMode::CMOVE_Dash)
			{
				return DashAcceleration;
			}
			else
			{
				return AccelerationA;
			}
		}
	}

	return Super::GetMaxAcceleration();
}

void UTDRL_CharacterMovementComponent::ProcessLanded(const FHitResult& Hit, float remainingTime, int32 Iterations)
{
	Super::ProcessLanded(Hit, remainingTime, Iterations);

	DashPast = 0.0f;
	Dash(false);
}

void FSavedMove_My::Clear()
{
	Super::Clear();

	// Clear all values
	SavedWantsToAlternativeWalk = 0;
	SavedWantsToDash = 0;
	SavedDashCount = 0;
}

uint8 FSavedMove_My::GetCompressedFlags() const
{
	uint8 Result = Super::GetCompressedFlags();

	/* There are 4 custom move flags for us to use. Below is what each is currently being used for:
	FLAG_Custom_0		= 0x10, // Walk
	FLAG_Custom_1		= 0x20, // Dash
	FLAG_Custom_2		= 0x40, // Unused
	FLAG_Custom_3		= 0x80, // Unused
	*/

	// Write to the compressed flags 
	if (SavedWantsToAlternativeWalk)
		Result |= FLAG_Custom_0;
	if (SavedWantsToDash)
		Result |= FLAG_Custom_1;

	return Result;
}

bool FSavedMove_My::CanCombineWith(const FSavedMovePtr& NewMovePtr, ACharacter* Character, float MaxDelta) const
{
	const FSavedMove_My* NewMove = static_cast<const FSavedMove_My*>(NewMovePtr.Get());

	// As an optimization, check if the engine can combine saved moves.
	if (SavedWantsToAlternativeWalk != NewMove->SavedWantsToAlternativeWalk ||
		SavedWantsToDash != NewMove->SavedWantsToDash ||
		SavedDashCount != NewMove->SavedDashCount ||
		SavedDashPast != NewMove->SavedDashPast)
	{
		return false;
	}

	return Super::CanCombineWith(NewMovePtr, Character, MaxDelta);
}

void FSavedMove_My::SetMoveFor(ACharacter* Character, float InDeltaTime, FVector const& NewAccel,
                               class FNetworkPredictionData_Client_Character& ClientData)
{
	Super::SetMoveFor(Character, InDeltaTime, NewAccel, ClientData);

	UTDRL_CharacterMovementComponent* charMov = static_cast<UTDRL_CharacterMovementComponent*>(Character->
		GetCharacterMovement());
	if (charMov)
	{
		// Copy values into the saved move
		SavedWantsToAlternativeWalk = charMov->WantsToAlternativeWalk;
		SavedWantsToDash = charMov->WantsToDash;
		SavedDashCount = charMov->DashCount;
		SavedDashPast = charMov->DashPast;
	}
}

void FSavedMove_My::PrepMoveFor(class ACharacter* Character)
{
	Super::PrepMoveFor(Character);

	UTDRL_CharacterMovementComponent* charMov = Cast<UTDRL_CharacterMovementComponent>(
		Character->GetCharacterMovement());
	if (charMov)
	{
		// Copt values out of the saved move
		charMov->WantsToAlternativeWalk = SavedWantsToAlternativeWalk;
		charMov->WantsToDash = SavedWantsToDash;
		charMov->DashCount = SavedDashCount;
		charMov->DashPast = SavedDashPast;
	}
}

FNetworkPredictionData_Client_My::FNetworkPredictionData_Client_My(const UCharacterMovementComponent& ClientMovement)
	: Super(ClientMovement)
{
}

FSavedMovePtr FNetworkPredictionData_Client_My::AllocateNewMove()
{
	return FSavedMovePtr(new FSavedMove_My());
}
