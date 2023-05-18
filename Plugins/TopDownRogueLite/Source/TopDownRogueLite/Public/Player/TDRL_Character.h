// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"

#include "TDRL_GameplayTypes.h"
#include "TDRL_Item.h"
#include "TDRL_Character.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDeathDelegate, FDeathData, DeathData);

USTRUCT(BlueprintType)
struct TOPDOWNROGUELITE_API FCameraTraceOcclusionParams
{
	GENERATED_USTRUCT_BODY()

	// Controls控制
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TraceOcclusion|Controls")
	uint8 bUseCameraOcclusionTrace : 1;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TraceOcclusion|Controls")
	uint8 bUseCameraOcclusionPostProcess : 1;

	// All
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TraceOcclusion")
	float StartForwardOffset = 200.0f;

	// Occlusion遮挡
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TraceOcclusion|Occlusion")
	FVector2D SizeFactor = FVector2D(5.0f, 3.0f);
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TraceOcclusion|Occlusion")
	TSet<TEnumAsByte<EObjectTypeQuery>> TraceChannels;
	// = TSet<TEnumAsByte<ECollisionChannel>>{ ECollisionChannel::ECC_WorldStatic };

	// Post Process后处理
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TraceOcclusion|PostProcess")
	TSet<TSubclassOf<AActor>> PostProcessAvoid = TSet<TSubclassOf<AActor>>();


	FCameraTraceOcclusionParams()
	{
		bUseCameraOcclusionTrace = true;
		bUseCameraOcclusionPostProcess = true;
		StartForwardOffset = 200.0f;

		//TraceChannels = TSet<TEnumAsByte<ECollisionChannel>>{ECollisionChannel::ECC_WorldStatic};
		PostProcessAvoid = TSet<TSubclassOf<AActor>>();

		SizeFactor = FVector2D(5.0f, 3.0f);
	}
};

UCLASS(Blueprintable, BlueprintType)
class TOPDOWNROGUELITE_API ATDRL_Character : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATDRL_Character(const FObjectInitializer& ObjInit);
	virtual void PostInitializeComponents() override;
	virtual void BeginDestroy() override;

#pragma region GlobalPostProcess

	/*Global post process. This material instance must follow the example material asset structure.*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TDRL|Character|PostProcess")
	class UMaterialInstance* GlobalPostProcess;
	UPROPERTY()
	class UMaterialInstanceDynamic* PostProcessInUse;
	UFUNCTION()
	void ApplyDynamicMaterialPostProcess();
	UFUNCTION()
	void RemoveDynamicMaterialPostProcess();

#pragma endregion

#pragma region GAS

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	/*Default Attribute Effect to apply when spawned*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TDRL|Character|Abilities")
	TSubclassOf<class UGameplayEffect> DefaultAttributeEffect;
	UFUNCTION()
	virtual void InitializeDefaultAttributeValues();
	/*List of default abilities to add when spawned*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TDRL|Character|Abilities")
	TArray<TSubclassOf<class UTDRL_GASGameplayAbility>> DefaultAbilities;
	UFUNCTION()
	virtual void GiveInitialAbilities();

#pragma endregion

#pragma region Health

	/*Max Character's health*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TDRL|Character|Health")
	float MaxHealth = 100.0f;
	/*Current Character's health*/
	UPROPERTY(ReplicatedUsing = OnRep_HealthModified, BlueprintReadOnly, Category = "TDRL|Character|Health|Runtime")
	float Health = 100.0f;
	UFUNCTION()
	virtual void OnRep_HealthModified(const float Previous);
	/*Set health (Server Only)*/
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category = "TDRL|Character|Health",
		meta = (DisplayName = "SetHealth", Keywords = "Set Health TDRL"))
	virtual void SetHealth(const float Value);
	/*Get health percentage (Health/MaxHealth)*/
	UFUNCTION(BlueprintPure, Category = "TDRL|Character|Health",
		meta = (DisplayName = "GetHealthPercentage", Keywords = "Get Health Percentage TDRL"))
	virtual float GetHealthPercentage() const
	{
		return Health / MaxHealth;
	}

	/*Heal character (Server Only)*/
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category = "TDRL|Character|Health",
		meta = (DisplayName = "Heal", Keywords = "Heal Health TDRL"))
	virtual bool Heal(const float Value, FStatusEffect Effect);
	UFUNCTION(NetMulticast, Unreliable)
	virtual void Heal_Effects(const FStatusEffect Value);

