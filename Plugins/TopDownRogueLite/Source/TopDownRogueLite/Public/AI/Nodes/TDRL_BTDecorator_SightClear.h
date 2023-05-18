// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TDRL_BTDecorator.h"
#include "TDRL_BTDecorator_SightClear.generated.h"

/**
 * 
 */
UCLASS(meta = (DisplayName = "Is Sight Clear"))
class TOPDOWNROGUELITE_API UTDRL_BTDecorator_SightClear : public UTDRL_BTDecorator
{
	GENERATED_BODY()

public:
	UTDRL_BTDecorator_SightClear();

	/*Target*/
	UPROPERTY(EditAnywhere, Category = "Condition")
	struct FBlackboardKeySelector Target;
	/*Sight trace radius, larger values will require more space free space between the target and the AI to return true.*/
	UPROPERTY(EditAnywhere, Category = "Condition")
	float TraceRadius = 16.0f;
	/*Tollerance between the hit result and the target location, it is applied if the trace will hit a different actor then the target*/
	UPROPERTY(EditAnywhere, Category = "Condition")
	float Tollerance = 0.0f;


	UPROPERTY(EditAnywhere, Category = "Cache")
	struct FBlackboardKeySelector CachedBool;
	UPROPERTY(EditAnywhere, Category = "Tick")
	float TickCheckInterval = 0.5f;

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
	virtual void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	virtual FString GetStaticDescription() const override;
};
