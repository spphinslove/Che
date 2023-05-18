// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Player/TDRL_Character.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class ATDRL_Item;
class ATDRL_NPCController;
class UAbilitySystemComponent;
class UCameraComponent;
class USpringArmComponent;
class UTDRL_CharacterMovementComponent;
class UTDRL_LineOfSightComponent;
struct FDeathData;
struct FStatusEffect;
struct FStunParameters;
#ifdef TOPDOWNROGUELITE_TDRL_Character_generated_h
#error "TDRL_Character.generated.h already included, missing '#pragma once' in TDRL_Character.h"
#endif
#define TOPDOWNROGUELITE_TDRL_Character_generated_h

#define FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Player_TDRL_Character_h_13_DELEGATE \
TOPDOWNROGUELITE_API void FOnDeathDelegate_DelegateWrapper(const FMulticastScriptDelegate& OnDeathDelegate, FDeathData DeathData);


#define FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Player_TDRL_Character_h_18_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics; \
	static class UScriptStruct* StaticStruct();


template<> TOPDOWNROGUELITE_API UScriptStruct* StaticStruct<struct FCameraTraceOcclusionParams>();

#define FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Player_TDRL_Character_h_57_SPARSE_DATA
#define FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Player_TDRL_Character_h_57_RPC_WRAPPERS \
	virtual void Death_Implementation(const FDeathData OutDeathData); \
	virtual void ClearStun_Server_Implementation(); \
	virtual void Stun_Server_Implementation(const FStunParameters StunParam, const FVector Direction, const FName Bone); \
	virtual void Input_RAction_Implementation(bool Pressed); \
	virtual void Input_Crouch_Implementation(bool Pressed); \
	virtual void Input_Jump_Implementation(bool Pressed); \
	virtual void Input_LockTarget_Implementation(bool Pressed); \
	virtual void Input_RotateCamera_Implementation(const float Value); \
	virtual void Input_SecondaryAction_Implementation(bool Pressed); \
	virtual void Input_PrimaryAction_Implementation(bool Pressed); \
	virtual void Input_PitchAim_Implementation(bool Pressed); \
	virtual void Input_AlternativeWalk_Implementation(bool Pressed); \
	virtual void Input_Dash_Implementation(bool Pressed); \
	virtual void Input_ChangeItemSlot_Implementation(const uint8 Slot); \
	virtual void Input_Drop_Implementation(bool Pressed); \
	virtual void Input_Pickup_Implementation(bool Pressed); \
	virtual void Input_Move_Implementation(const FVector Direction); \
	virtual void PerformRAction_Server_Implementation(bool Enable); \
	virtual void PerformSecondaryAction_Server_Implementation(bool Enable); \
	virtual void PerformPrimaryAction_Server_Implementation(bool Enable); \
	virtual void SelectItemSlot_Server_Implementation(const uint8 Slot); \
	virtual void DropItem_Server_Implementation(const uint8 Slot); \
	virtual void PickupItem_Server_Implementation(ATDRL_Item* Item); \
	virtual void EnableTraceForNearbyItems_Func_Implementation(bool Enable); \
	virtual void EnableTraceForNearbyItems_Server_Implementation(bool Enable); \
	virtual void SetInventorySlotsAmount_Implementation(const uint8 Slots); \
	virtual void DestroyDefaultWeapon_Implementation(); \
	virtual void SpawnDefaultWeapon_Implementation(); \
	virtual void Heal_Effects_Implementation(const FStatusEffect Value); \
 \
	DECLARE_FUNCTION(execGetDeathInfo); \
	DECLARE_FUNCTION(execGetIsDead); \
	DECLARE_FUNCTION(execOnRep_DeathInfo); \
	DECLARE_FUNCTION(execDeath); \
	DECLARE_FUNCTION(execCharacterDeath); \
	DECLARE_FUNCTION(execGetStunValue); \
	DECLARE_FUNCTION(execIsStunned); \
	DECLARE_FUNCTION(execClearStun_Func); \
	DECLARE_FUNCTION(execClearStun_Server); \
	DECLARE_FUNCTION(execClearStun); \
	DECLARE_FUNCTION(execStun_Func); \
	DECLARE_FUNCTION(execStun_Server); \
	DECLARE_FUNCTION(execStun); \
	DECLARE_FUNCTION(execOnRep_CurrentStun); \
	DECLARE_FUNCTION(execApplyDefaultKnockback); \
	DECLARE_FUNCTION(execGetNPCController); \
	DECLARE_FUNCTION(execIsDashing); \
	DECLARE_FUNCTION(execDash); \
	DECLARE_FUNCTION(execInput_RAction); \
	DECLARE_FUNCTION(execInput_Crouch); \
	DECLARE_FUNCTION(execInput_Jump); \
	DECLARE_FUNCTION(execInput_LockTarget); \
	DECLARE_FUNCTION(execInput_RotateCamera); \
	DECLARE_FUNCTION(execInput_SecondaryAction); \
	DECLARE_FUNCTION(execInput_PrimaryAction); \
	DECLARE_FUNCTION(execInput_PitchAim); \
	DECLARE_FUNCTION(execInput_AlternativeWalk); \
	DECLARE_FUNCTION(execInput_Dash); \
	DECLARE_FUNCTION(execInput_ChangeItemSlot); \
	DECLARE_FUNCTION(execInput_Drop); \
	DECLARE_FUNCTION(execInput_Pickup); \
	DECLARE_FUNCTION(execInput_Move); \
	DECLARE_FUNCTION(execGetSlotsOccupiedByItemClass); \
	DECLARE_FUNCTION(execGetItemByClass); \
	DECLARE_FUNCTION(execHasItemOfClass); \
	DECLARE_FUNCTION(execGetLowestRarityItemSlot); \
	DECLARE_FUNCTION(execGetHigestRarityItemSlot); \
	DECLARE_FUNCTION(execPerformRAction_Func); \
	DECLARE_FUNCTION(execPerformRAction_Server); \
	DECLARE_FUNCTION(execPerformRAction); \
	DECLARE_FUNCTION(execPerformSecondaryAction_Func); \
	DECLARE_FUNCTION(execPerformSecondaryAction_Server); \
	DECLARE_FUNCTION(execPerformSecondaryAction); \
	DECLARE_FUNCTION(execPerformPrimaryAction_Func); \
	DECLARE_FUNCTION(execPerformPrimaryAction_Server); \
	DECLARE_FUNCTION(execPerformPrimaryAction); \
	DECLARE_FUNCTION(execSelectItemSlot_Func); \
	DECLARE_FUNCTION(execSelectItemSlot_Server); \
	DECLARE_FUNCTION(execSelectItemSlot); \
	DECLARE_FUNCTION(execDestroyAllItems); \
	DECLARE_FUNCTION(execDropAllItems); \
	DECLARE_FUNCTION(execDropItem_Func); \
	DECLARE_FUNCTION(execDropItem_Server); \
	DECLARE_FUNCTION(execDropEquippedItem); \
	DECLARE_FUNCTION(execDropItem); \
	DECLARE_FUNCTION(execPickupItem_Func); \
	DECLARE_FUNCTION(execPickupItem_Server); \
	DECLARE_FUNCTION(execPickupItem); \
	DECLARE_FUNCTION(execGetEquippedItem); \
	DECLARE_FUNCTION(execGetNearestNearbyItem); \
	DECLARE_FUNCTION(execHasNearbyItems); \
	DECLARE_FUNCTION(execTraceForNearbyItems); \
	DECLARE_FUNCTION(execEnableTraceForNearbyItems_Func); \
	DECLARE_FUNCTION(execEnableTraceForNearbyItems_Server); \
	DECLARE_FUNCTION(execEnableTraceForNearbyItems); \
	DECLARE_FUNCTION(execOnRep_InventoryModified); \
	DECLARE_FUNCTION(execOnRep_SlotSelectionModified); \
	DECLARE_FUNCTION(execSetInventorySlotsAmount); \
	DECLARE_FUNCTION(execDestroyDefaultWeapon); \
	DECLARE_FUNCTION(execSpawnDefaultWeapon); \
	DECLARE_FUNCTION(execOnRep_MainWeaponModified); \
	DECLARE_FUNCTION(execTickCameraOrientation); \
	DECLARE_FUNCTION(execTraceForPostProcessOcclusion); \
	DECLARE_FUNCTION(execTraceForCameraOcclusion); \
	DECLARE_FUNCTION(execTickCameraOcclusionTrace); \
	DECLARE_FUNCTION(execGetSightComponent); \
	DECLARE_FUNCTION(execGetAbilityComponent); \
	DECLARE_FUNCTION(execGetCamera); \
	DECLARE_FUNCTION(execGetCameraSpringArm); \
	DECLARE_FUNCTION(execGetTDRLMovementComponent); \
	DECLARE_FUNCTION(execSetAimOffsetValue); \
	DECLARE_FUNCTION(execHeal_Effects); \
	DECLARE_FUNCTION(execHeal); \
	DECLARE_FUNCTION(execGetHealthPercentage); \
	DECLARE_FUNCTION(execSetHealth); \
	DECLARE_FUNCTION(execOnRep_HealthModified); \
	DECLARE_FUNCTION(execGiveInitialAbilities); \
	DECLARE_FUNCTION(execInitializeDefaultAttributeValues); \
	DECLARE_FUNCTION(execRemoveDynamicMaterialPostProcess); \
	DECLARE_FUNCTION(execApplyDynamicMaterialPostProcess);


