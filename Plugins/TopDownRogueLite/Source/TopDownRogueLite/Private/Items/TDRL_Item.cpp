// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_Item.h"
#include "TDRL_Character.h"
#include "TDRL_BFL_Global.h"
#include "TDRL_GASGameplayAbility.h"

#include "AbilitySystemComponent.h"
#include "Animation/AnimInstance.h"

#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ATDRL_Item::ATDRL_Item()
	: Super()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	SetRootComponent(Capsule);
	Capsule->SetCollisionProfileName("OverlapAllDynamic");
	FCollisionResponseContainer NewRespCont;
	Capsule->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	Capsule->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Block);
	Capsule->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Block);
	Capsule->SetCollisionResponseToChannel(ECollisionChannel::ECC_PhysicsBody, ECollisionResponse::ECR_Block);
	Capsule->SetCollisionResponseToChannel(ECollisionChannel::ECC_Vehicle, ECollisionResponse::ECR_Block);
	Capsule->SetCollisionResponseToChannel(ECollisionChannel::ECC_Destructible, ECollisionResponse::ECR_Block);
	Capsule->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	MeshOffset = CreateDefaultSubobject<USceneComponent>(TEXT("MeshOffset"));
	MeshOffset->SetupAttachment(Capsule);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(MeshOffset);
	Mesh->SetCustomDepthStencilValue(255);
	Mesh->SetCollisionProfileName("OverlapAllDynamic");
	Mesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	Mesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);
	Mesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Block);
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}

// Called when the game starts or when spawned
void ATDRL_Item::BeginPlay()
{
	Super::BeginPlay();

	if (bStaticInteractable)
	{
		SetupSkeletalMeshComponent();

		if (SkeletalMesh)
		{
			Mesh->SetVisibility(false, false);
			SkeletalMesh->SetVisibility(true, true);
		}
	}
}

