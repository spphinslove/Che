// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "TDRL_GASTypes.h"
#include "TDRL_GameplayTypes.h"
#include "TDRL_ItemTypes.generated.h"


UENUM(BlueprintType)
enum class EItemRarity : uint8
{
	IR_Trash UMETA(DisplayName = "Trash"),
	IR_Common UMETA(DisplayName = "Common"),
	IR_Uncommon UMETA(DisplayName = "Uncommon"),
	IR_Rare UMETA(DisplayName = "Rare"),
	IR_Epic UMETA(DisplayName = "Epic"),
	IR_Legend UMETA(DisplayName = "Legend"),
	IR_MAX UMETA(DisplayName = "Max"),
};

UENUM(BlueprintType)
enum class EItemInteractions : uint8
{
	II_Pickup UMETA(DisplayName = "Pickup"),
	II_Drop UMETA(DisplayName = "Drop"),
	II_Equip UMETA(DisplayName = "Equip"),
	II_Holster UMETA(DisplayName = "Holster")
};

USTRUCT(BlueprintType)
struct TOPDOWNROGUELITE_API FItemAbilitiesEffects
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemAbilities")
	FGASContainer AddOnPickup;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemAbilities")
	FGASContainer RemoveOnPickup;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemAbilities")
	FGASContainer AddOnDrop;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemAbilities")
	FGASContainer RemoveOnDrop;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemAbilities")
	FGASContainer AddOnEquipped;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemAbilities")
	FGASContainer RemoveOnEquipped;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemAbilities")
	FGASContainer AddOnHolstered;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemAbilities")
	FGASContainer RemoveOnHolstered;

	FItemAbilitiesEffects()
	{
		AddOnPickup = FGASContainer();
		RemoveOnPickup = FGASContainer();
		AddOnDrop = FGASContainer();
		RemoveOnDrop = FGASContainer();
		AddOnEquipped = FGASContainer();
		RemoveOnEquipped = FGASContainer();
		AddOnHolstered = FGASContainer();
		RemoveOnHolstered = FGASContainer();
	}

	bool HasAbilities(const EItemInteractions Interaction)
	{
		bool ReturnValue = false;
		switch (Interaction)
		{
		case EItemInteractions::II_Pickup:
			ReturnValue = AddOnPickup.HasAbilities() || RemoveOnPickup.HasAbilities();
			break;
		case EItemInteractions::II_Drop:
			ReturnValue = AddOnDrop.HasAbilities() || RemoveOnDrop.HasAbilities();
			break;
		case EItemInteractions::II_Equip:
			ReturnValue = AddOnEquipped.HasAbilities() || RemoveOnEquipped.HasAbilities();
			break;
		case EItemInteractions::II_Holster:
			ReturnValue = AddOnHolstered.HasAbilities() || RemoveOnHolstered.HasAbilities();
			break;
		}

		return ReturnValue;
	}

	bool HasEffects(const EItemInteractions Interaction)
	{
		bool ReturnValue = false;
		switch (Interaction)
		{
		case EItemInteractions::II_Pickup:
			ReturnValue = AddOnPickup.HasEffects() || RemoveOnPickup.HasEffects();
			break;
		case EItemInteractions::II_Drop:
			ReturnValue = AddOnDrop.HasEffects() || RemoveOnDrop.HasEffects();
			break;
		case EItemInteractions::II_Equip:
			ReturnValue = AddOnEquipped.HasEffects() || RemoveOnEquipped.HasEffects();
			break;
		case EItemInteractions::II_Holster:
			ReturnValue = AddOnHolstered.HasEffects() || RemoveOnHolstered.HasEffects();
			break;
		}

		return ReturnValue;
	}

	bool HasAnyAbility()
	{
		return HasAbilities(EItemInteractions::II_Pickup) || HasAbilities(EItemInteractions::II_Drop) ||
			HasAbilities(EItemInteractions::II_Equip) || HasAbilities(EItemInteractions::II_Holster);
	}

	bool HasAnyEffect()
	{
		return HasEffects(EItemInteractions::II_Pickup) || HasEffects(EItemInteractions::II_Drop) ||
			HasEffects(EItemInteractions::II_Equip) || HasEffects(EItemInteractions::II_Holster);
	}

	bool HasAny()
	{
		return HasAnyAbility() || HasAnyEffect();
	}

	bool HasAny(const EItemInteractions Interaction)
	{
		return HasAbilities(Interaction) || HasEffects(Interaction);
	}
};