#pragma endregion

#pragma region CameraOcclusion
	/*Player's camera occlusion parameters*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TDRL|Character|TraceOcclusion")
	FCameraTraceOcclusionParams OcclusionParam = FCameraTraceOcclusionParams();

protected:
	UPROPERTY()
	TArray<class UTDRL_CameraOcclusionComponent*> CameraOccludingComponents;

#pragma endregion

public:
#pragma region AimOffset

	/*Aim Offset value to apply*/
	UPROPERTY(BlueprintReadOnly, Replicated, Category = "TDRL|Character", meta = (AllowPrivateAccess = "true"))
	FVector2D AimOffsetValue;
	/*Set the current AimOffset value for this character*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|Character",
		meta = (DisplayName = "SetAimOffsetValue", Keywords = "Set Aim Offset Value TDRL"))
	virtual void SetAimOffsetValue(const FVector2D NewAimOffsetValue)
	{
		AimOffsetValue = NewAimOffsetValue;
	}

#pragma endregion

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	virtual void UnPossessed() override;

#pragma region Components

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraSpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UTDRL_LineOfSightComponent* SightComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UAbilitySystemComponent> AbilityComponent;
	UPROPERTY()
	TObjectPtr<class UTDRL_GASAttributeSet> AttributeSet;

#pragma endregion

public:
#pragma region Components

	/*Return the UCharacterMovementComponent as UTDRL_CharacterMovementComponen*/
	UFUNCTION(BlueprintPure, Category = "TDRL|Components",
		meta = (DisplayName = " GetCharacterMovement(TDRL)", Keywords = "Get Character Movement Component TDRL"))
	class UTDRL_CharacterMovementComponent* GetTDRLMovementComponent() const;
	/*Return the Character's Spring Arm*/
	UFUNCTION(BlueprintPure, Category = "TDRL|Components",
		meta = (DisplayName = " GetCameraSpringArm", Keywords = "Get Camera Spring Arm TDRL"))
	class USpringArmComponent* GetCameraSpringArm() const
	{
		return CameraSpringArm;
	}

	/*Return the Character's camera*/
	UFUNCTION(BlueprintPure, Category = "TDRL|Components",
		meta = (DisplayName = " GetCamera", Keywords = "Get Camera TDRL"))
	class UCameraComponent* GetCamera() const
	{
		return Camera;
	}

	/*Return the Character's AbilityComponent*/
	UFUNCTION(BlueprintPure, Category = "TDRL|Components",
		meta = (DisplayName = " GetAbilityComponent", Keywords = "Get Ability Component TDRL"))
	class UAbilitySystemComponent* GetAbilityComponent() const
	{
		return AbilityComponent;
	}

	/*Return the Character's SightComponent*/
	UFUNCTION(BlueprintPure, Category = "TDRL|Components",
		meta = (DisplayName = " GetSightComponent", Keywords = "Get Sight Component TDRL"))
	class UTDRL_LineOfSightComponent* GetSightComponent() const
	{
		return SightComponent;
	}

#pragma endregion

#pragma region Tick

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	virtual void TickCameraOcclusionTrace();
	UFUNCTION()
	virtual void TraceForCameraOcclusion(const FVector InStart, const FVector InEnd, const FRotator InOrientation);
	UFUNCTION()
	virtual void TraceForPostProcessOcclusion(const FVector InStart, const FVector InEnd, const FRotator InOrientation);
	UFUNCTION()
	virtual void TickCameraOrientation();

#pragma endregion
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

