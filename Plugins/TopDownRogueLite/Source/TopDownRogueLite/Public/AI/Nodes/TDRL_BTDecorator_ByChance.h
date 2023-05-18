// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TDRL_BTDecorator.h"
#include "TDRL_BTDecorator_ByChance.generated.h"

/**
 * 
 */
UCLASS(meta = (DisplayName = "By Chance"))
class TOPDOWNROGUELITE_API UTDRL_BTDecorator_ByChance : public UTDRL_BTDecorator
{
	GENERATED_BODY()

public:
	UTDRL_BTDecorator_ByChance();

	/*Chance allowing following tasks. Each time this Decorator is executed, a new chance will be pick.*/
	UPROPERTY(EditAnywhere, Category = "Condition",
		meta = (ClampMin = "0", ClampMax = "100", UIMin = "0", UIMax = "100"))
	uint8 Chances = 50;

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
	virtual void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual FString GetStaticDescription() const override;
};
