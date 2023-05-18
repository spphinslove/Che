// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "TDRL_BTService_UpdateAimOffset.generated.h"

/**
 * 
 */
UCLASS(meta = (DisplayName = "Update AnimOffset"))
class TOPDOWNROGUELITE_API UTDRL_BTService_UpdateAimOffset : public UBTService
{
	GENERATED_BODY()

public:
	UTDRL_BTService_UpdateAimOffset();
	/*Target actor the AI should face*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Service")
	struct FBlackboardKeySelector AimOffsetTarget;

protected:
	virtual void OnCeaseRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	virtual FString GetStaticDescription() const override;
};
