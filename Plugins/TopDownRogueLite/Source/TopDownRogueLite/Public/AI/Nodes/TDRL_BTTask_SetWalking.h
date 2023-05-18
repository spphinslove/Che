// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "TDRL_BTTask_SetWalking.generated.h"

/**
 * 
 */
UCLASS(meta = (DisplayName = "Enable Walking"))
class TOPDOWNROGUELITE_API UTDRL_BTTask_SetWalking : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UTDRL_BTTask_SetWalking();

	/*Character should walk?*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task")
	uint8 ShouldWalk : 1;

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
	virtual FString GetStaticDescription() const override;
};
