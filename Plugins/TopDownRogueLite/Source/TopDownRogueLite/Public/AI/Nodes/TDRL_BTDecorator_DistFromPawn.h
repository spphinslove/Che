// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TDRL_BTDecorator.h"

#include "TDRL_AITypes.h"
#include "TDRL_BTDecorator_DistFromPawn.generated.h"


/**
 * 
 */
UCLASS(meta = (DisplayName = "Distance from Pawn"))
class TOPDOWNROGUELITE_API UTDRL_BTDecorator_DistFromPawn : public UTDRL_BTDecorator
{
	GENERATED_BODY()

public:
	UTDRL_BTDecorator_DistFromPawn();

	/*Character's distance from this target*/
	UPROPERTY(EditAnywhere, Category = "Condition")
	struct FBlackboardKeySelector Target;
	/*Comparison method*/
	UPROPERTY(EditAnywhere, Category = "Condition")
	EMathComparisonMethod Method;
	/*Limit*/
	UPROPERTY(EditAnywhere, Category = "Condition")
	float Distance = 400.0f;

	UPROPERTY(EditAnywhere, Category = "Tick")
	float TickCheckInterval = 0.0f;

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
	virtual void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	virtual FString GetStaticDescription() const override;
};