#pragma region Inventory

	/*Amount of initial inventory slots. Does not affect runtime gameplay.*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TDRL|Character|Inventory")
	uint8 InitialInventorySlots = 3;

	/*Default weapon class*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TDRL|Character|Inventory")
	TSubclassOf<class ATDRL_Melee> DefaultWeaponClass;
	/*Default weapon pointer (once spawned and assigned)*/
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MainWeaponModified,
		Category = "TDRL|Character|Inventory|Runtime")
	class ATDRL_Melee* MainWeapon;

	UFUNCTION()
	virtual void OnRep_MainWeaponModified();
	UFUNCTION(Server, Reliable)
	void SpawnDefaultWeapon();
	UFUNCTION(Server, Reliable)
	void DestroyDefaultWeapon();

	/*Current selected slot*/
	UPROPERTY(ReplicatedUsing = OnRep_SlotSelectionModified, BlueprintReadOnly,
		Category = "TDRL|Character|Inventory|Runtime")
	uint8 SelectedItemSlot;
	/*Set the current "SelectedItemSlot"*/
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "TDRL|Character|Inventory",
		meta = (DisplayName = "SetInventorySlotsAmount", Keywords = "Set Inventory Slots Amount TDRL"))
	void SetInventorySlotsAmount(const uint8 Slots);
	UFUNCTION()
	virtual void OnRep_SlotSelectionModified(const uint8 Previous);

	/*Item inventory*/
	UPROPERTY(ReplicatedUsing = OnRep_InventoryModified, VisibleDefaultsOnly, BlueprintReadOnly,
		Category = "TDRL|Character|Inventory|Runtime")
	TArray<class ATDRL_Item*> Inventory;
	UFUNCTION()
	virtual void OnRep_InventoryModified(const TArray<class ATDRL_Item*> Previous);

	/*Reachable radius when looking for interactable items*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TDRL|Character|Inventory")
	float ItemTraceRadius = 150.0f;
	/*Channels to trace for Items*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TDRL|Character|Inventory")
	TSet<TEnumAsByte<EObjectTypeQuery>> TraceForItemsChannels;
	//= TSet<TEnumAsByte<ECollisionChannel>>{ ECollisionChannel::ECC_WorldStatic,  ECollisionChannel::ECC_WorldDynamic, ECollisionChannel::ECC_PhysicsBody };

	/*Nearest nearby index of "NearbyItems"*/
	UPROPERTY(BlueprintReadOnly, Category = "TDRL|Character|Inventory|Runtime")
	uint8 NearestNearbyItemIndex;
	/*List of traced Nearby Items*/
	UPROPERTY(BlueprintReadOnly, Category = "TDRL|Character|Inventory|Runtime")
	TArray<class ATDRL_Item*> NearbyItems;

	/*Show interaction Debug*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TDRL|Character|Inventory|Debug")
	uint8 bDebugShowTraceForItems : 1;

protected:
	UPROPERTY()
	FTimerHandle TraceItemTimerHandle;

public:
	/*Enable / Disable trace for nearby items*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|Character|Inventory",
		meta = (DisplayName = "EnableTraceForNearbyItems", Keywords = "Enable Trace For Nearby Items TDRL"))
	void EnableTraceForNearbyItems(const bool Enable);
	UFUNCTION(Server, Reliable)
	void EnableTraceForNearbyItems_Server(const bool Enable);
	UFUNCTION(Client, Reliable)
	void EnableTraceForNearbyItems_Func(const bool Enable);
	UFUNCTION()
	void TraceForNearbyItems();

	/*Return true if there's at least one nearby item*/
	UFUNCTION(BlueprintPure, Category = "TDRL|Character|Inventory",
		meta = (DisplayName = "HasNearbyItems", Keywords = "Has Nearby Items TDRL"))
	bool HasNearbyItems() const
	{
		return NearbyItems.Num() > 0;
	}

	/*Return the nearest nearby item*/
	UFUNCTION(BlueprintPure, Category = "TDRL|Character|Inventory",
		meta = (DisplayName = "GetNearestNearbyItem", Keywords = "Get Nearest Nearby Item TDRL"))
	class ATDRL_Item* GetNearestNearbyItem() const
	{
		if (NearbyItems.Num() > NearestNearbyItemIndex)
		{
			return NearbyItems[NearestNearbyItemIndex];
		}

		return nullptr;
	}

	/*Return the current equipped Item*/
	UFUNCTION(BlueprintPure, Category = "TDRL|Character|Inventory",
		meta = (DisplayName = "GetEquippedItem", Keywords = "Get Equipped Item TDRL"))
	class ATDRL_Item* GetEquippedItem() const;

	/*Pickup nearest item*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|Character|Item",
		meta = (DisplayName = "PickupItem", Keywords = "Pickup Item TDRL"))
	void PickupItem(class ATDRL_Item* Item);
	UFUNCTION(Server, Reliable)
	void PickupItem_Server(class ATDRL_Item* Item);
	UFUNCTION()
	void PickupItem_Func(class ATDRL_Item* Item);

	/*Drop equipped item*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|Character|Item",
		meta = (DisplayName = "DropItem", Keywords = "Drop Item TDRL"))
	void DropItem(const uint8 Slot);
	UFUNCTION(BlueprintCallable, Category = "TDRL|Character|Item",
		meta = (DisplayName = "DropEquippedItem", Keywords = "Drop Equipped Item TDRL"))
	void DropEquippedItem();
	UFUNCTION(Server, Reliable)
	void DropItem_Server(const uint8 Slot);
	UFUNCTION()
	void DropItem_Func(const uint8 Slot);

	/*Drop all the items contained in the Inventory (will not drop the main weapon)*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|Character|Inventory",
		meta = (DisplayName = "DropAllItems", Keywords = "Drop All Items TDRL"))
	virtual void DropAllItems();
	/*Destroy all the items contained in the Inventory (can decide if affects the Main Weapon too)*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|Character|Inventory",
		meta = (DisplayName = "DestroyAllItems", Keywords = "Destroy All Items TDRL"))
	virtual void DestroyAllItems(const bool bIncludeMain);

	/*Select a specific item slot*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|Character|Inventory",
		meta = (DisplayName = "SelectItemSlot", Keywords = "Select Item Slot TDRL"))
	void SelectItemSlot(const uint8 Slot);
	UFUNCTION(Server, Reliable)
	void SelectItemSlot_Server(const uint8 Slot);
	UFUNCTION()
	void SelectItemSlot_Func(const uint8 Slot);

	/*Perform Primary Action on the Equipped Item*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|Character|Item",
		meta = (DisplayName = "PerformPrimaryAction", Keywords = "Perform Primary Action TDRL"))
	void PerformPrimaryAction(const bool Enable);
	UFUNCTION(Server, Reliable)
	void PerformPrimaryAction_Server(const bool Enable);
	UFUNCTION()
	void PerformPrimaryAction_Func(const bool Enable);

	/*Perform Secondary Action on the Equipped Item*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|Character|Item",
		meta = (DisplayName = "PerformSecondaryAction", Keywords = "Perform Secondary Action TDRL"))
	void PerformSecondaryAction(const bool Enable);
	UFUNCTION(Server, Reliable)
	void PerformSecondaryAction_Server(const bool Enable);
	UFUNCTION()
	void PerformSecondaryAction_Func(const bool Enable);

	/*Perform R Action on the Equipped Item*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|Character|Item",
		meta = (DisplayName = "PerformRAction", Keywords = "Perform R Action TDRL"))
	void PerformRAction(const bool Enable);
	UFUNCTION(Server, Reliable)
	void PerformRAction_Server(const bool Enable);
	UFUNCTION()
	void PerformRAction_Func(const bool Enable);

	/*Will return the item's index with the highest rarity value*/
	UFUNCTION(BlueprintPure, Category = "TDRL|Character|Item")
	uint8 GetHigestRarityItemSlot(const bool ShouldBeWeapon = false);
	/*Will return the item's index with the lowest rarity value*/
	UFUNCTION(BlueprintPure, Category = "TDRL|Character|Item")
	uint8 GetLowestRarityItemSlot(const bool ShouldBeWeapon = false);

	/*Return true if there's at least one item derived from the specified class*/
	UFUNCTION(BlueprintPure, Category = "TDRL|Character|Inventory",
		meta = (DisplayName = "HasItemOfClass", Keywords = "Has Item Of Class TDRL"))
	bool HasItemOfClass(const TSubclassOf<ATDRL_Item> InClass, const bool bIncludeSubclasses = false);
	/*Get first item of the specified class*/
	UFUNCTION(BlueprintPure, Category = "TDRL|Character|Inventory",
		meta = (DisplayName = "GetItemByClass", Keywords = "Get Item By Class TDRL"))
	ATDRL_Item* GetItemByClass(const TSubclassOf<ATDRL_Item> InClass, int32& IndexOut);
	/*Return the list of slots occupied by a particular drink*/
	UFUNCTION(BlueprintPure, Category = "TDRL|Character|Inventory",
		meta = (DisplayName = "GetSlotsOccupiedByItemClass", Keywords = "Get Slots Occupied By Item Class TDRL"))
	TArray<uint8> GetSlotsOccupiedByItemClass(const TSubclassOf<ATDRL_Item> InClass,
	                                          const bool bIncludeSubclasses = false);

