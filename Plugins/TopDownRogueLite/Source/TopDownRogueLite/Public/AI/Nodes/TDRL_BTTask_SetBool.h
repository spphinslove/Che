// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "TDRL_BTTask_SetBool.generated.h"

/**
 * 
 */
UCLASS(meta = (DisplayName = "Set BB Bool"))
class TOPDOWNROGUELITE_API UTDRL_BTTask_SetBool : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UTDRL_BTTask_SetBool();

	/*Target bool selector*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task")
	struct FBlackboardKeySelector BBBool;
	/*New bool value*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task")
	uint8 NewValue : 1;

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
	virtual FString GetStaticDescription() const override;
};
