// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TDRL_ItemTypes.h"
#include "TDRL_Item.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteractedDelegate, class ATDRL_Character*, InteractingCharacter);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPickedUpDelegate, class ATDRL_Character*, InteractingCharacter);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDroppedDelegate, class ATDRL_Character*, InteractingCharacter);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEquippedDelegate, class ATDRL_Character*, InteractingCharacter);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHolsteredDelegate, class ATDRL_Character*, InteractingCharacter);

UCLASS()
class TOPDOWNROGUELITE_API ATDRL_Item : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATDRL_Item();

	/* Is this Item static? "Pickup" will be disabled and "Interaction" will be used instead*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDRL|Data|Item")
	uint8 bStaticInteractable : 1;
	/* Static Data structure for Items*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDRL|Data|Item")
	FItemStaticData StaticData;
	/* Should enable Visual Debug? Mainly used for traces.*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDRL|Data|Item")
	uint8 bEnableVisualDebug : 1;

	/*Will return the character holding this item. Must be equipped!*/
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "TDRL|Item|Runtime")
	class ATDRL_Character* EquippedCharacter;

	/*Interact delegate*/
	UPROPERTY(BlueprintAssignable, Category = "TDRL|Item|Delegates")
	FOnInteractedDelegate OnInteract;
	/*Pickup delegate*/
	UPROPERTY(BlueprintAssignable, Category = "TDRL|Item|Delegates")
	FOnPickedUpDelegate OnPickup;
	/*Drop delegate*/
	UPROPERTY(BlueprintAssignable, Category = "TDRL|Item|Delegates")
	FOnDroppedDelegate OnDrop;
	/*Equip delegate*/
	UPROPERTY(BlueprintAssignable, Category = "TDRL|Item|Delegates")
	FOnEquippedDelegate OnEquip;
	/*Holster delegate*/
	UPROPERTY(BlueprintAssignable, Category = "TDRL|Item|Delegates")
	FOnHolsteredDelegate OnHolster;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* Capsule;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class USceneComponent* MeshOffset;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* Mesh;

	UPROPERTY(Replicated)
	FTimerHandle GlobalTimerCountdownHandle;

	/*Runtime skeletal mesh component. Will be spawned and used when the weapon is equipped. Leave clear if you want to use the default static mesh*/
	UPROPERTY(BlueprintReadOnly, Category = "TDRL|Item|Runtime")
	USkeletalMeshComponent* SkeletalMesh;

	UFUNCTION()
	virtual void SetupSkeletalMeshComponent();
	UFUNCTION()
	virtual void RemoveSkeletalMeshComponent();

	UFUNCTION()
	virtual void UpdateOwnerGASAbilities(class UAbilitySystemComponent* AbilitySystem,
	                                     const EItemInteractions InteractionType);
	UFUNCTION()
	virtual void UpdateOwnerGASEffects(class UAbilitySystemComponent* AbilitySystem,
	                                   const EItemInteractions InteractionType);

