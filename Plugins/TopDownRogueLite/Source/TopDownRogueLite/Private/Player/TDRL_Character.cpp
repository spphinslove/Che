// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_Character.h"
#include "TDRL_CharacterMovementComponent.h"
#include "TDRL_PlayerController.h"
#include "TDRL_NPCController.h"
#include "TDRL_Melee.h"
#include "TDRL_HUD.h"
#include "TDRL_Item.h"
#include "TDRL_Fists.h"
#include "TDRL_Weapon.h"
#include "TDRL_BFL_Global.h"
#include "TDRL_CameraOcclusionComponent.h"
#include "TDRL_LineOfSightComponent.h"
#include "TDRL_DamageType.h"

#include "TDRL_GASGameplayAbility.h"
#include "TDRL_GASAttributeSet.h"
#include "AbilitySystemComponent.h"
#include <GameplayEffectTypes.h>

#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/EngineTypes.h"

#include "Net/UnrealNetwork.h"

#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "..\..\Public\Player\TDRL_Character.h"

/* Generic and overrides */

ATDRL_Character::ATDRL_Character(const FObjectInitializer& ObjInit)
	: Super(ObjInit.SetDefaultSubobjectClass<UTDRL_CharacterMovementComponent>(
		ACharacter::CharacterMovementComponentName))
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bDebugShowTraceForItems = false;
	DefaultWeaponClass = ATDRL_Fists::StaticClass();

	CameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	CameraSpringArm->SetupAttachment(GetRootComponent());
	CameraSpringArm->SetRelativeLocation(FVector(0.0f, 0.0f, 1200.0f));
	CameraSpringArm->TargetArmLength = 1200.0f;
	CameraSpringArm->bDoCollisionTest = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraSpringArm);
	Camera->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
	Camera->FieldOfView = 60.0f;

	AbilityComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilityComponent"));
	AbilityComponent->SetIsReplicated(true);
	AbilityComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UTDRL_GASAttributeSet>(TEXT("AttributeSet"));

	SightComponent = CreateDefaultSubobject<UTDRL_LineOfSightComponent>(TEXT("SightComponent"));
}

void ATDRL_Character::BeginPlay()
{
	Super::BeginPlay();

	SetInventorySlotsAmount(InitialInventorySlots);
	SetHealth(MaxHealth);

	GetCameraSpringArm()->SetWorldRotation(GetActorRotation());

	if (HasAuthority())
	{
		SpawnDefaultWeapon();
	}
}

void ATDRL_Character::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (GetNetMode() != ENetMode::NM_DedicatedServer)
	{
		if (UGameplayStatics::GetPlayerController(this, 0) == NewController)
		{
			GetMesh()->SetCustomDepthStencilValue(254);
			GetCharacterMovement()->SetAvoidanceEnabled(false);
		}
		else
		{
			GetMesh()->SetCustomDepthStencilValue(252);
		}
	}

	if (IsPlayerControlled())
	{
		if (!SightComponent->IsActive())
		{
			SightComponent->Deactivate();
		}

		if (GetLocalRole() == ENetRole::ROLE_Authority)
		{
			EnableTraceForNearbyItems(true);
		}
	}

	TArray<FGameplayAbilitySpecHandle> CAbilities;
	AbilityComponent->GetAllAbilities(CAbilities);

	if (CAbilities.Num() == 0)
	{
		// Server GAS init
		AbilityComponent->InitAbilityActorInfo(this, this);
		InitializeDefaultAttributeValues();
		GiveInitialAbilities();
	}
}

void ATDRL_Character::ApplyDefaultKnockback(const FVector InDirection, const FName InBoneName)
{
	FStunParameters NewDefStunParam = DefaultDamageKnockback;
	if (DefaultKnockbackMontages.Num() > 0)
	{
		NewDefStunParam.StunAnimationLoop = DefaultKnockbackMontages[FMath::RandRange(
			0, DefaultKnockbackMontages.Num() - 1)];
	}

	Stun(NewDefStunParam, InDirection, InBoneName);
}

void ATDRL_Character::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// Client GAS init
	AbilityComponent->InitAbilityActorInfo(this, this);
	InitializeDefaultAttributeValues();

	/*if (AbilityComponent && InputComponent) {
		const FGameplayAbilityInputBinds Binds("Confirm", "Cancel", "ETDRLGASAbilityInputID", static_cast<uint8>(ETDRLGASAbilityInputID::Confirm), static_cast<uint8>(ETDRLGASAbilityInputID::Cancel));
		AbilityComponent->BindAbilityActivationToInputComponent(InputComponent, Binds);
	}*/
}

void ATDRL_Character::UnPossessed()
{
	Super::UnPossessed();
	EnableTraceForNearbyItems(false);
	GetMesh()->SetCustomDepthStencilValue(252);
}

#pragma region Tick

void ATDRL_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsPlayerControlled() && IsLocallyControlled())
	{
		TickCameraOrientation();
		TickCameraOcclusionTrace();
	}
}

void ATDRL_Character::TickCameraOcclusionTrace()
{
	if (OcclusionParam.bUseCameraOcclusionTrace || OcclusionParam.bUseCameraOcclusionPostProcess)
	{
		const FVector CameraLoc = GetCamera()->GetComponentLocation();
		const FVector CharacterLoc = GetCapsuleComponent()->GetComponentLocation();

		const FVector TraceDirection = UKismetMathLibrary::GetDirectionUnitVector(CameraLoc, CharacterLoc);
		const FVector StartLocation = CameraLoc + (TraceDirection * OcclusionParam.StartForwardOffset);

		if (OcclusionParam.bUseCameraOcclusionTrace)
		{
			TraceForCameraOcclusion(StartLocation,
			                        CharacterLoc + FVector(
				                        0.0f, 0.0f,
				                        GetCapsuleComponent()->GetScaledCapsuleHalfHeight() * OcclusionParam.SizeFactor.
				                        Y), TraceDirection.Rotation());
		}
		if (OcclusionParam.bUseCameraOcclusionPostProcess)
		{
			TraceForPostProcessOcclusion(StartLocation, CharacterLoc, TraceDirection.Rotation());
		}
	}
}

