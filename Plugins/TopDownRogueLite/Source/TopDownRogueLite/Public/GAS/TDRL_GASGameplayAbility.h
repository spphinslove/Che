// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "TDRL_GASTypes.h"
#include "TDRL_GASGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNROGUELITE_API UTDRL_GASGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

	UTDRL_GASGameplayAbility();

public:
	/*AbilityInputID for this ability class (used for inputs)*/
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "TDRL|Ability")
	ETDRLGASAbilityInputID AbilityInputID = ETDRLGASAbilityInputID::None;

protected:
};