#pragma endregion

#pragma region NativeInputs

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "TDRL|Character|Input",
		meta = (DisplayName = "Input_Move", Keywords = "Input Move TDRL"))
	void Input_Move(const FVector Direction);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "TDRL|Character|Input",
		meta = (DisplayName = "Input_Pickup", Keywords = "Input Pickup TDRL"))
	void Input_Pickup(const bool Pressed);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "TDRL|Character|Input",
		meta = (DisplayName = "Input_Drop", Keywords = "Input Drop TDRL"))
	void Input_Drop(const bool Pressed);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "TDRL|Character|Input",
		meta = (DisplayName = "Input_ChangeItemSlot", Keywords = "Input Change Item Slot TDRL"))
	void Input_ChangeItemSlot(const uint8 Slot);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "TDRL|Character|Input",
		meta = (DisplayName = "Input_Dash", Keywords = "Input Dash TDRL"))
	void Input_Dash(const bool Pressed);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "TDRL|Character|Input",
		meta = (DisplayName = "Input_AlternativeWalk", Keywords = "Input Alternative Walk TDRL"))
	void Input_AlternativeWalk(const bool Pressed);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "TDRL|Character|Input",
		meta = (DisplayName = "Input_PitchAim", Keywords = "Input PitchAim TDRL"))
	void Input_PitchAim(const bool Pressed);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "TDRL|Character|Input",
		meta = (DisplayName = "Input_PrimaryAction", Keywords = "Input Primary Action TDRL"))
	void Input_PrimaryAction(const bool Pressed);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "TDRL|Character|Input",
		meta = (DisplayName = "Input_SecondaryAction", Keywords = "Input Secondary Action TDRL"))
	void Input_SecondaryAction(const bool Pressed);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "TDRL|Character|Input",
		meta = (DisplayName = "Input_RotateCamera", Keywords = "Input Rotate Camera TDRL"))
	void Input_RotateCamera(const float Value);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "TDRL|Character|Input",
		meta = (DisplayName = "Input_LockTarget", Keywords = "Input Lock Target TDRL"))
	void Input_LockTarget(const bool Pressed);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "TDRL|Character|Input",
		meta = (DisplayName = "Input_Jump", Keywords = "Input Jump TDRL"))
	void Input_Jump(const bool Pressed);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "TDRL|Character|Input",
		meta = (DisplayName = "Input_Crouch", Keywords = "Input Crouch TDRL"))
	void Input_Crouch(const bool Pressed);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "TDRL|Character|Input",
		meta = (DisplayName = "Input_RAction", Keywords = "Input R Action TDRL"))
	void Input_RAction(const bool Pressed);