void ATDRL_Character::TraceForCameraOcclusion(const FVector InStart, const FVector InEnd, const FRotator InOrientation)
{
	FCollisionObjectQueryParams QueryParam;

	for (auto Iter = OcclusionParam.TraceChannels.CreateConstIterator(); Iter; ++Iter)
	{
		const ECollisionChannel& Channel = UCollisionProfile::Get()->ConvertToCollisionChannel(false, *Iter);
		QueryParam.AddObjectTypesToQuery(Channel);
	}

	TArray<FHitResult> HitOut = TArray<FHitResult>();
	const FCollisionShape BoxShape = FCollisionShape::MakeBox(FVector(
		5.0f, GetCapsuleComponent()->GetScaledCapsuleRadius() * OcclusionParam.SizeFactor.X,
		GetCapsuleComponent()->GetScaledCapsuleHalfHeight() * OcclusionParam.SizeFactor.Y));

	bool bHitHappened = GetWorld()->SweepMultiByObjectType(
		HitOut,
		InStart,
		InEnd,
		FQuat(FRotator(0.0f, InOrientation.Yaw, InOrientation.Roll)),
		QueryParam,
		BoxShape,
		FCollisionQueryParams::DefaultQueryParam);

	/*DrawDebugBox(
		GetWorld(),
		InStart,
		BoxShape.GetExtent(),
		FQuat(FRotator(0.0f, InOrientation.Yaw, InOrientation.Roll)),
		FColor::Cyan, false, 0.05f);

	DrawDebugBox(
		GetWorld(),
		InEnd,
		BoxShape.GetExtent(),
		FQuat(FRotator(0.0f, InOrientation.Yaw, InOrientation.Roll)),
		FColor::Red, false, 0.05f);*/

	TArray<UTDRL_CameraOcclusionComponent*> LComps = TArray<UTDRL_CameraOcclusionComponent*>();

	if (bHitHappened)
	{
		for (int32 Idx = 0; Idx < HitOut.Num(); Idx++)
		{
			UTDRL_CameraOcclusionComponent* OcclusionComp = Cast<UTDRL_CameraOcclusionComponent>(
				HitOut[Idx].GetActor()->GetComponentByClass(UTDRL_CameraOcclusionComponent::StaticClass()));

			if (OcclusionComp)
			{
				OcclusionComp->SetOcclusionEnabled(true);
				LComps.Add(OcclusionComp);
			}
		}
	}

	for (int32 Idx = 0; Idx < CameraOccludingComponents.Num(); Idx++)
	{
		if (!LComps.Contains(CameraOccludingComponents[Idx]))
		{
			CameraOccludingComponents[Idx]->SetOcclusionEnabled(false);
		}
	}

	CameraOccludingComponents = LComps;
}

void ATDRL_Character::TraceForPostProcessOcclusion(const FVector InStart, const FVector InEnd,
                                                   const FRotator InOrientation)
{
	FHitResult HitOut = FHitResult();
	const FCollisionShape BoxShape = FCollisionShape::MakeBox(FVector(
		5.0f, GetCapsuleComponent()->GetScaledCapsuleRadius() * 0.9f,
		GetCapsuleComponent()->GetScaledCapsuleHalfHeight() * 0.9f));

	FCollisionQueryParams IgnoreParam;
	TArray<AActor*> IgnoringActs = TArray<AActor*>();

	GetAttachedActors(IgnoringActs, true, true);
	IgnoreParam.AddIgnoredActors(IgnoringActs);

	bool bHitHappened = GetWorld()->SweepSingleByChannel(
		HitOut,
		InStart,
		InEnd,
		FQuat(FRotator(0.0f, InOrientation.Yaw, InOrientation.Roll)),
		ECollisionChannel::ECC_Visibility,
		BoxShape,
		IgnoreParam);

	/*DrawDebugBox(
		GetWorld(),
		InStart,
		BoxShape.GetExtent(),
		FQuat(FRotator(0.0f, InOrientation.Yaw, InOrientation.Roll)),
		FColor::Blue, false, 0.05f);

	DrawDebugBox(
		GetWorld(),
		InEnd,
		BoxShape.GetExtent(),
		FQuat(FRotator(0.0f, InOrientation.Yaw, InOrientation.Roll)),
		FColor::Blue, false, 0.05f);*/

	if (HitOut.bBlockingHit)
	{
		if (HitOut.GetActor() == this)
		{
			GetMesh()->SetRenderCustomDepth(false);
		}
		else
		{
			bool bShouldAvoidClass = false;
			for (auto& CClass : OcclusionParam.PostProcessAvoid)
			{
				if (HitOut.GetActor()->GetClass()->IsChildOf(CClass))
				{
					bShouldAvoidClass = true;
					break;
				}
			}

			if (bShouldAvoidClass)
			{
				GetMesh()->SetRenderCustomDepth(false);
			}
			else
			{
				GetMesh()->SetRenderCustomDepth(true);
			}
		}
	}
	else
	{
		GetMesh()->SetRenderCustomDepth(false);
	}
}

void ATDRL_Character::TickCameraOrientation()
{
	if (FMath::IsNearlyEqual(GetCameraSpringArm()->TargetArmLength,
	                         FVector::Dist(GetCameraSpringArm()->GetComponentLocation(),
	                                       GetCamera()->GetComponentLocation()), 0.1f))
	{
		if (!GetCamera()->GetRelativeRotation().Equals(FRotator(-45.0f, GetCamera()->GetRelativeRotation().Yaw, 0.0f),
		                                               0.05f))
		{
			GetCamera()->SetRelativeRotation(FRotator(-45.0f, GetCamera()->GetRelativeRotation().Yaw, 0.0f));
		}
		return;
	}

	GetCamera()->SetWorldRotation(
		UKismetMathLibrary::FindLookAtRotation(GetCamera()->GetComponentLocation(),
		                                       GetCapsuleComponent()->GetComponentLocation()));
}

#pragma endregion

void ATDRL_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	/*if (AbilityComponent && InputComponent) {
		const FGameplayAbilityInputBinds Binds("Confirm", "Cancel", "ETDRLGASAbilityInputID", static_cast<uint8>(ETDRLGASAbilityInputID::Confirm), static_cast<uint8>(ETDRLGASAbilityInputID::Cancel));
		AbilityComponent->BindAbilityActivationToInputComponent(InputComponent, Binds);
	}*/
}

void ATDRL_Character::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(ATDRL_Character, Inventory, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ATDRL_Character, SelectedItemSlot, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ATDRL_Character, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ATDRL_Character, MainWeapon, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ATDRL_Character, CurrentStun, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ATDRL_Character, DeathInfo, COND_None, REPNOTIFY_Always); //REPNOTIFY_OnChanged
	DOREPLIFETIME_CONDITION(ATDRL_Character, AimOffsetValue, COND_SimulatedOnly);
}

