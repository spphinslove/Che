// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "TDRL_BTTask_FindRandomReachable.generated.h"

/**
 * 
 */
UCLASS(meta = (DisplayName = "Find Random Reachable Location"))
class TOPDOWNROGUELITE_API UTDRL_BTTask_FindRandomReachable : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UTDRL_BTTask_FindRandomReachable();

	/*Target*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task")
	struct FBlackboardKeySelector TargetOrigin;
	/*Vector selector you want to use to store the random location*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task")
	struct FBlackboardKeySelector TargetKeyVector;
	/*Radious around the target location*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task")
	float ReachRadius = 600.0f;

protected:
	// Event Receive Execute (Blueprint)
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
	virtual FString GetStaticDescription() const override;
};
