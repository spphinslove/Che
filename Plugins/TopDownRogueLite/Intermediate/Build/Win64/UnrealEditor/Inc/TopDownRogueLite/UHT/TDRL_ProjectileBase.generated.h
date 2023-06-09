// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Projectile/TDRL_ProjectileBase.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FHitResult;
#ifdef TOPDOWNROGUELITE_TDRL_ProjectileBase_generated_h
#error "TDRL_ProjectileBase.generated.h already included, missing '#pragma once' in TDRL_ProjectileBase.h"
#endif
#define TOPDOWNROGUELITE_TDRL_ProjectileBase_generated_h

#define FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Projectile_TDRL_ProjectileBase_h_13_SPARSE_DATA
#define FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Projectile_TDRL_ProjectileBase_h_13_RPC_WRAPPERS \
	virtual void RegisterInstancesDirection_Implementation(const FHitResult MainDirectionHit); \
	virtual void GatherInstancesDirection_Client_Implementation(); \
 \
	DECLARE_FUNCTION(execDestroyProjectile); \
	DECLARE_FUNCTION(execRegisterInstancesDirection); \
	DECLARE_FUNCTION(execGatherInstancesDirection_Client); \
	DECLARE_FUNCTION(execGatherInstancesDirection);


#define FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Projectile_TDRL_ProjectileBase_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void RegisterInstancesDirection_Implementation(const FHitResult MainDirectionHit); \
	virtual void GatherInstancesDirection_Client_Implementation(); \
 \
	DECLARE_FUNCTION(execDestroyProjectile); \
	DECLARE_FUNCTION(execRegisterInstancesDirection); \
	DECLARE_FUNCTION(execGatherInstancesDirection_Client); \
	DECLARE_FUNCTION(execGatherInstancesDirection);


#define FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Projectile_TDRL_ProjectileBase_h_13_ACCESSORS
#define FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Projectile_TDRL_ProjectileBase_h_13_CALLBACK_WRAPPERS
#define FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Projectile_TDRL_ProjectileBase_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATDRL_ProjectileBase(); \
	friend struct Z_Construct_UClass_ATDRL_ProjectileBase_Statics; \
public: \
	DECLARE_CLASS(ATDRL_ProjectileBase, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TopDownRogueLite"), NO_API) \
	DECLARE_SERIALIZER(ATDRL_ProjectileBase)


#define FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Projectile_TDRL_ProjectileBase_h_13_INCLASS \
private: \
	static void StaticRegisterNativesATDRL_ProjectileBase(); \
	friend struct Z_Construct_UClass_ATDRL_ProjectileBase_Statics; \
public: \
	DECLARE_CLASS(ATDRL_ProjectileBase, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TopDownRogueLite"), NO_API) \
	DECLARE_SERIALIZER(ATDRL_ProjectileBase)


#define FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Projectile_TDRL_ProjectileBase_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATDRL_ProjectileBase(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATDRL_ProjectileBase) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATDRL_ProjectileBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATDRL_ProjectileBase); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATDRL_ProjectileBase(ATDRL_ProjectileBase&&); \
	NO_API ATDRL_ProjectileBase(const ATDRL_ProjectileBase&); \
public: \
	NO_API virtual ~ATDRL_ProjectileBase();


#define FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Projectile_TDRL_ProjectileBase_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATDRL_ProjectileBase(ATDRL_ProjectileBase&&); \
	NO_API ATDRL_ProjectileBase(const ATDRL_ProjectileBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATDRL_ProjectileBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATDRL_ProjectileBase); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATDRL_ProjectileBase) \
	NO_API virtual ~ATDRL_ProjectileBase();


#define FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Projectile_TDRL_ProjectileBase_h_10_PROLOG
#define FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Projectile_TDRL_ProjectileBase_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Projectile_TDRL_ProjectileBase_h_13_SPARSE_DATA \
	FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Projectile_TDRL_ProjectileBase_h_13_RPC_WRAPPERS \
	FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Projectile_TDRL_ProjectileBase_h_13_ACCESSORS \
	FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Projectile_TDRL_ProjectileBase_h_13_CALLBACK_WRAPPERS \
	FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Projectile_TDRL_ProjectileBase_h_13_INCLASS \
	FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Projectile_TDRL_ProjectileBase_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Projectile_TDRL_ProjectileBase_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Projectile_TDRL_ProjectileBase_h_13_SPARSE_DATA \
	FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Projectile_TDRL_ProjectileBase_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Projectile_TDRL_ProjectileBase_h_13_ACCESSORS \
	FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Projectile_TDRL_ProjectileBase_h_13_CALLBACK_WRAPPERS \
	FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Projectile_TDRL_ProjectileBase_h_13_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Projectile_TDRL_ProjectileBase_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TOPDOWNROGUELITE_API UClass* StaticClass<class ATDRL_ProjectileBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Projectile_TDRL_ProjectileBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