void ATDRL_Character::OnRep_CurrentStun(const FStunParameters OldValue)
{
	if (CurrentStun.IsValid())
	{
		if (CurrentStun.StunAnimationLoop)
		{
			PlayAnimMontage(CurrentStun.StunAnimationLoop);
		}

		if (CurrentStun.bDropWeapon && SelectedItemSlot > 0)
		{
			DropItem(SelectedItemSlot);
		}
	}
	else
	{
		if (OldValue.StunAnimationLoop)
		{
			StopAnimMontage(OldValue.StunAnimationLoop);
		}
	}
}

UTDRL_CharacterMovementComponent* ATDRL_Character::GetTDRLMovementComponent() const
{
	return Cast<UTDRL_CharacterMovementComponent>(GetCharacterMovement());
}

bool ATDRL_Character::IsStunned()
{
	return CurrentStun.IsValid();
}

bool ATDRL_Character::GetStunValue(FStunParameters& Value)
{
	Value = CurrentStun;
	return CurrentStun.IsValid();
}

/* Health and Energy */

void ATDRL_Character::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void ATDRL_Character::BeginDestroy()
{
	Super::BeginDestroy();

	if (MainWeapon)
	{
		MainWeapon->Destroy();
	}
}

UAbilitySystemComponent* ATDRL_Character::GetAbilitySystemComponent() const
{
	return FindComponentByClass<UAbilitySystemComponent>();
}

void ATDRL_Character::ApplyDynamicMaterialPostProcess()
{
	if (!GlobalPostProcess)
	{
		return;
	}

	PostProcessInUse = UMaterialInstanceDynamic::Create(GlobalPostProcess, GetWorld());

	GetCamera()->PostProcessSettings.RemoveBlendable(GlobalPostProcess);
	GetCamera()->PostProcessSettings.AddBlendable(PostProcessInUse, 1.0f);
}

void ATDRL_Character::RemoveDynamicMaterialPostProcess()
{
	if (!PostProcessInUse || !GlobalPostProcess)
	{
		return;
	}

	GetCamera()->PostProcessSettings.RemoveBlendable(PostProcessInUse);
	GetCamera()->PostProcessSettings.AddBlendable(GlobalPostProcess, 1.0f);
	PostProcessInUse->ConditionalBeginDestroy();
	PostProcessInUse = nullptr;
}

void ATDRL_Character::OnRep_HealthModified(const float Previous)
{
}

void ATDRL_Character::SetHealth(const float Value)
{
	// The Health value MUST be set by the server
	if (GetLocalRole() != ROLE_Authority)
	{
		return;
	}

	Health = Value;
}

bool ATDRL_Character::Heal(const float Value, FStatusEffect Effect)
{
	// The Health value MUST be set by the server
	if (GetLocalRole() != ROLE_Authority || GetIsDead() || Health == MaxHealth)
	{
		return false;
	}

	Health = FMath::Min(Health + FMath::Abs(Value), MaxHealth);
	Heal_Effects(Effect);
	return true;
}

void ATDRL_Character::Heal_Effects_Implementation(const FStatusEffect Value)
{
	TArray<USceneComponent*> CompOut = TArray<USceneComponent*>();
	UTDRL_BFL_Global::SpawnStatusVFXs(this, Value, GetRootComponent(), FName(), CompOut);
}

/* Default Weapon */

void ATDRL_Character::SpawnDefaultWeapon_Implementation()
{
	if (!MainWeapon)
	{
		MainWeapon = GetWorld()->SpawnActor<ATDRL_Melee>(DefaultWeaponClass);

		if (MainWeapon)
		{
			MainWeapon->AssignToCharacter(this);
			MainWeapon->Pickup(this);
			MainWeapon->SetActorEnableCollision(false);
			MainWeapon->UpdateOwnerGAS(AbilityComponent, EItemInteractions::II_Pickup);

			if (SelectedItemSlot > 0 && Inventory[SelectedItemSlot - 1])
			{
				MainWeapon->Holster(this);
				MainWeapon->UpdateOwnerGAS(AbilityComponent, EItemInteractions::II_Holster);
			}
			else
			{
				MainWeapon->Equip(this);
				MainWeapon->UpdateOwnerGAS(AbilityComponent, EItemInteractions::II_Equip);
			}
		}
	}
}

void ATDRL_Character::DestroyDefaultWeapon_Implementation()
{
	if (MainWeapon)
	{
		MainWeapon->Destroy();
		MainWeapon = nullptr;
	}
}

void ATDRL_Character::OnRep_MainWeaponModified()
{
	if (MainWeapon)
	{
		MainWeapon->AssignToCharacter(this);
		MainWeapon->Pickup(this);

		if (SelectedItemSlot > 0 && Inventory[SelectedItemSlot - 1])
		{
			MainWeapon->Holster(this);
		}
		else
		{
			MainWeapon->Equip(this);
		}
	}
}

/* Item Tracing */

void ATDRL_Character::EnableTraceForNearbyItems(const bool Enable)
{
	if (!IsPlayerControlled())
	{
		return;
	}

	EnableTraceForNearbyItems_Server(Enable);
}

void ATDRL_Character::EnableTraceForNearbyItems_Server_Implementation(const bool Enable)
{
	EnableTraceForNearbyItems_Func(Enable);
}

void ATDRL_Character::EnableTraceForNearbyItems_Func_Implementation(const bool Enable)
{
	if (Enable)
	{
		GetWorld()->GetTimerManager().SetTimer(TraceItemTimerHandle, this, &ATDRL_Character::TraceForNearbyItems, 0.03f,
		                                       true);
	}
	else
	{
		if (TraceItemTimerHandle.IsValid())
		{
			GetWorld()->GetTimerManager().ClearTimer(TraceItemTimerHandle);
			TraceItemTimerHandle.Invalidate();
		}
	}
}