#define FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Player_TDRL_Character_h_57_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void Death_Implementation(const FDeathData OutDeathData); \
	virtual void ClearStun_Server_Implementation(); \
	virtual void Stun_Server_Implementation(const FStunParameters StunParam, const FVector Direction, const FName Bone); \
	virtual void Input_RAction_Implementation(bool Pressed); \
	virtual void Input_Crouch_Implementation(bool Pressed); \
	virtual void Input_Jump_Implementation(bool Pressed); \
	virtual void Input_LockTarget_Implementation(bool Pressed); \
	virtual void Input_RotateCamera_Implementation(const float Value); \
	virtual void Input_SecondaryAction_Implementation(bool Pressed); \
	virtual void Input_PrimaryAction_Implementation(bool Pressed); \
	virtual void Input_PitchAim_Implementation(bool Pressed); \
	virtual void Input_AlternativeWalk_Implementation(bool Pressed); \
	virtual void Input_Dash_Implementation(bool Pressed); \
	virtual void Input_ChangeItemSlot_Implementation(const uint8 Slot); \
	virtual void Input_Drop_Implementation(bool Pressed); \
	virtual void Input_Pickup_Implementation(bool Pressed); \
	virtual void Input_Move_Implementation(const FVector Direction); \
	virtual void PerformRAction_Server_Implementation(bool Enable); \
	virtual void PerformSecondaryAction_Server_Implementation(bool Enable); \
	virtual void PerformPrimaryAction_Server_Implementation(bool Enable); \
	virtual void SelectItemSlot_Server_Implementation(const uint8 Slot); \
	virtual void DropItem_Server_Implementation(const uint8 Slot); \
	virtual void PickupItem_Server_Implementation(ATDRL_Item* Item); \
	virtual void EnableTraceForNearbyItems_Func_Implementation(bool Enable); \
	virtual void EnableTraceForNearbyItems_Server_Implementation(bool Enable); \
	virtual void SetInventorySlotsAmount_Implementation(const uint8 Slots); \
	virtual void DestroyDefaultWeapon_Implementation(); \
	virtual void SpawnDefaultWeapon_Implementation(); \
	virtual void Heal_Effects_Implementation(const FStatusEffect Value); \
 \
	DECLARE_FUNCTION(execGetDeathInfo); \
	DECLARE_FUNCTION(execGetIsDead); \
	DECLARE_FUNCTION(execOnRep_DeathInfo); \
	DECLARE_FUNCTION(execDeath); \
	DECLARE_FUNCTION(execCharacterDeath); \
	DECLARE_FUNCTION(execGetStunValue); \
	DECLARE_FUNCTION(execIsStunned); \
	DECLARE_FUNCTION(execClearStun_Func); \
	DECLARE_FUNCTION(execClearStun_Server); \
	DECLARE_FUNCTION(execClearStun); \
	DECLARE_FUNCTION(execStun_Func); \
	DECLARE_FUNCTION(execStun_Server); \
	DECLARE_FUNCTION(execStun); \
	DECLARE_FUNCTION(execOnRep_CurrentStun); \
	DECLARE_FUNCTION(execApplyDefaultKnockback); \
	DECLARE_FUNCTION(execGetNPCController); \
	DECLARE_FUNCTION(execIsDashing); \
	DECLARE_FUNCTION(execDash); \
	DECLARE_FUNCTION(execInput_RAction); \
	DECLARE_FUNCTION(execInput_Crouch); \
	DECLARE_FUNCTION(execInput_Jump); \
	DECLARE_FUNCTION(execInput_LockTarget); \
	DECLARE_FUNCTION(execInput_RotateCamera); \
	DECLARE_FUNCTION(execInput_SecondaryAction); \
	DECLARE_FUNCTION(execInput_PrimaryAction); \
	DECLARE_FUNCTION(execInput_PitchAim); \
	DECLARE_FUNCTION(execInput_AlternativeWalk); \
	DECLARE_FUNCTION(execInput_Dash); \
	DECLARE_FUNCTION(execInput_ChangeItemSlot); \
	DECLARE_FUNCTION(execInput_Drop); \
	DECLARE_FUNCTION(execInput_Pickup); \
	DECLARE_FUNCTION(execInput_Move); \
	DECLARE_FUNCTION(execGetSlotsOccupiedByItemClass); \
	DECLARE_FUNCTION(execGetItemByClass); \
	DECLARE_FUNCTION(execHasItemOfClass); \
	DECLARE_FUNCTION(execGetLowestRarityItemSlot); \
	DECLARE_FUNCTION(execGetHigestRarityItemSlot); \
	DECLARE_FUNCTION(execPerformRAction_Func); \
	DECLARE_FUNCTION(execPerformRAction_Server); \
	DECLARE_FUNCTION(execPerformRAction); \
	DECLARE_FUNCTION(execPerformSecondaryAction_Func); \
	DECLARE_FUNCTION(execPerformSecondaryAction_Server); \
	DECLARE_FUNCTION(execPerformSecondaryAction); \
	DECLARE_FUNCTION(execPerformPrimaryAction_Func); \
	DECLARE_FUNCTION(execPerformPrimaryAction_Server); \
	DECLARE_FUNCTION(execPerformPrimaryAction); \
	DECLARE_FUNCTION(execSelectItemSlot_Func); \
	DECLARE_FUNCTION(execSelectItemSlot_Server); \
	DECLARE_FUNCTION(execSelectItemSlot); \
	DECLARE_FUNCTION(execDestroyAllItems); \
	DECLARE_FUNCTION(execDropAllItems); \
	DECLARE_FUNCTION(execDropItem_Func); \
	DECLARE_FUNCTION(execDropItem_Server); \
	DECLARE_FUNCTION(execDropEquippedItem); \
	DECLARE_FUNCTION(execDropItem); \
	DECLARE_FUNCTION(execPickupItem_Func); \
	DECLARE_FUNCTION(execPickupItem_Server); \
	DECLARE_FUNCTION(execPickupItem); \
	DECLARE_FUNCTION(execGetEquippedItem); \
	DECLARE_FUNCTION(execGetNearestNearbyItem); \
	DECLARE_FUNCTION(execHasNearbyItems); \
	DECLARE_FUNCTION(execTraceForNearbyItems); \
	DECLARE_FUNCTION(execEnableTraceForNearbyItems_Func); \
	DECLARE_FUNCTION(execEnableTraceForNearbyItems_Server); \
	DECLARE_FUNCTION(execEnableTraceForNearbyItems); \
	DECLARE_FUNCTION(execOnRep_InventoryModified); \
	DECLARE_FUNCTION(execOnRep_SlotSelectionModified); \
	DECLARE_FUNCTION(execSetInventorySlotsAmount); \
	DECLARE_FUNCTION(execDestroyDefaultWeapon); \
	DECLARE_FUNCTION(execSpawnDefaultWeapon); \
	DECLARE_FUNCTION(execOnRep_MainWeaponModified); \
	DECLARE_FUNCTION(execTickCameraOrientation); \
	DECLARE_FUNCTION(execTraceForPostProcessOcclusion); \
	DECLARE_FUNCTION(execTraceForCameraOcclusion); \
	DECLARE_FUNCTION(execTickCameraOcclusionTrace); \
	DECLARE_FUNCTION(execGetSightComponent); \
	DECLARE_FUNCTION(execGetAbilityComponent); \
	DECLARE_FUNCTION(execGetCamera); \
	DECLARE_FUNCTION(execGetCameraSpringArm); \
	DECLARE_FUNCTION(execGetTDRLMovementComponent); \
	DECLARE_FUNCTION(execSetAimOffsetValue); \
	DECLARE_FUNCTION(execHeal_Effects); \
	DECLARE_FUNCTION(execHeal); \
	DECLARE_FUNCTION(execGetHealthPercentage); \
	DECLARE_FUNCTION(execSetHealth); \
	DECLARE_FUNCTION(execOnRep_HealthModified); \
	DECLARE_FUNCTION(execGiveInitialAbilities); \
	DECLARE_FUNCTION(execInitializeDefaultAttributeValues); \
	DECLARE_FUNCTION(execRemoveDynamicMaterialPostProcess); \
	DECLARE_FUNCTION(execApplyDynamicMaterialPostProcess);


