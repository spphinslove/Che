// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_PlayerController.h"
#include "TDRL_Character.h"
#include "TDRL_PlayerState.h"
#include "TDRL_PlayersSpawn.h"

#include "Net/UnrealNetwork.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

#include "TimerManager.h"

ATDRL_PlayerController::ATDRL_PlayerController()
	: Super()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

bool ATDRL_PlayerController::GetActorsOfClassInRadiusUnderMouse(const TArray<TSubclassOf<AActor>> Classes,
                                                                const float Radius,
                                                                const TArray<TEnumAsByte<EObjectTypeQuery>>& Channels,
                                                                const TArray<AActor*>& IgnoreActors,
                                                                TArray<AActor*>& OutActors, const bool bDebug) const
{
	if (!bBlockingUnderMouse)
	{
		return false;
	}

	TArray<AActor*> TempActorsInSphere;
	for (auto& CClass : Classes)
	{
		TempActorsInSphere.Empty();
		if (UKismetSystemLibrary::SphereOverlapActors(this, LastValidHitUnderMouse.ImpactPoint, Radius, Channels,
		                                              CClass, IgnoreActors, TempActorsInSphere))
		{
			OutActors.Append(TempActorsInSphere);
		}
	}

	if (OutActors.Num() == 0)
	{
		if (bDebug)
		{
			DrawDebugSphere(GetWorld(), LastValidHitUnderMouse.ImpactPoint, Radius, 8, FColor::Red, false, 3.0f, 0,
			                1.0f);
		}

		return false;
	}

	if (bDebug)
	{
		DrawDebugSphere(GetWorld(), LastValidHitUnderMouse.ImpactPoint, Radius, 8, FColor::Green, false, 3.0f, 0, 1.0f);
	}

	return true;
}

AActor* ATDRL_PlayerController::GetClosestActorOfClassInRadiusUnderMouse(
	const TArray<TSubclassOf<AActor>> Classes, const float Radius,
	const TArray<TEnumAsByte<EObjectTypeQuery>>& Channels, const TArray<AActor*>& IgnoreActors, const bool bDebug) const
{
	TArray<AActor*> ActorsToCompare = TArray<AActor*>();

	if (!GetActorsOfClassInRadiusUnderMouse(Classes, Radius, Channels, IgnoreActors, ActorsToCompare, bDebug))
	{
		return nullptr;
	}

	float ClosestDistance = FLT_MAX;
	int32 ClosestIndex = -1;
	for (int32 i = 0; i < ActorsToCompare.Num(); i++)
	{
		const float CDistance = FVector::Dist(ActorsToCompare[i]->GetActorLocation(),
		                                      LastValidHitUnderMouse.ImpactPoint);

		if (CDistance < ClosestDistance)
		{
			ClosestDistance = CDistance;
			ClosestIndex = i;
		}
	}

	if (ClosestIndex < 0)
	{
		return nullptr;
	}

	if (bDebug)
	{
		for (int32 i = 0; i < ActorsToCompare.Num(); i++)
		{
			DrawDebugLine(GetWorld(), ActorsToCompare[i]->GetActorLocation(), LastValidHitUnderMouse.ImpactPoint,
			              (i == ClosestIndex) ? FColor::Green : FColor::Orange, false, 3.0f, 0, 2.0f);
		}
	}

	return ActorsToCompare[ClosestIndex];
}

#pragma region ControlRotation

EControlRotationType ATDRL_PlayerController::GetControlRotationType() const
{
	return ControlRotationType;
}

void ATDRL_PlayerController::SetControlRotationType(const EControlRotationType NewValue)
{
	ControlRotationType = NewValue;
}

FVector ATDRL_PlayerController::GetLocationTarget() const
{
	return LocationTarget;
}

void ATDRL_PlayerController::SetLocationTarget(const FVector TargetLocation)
{
	LocationTarget = TargetLocation;
}

#pragma endregion

#pragma region LockTarget

AActor* ATDRL_PlayerController::GetLockedTarget() const
{
	return LockedTarget;
}

void ATDRL_PlayerController::SetLockedTarget(AActor* NewTarget)
{
	LockedTarget = NewTarget;
}

#pragma endregion

#pragma region Possess

void ATDRL_PlayerController::TDRLCharacterChanged_Server_Implementation(APawn* InPawn)
{
	PossessedTDRLCharacter = Cast<ATDRL_Character>(InPawn);
}

#pragma endregion

#pragma region Overrides

void ATDRL_PlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void ATDRL_PlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	TDRLCharacterChanged_Server(InPawn);
}

void ATDRL_PlayerController::OnUnPossess()
{
	Super::OnUnPossess();
	TDRLCharacterChanged_Server(nullptr);
}

void ATDRL_PlayerController::BeginPlayingState()
{
	Super::BeginPlayingState();
}

void ATDRL_PlayerController::AcknowledgePossession(APawn* InPawn)
{
	Super::AcknowledgePossession(InPawn);
}

void ATDRL_PlayerController::ServerAcknowledgePossession_Implementation(APawn* InPawn)
{
	Super::ServerAcknowledgePossession_Implementation(InPawn);
}