void ATDRL_Character::TraceForNearbyItems()
{
	FCollisionShape MySphere = FCollisionShape::MakeSphere(ItemTraceRadius); // 0.75M Radius

	TArray<FHitResult> OutResults;
	FCollisionQueryParams QParam;
	QParam.AddIgnoredActor(this);

	for (uint8 i = 0; i < Inventory.Num(); i++)
	{
		if (Inventory[i])
		{
			QParam.AddIgnoredActor(Inventory[i]);
		}
	}

	FCollisionResponseParams RespParam;

	RespParam.CollisionResponse.SetAllChannels(ECollisionResponse::ECR_Ignore);

	for (auto Iter = TraceForItemsChannels.CreateConstIterator(); Iter; ++Iter)
	{
		const ECollisionChannel& Channel = UCollisionProfile::Get()->ConvertToCollisionChannel(false, *Iter);
		RespParam.CollisionResponse.SetResponse(Channel, ECollisionResponse::ECR_Block);
	}

	GetWorld()->SweepMultiByChannel(OutResults, GetActorLocation(), GetActorLocation() + GetActorUpVector(),
	                                FQuat::Identity, ECollisionChannel::ECC_Visibility, MySphere, QParam, RespParam);

	if (bDebugShowTraceForItems)
	{
		DrawDebugSphere(GetWorld(), GetActorLocation(), ItemTraceRadius, 6, FColor::Blue, false, .03f);
	}

	if (NearbyItems.Num() > NearestNearbyItemIndex)
	{
		NearbyItems[NearestNearbyItemIndex]->EnableItemOutliner(false);
	}

	NearbyItems.Empty();
	float NearestDist = FLT_MAX;
	NearestNearbyItemIndex = 0;

	for (int32 i = 0; i < OutResults.Num(); i++)
	{
		if (NearbyItems.Num() >= 255)
		{
			break;
		}

		if (OutResults[i].GetActor()->GetOwner() != nullptr)
		{
			continue;
		}

		ATDRL_Item* CItem = Cast<ATDRL_Item>(OutResults[i].GetActor());

		if (CItem)
		{
			FHitResult LineTraceCheck;
			GetWorld()->LineTraceSingleByChannel(LineTraceCheck, GetActorLocation(),
			                                     OutResults[i].GetComponent()->GetComponentLocation(),
			                                     ECollisionChannel::ECC_Visibility, QParam);

			if (LineTraceCheck.GetActor() != CItem)
			{
				GetWorld()->LineTraceSingleByChannel(LineTraceCheck, GetActorLocation(),
				                                     OutResults[i].Location + (
					                                     UKismetMathLibrary::GetDirectionUnitVector(
						                                     GetActorLocation(), OutResults[i].Location) * 5.0f),
				                                     ECollisionChannel::ECC_Visibility, QParam);
			}

			if (LineTraceCheck.GetActor() == CItem)
			{
				NearbyItems.Add(CItem);

				const float CurDist = (LineTraceCheck.GetComponent()->GetComponentLocation() - GetActorLocation()).
					Length() + (UKismetMathLibrary::Abs(UKismetMathLibrary::NormalizedDeltaRotator(
						UKismetMathLibrary::MakeRotFromX(
							UKismetMathLibrary::GetDirectionUnitVector(GetActorLocation(),
							                                           LineTraceCheck.GetComponent()->
							                                           GetComponentLocation())),
						GetActorRotation()).Yaw) / 4);

				if (NearestDist > CurDist)
				{
					NearestDist = CurDist;
					NearestNearbyItemIndex = NearbyItems.Num() - 1;
				}
			}
		}
	}

	if (NearbyItems.Num() > NearestNearbyItemIndex)
	{
		NearbyItems[NearestNearbyItemIndex]->EnableItemOutliner(true);
	}

	//UE_LOG(LogTemp, Log, TEXT("Nearest index is %f"), NearestNearbyItemIndex);
}

/* Inventory size */