public:
	UFUNCTION()
	virtual void UpdateOwnerGAS(class UAbilitySystemComponent* AbilitySystem, const EItemInteractions InteractionType);
	/*Return true if the global timer is over and the item can perform a new task*/
	UFUNCTION(BlueprintPure, Category = "TDRL|Item|GlobalTimer")
	bool IsItemGlobalTimerOver() const;
	UFUNCTION(BlueprintCallable, Category = "TDRL|Item|GlobalTimer")
	void ClearItemGlobalTimer();

	/*Return the Capsule component*/
	UFUNCTION(BlueprintPure, Category = "TDRL|Item|Components",
		meta = (DisplayName = "GetCapsuleComponent", CompactNodeTitle = "Capsule", Keywords =
			"Get Spawned Character TDRL"))
	virtual UCapsuleComponent* GetCapsuleComponent() const
	{
		return Capsule;
	}

	/*Return the MeshOffset component*/
	UFUNCTION(BlueprintPure, Category = "TDRL|Item|Components",
		meta = (DisplayName = "GetMeshOffsetComponent", CompactNodeTitle = "MeshOffset", Keywords =
			"Get Spawned Character TDRL"))
	virtual USceneComponent* GetMeshOffsetComponent() const
	{
		return MeshOffset;
	}

	/*Return the Mesh component*/
	UFUNCTION(BlueprintPure, Category = "TDRL|Item|Components",
		meta = (DisplayName = "GetMeshComponent", CompactNodeTitle = "Mesh", Keywords = "Get Spawned Character TDRL"))
	virtual UStaticMeshComponent* GetMeshComponent() const
	{
		if (!Mesh)
		{
			return nullptr;
		}

		return Mesh;
	}

	/*Enable/disable its Outliner*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|Item|Components",
		meta = (DisplayName = "EnableItemOutliner", CompactNodeTitle = "OutlinerOn", Keywords =
			"Get Spawned Character TDRL"))
	virtual void EnableItemOutliner(bool Enable) const;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

	/*Assign this item to a character. This way the item is binded to a specific character and can't be stolen*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|Item",
		meta = (DisplayName = "AssignToCharacter", Keywords = "Assign To Character TDRL"))
	virtual void AssignToCharacter(class ATDRL_Character* Character);

	UFUNCTION()
	virtual void Interact(class ATDRL_Character* InteractingCharacter);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "TDRL|Item|Input",
		meta = (DisplayName = "Interacted", Keywords = "Interacted TDRL"))
	void Interacted(class ATDRL_Character* InteractingCharacter);

	UFUNCTION()
	virtual void Pickup(class ATDRL_Character* InteractingCharacter);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "TDRL|Item|Input",
		meta = (DisplayName = "PickedUp", Keywords = "PickedUp TDRL"))
	void PickedUp(class ATDRL_Character* InteractingCharacter);
	UFUNCTION()
	virtual void Drop(class ATDRL_Character* InteractingCharacter);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "TDRL|Item|Input",
		meta = (DisplayName = "Dropped", Keywords = "Dropped TDRL"))
	void Dropped(class ATDRL_Character* InteractingCharacter);

	UFUNCTION()
	virtual void Equip(class ATDRL_Character* InteractingCharacter);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "TDRL|Item|Input",
		meta = (DisplayName = "Equipped", Keywords = "Equipped TDRL"))
	void Equipped(class ATDRL_Character* InteractingCharacter);
	UFUNCTION()
	virtual void Holster(class ATDRL_Character* InteractingCharacter);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "TDRL|Item|Input",
		meta = (DisplayName = "Holstered", Keywords = "Holstered TDRL"))
	void Holstered(class ATDRL_Character* InteractingCharacter);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, BlueprintAuthorityOnly, Category = "TDRL|Item|Input",
		meta = (DisplayName = "PrimaryAction", Keywords = "Primary Action TDRL"))
	void PrimaryAction(const bool Enabled);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, BlueprintAuthorityOnly, Category = "TDRL|Item|Input",
		meta = (DisplayName = "SecondaryAction", Keywords = "Secondary Action TDRL"))
	void SecondaryAction(const bool Enabled);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, BlueprintAuthorityOnly, Category = "TDRL|Item|Input",
		meta = (DisplayName = "RAction", Keywords = "RAction TDRL"))
	void RAction(const bool Enabled);

	/*This function will play an AnimMontage (usually attacks) to the owning pawn's skeletal mesh component*/
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category = "TDRL|Item|Animations",
		meta = (DisplayName = "PlayAnimMontageOnOwningCharacter", Keywords =
			"Play Anim Montage AnimMontage On Owning Character TDRL NPCSpawn"))
	virtual void PlayAnimMontageOnOwningCharacter(UAnimMontage* AttackMontage, const float Rate = 1.0f);
	UFUNCTION(NetMulticast, Reliable)
	virtual void PlayAnimMontageOnOwningCharacter_Clients(UAnimMontage* AttackMontage, const float Rate = 1.0f);
	UFUNCTION()
	virtual void PlayAnimMontageOnOwningCharacter_Func(UAnimMontage* AttackMontage, const float Rate = 1.0f);
};
