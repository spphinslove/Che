// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "TDRL_BTTask_PlayAnimMontage.generated.h"

/**
 * 
 */
UCLASS(meta = (DisplayName = "Play AnimMontage"))
class TOPDOWNROGUELITE_API UTDRL_BTTask_PlayAnimMontage : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UTDRL_BTTask_PlayAnimMontage();

	/*Selector Animation Montage to play*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task", meta = (EditCondition = "!bUseAnimMontageAsset"))
	struct FBlackboardKeySelector AnimMontage;
	/*Playrate to apply to this animation*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task")
	float AnimPlayRate = 1.0f;

	/*Use specific AnimMontage asset*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task|Asset")
	uint8 bUseAnimMontageAsset : 1;
	/*AnimMontage Asset to use*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task|Asset", meta = (EditCondition = "bUseAnimMontageAsset"))
	class UAnimMontage* AnimMontageAsset;

	/*Should stop montage on abort or keep playing?*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task|Ending")
	uint8 bStopMontageOnAbort : 1;
	/*Should clear "AnimMontage" selector after stop playing?*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task|Ending",
		meta = (EditCondition = "!bUseAnimMontageAsset"))
	uint8 bClearBBValue : 1;

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
	virtual EBTNodeResult::Type AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
	virtual FString GetStaticDescription() const override;
	UFUNCTION()
	virtual void AnimIsOver(UBehaviorTreeComponent* OwnerComp);

	UPROPERTY()
	FTimerHandle AnimEndHandle;
};
