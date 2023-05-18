// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TDRL_BTDecorator.h"
#include "TDRL_BTDecorator_PlayingMontage.generated.h"

/**
 * 
 */
UCLASS(meta = (DisplayName = "Is Playing Montage"))
class TOPDOWNROGUELITE_API UTDRL_BTDecorator_PlayingMontage : public UTDRL_BTDecorator
{
	GENERATED_BODY()

public:
	UTDRL_BTDecorator_PlayingMontage();

	/*Target to check if it's playing a montage*/
	UPROPERTY(EditAnywhere, Category = "Condition", meta = (EditCondition = "bSelectMontage"))
	struct FBlackboardKeySelector BBMontage;
	/*Force to check for a specific montage, if this variable is false and "SpecificMontages" is null, the script will check for ANY montage.*/
	UPROPERTY(EditAnywhere, Category = "Condition")
	uint8 bSelectMontage : 1;
	/*Specific montage to check, will return false if it's playing any other montage.*/
	UPROPERTY(EditAnywhere, Category = "Condition|AdditionalFilters", meta = (EditCondition = "bSelectMontage"))
	TArray<class UAnimMontage*> SpecificMontages;

	UPROPERTY(EditAnywhere, Category = "Tick")
	float TickCheckInterval = 0.0f;

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
	virtual void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	virtual FString GetStaticDescription() const override;
};
