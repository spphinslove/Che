// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetUserData.h"
#include "TDRL_AUData_MeleeTraceFilter.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class TOPDOWNROGUELITE_API UTDRL_AUData_MeleeTraceFilter : public UAssetUserData
{
	GENERATED_BODY()

	UTDRL_AUData_MeleeTraceFilter();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDRL|Filters")
	TArray<FName> TagFilters;

protected:
};