USTRUCT(BlueprintType)
struct TOPDOWNROGUELITE_API FItemStaticData
{
	GENERATED_USTRUCT_BODY()

	/*Item name to display*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	FName Name;
	/*Item rarity*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	EItemRarity Rarity;
	/*Item icon*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	TSoftObjectPtr<UTexture2D> Icon;
	/*Socket this Item will be attached when equipped*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	FName Socket;
	/*Layer Animation stance to use*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	TSubclassOf<class UAnimInstance> LayerAnimInstance;

	/*Should always equip when picked up? Otherwise, if the player is selecting the main weapon, this one will just simply be place into the inventory*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	uint8 bAlwaysEquipOnPickup : 1;

	/*Skeletal mesh asset to use when equipped. Will use the static mesh if this is null*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	USkeletalMesh* SkeletalMesh;
	/*AnimBlueprint to assign to the SkeletalMesh*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	TSubclassOf<class UAnimInstance> AnimBlueprint;
	/*Abilities and effects to handle during the various events*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	FItemAbilitiesEffects GASData;

	FItemStaticData()
	{
		Name = FName();
		Rarity = EItemRarity::IR_Common;
		Icon = nullptr;
		Socket = FName("hand_r");
		LayerAnimInstance = nullptr;
		bAlwaysEquipOnPickup = false;
		SkeletalMesh = nullptr;
		AnimBlueprint = nullptr;
		GASData = FItemAbilitiesEffects();
	}
};

USTRUCT(BlueprintType)
struct TOPDOWNROGUELITE_API FMeleePrimaryAttackMontages
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttackMontages")
	TArray<class UAnimMontage*> Still;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttackMontages")
	TArray<class UAnimMontage*> Forward;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttackMontages")
	TArray<class UAnimMontage*> Backward;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttackMontages")
	TArray<class UAnimMontage*> Right;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttackMontages")
	TArray<class UAnimMontage*> Left;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttackMontages")
	TArray<class UAnimMontage*> Falling;

	FMeleePrimaryAttackMontages()
	{
		Still = TArray<class UAnimMontage*>();
		Forward = TArray<class UAnimMontage*>();
		Backward = TArray<class UAnimMontage*>();
		Right = TArray<class UAnimMontage*>();
		Left = TArray<class UAnimMontage*>();
		Falling = TArray<class UAnimMontage*>();
	}
};

USTRUCT(BlueprintType)
struct TOPDOWNROGUELITE_API FMeleeStaticData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	FMeleePrimaryAttackMontages AnimMontages;

	/*Base damage to apply when this melee weapon hit something*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	float Damage;
	/*Delay this time before start tracing the attack*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	float Delay;
	/*Time window, the attack duration*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	float TimeWindow;
	/*Countdown before being able to attack again*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	float Countdown;
	/*Noise emitted by an attack without hit*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	float Loudness;
	/*Noise emitted by an actual hit*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	float HitLoudness;
	/*Noise Tag for normal Loudness*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	FName NoiseTag;
	/*Noise Tag for HitNoiseTag*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	FName HitNoiseTag;
	/*Damage type to apply*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	TSubclassOf<class UDamageType> DamageType;

	/*Hit VFXs list to use on Hit*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData", meta = (AllowedStructTypes = "FHitEffectType"))
	UDataTable* HitVFXs;
	/*Should use tag filters? Using these tags you can decide which bodies will be traced depending on the animation playing*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	uint8 bUseTagFilter : 1;


	FMeleeStaticData()
	{
		AnimMontages = FMeleePrimaryAttackMontages();

		Damage = 50.0f;
		Delay = 0.05f;
		TimeWindow = 0.3f;
		Countdown = 0.5f;
		Loudness = 0.15f;
		HitLoudness = 0.3f;
		NoiseTag = FName("AINoise");
		HitNoiseTag = FName("AINoiseHit");
		DamageType = nullptr;
		HitVFXs = nullptr;
		bUseTagFilter = false;
	}
};

USTRUCT(BlueprintType)
struct TOPDOWNROGUELITE_API FFirearmMontages
{
	GENERATED_USTRUCT_BODY()

	/*Played when performing the Primary Action*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montages")
	class UAnimMontage* Primary;
	/*Played when performing the Secondary Action*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montages")
	class UAnimMontage* Secondary;
	/*Played when Reloading*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montages")
	class UAnimMontage* Reload;

	FFirearmMontages()
	{
		Primary = nullptr;
		Secondary = nullptr;
		Reload = nullptr;
	}
};

USTRUCT(BlueprintType)
struct TOPDOWNROGUELITE_API FFirearmStaticData
{
	GENERATED_USTRUCT_BODY()

	/*Firearm montages to play*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	FFirearmMontages AnimMontages;
	/*Projectile class to spawn when fire*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	TSubclassOf<class ATDRL_ProjectileBase> ProjectileClass;
	/*Firerate of this firearm (IMPORTANT: firerate is Bullets/Second)*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	float FireRate;
	/*Delay before firing*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	float FireDelay;
	/*Burst length in bullets. 0 will not use burst*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	uint8 Burst;
	/*Max ammo this weapon can carry (excluding magazine)*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	int32 MaxAmmo;
	/*Max ammo this weapon can carry into the magazine alone*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	int32 MagazineSize;
	/*Time required to reload this firearm*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	float ReloadTime;
	/*Noise loudness when shot*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	float Loudness;
	/*Noise tag for AIPerception management*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	FName NoiseTag;

	/*Used for filtering ammo pickups*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	FName AmmoTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	TArray<TSubclassOf<AActor>> MuzzleObstructionCheckIgnore;

	FFirearmStaticData()
	{
		AnimMontages = FFirearmMontages();
		ProjectileClass = nullptr;
		FireRate = 1.0f;
		FireDelay = 0.0f;
		Burst = 1;
		MaxAmmo = 60;
		MagazineSize = 7;
		ReloadTime = 3.0f;
		Loudness = 1.0f;
		NoiseTag = FName("AINoise");

		AmmoTag = FName();

		MuzzleObstructionCheckIgnore = TArray<TSubclassOf<AActor>>{APawn::StaticClass()};
	}
};

USTRUCT(BlueprintType)
struct TOPDOWNROGUELITE_API FProjectileStaticData
{
	GENERATED_USTRUCT_BODY()

	/*Number of instances or traces to spawn*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	uint8 Instances;
	/*Trajectory variance between instances (randomized direction)*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	FVector2D TrajectoryVariance;

	/*Max time this projectile can operate before being destroyed*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	float Lifetime;
	/*Base damage to apply when hit something*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	float Damage;
	/*Noise loudness when this projectile hit something*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	float HitLoudness;
	/*Noise tag for AIPerception management*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	FName HitNoiseTag;
	/*Damage type to apply*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	TSubclassOf<class UDamageType> DamageType;

	/*Projectile sound*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData")
	class USoundCue* SoundEffect;

	/*Projectile muzzle vfx*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData",
		meta = (EditCondition = "MuzzleEffectParticle==nullptr", EditConditionHides))
	class UNiagaraSystem* MuzzleEffectNiagara;
	/*Projectile muzzle vfx*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData",
		meta = (EditCondition = "MuzzleEffectNiagara==nullptr", EditConditionHides))
	class UParticleSystem* MuzzleEffectParticle;

	/*Hit VFXs list to use on Hit*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticData", meta = (AllowedStructTypes = "FHitEffectType"))
	UDataTable* HitVFXs;

	FProjectileStaticData()
	{
		Instances = 1;
		TrajectoryVariance = FVector2D(0.5f);

		Lifetime = 2.0f;
		Damage = 100.0f;
		HitLoudness = 0.75f;
		HitVFXs = nullptr;
		HitNoiseTag = FName("AINoiseHit");
		DamageType = nullptr;
		MuzzleEffectNiagara = nullptr;
		MuzzleEffectParticle = nullptr;
		SoundEffect = nullptr;
	}
};

/**
 * 
 */
class TOPDOWNROGUELITE_API TDRL_ItemTypes
{
public:
	TDRL_ItemTypes();
	~TDRL_ItemTypes();
};
