// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/TDRL_Melee.h"
#include "TDRL_Fists.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNROGUELITE_API ATDRL_Fists : public ATDRL_Melee
{
	GENERATED_BODY()

public:
	ATDRL_Fists();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	class USphereComponent* RightFist;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	class USphereComponent* LeftFist;

public:
};