#define FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Player_TDRL_Character_h_57_ACCESSORS
#define FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Player_TDRL_Character_h_57_CALLBACK_WRAPPERS
#define FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Player_TDRL_Character_h_57_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATDRL_Character(); \
	friend struct Z_Construct_UClass_ATDRL_Character_Statics; \
public: \
	DECLARE_CLASS(ATDRL_Character, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TopDownRogueLite"), NO_API) \
	DECLARE_SERIALIZER(ATDRL_Character) \
	virtual UObject* _getUObject() const override { return const_cast<ATDRL_Character*>(this); } \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		Health=NETFIELD_REP_START, \
		AimOffsetValue, \
		MainWeapon, \
		SelectedItemSlot, \
		Inventory, \
		CurrentStun, \
		DeathInfo, \
		NETFIELD_REP_END=DeathInfo	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Player_TDRL_Character_h_57_INCLASS \
private: \
	static void StaticRegisterNativesATDRL_Character(); \
	friend struct Z_Construct_UClass_ATDRL_Character_Statics; \
public: \
	DECLARE_CLASS(ATDRL_Character, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TopDownRogueLite"), NO_API) \
	DECLARE_SERIALIZER(ATDRL_Character) \
	virtual UObject* _getUObject() const override { return const_cast<ATDRL_Character*>(this); } \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		Health=NETFIELD_REP_START, \
		AimOffsetValue, \
		MainWeapon, \
		SelectedItemSlot, \
		Inventory, \
		CurrentStun, \
		DeathInfo, \
		NETFIELD_REP_END=DeathInfo	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Player_TDRL_Character_h_57_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATDRL_Character(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATDRL_Character) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATDRL_Character); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATDRL_Character); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATDRL_Character(ATDRL_Character&&); \
	NO_API ATDRL_Character(const ATDRL_Character&); \