#pragma endregion

#pragma region Dash

	/*Perform Dash action if possible*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|Character|Movements",
		meta = (DisplayName = "Dash", Keywords = "Dash Perform TDRL"))
	void Dash(const bool Enable);
	/*Return true if it's currently dashing*/
	UFUNCTION(BlueprintPure, Category = "TDRL|Character|Movements",
		meta = (DisplayName = "IsDashing", Keywords = "Is Dashing TDRL"))
	bool IsDashing();

#pragma endregion

#pragma region AI

	/*Return the AIController as ATDRL_NPCController. Return null if the character is not possessed by AI or it's player possessed*/
	UFUNCTION(BlueprintPure, Category = "TDRL|Character|AI",
		meta = (DisplayName = "GetNPCController", Keywords = "Get NPC AI Controller TDRL"))
	class ATDRL_NPCController* GetNPCController() const;

#pragma endregion

#pragma region Stun
	/*Default Stun parameters for Knockback when getting normal damage*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TDRL|Character|Stun")
	FStunParameters DefaultDamageKnockback = FStunParameters();
	/*List of AnimMontage to use when the Knockbabk happen*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TDRL|Character|Stun")
	TArray<UAnimMontage*> DefaultKnockbackMontages = TArray<UAnimMontage*>();
	/*Apply the default Knockback (used when the character gets damage)*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|Character|Stun",
		meta = (DisplayName = "ApplyDefaultKnockback", Keywords = "Apply Default Knockback TDRL"))
	void ApplyDefaultKnockback(const FVector InDirection, const FName InBoneName);

	UPROPERTY(ReplicatedUsing = OnRep_CurrentStun)
	FStunParameters CurrentStun;
	UFUNCTION()
	virtual void OnRep_CurrentStun(const FStunParameters OldValue);
	UPROPERTY()
	FTimerHandle StunTimerHandle;

	/*Apply stun status*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|Character|Stun",
		meta = (DisplayName = "Stun", Keywords = "Apply Stun TDRL"))
	virtual void Stun(const FStunParameters StunParam, const FVector Direction, const FName Bone);
	UFUNCTION(Server, Reliable)
	virtual void Stun_Server(const FStunParameters StunParam, const FVector Direction, const FName Bone);
	UFUNCTION()
	virtual void Stun_Func(const FStunParameters StunParam, const FVector Direction, const FName Bone);

	/*Clear stun status*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|Character|Stun",
		meta = (DisplayName = "ClearStun", Keywords = "Clear Remove Stun TDRL"))
	virtual void ClearStun();
	UFUNCTION(Server, Reliable)
	virtual void ClearStun_Server();
	UFUNCTION()
	virtual void ClearStun_Func();

	/*Is currently stunned?*/
	UFUNCTION(BlueprintPure, Category = "TDRL|Character|Stun",
		meta = (DisplayName = "IsStunned", Keywords = "Is Stunned Stun TDRL"))
	bool IsStunned();
	/*Return if the character is currently stunned and the current Stun parameters*/
	UFUNCTION(BlueprintPure, Category = "TDRL|Character|Stun",
		meta = (DisplayName = "GetStunValue", Keywords = "Get Stun Value TDRL"))
	bool GetStunValue(FStunParameters& Value);

