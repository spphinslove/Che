// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "Engine/DataTable.h"
#include "Engine/StaticMeshActor.h"
#include "Engine/DecalActor.h"

#include "Animation/AnimMontage.h"

#include "SkeletalMeshMerge.h"
#include "TDRL_GameplayTypes.generated.h"

UENUM(BlueprintType)
enum class EPlayersSapawnUnlockMethod : uint8
{
	PSUM_None UMETA(DisplayName = "None"),
	PSUM_Overlap UMETA(DisplayName = "Overlap"),
	PSUM_Team UMETA(DisplayName = "Team"),
};

UENUM(BlueprintType)
enum class EPlayersSapawnMethod : uint8
{
	PSM_None UMETA(DisplayName = "None"),
	PSM_Progressive UMETA(DisplayName = "Progressive"),
	PSM_Random UMETA(DisplayName = "Random"),
};

UENUM(BlueprintType)
enum class EControlRotationType : uint8
{
	UnderMouse UMETA(DisplayName = "UnderMouse"),
	LockedTarget UMETA(DisplayName = "LockedTarget"),
	TargetLocation UMETA(DisplayName = "TargetLocation"),
};

USTRUCT(BlueprintType)
struct TOPDOWNROGUELITE_API FDeathData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	uint8 bIsDead : 1;

	// Dead character
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Death")
	class ATDRL_Character* Character;
	// Actor responsable for this death
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Death")
	AActor* Actor;
	// Instigator (controller) responsable for this death
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Death")
	AController* Controller;
	// Last damage received
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Death")
	float LastDamage;

	FDeathData()
	{
		Character = nullptr;
		bIsDead = false;
		Actor = nullptr;
		Controller = nullptr;
		LastDamage = 0.0f;
	}

	FDeathData(class ATDRL_Character* InCharacter, AActor* InActor, AController* InController, float InLastDamage)
	{
		if (InActor || InController || InLastDamage != 0.0f)
		{
			bIsDead = true;
		}

		Character = InCharacter;
		Actor = InActor;
		Controller = InController;
		LastDamage = InLastDamage;
	}

	/*Set when the character dies (CharacterDeath function)*/
	bool IsDead()
	{
		return bIsDead;
	}
};

USTRUCT(BlueprintType)
struct TOPDOWNROGUELITE_API FHitEffectType : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HitVFXs",
		meta = (EditCondition = "HitParticleEffect==nullptr", EditConditionHides))
	class UNiagaraSystem* HitNiagaraEffect;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HitVFXs",
		meta = (EditCondition = "HitNiagaraEffect==nullptr", EditConditionHides))
	class UParticleSystem* HitParticleEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttachedVFXs",
		meta = (EditCondition = "AttachedParticleEffect==nullptr", EditConditionHides))
	class UNiagaraSystem* AttachedNiagaraEffect;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttachedVFXs",
		meta = (EditCondition = "AttachedNiagaraEffect==nullptr", EditConditionHides))
	class UParticleSystem* AttachedParticleEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
	TSubclassOf<class AActor> ActorClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor",
		meta = (EditCondition = "ActorClass!=nullptr", EditConditionHides))
	class UStaticMesh* AttachedMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Decal")
	TSubclassOf<class ADecalActor> DecalActorClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Decal",
		meta = (EditCondition = "DecalActorClass!=nullptr", EditConditionHides))
	class UMaterialInstance* DecalMaterial;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Decal",
		meta = (EditCondition = "DecalActorClass!=nullptr", EditConditionHides))
	FVector DecalScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	class USoundCue* SoundEffect;

	FHitEffectType()
	{
		HitNiagaraEffect = nullptr;
		HitParticleEffect = nullptr;

		AttachedNiagaraEffect = nullptr;
		AttachedParticleEffect = nullptr;

		ActorClass = nullptr;
		AttachedMesh = nullptr;

		DecalActorClass = nullptr;
		DecalMaterial = nullptr;
		DecalScale = FVector(1.0f);

		SoundEffect = nullptr;
	}
};

USTRUCT(BlueprintType)
struct TOPDOWNROGUELITE_API FDashEffect
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VFX",
		meta = (EditCondition = "ParticleEffect==nullptr", EditConditionHides))
	class UNiagaraSystem* NiagaraEffect;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VFX",
		meta = (EditCondition = "NiagaraEffect==nullptr", EditConditionHides))
	class UParticleSystem* ParticleEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	class USoundCue* SoundEffect;

	FDashEffect()
	{
		NiagaraEffect = nullptr;
		ParticleEffect = nullptr;
		SoundEffect = nullptr;
	}
};

USTRUCT(BlueprintType)
struct TOPDOWNROGUELITE_API FStunParameters
{
	GENERATED_USTRUCT_BODY()