void ATDRL_PlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateTraceUnderMouse();
	UpdateControlRotation();

	if (!GetPawn())
	{
		return;
	}

	TArray<AActor*> AttachedToPawn;
	GetPawn()->GetAttachedActors(AttachedToPawn, true, true);
	AttachedToPawn.Add(GetPawn());

	if (LastValidHitUnderMouse.bBlockingHit && !AttachedToPawn.Contains(LastValidHitUnderMouse.GetActor()))
	{
		FRotator AimRot = FRotator(0.0f);

		switch (ControlRotationType)
		{
		case EControlRotationType::UnderMouse:
			AimRot = UKismetMathLibrary::FindLookAtRotation(GetPawn()->GetActorLocation(),
			                                                LastValidHitUnderMouse.Location) - GetPawn()->
				GetActorRotation();
			break;
		case EControlRotationType::LockedTarget:
			if (!LockedTarget)
			{
				return;
			}
			AimRot = UKismetMathLibrary::FindLookAtRotation(GetPawn()->GetActorLocation(),
			                                                LockedTarget->GetActorLocation()) - GetPawn()->
				GetActorRotation();
			break;
		case EControlRotationType::TargetLocation:
			AimRot = UKismetMathLibrary::FindLookAtRotation(GetPawn()->GetActorLocation(), GetLocationTarget()) -
				GetPawn()->GetActorRotation();
			break;
		}

		UpdateAimOffsetValue(FVector2D(AimRot.Yaw, (bShouldUsePitch) ? AimRot.Pitch : 0.0f));
	}
}

void ATDRL_PlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ATDRL_PlayerController, PossessedTDRLCharacter);
	DOREPLIFETIME(ATDRL_PlayerController, LatestValidStartTag);
}

#pragma endregion

#pragma region TickUpdates

void ATDRL_PlayerController::UpdateTraceUnderMouse()
{
	FHitResult TempResult = FHitResult();
	bBlockingUnderMouse = GetHitResultUnderCursorByChannel(
		UEngineTypes::ConvertToTraceType(ECollisionChannel::ECC_Visibility), false, TempResult);

	if (TempResult.bBlockingHit)
	{
		LastValidHitUnderMouse = TempResult;
	}
}

void ATDRL_PlayerController::UpdateControlRotation()
{
	if (!GetPawn())
	{
		return;
	}

	if (!PossessedTDRLCharacter)
	{
		if (!GetCharacter() || !bBlockingUnderMouse)
		{
			return;
		}

		if (!GetPawn()->GetClass()->IsChildOf(ATDRL_Character::StaticClass()))
		{
			return;
		}
	}

	FRotator NewRotation = FRotator::ZeroRotator;
	float MouseTargetRot = 0.0f;
	TArray<AActor*> AttachedToCharacter;
	GetPawn()->GetAttachedActors(AttachedToCharacter, true, true);

	switch (ControlRotationType)
	{
	case EControlRotationType::UnderMouse:
		if (LastValidHitUnderMouse.bBlockingHit)
		{
			if (LastValidHitUnderMouse.GetActor() == GetPawn() || AttachedToCharacter.Contains(
				LastValidHitUnderMouse.GetActor()))
			{
				return;
			}
		}

		NewRotation = FRotator(
			0.0f, UKismetMathLibrary::FindLookAtRotation(GetPawn()->GetActorLocation(), LastValidHitUnderMouse.Location)
			.Yaw, 0.0f);

		if (MouseTargetRot < 0.0f)
		{
			NewRotation.Yaw = NewRotation.Yaw + 360.0f;
		}

		break;

	case EControlRotationType::LockedTarget:
		if (!GetLockedTarget())
		{
			return;
		}

		NewRotation = UKismetMathLibrary::MakeRotFromX(
			UKismetMathLibrary::GetDirectionUnitVector(GetPawn()->GetActorLocation(),
			                                           GetLockedTarget()->GetActorLocation()));
		break;

	case EControlRotationType::TargetLocation:
		NewRotation = UKismetMathLibrary::FindLookAtRotation(GetPawn()->GetActorLocation(), GetLocationTarget()) -
			GetPawn()->GetActorRotation();
	}

	SetControlRotation(NewRotation);
}

#pragma endregion

#pragma region Aim Offset

void ATDRL_PlayerController::UpdateAimOffsetValue(const FVector2D NewValue)
{
	if (!PossessedTDRLCharacter)
	{
		return;
	}

	PossessedTDRLCharacter->AimOffsetValue = NewValue;

	if (!UpdateAimOffsetServerHandle.IsValid())
	{
		UpdateAimOffsetValue_Serv(NewValue);
		GetWorld()->GetTimerManager().SetTimer(UpdateAimOffsetServerHandle, this,
		                                       &ATDRL_PlayerController::UpdateOnServerTimerOver, AimOffsetUpdateTime,
		                                       false);
	}
}

void ATDRL_PlayerController::UpdateAimOffsetValue_Serv_Implementation(const FVector2D NewValue)
{
	if (!PossessedTDRLCharacter)
	{
		return;
	}

	PossessedTDRLCharacter->AimOffsetValue = NewValue;
}

void ATDRL_PlayerController::UpdateOnServerTimerOver()
{
	if (UpdateAimOffsetServerHandle.IsValid())
	{
		UpdateAimOffsetServerHandle.Invalidate();
	}
}

#pragma endregion

#pragma region Cosmetics

FCosmeticParameterList ATDRL_PlayerController::GetDefaultCharacterCosmetic()
{
	return UnloadedCosmeticParameter;
}

#pragma endregion

#pragma region Spawn

void ATDRL_PlayerController::PlayersSpawnAreaOverlapped_Implementation(ATDRL_PlayersSpawn* Spawner)
{
}

#pragma endregion
