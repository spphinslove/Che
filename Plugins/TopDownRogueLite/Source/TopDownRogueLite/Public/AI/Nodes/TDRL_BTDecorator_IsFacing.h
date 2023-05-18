// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TDRL_BTDecorator.h"
#include "TDRL_BTDecorator_IsFacing.generated.h"

/**
 * 
 */
UCLASS(meta = (DisplayName = "Is Facing"))
class TOPDOWNROGUELITE_API UTDRL_BTDecorator_IsFacing : public UTDRL_BTDecorator
{
	GENERATED_BODY()

public:
	UTDRL_BTDecorator_IsFacing();

	/*Target the character should be facing*/
	UPROPERTY(EditAnywhere, Category = "Condition", meta = (EditCondition = "!bUseAbsoluteWorldRotation"))
	struct FBlackboardKeySelector TargetToFace;
	/*Tollerance in degrees*/
	UPROPERTY(EditAnywhere, Category = "Condition")
	float Tollerance = 90.0f;
	/*Should test against a constant absolute world rotation?*/
	UPROPERTY(EditAnywhere, Category = "Condition")
	uint8 bUseAbsoluteWorldRotation : 1;
	/*Constant absolute world rotation*/
	UPROPERTY(EditAnywhere, Category = "Condition", meta = (EditCondition = "bUseAbsoluteWorldRotation"))
	FRotator AbsWorldRotation;

	UPROPERTY(EditAnywhere, Category = "Tick")
	float TickCheckInterval = 0.0f;

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
	virtual void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	virtual FString GetStaticDescription() const override;
};
