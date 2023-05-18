// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TopDownRogueLite/Public/Projectile/TDRL_ProjectileBase.h"
#include "../../Source/Runtime/Engine/Classes/Engine/HitResult.h"
#include "../../Source/Runtime/Engine/Classes/Engine/TimerHandle.h"
#include "TopDownRogueLite/Public/Types/TDRL_ItemTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTDRL_ProjectileBase() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTimerHandle();
	TOPDOWNROGUELITE_API UClass* Z_Construct_UClass_ATDRL_ProjectileBase();
	TOPDOWNROGUELITE_API UClass* Z_Construct_UClass_ATDRL_ProjectileBase_NoRegister();
	TOPDOWNROGUELITE_API UScriptStruct* Z_Construct_UScriptStruct_FProjectileStaticData();
	UPackage* Z_Construct_UPackage__Script_TopDownRogueLite();
// End Cross Module References
	DEFINE_FUNCTION(ATDRL_ProjectileBase::execDestroyProjectile)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DestroyProjectile();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_ProjectileBase::execRegisterInstancesDirection)
	{
		P_GET_STRUCT(FHitResult,Z_Param_MainDirectionHit);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RegisterInstancesDirection_Implementation(Z_Param_MainDirectionHit);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_ProjectileBase::execGatherInstancesDirection_Client)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GatherInstancesDirection_Client_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_ProjectileBase::execGatherInstancesDirection)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GatherInstancesDirection();
		P_NATIVE_END;
	}
	struct TDRL_ProjectileBase_eventRegisterInstancesDirection_Parms
	{
		FHitResult MainDirectionHit;
	};
	static FName NAME_ATDRL_ProjectileBase_GatherInstancesDirection_Client = FName(TEXT("GatherInstancesDirection_Client"));
	void ATDRL_ProjectileBase::GatherInstancesDirection_Client()
	{
		ProcessEvent(FindFunctionChecked(NAME_ATDRL_ProjectileBase_GatherInstancesDirection_Client),NULL);
	}
	static FName NAME_ATDRL_ProjectileBase_RegisterInstancesDirection = FName(TEXT("RegisterInstancesDirection"));
	void ATDRL_ProjectileBase::RegisterInstancesDirection(const FHitResult MainDirectionHit)
	{
		TDRL_ProjectileBase_eventRegisterInstancesDirection_Parms Parms;
		Parms.MainDirectionHit=MainDirectionHit;
		ProcessEvent(FindFunctionChecked(NAME_ATDRL_ProjectileBase_RegisterInstancesDirection),&Parms);
	}
	void ATDRL_ProjectileBase::StaticRegisterNativesATDRL_ProjectileBase()
	{
		UClass* Class = ATDRL_ProjectileBase::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "DestroyProjectile", &ATDRL_ProjectileBase::execDestroyProjectile },
			{ "GatherInstancesDirection", &ATDRL_ProjectileBase::execGatherInstancesDirection },
			{ "GatherInstancesDirection_Client", &ATDRL_ProjectileBase::execGatherInstancesDirection_Client },
			{ "RegisterInstancesDirection", &ATDRL_ProjectileBase::execRegisterInstancesDirection },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ATDRL_ProjectileBase_DestroyProjectile_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_ProjectileBase_DestroyProjectile_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Projectile/TDRL_ProjectileBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_ProjectileBase_DestroyProjectile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_ProjectileBase, nullptr, "DestroyProjectile", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_ProjectileBase_DestroyProjectile_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_ProjectileBase_DestroyProjectile_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_ProjectileBase_DestroyProjectile()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_ProjectileBase_DestroyProjectile_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_ProjectileBase_GatherInstancesDirection_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_ProjectileBase_GatherInstancesDirection_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Projectile/TDRL_ProjectileBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_ProjectileBase_GatherInstancesDirection_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_ProjectileBase, nullptr, "GatherInstancesDirection", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_ProjectileBase_GatherInstancesDirection_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_ProjectileBase_GatherInstancesDirection_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_ProjectileBase_GatherInstancesDirection()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_ProjectileBase_GatherInstancesDirection_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_ProjectileBase_GatherInstancesDirection_Client_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_ProjectileBase_GatherInstancesDirection_Client_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Projectile/TDRL_ProjectileBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_ProjectileBase_GatherInstancesDirection_Client_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_ProjectileBase, nullptr, "GatherInstancesDirection_Client", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_ProjectileBase_GatherInstancesDirection_Client_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_ProjectileBase_GatherInstancesDirection_Client_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_ProjectileBase_GatherInstancesDirection_Client()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_ProjectileBase_GatherInstancesDirection_Client_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_ProjectileBase_RegisterInstancesDirection_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MainDirectionHit_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_MainDirectionHit;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_ProjectileBase_RegisterInstancesDirection_Statics::NewProp_MainDirectionHit_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATDRL_ProjectileBase_RegisterInstancesDirection_Statics::NewProp_MainDirectionHit = { "MainDirectionHit", nullptr, (EPropertyFlags)0x0010008000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_ProjectileBase_eventRegisterInstancesDirection_Parms, MainDirectionHit), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_ProjectileBase_RegisterInstancesDirection_Statics::NewProp_MainDirectionHit_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_ProjectileBase_RegisterInstancesDirection_Statics::NewProp_MainDirectionHit_MetaData)) }; // 1287526515
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_ProjectileBase_RegisterInstancesDirection_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_ProjectileBase_RegisterInstancesDirection_Statics::NewProp_MainDirectionHit,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_ProjectileBase_RegisterInstancesDirection_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Projectile/TDRL_ProjectileBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_ProjectileBase_RegisterInstancesDirection_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_ProjectileBase, nullptr, "RegisterInstancesDirection", nullptr, nullptr, sizeof(TDRL_ProjectileBase_eventRegisterInstancesDirection_Parms), Z_Construct_UFunction_ATDRL_ProjectileBase_RegisterInstancesDirection_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_ProjectileBase_RegisterInstancesDirection_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_ProjectileBase_RegisterInstancesDirection_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_ProjectileBase_RegisterInstancesDirection_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_ProjectileBase_RegisterInstancesDirection()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_ProjectileBase_RegisterInstancesDirection_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATDRL_ProjectileBase);
	UClass* Z_Construct_UClass_ATDRL_ProjectileBase_NoRegister()
	{
		return ATDRL_ProjectileBase::StaticClass();
	}
	struct Z_Construct_UClass_ATDRL_ProjectileBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileStaticData_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ProjectileStaticData;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bEnableDebug_MetaData[];
