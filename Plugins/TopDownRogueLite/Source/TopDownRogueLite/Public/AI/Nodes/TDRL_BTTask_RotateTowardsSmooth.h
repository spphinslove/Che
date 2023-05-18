// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "TDRL_BTTask_RotateTowardsSmooth.generated.h"

/**
 * 
 */
UCLASS(meta = (DisplayName = "Smoothly Rotate Towards"))
class TOPDOWNROGUELITE_API UTDRL_BTTask_RotateTowardsSmooth : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UTDRL_BTTask_RotateTowardsSmooth();

	/*Target the character should face*/
	UPROPERTY(EditAnywhere, Category = "Task")
	struct FBlackboardKeySelector Target;
	/*Rotation speed*/
	UPROPERTY(EditAnywhere, Category = "Task")
	float RotationSpeed = 2.0f;
	/*Rotation tollerance*/
	UPROPERTY(EditAnywhere, Category = "Task")
	float Tollerance = 5.0f;

	/*Should use an exact world rotation?*/
	UPROPERTY(EditAnywhere, Category = "Task")
	uint8 bUseAbsoluteWorldRotation : 1;
	/*World rotation Yaw to apply*/
	UPROPERTY(EditAnywhere, Category = "Task", meta = (EditCondition = "bUseAbsoluteWorldRotation"))
	float AbsWorldRotationYaw;

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds);
	virtual FString GetStaticDescription() const override;

	UPROPERTY()
	FRotator TargetRotation;
};