void ATDRL_Item::SetupSkeletalMeshComponent()
{
	if (!StaticData.SkeletalMesh)
	{
		return;
	}

	SkeletalMesh = NewObject<USkeletalMeshComponent>(
		this, MakeUniqueObjectName(this, USkeletalMeshComponent::StaticClass(), "ItemSkeletalMesh"));
	SkeletalMesh->SetSkeletalMesh(StaticData.SkeletalMesh);
	SkeletalMesh->RegisterComponent();
	SkeletalMesh->AttachToComponent(GetMeshComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
	SkeletalMesh->SetVisibility(false, true);
	SkeletalMesh->CustomDepthStencilValue = Mesh->CustomDepthStencilValue;

	for (int32 i = 0; i < Mesh->GetMaterials().Num() && i < SkeletalMesh->GetMaterials().Num(); i++)
	{
		SkeletalMesh->SetMaterial(i, Mesh->GetMaterials()[i]);
	}

	if (StaticData.AnimBlueprint)
	{
		SkeletalMesh->SetAnimInstanceClass(StaticData.AnimBlueprint);
	}
}

void ATDRL_Item::RemoveSkeletalMeshComponent()
{
	if (!SkeletalMesh)
	{
		return;
	}

	SkeletalMesh->DestroyComponent();
	SkeletalMesh = nullptr;
}

void ATDRL_Item::UpdateOwnerGAS(UAbilitySystemComponent* AbilitySystem, const EItemInteractions InteractionType)
{
	if (!StaticData.GASData.HasAny(InteractionType) || !HasAuthority() || !AbilitySystem)
	{
		return;
	}

	UpdateOwnerGASAbilities(AbilitySystem, InteractionType);
	UpdateOwnerGASEffects(AbilitySystem, InteractionType);
}

void ATDRL_Item::UpdateOwnerGASAbilities(UAbilitySystemComponent* AbilitySystem,
                                         const EItemInteractions InteractionType)
{
	if (!StaticData.GASData.HasAbilities(InteractionType) || !HasAuthority() || !AbilitySystem)
	{
		return;
	}

	switch (InteractionType)
	{
	case EItemInteractions::II_Pickup:

		for (TSubclassOf<UTDRL_GASGameplayAbility>& CAbility : StaticData.GASData.AddOnPickup.Abilities)
		{
			AbilitySystem->GiveAbility(FGameplayAbilitySpec(CAbility, 1,
			                                                static_cast<int32>(CAbility.GetDefaultObject()->
				                                                AbilityInputID), this));
		}
		for (TSubclassOf<UTDRL_GASGameplayAbility>& CAbility : StaticData.GASData.RemoveOnPickup.Abilities)
		{
			FGameplayAbilitySpec* SpecFound = AbilitySystem->FindAbilitySpecFromClass(CAbility);
			if (SpecFound)
			{
				AbilitySystem->ClearAbility(SpecFound->Handle);
			}
		}

		break;
	case EItemInteractions::II_Drop:
		for (TSubclassOf<UTDRL_GASGameplayAbility>& CAbility : StaticData.GASData.AddOnDrop.Abilities)
		{
			AbilitySystem->GiveAbility(FGameplayAbilitySpec(CAbility, 1,
			                                                static_cast<int32>(CAbility.GetDefaultObject()->
				                                                AbilityInputID), this));
		}
		for (TSubclassOf<UTDRL_GASGameplayAbility>& CAbility : StaticData.GASData.RemoveOnDrop.Abilities)
		{
			FGameplayAbilitySpec* SpecFound = AbilitySystem->FindAbilitySpecFromClass(CAbility);
			if (SpecFound)
			{
				AbilitySystem->ClearAbility(SpecFound->Handle);
			}
		}

		break;
	case EItemInteractions::II_Equip:
		for (TSubclassOf<UTDRL_GASGameplayAbility>& CAbility : StaticData.GASData.AddOnEquipped.Abilities)
		{
			AbilitySystem->GiveAbility(FGameplayAbilitySpec(CAbility, 1,
			                                                static_cast<int32>(CAbility.GetDefaultObject()->
				                                                AbilityInputID), this));
		}
		for (TSubclassOf<UTDRL_GASGameplayAbility>& CAbility : StaticData.GASData.RemoveOnEquipped.Abilities)
		{
			FGameplayAbilitySpec* SpecFound = AbilitySystem->FindAbilitySpecFromClass(CAbility);
			if (SpecFound)
			{
				AbilitySystem->ClearAbility(SpecFound->Handle);
			}
		}

		break;
	case EItemInteractions::II_Holster:
		for (TSubclassOf<UTDRL_GASGameplayAbility>& CAbility : StaticData.GASData.AddOnHolstered.Abilities)
		{
			AbilitySystem->GiveAbility(FGameplayAbilitySpec(CAbility, 1,
			                                                static_cast<int32>(CAbility.GetDefaultObject()->
				                                                AbilityInputID), this));
		}
		for (TSubclassOf<UTDRL_GASGameplayAbility>& CAbility : StaticData.GASData.RemoveOnHolstered.Abilities)
		{
			FGameplayAbilitySpec* SpecFound = AbilitySystem->FindAbilitySpecFromClass(CAbility);
			if (SpecFound)
			{
				AbilitySystem->ClearAbility(SpecFound->Handle);
			}
		}

		break;
	}
}

void ATDRL_Item::UpdateOwnerGASEffects(UAbilitySystemComponent* AbilitySystem, const EItemInteractions InteractionType)
{
	if (!StaticData.GASData.HasEffects(InteractionType) || !HasAuthority() || !AbilitySystem)
	{
		return;
	}

	FGameplayEffectContextHandle EffectContext = AbilitySystem->MakeEffectContext();
	EffectContext.AddSourceObject(AbilitySystem->GetOwner());

	switch (InteractionType)
	{
	case EItemInteractions::II_Pickup:
		for (TSubclassOf<UGameplayEffect>& CEffect : StaticData.GASData.AddOnPickup.Effects)
		{
			FGameplayEffectSpecHandle SpecHandle = AbilitySystem->MakeOutgoingSpec(CEffect, 1, EffectContext);
			AbilitySystem->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
		}
		for (TSubclassOf<UGameplayEffect>& CEffect : StaticData.GASData.RemoveOnPickup.Effects)
		{
			AbilitySystem->RemoveActiveGameplayEffectBySourceEffect(CEffect, AbilitySystem);
		}

		break;
	case EItemInteractions::II_Drop:
		for (TSubclassOf<UGameplayEffect>& CEffect : StaticData.GASData.AddOnDrop.Effects)
		{
			FGameplayEffectSpecHandle SpecHandle = AbilitySystem->MakeOutgoingSpec(CEffect, 1, EffectContext);
			AbilitySystem->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
		}
		for (TSubclassOf<UGameplayEffect>& CEffect : StaticData.GASData.RemoveOnDrop.Effects)
		{
			AbilitySystem->RemoveActiveGameplayEffectBySourceEffect(CEffect, AbilitySystem);
		}

		break;
	case EItemInteractions::II_Equip:
		for (TSubclassOf<UGameplayEffect>& CEffect : StaticData.GASData.AddOnEquipped.Effects)
		{
			FGameplayEffectSpecHandle SpecHandle = AbilitySystem->MakeOutgoingSpec(CEffect, 1, EffectContext);
			AbilitySystem->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
		}
		for (TSubclassOf<UGameplayEffect>& CEffect : StaticData.GASData.RemoveOnEquipped.Effects)
		{
			AbilitySystem->RemoveActiveGameplayEffectBySourceEffect(CEffect, AbilitySystem);
		}

		break;
	case EItemInteractions::II_Holster:
		for (TSubclassOf<UGameplayEffect>& CEffect : StaticData.GASData.AddOnHolstered.Effects)
		{
			FGameplayEffectSpecHandle SpecHandle = AbilitySystem->MakeOutgoingSpec(CEffect, 1, EffectContext);
			AbilitySystem->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
		}
		for (TSubclassOf<UGameplayEffect>& CEffect : StaticData.GASData.RemoveOnHolstered.Effects)
		{
			AbilitySystem->RemoveActiveGameplayEffectBySourceEffect(CEffect, AbilitySystem);
		}

		break;
	}
}

bool ATDRL_Item::IsItemGlobalTimerOver() const
{
	return !GlobalTimerCountdownHandle.IsValid();
}

void ATDRL_Item::ClearItemGlobalTimer()
{
	if (GlobalTimerCountdownHandle.IsValid())
	{
		GetWorld()->GetTimerManager().ClearTimer(GlobalTimerCountdownHandle);
		GlobalTimerCountdownHandle.Invalidate();
	}
}

void ATDRL_Item::EnableItemOutliner(bool Enable) const
{
	if (SkeletalMesh && bStaticInteractable)
	{
		SkeletalMesh->SetRenderCustomDepth(Enable);
	}
	else
	{
		Mesh->SetRenderCustomDepth(Enable);
		Mesh->bDisallowNanite = Enable;
	}
}

// Called every frame
void ATDRL_Item::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATDRL_Item::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ATDRL_Item, EquippedCharacter);
	DOREPLIFETIME_CONDITION(ATDRL_Item, GlobalTimerCountdownHandle, COND_OwnerOnly);
}