#pragma endregion

#pragma region Death

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, class AController* EventInstigator,
	                         AActor* DamageCauser) override;

	/*Notify the character is dead*/
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category = "TDRL|Character|Death",
		meta = (DisplayName = "CharacterDeath", Keywords = "Character Died Die Death TDRL"))
	virtual void CharacterDeath(FDeathData OutDeathData);
	/*Death native event, called on server*/
	UFUNCTION(BlueprintNativeEvent, Category = "TDRL|Character|Death",
		meta = (DisplayName = "Death", Keywords = "Death TDRL"))
	void Death(const FDeathData OutDeathData);
	/*Death delegate*/
	UPROPERTY(BlueprintAssignable, Category = "TDRL|Delegates|Death")
	FOnDeathDelegate OnDeath;

protected:
	UPROPERTY(ReplicatedUsing = OnRep_DeathInfo)
	FDeathData DeathInfo;
	UFUNCTION()
	virtual void OnRep_DeathInfo();

public:
	/*Return if the character is dead (after calling the CharacterDeath function)*/
	UFUNCTION(BlueprintPure, Category = "TDRL|Character|Death",
		meta = (DisplayName = "GetIsDead", Keywords = "Get Is Dead TDRL"))
	virtual bool GetIsDead() const
	{
		return DeathInfo.bIsDead;
	}

	/*Will return info about death*/
	UFUNCTION(BlueprintPure, Category = "TDRL|Character|Death",
		meta = (DisplayName = "GetDeathInfo", Keywords = "Get Death Info TDRL"))
	virtual FDeathData GetDeathInfo() const
	{
		return DeathInfo;
	}

#pragma endregion
};
