// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "TDRL_BTTask_PrimayAction.generated.h"

/**
 * 
 */
UCLASS(meta = (DisplayName = "Enable Primary Action"))
class TOPDOWNROGUELITE_API UTDRL_BTTask_PrimayAction : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UTDRL_BTTask_PrimayAction();

	/*Should enable Primary Action (will keep going untill it's disabled)*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task")
	uint8 Enable : 1;
	/*Should stop after the first Primary Action is performed? (DoOnce)*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task")
	float StopAfter;

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
	virtual EBTNodeResult::Type AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
	virtual FString GetStaticDescription() const override;

	UFUNCTION()
	virtual void EndAttackTimer(UBehaviorTreeComponent* OwnerComp);
};