public: \
	NO_API virtual ~ATDRL_Character();


#define FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Player_TDRL_Character_h_57_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATDRL_Character(ATDRL_Character&&); \
	NO_API ATDRL_Character(const ATDRL_Character&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATDRL_Character); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATDRL_Character); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATDRL_Character) \
	NO_API virtual ~ATDRL_Character();


#define FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Player_TDRL_Character_h_54_PROLOG
#define FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Player_TDRL_Character_h_57_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Player_TDRL_Character_h_57_SPARSE_DATA \
	FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Player_TDRL_Character_h_57_RPC_WRAPPERS \
	FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Player_TDRL_Character_h_57_ACCESSORS \
	FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Player_TDRL_Character_h_57_CALLBACK_WRAPPERS \
	FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Player_TDRL_Character_h_57_INCLASS \
	FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Player_TDRL_Character_h_57_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Player_TDRL_Character_h_57_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Player_TDRL_Character_h_57_SPARSE_DATA \
	FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Player_TDRL_Character_h_57_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Player_TDRL_Character_h_57_ACCESSORS \
	FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Player_TDRL_Character_h_57_CALLBACK_WRAPPERS \
	FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Player_TDRL_Character_h_57_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Player_TDRL_Character_h_57_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TOPDOWNROGUELITE_API UClass* StaticClass<class ATDRL_Character>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Player_TDRL_Character_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