void ATDRL_Character::SetInventorySlotsAmount_Implementation(const uint8 Slots)
{
	if (Inventory.Num() < Slots)
	{
		Inventory.Init(nullptr, Slots);
	}
	else
	{
		//Dorp !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	}
}

ATDRL_Item* ATDRL_Character::GetEquippedItem() const
{
	if (SelectedItemSlot > 0)
	{
		if (Inventory[SelectedItemSlot - 1])
		{
			return Inventory[SelectedItemSlot - 1];
		}
	}

	return MainWeapon;
}

/* Pickup and Drop Item */

void ATDRL_Character::PickupItem(ATDRL_Item* Item)
{
	if (IsStunned())
	{
		return;
	}

	if (GetLocalRole() == ROLE_SimulatedProxy)
	{
		return;
	}

	if (IsLocallyControlled())
	{
		switch (GetLocalRole())
		{
		case ENetRole::ROLE_Authority:
			PickupItem_Func(Item);
			break;
		case ENetRole::ROLE_AutonomousProxy:
			PickupItem_Server(Item);
			break;
		}
	}
}

void ATDRL_Character::PickupItem_Server_Implementation(ATDRL_Item* Item)
{
	PickupItem_Func(Item);
}

void ATDRL_Character::PickupItem_Func(ATDRL_Item* Item)
{
	if (IsStunned())
	{
		return;
	}

	if (!Item)
	{
		return;
	}

	if (Item->bStaticInteractable)
	{
		// Interact
		Item->Interact(this);
	}
	else
	{
		// Pickup
		if (SelectedItemSlot > 0)
		{
			if (Inventory.Num() < SelectedItemSlot)
			{
				return;
			}

			if (Inventory[SelectedItemSlot - 1])
			{
				// Block for global CD
				if (!Inventory[SelectedItemSlot - 1]->IsItemGlobalTimerOver())
				{
					return;
				}

				Inventory[SelectedItemSlot - 1]->Drop(this);
				Inventory[SelectedItemSlot - 1]->UpdateOwnerGAS(AbilityComponent, EItemInteractions::II_Drop);
				Inventory[SelectedItemSlot - 1]->AssignToCharacter(nullptr);
			}
			else
			{
				// Block for global CD
				if (MainWeapon)
				{
					if (!MainWeapon->IsItemGlobalTimerOver())
					{
						return;
					}

					MainWeapon->Holster(this);
					MainWeapon->UpdateOwnerGAS(AbilityComponent, EItemInteractions::II_Holster);
				}
			}

			Inventory[SelectedItemSlot - 1] = Item;
			Item->AssignToCharacter(this);
			Item->Pickup(this);
			Item->UpdateOwnerGAS(AbilityComponent, EItemInteractions::II_Pickup);
			Item->Equip(this);
			Item->UpdateOwnerGAS(AbilityComponent, EItemInteractions::II_Equip);

			if (IsLocallyControlled())
			{
				// Update HUD
				ATDRL_HUD* CHud = UTDRL_BFL_Global::GetTDRLHUD(this);
				if (CHud)
				{
					CHud->RefreshIcons();
				}
			}

			//UE_LOG(LogTemp, Warning, TEXT("SelectedSlot %i"), SelectedItemSlot);
		}
		else
		{
			if (Inventory.Num() == 0)
			{
				return;
			}

			int32 FirstFreeSlot = 0;
			bool bFreeSlots = false;

			for (int32 i = 0; i < Inventory.Num(); i++)
			{
				if (!Inventory[i])
				{
					FirstFreeSlot = i;
					bFreeSlots = true;
					break;
				}
			}

			if (!bFreeSlots)
			{
				return;
			}

			Inventory[FirstFreeSlot] = Item;
			Item->AssignToCharacter(this);
			Item->Pickup(this);
			Item->UpdateOwnerGAS(AbilityComponent, EItemInteractions::II_Pickup);

			if (Item->StaticData.bAlwaysEquipOnPickup)
			{
				//Item->Equipped();
				SelectItemSlot(FirstFreeSlot + 1);
				//Item->UpdateOwnerGAS(AbilityComponent, EItemInteractions::II_Equip);
			}

			if (IsLocallyControlled())
			{
				// Update HUD
				ATDRL_HUD* CHud = UTDRL_BFL_Global::GetTDRLHUD(this);
				if (CHud)
				{
					CHud->RefreshIcons();
				}
			}
		}
	}
}

void ATDRL_Character::DropItem(const uint8 Slot)
{
	if (IsStunned())
	{
		return;
	}

	if (Slot == 0 || Slot > Inventory.Num())
	{
		return;
	}

	if (!Inventory[Slot - 1])
	{
		return;
	}

	if (IsLocallyControlled())
	{
		switch (GetLocalRole())
		{
		case ENetRole::ROLE_Authority:
			DropItem_Func(Slot);
			break;
		case ENetRole::ROLE_AutonomousProxy:
			DropItem_Server(Slot);
			break;
		}
	}
	else
	{
		DropItem_Func(Slot);
	}
}

void ATDRL_Character::DropEquippedItem()
{
	DropItem(SelectedItemSlot);
}

void ATDRL_Character::DropItem_Server_Implementation(const uint8 Slot)
{
	DropItem_Func(Slot);
}

void ATDRL_Character::DropItem_Func(const uint8 Slot)
{
	if (IsStunned() || Slot < 1 || Slot > Inventory.Num())
	{
		return;
	}

	if (!Inventory[Slot - 1])
	{
		return;
	}

	if (!Inventory[Slot - 1]->IsItemGlobalTimerOver())
	{
		return;
	}

	Inventory[Slot - 1]->Drop(this);
	Inventory[Slot - 1]->UpdateOwnerGAS(AbilityComponent, EItemInteractions::II_Holster);
	Inventory[Slot - 1]->UpdateOwnerGAS(AbilityComponent, EItemInteractions::II_Drop);
	Inventory[Slot - 1]->AssignToCharacter(nullptr);
	Inventory[Slot - 1]->SetActorEnableCollision(true);
	Inventory[Slot - 1] = nullptr;

	if (MainWeapon)
	{
		MainWeapon->Equip(this);
		MainWeapon->UpdateOwnerGAS(AbilityComponent, EItemInteractions::II_Equip);
	}

	if (IsLocallyControlled())
	{
		// Update HUD
		ATDRL_HUD* CHud = UTDRL_BFL_Global::GetTDRLHUD(this);
		if (CHud)
		{
			CHud->RefreshIcons();
		}
	}
}

/* Item selection */

void ATDRL_Character::DropAllItems()
{
	for (int32 i = 0; i < Inventory.Num(); i++)
	{
		if (Inventory[i])
		{
			DropItem(i + 1);
		}
	}

	if (IsLocallyControlled())
	{
		// Update HUD
		ATDRL_HUD* CHud = UTDRL_BFL_Global::GetTDRLHUD(this);
		if (CHud)
		{
			CHud->RefreshIcons();
		}
	}
}

void ATDRL_Character::DestroyAllItems(const bool bIncludeMain)
{
	TArray<ATDRL_Item*> TempInv = Inventory;

	DropAllItems();

	for (int32 i = 0; i < TempInv.Num(); i++)
	{
		if (TempInv[i])
		{
			TempInv[i]->Destroy();
		}
	}

	SelectItemSlot(0);

	if (bIncludeMain)
	{
		if (MainWeapon)
		{
			MainWeapon->Destroy();
		}
	}

	if (IsLocallyControlled())
	{
		// Update HUD
		ATDRL_HUD* CHud = UTDRL_BFL_Global::GetTDRLHUD(this);
		if (CHud)
		{
			CHud->RefreshIcons();
		}
	}
}

void ATDRL_Character::SelectItemSlot(const uint8 Slot)
{
	if (IsStunned())
	{
		return;
	}

	if (IsLocallyControlled())
	{
		switch (GetLocalRole())
		{
		case ENetRole::ROLE_Authority:
			SelectItemSlot_Func(Slot);
			break;
		case ENetRole::ROLE_AutonomousProxy:
			SelectItemSlot_Server(Slot);
			break;
		}

		// Update HUD
		ATDRL_HUD* CHud = UTDRL_BFL_Global::GetTDRLHUD(this);
		if (CHud)
		{
			CHud->SelectSlotUI(SelectedItemSlot);
		}
	}
}

void ATDRL_Character::SelectItemSlot_Server_Implementation(const uint8 Slot)
{
	SelectItemSlot_Func(Slot);
}

void ATDRL_Character::SelectItemSlot_Func(const uint8 Slot)
{
	if (IsStunned() || !MainWeapon)
	{
		return;
	}

	// Global Timer Filter
	if (SelectedItemSlot > 0)
	{
		if (Inventory[SelectedItemSlot - 1])
		{
			if (!Inventory[SelectedItemSlot - 1]->IsItemGlobalTimerOver())
			{
				return;
			}
		}
		else
		{
			if (!MainWeapon->IsItemGlobalTimerOver())
			{
				return;
			}
		}
	}
	else
	{
		if (!MainWeapon->IsItemGlobalTimerOver())
		{
			return;
		}
	}

	// Current weapon
	if (SelectedItemSlot > 0 && Inventory[SelectedItemSlot - 1])
	{
		Inventory[SelectedItemSlot - 1]->Holster(this);
		Inventory[SelectedItemSlot - 1]->UpdateOwnerGAS(AbilityComponent, EItemInteractions::II_Holster);
	}
	else
	{
		if (Slot > 0)
		{
			if (Inventory[Slot - 1])
			{
				MainWeapon->Holster(this);
				MainWeapon->UpdateOwnerGAS(AbilityComponent, EItemInteractions::II_Holster);
			}
		}
	}

	if (Slot > 0)
	{
		if (!Inventory[Slot - 1])
		{
			MainWeapon->Equip(this);
			MainWeapon->UpdateOwnerGAS(AbilityComponent, EItemInteractions::II_Equip);
		}
	}

	if (Slot == 0 || SelectedItemSlot == Slot)
	{
		if (SelectedItemSlot != 0)
		{
			SelectedItemSlot = 0;
			MainWeapon->Equip(this);
			MainWeapon->UpdateOwnerGAS(AbilityComponent, EItemInteractions::II_Equip);
		}

		// Default weapon equipped
		return;
	}

	// New weapon
	SelectedItemSlot = Slot;
	if (Inventory[SelectedItemSlot - 1])
	{
		Inventory[SelectedItemSlot - 1]->Equip(this);
		Inventory[SelectedItemSlot - 1]->UpdateOwnerGAS(AbilityComponent, EItemInteractions::II_Equip);
	}
}

/* Inventory client replication events */

void ATDRL_Character::OnRep_SlotSelectionModified(const uint8 Previous)
{
	//UE_LOG(LogTemp, Warning, TEXT("Previous Slot %i"), Previous);
	if (!MainWeapon)
	{
		return;
	}

	if (Previous > 0)
	{
		if (Inventory[Previous - 1])
		{
			Inventory[Previous - 1]->Holster(this);
		}
		else
		{
			if (SelectedItemSlot > 0)
			{
				if (Inventory[SelectedItemSlot - 1])
				{
					MainWeapon->Holster(this);
				}
			}
		}
	}
	else
	{
		if (SelectedItemSlot > 0)
		{
			if (Inventory[SelectedItemSlot - 1])
			{
				MainWeapon->Holster(this);
			}
		}
	}

	if (SelectedItemSlot > 0)
	{
		if (Inventory[SelectedItemSlot - 1])
		{
			Inventory[SelectedItemSlot - 1]->Equip(this);
		}
		else
		{
			if (Previous > 0)
			{
				if (Inventory[Previous - 1])
				{
					MainWeapon->Equip(this);
				}
			}
		}
	}
	else
	{
		MainWeapon->Equip(this);
	}

	if (IsLocallyControlled())
	{
		// Update HUD
		ATDRL_HUD* CHud = UTDRL_BFL_Global::GetTDRLHUD(this);
		if (CHud)
		{
			CHud->SelectSlotUI(SelectedItemSlot);
		}
	}
}

void ATDRL_Character::OnRep_InventoryModified(const TArray<class ATDRL_Item*> Previous)
{
	//UE_LOG(LogTemp, Warning, TEXT("Previous length %i"), Previous.Num());

	FCriticalSection Mutex;

	TArray<uint8> ChangedIndexes = TArray<uint8>();
	ParallelFor(Previous.Num(), [&](int32 Idx)
	{
		if (Previous[Idx] != Inventory[Idx])
		{
			Mutex.Lock();
			ChangedIndexes.Add(Idx);
			Mutex.Unlock();
		}
	});

	for (uint8 i = 0; i < ChangedIndexes.Num(); i++)
	{
		if (Inventory[ChangedIndexes[i]])
		{
			Inventory[ChangedIndexes[i]]->AssignToCharacter(this);
			Inventory[ChangedIndexes[i]]->Pickup(this);
			Inventory[ChangedIndexes[i]]->SetActorEnableCollision(false);

			if (ChangedIndexes[i] + 1 == SelectedItemSlot)
			{
				if (!Previous[i] && MainWeapon)
				{
					MainWeapon->Holster(this);
				}
				Inventory[ChangedIndexes[i]]->Equip(this);
			}
			else
			{
				if (Inventory[ChangedIndexes[i]]->StaticData.bAlwaysEquipOnPickup)
				{
					SelectItemSlot(ChangedIndexes[i] + 1);
				}
			}
		}

		if (Previous[ChangedIndexes[i]])
		{
			Previous[ChangedIndexes[i]]->Drop(this);
			Previous[ChangedIndexes[i]]->AssignToCharacter(nullptr);
			Previous[ChangedIndexes[i]]->SetActorEnableCollision(true);

			if (ChangedIndexes[i] + 1 == SelectedItemSlot && !Inventory[ChangedIndexes[i]])
			{
				if (MainWeapon)
				{
					MainWeapon->Equip(this);
				}
			}
		}
	}

	if (IsLocallyControlled())
	{
		// Update HUD
		ATDRL_HUD* CHud = UTDRL_BFL_Global::GetTDRLHUD(this);
		if (CHud)
		{
			CHud->RefreshIcons();
		}
	}
}

/* Game actions */

void ATDRL_Character::PerformPrimaryAction(const bool Enable)
{
	if (IsStunned() && Enable)
	{
		return;
	}

	if (IsLocallyControlled())
	{
		switch (GetLocalRole())
		{
		case ENetRole::ROLE_Authority:
			PerformPrimaryAction_Func(Enable);
			break;
		case ENetRole::ROLE_AutonomousProxy:
			PerformPrimaryAction_Server(Enable);
			break;
		}
	}
}

void ATDRL_Character::PerformPrimaryAction_Server_Implementation(const bool Enable)
{
	PerformPrimaryAction_Func(Enable);
}

void ATDRL_Character::PerformPrimaryAction_Func(const bool Enable)
{
	if (IsStunned() && Enable)
	{
		return;
	}

	if (SelectedItemSlot > 0)
	{
		if (Inventory[SelectedItemSlot - 1])
		{
			Inventory[SelectedItemSlot - 1]->PrimaryAction(Enable);
			return;
		}
	}

	if (MainWeapon)
	{
		MainWeapon->PrimaryAction(Enable);
	}
}

void ATDRL_Character::PerformSecondaryAction(const bool Enable)
{
	if (IsStunned() && Enable)
	{
		return;
	}

	if (IsLocallyControlled())
	{
		switch (GetLocalRole())
		{
		case ENetRole::ROLE_Authority:
			PerformSecondaryAction_Func(Enable);
			break;
		case ENetRole::ROLE_AutonomousProxy:
			PerformSecondaryAction_Server(Enable);
			break;
		}
	}
}

void ATDRL_Character::PerformSecondaryAction_Server_Implementation(const bool Enable)
{
	PerformSecondaryAction_Func(Enable);
}

void ATDRL_Character::PerformSecondaryAction_Func(const bool Enable)
{
	if (IsStunned() && Enable)
	{
		return;
	}

	if (SelectedItemSlot > 0)
	{
		if (Inventory[SelectedItemSlot - 1])
		{
			Inventory[SelectedItemSlot - 1]->SecondaryAction(Enable);
			return;
		}
	}

	if (MainWeapon)
	{
		MainWeapon->SecondaryAction(Enable);
	}
}

void ATDRL_Character::PerformRAction(const bool Enable)
{
	if (IsStunned() && Enable)
	{
		return;
	}

	if (IsLocallyControlled())
	{
		switch (GetLocalRole())
		{
		case ENetRole::ROLE_Authority:
			PerformRAction_Func(Enable);
			break;
		case ENetRole::ROLE_AutonomousProxy:
			PerformRAction_Server(Enable);
			break;
		}
	}
}

void ATDRL_Character::PerformRAction_Server_Implementation(const bool Enable)
{
	PerformRAction_Func(Enable);
}

void ATDRL_Character::PerformRAction_Func(const bool Enable)
{
	if (IsStunned() && Enable)
	{
		return;
	}

	if (SelectedItemSlot > 0)
	{
		if (Inventory[SelectedItemSlot - 1])
		{
			Inventory[SelectedItemSlot - 1]->RAction(Enable);
			return;
		}
	}

	if (MainWeapon)
	{
		MainWeapon->RAction(Enable);
	}
}

uint8 ATDRL_Character::GetHigestRarityItemSlot(const bool ShouldBeWeapon)
{
	uint8 ReturnValue = 0;
	uint8 MaxRariyFound = 0;

	if (MainWeapon)
	{
		MaxRariyFound = static_cast<uint8>(MainWeapon->StaticData.Rarity);
	}

	for (uint8 i = 0; i < Inventory.Num(); i++)
	{
		if (!Inventory[i])
		{
			continue;
		}
		else
		{
			if (ShouldBeWeapon)
			{
				if (!Inventory[i]->GetClass()->StaticClass()->IsChildOf(ATDRL_Weapon::StaticClass()))
				{
					continue;
				}
			}
		}

		const uint8 NewRarity = static_cast<uint8>(Inventory[i]->StaticData.Rarity);
		if (NewRarity > MaxRariyFound)
		{
			ReturnValue = i + 1;
			MaxRariyFound = NewRarity;

			if (MaxRariyFound == static_cast<uint8>(EItemRarity::IR_MAX))
			{
				break;
			}
		}
	}

	return ReturnValue;
}

uint8 ATDRL_Character::GetLowestRarityItemSlot(const bool ShouldBeWeapon)
{
	uint8 ReturnValue = 0;
	uint8 MaxRariyFound = 0;
	if (MainWeapon)
	{
		MaxRariyFound = static_cast<uint8>(MainWeapon->StaticData.Rarity);
	}

	for (uint8 i = 0; i < Inventory.Num(); i++)
	{
		if (!Inventory[i])
		{
			continue;
		}
		else
		{
			if (ShouldBeWeapon)
			{
				if (!Inventory[i]->GetClass()->StaticClass()->IsChildOf(ATDRL_Weapon::StaticClass()))
				{
					continue;
				}
			}
		}

		const uint8 NewRarity = static_cast<uint8>(Inventory[i]->StaticData.Rarity);
		if (NewRarity < MaxRariyFound)
		{
			ReturnValue = i + 1;
			MaxRariyFound = NewRarity;

			if (MaxRariyFound == static_cast<uint8>(EItemRarity::IR_Trash))
			{
				break;
			}
		}
	}

	return ReturnValue;
}

bool ATDRL_Character::HasItemOfClass(const TSubclassOf<ATDRL_Item> InClass, const bool bIncludeSubclasses)
{
	TArray<TSubclassOf<ATDRL_Item>> InvClasses = TArray<TSubclassOf<ATDRL_Item>>();

	for (uint8 i = 0; i < Inventory.Num(); i++)
	{
		if (Inventory[i]->GetClass()->StaticClass() == InClass.Get())
		{
			return true;
		}

		if (bIncludeSubclasses)
		{
			if (Inventory[i]->GetClass()->StaticClass()->IsChildOf(InClass.Get()))
			{
				return true;
			}
		}
	}

	return false;
}

TArray<uint8> ATDRL_Character::GetSlotsOccupiedByItemClass(const TSubclassOf<ATDRL_Item> InClass,
                                                           const bool bIncludeSubclasses)
{
	TArray<uint8> ListOut = TArray<uint8>();

	for (uint8 i = 0; i < Inventory.Num(); i++)
	{
		if (Inventory[i]->GetClass()->StaticClass() == InClass.Get())
		{
			ListOut.Add(i);
			continue;
		}

		if (bIncludeSubclasses)
		{
			if (Inventory[i]->GetClass()->StaticClass()->IsChildOf(InClass.Get()))
			{
				ListOut.Add(i);
				continue;
			}
		}
	}

	return ListOut;
}

/* Game Inputs */

void ATDRL_Character::Input_PitchAim_Implementation(const bool Pressed)
{
}

void ATDRL_Character::Input_Dash_Implementation(const bool Pressed)
{
}

void ATDRL_Character::Input_AlternativeWalk_Implementation(const bool Pressed)
{
}

void ATDRL_Character::Input_ChangeItemSlot_Implementation(const uint8 Slot)
{
}

void ATDRL_Character::Input_Drop_Implementation(const bool Pressed)
{
}

void ATDRL_Character::Input_Pickup_Implementation(const bool Pressed)
{
}

void ATDRL_Character::Input_Move_Implementation(const FVector Direction)
{
}

void ATDRL_Character::Input_PrimaryAction_Implementation(const bool Pressed)
{
}

void ATDRL_Character::Input_SecondaryAction_Implementation(const bool Pressed)
{
}

void ATDRL_Character::Input_RotateCamera_Implementation(const float Value)
{
}

void ATDRL_Character::Input_LockTarget_Implementation(const bool Pressed)
{
}

void ATDRL_Character::Input_Jump_Implementation(const bool Pressed)
{
}

void ATDRL_Character::Input_Crouch_Implementation(const bool Pressed)
{
}

void ATDRL_Character::Input_RAction_Implementation(const bool Pressed)
{
}

/* Damage system */

void ATDRL_Character::Dash(const bool Enable)
{
	if (!IsLocallyControlled())
	{
		return;
	}

	if (GetEquippedItem())
	{
		if (!GetEquippedItem()->IsItemGlobalTimerOver())
		{
			return;
		}
	}

	UTDRL_CharacterMovementComponent* MovComp = GetTDRLMovementComponent();

	if (MovComp)
	{
		MovComp->Dash(Enable);
	}
}

bool ATDRL_Character::IsDashing()
{
	return GetTDRLMovementComponent()->IsDashing();
}

ATDRL_NPCController* ATDRL_Character::GetNPCController() const
{
	return Cast<ATDRL_NPCController>(GetController());
}

ATDRL_Item* ATDRL_Character::GetItemByClass(const TSubclassOf<ATDRL_Item> InClass, int32& IndexOut)
{
	IndexOut = -1;
	ATDRL_Item* OutItem = nullptr;
	for (int32 i = 0; i < Inventory.Num(); i++)
	{
		if (Inventory[i])
		{
			if (Inventory[i]->GetClass() == InClass)
			{
				OutItem = Inventory[i];
				IndexOut = i;
				break;
			}
		}
	}

	return OutItem;
}

float ATDRL_Character::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
                                  AActor* DamageCauser)
{
	/*HitResult hitRes;
	FVector Dir;
	DamageEvent.GetBestHitInfo(this, DamageCauser, hitRes, Dir);
	Dir.Normalize();*/

	const FPointDamageEvent* PointDamageEvent = (FPointDamageEvent*)(&DamageEvent);

	// ...

	return Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
}

