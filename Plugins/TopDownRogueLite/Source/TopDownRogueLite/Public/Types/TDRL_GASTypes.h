// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TDRL_GASTypes.generated.h"

UENUM(BlueprintType)
enum class ETDRLGASAbilityInputID : uint8
{
	None,
	Confirm,
	Cancel,
	Move,
	Pickup,
	Drop,
	PrimaryAction,
	SecondaryAction,
	RAction,
	CameraRotation,
	Crouch,
	Jump,
	Dash,
	Walk,
	PitchAim,
	SwitchWeapon
};

USTRUCT(BlueprintType)
struct TOPDOWNROGUELITE_API FGASContainer
{
	GENERATED_USTRUCT_BODY()

	/*Abilities List*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDRL|GAS")
	TArray<TSubclassOf<class UTDRL_GASGameplayAbility>> Abilities;
	/*Effects List*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDRL|GAS")
	TArray<TSubclassOf<class UGameplayEffect>> Effects;

	FGASContainer()
	{
		Abilities = TArray<TSubclassOf<class UTDRL_GASGameplayAbility>>();
		Effects = TArray<TSubclassOf<class UGameplayEffect>>();
	}

	bool HasAbilities()
	{
		return Abilities.Num() > 0;
	}

	bool HasEffects()
	{
		return Effects.Num() > 0;
	}

	bool HasAny()
	{
		return HasAbilities() || HasEffects();
	}
};