	/*Amount of time the character will be unable to perform actions*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stun")
	float Time = 3.0f;
	/*Force applied to the character*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stun")
	float Force = 0.0f;
	/*AnimMontage to play during stun*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stun")
	UAnimMontage* StunAnimationLoop;
	/*Should drop weapon?*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stun")
	uint8 bDropWeapon : 1;

protected:
	UPROPERTY()
	uint8 StunIsSet : 1;

public:
	FStunParameters()
	{
		Time = 0.0f;
		Force = 0.0f;
		StunAnimationLoop = nullptr;
		bDropWeapon = false;

		StunIsSet = false;
	}

	FStunParameters(const FStunParameters& Value)
	{
		Time = Value.Time;
		Force = Value.Force;
		StunAnimationLoop = Value.StunAnimationLoop;
		bDropWeapon = Value.bDropWeapon;

		StunIsSet = true;
	}

	FStunParameters(const float InTime, const float InForce, UAnimMontage* InStunAnimationLoop, const bool InRagdoll,
	                const bool InDropWeapon)
	{
		Time = InTime;
		Force = InForce;
		StunAnimationLoop = InStunAnimationLoop;
		bDropWeapon = InDropWeapon;

		StunIsSet = true;
	}

	bool IsValid()
	{
		return StunIsSet;
	}

	void Clear()
	{
		Time = 0.0f;
		Force = 0.0f;
		StunAnimationLoop = nullptr;
		bDropWeapon = false;

		StunIsSet = false;
	}
};

USTRUCT(BlueprintType)
struct TOPDOWNROGUELITE_API FStatusEffect
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status",
		meta = (EditCondition = "ParticleEffect==nullptr", EditConditionHides))
	class UNiagaraSystem* NiagaraEffect;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status",
		meta = (EditCondition = "NiagaraEffect==nullptr", EditConditionHides))
	class UParticleSystem* ParticleEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status",
		meta = (EditCondition = "SoundEffect==nullptr", EditConditionHides))
	UAnimMontage* Montage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status",
		meta = (EditCondition = "StunAnimationLoop==nullptr", EditConditionHides))
	class USoundCue* SoundEffect;

public:
	FStatusEffect()
	{
		NiagaraEffect = nullptr;
		ParticleEffect = nullptr;
		Montage = nullptr;
		SoundEffect = nullptr;
	}
};

#pragma region Cosmetics

USTRUCT(BlueprintType)
struct TOPDOWNROGUELITE_API FCosmeticParameterList : public FTableRowBase
{
	GENERATED_BODY()

	// The list of skeletal meshes to merge.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cosmetic")
	TArray<USkeletalMesh*> Meshes;
	// Skeleton that will be used for the merged mesh.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cosmetic")
	class USkeleton* Skeleton;
	// Mesh Physics Asset to use.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cosmetic")
	class UPhysicsAsset* PhysicsAsset;
	// Mesh Physics Asset to use.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cosmetic")
	class UPhysicsAsset* ShadowPhysicsAsset;

	FCosmeticParameterList()
	{
		Meshes = TArray<USkeletalMesh*>();
		Skeleton = nullptr;
		PhysicsAsset = nullptr;
		ShadowPhysicsAsset = nullptr;
	}

	bool IsValidCosmeticData() const
	{
		return Meshes.Num() > 0;
	}
};

/**
* Struct containing all parameters used to perform a Skeletal Mesh merge.
*/
USTRUCT(BlueprintType)
struct TOPDOWNROGUELITE_API FMergeSkeletalMeshesParameters
{
	GENERATED_BODY()

	// The list of skeletal meshes to merge.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SkeletalMerge")
	TArray<USkeletalMesh*> MeshesToMerge;
	// Section mapping for this merge event
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SkeletalMerge")
	TArray<FSkelMeshMergeSectionMapping> MeshSectionMappings;
	// UVTransforms per each mesh in the list
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SkeletalMerge")
	FSkelMeshMergeUVTransformMapping UVTransformsPerMesh;
	// The number of high LODs to remove from input meshes
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SkeletalMerge")
	int32 StripTopLODS;
	// Whether or not the resulting mesh needs to be accessed by the CPU for any reason (e.g. for spawning particle effects).
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SkeletalMerge")
	uint8 bNeedsCpuAccess : 1;
	// Update skeleton before merge. Otherwise, update after.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SkeletalMerge")
	uint8 bSkeletonBefore : 1;
	// Skeleton that will be used for the merged mesh.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SkeletalMerge")
	class USkeleton* Skeleton;

	// Mesh Physics Asset to use.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SkeletalMerge")
	class UPhysicsAsset* PhysicsAsset;
	// Mesh Physics Asset to use.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SkeletalMerge")
	class UPhysicsAsset* ShadowPhysicsAsset;

	FMergeSkeletalMeshesParameters()
	{
		MeshesToMerge = TArray<USkeletalMesh*>();
		StripTopLODS = 0;
		bNeedsCpuAccess = false;
		bSkeletonBefore = false;
		Skeleton = nullptr;
		PhysicsAsset = nullptr;
		ShadowPhysicsAsset = nullptr;
	}
};

#pragma endregion

#pragma region Currency

USTRUCT(BlueprintType)
struct TOPDOWNROGUELITE_API FCurrencyData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Currency")
	FName ShortName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Currency")
	UTexture2D* Icon;

	FCurrencyData()
	{
		ShortName = FName();
		Icon = nullptr;
	}

	bool IsValidData() const
	{
		return ShortName != FName() && Icon;
	}
};

USTRUCT(BlueprintType)
struct TOPDOWNROGUELITE_API FCurrenciesList : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Currency")
	TMap<FName, FCurrencyData> List;

	FCurrenciesList()
	{
		List = TMap<FName, FCurrencyData>();
	}

	bool Contains(FName InKey) const
	{
		return List.Contains(InKey);
	}

	const FCurrencyData* Find(FName InKey) const
	{
		return List.Find(InKey);
	}

	FCurrencyData FindRef(FName InKey) const
	{
		return List.FindRef(InKey);
	}

	bool Add(const FName InName, FCurrencyData InData)
	{
		if (List.Contains(InName) || InName == FName() || !InData.IsValidData())
		{
			return false;
		}

		List.Add(TTuple<FName, FCurrencyData>(InName, InData));
		return true;
	}

	bool Append(TMap<FName, FCurrencyData> InMap)
	{
		if (InMap.Num() == 0)
		{
			return false;
		}

		List.Append(InMap);
		return true;
	}

	void Empty()
	{
		List.Empty();
	}
};

#pragma endregion
