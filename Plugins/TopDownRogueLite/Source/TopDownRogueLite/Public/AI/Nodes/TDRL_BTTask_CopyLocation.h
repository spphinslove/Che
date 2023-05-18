// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "TDRL_BTTask_CopyLocation.generated.h"

/**
 * 
 */
UCLASS(meta = (DisplayName = "Copy BB Location"))
class TOPDOWNROGUELITE_API UTDRL_BTTask_CopyLocation : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UTDRL_BTTask_CopyLocation();

	/*Copy value from this blackboard selector*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task")
	struct FBlackboardKeySelector From;
	/*To this blackboard selector*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task")
	struct FBlackboardKeySelector Target;

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
	virtual FString GetStaticDescription() const override;
};
