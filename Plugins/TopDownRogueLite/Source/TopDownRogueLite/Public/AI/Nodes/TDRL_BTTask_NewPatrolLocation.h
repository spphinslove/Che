// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "TDRL_BTTask_NewPatrolLocation.generated.h"

/**
 * 
 */
UCLASS(meta = (DisplayName = "New Patrol Target Location"))
class TOPDOWNROGUELITE_API UTDRL_BTTask_NewPatrolLocation : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UTDRL_BTTask_NewPatrolLocation();

	/*Target selector the AI is patrolling*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task")
	struct FBlackboardKeySelector TargetToPatrol;
	/*Radius tollerance around the target/spline point*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task")
	float Tollerance = 200.0f;
	/*Selector used to save the new patrol location*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task")
	struct FBlackboardKeySelector StoredLocation;

	/*[AISplineTool] Should pick random spline points? Or just follow the order (None = false)*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task|SplineAITool")
	struct FBlackboardKeySelector UseRandomPoints;
	/*[AISplineTool] Used to cache the last assigned spline point*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task|SplineAITool")
	struct FBlackboardKeySelector StoredAIPointIndex;

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
	virtual FString GetStaticDescription() const override;
};
