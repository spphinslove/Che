// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "TDRL_BTTask_RotateTowardsRandom.generated.h"

UENUM(BlueprintType)
enum class ERandRotDirection : uint8
{
	RRD_None UMETA(DisplayName = "None"),
	RRD_Right UMETA(DisplayName = "Right"),
	RRD_Left UMETA(DisplayName = "Left"),
	RRD_Random UMETA(DisplayName = "Random"),
};

/**
 * 
 */
UCLASS(meta = (DisplayName = "Rotate Toward Random"))
class TOPDOWNROGUELITE_API UTDRL_BTTask_RotateTowardsRandom : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UTDRL_BTTask_RotateTowardsRandom();

	/*Clamp random angle.*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task",
		meta = (EditCondition = "!bUseExactAngle", ClampMin = 0.0, UIMin = 0.0))
	FVector2D ClampRandomAngle = FVector2D(45.0f, 90.0f);
	/*Should use an exact world rotation?*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task")
	uint8 bUseExactAngle : 1;
	/*World rotation Yaw to apply*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task",
		meta = (EditCondition = "bUseExactAngle", ClampMin = 0.0, UIMin = 0.0))
	float ExactAngle = 0.0f;
	/*Rotation method*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task")
	ERandRotDirection Method = ERandRotDirection::RRD_Random;
	/*Rotation speed*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task")
	float RotationSpeed = 2.0f;

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds);
	virtual FString GetStaticDescription() const override;

	UPROPERTY()
	FRotator TargetRotation;
};
