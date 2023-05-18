// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "TDRL_BTService_ClearIfDead.generated.h"

/**
 * 
 */
UCLASS(meta = (DisplayName = "Clear Blackboard Key if Dead"))
class TOPDOWNROGUELITE_API UTDRL_BTService_ClearIfDead : public UBTService
{
	GENERATED_BODY()

public:
	UTDRL_BTService_ClearIfDead();
	/*Target actor or location AI wants to reach*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Service")
	struct FBlackboardKeySelector Target;

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	virtual FString GetStaticDescription() const override;
};