void ATDRL_Character::Stun(const FStunParameters StunParam, const FVector Direction, const FName Bone)
{
	if (GetLocalRole() == ROLE_SimulatedProxy)
	{
		return;
	}

	switch (GetLocalRole())
	{
	case ENetRole::ROLE_Authority:
		Stun_Func(StunParam, Direction, Bone);
		break;
	case ENetRole::ROLE_AutonomousProxy:
		Stun_Server(StunParam, Direction, Bone);
		break;
	}
}

void ATDRL_Character::Stun_Server_Implementation(const FStunParameters StunParam, const FVector Direction,
                                                 const FName Bone)
{
	Stun_Func(StunParam, Direction, Bone);
}

void ATDRL_Character::Stun_Func(const FStunParameters StunParam, const FVector Direction, const FName Bone)
{
	LaunchCharacter(Direction.GetSafeNormal() * StunParam.Force, true, true);

	if (StunParam.StunAnimationLoop)
	{
		PlayAnimMontage(StunParam.StunAnimationLoop);
	}

	if (StunParam.bDropWeapon && SelectedItemSlot > 0)
	{
		DropItem(SelectedItemSlot);
	}

	GetCharacterMovement()->bUseControllerDesiredRotation = false;
	Input_PrimaryAction(false);
	Input_SecondaryAction(false);
	Input_RAction(false);

	CurrentStun = StunParam;

	GetWorld()->GetTimerManager().SetTimer(StunTimerHandle, this, &ATDRL_Character::ClearStun_Func, StunParam.Time,
	                                       false);
}