#endif
		static void NewProp_bEnableDebug_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableDebug;
		static const UECodeGen_Private::FStructPropertyParams NewProp_InstancesDirection_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InstancesDirection_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_InstancesDirection;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LifeTimerHandle_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_LifeTimerHandle;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATDRL_ProjectileBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_TopDownRogueLite,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ATDRL_ProjectileBase_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ATDRL_ProjectileBase_DestroyProjectile, "DestroyProjectile" }, // 767218608
		{ &Z_Construct_UFunction_ATDRL_ProjectileBase_GatherInstancesDirection, "GatherInstancesDirection" }, // 4172655266
		{ &Z_Construct_UFunction_ATDRL_ProjectileBase_GatherInstancesDirection_Client, "GatherInstancesDirection_Client" }, // 3169209865
		{ &Z_Construct_UFunction_ATDRL_ProjectileBase_RegisterInstancesDirection, "RegisterInstancesDirection" }, // 162817868
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_ProjectileBase_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Projectile/TDRL_ProjectileBase.h" },
		{ "ModuleRelativePath", "Public/Projectile/TDRL_ProjectileBase.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_ProjectileBase_Statics::NewProp_ProjectileStaticData_MetaData[] = {
		{ "Category", "TDRL|Data|Projectile" },
		{ "Comment", "/*Projectile static data*/" },
		{ "ModuleRelativePath", "Public/Projectile/TDRL_ProjectileBase.h" },
		{ "ToolTip", "Projectile static data" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ATDRL_ProjectileBase_Statics::NewProp_ProjectileStaticData = { "ProjectileStaticData", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATDRL_ProjectileBase, ProjectileStaticData), Z_Construct_UScriptStruct_FProjectileStaticData, METADATA_PARAMS(Z_Construct_UClass_ATDRL_ProjectileBase_Statics::NewProp_ProjectileStaticData_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_ProjectileBase_Statics::NewProp_ProjectileStaticData_MetaData)) }; // 2675807444
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_ProjectileBase_Statics::NewProp_bEnableDebug_MetaData[] = {
		{ "Category", "TDRL|Projectile" },
		{ "Comment", "/*Enable visual debug*/" },
		{ "ModuleRelativePath", "Public/Projectile/TDRL_ProjectileBase.h" },
		{ "ToolTip", "Enable visual debug" },
	};
