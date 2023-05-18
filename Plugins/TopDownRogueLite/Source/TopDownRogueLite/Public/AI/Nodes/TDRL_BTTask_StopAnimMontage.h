// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "TDRL_BTTask_StopAnimMontage.generated.h"

/**
 * 
 */
UCLASS(meta = (DisplayName = "Stop AnimMontage"))
class TOPDOWNROGUELITE_API UTDRL_BTTask_StopAnimMontage : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UTDRL_BTTask_StopAnimMontage();

	/*Should use a selector to identify which AnimMontage to stop?*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task", meta = (EditCondition = "!bStopSpecificAnimMontage"))
	uint8 bUseBlackboardKey : 1;
	/*Specific target AnimMontage Selector*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task", meta = (EditCondition = "bUseBlackboardKey"))
	struct FBlackboardKeySelector AnimKey;
	/*Should clear the selector used for this animation once it's over?*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task", meta = (EditCondition = "bUseBlackboardKey"))
	uint8 bClearBBValue : 1;

	/*Should stop a specific AnimMontage asset?*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task|Asset", meta = (EditCondition = "!bUseBlackboardKey"))
	uint8 bStopSpecificAnimMontage : 1;
	/*Specific AnimMontage to stop.*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task|Asset",
		meta = (EditCondition = "bStopSpecificAnimMontage"))
	class UAnimMontage* AnimMontageAsset;

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
	virtual FString GetStaticDescription() const override;
};
