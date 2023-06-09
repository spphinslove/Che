// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TopDownRogueLite/Public/Player/TDRL_Character.h"
#include "../../Source/Runtime/Engine/Classes/Engine/TimerHandle.h"
#include "TopDownRogueLite/Public/Types/TDRL_GameplayTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTDRL_Character() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInstance_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_EObjectTypeQuery();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTimerHandle();
	GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilitySystemComponent_NoRegister();
	GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilitySystemInterface_NoRegister();
	GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayEffect_NoRegister();
	TOPDOWNROGUELITE_API UClass* Z_Construct_UClass_ATDRL_Character();
	TOPDOWNROGUELITE_API UClass* Z_Construct_UClass_ATDRL_Character_NoRegister();
	TOPDOWNROGUELITE_API UClass* Z_Construct_UClass_ATDRL_Item_NoRegister();
	TOPDOWNROGUELITE_API UClass* Z_Construct_UClass_ATDRL_Melee_NoRegister();
	TOPDOWNROGUELITE_API UClass* Z_Construct_UClass_ATDRL_NPCController_NoRegister();
	TOPDOWNROGUELITE_API UClass* Z_Construct_UClass_UTDRL_CameraOcclusionComponent_NoRegister();
	TOPDOWNROGUELITE_API UClass* Z_Construct_UClass_UTDRL_CharacterMovementComponent_NoRegister();
	TOPDOWNROGUELITE_API UClass* Z_Construct_UClass_UTDRL_GASAttributeSet_NoRegister();
	TOPDOWNROGUELITE_API UClass* Z_Construct_UClass_UTDRL_GASGameplayAbility_NoRegister();
	TOPDOWNROGUELITE_API UClass* Z_Construct_UClass_UTDRL_LineOfSightComponent_NoRegister();
	TOPDOWNROGUELITE_API UFunction* Z_Construct_UDelegateFunction_TopDownRogueLite_OnDeathDelegate__DelegateSignature();
	TOPDOWNROGUELITE_API UScriptStruct* Z_Construct_UScriptStruct_FCameraTraceOcclusionParams();
	TOPDOWNROGUELITE_API UScriptStruct* Z_Construct_UScriptStruct_FDeathData();
	TOPDOWNROGUELITE_API UScriptStruct* Z_Construct_UScriptStruct_FStatusEffect();
	TOPDOWNROGUELITE_API UScriptStruct* Z_Construct_UScriptStruct_FStunParameters();
	UPackage* Z_Construct_UPackage__Script_TopDownRogueLite();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_TopDownRogueLite_OnDeathDelegate__DelegateSignature_Statics
	{
		struct _Script_TopDownRogueLite_eventOnDeathDelegate_Parms
		{
			FDeathData DeathData;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_DeathData;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_TopDownRogueLite_OnDeathDelegate__DelegateSignature_Statics::NewProp_DeathData = { "DeathData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(_Script_TopDownRogueLite_eventOnDeathDelegate_Parms, DeathData), Z_Construct_UScriptStruct_FDeathData, METADATA_PARAMS(nullptr, 0) }; // 3112512265
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_TopDownRogueLite_OnDeathDelegate__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_TopDownRogueLite_OnDeathDelegate__DelegateSignature_Statics::NewProp_DeathData,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_TopDownRogueLite_OnDeathDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_TopDownRogueLite_OnDeathDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_TopDownRogueLite, nullptr, "OnDeathDelegate__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_TopDownRogueLite_OnDeathDelegate__DelegateSignature_Statics::_Script_TopDownRogueLite_eventOnDeathDelegate_Parms), Z_Construct_UDelegateFunction_TopDownRogueLite_OnDeathDelegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_TopDownRogueLite_OnDeathDelegate__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_TopDownRogueLite_OnDeathDelegate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_TopDownRogueLite_OnDeathDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_TopDownRogueLite_OnDeathDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_TopDownRogueLite_OnDeathDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FOnDeathDelegate_DelegateWrapper(const FMulticastScriptDelegate& OnDeathDelegate, FDeathData DeathData)
{
	struct _Script_TopDownRogueLite_eventOnDeathDelegate_Parms
	{
		FDeathData DeathData;
	};
	_Script_TopDownRogueLite_eventOnDeathDelegate_Parms Parms;
	Parms.DeathData=DeathData;
	OnDeathDelegate.ProcessMulticastDelegate<UObject>(&Parms);
}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_CameraTraceOcclusionParams;
class UScriptStruct* FCameraTraceOcclusionParams::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_CameraTraceOcclusionParams.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_CameraTraceOcclusionParams.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCameraTraceOcclusionParams, (UObject*)Z_Construct_UPackage__Script_TopDownRogueLite(), TEXT("CameraTraceOcclusionParams"));
	}
	return Z_Registration_Info_UScriptStruct_CameraTraceOcclusionParams.OuterSingleton;
}
template<> TOPDOWNROGUELITE_API UScriptStruct* StaticStruct<FCameraTraceOcclusionParams>()
{
	return FCameraTraceOcclusionParams::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseCameraOcclusionTrace_MetaData[];
#endif
		static void NewProp_bUseCameraOcclusionTrace_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseCameraOcclusionTrace;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseCameraOcclusionPostProcess_MetaData[];
#endif
		static void NewProp_bUseCameraOcclusionPostProcess_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseCameraOcclusionPostProcess;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StartForwardOffset_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_StartForwardOffset;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SizeFactor_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SizeFactor;
		static const UECodeGen_Private::FBytePropertyParams NewProp_TraceChannels_ElementProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TraceChannels_MetaData[];
#endif
		static const UECodeGen_Private::FSetPropertyParams NewProp_TraceChannels;
		static const UECodeGen_Private::FClassPropertyParams NewProp_PostProcessAvoid_ElementProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PostProcessAvoid_MetaData[];
#endif
		static const UECodeGen_Private::FSetPropertyParams NewProp_PostProcessAvoid;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCameraTraceOcclusionParams>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_bUseCameraOcclusionTrace_MetaData[] = {
		{ "Category", "TraceOcclusion|Controls" },
		{ "Comment", "// Controls\n" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Controls" },
	};
#endif
	void Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_bUseCameraOcclusionTrace_SetBit(void* Obj)
	{
		((FCameraTraceOcclusionParams*)Obj)->bUseCameraOcclusionTrace = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_bUseCameraOcclusionTrace = { "bUseCameraOcclusionTrace", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(uint8), sizeof(FCameraTraceOcclusionParams), &Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_bUseCameraOcclusionTrace_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_bUseCameraOcclusionTrace_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_bUseCameraOcclusionTrace_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_bUseCameraOcclusionPostProcess_MetaData[] = {
		{ "Category", "TraceOcclusion|Controls" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_bUseCameraOcclusionPostProcess_SetBit(void* Obj)
	{
		((FCameraTraceOcclusionParams*)Obj)->bUseCameraOcclusionPostProcess = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_bUseCameraOcclusionPostProcess = { "bUseCameraOcclusionPostProcess", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(uint8), sizeof(FCameraTraceOcclusionParams), &Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_bUseCameraOcclusionPostProcess_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_bUseCameraOcclusionPostProcess_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_bUseCameraOcclusionPostProcess_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_StartForwardOffset_MetaData[] = {
		{ "Category", "TraceOcclusion" },
		{ "Comment", "// All\n" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "All" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_StartForwardOffset = { "StartForwardOffset", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FCameraTraceOcclusionParams, StartForwardOffset), METADATA_PARAMS(Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_StartForwardOffset_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_StartForwardOffset_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_SizeFactor_MetaData[] = {
		{ "Category", "TraceOcclusion|Occlusion" },
		{ "Comment", "// Occlusion\n" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Occlusion" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_SizeFactor = { "SizeFactor", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FCameraTraceOcclusionParams, SizeFactor), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_SizeFactor_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_SizeFactor_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_TraceChannels_ElementProp = { "TraceChannels", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UEnum_Engine_EObjectTypeQuery, METADATA_PARAMS(nullptr, 0) }; // 3629342158
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_TraceChannels_MetaData[] = {
		{ "Category", "TraceOcclusion|Occlusion" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_TraceChannels = { "TraceChannels", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FCameraTraceOcclusionParams, TraceChannels), METADATA_PARAMS(Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_TraceChannels_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_TraceChannels_MetaData)) }; // 3629342158
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_PostProcessAvoid_ElementProp = { "PostProcessAvoid", nullptr, (EPropertyFlags)0x0004000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_PostProcessAvoid_MetaData[] = {
		{ "Category", "TraceOcclusion|PostProcess" },
		{ "Comment", "// Post Process\n" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Post Process" },
	};
#endif
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_PostProcessAvoid = { "PostProcessAvoid", nullptr, (EPropertyFlags)0x0014000000010005, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FCameraTraceOcclusionParams, PostProcessAvoid), METADATA_PARAMS(Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_PostProcessAvoid_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_PostProcessAvoid_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_bUseCameraOcclusionTrace,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_bUseCameraOcclusionPostProcess,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_StartForwardOffset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_SizeFactor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_TraceChannels_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_TraceChannels,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_PostProcessAvoid_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewProp_PostProcessAvoid,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_TopDownRogueLite,
		nullptr,
		&NewStructOps,
		"CameraTraceOcclusionParams",
		sizeof(FCameraTraceOcclusionParams),
		alignof(FCameraTraceOcclusionParams),
		Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FCameraTraceOcclusionParams()
	{
		if (!Z_Registration_Info_UScriptStruct_CameraTraceOcclusionParams.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_CameraTraceOcclusionParams.InnerSingleton, Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_CameraTraceOcclusionParams.InnerSingleton;
	}
	DEFINE_FUNCTION(ATDRL_Character::execGetDeathInfo)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FDeathData*)Z_Param__Result=P_THIS->GetDeathInfo();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execGetIsDead)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetIsDead();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execOnRep_DeathInfo)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnRep_DeathInfo();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execDeath)
	{
		P_GET_STRUCT(FDeathData,Z_Param_OutDeathData);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Death_Implementation(Z_Param_OutDeathData);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execCharacterDeath)
	{
		P_GET_STRUCT(FDeathData,Z_Param_OutDeathData);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CharacterDeath(Z_Param_OutDeathData);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execGetStunValue)
	{
		P_GET_STRUCT_REF(FStunParameters,Z_Param_Out_Value);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetStunValue(Z_Param_Out_Value);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execIsStunned)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsStunned();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execClearStun_Func)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ClearStun_Func();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execClearStun_Server)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ClearStun_Server_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execClearStun)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ClearStun();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execStun_Func)
	{
		P_GET_STRUCT(FStunParameters,Z_Param_StunParam);
		P_GET_STRUCT(FVector,Z_Param_Direction);
		P_GET_PROPERTY(FNameProperty,Z_Param_Bone);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Stun_Func(Z_Param_StunParam,Z_Param_Direction,Z_Param_Bone);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execStun_Server)
	{
		P_GET_STRUCT(FStunParameters,Z_Param_StunParam);
		P_GET_STRUCT(FVector,Z_Param_Direction);
		P_GET_PROPERTY(FNameProperty,Z_Param_Bone);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Stun_Server_Implementation(Z_Param_StunParam,Z_Param_Direction,Z_Param_Bone);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execStun)
	{
		P_GET_STRUCT(FStunParameters,Z_Param_StunParam);
		P_GET_STRUCT(FVector,Z_Param_Direction);
		P_GET_PROPERTY(FNameProperty,Z_Param_Bone);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Stun(Z_Param_StunParam,Z_Param_Direction,Z_Param_Bone);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execOnRep_CurrentStun)
	{
		P_GET_STRUCT(FStunParameters,Z_Param_OldValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnRep_CurrentStun(Z_Param_OldValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execApplyDefaultKnockback)
	{
		P_GET_STRUCT(FVector,Z_Param_InDirection);
		P_GET_PROPERTY(FNameProperty,Z_Param_InBoneName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ApplyDefaultKnockback(Z_Param_InDirection,Z_Param_InBoneName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execGetNPCController)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(ATDRL_NPCController**)Z_Param__Result=P_THIS->GetNPCController();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execIsDashing)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsDashing();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execDash)
	{
		P_GET_UBOOL(Z_Param_Enable);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Dash(Z_Param_Enable);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execInput_RAction)
	{
		P_GET_UBOOL(Z_Param_Pressed);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Input_RAction_Implementation(Z_Param_Pressed);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execInput_Crouch)
	{
		P_GET_UBOOL(Z_Param_Pressed);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Input_Crouch_Implementation(Z_Param_Pressed);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execInput_Jump)
	{
		P_GET_UBOOL(Z_Param_Pressed);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Input_Jump_Implementation(Z_Param_Pressed);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execInput_LockTarget)
	{
		P_GET_UBOOL(Z_Param_Pressed);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Input_LockTarget_Implementation(Z_Param_Pressed);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execInput_RotateCamera)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_Value);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Input_RotateCamera_Implementation(Z_Param_Value);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execInput_SecondaryAction)
	{
		P_GET_UBOOL(Z_Param_Pressed);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Input_SecondaryAction_Implementation(Z_Param_Pressed);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execInput_PrimaryAction)
	{
		P_GET_UBOOL(Z_Param_Pressed);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Input_PrimaryAction_Implementation(Z_Param_Pressed);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execInput_PitchAim)
	{
		P_GET_UBOOL(Z_Param_Pressed);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Input_PitchAim_Implementation(Z_Param_Pressed);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execInput_AlternativeWalk)
	{
		P_GET_UBOOL(Z_Param_Pressed);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Input_AlternativeWalk_Implementation(Z_Param_Pressed);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execInput_Dash)
	{
		P_GET_UBOOL(Z_Param_Pressed);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Input_Dash_Implementation(Z_Param_Pressed);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execInput_ChangeItemSlot)
	{
		P_GET_PROPERTY(FByteProperty,Z_Param_Slot);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Input_ChangeItemSlot_Implementation(Z_Param_Slot);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execInput_Drop)
	{
		P_GET_UBOOL(Z_Param_Pressed);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Input_Drop_Implementation(Z_Param_Pressed);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execInput_Pickup)
	{
		P_GET_UBOOL(Z_Param_Pressed);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Input_Pickup_Implementation(Z_Param_Pressed);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execInput_Move)
	{
		P_GET_STRUCT(FVector,Z_Param_Direction);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Input_Move_Implementation(Z_Param_Direction);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execGetSlotsOccupiedByItemClass)
	{
		P_GET_OBJECT(UClass,Z_Param_InClass);
		P_GET_UBOOL(Z_Param_bIncludeSubclasses);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<uint8>*)Z_Param__Result=P_THIS->GetSlotsOccupiedByItemClass(Z_Param_InClass,Z_Param_bIncludeSubclasses);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execGetItemByClass)
	{
		P_GET_OBJECT(UClass,Z_Param_InClass);
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_IndexOut);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(ATDRL_Item**)Z_Param__Result=P_THIS->GetItemByClass(Z_Param_InClass,Z_Param_Out_IndexOut);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execHasItemOfClass)
	{
		P_GET_OBJECT(UClass,Z_Param_InClass);
		P_GET_UBOOL(Z_Param_bIncludeSubclasses);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->HasItemOfClass(Z_Param_InClass,Z_Param_bIncludeSubclasses);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execGetLowestRarityItemSlot)
	{
		P_GET_UBOOL(Z_Param_ShouldBeWeapon);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(uint8*)Z_Param__Result=P_THIS->GetLowestRarityItemSlot(Z_Param_ShouldBeWeapon);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execGetHigestRarityItemSlot)
	{
		P_GET_UBOOL(Z_Param_ShouldBeWeapon);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(uint8*)Z_Param__Result=P_THIS->GetHigestRarityItemSlot(Z_Param_ShouldBeWeapon);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execPerformRAction_Func)
	{
		P_GET_UBOOL(Z_Param_Enable);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PerformRAction_Func(Z_Param_Enable);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execPerformRAction_Server)
	{
		P_GET_UBOOL(Z_Param_Enable);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PerformRAction_Server_Implementation(Z_Param_Enable);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execPerformRAction)
	{
		P_GET_UBOOL(Z_Param_Enable);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PerformRAction(Z_Param_Enable);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execPerformSecondaryAction_Func)
	{
		P_GET_UBOOL(Z_Param_Enable);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PerformSecondaryAction_Func(Z_Param_Enable);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execPerformSecondaryAction_Server)
	{
		P_GET_UBOOL(Z_Param_Enable);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PerformSecondaryAction_Server_Implementation(Z_Param_Enable);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execPerformSecondaryAction)
	{
		P_GET_UBOOL(Z_Param_Enable);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PerformSecondaryAction(Z_Param_Enable);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execPerformPrimaryAction_Func)
	{
		P_GET_UBOOL(Z_Param_Enable);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PerformPrimaryAction_Func(Z_Param_Enable);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execPerformPrimaryAction_Server)
	{
		P_GET_UBOOL(Z_Param_Enable);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PerformPrimaryAction_Server_Implementation(Z_Param_Enable);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execPerformPrimaryAction)
	{
		P_GET_UBOOL(Z_Param_Enable);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PerformPrimaryAction(Z_Param_Enable);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execSelectItemSlot_Func)
	{
		P_GET_PROPERTY(FByteProperty,Z_Param_Slot);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SelectItemSlot_Func(Z_Param_Slot);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execSelectItemSlot_Server)
	{
		P_GET_PROPERTY(FByteProperty,Z_Param_Slot);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SelectItemSlot_Server_Implementation(Z_Param_Slot);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execSelectItemSlot)
	{
		P_GET_PROPERTY(FByteProperty,Z_Param_Slot);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SelectItemSlot(Z_Param_Slot);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execDestroyAllItems)
	{
		P_GET_UBOOL(Z_Param_bIncludeMain);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DestroyAllItems(Z_Param_bIncludeMain);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execDropAllItems)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DropAllItems();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execDropItem_Func)
	{
		P_GET_PROPERTY(FByteProperty,Z_Param_Slot);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DropItem_Func(Z_Param_Slot);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execDropItem_Server)
	{
		P_GET_PROPERTY(FByteProperty,Z_Param_Slot);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DropItem_Server_Implementation(Z_Param_Slot);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execDropEquippedItem)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DropEquippedItem();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execDropItem)
	{
		P_GET_PROPERTY(FByteProperty,Z_Param_Slot);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DropItem(Z_Param_Slot);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execPickupItem_Func)
	{
		P_GET_OBJECT(ATDRL_Item,Z_Param_Item);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PickupItem_Func(Z_Param_Item);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execPickupItem_Server)
	{
		P_GET_OBJECT(ATDRL_Item,Z_Param_Item);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PickupItem_Server_Implementation(Z_Param_Item);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execPickupItem)
	{
		P_GET_OBJECT(ATDRL_Item,Z_Param_Item);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PickupItem(Z_Param_Item);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execGetEquippedItem)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(ATDRL_Item**)Z_Param__Result=P_THIS->GetEquippedItem();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execGetNearestNearbyItem)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(ATDRL_Item**)Z_Param__Result=P_THIS->GetNearestNearbyItem();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execHasNearbyItems)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->HasNearbyItems();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execTraceForNearbyItems)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->TraceForNearbyItems();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execEnableTraceForNearbyItems_Func)
	{
		P_GET_UBOOL(Z_Param_Enable);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EnableTraceForNearbyItems_Func_Implementation(Z_Param_Enable);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execEnableTraceForNearbyItems_Server)
	{
		P_GET_UBOOL(Z_Param_Enable);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EnableTraceForNearbyItems_Server_Implementation(Z_Param_Enable);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execEnableTraceForNearbyItems)
	{
		P_GET_UBOOL(Z_Param_Enable);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EnableTraceForNearbyItems(Z_Param_Enable);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execOnRep_InventoryModified)
	{
		P_GET_TARRAY(ATDRL_Item*,Z_Param_Previous);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnRep_InventoryModified(Z_Param_Previous);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execOnRep_SlotSelectionModified)
	{
		P_GET_PROPERTY(FByteProperty,Z_Param_Previous);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnRep_SlotSelectionModified(Z_Param_Previous);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execSetInventorySlotsAmount)
	{
		P_GET_PROPERTY(FByteProperty,Z_Param_Slots);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetInventorySlotsAmount_Implementation(Z_Param_Slots);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execDestroyDefaultWeapon)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DestroyDefaultWeapon_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execSpawnDefaultWeapon)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SpawnDefaultWeapon_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execOnRep_MainWeaponModified)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnRep_MainWeaponModified();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execTickCameraOrientation)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->TickCameraOrientation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execTraceForPostProcessOcclusion)
	{
		P_GET_STRUCT(FVector,Z_Param_InStart);
		P_GET_STRUCT(FVector,Z_Param_InEnd);
		P_GET_STRUCT(FRotator,Z_Param_InOrientation);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->TraceForPostProcessOcclusion(Z_Param_InStart,Z_Param_InEnd,Z_Param_InOrientation);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execTraceForCameraOcclusion)
	{
		P_GET_STRUCT(FVector,Z_Param_InStart);
		P_GET_STRUCT(FVector,Z_Param_InEnd);
		P_GET_STRUCT(FRotator,Z_Param_InOrientation);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->TraceForCameraOcclusion(Z_Param_InStart,Z_Param_InEnd,Z_Param_InOrientation);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execTickCameraOcclusionTrace)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->TickCameraOcclusionTrace();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execGetSightComponent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UTDRL_LineOfSightComponent**)Z_Param__Result=P_THIS->GetSightComponent();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execGetAbilityComponent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UAbilitySystemComponent**)Z_Param__Result=P_THIS->GetAbilityComponent();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execGetCamera)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UCameraComponent**)Z_Param__Result=P_THIS->GetCamera();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execGetCameraSpringArm)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USpringArmComponent**)Z_Param__Result=P_THIS->GetCameraSpringArm();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execGetTDRLMovementComponent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UTDRL_CharacterMovementComponent**)Z_Param__Result=P_THIS->GetTDRLMovementComponent();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execSetAimOffsetValue)
	{
		P_GET_STRUCT(FVector2D,Z_Param_NewAimOffsetValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetAimOffsetValue(Z_Param_NewAimOffsetValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execHeal_Effects)
	{
		P_GET_STRUCT(FStatusEffect,Z_Param_Value);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Heal_Effects_Implementation(Z_Param_Value);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execHeal)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_Value);
		P_GET_STRUCT(FStatusEffect,Z_Param_Effect);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->Heal(Z_Param_Value,Z_Param_Effect);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execGetHealthPercentage)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetHealthPercentage();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execSetHealth)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_Value);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetHealth(Z_Param_Value);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execOnRep_HealthModified)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_Previous);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnRep_HealthModified(Z_Param_Previous);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execGiveInitialAbilities)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GiveInitialAbilities();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execInitializeDefaultAttributeValues)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->InitializeDefaultAttributeValues();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execRemoveDynamicMaterialPostProcess)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveDynamicMaterialPostProcess();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATDRL_Character::execApplyDynamicMaterialPostProcess)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ApplyDynamicMaterialPostProcess();
		P_NATIVE_END;
	}
	struct TDRL_Character_eventDeath_Parms
	{
		FDeathData OutDeathData;
	};
	struct TDRL_Character_eventDropItem_Server_Parms
	{
		uint8 Slot;
	};
	struct TDRL_Character_eventEnableTraceForNearbyItems_Func_Parms
	{
		bool Enable;
	};
	struct TDRL_Character_eventEnableTraceForNearbyItems_Server_Parms
	{
		bool Enable;
	};
	struct TDRL_Character_eventHeal_Effects_Parms
	{
		FStatusEffect Value;
	};
	struct TDRL_Character_eventInput_AlternativeWalk_Parms
	{
		bool Pressed;
	};
	struct TDRL_Character_eventInput_ChangeItemSlot_Parms
	{
		uint8 Slot;
	};
	struct TDRL_Character_eventInput_Crouch_Parms
	{
		bool Pressed;
	};
	struct TDRL_Character_eventInput_Dash_Parms
	{
		bool Pressed;
	};
	struct TDRL_Character_eventInput_Drop_Parms
	{
		bool Pressed;
	};
	struct TDRL_Character_eventInput_Jump_Parms
	{
		bool Pressed;
	};
	struct TDRL_Character_eventInput_LockTarget_Parms
	{
		bool Pressed;
	};
	struct TDRL_Character_eventInput_Move_Parms
	{
		FVector Direction;
	};
	struct TDRL_Character_eventInput_Pickup_Parms
	{
		bool Pressed;
	};
	struct TDRL_Character_eventInput_PitchAim_Parms
	{
		bool Pressed;
	};
	struct TDRL_Character_eventInput_PrimaryAction_Parms
	{
		bool Pressed;
	};
	struct TDRL_Character_eventInput_RAction_Parms
	{
		bool Pressed;
	};
	struct TDRL_Character_eventInput_RotateCamera_Parms
	{
		float Value;
	};
	struct TDRL_Character_eventInput_SecondaryAction_Parms
	{
		bool Pressed;
	};
	struct TDRL_Character_eventPerformPrimaryAction_Server_Parms
	{
		bool Enable;
	};
	struct TDRL_Character_eventPerformRAction_Server_Parms
	{
		bool Enable;
	};
	struct TDRL_Character_eventPerformSecondaryAction_Server_Parms
	{
		bool Enable;
	};
	struct TDRL_Character_eventPickupItem_Server_Parms
	{
		ATDRL_Item* Item;
	};
	struct TDRL_Character_eventSelectItemSlot_Server_Parms
	{
		uint8 Slot;
	};
	struct TDRL_Character_eventSetInventorySlotsAmount_Parms
	{
		uint8 Slots;
	};
	struct TDRL_Character_eventStun_Server_Parms
	{
		FStunParameters StunParam;
		FVector Direction;
		FName Bone;
	};
	static FName NAME_ATDRL_Character_ClearStun_Server = FName(TEXT("ClearStun_Server"));
	void ATDRL_Character::ClearStun_Server()
	{
		ProcessEvent(FindFunctionChecked(NAME_ATDRL_Character_ClearStun_Server),NULL);
	}
	static FName NAME_ATDRL_Character_Death = FName(TEXT("Death"));
	void ATDRL_Character::Death(const FDeathData OutDeathData)
	{
		TDRL_Character_eventDeath_Parms Parms;
		Parms.OutDeathData=OutDeathData;
		ProcessEvent(FindFunctionChecked(NAME_ATDRL_Character_Death),&Parms);
	}
	static FName NAME_ATDRL_Character_DestroyDefaultWeapon = FName(TEXT("DestroyDefaultWeapon"));
	void ATDRL_Character::DestroyDefaultWeapon()
	{
		ProcessEvent(FindFunctionChecked(NAME_ATDRL_Character_DestroyDefaultWeapon),NULL);
	}
	static FName NAME_ATDRL_Character_DropItem_Server = FName(TEXT("DropItem_Server"));
	void ATDRL_Character::DropItem_Server(const uint8 Slot)
	{
		TDRL_Character_eventDropItem_Server_Parms Parms;
		Parms.Slot=Slot;
		ProcessEvent(FindFunctionChecked(NAME_ATDRL_Character_DropItem_Server),&Parms);
	}
	static FName NAME_ATDRL_Character_EnableTraceForNearbyItems_Func = FName(TEXT("EnableTraceForNearbyItems_Func"));
	void ATDRL_Character::EnableTraceForNearbyItems_Func(bool Enable)
	{
		TDRL_Character_eventEnableTraceForNearbyItems_Func_Parms Parms;
		Parms.Enable=Enable ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_ATDRL_Character_EnableTraceForNearbyItems_Func),&Parms);
	}
	static FName NAME_ATDRL_Character_EnableTraceForNearbyItems_Server = FName(TEXT("EnableTraceForNearbyItems_Server"));
	void ATDRL_Character::EnableTraceForNearbyItems_Server(bool Enable)
	{
		TDRL_Character_eventEnableTraceForNearbyItems_Server_Parms Parms;
		Parms.Enable=Enable ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_ATDRL_Character_EnableTraceForNearbyItems_Server),&Parms);
	}
	static FName NAME_ATDRL_Character_Heal_Effects = FName(TEXT("Heal_Effects"));
	void ATDRL_Character::Heal_Effects(const FStatusEffect Value)
	{
		TDRL_Character_eventHeal_Effects_Parms Parms;
		Parms.Value=Value;
		ProcessEvent(FindFunctionChecked(NAME_ATDRL_Character_Heal_Effects),&Parms);
	}
	static FName NAME_ATDRL_Character_Input_AlternativeWalk = FName(TEXT("Input_AlternativeWalk"));
	void ATDRL_Character::Input_AlternativeWalk(bool Pressed)
	{
		TDRL_Character_eventInput_AlternativeWalk_Parms Parms;
		Parms.Pressed=Pressed ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_ATDRL_Character_Input_AlternativeWalk),&Parms);
	}
	static FName NAME_ATDRL_Character_Input_ChangeItemSlot = FName(TEXT("Input_ChangeItemSlot"));
	void ATDRL_Character::Input_ChangeItemSlot(const uint8 Slot)
	{
		TDRL_Character_eventInput_ChangeItemSlot_Parms Parms;
		Parms.Slot=Slot;
		ProcessEvent(FindFunctionChecked(NAME_ATDRL_Character_Input_ChangeItemSlot),&Parms);
	}
	static FName NAME_ATDRL_Character_Input_Crouch = FName(TEXT("Input_Crouch"));
	void ATDRL_Character::Input_Crouch(bool Pressed)
	{
		TDRL_Character_eventInput_Crouch_Parms Parms;
		Parms.Pressed=Pressed ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_ATDRL_Character_Input_Crouch),&Parms);
	}
	static FName NAME_ATDRL_Character_Input_Dash = FName(TEXT("Input_Dash"));
	void ATDRL_Character::Input_Dash(bool Pressed)
	{
		TDRL_Character_eventInput_Dash_Parms Parms;
		Parms.Pressed=Pressed ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_ATDRL_Character_Input_Dash),&Parms);
	}
	static FName NAME_ATDRL_Character_Input_Drop = FName(TEXT("Input_Drop"));
	void ATDRL_Character::Input_Drop(bool Pressed)
	{
		TDRL_Character_eventInput_Drop_Parms Parms;
		Parms.Pressed=Pressed ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_ATDRL_Character_Input_Drop),&Parms);
	}
	static FName NAME_ATDRL_Character_Input_Jump = FName(TEXT("Input_Jump"));
	void ATDRL_Character::Input_Jump(bool Pressed)
	{
		TDRL_Character_eventInput_Jump_Parms Parms;
		Parms.Pressed=Pressed ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_ATDRL_Character_Input_Jump),&Parms);
	}
	static FName NAME_ATDRL_Character_Input_LockTarget = FName(TEXT("Input_LockTarget"));
	void ATDRL_Character::Input_LockTarget(bool Pressed)
	{
		TDRL_Character_eventInput_LockTarget_Parms Parms;
		Parms.Pressed=Pressed ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_ATDRL_Character_Input_LockTarget),&Parms);
	}
	static FName NAME_ATDRL_Character_Input_Move = FName(TEXT("Input_Move"));
	void ATDRL_Character::Input_Move(const FVector Direction)
	{
		TDRL_Character_eventInput_Move_Parms Parms;
		Parms.Direction=Direction;
		ProcessEvent(FindFunctionChecked(NAME_ATDRL_Character_Input_Move),&Parms);
	}
	static FName NAME_ATDRL_Character_Input_Pickup = FName(TEXT("Input_Pickup"));
	void ATDRL_Character::Input_Pickup(bool Pressed)
	{
		TDRL_Character_eventInput_Pickup_Parms Parms;
		Parms.Pressed=Pressed ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_ATDRL_Character_Input_Pickup),&Parms);
	}
	static FName NAME_ATDRL_Character_Input_PitchAim = FName(TEXT("Input_PitchAim"));
	void ATDRL_Character::Input_PitchAim(bool Pressed)
	{
		TDRL_Character_eventInput_PitchAim_Parms Parms;
		Parms.Pressed=Pressed ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_ATDRL_Character_Input_PitchAim),&Parms);
	}
	static FName NAME_ATDRL_Character_Input_PrimaryAction = FName(TEXT("Input_PrimaryAction"));
	void ATDRL_Character::Input_PrimaryAction(bool Pressed)
	{
		TDRL_Character_eventInput_PrimaryAction_Parms Parms;
		Parms.Pressed=Pressed ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_ATDRL_Character_Input_PrimaryAction),&Parms);
	}
	static FName NAME_ATDRL_Character_Input_RAction = FName(TEXT("Input_RAction"));
	void ATDRL_Character::Input_RAction(bool Pressed)
	{
		TDRL_Character_eventInput_RAction_Parms Parms;
		Parms.Pressed=Pressed ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_ATDRL_Character_Input_RAction),&Parms);
	}
	static FName NAME_ATDRL_Character_Input_RotateCamera = FName(TEXT("Input_RotateCamera"));
	void ATDRL_Character::Input_RotateCamera(const float Value)
	{
		TDRL_Character_eventInput_RotateCamera_Parms Parms;
		Parms.Value=Value;
		ProcessEvent(FindFunctionChecked(NAME_ATDRL_Character_Input_RotateCamera),&Parms);
	}
	static FName NAME_ATDRL_Character_Input_SecondaryAction = FName(TEXT("Input_SecondaryAction"));
	void ATDRL_Character::Input_SecondaryAction(bool Pressed)
	{
		TDRL_Character_eventInput_SecondaryAction_Parms Parms;
		Parms.Pressed=Pressed ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_ATDRL_Character_Input_SecondaryAction),&Parms);
	}
	static FName NAME_ATDRL_Character_PerformPrimaryAction_Server = FName(TEXT("PerformPrimaryAction_Server"));
	void ATDRL_Character::PerformPrimaryAction_Server(bool Enable)
	{
		TDRL_Character_eventPerformPrimaryAction_Server_Parms Parms;
		Parms.Enable=Enable ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_ATDRL_Character_PerformPrimaryAction_Server),&Parms);
	}
	static FName NAME_ATDRL_Character_PerformRAction_Server = FName(TEXT("PerformRAction_Server"));
	void ATDRL_Character::PerformRAction_Server(bool Enable)
	{
		TDRL_Character_eventPerformRAction_Server_Parms Parms;
		Parms.Enable=Enable ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_ATDRL_Character_PerformRAction_Server),&Parms);
	}
	static FName NAME_ATDRL_Character_PerformSecondaryAction_Server = FName(TEXT("PerformSecondaryAction_Server"));
	void ATDRL_Character::PerformSecondaryAction_Server(bool Enable)
	{
		TDRL_Character_eventPerformSecondaryAction_Server_Parms Parms;
		Parms.Enable=Enable ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_ATDRL_Character_PerformSecondaryAction_Server),&Parms);
	}
	static FName NAME_ATDRL_Character_PickupItem_Server = FName(TEXT("PickupItem_Server"));
	void ATDRL_Character::PickupItem_Server(ATDRL_Item* Item)
	{
		TDRL_Character_eventPickupItem_Server_Parms Parms;
		Parms.Item=Item;
		ProcessEvent(FindFunctionChecked(NAME_ATDRL_Character_PickupItem_Server),&Parms);
	}
	static FName NAME_ATDRL_Character_SelectItemSlot_Server = FName(TEXT("SelectItemSlot_Server"));
	void ATDRL_Character::SelectItemSlot_Server(const uint8 Slot)
	{
		TDRL_Character_eventSelectItemSlot_Server_Parms Parms;
		Parms.Slot=Slot;
		ProcessEvent(FindFunctionChecked(NAME_ATDRL_Character_SelectItemSlot_Server),&Parms);
	}
	static FName NAME_ATDRL_Character_SetInventorySlotsAmount = FName(TEXT("SetInventorySlotsAmount"));
	void ATDRL_Character::SetInventorySlotsAmount(const uint8 Slots)
	{
		TDRL_Character_eventSetInventorySlotsAmount_Parms Parms;
		Parms.Slots=Slots;
		ProcessEvent(FindFunctionChecked(NAME_ATDRL_Character_SetInventorySlotsAmount),&Parms);
	}
	static FName NAME_ATDRL_Character_SpawnDefaultWeapon = FName(TEXT("SpawnDefaultWeapon"));
	void ATDRL_Character::SpawnDefaultWeapon()
	{
		ProcessEvent(FindFunctionChecked(NAME_ATDRL_Character_SpawnDefaultWeapon),NULL);
	}
	static FName NAME_ATDRL_Character_Stun_Server = FName(TEXT("Stun_Server"));
	void ATDRL_Character::Stun_Server(const FStunParameters StunParam, const FVector Direction, const FName Bone)
	{
		TDRL_Character_eventStun_Server_Parms Parms;
		Parms.StunParam=StunParam;
		Parms.Direction=Direction;
		Parms.Bone=Bone;
		ProcessEvent(FindFunctionChecked(NAME_ATDRL_Character_Stun_Server),&Parms);
	}
	void ATDRL_Character::StaticRegisterNativesATDRL_Character()
	{
		UClass* Class = ATDRL_Character::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ApplyDefaultKnockback", &ATDRL_Character::execApplyDefaultKnockback },
			{ "ApplyDynamicMaterialPostProcess", &ATDRL_Character::execApplyDynamicMaterialPostProcess },
			{ "CharacterDeath", &ATDRL_Character::execCharacterDeath },
			{ "ClearStun", &ATDRL_Character::execClearStun },
			{ "ClearStun_Func", &ATDRL_Character::execClearStun_Func },
			{ "ClearStun_Server", &ATDRL_Character::execClearStun_Server },
			{ "Dash", &ATDRL_Character::execDash },
			{ "Death", &ATDRL_Character::execDeath },
			{ "DestroyAllItems", &ATDRL_Character::execDestroyAllItems },
			{ "DestroyDefaultWeapon", &ATDRL_Character::execDestroyDefaultWeapon },
			{ "DropAllItems", &ATDRL_Character::execDropAllItems },
			{ "DropEquippedItem", &ATDRL_Character::execDropEquippedItem },
			{ "DropItem", &ATDRL_Character::execDropItem },
			{ "DropItem_Func", &ATDRL_Character::execDropItem_Func },
			{ "DropItem_Server", &ATDRL_Character::execDropItem_Server },
			{ "EnableTraceForNearbyItems", &ATDRL_Character::execEnableTraceForNearbyItems },
			{ "EnableTraceForNearbyItems_Func", &ATDRL_Character::execEnableTraceForNearbyItems_Func },
			{ "EnableTraceForNearbyItems_Server", &ATDRL_Character::execEnableTraceForNearbyItems_Server },
			{ "GetAbilityComponent", &ATDRL_Character::execGetAbilityComponent },
			{ "GetCamera", &ATDRL_Character::execGetCamera },
			{ "GetCameraSpringArm", &ATDRL_Character::execGetCameraSpringArm },
			{ "GetDeathInfo", &ATDRL_Character::execGetDeathInfo },
			{ "GetEquippedItem", &ATDRL_Character::execGetEquippedItem },
			{ "GetHealthPercentage", &ATDRL_Character::execGetHealthPercentage },
			{ "GetHigestRarityItemSlot", &ATDRL_Character::execGetHigestRarityItemSlot },
			{ "GetIsDead", &ATDRL_Character::execGetIsDead },
			{ "GetItemByClass", &ATDRL_Character::execGetItemByClass },
			{ "GetLowestRarityItemSlot", &ATDRL_Character::execGetLowestRarityItemSlot },
			{ "GetNearestNearbyItem", &ATDRL_Character::execGetNearestNearbyItem },
			{ "GetNPCController", &ATDRL_Character::execGetNPCController },
			{ "GetSightComponent", &ATDRL_Character::execGetSightComponent },
			{ "GetSlotsOccupiedByItemClass", &ATDRL_Character::execGetSlotsOccupiedByItemClass },
			{ "GetStunValue", &ATDRL_Character::execGetStunValue },
			{ "GetTDRLMovementComponent", &ATDRL_Character::execGetTDRLMovementComponent },
			{ "GiveInitialAbilities", &ATDRL_Character::execGiveInitialAbilities },
			{ "HasItemOfClass", &ATDRL_Character::execHasItemOfClass },
			{ "HasNearbyItems", &ATDRL_Character::execHasNearbyItems },
			{ "Heal", &ATDRL_Character::execHeal },
			{ "Heal_Effects", &ATDRL_Character::execHeal_Effects },
			{ "InitializeDefaultAttributeValues", &ATDRL_Character::execInitializeDefaultAttributeValues },
			{ "Input_AlternativeWalk", &ATDRL_Character::execInput_AlternativeWalk },
			{ "Input_ChangeItemSlot", &ATDRL_Character::execInput_ChangeItemSlot },
			{ "Input_Crouch", &ATDRL_Character::execInput_Crouch },
			{ "Input_Dash", &ATDRL_Character::execInput_Dash },
			{ "Input_Drop", &ATDRL_Character::execInput_Drop },
			{ "Input_Jump", &ATDRL_Character::execInput_Jump },
			{ "Input_LockTarget", &ATDRL_Character::execInput_LockTarget },
			{ "Input_Move", &ATDRL_Character::execInput_Move },
			{ "Input_Pickup", &ATDRL_Character::execInput_Pickup },
			{ "Input_PitchAim", &ATDRL_Character::execInput_PitchAim },
			{ "Input_PrimaryAction", &ATDRL_Character::execInput_PrimaryAction },
			{ "Input_RAction", &ATDRL_Character::execInput_RAction },
			{ "Input_RotateCamera", &ATDRL_Character::execInput_RotateCamera },
			{ "Input_SecondaryAction", &ATDRL_Character::execInput_SecondaryAction },
			{ "IsDashing", &ATDRL_Character::execIsDashing },
			{ "IsStunned", &ATDRL_Character::execIsStunned },
			{ "OnRep_CurrentStun", &ATDRL_Character::execOnRep_CurrentStun },
			{ "OnRep_DeathInfo", &ATDRL_Character::execOnRep_DeathInfo },
			{ "OnRep_HealthModified", &ATDRL_Character::execOnRep_HealthModified },
			{ "OnRep_InventoryModified", &ATDRL_Character::execOnRep_InventoryModified },
			{ "OnRep_MainWeaponModified", &ATDRL_Character::execOnRep_MainWeaponModified },
			{ "OnRep_SlotSelectionModified", &ATDRL_Character::execOnRep_SlotSelectionModified },
			{ "PerformPrimaryAction", &ATDRL_Character::execPerformPrimaryAction },
			{ "PerformPrimaryAction_Func", &ATDRL_Character::execPerformPrimaryAction_Func },
			{ "PerformPrimaryAction_Server", &ATDRL_Character::execPerformPrimaryAction_Server },
			{ "PerformRAction", &ATDRL_Character::execPerformRAction },
			{ "PerformRAction_Func", &ATDRL_Character::execPerformRAction_Func },
			{ "PerformRAction_Server", &ATDRL_Character::execPerformRAction_Server },
			{ "PerformSecondaryAction", &ATDRL_Character::execPerformSecondaryAction },
			{ "PerformSecondaryAction_Func", &ATDRL_Character::execPerformSecondaryAction_Func },
			{ "PerformSecondaryAction_Server", &ATDRL_Character::execPerformSecondaryAction_Server },
			{ "PickupItem", &ATDRL_Character::execPickupItem },
			{ "PickupItem_Func", &ATDRL_Character::execPickupItem_Func },
			{ "PickupItem_Server", &ATDRL_Character::execPickupItem_Server },
			{ "RemoveDynamicMaterialPostProcess", &ATDRL_Character::execRemoveDynamicMaterialPostProcess },
			{ "SelectItemSlot", &ATDRL_Character::execSelectItemSlot },
			{ "SelectItemSlot_Func", &ATDRL_Character::execSelectItemSlot_Func },
			{ "SelectItemSlot_Server", &ATDRL_Character::execSelectItemSlot_Server },
			{ "SetAimOffsetValue", &ATDRL_Character::execSetAimOffsetValue },
			{ "SetHealth", &ATDRL_Character::execSetHealth },
			{ "SetInventorySlotsAmount", &ATDRL_Character::execSetInventorySlotsAmount },
			{ "SpawnDefaultWeapon", &ATDRL_Character::execSpawnDefaultWeapon },
			{ "Stun", &ATDRL_Character::execStun },
			{ "Stun_Func", &ATDRL_Character::execStun_Func },
			{ "Stun_Server", &ATDRL_Character::execStun_Server },
			{ "TickCameraOcclusionTrace", &ATDRL_Character::execTickCameraOcclusionTrace },
			{ "TickCameraOrientation", &ATDRL_Character::execTickCameraOrientation },
			{ "TraceForCameraOcclusion", &ATDRL_Character::execTraceForCameraOcclusion },
			{ "TraceForNearbyItems", &ATDRL_Character::execTraceForNearbyItems },
			{ "TraceForPostProcessOcclusion", &ATDRL_Character::execTraceForPostProcessOcclusion },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ATDRL_Character_ApplyDefaultKnockback_Statics
	{
		struct TDRL_Character_eventApplyDefaultKnockback_Parms
		{
			FVector InDirection;
			FName InBoneName;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InDirection_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_InDirection;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InBoneName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_InBoneName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_ApplyDefaultKnockback_Statics::NewProp_InDirection_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATDRL_Character_ApplyDefaultKnockback_Statics::NewProp_InDirection = { "InDirection", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventApplyDefaultKnockback_Parms, InDirection), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_ApplyDefaultKnockback_Statics::NewProp_InDirection_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_ApplyDefaultKnockback_Statics::NewProp_InDirection_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_ApplyDefaultKnockback_Statics::NewProp_InBoneName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ATDRL_Character_ApplyDefaultKnockback_Statics::NewProp_InBoneName = { "InBoneName", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventApplyDefaultKnockback_Parms, InBoneName), METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_ApplyDefaultKnockback_Statics::NewProp_InBoneName_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_ApplyDefaultKnockback_Statics::NewProp_InBoneName_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_ApplyDefaultKnockback_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_ApplyDefaultKnockback_Statics::NewProp_InDirection,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_ApplyDefaultKnockback_Statics::NewProp_InBoneName,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_ApplyDefaultKnockback_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Stun" },
		{ "Comment", "/*Apply the default Knockback (used when the character gets damage)*/" },
		{ "DisplayName", "ApplyDefaultKnockback" },
		{ "Keywords", "Apply Default Knockback TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Apply the default Knockback (used when the character gets damage)" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_ApplyDefaultKnockback_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "ApplyDefaultKnockback", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_ApplyDefaultKnockback_Statics::TDRL_Character_eventApplyDefaultKnockback_Parms), Z_Construct_UFunction_ATDRL_Character_ApplyDefaultKnockback_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_ApplyDefaultKnockback_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_ApplyDefaultKnockback_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_ApplyDefaultKnockback_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_ApplyDefaultKnockback()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_ApplyDefaultKnockback_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_ApplyDynamicMaterialPostProcess_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_ApplyDynamicMaterialPostProcess_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_ApplyDynamicMaterialPostProcess_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "ApplyDynamicMaterialPostProcess", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_ApplyDynamicMaterialPostProcess_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_ApplyDynamicMaterialPostProcess_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_ApplyDynamicMaterialPostProcess()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_ApplyDynamicMaterialPostProcess_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_CharacterDeath_Statics
	{
		struct TDRL_Character_eventCharacterDeath_Parms
		{
			FDeathData OutDeathData;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_OutDeathData;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATDRL_Character_CharacterDeath_Statics::NewProp_OutDeathData = { "OutDeathData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventCharacterDeath_Parms, OutDeathData), Z_Construct_UScriptStruct_FDeathData, METADATA_PARAMS(nullptr, 0) }; // 3112512265
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_CharacterDeath_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_CharacterDeath_Statics::NewProp_OutDeathData,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_CharacterDeath_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Death" },
		{ "Comment", "/*Notify the character is dead*/" },
		{ "DisplayName", "CharacterDeath" },
		{ "Keywords", "Character Died Die Death TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Notify the character is dead" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_CharacterDeath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "CharacterDeath", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_CharacterDeath_Statics::TDRL_Character_eventCharacterDeath_Parms), Z_Construct_UFunction_ATDRL_Character_CharacterDeath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_CharacterDeath_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020404, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_CharacterDeath_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_CharacterDeath_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_CharacterDeath()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_CharacterDeath_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_ClearStun_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_ClearStun_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Stun" },
		{ "Comment", "/*Clear stun status*/" },
		{ "DisplayName", "ClearStun" },
		{ "Keywords", "Clear Remove Stun TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Clear stun status" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_ClearStun_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "ClearStun", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_ClearStun_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_ClearStun_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_ClearStun()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_ClearStun_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_ClearStun_Func_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_ClearStun_Func_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_ClearStun_Func_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "ClearStun_Func", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_ClearStun_Func_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_ClearStun_Func_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_ClearStun_Func()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_ClearStun_Func_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_ClearStun_Server_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_ClearStun_Server_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_ClearStun_Server_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "ClearStun_Server", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_ClearStun_Server_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_ClearStun_Server_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_ClearStun_Server()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_ClearStun_Server_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_Dash_Statics
	{
		struct TDRL_Character_eventDash_Parms
		{
			bool Enable;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Enable_MetaData[];
#endif
		static void NewProp_Enable_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Enable;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Dash_Statics::NewProp_Enable_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_ATDRL_Character_Dash_Statics::NewProp_Enable_SetBit(void* Obj)
	{
		((TDRL_Character_eventDash_Parms*)Obj)->Enable = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATDRL_Character_Dash_Statics::NewProp_Enable = { "Enable", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(TDRL_Character_eventDash_Parms), &Z_Construct_UFunction_ATDRL_Character_Dash_Statics::NewProp_Enable_SetBit, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Dash_Statics::NewProp_Enable_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Dash_Statics::NewProp_Enable_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_Dash_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_Dash_Statics::NewProp_Enable,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Dash_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Movements" },
		{ "Comment", "/*Perform Dash action if possible*/" },
		{ "DisplayName", "Dash" },
		{ "Keywords", "Dash Perform TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Perform Dash action if possible" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_Dash_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "Dash", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_Dash_Statics::TDRL_Character_eventDash_Parms), Z_Construct_UFunction_ATDRL_Character_Dash_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Dash_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Dash_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Dash_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_Dash()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_Dash_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_Death_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OutDeathData_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_OutDeathData;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Death_Statics::NewProp_OutDeathData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATDRL_Character_Death_Statics::NewProp_OutDeathData = { "OutDeathData", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventDeath_Parms, OutDeathData), Z_Construct_UScriptStruct_FDeathData, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Death_Statics::NewProp_OutDeathData_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Death_Statics::NewProp_OutDeathData_MetaData)) }; // 3112512265
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_Death_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_Death_Statics::NewProp_OutDeathData,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Death_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Death" },
		{ "Comment", "/*Death native event, called on server*/" },
		{ "DisplayName", "Death" },
		{ "Keywords", "Death TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Death native event, called on server" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_Death_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "Death", nullptr, nullptr, sizeof(TDRL_Character_eventDeath_Parms), Z_Construct_UFunction_ATDRL_Character_Death_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Death_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Death_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Death_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_Death()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_Death_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_DestroyAllItems_Statics
	{
		struct TDRL_Character_eventDestroyAllItems_Parms
		{
			bool bIncludeMain;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIncludeMain_MetaData[];
#endif
		static void NewProp_bIncludeMain_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIncludeMain;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_DestroyAllItems_Statics::NewProp_bIncludeMain_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_ATDRL_Character_DestroyAllItems_Statics::NewProp_bIncludeMain_SetBit(void* Obj)
	{
		((TDRL_Character_eventDestroyAllItems_Parms*)Obj)->bIncludeMain = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATDRL_Character_DestroyAllItems_Statics::NewProp_bIncludeMain = { "bIncludeMain", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(TDRL_Character_eventDestroyAllItems_Parms), &Z_Construct_UFunction_ATDRL_Character_DestroyAllItems_Statics::NewProp_bIncludeMain_SetBit, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_DestroyAllItems_Statics::NewProp_bIncludeMain_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_DestroyAllItems_Statics::NewProp_bIncludeMain_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_DestroyAllItems_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_DestroyAllItems_Statics::NewProp_bIncludeMain,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_DestroyAllItems_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Inventory" },
		{ "Comment", "/*Destroy all the items contained in the Inventory (can decide if affects the Main Weapon too)*/" },
		{ "DisplayName", "DestroyAllItems" },
		{ "Keywords", "Destroy All Items TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Destroy all the items contained in the Inventory (can decide if affects the Main Weapon too)" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_DestroyAllItems_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "DestroyAllItems", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_DestroyAllItems_Statics::TDRL_Character_eventDestroyAllItems_Parms), Z_Construct_UFunction_ATDRL_Character_DestroyAllItems_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_DestroyAllItems_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_DestroyAllItems_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_DestroyAllItems_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_DestroyAllItems()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_DestroyAllItems_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_DestroyDefaultWeapon_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_DestroyDefaultWeapon_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_DestroyDefaultWeapon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "DestroyDefaultWeapon", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_DestroyDefaultWeapon_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_DestroyDefaultWeapon_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_DestroyDefaultWeapon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_DestroyDefaultWeapon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_DropAllItems_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_DropAllItems_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Inventory" },
		{ "Comment", "/*Drop all the items contained in the Inventory (will not drop the main weapon)*/" },
		{ "DisplayName", "DropAllItems" },
		{ "Keywords", "Drop All Items TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Drop all the items contained in the Inventory (will not drop the main weapon)" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_DropAllItems_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "DropAllItems", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_DropAllItems_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_DropAllItems_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_DropAllItems()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_DropAllItems_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_DropEquippedItem_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_DropEquippedItem_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Item" },
		{ "DisplayName", "DropEquippedItem" },
		{ "Keywords", "Drop Equipped Item TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_DropEquippedItem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "DropEquippedItem", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_DropEquippedItem_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_DropEquippedItem_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_DropEquippedItem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_DropEquippedItem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_DropItem_Statics
	{
		struct TDRL_Character_eventDropItem_Parms
		{
			uint8 Slot;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Slot_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_Slot;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_DropItem_Statics::NewProp_Slot_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ATDRL_Character_DropItem_Statics::NewProp_Slot = { "Slot", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventDropItem_Parms, Slot), nullptr, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_DropItem_Statics::NewProp_Slot_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_DropItem_Statics::NewProp_Slot_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_DropItem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_DropItem_Statics::NewProp_Slot,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_DropItem_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Item" },
		{ "Comment", "/*Drop equipped item*/" },
		{ "DisplayName", "DropItem" },
		{ "Keywords", "Drop Item TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Drop equipped item" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_DropItem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "DropItem", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_DropItem_Statics::TDRL_Character_eventDropItem_Parms), Z_Construct_UFunction_ATDRL_Character_DropItem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_DropItem_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_DropItem_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_DropItem_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_DropItem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_DropItem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_DropItem_Func_Statics
	{
		struct TDRL_Character_eventDropItem_Func_Parms
		{
			uint8 Slot;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Slot_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_Slot;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_DropItem_Func_Statics::NewProp_Slot_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ATDRL_Character_DropItem_Func_Statics::NewProp_Slot = { "Slot", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventDropItem_Func_Parms, Slot), nullptr, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_DropItem_Func_Statics::NewProp_Slot_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_DropItem_Func_Statics::NewProp_Slot_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_DropItem_Func_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_DropItem_Func_Statics::NewProp_Slot,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_DropItem_Func_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_DropItem_Func_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "DropItem_Func", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_DropItem_Func_Statics::TDRL_Character_eventDropItem_Func_Parms), Z_Construct_UFunction_ATDRL_Character_DropItem_Func_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_DropItem_Func_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_DropItem_Func_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_DropItem_Func_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_DropItem_Func()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_DropItem_Func_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_DropItem_Server_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Slot_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_Slot;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_DropItem_Server_Statics::NewProp_Slot_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ATDRL_Character_DropItem_Server_Statics::NewProp_Slot = { "Slot", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventDropItem_Server_Parms, Slot), nullptr, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_DropItem_Server_Statics::NewProp_Slot_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_DropItem_Server_Statics::NewProp_Slot_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_DropItem_Server_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_DropItem_Server_Statics::NewProp_Slot,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_DropItem_Server_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_DropItem_Server_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "DropItem_Server", nullptr, nullptr, sizeof(TDRL_Character_eventDropItem_Server_Parms), Z_Construct_UFunction_ATDRL_Character_DropItem_Server_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_DropItem_Server_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_DropItem_Server_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_DropItem_Server_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_DropItem_Server()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_DropItem_Server_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Statics
	{
		struct TDRL_Character_eventEnableTraceForNearbyItems_Parms
		{
			bool Enable;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Enable_MetaData[];
#endif
		static void NewProp_Enable_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Enable;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Statics::NewProp_Enable_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Statics::NewProp_Enable_SetBit(void* Obj)
	{
		((TDRL_Character_eventEnableTraceForNearbyItems_Parms*)Obj)->Enable = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Statics::NewProp_Enable = { "Enable", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(TDRL_Character_eventEnableTraceForNearbyItems_Parms), &Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Statics::NewProp_Enable_SetBit, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Statics::NewProp_Enable_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Statics::NewProp_Enable_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Statics::NewProp_Enable,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Inventory" },
		{ "Comment", "/*Enable / Disable trace for nearby items*/" },
		{ "DisplayName", "EnableTraceForNearbyItems" },
		{ "Keywords", "Enable Trace For Nearby Items TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Enable / Disable trace for nearby items" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "EnableTraceForNearbyItems", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Statics::TDRL_Character_eventEnableTraceForNearbyItems_Parms), Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Func_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Enable_MetaData[];
#endif
		static void NewProp_Enable_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Enable;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Func_Statics::NewProp_Enable_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Func_Statics::NewProp_Enable_SetBit(void* Obj)
	{
		((TDRL_Character_eventEnableTraceForNearbyItems_Func_Parms*)Obj)->Enable = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Func_Statics::NewProp_Enable = { "Enable", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(TDRL_Character_eventEnableTraceForNearbyItems_Func_Parms), &Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Func_Statics::NewProp_Enable_SetBit, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Func_Statics::NewProp_Enable_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Func_Statics::NewProp_Enable_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Func_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Func_Statics::NewProp_Enable,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Func_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Func_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "EnableTraceForNearbyItems_Func", nullptr, nullptr, sizeof(TDRL_Character_eventEnableTraceForNearbyItems_Func_Parms), Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Func_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Func_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Func_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Func_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Func()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Func_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Server_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Enable_MetaData[];
#endif
		static void NewProp_Enable_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Enable;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Server_Statics::NewProp_Enable_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Server_Statics::NewProp_Enable_SetBit(void* Obj)
	{
		((TDRL_Character_eventEnableTraceForNearbyItems_Server_Parms*)Obj)->Enable = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Server_Statics::NewProp_Enable = { "Enable", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(TDRL_Character_eventEnableTraceForNearbyItems_Server_Parms), &Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Server_Statics::NewProp_Enable_SetBit, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Server_Statics::NewProp_Enable_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Server_Statics::NewProp_Enable_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Server_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Server_Statics::NewProp_Enable,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Server_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Server_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "EnableTraceForNearbyItems_Server", nullptr, nullptr, sizeof(TDRL_Character_eventEnableTraceForNearbyItems_Server_Parms), Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Server_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Server_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Server_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Server_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Server()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Server_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_GetAbilityComponent_Statics
	{
		struct TDRL_Character_eventGetAbilityComponent_Parms
		{
			UAbilitySystemComponent* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_GetAbilityComponent_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATDRL_Character_GetAbilityComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventGetAbilityComponent_Parms, ReturnValue), Z_Construct_UClass_UAbilitySystemComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_GetAbilityComponent_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetAbilityComponent_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_GetAbilityComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_GetAbilityComponent_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_GetAbilityComponent_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Components" },
		{ "Comment", "/*Return the Character's AbilityComponent*/" },
		{ "DisplayName", "GetAbilityComponent" },
		{ "Keywords", "Get Ability Component TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Return the Character's AbilityComponent" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_GetAbilityComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "GetAbilityComponent", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_GetAbilityComponent_Statics::TDRL_Character_eventGetAbilityComponent_Parms), Z_Construct_UFunction_ATDRL_Character_GetAbilityComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetAbilityComponent_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_GetAbilityComponent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetAbilityComponent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_GetAbilityComponent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_GetAbilityComponent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_GetCamera_Statics
	{
		struct TDRL_Character_eventGetCamera_Parms
		{
			UCameraComponent* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_GetCamera_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATDRL_Character_GetCamera_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventGetCamera_Parms, ReturnValue), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_GetCamera_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetCamera_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_GetCamera_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_GetCamera_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_GetCamera_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Components" },
		{ "Comment", "/*Return the Character's camera*/" },
		{ "DisplayName", "GetCamera" },
		{ "Keywords", "Get Camera TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Return the Character's camera" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_GetCamera_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "GetCamera", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_GetCamera_Statics::TDRL_Character_eventGetCamera_Parms), Z_Construct_UFunction_ATDRL_Character_GetCamera_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetCamera_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_GetCamera_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetCamera_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_GetCamera()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_GetCamera_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_GetCameraSpringArm_Statics
	{
		struct TDRL_Character_eventGetCameraSpringArm_Parms
		{
			USpringArmComponent* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_GetCameraSpringArm_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATDRL_Character_GetCameraSpringArm_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventGetCameraSpringArm_Parms, ReturnValue), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_GetCameraSpringArm_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetCameraSpringArm_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_GetCameraSpringArm_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_GetCameraSpringArm_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_GetCameraSpringArm_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Components" },
		{ "Comment", "/*Return the Character's Spring Arm*/" },
		{ "DisplayName", "GetCameraSpringArm" },
		{ "Keywords", "Get Camera Spring Arm TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Return the Character's Spring Arm" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_GetCameraSpringArm_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "GetCameraSpringArm", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_GetCameraSpringArm_Statics::TDRL_Character_eventGetCameraSpringArm_Parms), Z_Construct_UFunction_ATDRL_Character_GetCameraSpringArm_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetCameraSpringArm_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_GetCameraSpringArm_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetCameraSpringArm_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_GetCameraSpringArm()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_GetCameraSpringArm_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_GetDeathInfo_Statics
	{
		struct TDRL_Character_eventGetDeathInfo_Parms
		{
			FDeathData ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATDRL_Character_GetDeathInfo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventGetDeathInfo_Parms, ReturnValue), Z_Construct_UScriptStruct_FDeathData, METADATA_PARAMS(nullptr, 0) }; // 3112512265
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_GetDeathInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_GetDeathInfo_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_GetDeathInfo_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Death" },
		{ "Comment", "/*Will return info about death*/" },
		{ "DisplayName", "GetDeathInfo" },
		{ "Keywords", "Get Death Info TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Will return info about death" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_GetDeathInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "GetDeathInfo", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_GetDeathInfo_Statics::TDRL_Character_eventGetDeathInfo_Parms), Z_Construct_UFunction_ATDRL_Character_GetDeathInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetDeathInfo_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_GetDeathInfo_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetDeathInfo_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_GetDeathInfo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_GetDeathInfo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_GetEquippedItem_Statics
	{
		struct TDRL_Character_eventGetEquippedItem_Parms
		{
			ATDRL_Item* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATDRL_Character_GetEquippedItem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventGetEquippedItem_Parms, ReturnValue), Z_Construct_UClass_ATDRL_Item_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_GetEquippedItem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_GetEquippedItem_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_GetEquippedItem_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Inventory" },
		{ "Comment", "/*Return the current equipped Item*/" },
		{ "DisplayName", "GetEquippedItem" },
		{ "Keywords", "Get Equipped Item TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Return the current equipped Item" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_GetEquippedItem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "GetEquippedItem", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_GetEquippedItem_Statics::TDRL_Character_eventGetEquippedItem_Parms), Z_Construct_UFunction_ATDRL_Character_GetEquippedItem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetEquippedItem_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_GetEquippedItem_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetEquippedItem_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_GetEquippedItem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_GetEquippedItem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_GetHealthPercentage_Statics
	{
		struct TDRL_Character_eventGetHealthPercentage_Parms
		{
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ATDRL_Character_GetHealthPercentage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventGetHealthPercentage_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_GetHealthPercentage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_GetHealthPercentage_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_GetHealthPercentage_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Health" },
		{ "Comment", "/*Get health percentage (Health/MaxHealth)*/" },
		{ "DisplayName", "GetHealthPercentage" },
		{ "Keywords", "Get Health Percentage TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Get health percentage (Health/MaxHealth)" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_GetHealthPercentage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "GetHealthPercentage", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_GetHealthPercentage_Statics::TDRL_Character_eventGetHealthPercentage_Parms), Z_Construct_UFunction_ATDRL_Character_GetHealthPercentage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetHealthPercentage_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_GetHealthPercentage_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetHealthPercentage_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_GetHealthPercentage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_GetHealthPercentage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_GetHigestRarityItemSlot_Statics
	{
		struct TDRL_Character_eventGetHigestRarityItemSlot_Parms
		{
			bool ShouldBeWeapon;
			uint8 ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ShouldBeWeapon_MetaData[];
#endif
		static void NewProp_ShouldBeWeapon_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ShouldBeWeapon;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_GetHigestRarityItemSlot_Statics::NewProp_ShouldBeWeapon_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_ATDRL_Character_GetHigestRarityItemSlot_Statics::NewProp_ShouldBeWeapon_SetBit(void* Obj)
	{
		((TDRL_Character_eventGetHigestRarityItemSlot_Parms*)Obj)->ShouldBeWeapon = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATDRL_Character_GetHigestRarityItemSlot_Statics::NewProp_ShouldBeWeapon = { "ShouldBeWeapon", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(TDRL_Character_eventGetHigestRarityItemSlot_Parms), &Z_Construct_UFunction_ATDRL_Character_GetHigestRarityItemSlot_Statics::NewProp_ShouldBeWeapon_SetBit, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_GetHigestRarityItemSlot_Statics::NewProp_ShouldBeWeapon_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetHigestRarityItemSlot_Statics::NewProp_ShouldBeWeapon_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ATDRL_Character_GetHigestRarityItemSlot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventGetHigestRarityItemSlot_Parms, ReturnValue), nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_GetHigestRarityItemSlot_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_GetHigestRarityItemSlot_Statics::NewProp_ShouldBeWeapon,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_GetHigestRarityItemSlot_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_GetHigestRarityItemSlot_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Item" },
		{ "Comment", "/*Will return the item's index with the highest rarity value*/" },
		{ "CPP_Default_ShouldBeWeapon", "false" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Will return the item's index with the highest rarity value" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_GetHigestRarityItemSlot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "GetHigestRarityItemSlot", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_GetHigestRarityItemSlot_Statics::TDRL_Character_eventGetHigestRarityItemSlot_Parms), Z_Construct_UFunction_ATDRL_Character_GetHigestRarityItemSlot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetHigestRarityItemSlot_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_GetHigestRarityItemSlot_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetHigestRarityItemSlot_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_GetHigestRarityItemSlot()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_GetHigestRarityItemSlot_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_GetIsDead_Statics
	{
		struct TDRL_Character_eventGetIsDead_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ATDRL_Character_GetIsDead_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((TDRL_Character_eventGetIsDead_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATDRL_Character_GetIsDead_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(TDRL_Character_eventGetIsDead_Parms), &Z_Construct_UFunction_ATDRL_Character_GetIsDead_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_GetIsDead_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_GetIsDead_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_GetIsDead_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Death" },
		{ "Comment", "/*Return if the character is dead (after calling the CharacterDeath function)*/" },
		{ "DisplayName", "GetIsDead" },
		{ "Keywords", "Get Is Dead TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Return if the character is dead (after calling the CharacterDeath function)" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_GetIsDead_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "GetIsDead", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_GetIsDead_Statics::TDRL_Character_eventGetIsDead_Parms), Z_Construct_UFunction_ATDRL_Character_GetIsDead_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetIsDead_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_GetIsDead_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetIsDead_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_GetIsDead()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_GetIsDead_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_GetItemByClass_Statics
	{
		struct TDRL_Character_eventGetItemByClass_Parms
		{
			const TSubclassOf<ATDRL_Item>  InClass;
			int32 IndexOut;
			ATDRL_Item* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_InClass;
		static const UECodeGen_Private::FIntPropertyParams NewProp_IndexOut;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_GetItemByClass_Statics::NewProp_InClass_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_ATDRL_Character_GetItemByClass_Statics::NewProp_InClass = { "InClass", nullptr, (EPropertyFlags)0x0014000000000082, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventGetItemByClass_Parms, InClass), Z_Construct_UClass_UClass, Z_Construct_UClass_ATDRL_Item_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_GetItemByClass_Statics::NewProp_InClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetItemByClass_Statics::NewProp_InClass_MetaData)) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ATDRL_Character_GetItemByClass_Statics::NewProp_IndexOut = { "IndexOut", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventGetItemByClass_Parms, IndexOut), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATDRL_Character_GetItemByClass_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventGetItemByClass_Parms, ReturnValue), Z_Construct_UClass_ATDRL_Item_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_GetItemByClass_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_GetItemByClass_Statics::NewProp_InClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_GetItemByClass_Statics::NewProp_IndexOut,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_GetItemByClass_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_GetItemByClass_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Inventory" },
		{ "Comment", "/*Get first item of the specified class*/" },
		{ "DisplayName", "GetItemByClass" },
		{ "Keywords", "Get Item By Class TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Get first item of the specified class" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_GetItemByClass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "GetItemByClass", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_GetItemByClass_Statics::TDRL_Character_eventGetItemByClass_Parms), Z_Construct_UFunction_ATDRL_Character_GetItemByClass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetItemByClass_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_GetItemByClass_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetItemByClass_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_GetItemByClass()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_GetItemByClass_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_GetLowestRarityItemSlot_Statics
	{
		struct TDRL_Character_eventGetLowestRarityItemSlot_Parms
		{
			bool ShouldBeWeapon;
			uint8 ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ShouldBeWeapon_MetaData[];
#endif
		static void NewProp_ShouldBeWeapon_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ShouldBeWeapon;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_GetLowestRarityItemSlot_Statics::NewProp_ShouldBeWeapon_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_ATDRL_Character_GetLowestRarityItemSlot_Statics::NewProp_ShouldBeWeapon_SetBit(void* Obj)
	{
		((TDRL_Character_eventGetLowestRarityItemSlot_Parms*)Obj)->ShouldBeWeapon = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATDRL_Character_GetLowestRarityItemSlot_Statics::NewProp_ShouldBeWeapon = { "ShouldBeWeapon", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(TDRL_Character_eventGetLowestRarityItemSlot_Parms), &Z_Construct_UFunction_ATDRL_Character_GetLowestRarityItemSlot_Statics::NewProp_ShouldBeWeapon_SetBit, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_GetLowestRarityItemSlot_Statics::NewProp_ShouldBeWeapon_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetLowestRarityItemSlot_Statics::NewProp_ShouldBeWeapon_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ATDRL_Character_GetLowestRarityItemSlot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventGetLowestRarityItemSlot_Parms, ReturnValue), nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_GetLowestRarityItemSlot_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_GetLowestRarityItemSlot_Statics::NewProp_ShouldBeWeapon,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_GetLowestRarityItemSlot_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_GetLowestRarityItemSlot_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Item" },
		{ "Comment", "/*Will return the item's index with the lowest rarity value*/" },
		{ "CPP_Default_ShouldBeWeapon", "false" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Will return the item's index with the lowest rarity value" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_GetLowestRarityItemSlot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "GetLowestRarityItemSlot", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_GetLowestRarityItemSlot_Statics::TDRL_Character_eventGetLowestRarityItemSlot_Parms), Z_Construct_UFunction_ATDRL_Character_GetLowestRarityItemSlot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetLowestRarityItemSlot_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_GetLowestRarityItemSlot_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetLowestRarityItemSlot_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_GetLowestRarityItemSlot()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_GetLowestRarityItemSlot_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_GetNearestNearbyItem_Statics
	{
		struct TDRL_Character_eventGetNearestNearbyItem_Parms
		{
			ATDRL_Item* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATDRL_Character_GetNearestNearbyItem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventGetNearestNearbyItem_Parms, ReturnValue), Z_Construct_UClass_ATDRL_Item_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_GetNearestNearbyItem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_GetNearestNearbyItem_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_GetNearestNearbyItem_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Inventory" },
		{ "Comment", "/*Return the nearest nearby item*/" },
		{ "DisplayName", "GetNearestNearbyItem" },
		{ "Keywords", "Get Nearest Nearby Item TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Return the nearest nearby item" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_GetNearestNearbyItem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "GetNearestNearbyItem", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_GetNearestNearbyItem_Statics::TDRL_Character_eventGetNearestNearbyItem_Parms), Z_Construct_UFunction_ATDRL_Character_GetNearestNearbyItem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetNearestNearbyItem_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_GetNearestNearbyItem_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetNearestNearbyItem_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_GetNearestNearbyItem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_GetNearestNearbyItem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_GetNPCController_Statics
	{
		struct TDRL_Character_eventGetNPCController_Parms
		{
			ATDRL_NPCController* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATDRL_Character_GetNPCController_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventGetNPCController_Parms, ReturnValue), Z_Construct_UClass_ATDRL_NPCController_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_GetNPCController_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_GetNPCController_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_GetNPCController_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|AI" },
		{ "Comment", "/*Return the AIController as ATDRL_NPCController. Return null if the character is not possessed by AI or it's player possessed*/" },
		{ "DisplayName", "GetNPCController" },
		{ "Keywords", "Get NPC AI Controller TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Return the AIController as ATDRL_NPCController. Return null if the character is not possessed by AI or it's player possessed" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_GetNPCController_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "GetNPCController", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_GetNPCController_Statics::TDRL_Character_eventGetNPCController_Parms), Z_Construct_UFunction_ATDRL_Character_GetNPCController_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetNPCController_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_GetNPCController_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetNPCController_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_GetNPCController()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_GetNPCController_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_GetSightComponent_Statics
	{
		struct TDRL_Character_eventGetSightComponent_Parms
		{
			UTDRL_LineOfSightComponent* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_GetSightComponent_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATDRL_Character_GetSightComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventGetSightComponent_Parms, ReturnValue), Z_Construct_UClass_UTDRL_LineOfSightComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_GetSightComponent_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetSightComponent_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_GetSightComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_GetSightComponent_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_GetSightComponent_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Components" },
		{ "Comment", "/*Return the Character's SightComponent*/" },
		{ "DisplayName", "GetSightComponent" },
		{ "Keywords", "Get Sight Component TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Return the Character's SightComponent" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_GetSightComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "GetSightComponent", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_GetSightComponent_Statics::TDRL_Character_eventGetSightComponent_Parms), Z_Construct_UFunction_ATDRL_Character_GetSightComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetSightComponent_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_GetSightComponent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetSightComponent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_GetSightComponent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_GetSightComponent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_GetSlotsOccupiedByItemClass_Statics
	{
		struct TDRL_Character_eventGetSlotsOccupiedByItemClass_Parms
		{
			const TSubclassOf<ATDRL_Item>  InClass;
			bool bIncludeSubclasses;
			TArray<uint8> ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_InClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIncludeSubclasses_MetaData[];
#endif
		static void NewProp_bIncludeSubclasses_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIncludeSubclasses;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_GetSlotsOccupiedByItemClass_Statics::NewProp_InClass_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_ATDRL_Character_GetSlotsOccupiedByItemClass_Statics::NewProp_InClass = { "InClass", nullptr, (EPropertyFlags)0x0014000000000082, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventGetSlotsOccupiedByItemClass_Parms, InClass), Z_Construct_UClass_UClass, Z_Construct_UClass_ATDRL_Item_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_GetSlotsOccupiedByItemClass_Statics::NewProp_InClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetSlotsOccupiedByItemClass_Statics::NewProp_InClass_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_GetSlotsOccupiedByItemClass_Statics::NewProp_bIncludeSubclasses_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_ATDRL_Character_GetSlotsOccupiedByItemClass_Statics::NewProp_bIncludeSubclasses_SetBit(void* Obj)
	{
		((TDRL_Character_eventGetSlotsOccupiedByItemClass_Parms*)Obj)->bIncludeSubclasses = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATDRL_Character_GetSlotsOccupiedByItemClass_Statics::NewProp_bIncludeSubclasses = { "bIncludeSubclasses", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(TDRL_Character_eventGetSlotsOccupiedByItemClass_Parms), &Z_Construct_UFunction_ATDRL_Character_GetSlotsOccupiedByItemClass_Statics::NewProp_bIncludeSubclasses_SetBit, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_GetSlotsOccupiedByItemClass_Statics::NewProp_bIncludeSubclasses_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetSlotsOccupiedByItemClass_Statics::NewProp_bIncludeSubclasses_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ATDRL_Character_GetSlotsOccupiedByItemClass_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ATDRL_Character_GetSlotsOccupiedByItemClass_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventGetSlotsOccupiedByItemClass_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_GetSlotsOccupiedByItemClass_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_GetSlotsOccupiedByItemClass_Statics::NewProp_InClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_GetSlotsOccupiedByItemClass_Statics::NewProp_bIncludeSubclasses,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_GetSlotsOccupiedByItemClass_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_GetSlotsOccupiedByItemClass_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_GetSlotsOccupiedByItemClass_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Inventory" },
		{ "Comment", "/*Return the list of slots occupied by a particular drink*/" },
		{ "CPP_Default_bIncludeSubclasses", "false" },
		{ "DisplayName", "GetSlotsOccupiedByItemClass" },
		{ "Keywords", "Get Slots Occupied By Item Class TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Return the list of slots occupied by a particular drink" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_GetSlotsOccupiedByItemClass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "GetSlotsOccupiedByItemClass", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_GetSlotsOccupiedByItemClass_Statics::TDRL_Character_eventGetSlotsOccupiedByItemClass_Parms), Z_Construct_UFunction_ATDRL_Character_GetSlotsOccupiedByItemClass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetSlotsOccupiedByItemClass_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_GetSlotsOccupiedByItemClass_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetSlotsOccupiedByItemClass_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_GetSlotsOccupiedByItemClass()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_GetSlotsOccupiedByItemClass_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_GetStunValue_Statics
	{
		struct TDRL_Character_eventGetStunValue_Parms
		{
			FStunParameters Value;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Value;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATDRL_Character_GetStunValue_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventGetStunValue_Parms, Value), Z_Construct_UScriptStruct_FStunParameters, METADATA_PARAMS(nullptr, 0) }; // 1924132683
	void Z_Construct_UFunction_ATDRL_Character_GetStunValue_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((TDRL_Character_eventGetStunValue_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATDRL_Character_GetStunValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(TDRL_Character_eventGetStunValue_Parms), &Z_Construct_UFunction_ATDRL_Character_GetStunValue_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_GetStunValue_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_GetStunValue_Statics::NewProp_Value,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_GetStunValue_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_GetStunValue_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Stun" },
		{ "Comment", "/*Return if the character is currently stunned and the current Stun parameters*/" },
		{ "DisplayName", "GetStunValue" },
		{ "Keywords", "Get Stun Value TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Return if the character is currently stunned and the current Stun parameters" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_GetStunValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "GetStunValue", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_GetStunValue_Statics::TDRL_Character_eventGetStunValue_Parms), Z_Construct_UFunction_ATDRL_Character_GetStunValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetStunValue_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_GetStunValue_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetStunValue_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_GetStunValue()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_GetStunValue_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_GetTDRLMovementComponent_Statics
	{
		struct TDRL_Character_eventGetTDRLMovementComponent_Parms
		{
			UTDRL_CharacterMovementComponent* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_GetTDRLMovementComponent_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATDRL_Character_GetTDRLMovementComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventGetTDRLMovementComponent_Parms, ReturnValue), Z_Construct_UClass_UTDRL_CharacterMovementComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_GetTDRLMovementComponent_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetTDRLMovementComponent_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_GetTDRLMovementComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_GetTDRLMovementComponent_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_GetTDRLMovementComponent_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Components" },
		{ "Comment", "/*Return the UCharacterMovementComponent as UTDRL_CharacterMovementComponen*/" },
		{ "DisplayName", "GetCharacterMovement(TDRL)" },
		{ "Keywords", "Get Character Movement Component TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Return the UCharacterMovementComponent as UTDRL_CharacterMovementComponen" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_GetTDRLMovementComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "GetTDRLMovementComponent", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_GetTDRLMovementComponent_Statics::TDRL_Character_eventGetTDRLMovementComponent_Parms), Z_Construct_UFunction_ATDRL_Character_GetTDRLMovementComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetTDRLMovementComponent_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_GetTDRLMovementComponent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GetTDRLMovementComponent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_GetTDRLMovementComponent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_GetTDRLMovementComponent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_GiveInitialAbilities_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_GiveInitialAbilities_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_GiveInitialAbilities_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "GiveInitialAbilities", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_GiveInitialAbilities_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_GiveInitialAbilities_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_GiveInitialAbilities()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_GiveInitialAbilities_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_HasItemOfClass_Statics
	{
		struct TDRL_Character_eventHasItemOfClass_Parms
		{
			const TSubclassOf<ATDRL_Item>  InClass;
			bool bIncludeSubclasses;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_InClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIncludeSubclasses_MetaData[];
#endif
		static void NewProp_bIncludeSubclasses_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIncludeSubclasses;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_HasItemOfClass_Statics::NewProp_InClass_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_ATDRL_Character_HasItemOfClass_Statics::NewProp_InClass = { "InClass", nullptr, (EPropertyFlags)0x0014000000000082, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventHasItemOfClass_Parms, InClass), Z_Construct_UClass_UClass, Z_Construct_UClass_ATDRL_Item_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_HasItemOfClass_Statics::NewProp_InClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_HasItemOfClass_Statics::NewProp_InClass_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_HasItemOfClass_Statics::NewProp_bIncludeSubclasses_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_ATDRL_Character_HasItemOfClass_Statics::NewProp_bIncludeSubclasses_SetBit(void* Obj)
	{
		((TDRL_Character_eventHasItemOfClass_Parms*)Obj)->bIncludeSubclasses = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATDRL_Character_HasItemOfClass_Statics::NewProp_bIncludeSubclasses = { "bIncludeSubclasses", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(TDRL_Character_eventHasItemOfClass_Parms), &Z_Construct_UFunction_ATDRL_Character_HasItemOfClass_Statics::NewProp_bIncludeSubclasses_SetBit, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_HasItemOfClass_Statics::NewProp_bIncludeSubclasses_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_HasItemOfClass_Statics::NewProp_bIncludeSubclasses_MetaData)) };
	void Z_Construct_UFunction_ATDRL_Character_HasItemOfClass_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((TDRL_Character_eventHasItemOfClass_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATDRL_Character_HasItemOfClass_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(TDRL_Character_eventHasItemOfClass_Parms), &Z_Construct_UFunction_ATDRL_Character_HasItemOfClass_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_HasItemOfClass_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_HasItemOfClass_Statics::NewProp_InClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_HasItemOfClass_Statics::NewProp_bIncludeSubclasses,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_HasItemOfClass_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_HasItemOfClass_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Inventory" },
		{ "Comment", "/*Return true if there's at least one item derived from the specified class*/" },
		{ "CPP_Default_bIncludeSubclasses", "false" },
		{ "DisplayName", "HasItemOfClass" },
		{ "Keywords", "Has Item Of Class TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Return true if there's at least one item derived from the specified class" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_HasItemOfClass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "HasItemOfClass", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_HasItemOfClass_Statics::TDRL_Character_eventHasItemOfClass_Parms), Z_Construct_UFunction_ATDRL_Character_HasItemOfClass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_HasItemOfClass_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_HasItemOfClass_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_HasItemOfClass_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_HasItemOfClass()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_HasItemOfClass_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_HasNearbyItems_Statics
	{
		struct TDRL_Character_eventHasNearbyItems_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ATDRL_Character_HasNearbyItems_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((TDRL_Character_eventHasNearbyItems_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATDRL_Character_HasNearbyItems_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(TDRL_Character_eventHasNearbyItems_Parms), &Z_Construct_UFunction_ATDRL_Character_HasNearbyItems_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_HasNearbyItems_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_HasNearbyItems_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_HasNearbyItems_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Inventory" },
		{ "Comment", "/*Return true if there's at least one nearby item*/" },
		{ "DisplayName", "HasNearbyItems" },
		{ "Keywords", "Has Nearby Items TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Return true if there's at least one nearby item" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_HasNearbyItems_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "HasNearbyItems", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_HasNearbyItems_Statics::TDRL_Character_eventHasNearbyItems_Parms), Z_Construct_UFunction_ATDRL_Character_HasNearbyItems_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_HasNearbyItems_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_HasNearbyItems_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_HasNearbyItems_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_HasNearbyItems()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_HasNearbyItems_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_Heal_Statics
	{
		struct TDRL_Character_eventHeal_Parms
		{
			float Value;
			FStatusEffect Effect;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Value;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Effect;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Heal_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ATDRL_Character_Heal_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventHeal_Parms, Value), METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Heal_Statics::NewProp_Value_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Heal_Statics::NewProp_Value_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATDRL_Character_Heal_Statics::NewProp_Effect = { "Effect", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventHeal_Parms, Effect), Z_Construct_UScriptStruct_FStatusEffect, METADATA_PARAMS(nullptr, 0) }; // 540262957
	void Z_Construct_UFunction_ATDRL_Character_Heal_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((TDRL_Character_eventHeal_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATDRL_Character_Heal_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(TDRL_Character_eventHeal_Parms), &Z_Construct_UFunction_ATDRL_Character_Heal_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_Heal_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_Heal_Statics::NewProp_Value,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_Heal_Statics::NewProp_Effect,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_Heal_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Heal_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Health" },
		{ "Comment", "/*Heal character (Server Only)*/" },
		{ "DisplayName", "Heal" },
		{ "Keywords", "Heal Health TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Heal character (Server Only)" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_Heal_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "Heal", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_Heal_Statics::TDRL_Character_eventHeal_Parms), Z_Construct_UFunction_ATDRL_Character_Heal_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Heal_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020404, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Heal_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Heal_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_Heal()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_Heal_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_Heal_Effects_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Value;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Heal_Effects_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATDRL_Character_Heal_Effects_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventHeal_Effects_Parms, Value), Z_Construct_UScriptStruct_FStatusEffect, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Heal_Effects_Statics::NewProp_Value_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Heal_Effects_Statics::NewProp_Value_MetaData)) }; // 540262957
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_Heal_Effects_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_Heal_Effects_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Heal_Effects_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_Heal_Effects_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "Heal_Effects", nullptr, nullptr, sizeof(TDRL_Character_eventHeal_Effects_Parms), Z_Construct_UFunction_ATDRL_Character_Heal_Effects_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Heal_Effects_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00024C40, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Heal_Effects_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Heal_Effects_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_Heal_Effects()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_Heal_Effects_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_InitializeDefaultAttributeValues_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_InitializeDefaultAttributeValues_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_InitializeDefaultAttributeValues_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "InitializeDefaultAttributeValues", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_InitializeDefaultAttributeValues_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_InitializeDefaultAttributeValues_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_InitializeDefaultAttributeValues()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_InitializeDefaultAttributeValues_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_Input_AlternativeWalk_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Pressed_MetaData[];
#endif
		static void NewProp_Pressed_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Pressed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Input_AlternativeWalk_Statics::NewProp_Pressed_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_ATDRL_Character_Input_AlternativeWalk_Statics::NewProp_Pressed_SetBit(void* Obj)
	{
		((TDRL_Character_eventInput_AlternativeWalk_Parms*)Obj)->Pressed = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATDRL_Character_Input_AlternativeWalk_Statics::NewProp_Pressed = { "Pressed", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(TDRL_Character_eventInput_AlternativeWalk_Parms), &Z_Construct_UFunction_ATDRL_Character_Input_AlternativeWalk_Statics::NewProp_Pressed_SetBit, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Input_AlternativeWalk_Statics::NewProp_Pressed_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_AlternativeWalk_Statics::NewProp_Pressed_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_Input_AlternativeWalk_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_Input_AlternativeWalk_Statics::NewProp_Pressed,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Input_AlternativeWalk_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Input" },
		{ "DisplayName", "Input_AlternativeWalk" },
		{ "Keywords", "Input Alternative Walk TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_Input_AlternativeWalk_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "Input_AlternativeWalk", nullptr, nullptr, sizeof(TDRL_Character_eventInput_AlternativeWalk_Parms), Z_Construct_UFunction_ATDRL_Character_Input_AlternativeWalk_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_AlternativeWalk_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Input_AlternativeWalk_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_AlternativeWalk_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_Input_AlternativeWalk()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_Input_AlternativeWalk_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_Input_ChangeItemSlot_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Slot_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_Slot;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Input_ChangeItemSlot_Statics::NewProp_Slot_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ATDRL_Character_Input_ChangeItemSlot_Statics::NewProp_Slot = { "Slot", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventInput_ChangeItemSlot_Parms, Slot), nullptr, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Input_ChangeItemSlot_Statics::NewProp_Slot_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_ChangeItemSlot_Statics::NewProp_Slot_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_Input_ChangeItemSlot_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_Input_ChangeItemSlot_Statics::NewProp_Slot,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Input_ChangeItemSlot_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Input" },
		{ "DisplayName", "Input_ChangeItemSlot" },
		{ "Keywords", "Input Change Item Slot TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_Input_ChangeItemSlot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "Input_ChangeItemSlot", nullptr, nullptr, sizeof(TDRL_Character_eventInput_ChangeItemSlot_Parms), Z_Construct_UFunction_ATDRL_Character_Input_ChangeItemSlot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_ChangeItemSlot_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Input_ChangeItemSlot_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_ChangeItemSlot_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_Input_ChangeItemSlot()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_Input_ChangeItemSlot_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_Input_Crouch_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Pressed_MetaData[];
#endif
		static void NewProp_Pressed_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Pressed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Input_Crouch_Statics::NewProp_Pressed_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_ATDRL_Character_Input_Crouch_Statics::NewProp_Pressed_SetBit(void* Obj)
	{
		((TDRL_Character_eventInput_Crouch_Parms*)Obj)->Pressed = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATDRL_Character_Input_Crouch_Statics::NewProp_Pressed = { "Pressed", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(TDRL_Character_eventInput_Crouch_Parms), &Z_Construct_UFunction_ATDRL_Character_Input_Crouch_Statics::NewProp_Pressed_SetBit, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Input_Crouch_Statics::NewProp_Pressed_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_Crouch_Statics::NewProp_Pressed_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_Input_Crouch_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_Input_Crouch_Statics::NewProp_Pressed,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Input_Crouch_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Input" },
		{ "DisplayName", "Input_Crouch" },
		{ "Keywords", "Input Crouch TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_Input_Crouch_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "Input_Crouch", nullptr, nullptr, sizeof(TDRL_Character_eventInput_Crouch_Parms), Z_Construct_UFunction_ATDRL_Character_Input_Crouch_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_Crouch_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Input_Crouch_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_Crouch_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_Input_Crouch()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_Input_Crouch_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_Input_Dash_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Pressed_MetaData[];
#endif
		static void NewProp_Pressed_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Pressed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Input_Dash_Statics::NewProp_Pressed_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_ATDRL_Character_Input_Dash_Statics::NewProp_Pressed_SetBit(void* Obj)
	{
		((TDRL_Character_eventInput_Dash_Parms*)Obj)->Pressed = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATDRL_Character_Input_Dash_Statics::NewProp_Pressed = { "Pressed", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(TDRL_Character_eventInput_Dash_Parms), &Z_Construct_UFunction_ATDRL_Character_Input_Dash_Statics::NewProp_Pressed_SetBit, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Input_Dash_Statics::NewProp_Pressed_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_Dash_Statics::NewProp_Pressed_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_Input_Dash_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_Input_Dash_Statics::NewProp_Pressed,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Input_Dash_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Input" },
		{ "DisplayName", "Input_Dash" },
		{ "Keywords", "Input Dash TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_Input_Dash_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "Input_Dash", nullptr, nullptr, sizeof(TDRL_Character_eventInput_Dash_Parms), Z_Construct_UFunction_ATDRL_Character_Input_Dash_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_Dash_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Input_Dash_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_Dash_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_Input_Dash()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_Input_Dash_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_Input_Drop_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Pressed_MetaData[];
#endif
		static void NewProp_Pressed_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Pressed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Input_Drop_Statics::NewProp_Pressed_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_ATDRL_Character_Input_Drop_Statics::NewProp_Pressed_SetBit(void* Obj)
	{
		((TDRL_Character_eventInput_Drop_Parms*)Obj)->Pressed = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATDRL_Character_Input_Drop_Statics::NewProp_Pressed = { "Pressed", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(TDRL_Character_eventInput_Drop_Parms), &Z_Construct_UFunction_ATDRL_Character_Input_Drop_Statics::NewProp_Pressed_SetBit, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Input_Drop_Statics::NewProp_Pressed_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_Drop_Statics::NewProp_Pressed_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_Input_Drop_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_Input_Drop_Statics::NewProp_Pressed,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Input_Drop_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Input" },
		{ "DisplayName", "Input_Drop" },
		{ "Keywords", "Input Drop TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_Input_Drop_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "Input_Drop", nullptr, nullptr, sizeof(TDRL_Character_eventInput_Drop_Parms), Z_Construct_UFunction_ATDRL_Character_Input_Drop_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_Drop_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Input_Drop_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_Drop_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_Input_Drop()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_Input_Drop_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_Input_Jump_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Pressed_MetaData[];
#endif
		static void NewProp_Pressed_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Pressed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Input_Jump_Statics::NewProp_Pressed_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_ATDRL_Character_Input_Jump_Statics::NewProp_Pressed_SetBit(void* Obj)
	{
		((TDRL_Character_eventInput_Jump_Parms*)Obj)->Pressed = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATDRL_Character_Input_Jump_Statics::NewProp_Pressed = { "Pressed", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(TDRL_Character_eventInput_Jump_Parms), &Z_Construct_UFunction_ATDRL_Character_Input_Jump_Statics::NewProp_Pressed_SetBit, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Input_Jump_Statics::NewProp_Pressed_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_Jump_Statics::NewProp_Pressed_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_Input_Jump_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_Input_Jump_Statics::NewProp_Pressed,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Input_Jump_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Input" },
		{ "DisplayName", "Input_Jump" },
		{ "Keywords", "Input Jump TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_Input_Jump_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "Input_Jump", nullptr, nullptr, sizeof(TDRL_Character_eventInput_Jump_Parms), Z_Construct_UFunction_ATDRL_Character_Input_Jump_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_Jump_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Input_Jump_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_Jump_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_Input_Jump()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_Input_Jump_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_Input_LockTarget_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Pressed_MetaData[];
#endif
		static void NewProp_Pressed_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Pressed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Input_LockTarget_Statics::NewProp_Pressed_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_ATDRL_Character_Input_LockTarget_Statics::NewProp_Pressed_SetBit(void* Obj)
	{
		((TDRL_Character_eventInput_LockTarget_Parms*)Obj)->Pressed = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATDRL_Character_Input_LockTarget_Statics::NewProp_Pressed = { "Pressed", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(TDRL_Character_eventInput_LockTarget_Parms), &Z_Construct_UFunction_ATDRL_Character_Input_LockTarget_Statics::NewProp_Pressed_SetBit, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Input_LockTarget_Statics::NewProp_Pressed_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_LockTarget_Statics::NewProp_Pressed_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_Input_LockTarget_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_Input_LockTarget_Statics::NewProp_Pressed,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Input_LockTarget_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Input" },
		{ "DisplayName", "Input_LockTarget" },
		{ "Keywords", "Input Lock Target TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_Input_LockTarget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "Input_LockTarget", nullptr, nullptr, sizeof(TDRL_Character_eventInput_LockTarget_Parms), Z_Construct_UFunction_ATDRL_Character_Input_LockTarget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_LockTarget_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Input_LockTarget_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_LockTarget_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_Input_LockTarget()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_Input_LockTarget_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_Input_Move_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Direction_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Direction;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Input_Move_Statics::NewProp_Direction_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATDRL_Character_Input_Move_Statics::NewProp_Direction = { "Direction", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventInput_Move_Parms, Direction), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Input_Move_Statics::NewProp_Direction_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_Move_Statics::NewProp_Direction_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_Input_Move_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_Input_Move_Statics::NewProp_Direction,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Input_Move_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Input" },
		{ "DisplayName", "Input_Move" },
		{ "Keywords", "Input Move TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_Input_Move_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "Input_Move", nullptr, nullptr, sizeof(TDRL_Character_eventInput_Move_Parms), Z_Construct_UFunction_ATDRL_Character_Input_Move_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_Move_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C820C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Input_Move_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_Move_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_Input_Move()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_Input_Move_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_Input_Pickup_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Pressed_MetaData[];
#endif
		static void NewProp_Pressed_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Pressed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Input_Pickup_Statics::NewProp_Pressed_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_ATDRL_Character_Input_Pickup_Statics::NewProp_Pressed_SetBit(void* Obj)
	{
		((TDRL_Character_eventInput_Pickup_Parms*)Obj)->Pressed = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATDRL_Character_Input_Pickup_Statics::NewProp_Pressed = { "Pressed", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(TDRL_Character_eventInput_Pickup_Parms), &Z_Construct_UFunction_ATDRL_Character_Input_Pickup_Statics::NewProp_Pressed_SetBit, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Input_Pickup_Statics::NewProp_Pressed_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_Pickup_Statics::NewProp_Pressed_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_Input_Pickup_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_Input_Pickup_Statics::NewProp_Pressed,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Input_Pickup_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Input" },
		{ "DisplayName", "Input_Pickup" },
		{ "Keywords", "Input Pickup TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_Input_Pickup_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "Input_Pickup", nullptr, nullptr, sizeof(TDRL_Character_eventInput_Pickup_Parms), Z_Construct_UFunction_ATDRL_Character_Input_Pickup_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_Pickup_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Input_Pickup_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_Pickup_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_Input_Pickup()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_Input_Pickup_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_Input_PitchAim_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Pressed_MetaData[];
#endif
		static void NewProp_Pressed_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Pressed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Input_PitchAim_Statics::NewProp_Pressed_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_ATDRL_Character_Input_PitchAim_Statics::NewProp_Pressed_SetBit(void* Obj)
	{
		((TDRL_Character_eventInput_PitchAim_Parms*)Obj)->Pressed = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATDRL_Character_Input_PitchAim_Statics::NewProp_Pressed = { "Pressed", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(TDRL_Character_eventInput_PitchAim_Parms), &Z_Construct_UFunction_ATDRL_Character_Input_PitchAim_Statics::NewProp_Pressed_SetBit, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Input_PitchAim_Statics::NewProp_Pressed_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_PitchAim_Statics::NewProp_Pressed_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_Input_PitchAim_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_Input_PitchAim_Statics::NewProp_Pressed,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Input_PitchAim_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Input" },
		{ "DisplayName", "Input_PitchAim" },
		{ "Keywords", "Input PitchAim TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_Input_PitchAim_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "Input_PitchAim", nullptr, nullptr, sizeof(TDRL_Character_eventInput_PitchAim_Parms), Z_Construct_UFunction_ATDRL_Character_Input_PitchAim_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_PitchAim_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Input_PitchAim_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_PitchAim_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_Input_PitchAim()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_Input_PitchAim_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_Input_PrimaryAction_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Pressed_MetaData[];
#endif
		static void NewProp_Pressed_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Pressed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Input_PrimaryAction_Statics::NewProp_Pressed_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_ATDRL_Character_Input_PrimaryAction_Statics::NewProp_Pressed_SetBit(void* Obj)
	{
		((TDRL_Character_eventInput_PrimaryAction_Parms*)Obj)->Pressed = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATDRL_Character_Input_PrimaryAction_Statics::NewProp_Pressed = { "Pressed", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(TDRL_Character_eventInput_PrimaryAction_Parms), &Z_Construct_UFunction_ATDRL_Character_Input_PrimaryAction_Statics::NewProp_Pressed_SetBit, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Input_PrimaryAction_Statics::NewProp_Pressed_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_PrimaryAction_Statics::NewProp_Pressed_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_Input_PrimaryAction_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_Input_PrimaryAction_Statics::NewProp_Pressed,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Input_PrimaryAction_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Input" },
		{ "DisplayName", "Input_PrimaryAction" },
		{ "Keywords", "Input Primary Action TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_Input_PrimaryAction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "Input_PrimaryAction", nullptr, nullptr, sizeof(TDRL_Character_eventInput_PrimaryAction_Parms), Z_Construct_UFunction_ATDRL_Character_Input_PrimaryAction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_PrimaryAction_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Input_PrimaryAction_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_PrimaryAction_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_Input_PrimaryAction()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_Input_PrimaryAction_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_Input_RAction_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Pressed_MetaData[];
#endif
		static void NewProp_Pressed_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Pressed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Input_RAction_Statics::NewProp_Pressed_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_ATDRL_Character_Input_RAction_Statics::NewProp_Pressed_SetBit(void* Obj)
	{
		((TDRL_Character_eventInput_RAction_Parms*)Obj)->Pressed = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATDRL_Character_Input_RAction_Statics::NewProp_Pressed = { "Pressed", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(TDRL_Character_eventInput_RAction_Parms), &Z_Construct_UFunction_ATDRL_Character_Input_RAction_Statics::NewProp_Pressed_SetBit, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Input_RAction_Statics::NewProp_Pressed_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_RAction_Statics::NewProp_Pressed_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_Input_RAction_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_Input_RAction_Statics::NewProp_Pressed,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Input_RAction_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Input" },
		{ "DisplayName", "Input_RAction" },
		{ "Keywords", "Input R Action TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_Input_RAction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "Input_RAction", nullptr, nullptr, sizeof(TDRL_Character_eventInput_RAction_Parms), Z_Construct_UFunction_ATDRL_Character_Input_RAction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_RAction_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Input_RAction_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_RAction_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_Input_RAction()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_Input_RAction_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_Input_RotateCamera_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Value;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Input_RotateCamera_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ATDRL_Character_Input_RotateCamera_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventInput_RotateCamera_Parms, Value), METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Input_RotateCamera_Statics::NewProp_Value_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_RotateCamera_Statics::NewProp_Value_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_Input_RotateCamera_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_Input_RotateCamera_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Input_RotateCamera_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Input" },
		{ "DisplayName", "Input_RotateCamera" },
		{ "Keywords", "Input Rotate Camera TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_Input_RotateCamera_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "Input_RotateCamera", nullptr, nullptr, sizeof(TDRL_Character_eventInput_RotateCamera_Parms), Z_Construct_UFunction_ATDRL_Character_Input_RotateCamera_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_RotateCamera_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Input_RotateCamera_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_RotateCamera_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_Input_RotateCamera()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_Input_RotateCamera_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_Input_SecondaryAction_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Pressed_MetaData[];
#endif
		static void NewProp_Pressed_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Pressed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Input_SecondaryAction_Statics::NewProp_Pressed_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_ATDRL_Character_Input_SecondaryAction_Statics::NewProp_Pressed_SetBit(void* Obj)
	{
		((TDRL_Character_eventInput_SecondaryAction_Parms*)Obj)->Pressed = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATDRL_Character_Input_SecondaryAction_Statics::NewProp_Pressed = { "Pressed", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(TDRL_Character_eventInput_SecondaryAction_Parms), &Z_Construct_UFunction_ATDRL_Character_Input_SecondaryAction_Statics::NewProp_Pressed_SetBit, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Input_SecondaryAction_Statics::NewProp_Pressed_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_SecondaryAction_Statics::NewProp_Pressed_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_Input_SecondaryAction_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_Input_SecondaryAction_Statics::NewProp_Pressed,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Input_SecondaryAction_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Input" },
		{ "DisplayName", "Input_SecondaryAction" },
		{ "Keywords", "Input Secondary Action TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_Input_SecondaryAction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "Input_SecondaryAction", nullptr, nullptr, sizeof(TDRL_Character_eventInput_SecondaryAction_Parms), Z_Construct_UFunction_ATDRL_Character_Input_SecondaryAction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_SecondaryAction_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Input_SecondaryAction_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Input_SecondaryAction_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_Input_SecondaryAction()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_Input_SecondaryAction_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_IsDashing_Statics
	{
		struct TDRL_Character_eventIsDashing_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ATDRL_Character_IsDashing_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((TDRL_Character_eventIsDashing_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATDRL_Character_IsDashing_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(TDRL_Character_eventIsDashing_Parms), &Z_Construct_UFunction_ATDRL_Character_IsDashing_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_IsDashing_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_IsDashing_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_IsDashing_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Movements" },
		{ "Comment", "/*Return true if it's currently dashing*/" },
		{ "DisplayName", "IsDashing" },
		{ "Keywords", "Is Dashing TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Return true if it's currently dashing" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_IsDashing_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "IsDashing", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_IsDashing_Statics::TDRL_Character_eventIsDashing_Parms), Z_Construct_UFunction_ATDRL_Character_IsDashing_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_IsDashing_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_IsDashing_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_IsDashing_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_IsDashing()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_IsDashing_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_IsStunned_Statics
	{
		struct TDRL_Character_eventIsStunned_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ATDRL_Character_IsStunned_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((TDRL_Character_eventIsStunned_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATDRL_Character_IsStunned_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(TDRL_Character_eventIsStunned_Parms), &Z_Construct_UFunction_ATDRL_Character_IsStunned_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_IsStunned_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_IsStunned_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_IsStunned_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Stun" },
		{ "Comment", "/*Is currently stunned?*/" },
		{ "DisplayName", "IsStunned" },
		{ "Keywords", "Is Stunned Stun TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Is currently stunned?" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_IsStunned_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "IsStunned", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_IsStunned_Statics::TDRL_Character_eventIsStunned_Parms), Z_Construct_UFunction_ATDRL_Character_IsStunned_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_IsStunned_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_IsStunned_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_IsStunned_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_IsStunned()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_IsStunned_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_OnRep_CurrentStun_Statics
	{
		struct TDRL_Character_eventOnRep_CurrentStun_Parms
		{
			FStunParameters OldValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OldValue_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_OldValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_OnRep_CurrentStun_Statics::NewProp_OldValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATDRL_Character_OnRep_CurrentStun_Statics::NewProp_OldValue = { "OldValue", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventOnRep_CurrentStun_Parms, OldValue), Z_Construct_UScriptStruct_FStunParameters, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_OnRep_CurrentStun_Statics::NewProp_OldValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_OnRep_CurrentStun_Statics::NewProp_OldValue_MetaData)) }; // 1924132683
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_OnRep_CurrentStun_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_OnRep_CurrentStun_Statics::NewProp_OldValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_OnRep_CurrentStun_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_OnRep_CurrentStun_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "OnRep_CurrentStun", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_OnRep_CurrentStun_Statics::TDRL_Character_eventOnRep_CurrentStun_Parms), Z_Construct_UFunction_ATDRL_Character_OnRep_CurrentStun_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_OnRep_CurrentStun_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_OnRep_CurrentStun_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_OnRep_CurrentStun_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_OnRep_CurrentStun()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_OnRep_CurrentStun_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_OnRep_DeathInfo_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_OnRep_DeathInfo_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_OnRep_DeathInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "OnRep_DeathInfo", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_OnRep_DeathInfo_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_OnRep_DeathInfo_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_OnRep_DeathInfo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_OnRep_DeathInfo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_OnRep_HealthModified_Statics
	{
		struct TDRL_Character_eventOnRep_HealthModified_Parms
		{
			float Previous;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Previous_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Previous;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_OnRep_HealthModified_Statics::NewProp_Previous_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ATDRL_Character_OnRep_HealthModified_Statics::NewProp_Previous = { "Previous", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventOnRep_HealthModified_Parms, Previous), METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_OnRep_HealthModified_Statics::NewProp_Previous_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_OnRep_HealthModified_Statics::NewProp_Previous_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_OnRep_HealthModified_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_OnRep_HealthModified_Statics::NewProp_Previous,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_OnRep_HealthModified_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_OnRep_HealthModified_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "OnRep_HealthModified", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_OnRep_HealthModified_Statics::TDRL_Character_eventOnRep_HealthModified_Parms), Z_Construct_UFunction_ATDRL_Character_OnRep_HealthModified_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_OnRep_HealthModified_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_OnRep_HealthModified_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_OnRep_HealthModified_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_OnRep_HealthModified()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_OnRep_HealthModified_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_OnRep_InventoryModified_Statics
	{
		struct TDRL_Character_eventOnRep_InventoryModified_Parms
		{
			TArray<ATDRL_Item*> Previous;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Previous_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Previous_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Previous;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATDRL_Character_OnRep_InventoryModified_Statics::NewProp_Previous_Inner = { "Previous", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UClass_ATDRL_Item_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_OnRep_InventoryModified_Statics::NewProp_Previous_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ATDRL_Character_OnRep_InventoryModified_Statics::NewProp_Previous = { "Previous", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventOnRep_InventoryModified_Parms, Previous), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_OnRep_InventoryModified_Statics::NewProp_Previous_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_OnRep_InventoryModified_Statics::NewProp_Previous_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_OnRep_InventoryModified_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_OnRep_InventoryModified_Statics::NewProp_Previous_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_OnRep_InventoryModified_Statics::NewProp_Previous,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_OnRep_InventoryModified_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_OnRep_InventoryModified_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "OnRep_InventoryModified", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_OnRep_InventoryModified_Statics::TDRL_Character_eventOnRep_InventoryModified_Parms), Z_Construct_UFunction_ATDRL_Character_OnRep_InventoryModified_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_OnRep_InventoryModified_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_OnRep_InventoryModified_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_OnRep_InventoryModified_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_OnRep_InventoryModified()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_OnRep_InventoryModified_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_OnRep_MainWeaponModified_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_OnRep_MainWeaponModified_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_OnRep_MainWeaponModified_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "OnRep_MainWeaponModified", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_OnRep_MainWeaponModified_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_OnRep_MainWeaponModified_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_OnRep_MainWeaponModified()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_OnRep_MainWeaponModified_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_OnRep_SlotSelectionModified_Statics
	{
		struct TDRL_Character_eventOnRep_SlotSelectionModified_Parms
		{
			uint8 Previous;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Previous_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_Previous;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_OnRep_SlotSelectionModified_Statics::NewProp_Previous_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ATDRL_Character_OnRep_SlotSelectionModified_Statics::NewProp_Previous = { "Previous", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventOnRep_SlotSelectionModified_Parms, Previous), nullptr, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_OnRep_SlotSelectionModified_Statics::NewProp_Previous_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_OnRep_SlotSelectionModified_Statics::NewProp_Previous_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_OnRep_SlotSelectionModified_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_OnRep_SlotSelectionModified_Statics::NewProp_Previous,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_OnRep_SlotSelectionModified_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_OnRep_SlotSelectionModified_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "OnRep_SlotSelectionModified", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_OnRep_SlotSelectionModified_Statics::TDRL_Character_eventOnRep_SlotSelectionModified_Parms), Z_Construct_UFunction_ATDRL_Character_OnRep_SlotSelectionModified_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_OnRep_SlotSelectionModified_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_OnRep_SlotSelectionModified_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_OnRep_SlotSelectionModified_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_OnRep_SlotSelectionModified()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_OnRep_SlotSelectionModified_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Statics
	{
		struct TDRL_Character_eventPerformPrimaryAction_Parms
		{
			bool Enable;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Enable_MetaData[];
#endif
		static void NewProp_Enable_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Enable;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Statics::NewProp_Enable_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Statics::NewProp_Enable_SetBit(void* Obj)
	{
		((TDRL_Character_eventPerformPrimaryAction_Parms*)Obj)->Enable = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Statics::NewProp_Enable = { "Enable", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(TDRL_Character_eventPerformPrimaryAction_Parms), &Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Statics::NewProp_Enable_SetBit, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Statics::NewProp_Enable_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Statics::NewProp_Enable_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Statics::NewProp_Enable,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Item" },
		{ "Comment", "/*Perform Primary Action on the Equipped Item*/" },
		{ "DisplayName", "PerformPrimaryAction" },
		{ "Keywords", "Perform Primary Action TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Perform Primary Action on the Equipped Item" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "PerformPrimaryAction", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Statics::TDRL_Character_eventPerformPrimaryAction_Parms), Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Func_Statics
	{
		struct TDRL_Character_eventPerformPrimaryAction_Func_Parms
		{
			bool Enable;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Enable_MetaData[];
#endif
		static void NewProp_Enable_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Enable;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Func_Statics::NewProp_Enable_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Func_Statics::NewProp_Enable_SetBit(void* Obj)
	{
		((TDRL_Character_eventPerformPrimaryAction_Func_Parms*)Obj)->Enable = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Func_Statics::NewProp_Enable = { "Enable", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(TDRL_Character_eventPerformPrimaryAction_Func_Parms), &Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Func_Statics::NewProp_Enable_SetBit, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Func_Statics::NewProp_Enable_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Func_Statics::NewProp_Enable_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Func_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Func_Statics::NewProp_Enable,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Func_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Func_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "PerformPrimaryAction_Func", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Func_Statics::TDRL_Character_eventPerformPrimaryAction_Func_Parms), Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Func_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Func_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Func_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Func_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Func()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Func_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Server_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Enable_MetaData[];
#endif
		static void NewProp_Enable_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Enable;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Server_Statics::NewProp_Enable_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Server_Statics::NewProp_Enable_SetBit(void* Obj)
	{
		((TDRL_Character_eventPerformPrimaryAction_Server_Parms*)Obj)->Enable = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Server_Statics::NewProp_Enable = { "Enable", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(TDRL_Character_eventPerformPrimaryAction_Server_Parms), &Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Server_Statics::NewProp_Enable_SetBit, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Server_Statics::NewProp_Enable_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Server_Statics::NewProp_Enable_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Server_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Server_Statics::NewProp_Enable,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Server_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Server_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "PerformPrimaryAction_Server", nullptr, nullptr, sizeof(TDRL_Character_eventPerformPrimaryAction_Server_Parms), Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Server_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Server_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Server_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Server_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Server()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Server_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_PerformRAction_Statics
	{
		struct TDRL_Character_eventPerformRAction_Parms
		{
			bool Enable;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Enable_MetaData[];
#endif
		static void NewProp_Enable_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Enable;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_PerformRAction_Statics::NewProp_Enable_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_ATDRL_Character_PerformRAction_Statics::NewProp_Enable_SetBit(void* Obj)
	{
		((TDRL_Character_eventPerformRAction_Parms*)Obj)->Enable = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATDRL_Character_PerformRAction_Statics::NewProp_Enable = { "Enable", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(TDRL_Character_eventPerformRAction_Parms), &Z_Construct_UFunction_ATDRL_Character_PerformRAction_Statics::NewProp_Enable_SetBit, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_PerformRAction_Statics::NewProp_Enable_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_PerformRAction_Statics::NewProp_Enable_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_PerformRAction_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_PerformRAction_Statics::NewProp_Enable,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_PerformRAction_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Item" },
		{ "Comment", "/*Perform R Action on the Equipped Item*/" },
		{ "DisplayName", "PerformRAction" },
		{ "Keywords", "Perform R Action TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Perform R Action on the Equipped Item" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_PerformRAction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "PerformRAction", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_PerformRAction_Statics::TDRL_Character_eventPerformRAction_Parms), Z_Construct_UFunction_ATDRL_Character_PerformRAction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_PerformRAction_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_PerformRAction_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_PerformRAction_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_PerformRAction()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_PerformRAction_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_PerformRAction_Func_Statics
	{
		struct TDRL_Character_eventPerformRAction_Func_Parms
		{
			bool Enable;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Enable_MetaData[];
#endif
		static void NewProp_Enable_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Enable;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_PerformRAction_Func_Statics::NewProp_Enable_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_ATDRL_Character_PerformRAction_Func_Statics::NewProp_Enable_SetBit(void* Obj)
	{
		((TDRL_Character_eventPerformRAction_Func_Parms*)Obj)->Enable = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATDRL_Character_PerformRAction_Func_Statics::NewProp_Enable = { "Enable", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(TDRL_Character_eventPerformRAction_Func_Parms), &Z_Construct_UFunction_ATDRL_Character_PerformRAction_Func_Statics::NewProp_Enable_SetBit, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_PerformRAction_Func_Statics::NewProp_Enable_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_PerformRAction_Func_Statics::NewProp_Enable_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_PerformRAction_Func_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_PerformRAction_Func_Statics::NewProp_Enable,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_PerformRAction_Func_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_PerformRAction_Func_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "PerformRAction_Func", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_PerformRAction_Func_Statics::TDRL_Character_eventPerformRAction_Func_Parms), Z_Construct_UFunction_ATDRL_Character_PerformRAction_Func_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_PerformRAction_Func_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_PerformRAction_Func_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_PerformRAction_Func_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_PerformRAction_Func()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_PerformRAction_Func_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_PerformRAction_Server_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Enable_MetaData[];
#endif
		static void NewProp_Enable_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Enable;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_PerformRAction_Server_Statics::NewProp_Enable_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_ATDRL_Character_PerformRAction_Server_Statics::NewProp_Enable_SetBit(void* Obj)
	{
		((TDRL_Character_eventPerformRAction_Server_Parms*)Obj)->Enable = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATDRL_Character_PerformRAction_Server_Statics::NewProp_Enable = { "Enable", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(TDRL_Character_eventPerformRAction_Server_Parms), &Z_Construct_UFunction_ATDRL_Character_PerformRAction_Server_Statics::NewProp_Enable_SetBit, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_PerformRAction_Server_Statics::NewProp_Enable_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_PerformRAction_Server_Statics::NewProp_Enable_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_PerformRAction_Server_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_PerformRAction_Server_Statics::NewProp_Enable,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_PerformRAction_Server_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_PerformRAction_Server_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "PerformRAction_Server", nullptr, nullptr, sizeof(TDRL_Character_eventPerformRAction_Server_Parms), Z_Construct_UFunction_ATDRL_Character_PerformRAction_Server_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_PerformRAction_Server_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_PerformRAction_Server_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_PerformRAction_Server_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_PerformRAction_Server()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_PerformRAction_Server_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Statics
	{
		struct TDRL_Character_eventPerformSecondaryAction_Parms
		{
			bool Enable;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Enable_MetaData[];
#endif
		static void NewProp_Enable_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Enable;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Statics::NewProp_Enable_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Statics::NewProp_Enable_SetBit(void* Obj)
	{
		((TDRL_Character_eventPerformSecondaryAction_Parms*)Obj)->Enable = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Statics::NewProp_Enable = { "Enable", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(TDRL_Character_eventPerformSecondaryAction_Parms), &Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Statics::NewProp_Enable_SetBit, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Statics::NewProp_Enable_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Statics::NewProp_Enable_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Statics::NewProp_Enable,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Item" },
		{ "Comment", "/*Perform Secondary Action on the Equipped Item*/" },
		{ "DisplayName", "PerformSecondaryAction" },
		{ "Keywords", "Perform Secondary Action TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Perform Secondary Action on the Equipped Item" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "PerformSecondaryAction", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Statics::TDRL_Character_eventPerformSecondaryAction_Parms), Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Func_Statics
	{
		struct TDRL_Character_eventPerformSecondaryAction_Func_Parms
		{
			bool Enable;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Enable_MetaData[];
#endif
		static void NewProp_Enable_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Enable;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Func_Statics::NewProp_Enable_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Func_Statics::NewProp_Enable_SetBit(void* Obj)
	{
		((TDRL_Character_eventPerformSecondaryAction_Func_Parms*)Obj)->Enable = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Func_Statics::NewProp_Enable = { "Enable", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(TDRL_Character_eventPerformSecondaryAction_Func_Parms), &Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Func_Statics::NewProp_Enable_SetBit, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Func_Statics::NewProp_Enable_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Func_Statics::NewProp_Enable_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Func_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Func_Statics::NewProp_Enable,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Func_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Func_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "PerformSecondaryAction_Func", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Func_Statics::TDRL_Character_eventPerformSecondaryAction_Func_Parms), Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Func_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Func_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Func_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Func_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Func()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Func_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Server_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Enable_MetaData[];
#endif
		static void NewProp_Enable_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Enable;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Server_Statics::NewProp_Enable_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Server_Statics::NewProp_Enable_SetBit(void* Obj)
	{
		((TDRL_Character_eventPerformSecondaryAction_Server_Parms*)Obj)->Enable = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Server_Statics::NewProp_Enable = { "Enable", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(TDRL_Character_eventPerformSecondaryAction_Server_Parms), &Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Server_Statics::NewProp_Enable_SetBit, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Server_Statics::NewProp_Enable_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Server_Statics::NewProp_Enable_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Server_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Server_Statics::NewProp_Enable,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Server_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Server_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "PerformSecondaryAction_Server", nullptr, nullptr, sizeof(TDRL_Character_eventPerformSecondaryAction_Server_Parms), Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Server_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Server_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Server_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Server_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Server()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Server_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_PickupItem_Statics
	{
		struct TDRL_Character_eventPickupItem_Parms
		{
			ATDRL_Item* Item;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Item;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATDRL_Character_PickupItem_Statics::NewProp_Item = { "Item", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventPickupItem_Parms, Item), Z_Construct_UClass_ATDRL_Item_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_PickupItem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_PickupItem_Statics::NewProp_Item,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_PickupItem_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Item" },
		{ "Comment", "/*Pickup nearest item*/" },
		{ "DisplayName", "PickupItem" },
		{ "Keywords", "Pickup Item TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Pickup nearest item" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_PickupItem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "PickupItem", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_PickupItem_Statics::TDRL_Character_eventPickupItem_Parms), Z_Construct_UFunction_ATDRL_Character_PickupItem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_PickupItem_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_PickupItem_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_PickupItem_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_PickupItem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_PickupItem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_PickupItem_Func_Statics
	{
		struct TDRL_Character_eventPickupItem_Func_Parms
		{
			ATDRL_Item* Item;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Item;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATDRL_Character_PickupItem_Func_Statics::NewProp_Item = { "Item", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventPickupItem_Func_Parms, Item), Z_Construct_UClass_ATDRL_Item_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_PickupItem_Func_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_PickupItem_Func_Statics::NewProp_Item,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_PickupItem_Func_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_PickupItem_Func_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "PickupItem_Func", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_PickupItem_Func_Statics::TDRL_Character_eventPickupItem_Func_Parms), Z_Construct_UFunction_ATDRL_Character_PickupItem_Func_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_PickupItem_Func_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_PickupItem_Func_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_PickupItem_Func_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_PickupItem_Func()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_PickupItem_Func_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_PickupItem_Server_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Item;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATDRL_Character_PickupItem_Server_Statics::NewProp_Item = { "Item", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventPickupItem_Server_Parms, Item), Z_Construct_UClass_ATDRL_Item_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_PickupItem_Server_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_PickupItem_Server_Statics::NewProp_Item,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_PickupItem_Server_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_PickupItem_Server_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "PickupItem_Server", nullptr, nullptr, sizeof(TDRL_Character_eventPickupItem_Server_Parms), Z_Construct_UFunction_ATDRL_Character_PickupItem_Server_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_PickupItem_Server_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_PickupItem_Server_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_PickupItem_Server_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_PickupItem_Server()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_PickupItem_Server_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_RemoveDynamicMaterialPostProcess_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_RemoveDynamicMaterialPostProcess_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_RemoveDynamicMaterialPostProcess_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "RemoveDynamicMaterialPostProcess", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_RemoveDynamicMaterialPostProcess_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_RemoveDynamicMaterialPostProcess_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_RemoveDynamicMaterialPostProcess()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_RemoveDynamicMaterialPostProcess_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Statics
	{
		struct TDRL_Character_eventSelectItemSlot_Parms
		{
			uint8 Slot;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Slot_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_Slot;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Statics::NewProp_Slot_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Statics::NewProp_Slot = { "Slot", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventSelectItemSlot_Parms, Slot), nullptr, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Statics::NewProp_Slot_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Statics::NewProp_Slot_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Statics::NewProp_Slot,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Inventory" },
		{ "Comment", "/*Select a specific item slot*/" },
		{ "DisplayName", "SelectItemSlot" },
		{ "Keywords", "Select Item Slot TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Select a specific item slot" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "SelectItemSlot", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Statics::TDRL_Character_eventSelectItemSlot_Parms), Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_SelectItemSlot()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Func_Statics
	{
		struct TDRL_Character_eventSelectItemSlot_Func_Parms
		{
			uint8 Slot;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Slot_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_Slot;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Func_Statics::NewProp_Slot_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Func_Statics::NewProp_Slot = { "Slot", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventSelectItemSlot_Func_Parms, Slot), nullptr, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Func_Statics::NewProp_Slot_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Func_Statics::NewProp_Slot_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Func_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Func_Statics::NewProp_Slot,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Func_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Func_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "SelectItemSlot_Func", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Func_Statics::TDRL_Character_eventSelectItemSlot_Func_Parms), Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Func_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Func_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Func_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Func_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Func()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Func_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Server_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Slot_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_Slot;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Server_Statics::NewProp_Slot_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Server_Statics::NewProp_Slot = { "Slot", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventSelectItemSlot_Server_Parms, Slot), nullptr, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Server_Statics::NewProp_Slot_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Server_Statics::NewProp_Slot_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Server_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Server_Statics::NewProp_Slot,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Server_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Server_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "SelectItemSlot_Server", nullptr, nullptr, sizeof(TDRL_Character_eventSelectItemSlot_Server_Parms), Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Server_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Server_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Server_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Server_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Server()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Server_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_SetAimOffsetValue_Statics
	{
		struct TDRL_Character_eventSetAimOffsetValue_Parms
		{
			FVector2D NewAimOffsetValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NewAimOffsetValue_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_NewAimOffsetValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_SetAimOffsetValue_Statics::NewProp_NewAimOffsetValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATDRL_Character_SetAimOffsetValue_Statics::NewProp_NewAimOffsetValue = { "NewAimOffsetValue", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventSetAimOffsetValue_Parms, NewAimOffsetValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_SetAimOffsetValue_Statics::NewProp_NewAimOffsetValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_SetAimOffsetValue_Statics::NewProp_NewAimOffsetValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_SetAimOffsetValue_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_SetAimOffsetValue_Statics::NewProp_NewAimOffsetValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_SetAimOffsetValue_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character" },
		{ "Comment", "/*Set the current AimOffset value for this character*/" },
		{ "DisplayName", "SetAimOffsetValue" },
		{ "Keywords", "Set Aim Offset Value TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Set the current AimOffset value for this character" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_SetAimOffsetValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "SetAimOffsetValue", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_SetAimOffsetValue_Statics::TDRL_Character_eventSetAimOffsetValue_Parms), Z_Construct_UFunction_ATDRL_Character_SetAimOffsetValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_SetAimOffsetValue_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_SetAimOffsetValue_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_SetAimOffsetValue_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_SetAimOffsetValue()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_SetAimOffsetValue_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_SetHealth_Statics
	{
		struct TDRL_Character_eventSetHealth_Parms
		{
			float Value;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Value;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_SetHealth_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ATDRL_Character_SetHealth_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventSetHealth_Parms, Value), METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_SetHealth_Statics::NewProp_Value_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_SetHealth_Statics::NewProp_Value_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_SetHealth_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_SetHealth_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_SetHealth_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Health" },
		{ "Comment", "/*Set health (Server Only)*/" },
		{ "DisplayName", "SetHealth" },
		{ "Keywords", "Set Health TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Set health (Server Only)" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_SetHealth_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "SetHealth", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_SetHealth_Statics::TDRL_Character_eventSetHealth_Parms), Z_Construct_UFunction_ATDRL_Character_SetHealth_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_SetHealth_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020404, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_SetHealth_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_SetHealth_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_SetHealth()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_SetHealth_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_SetInventorySlotsAmount_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Slots_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_Slots;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_SetInventorySlotsAmount_Statics::NewProp_Slots_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ATDRL_Character_SetInventorySlotsAmount_Statics::NewProp_Slots = { "Slots", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventSetInventorySlotsAmount_Parms, Slots), nullptr, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_SetInventorySlotsAmount_Statics::NewProp_Slots_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_SetInventorySlotsAmount_Statics::NewProp_Slots_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_SetInventorySlotsAmount_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_SetInventorySlotsAmount_Statics::NewProp_Slots,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_SetInventorySlotsAmount_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Inventory" },
		{ "Comment", "/*Set the current \"SelectedItemSlot\"*/" },
		{ "DisplayName", "SetInventorySlotsAmount" },
		{ "Keywords", "Set Inventory Slots Amount TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Set the current \"SelectedItemSlot\"" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_SetInventorySlotsAmount_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "SetInventorySlotsAmount", nullptr, nullptr, sizeof(TDRL_Character_eventSetInventorySlotsAmount_Parms), Z_Construct_UFunction_ATDRL_Character_SetInventorySlotsAmount_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_SetInventorySlotsAmount_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04220CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_SetInventorySlotsAmount_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_SetInventorySlotsAmount_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_SetInventorySlotsAmount()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_SetInventorySlotsAmount_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_SpawnDefaultWeapon_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_SpawnDefaultWeapon_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_SpawnDefaultWeapon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "SpawnDefaultWeapon", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_SpawnDefaultWeapon_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_SpawnDefaultWeapon_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_SpawnDefaultWeapon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_SpawnDefaultWeapon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_Stun_Statics
	{
		struct TDRL_Character_eventStun_Parms
		{
			FStunParameters StunParam;
			FVector Direction;
			FName Bone;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StunParam_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_StunParam;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Direction_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Direction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Bone_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_Bone;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Stun_Statics::NewProp_StunParam_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATDRL_Character_Stun_Statics::NewProp_StunParam = { "StunParam", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventStun_Parms, StunParam), Z_Construct_UScriptStruct_FStunParameters, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Stun_Statics::NewProp_StunParam_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Stun_Statics::NewProp_StunParam_MetaData)) }; // 1924132683
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Stun_Statics::NewProp_Direction_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATDRL_Character_Stun_Statics::NewProp_Direction = { "Direction", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventStun_Parms, Direction), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Stun_Statics::NewProp_Direction_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Stun_Statics::NewProp_Direction_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Stun_Statics::NewProp_Bone_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ATDRL_Character_Stun_Statics::NewProp_Bone = { "Bone", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventStun_Parms, Bone), METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Stun_Statics::NewProp_Bone_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Stun_Statics::NewProp_Bone_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_Stun_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_Stun_Statics::NewProp_StunParam,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_Stun_Statics::NewProp_Direction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_Stun_Statics::NewProp_Bone,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Stun_Statics::Function_MetaDataParams[] = {
		{ "Category", "TDRL|Character|Stun" },
		{ "Comment", "/*Apply stun status*/" },
		{ "DisplayName", "Stun" },
		{ "Keywords", "Apply Stun TDRL" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Apply stun status" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_Stun_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "Stun", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_Stun_Statics::TDRL_Character_eventStun_Parms), Z_Construct_UFunction_ATDRL_Character_Stun_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Stun_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Stun_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Stun_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_Stun()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_Stun_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_Stun_Func_Statics
	{
		struct TDRL_Character_eventStun_Func_Parms
		{
			FStunParameters StunParam;
			FVector Direction;
			FName Bone;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StunParam_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_StunParam;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Direction_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Direction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Bone_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_Bone;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Stun_Func_Statics::NewProp_StunParam_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATDRL_Character_Stun_Func_Statics::NewProp_StunParam = { "StunParam", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventStun_Func_Parms, StunParam), Z_Construct_UScriptStruct_FStunParameters, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Stun_Func_Statics::NewProp_StunParam_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Stun_Func_Statics::NewProp_StunParam_MetaData)) }; // 1924132683
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Stun_Func_Statics::NewProp_Direction_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATDRL_Character_Stun_Func_Statics::NewProp_Direction = { "Direction", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventStun_Func_Parms, Direction), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Stun_Func_Statics::NewProp_Direction_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Stun_Func_Statics::NewProp_Direction_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Stun_Func_Statics::NewProp_Bone_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ATDRL_Character_Stun_Func_Statics::NewProp_Bone = { "Bone", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventStun_Func_Parms, Bone), METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Stun_Func_Statics::NewProp_Bone_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Stun_Func_Statics::NewProp_Bone_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_Stun_Func_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_Stun_Func_Statics::NewProp_StunParam,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_Stun_Func_Statics::NewProp_Direction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_Stun_Func_Statics::NewProp_Bone,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Stun_Func_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_Stun_Func_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "Stun_Func", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_Stun_Func_Statics::TDRL_Character_eventStun_Func_Parms), Z_Construct_UFunction_ATDRL_Character_Stun_Func_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Stun_Func_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00820400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Stun_Func_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Stun_Func_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_Stun_Func()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_Stun_Func_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_Stun_Server_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StunParam_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_StunParam;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Direction_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Direction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Bone_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_Bone;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Stun_Server_Statics::NewProp_StunParam_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATDRL_Character_Stun_Server_Statics::NewProp_StunParam = { "StunParam", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventStun_Server_Parms, StunParam), Z_Construct_UScriptStruct_FStunParameters, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Stun_Server_Statics::NewProp_StunParam_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Stun_Server_Statics::NewProp_StunParam_MetaData)) }; // 1924132683
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Stun_Server_Statics::NewProp_Direction_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATDRL_Character_Stun_Server_Statics::NewProp_Direction = { "Direction", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventStun_Server_Parms, Direction), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Stun_Server_Statics::NewProp_Direction_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Stun_Server_Statics::NewProp_Direction_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Stun_Server_Statics::NewProp_Bone_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ATDRL_Character_Stun_Server_Statics::NewProp_Bone = { "Bone", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventStun_Server_Parms, Bone), METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Stun_Server_Statics::NewProp_Bone_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Stun_Server_Statics::NewProp_Bone_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_Stun_Server_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_Stun_Server_Statics::NewProp_StunParam,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_Stun_Server_Statics::NewProp_Direction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_Stun_Server_Statics::NewProp_Bone,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_Stun_Server_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_Stun_Server_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "Stun_Server", nullptr, nullptr, sizeof(TDRL_Character_eventStun_Server_Parms), Z_Construct_UFunction_ATDRL_Character_Stun_Server_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Stun_Server_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00A20CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_Stun_Server_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_Stun_Server_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_Stun_Server()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_Stun_Server_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_TickCameraOcclusionTrace_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_TickCameraOcclusionTrace_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_TickCameraOcclusionTrace_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "TickCameraOcclusionTrace", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_TickCameraOcclusionTrace_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_TickCameraOcclusionTrace_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_TickCameraOcclusionTrace()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_TickCameraOcclusionTrace_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_TickCameraOrientation_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_TickCameraOrientation_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_TickCameraOrientation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "TickCameraOrientation", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_TickCameraOrientation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_TickCameraOrientation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_TickCameraOrientation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_TickCameraOrientation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_TraceForCameraOcclusion_Statics
	{
		struct TDRL_Character_eventTraceForCameraOcclusion_Parms
		{
			FVector InStart;
			FVector InEnd;
			FRotator InOrientation;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InStart_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_InStart;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InEnd_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_InEnd;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InOrientation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_InOrientation;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_TraceForCameraOcclusion_Statics::NewProp_InStart_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATDRL_Character_TraceForCameraOcclusion_Statics::NewProp_InStart = { "InStart", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventTraceForCameraOcclusion_Parms, InStart), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_TraceForCameraOcclusion_Statics::NewProp_InStart_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_TraceForCameraOcclusion_Statics::NewProp_InStart_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_TraceForCameraOcclusion_Statics::NewProp_InEnd_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATDRL_Character_TraceForCameraOcclusion_Statics::NewProp_InEnd = { "InEnd", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventTraceForCameraOcclusion_Parms, InEnd), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_TraceForCameraOcclusion_Statics::NewProp_InEnd_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_TraceForCameraOcclusion_Statics::NewProp_InEnd_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_TraceForCameraOcclusion_Statics::NewProp_InOrientation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATDRL_Character_TraceForCameraOcclusion_Statics::NewProp_InOrientation = { "InOrientation", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventTraceForCameraOcclusion_Parms, InOrientation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_TraceForCameraOcclusion_Statics::NewProp_InOrientation_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_TraceForCameraOcclusion_Statics::NewProp_InOrientation_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_TraceForCameraOcclusion_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_TraceForCameraOcclusion_Statics::NewProp_InStart,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_TraceForCameraOcclusion_Statics::NewProp_InEnd,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_TraceForCameraOcclusion_Statics::NewProp_InOrientation,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_TraceForCameraOcclusion_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_TraceForCameraOcclusion_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "TraceForCameraOcclusion", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_TraceForCameraOcclusion_Statics::TDRL_Character_eventTraceForCameraOcclusion_Parms), Z_Construct_UFunction_ATDRL_Character_TraceForCameraOcclusion_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_TraceForCameraOcclusion_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00820400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_TraceForCameraOcclusion_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_TraceForCameraOcclusion_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_TraceForCameraOcclusion()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_TraceForCameraOcclusion_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_TraceForNearbyItems_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_TraceForNearbyItems_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_TraceForNearbyItems_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "TraceForNearbyItems", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_TraceForNearbyItems_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_TraceForNearbyItems_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_TraceForNearbyItems()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_TraceForNearbyItems_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATDRL_Character_TraceForPostProcessOcclusion_Statics
	{
		struct TDRL_Character_eventTraceForPostProcessOcclusion_Parms
		{
			FVector InStart;
			FVector InEnd;
			FRotator InOrientation;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InStart_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_InStart;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InEnd_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_InEnd;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InOrientation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_InOrientation;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_TraceForPostProcessOcclusion_Statics::NewProp_InStart_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATDRL_Character_TraceForPostProcessOcclusion_Statics::NewProp_InStart = { "InStart", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventTraceForPostProcessOcclusion_Parms, InStart), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_TraceForPostProcessOcclusion_Statics::NewProp_InStart_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_TraceForPostProcessOcclusion_Statics::NewProp_InStart_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_TraceForPostProcessOcclusion_Statics::NewProp_InEnd_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATDRL_Character_TraceForPostProcessOcclusion_Statics::NewProp_InEnd = { "InEnd", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventTraceForPostProcessOcclusion_Parms, InEnd), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_TraceForPostProcessOcclusion_Statics::NewProp_InEnd_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_TraceForPostProcessOcclusion_Statics::NewProp_InEnd_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_TraceForPostProcessOcclusion_Statics::NewProp_InOrientation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATDRL_Character_TraceForPostProcessOcclusion_Statics::NewProp_InOrientation = { "InOrientation", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(TDRL_Character_eventTraceForPostProcessOcclusion_Parms, InOrientation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_TraceForPostProcessOcclusion_Statics::NewProp_InOrientation_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_TraceForPostProcessOcclusion_Statics::NewProp_InOrientation_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATDRL_Character_TraceForPostProcessOcclusion_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_TraceForPostProcessOcclusion_Statics::NewProp_InStart,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_TraceForPostProcessOcclusion_Statics::NewProp_InEnd,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATDRL_Character_TraceForPostProcessOcclusion_Statics::NewProp_InOrientation,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATDRL_Character_TraceForPostProcessOcclusion_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATDRL_Character_TraceForPostProcessOcclusion_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATDRL_Character, nullptr, "TraceForPostProcessOcclusion", nullptr, nullptr, sizeof(Z_Construct_UFunction_ATDRL_Character_TraceForPostProcessOcclusion_Statics::TDRL_Character_eventTraceForPostProcessOcclusion_Parms), Z_Construct_UFunction_ATDRL_Character_TraceForPostProcessOcclusion_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_TraceForPostProcessOcclusion_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00820400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATDRL_Character_TraceForPostProcessOcclusion_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATDRL_Character_TraceForPostProcessOcclusion_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATDRL_Character_TraceForPostProcessOcclusion()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATDRL_Character_TraceForPostProcessOcclusion_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATDRL_Character);
	UClass* Z_Construct_UClass_ATDRL_Character_NoRegister()
	{
		return ATDRL_Character::StaticClass();
	}
	struct Z_Construct_UClass_ATDRL_Character_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GlobalPostProcess_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_GlobalPostProcess;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PostProcessInUse_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PostProcessInUse;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultAttributeEffect_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_DefaultAttributeEffect;
		static const UECodeGen_Private::FClassPropertyParams NewProp_DefaultAbilities_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultAbilities_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_DefaultAbilities;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxHealth_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxHealth;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Health_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Health;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OcclusionParam_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_OcclusionParam;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraOccludingComponents_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraOccludingComponents_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_CameraOccludingComponents;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AimOffsetValue_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_AimOffsetValue;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraSpringArm_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraSpringArm;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Camera;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SightComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SightComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AbilityComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_AbilityComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AttributeSet_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_AttributeSet;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InitialInventorySlots_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_InitialInventorySlots;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultWeaponClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_DefaultWeaponClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MainWeapon_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MainWeapon;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SelectedItemSlot_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_SelectedItemSlot;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Inventory_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Inventory_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Inventory;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ItemTraceRadius_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ItemTraceRadius;
		static const UECodeGen_Private::FBytePropertyParams NewProp_TraceForItemsChannels_ElementProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TraceForItemsChannels_MetaData[];
#endif
		static const UECodeGen_Private::FSetPropertyParams NewProp_TraceForItemsChannels;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NearestNearbyItemIndex_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_NearestNearbyItemIndex;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_NearbyItems_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NearbyItems_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_NearbyItems;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bDebugShowTraceForItems_MetaData[];
#endif
		static void NewProp_bDebugShowTraceForItems_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDebugShowTraceForItems;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TraceItemTimerHandle_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_TraceItemTimerHandle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultDamageKnockback_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_DefaultDamageKnockback;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultKnockbackMontages_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultKnockbackMontages_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_DefaultKnockbackMontages;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentStun_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentStun;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StunTimerHandle_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_StunTimerHandle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnDeath_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnDeath;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DeathInfo_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_DeathInfo;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATDRL_Character_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_TopDownRogueLite,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ATDRL_Character_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ATDRL_Character_ApplyDefaultKnockback, "ApplyDefaultKnockback" }, // 2687994716
		{ &Z_Construct_UFunction_ATDRL_Character_ApplyDynamicMaterialPostProcess, "ApplyDynamicMaterialPostProcess" }, // 2338585825
		{ &Z_Construct_UFunction_ATDRL_Character_CharacterDeath, "CharacterDeath" }, // 3792052906
		{ &Z_Construct_UFunction_ATDRL_Character_ClearStun, "ClearStun" }, // 1354118412
		{ &Z_Construct_UFunction_ATDRL_Character_ClearStun_Func, "ClearStun_Func" }, // 1880749445
		{ &Z_Construct_UFunction_ATDRL_Character_ClearStun_Server, "ClearStun_Server" }, // 3473243501
		{ &Z_Construct_UFunction_ATDRL_Character_Dash, "Dash" }, // 3655968291
		{ &Z_Construct_UFunction_ATDRL_Character_Death, "Death" }, // 1405813529
		{ &Z_Construct_UFunction_ATDRL_Character_DestroyAllItems, "DestroyAllItems" }, // 2432018838
		{ &Z_Construct_UFunction_ATDRL_Character_DestroyDefaultWeapon, "DestroyDefaultWeapon" }, // 3965852891
		{ &Z_Construct_UFunction_ATDRL_Character_DropAllItems, "DropAllItems" }, // 3751689845
		{ &Z_Construct_UFunction_ATDRL_Character_DropEquippedItem, "DropEquippedItem" }, // 2797164750
		{ &Z_Construct_UFunction_ATDRL_Character_DropItem, "DropItem" }, // 776414226
		{ &Z_Construct_UFunction_ATDRL_Character_DropItem_Func, "DropItem_Func" }, // 3466020555
		{ &Z_Construct_UFunction_ATDRL_Character_DropItem_Server, "DropItem_Server" }, // 4278774791
		{ &Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems, "EnableTraceForNearbyItems" }, // 1491137133
		{ &Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Func, "EnableTraceForNearbyItems_Func" }, // 4270575655
		{ &Z_Construct_UFunction_ATDRL_Character_EnableTraceForNearbyItems_Server, "EnableTraceForNearbyItems_Server" }, // 1487012792
		{ &Z_Construct_UFunction_ATDRL_Character_GetAbilityComponent, "GetAbilityComponent" }, // 2098986845
		{ &Z_Construct_UFunction_ATDRL_Character_GetCamera, "GetCamera" }, // 2207470606
		{ &Z_Construct_UFunction_ATDRL_Character_GetCameraSpringArm, "GetCameraSpringArm" }, // 687123300
		{ &Z_Construct_UFunction_ATDRL_Character_GetDeathInfo, "GetDeathInfo" }, // 3137027613
		{ &Z_Construct_UFunction_ATDRL_Character_GetEquippedItem, "GetEquippedItem" }, // 2980313085
		{ &Z_Construct_UFunction_ATDRL_Character_GetHealthPercentage, "GetHealthPercentage" }, // 3606631470
		{ &Z_Construct_UFunction_ATDRL_Character_GetHigestRarityItemSlot, "GetHigestRarityItemSlot" }, // 337977789
		{ &Z_Construct_UFunction_ATDRL_Character_GetIsDead, "GetIsDead" }, // 3146699817
		{ &Z_Construct_UFunction_ATDRL_Character_GetItemByClass, "GetItemByClass" }, // 796502837
		{ &Z_Construct_UFunction_ATDRL_Character_GetLowestRarityItemSlot, "GetLowestRarityItemSlot" }, // 1704635919
		{ &Z_Construct_UFunction_ATDRL_Character_GetNearestNearbyItem, "GetNearestNearbyItem" }, // 845522622
		{ &Z_Construct_UFunction_ATDRL_Character_GetNPCController, "GetNPCController" }, // 768718958
		{ &Z_Construct_UFunction_ATDRL_Character_GetSightComponent, "GetSightComponent" }, // 1500784674
		{ &Z_Construct_UFunction_ATDRL_Character_GetSlotsOccupiedByItemClass, "GetSlotsOccupiedByItemClass" }, // 1299125889
		{ &Z_Construct_UFunction_ATDRL_Character_GetStunValue, "GetStunValue" }, // 1634590616
		{ &Z_Construct_UFunction_ATDRL_Character_GetTDRLMovementComponent, "GetTDRLMovementComponent" }, // 912447254
		{ &Z_Construct_UFunction_ATDRL_Character_GiveInitialAbilities, "GiveInitialAbilities" }, // 350587906
		{ &Z_Construct_UFunction_ATDRL_Character_HasItemOfClass, "HasItemOfClass" }, // 273214573
		{ &Z_Construct_UFunction_ATDRL_Character_HasNearbyItems, "HasNearbyItems" }, // 4148421204
		{ &Z_Construct_UFunction_ATDRL_Character_Heal, "Heal" }, // 2402488913
		{ &Z_Construct_UFunction_ATDRL_Character_Heal_Effects, "Heal_Effects" }, // 506161273
		{ &Z_Construct_UFunction_ATDRL_Character_InitializeDefaultAttributeValues, "InitializeDefaultAttributeValues" }, // 1901833985
		{ &Z_Construct_UFunction_ATDRL_Character_Input_AlternativeWalk, "Input_AlternativeWalk" }, // 2049067129
		{ &Z_Construct_UFunction_ATDRL_Character_Input_ChangeItemSlot, "Input_ChangeItemSlot" }, // 2830412443
		{ &Z_Construct_UFunction_ATDRL_Character_Input_Crouch, "Input_Crouch" }, // 3197677906
		{ &Z_Construct_UFunction_ATDRL_Character_Input_Dash, "Input_Dash" }, // 1960407393
		{ &Z_Construct_UFunction_ATDRL_Character_Input_Drop, "Input_Drop" }, // 945875689
		{ &Z_Construct_UFunction_ATDRL_Character_Input_Jump, "Input_Jump" }, // 129295477
		{ &Z_Construct_UFunction_ATDRL_Character_Input_LockTarget, "Input_LockTarget" }, // 1561874298
		{ &Z_Construct_UFunction_ATDRL_Character_Input_Move, "Input_Move" }, // 2683090471
		{ &Z_Construct_UFunction_ATDRL_Character_Input_Pickup, "Input_Pickup" }, // 3902338407
		{ &Z_Construct_UFunction_ATDRL_Character_Input_PitchAim, "Input_PitchAim" }, // 4095202492
		{ &Z_Construct_UFunction_ATDRL_Character_Input_PrimaryAction, "Input_PrimaryAction" }, // 1800229829
		{ &Z_Construct_UFunction_ATDRL_Character_Input_RAction, "Input_RAction" }, // 3706834174
		{ &Z_Construct_UFunction_ATDRL_Character_Input_RotateCamera, "Input_RotateCamera" }, // 2128640492
		{ &Z_Construct_UFunction_ATDRL_Character_Input_SecondaryAction, "Input_SecondaryAction" }, // 3913402483
		{ &Z_Construct_UFunction_ATDRL_Character_IsDashing, "IsDashing" }, // 3056972009
		{ &Z_Construct_UFunction_ATDRL_Character_IsStunned, "IsStunned" }, // 3263430209
		{ &Z_Construct_UFunction_ATDRL_Character_OnRep_CurrentStun, "OnRep_CurrentStun" }, // 638701950
		{ &Z_Construct_UFunction_ATDRL_Character_OnRep_DeathInfo, "OnRep_DeathInfo" }, // 3405490722
		{ &Z_Construct_UFunction_ATDRL_Character_OnRep_HealthModified, "OnRep_HealthModified" }, // 3113419446
		{ &Z_Construct_UFunction_ATDRL_Character_OnRep_InventoryModified, "OnRep_InventoryModified" }, // 2663233054
		{ &Z_Construct_UFunction_ATDRL_Character_OnRep_MainWeaponModified, "OnRep_MainWeaponModified" }, // 3145661024
		{ &Z_Construct_UFunction_ATDRL_Character_OnRep_SlotSelectionModified, "OnRep_SlotSelectionModified" }, // 3346348736
		{ &Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction, "PerformPrimaryAction" }, // 3023384038
		{ &Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Func, "PerformPrimaryAction_Func" }, // 318367469
		{ &Z_Construct_UFunction_ATDRL_Character_PerformPrimaryAction_Server, "PerformPrimaryAction_Server" }, // 3022306472
		{ &Z_Construct_UFunction_ATDRL_Character_PerformRAction, "PerformRAction" }, // 3445266306
		{ &Z_Construct_UFunction_ATDRL_Character_PerformRAction_Func, "PerformRAction_Func" }, // 2512155447
		{ &Z_Construct_UFunction_ATDRL_Character_PerformRAction_Server, "PerformRAction_Server" }, // 2300139793
		{ &Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction, "PerformSecondaryAction" }, // 3542073711
		{ &Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Func, "PerformSecondaryAction_Func" }, // 1375431283
		{ &Z_Construct_UFunction_ATDRL_Character_PerformSecondaryAction_Server, "PerformSecondaryAction_Server" }, // 30540085
		{ &Z_Construct_UFunction_ATDRL_Character_PickupItem, "PickupItem" }, // 3649730293
		{ &Z_Construct_UFunction_ATDRL_Character_PickupItem_Func, "PickupItem_Func" }, // 177593470
		{ &Z_Construct_UFunction_ATDRL_Character_PickupItem_Server, "PickupItem_Server" }, // 2594773886
		{ &Z_Construct_UFunction_ATDRL_Character_RemoveDynamicMaterialPostProcess, "RemoveDynamicMaterialPostProcess" }, // 3374003854
		{ &Z_Construct_UFunction_ATDRL_Character_SelectItemSlot, "SelectItemSlot" }, // 456559979
		{ &Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Func, "SelectItemSlot_Func" }, // 2552124493
		{ &Z_Construct_UFunction_ATDRL_Character_SelectItemSlot_Server, "SelectItemSlot_Server" }, // 3946789020
		{ &Z_Construct_UFunction_ATDRL_Character_SetAimOffsetValue, "SetAimOffsetValue" }, // 1255706660
		{ &Z_Construct_UFunction_ATDRL_Character_SetHealth, "SetHealth" }, // 602590359
		{ &Z_Construct_UFunction_ATDRL_Character_SetInventorySlotsAmount, "SetInventorySlotsAmount" }, // 334274054
		{ &Z_Construct_UFunction_ATDRL_Character_SpawnDefaultWeapon, "SpawnDefaultWeapon" }, // 172061148
		{ &Z_Construct_UFunction_ATDRL_Character_Stun, "Stun" }, // 3647258601
		{ &Z_Construct_UFunction_ATDRL_Character_Stun_Func, "Stun_Func" }, // 1443492209
		{ &Z_Construct_UFunction_ATDRL_Character_Stun_Server, "Stun_Server" }, // 901295178
		{ &Z_Construct_UFunction_ATDRL_Character_TickCameraOcclusionTrace, "TickCameraOcclusionTrace" }, // 2473367935
		{ &Z_Construct_UFunction_ATDRL_Character_TickCameraOrientation, "TickCameraOrientation" }, // 3804966987
		{ &Z_Construct_UFunction_ATDRL_Character_TraceForCameraOcclusion, "TraceForCameraOcclusion" }, // 2097875894
		{ &Z_Construct_UFunction_ATDRL_Character_TraceForNearbyItems, "TraceForNearbyItems" }, // 37093918
		{ &Z_Construct_UFunction_ATDRL_Character_TraceForPostProcessOcclusion, "TraceForPostProcessOcclusion" }, // 2110760490
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_Character_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Player/TDRL_Character.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_Character_Statics::NewProp_GlobalPostProcess_MetaData[] = {
		{ "Category", "TDRL|Character|PostProcess" },
		{ "Comment", "/*Global post process. This material instance must follow the example material asset structure.*/" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Global post process. This material instance must follow the example material asset structure." },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_GlobalPostProcess = { "GlobalPostProcess", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATDRL_Character, GlobalPostProcess), Z_Construct_UClass_UMaterialInstance_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_GlobalPostProcess_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_GlobalPostProcess_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_Character_Statics::NewProp_PostProcessInUse_MetaData[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_PostProcessInUse = { "PostProcessInUse", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATDRL_Character, PostProcessInUse), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_PostProcessInUse_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_PostProcessInUse_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_Character_Statics::NewProp_DefaultAttributeEffect_MetaData[] = {
		{ "Category", "TDRL|Character|Abilities" },
		{ "Comment", "/*Default Attribute Effect to apply when spawned*/" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Default Attribute Effect to apply when spawned" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_DefaultAttributeEffect = { "DefaultAttributeEffect", nullptr, (EPropertyFlags)0x0014000000010015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATDRL_Character, DefaultAttributeEffect), Z_Construct_UClass_UClass, Z_Construct_UClass_UGameplayEffect_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_DefaultAttributeEffect_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_DefaultAttributeEffect_MetaData)) };
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_DefaultAbilities_Inner = { "DefaultAbilities", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UClass_UClass, Z_Construct_UClass_UTDRL_GASGameplayAbility_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_Character_Statics::NewProp_DefaultAbilities_MetaData[] = {
		{ "Category", "TDRL|Character|Abilities" },
		{ "Comment", "/*List of default abilities to add when spawned*/" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "List of default abilities to add when spawned" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_DefaultAbilities = { "DefaultAbilities", nullptr, (EPropertyFlags)0x0014000000010015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATDRL_Character, DefaultAbilities), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_DefaultAbilities_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_DefaultAbilities_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_Character_Statics::NewProp_MaxHealth_MetaData[] = {
		{ "Category", "TDRL|Character|Health" },
		{ "Comment", "/*Max Character's health*/" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Max Character's health" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_MaxHealth = { "MaxHealth", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATDRL_Character, MaxHealth), METADATA_PARAMS(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_MaxHealth_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_MaxHealth_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_Character_Statics::NewProp_Health_MetaData[] = {
		{ "Category", "TDRL|Character|Health|Runtime" },
		{ "Comment", "/*Current Character's health*/" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Current Character's health" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_Health = { "Health", "OnRep_HealthModified", (EPropertyFlags)0x0010000100000034, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATDRL_Character, Health), METADATA_PARAMS(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_Health_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_Health_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_Character_Statics::NewProp_OcclusionParam_MetaData[] = {
		{ "Category", "TDRL|Character|TraceOcclusion" },
		{ "Comment", "/*Player's camera occlusion parameters*/" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Player's camera occlusion parameters" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_OcclusionParam = { "OcclusionParam", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATDRL_Character, OcclusionParam), Z_Construct_UScriptStruct_FCameraTraceOcclusionParams, METADATA_PARAMS(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_OcclusionParam_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_OcclusionParam_MetaData)) }; // 1244550909
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_CameraOccludingComponents_Inner = { "CameraOccludingComponents", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UClass_UTDRL_CameraOcclusionComponent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_Character_Statics::NewProp_CameraOccludingComponents_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_CameraOccludingComponents = { "CameraOccludingComponents", nullptr, (EPropertyFlags)0x0020088000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATDRL_Character, CameraOccludingComponents), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_CameraOccludingComponents_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_CameraOccludingComponents_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_Character_Statics::NewProp_AimOffsetValue_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "TDRL|Character" },
		{ "Comment", "/*Aim Offset value to apply*/" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Aim Offset value to apply" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_AimOffsetValue = { "AimOffsetValue", nullptr, (EPropertyFlags)0x0010000000000034, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATDRL_Character, AimOffsetValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_AimOffsetValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_AimOffsetValue_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_Character_Statics::NewProp_CameraSpringArm_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_CameraSpringArm = { "CameraSpringArm", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATDRL_Character, CameraSpringArm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_CameraSpringArm_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_CameraSpringArm_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_Character_Statics::NewProp_Camera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_Camera = { "Camera", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATDRL_Character, Camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_Camera_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_Camera_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_Character_Statics::NewProp_SightComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_SightComponent = { "SightComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATDRL_Character, SightComponent), Z_Construct_UClass_UTDRL_LineOfSightComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_SightComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_SightComponent_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_Character_Statics::NewProp_AbilityComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_AbilityComponent = { "AbilityComponent", nullptr, (EPropertyFlags)0x00240800000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATDRL_Character, AbilityComponent), Z_Construct_UClass_UAbilitySystemComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_AbilityComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_AbilityComponent_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_Character_Statics::NewProp_AttributeSet_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_AttributeSet = { "AttributeSet", nullptr, (EPropertyFlags)0x0024080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATDRL_Character, AttributeSet), Z_Construct_UClass_UTDRL_GASAttributeSet_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_AttributeSet_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_AttributeSet_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_Character_Statics::NewProp_InitialInventorySlots_MetaData[] = {
		{ "Category", "TDRL|Character|Inventory" },
		{ "Comment", "/*Amount of initial inventory slots. Does not affect runtime gameplay.*/" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Amount of initial inventory slots. Does not affect runtime gameplay." },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_InitialInventorySlots = { "InitialInventorySlots", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATDRL_Character, InitialInventorySlots), nullptr, METADATA_PARAMS(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_InitialInventorySlots_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_InitialInventorySlots_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_Character_Statics::NewProp_DefaultWeaponClass_MetaData[] = {
		{ "Category", "TDRL|Character|Inventory" },
		{ "Comment", "/*Default weapon class*/" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Default weapon class" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_DefaultWeaponClass = { "DefaultWeaponClass", nullptr, (EPropertyFlags)0x0014000000010015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATDRL_Character, DefaultWeaponClass), Z_Construct_UClass_UClass, Z_Construct_UClass_ATDRL_Melee_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_DefaultWeaponClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_DefaultWeaponClass_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_Character_Statics::NewProp_MainWeapon_MetaData[] = {
		{ "Category", "TDRL|Character|Inventory|Runtime" },
		{ "Comment", "/*Default weapon pointer (once spawned and assigned)*/" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Default weapon pointer (once spawned and assigned)" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_MainWeapon = { "MainWeapon", "OnRep_MainWeaponModified", (EPropertyFlags)0x0010000100000034, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATDRL_Character, MainWeapon), Z_Construct_UClass_ATDRL_Melee_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_MainWeapon_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_MainWeapon_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_Character_Statics::NewProp_SelectedItemSlot_MetaData[] = {
		{ "Category", "TDRL|Character|Inventory|Runtime" },
		{ "Comment", "/*Current selected slot*/" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Current selected slot" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_SelectedItemSlot = { "SelectedItemSlot", "OnRep_SlotSelectionModified", (EPropertyFlags)0x0010000100000034, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATDRL_Character, SelectedItemSlot), nullptr, METADATA_PARAMS(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_SelectedItemSlot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_SelectedItemSlot_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_Inventory_Inner = { "Inventory", nullptr, (EPropertyFlags)0x0000000000020000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UClass_ATDRL_Item_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_Character_Statics::NewProp_Inventory_MetaData[] = {
		{ "Category", "TDRL|Character|Inventory|Runtime" },
		{ "Comment", "/*Item inventory*/" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Item inventory" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_Inventory = { "Inventory", "OnRep_InventoryModified", (EPropertyFlags)0x0010000100030035, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATDRL_Character, Inventory), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_Inventory_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_Inventory_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_Character_Statics::NewProp_ItemTraceRadius_MetaData[] = {
		{ "Category", "TDRL|Character|Inventory" },
		{ "Comment", "/*Reachable radius when looking for interactable items*/" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Reachable radius when looking for interactable items" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_ItemTraceRadius = { "ItemTraceRadius", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATDRL_Character, ItemTraceRadius), METADATA_PARAMS(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_ItemTraceRadius_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_ItemTraceRadius_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_TraceForItemsChannels_ElementProp = { "TraceForItemsChannels", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UEnum_Engine_EObjectTypeQuery, METADATA_PARAMS(nullptr, 0) }; // 3629342158
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_Character_Statics::NewProp_TraceForItemsChannels_MetaData[] = {
		{ "Category", "TDRL|Character|Inventory" },
		{ "Comment", "/*Channels to trace for Items*/" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Channels to trace for Items" },
	};
#endif
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_TraceForItemsChannels = { "TraceForItemsChannels", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATDRL_Character, TraceForItemsChannels), METADATA_PARAMS(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_TraceForItemsChannels_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_TraceForItemsChannels_MetaData)) }; // 3629342158
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_Character_Statics::NewProp_NearestNearbyItemIndex_MetaData[] = {
		{ "Category", "TDRL|Character|Inventory|Runtime" },
		{ "Comment", "/*Nearest nearby index of \"NearbyItems\"*/" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Nearest nearby index of \"NearbyItems\"" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_NearestNearbyItemIndex = { "NearestNearbyItemIndex", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATDRL_Character, NearestNearbyItemIndex), nullptr, METADATA_PARAMS(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_NearestNearbyItemIndex_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_NearestNearbyItemIndex_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_NearbyItems_Inner = { "NearbyItems", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UClass_ATDRL_Item_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_Character_Statics::NewProp_NearbyItems_MetaData[] = {
		{ "Category", "TDRL|Character|Inventory|Runtime" },
		{ "Comment", "/*List of traced Nearby Items*/" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "List of traced Nearby Items" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_NearbyItems = { "NearbyItems", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATDRL_Character, NearbyItems), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_NearbyItems_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_NearbyItems_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_Character_Statics::NewProp_bDebugShowTraceForItems_MetaData[] = {
		{ "Category", "TDRL|Character|Inventory|Debug" },
		{ "Comment", "/*Show interaction Debug*/" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Show interaction Debug" },
	};
#endif
	void Z_Construct_UClass_ATDRL_Character_Statics::NewProp_bDebugShowTraceForItems_SetBit(void* Obj)
	{
		((ATDRL_Character*)Obj)->bDebugShowTraceForItems = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_bDebugShowTraceForItems = { "bDebugShowTraceForItems", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(uint8), sizeof(ATDRL_Character), &Z_Construct_UClass_ATDRL_Character_Statics::NewProp_bDebugShowTraceForItems_SetBit, METADATA_PARAMS(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_bDebugShowTraceForItems_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_bDebugShowTraceForItems_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_Character_Statics::NewProp_TraceItemTimerHandle_MetaData[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_TraceItemTimerHandle = { "TraceItemTimerHandle", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATDRL_Character, TraceItemTimerHandle), Z_Construct_UScriptStruct_FTimerHandle, METADATA_PARAMS(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_TraceItemTimerHandle_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_TraceItemTimerHandle_MetaData)) }; // 3633724737
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_Character_Statics::NewProp_DefaultDamageKnockback_MetaData[] = {
		{ "Category", "TDRL|Character|Stun" },
		{ "Comment", "/*Default Stun parameters for Knockback when getting normal damage*/" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Default Stun parameters for Knockback when getting normal damage" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_DefaultDamageKnockback = { "DefaultDamageKnockback", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATDRL_Character, DefaultDamageKnockback), Z_Construct_UScriptStruct_FStunParameters, METADATA_PARAMS(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_DefaultDamageKnockback_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_DefaultDamageKnockback_MetaData)) }; // 1924132683
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_DefaultKnockbackMontages_Inner = { "DefaultKnockbackMontages", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_Character_Statics::NewProp_DefaultKnockbackMontages_MetaData[] = {
		{ "Category", "TDRL|Character|Stun" },
		{ "Comment", "/*List of AnimMontage to use when the Knockbabk happen*/" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "List of AnimMontage to use when the Knockbabk happen" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_DefaultKnockbackMontages = { "DefaultKnockbackMontages", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATDRL_Character, DefaultKnockbackMontages), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_DefaultKnockbackMontages_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_DefaultKnockbackMontages_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_Character_Statics::NewProp_CurrentStun_MetaData[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_CurrentStun = { "CurrentStun", "OnRep_CurrentStun", (EPropertyFlags)0x0010000100000020, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATDRL_Character, CurrentStun), Z_Construct_UScriptStruct_FStunParameters, METADATA_PARAMS(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_CurrentStun_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_CurrentStun_MetaData)) }; // 1924132683
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_Character_Statics::NewProp_StunTimerHandle_MetaData[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_StunTimerHandle = { "StunTimerHandle", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATDRL_Character, StunTimerHandle), Z_Construct_UScriptStruct_FTimerHandle, METADATA_PARAMS(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_StunTimerHandle_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_StunTimerHandle_MetaData)) }; // 3633724737
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_Character_Statics::NewProp_OnDeath_MetaData[] = {
		{ "Category", "TDRL|Delegates|Death" },
		{ "Comment", "/*Death delegate*/" },
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
		{ "ToolTip", "Death delegate" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_OnDeath = { "OnDeath", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATDRL_Character, OnDeath), Z_Construct_UDelegateFunction_TopDownRogueLite_OnDeathDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_OnDeath_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_OnDeath_MetaData)) }; // 3646839238
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATDRL_Character_Statics::NewProp_DeathInfo_MetaData[] = {
		{ "ModuleRelativePath", "Public/Player/TDRL_Character.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ATDRL_Character_Statics::NewProp_DeathInfo = { "DeathInfo", "OnRep_DeathInfo", (EPropertyFlags)0x0020080100000020, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATDRL_Character, DeathInfo), Z_Construct_UScriptStruct_FDeathData, METADATA_PARAMS(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_DeathInfo_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_Character_Statics::NewProp_DeathInfo_MetaData)) }; // 3112512265
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATDRL_Character_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_GlobalPostProcess,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_PostProcessInUse,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_DefaultAttributeEffect,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_DefaultAbilities_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_DefaultAbilities,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_MaxHealth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_Health,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_OcclusionParam,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_CameraOccludingComponents_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_CameraOccludingComponents,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_AimOffsetValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_CameraSpringArm,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_Camera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_SightComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_AbilityComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_AttributeSet,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_InitialInventorySlots,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_DefaultWeaponClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_MainWeapon,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_SelectedItemSlot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_Inventory_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_Inventory,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_ItemTraceRadius,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_TraceForItemsChannels_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_TraceForItemsChannels,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_NearestNearbyItemIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_NearbyItems_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_NearbyItems,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_bDebugShowTraceForItems,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_TraceItemTimerHandle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_DefaultDamageKnockback,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_DefaultKnockbackMontages_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_DefaultKnockbackMontages,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_CurrentStun,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_StunTimerHandle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_OnDeath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATDRL_Character_Statics::NewProp_DeathInfo,
	};
		const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_ATDRL_Character_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UAbilitySystemInterface_NoRegister, (int32)VTABLE_OFFSET(ATDRL_Character, IAbilitySystemInterface), false },  // 220555618
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATDRL_Character_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATDRL_Character>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ATDRL_Character_Statics::ClassParams = {
		&ATDRL_Character::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ATDRL_Character_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_Character_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ATDRL_Character_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ATDRL_Character_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATDRL_Character()
	{
		if (!Z_Registration_Info_UClass_ATDRL_Character.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATDRL_Character.OuterSingleton, Z_Construct_UClass_ATDRL_Character_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ATDRL_Character.OuterSingleton;
	}
	template<> TOPDOWNROGUELITE_API UClass* StaticClass<ATDRL_Character>()
	{
		return ATDRL_Character::StaticClass();
	}

	void ATDRL_Character::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
	{
		static const FName Name_Health(TEXT("Health"));
		static const FName Name_AimOffsetValue(TEXT("AimOffsetValue"));
		static const FName Name_MainWeapon(TEXT("MainWeapon"));
		static const FName Name_SelectedItemSlot(TEXT("SelectedItemSlot"));
		static const FName Name_Inventory(TEXT("Inventory"));
		static const FName Name_CurrentStun(TEXT("CurrentStun"));
		static const FName Name_DeathInfo(TEXT("DeathInfo"));

		const bool bIsValid = true
			&& Name_Health == ClassReps[(int32)ENetFields_Private::Health].Property->GetFName()
			&& Name_AimOffsetValue == ClassReps[(int32)ENetFields_Private::AimOffsetValue].Property->GetFName()
			&& Name_MainWeapon == ClassReps[(int32)ENetFields_Private::MainWeapon].Property->GetFName()
			&& Name_SelectedItemSlot == ClassReps[(int32)ENetFields_Private::SelectedItemSlot].Property->GetFName()
			&& Name_Inventory == ClassReps[(int32)ENetFields_Private::Inventory].Property->GetFName()
			&& Name_CurrentStun == ClassReps[(int32)ENetFields_Private::CurrentStun].Property->GetFName()
			&& Name_DeathInfo == ClassReps[(int32)ENetFields_Private::DeathInfo].Property->GetFName();

		checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in ATDRL_Character"));
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATDRL_Character);
	ATDRL_Character::~ATDRL_Character() {}
	struct Z_CompiledInDeferFile_FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Player_TDRL_Character_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Player_TDRL_Character_h_Statics::ScriptStructInfo[] = {
		{ FCameraTraceOcclusionParams::StaticStruct, Z_Construct_UScriptStruct_FCameraTraceOcclusionParams_Statics::NewStructOps, TEXT("CameraTraceOcclusionParams"), &Z_Registration_Info_UScriptStruct_CameraTraceOcclusionParams, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCameraTraceOcclusionParams), 1244550909U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Player_TDRL_Character_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ATDRL_Character, ATDRL_Character::StaticClass, TEXT("ATDRL_Character"), &Z_Registration_Info_UClass_ATDRL_Character, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATDRL_Character), 948212615U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Player_TDRL_Character_h_4205343612(TEXT("/Script/TopDownRogueLite"),
		Z_CompiledInDeferFile_FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Player_TDRL_Character_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Player_TDRL_Character_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Player_TDRL_Character_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_Che_Plugins_TopDownRogueLite_Source_TopDownRogueLite_Public_Player_TDRL_Character_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
