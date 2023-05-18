// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DamageType.h"
#include "TDRL_DamageType.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNROGUELITE_API UTDRL_DamageType : public UDamageType
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDRL|DamageType")
	float CriticalProbability = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDRL|DamageType")
	float StunProbability = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDRL|DamageType")
	FStunParameters Stun = FStunParameters();
};
