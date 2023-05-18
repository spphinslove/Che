// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"

#include "TDRL_AITypes.h"
#include "TDRL_BTService_WalkOnDistance.generated.h"

/**
 * 
 */
UCLASS(meta = (DisplayName = "Start Walking on Distance"))
class TOPDOWNROGUELITE_API UTDRL_BTService_WalkOnDistance : public UBTService
{
	GENERATED_BODY()

public:
	UTDRL_BTService_WalkOnDistance();

	/*Target actor or location AI wants to reach*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Service")
	struct FBlackboardKeySelector Target;
	/*Comparison method*/
	UPROPERTY(EditAnywhere, Category = "Service")
	EMathComparisonMethod Method;
	/*Trigger distance*/
	UPROPERTY(EditAnywhere, Category = "Service")
	float Distance = 400.0f;

	UPROPERTY(EditAnywhere, Category = "Service")
	uint8 bRestoreWhenFinish : 1;

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	virtual void OnCeaseRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual FString GetStaticDescription() const override;
};