#if WITH_EDITOR
void ATDRL_Item::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	FName PropertyName = (PropertyChangedEvent.Property != NULL)
		                     ? PropertyChangedEvent.Property->GetFName()
		                     : NAME_None;
}
#endif

void ATDRL_Item::AssignToCharacter(ATDRL_Character* Character)
{
	if (Character)
	{
		AttachToActor((AActor*)Character, FAttachmentTransformRules::SnapToTargetIncludingScale);
		if (Character->IsHidden())
		{
			SetActorHiddenInGame(false);
		}
	}
	else
	{
		DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		GetMeshComponent()->SetVisibility(true);

		ATDRL_Character* LocalPlayerChar = UTDRL_BFL_Global::GetPlayerCharacterTDRL(this);
	}

	EquippedCharacter = Cast<ATDRL_Character>(Character);
	SetInstigator(Character);
	SetOwner((AActor*)Character);
}

void ATDRL_Item::Interact(ATDRL_Character* InteractingCharacter)
{
	Interacted(InteractingCharacter);
	OnInteract.Broadcast(InteractingCharacter);
}

void ATDRL_Item::Interacted_Implementation(ATDRL_Character* InteractingCharacter)
{
}

void ATDRL_Item::Pickup(ATDRL_Character* InteractingCharacter)
{
	PickedUp(InteractingCharacter);
	OnPickup.Broadcast(InteractingCharacter);
}