void ATDRL_Character::ClearStun()
{
	if (GetLocalRole() == ROLE_SimulatedProxy)
	{
		return;
	}

	switch (GetLocalRole())
	{
	case ENetRole::ROLE_Authority:
		ClearStun_Func();
		break;
	case ENetRole::ROLE_AutonomousProxy:
		ClearStun_Func();
		break;
	}
}

void ATDRL_Character::CharacterDeath(FDeathData OutDeathData)
{
	if (GetLocalRole() != ENetRole::ROLE_Authority || DeathInfo.IsDead())
	{
		return;
	}

	PerformPrimaryAction(false);
	PerformSecondaryAction(false);
	PerformRAction(false);
	Dash(false);
	DestroyDefaultWeapon();

	if (StunTimerHandle.IsValid())
	{
		GetWorld()->GetTimerManager().ClearTimer(StunTimerHandle);
		StunTimerHandle.Invalidate();
		CurrentStun.Clear();
	}

	if (GetEquippedItem())
	{
		GetEquippedItem()->ClearItemGlobalTimer();
	}

	if (!OutDeathData.Character)
	{
		OutDeathData.Character = this;
	}

	DeathInfo = OutDeathData;
	DeathInfo.bIsDead = true;
	OnDeath.Broadcast(OutDeathData);
	Death(OutDeathData);
}

