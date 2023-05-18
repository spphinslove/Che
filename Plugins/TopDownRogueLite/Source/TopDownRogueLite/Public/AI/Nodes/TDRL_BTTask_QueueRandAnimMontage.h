// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"

#include "TDRL_AITypes.h"
#include "TDRL_BTTask_QueueRandAnimMontage.generated.h"

/**
 * 
 */
UCLASS(meta = (DisplayName = "Queue Random AnimMontage to BB"))
class TOPDOWNROGUELITE_API UTDRL_BTTask_QueueRandAnimMontage : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UTDRL_BTTask_QueueRandAnimMontage();
	/*Target selector where the result will be stored*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task")
	struct FBlackboardKeySelector QueueAnimKey;
	/*You can select a group of AnimMontage asset by name. A random AnimMontage will be selected from that group. IMPORTANT: these groups are stored inside the TDRL_AIController class*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task", meta = (EditCondition = "!bUseCustomContainer"))
	FName GroupName;

	/*Should use a custom container for random AnimMontages.*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task")
	uint8 bUseCustomContainer : 1;
	/*Custom AnimMontage container*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task", meta = (EditCondition = "bUseCustomContainer"))
	TSubclassOf<UAIAnimMontageContainer> CustomAnimMontageContainer;

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
	virtual FString GetStaticDescription() const override;
};