void ATDRL_Item::PickedUp_Implementation(ATDRL_Character* InteractingCharacter)
{
	SetupSkeletalMeshComponent();
	GetMeshComponent()->SetVisibility(false, true);
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ATDRL_Item::Drop(ATDRL_Character* InteractingCharacter)
{
	Dropped(InteractingCharacter);
	OnDrop.Broadcast(InteractingCharacter);
}

void ATDRL_Item::Dropped_Implementation(ATDRL_Character* InteractingCharacter)
{
	RemoveSkeletalMeshComponent();
	GetMeshComponent()->SetVisibility(true, true);
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	GetMeshComponent()->AttachToComponent(GetMeshOffsetComponent(),
	                                      FAttachmentTransformRules::SnapToTargetIncludingScale);
}

void ATDRL_Item::Equip(ATDRL_Character* InteractingCharacter)
{
	Equipped(InteractingCharacter);
	OnEquip.Broadcast(InteractingCharacter);
}

void ATDRL_Item::Equipped_Implementation(ATDRL_Character* InteractingCharacter)
{
	// Character's Animation Layer
	if (EquippedCharacter)
	{
		if (StaticData.LayerAnimInstance)
		{
			EquippedCharacter->GetMesh()->LinkAnimClassLayers(StaticData.LayerAnimInstance);
		}
		else
		{
			//EquippedCharacter->GetMesh()->LinkAnimClassLayers(nullptr);
		}
	}

	//Mesh component
	if (!GetMeshComponent())
	{
		return;
	}

	if (GetMeshComponent()->GetStaticMesh())
	{
		if (EquippedCharacter)
		{
			GetMeshComponent()->AttachToComponent(EquippedCharacter->GetMesh(),
			                                      FAttachmentTransformRules::SnapToTargetIncludingScale,
			                                      StaticData.Socket);
		}

		if (SkeletalMesh)
		{
			SkeletalMesh->SetVisibility(true, true);
		}
		else
		{
			GetMeshComponent()->SetVisibility(true, true);
		}
	}

	// Additional components
	TArray<UPrimitiveComponent*> AttachComps;
	TArray<UShapeComponent*> ShapeComps;
	TArray<UStaticMeshComponent*> StaticComps;

	GetComponents<UShapeComponent>(ShapeComps, false);
	GetComponents<UStaticMeshComponent>(StaticComps, false);
	AttachComps.Append(ShapeComps);
	AttachComps.Append(StaticComps);

	FCriticalSection Mutex;

	ParallelFor(AttachComps.Num(), [&](int32 Idx)
	{
		if (AttachComps[Idx]->ComponentTags.Num() > 0)
		{
			if (EquippedCharacter->GetMesh()->DoesSocketExist(AttachComps[Idx]->ComponentTags[0]) && AttachComps[Idx] !=
				GetMeshComponent() && (AttachComps[Idx]->GetClass()))
			{
				if (AttachComps[Idx])
				{
					Mutex.Lock();
					AttachComps[Idx]->AttachToComponent(EquippedCharacter->GetMesh(),
					                                    FAttachmentTransformRules::SnapToTargetNotIncludingScale,
					                                    AttachComps[Idx]->ComponentTags[0]);
					Mutex.Unlock();
				}
			}
		}
	});
}

void ATDRL_Item::Holster(ATDRL_Character* InteractingCharacter)
{
	Holstered(InteractingCharacter);
	OnHolster.Broadcast(InteractingCharacter);
}

void ATDRL_Item::Holstered_Implementation(ATDRL_Character* InteractingCharacter)
{
	// Mesh component
	if (!GetMeshComponent())
	{
		return;
	}

	GetMeshComponent()->AttachToComponent(GetMeshOffsetComponent(),
	                                      FAttachmentTransformRules::SnapToTargetIncludingScale);

	if (SkeletalMesh)
	{
		SkeletalMesh->SetVisibility(false, true);
	}
	else
	{
		GetMeshComponent()->SetVisibility(false, true);
	}

	// Additional components
	TArray<UPrimitiveComponent*> AttachComps;
	TArray<UShapeComponent*> ShapeComps;
	TArray<UStaticMeshComponent*> StaticComps;

	GetComponents<UShapeComponent>(ShapeComps, false);
	GetComponents<UStaticMeshComponent>(StaticComps, false);
	AttachComps.Append(ShapeComps);
	AttachComps.Append(StaticComps);

	FCriticalSection Mutex;

	ParallelFor(AttachComps.Num(), [&](int32 Idx)
	{
		if (AttachComps[Idx]->ComponentTags.Num() < 1 || AttachComps[Idx] == GetMeshComponent())
		{
			return;
		}

		if (!EquippedCharacter->GetMesh()->DoesSocketExist(AttachComps[Idx]->ComponentTags[0]))
		{
			return;
		}

		if (AttachComps[Idx])
		{
			if (AttachComps[Idx]->ComponentTags.Num() > 0)
			{
				Mutex.Lock();
				AttachComps[Idx]->AttachToComponent(GetRootComponent(),
				                                    FAttachmentTransformRules::SnapToTargetIncludingScale, FName());
				Mutex.Unlock();
			}
		}
	});
}

void ATDRL_Item::PrimaryAction_Implementation(const bool Enabled)
{
}

void ATDRL_Item::SecondaryAction_Implementation(const bool Enabled)
{
}

void ATDRL_Item::RAction_Implementation(const bool Enabled)
{
}

void ATDRL_Item::PlayAnimMontageOnOwningCharacter(UAnimMontage* AttackMontage, const float Rate)
{
	if (!AttackMontage || !EquippedCharacter)
	{
		return;
	}

	switch (GetNetMode())
	{
	case ENetMode::NM_Client:
		return;
	case ENetMode::NM_DedicatedServer:
	case ENetMode::NM_ListenServer:
		PlayAnimMontageOnOwningCharacter_Clients(AttackMontage, Rate);
		break;
	case ENetMode::NM_Standalone:
		PlayAnimMontageOnOwningCharacter_Func(AttackMontage, Rate);
		break;
	}
}

void ATDRL_Item::PlayAnimMontageOnOwningCharacter_Clients_Implementation(UAnimMontage* AttackMontage, const float Rate)
{
	PlayAnimMontageOnOwningCharacter_Func(AttackMontage, Rate);
}

void ATDRL_Item::PlayAnimMontageOnOwningCharacter_Func(UAnimMontage* AttackMontage, const float Rate)
{
	if (!AttackMontage)
	{
		return;
	}

	if (EquippedCharacter)
	{
		const float AttackAnimLength = EquippedCharacter->PlayAnimMontage(AttackMontage, Rate, FName());
	}
}