#endif
	void Z_Construct_UClass_ATDRL_ProjectileBase_Statics::NewProp_bEnableDebug_SetBit(void* Obj)
	{
		((ATDRL_ProjectileBase*)Obj)->bEnableDebug = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ATDRL_ProjectileBase_Statics::NewProp_bEnableDebug = { "bEnableDebug", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(uint8), sizeof(ATDRL_ProjectileBase), &Z_Construct_UClass_ATDRL_ProjectileBase_Statics::NewProp_bEnableDebug_SetBit, METADATA_PARAMS(Z_Construct_UClass_ATDRL_ProjectileBase_Statics::NewProp_bEnableDebug_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_ProjectileBase_Statics::NewProp_bEnableDebug_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ATDRL_ProjectileBase_Statics::NewProp_InstancesDirection_Inner = { "InstancesDirection", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_ProjectileBase_Statics::NewProp_InstancesDirection_MetaData[] = {
		{ "Category", "TDRL|Projectile|Runtime" },
		{ "ModuleRelativePath", "Public/Projectile/TDRL_ProjectileBase.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ATDRL_ProjectileBase_Statics::NewProp_InstancesDirection = { "InstancesDirection", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATDRL_ProjectileBase, InstancesDirection), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ATDRL_ProjectileBase_Statics::NewProp_InstancesDirection_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_ProjectileBase_Statics::NewProp_InstancesDirection_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_ProjectileBase_Statics::NewProp_LifeTimerHandle_MetaData[] = {
		{ "ModuleRelativePath", "Public/Projectile/TDRL_ProjectileBase.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ATDRL_ProjectileBase_Statics::NewProp_LifeTimerHandle = { "LifeTimerHandle", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATDRL_ProjectileBase, LifeTimerHandle), Z_Construct_UScriptStruct_FTimerHandle, METADATA_PARAMS(Z_Construct_UClass_ATDRL_ProjectileBase_Statics::NewProp_LifeTimerHandle_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_ProjectileBase_Statics::NewProp_LifeTimerHandle_MetaData)) }; // 3633724737
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATDRL_ProjectileBase_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_ProjectileBase_Statics::NewProp_ProjectileStaticData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_ProjectileBase_Statics::NewProp_bEnableDebug,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_ProjectileBase_Statics::NewProp_InstancesDirection_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_ProjectileBase_Statics::NewProp_InstancesDirection,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_ProjectileBase_Statics::NewProp_LifeTimerHandle,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATDRL_ProjectileBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATDRL_ProjectileBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ATDRL_ProjectileBase_Statics::ClassParams = {
		&ATDRL_ProjectileBase::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ATDRL_ProjectileBase_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_ProjectileBase_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ATDRL_ProjectileBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_ProjectileBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATDRL_ProjectileBase()
	{
		if (!Z_Registration_Info_UClass_ATDRL_ProjectileBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATDRL_ProjectileBase.OuterSingleton, Z_Construct_UClass_ATDRL_ProjectileBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ATDRL_ProjectileBase.OuterSingleton;
	}
	template<> TOPDOWNROGUELITE_API UClass* StaticClass<ATDRL_ProjectileBase>()
	{
		return ATDRL_ProjectileBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATDRL_ProjectileBase);
	ATDRL_ProjectileBase::~ATDRL_ProjectileBase() {}
	struct Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Projectile_TDRL_ProjectileBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Projectile_TDRL_ProjectileBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ATDRL_ProjectileBase, ATDRL_ProjectileBase::StaticClass, TEXT("ATDRL_ProjectileBase"), &Z_Registration_Info_UClass_ATDRL_ProjectileBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATDRL_ProjectileBase), 3979015549U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Projectile_TDRL_ProjectileBase_h_492686165(TEXT("/Script/TopDownRogueLite"),
		Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Projectile_TDRL_ProjectileBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Projectile_TDRL_ProjectileBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
