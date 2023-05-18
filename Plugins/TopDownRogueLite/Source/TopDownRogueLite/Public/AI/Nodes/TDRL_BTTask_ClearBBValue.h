// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "TDRL_BTTask_ClearBBValue.generated.h"

/**
 * 
 */
UCLASS(meta = (DisplayName = "Clear BB Value"))
class TOPDOWNROGUELITE_API UTDRL_BTTask_ClearBBValue : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UTDRL_BTTask_ClearBBValue();

	/*Backboard entry you want to clear*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task")
	struct FBlackboardKeySelector BBEntry;

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
	virtual FString GetStaticDescription() const override;
};