void ATDRL_Character::OnRep_DeathInfo()
{
	OnDeath.Broadcast(DeathInfo);
	Death(DeathInfo);
}

void ATDRL_Character::Death_Implementation(const FDeathData OutDeathData)
{
}

void ATDRL_Character::ClearStun_Server_Implementation()
{
	ClearStun_Func();
}

void ATDRL_Character::ClearStun_Func()
{
	GetCharacterMovement()->bUseControllerDesiredRotation = true;
	StopAnimMontage(CurrentStun.StunAnimationLoop);
	CurrentStun.Clear();

	if (StunTimerHandle.IsValid())
	{
		StunTimerHandle.Invalidate();
	}
}

void ATDRL_Character::InitializeDefaultAttributeValues()
{
	if (!AbilityComponent || !DefaultAttributeEffect)
	{
		return;
	}

	FGameplayEffectContextHandle EffectContext = AbilityComponent->MakeEffectContext();
	EffectContext.AddSourceObject(this);

	FGameplayEffectSpecHandle SpecHandle = AbilityComponent->MakeOutgoingSpec(DefaultAttributeEffect, 1, EffectContext);

	if (SpecHandle.IsValid())
	{
		FActiveGameplayEffectHandle GEHandle = AbilityComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
	}
}

void ATDRL_Character::GiveInitialAbilities()
{
	if (!HasAuthority() || !AbilityComponent)
	{
		return;
	}

	for (TSubclassOf<UTDRL_GASGameplayAbility>& StartupAbility : DefaultAbilities)
	{
		AbilityComponent->GiveAbility(FGameplayAbilitySpec(StartupAbility, 1,
		                                                   static_cast<int32>(StartupAbility.GetDefaultObject()->
			                                                   AbilityInputID), this));
	}
}
