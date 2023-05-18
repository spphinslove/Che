// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Types/TDRL_GameplayTypes.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TOPDOWNROGUELITE_TDRL_GameplayTypes_generated_h
#error "TDRL_GameplayTypes.generated.h already included, missing '#pragma once' in TDRL_GameplayTypes.h"
#endif
#define TOPDOWNROGUELITE_TDRL_GameplayTypes_generated_h

#define FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Types_TDRL_GameplayTypes_h_43_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FDeathData_Statics; \
	static class UScriptStruct* StaticStruct();


template<> TOPDOWNROGUELITE_API UScriptStruct* StaticStruct<struct FDeathData>();

#define FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Types_TDRL_GameplayTypes_h_90_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FHitEffectType_Statics; \
	static class UScriptStruct* StaticStruct(); \
	typedef FTableRowBase Super;


template<> TOPDOWNROGUELITE_API UScriptStruct* StaticStruct<struct FHitEffectType>();

#define FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Types_TDRL_GameplayTypes_h_140_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FDashEffect_Statics; \
	static class UScriptStruct* StaticStruct();


template<> TOPDOWNROGUELITE_API UScriptStruct* StaticStruct<struct FDashEffect>();

#define FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Types_TDRL_GameplayTypes_h_162_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FStunParameters_Statics; \
	static class UScriptStruct* StaticStruct();


template<> TOPDOWNROGUELITE_API UScriptStruct* StaticStruct<struct FStunParameters>();

#define FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Types_TDRL_GameplayTypes_h_227_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FStatusEffect_Statics; \
	static class UScriptStruct* StaticStruct();


template<> TOPDOWNROGUELITE_API UScriptStruct* StaticStruct<struct FStatusEffect>();

#define FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Types_TDRL_GameplayTypes_h_255_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCosmeticParameterList_Statics; \
	static class UScriptStruct* StaticStruct(); \
	typedef FTableRowBase Super;


template<> TOPDOWNROGUELITE_API UScriptStruct* StaticStruct<struct FCosmeticParameterList>();

#define FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Types_TDRL_GameplayTypes_h_289_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMergeSkeletalMeshesParameters_Statics; \
	static class UScriptStruct* StaticStruct();


template<> TOPDOWNROGUELITE_API UScriptStruct* StaticStruct<struct FMergeSkeletalMeshesParameters>();

#define FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Types_TDRL_GameplayTypes_h_339_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCurrencyData_Statics; \
	static class UScriptStruct* StaticStruct();


template<> TOPDOWNROGUELITE_API UScriptStruct* StaticStruct<struct FCurrencyData>();

#define FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Types_TDRL_GameplayTypes_h_360_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCurrenciesList_Statics; \
	static class UScriptStruct* StaticStruct(); \
	typedef FTableRowBase Super;


template<> TOPDOWNROGUELITE_API UScriptStruct* StaticStruct<struct FCurrenciesList>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Types_TDRL_GameplayTypes_h


#define FOREACH_ENUM_EPLAYERSSAPAWNUNLOCKMETHOD(op) \
	op(EPlayersSapawnUnlockMethod::PSUM_None) \
	op(EPlayersSapawnUnlockMethod::PSUM_Overlap) \
	op(EPlayersSapawnUnlockMethod::PSUM_Team) 

enum class EPlayersSapawnUnlockMethod : uint8;
template<> struct TIsUEnumClass<EPlayersSapawnUnlockMethod> { enum { Value = true }; };
template<> TOPDOWNROGUELITE_API UEnum* StaticEnum<EPlayersSapawnUnlockMethod>();

#define FOREACH_ENUM_EPLAYERSSAPAWNMETHOD(op) \
	op(EPlayersSapawnMethod::PSM_None) \
	op(EPlayersSapawnMethod::PSM_Progressive) \
	op(EPlayersSapawnMethod::PSM_Random) 

enum class EPlayersSapawnMethod : uint8;
template<> struct TIsUEnumClass<EPlayersSapawnMethod> { enum { Value = true }; };
template<> TOPDOWNROGUELITE_API UEnum* StaticEnum<EPlayersSapawnMethod>();

#define FOREACH_ENUM_ECONTROLROTATIONTYPE(op) \
	op(EControlRotationType::UnderMouse) \
	op(EControlRotationType::LockedTarget) \
	op(EControlRotationType::TargetLocation) 

enum class EControlRotationType : uint8;
template<> struct TIsUEnumClass<EControlRotationType> { enum { Value = true }; };
template<> TOPDOWNROGUELITE_API UEnum* StaticEnum<EControlRotationType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
