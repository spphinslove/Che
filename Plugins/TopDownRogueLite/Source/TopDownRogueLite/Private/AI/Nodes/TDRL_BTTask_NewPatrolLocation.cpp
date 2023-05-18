// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_BTTask_NewPatrolLocation.h"
#include "TDRL_AISplineTool.h"

#include "Components/SplineComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NavigationSystem.h"
#include "..\..\..\Public\AI\Nodes\TDRL_BTTask_NewPatrolLocation.h"

UTDRL_BTTask_NewPatrolLocation::UTDRL_BTTask_NewPatrolLocation()
	: Super()
{
	NodeName = "New Patrol Target Location";

	UseRandomPoints.AddBoolFilter(this, GET_MEMBER_NAME_CHECKED(UTDRL_BTTask_NewPatrolLocation, UseRandomPoints));
	UseRandomPoints.AllowNoneAsValue(true);

	TargetToPatrol.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UTDRL_BTTask_NewPatrolLocation, TargetToPatrol),
	                               AActor::StaticClass());
	TargetToPatrol.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UTDRL_BTTask_NewPatrolLocation, TargetToPatrol));

	StoredAIPointIndex.AddIntFilter(this, GET_MEMBER_NAME_CHECKED(UTDRL_BTTask_NewPatrolLocation, StoredAIPointIndex));

	StoredLocation.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UTDRL_BTTask_NewPatrolLocation, StoredAIPointIndex));
}

EBTNodeResult::Type UTDRL_BTTask_NewPatrolLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	UNavigationSystemV1* NavSys = UNavigationSystemV1::GetCurrent(GetWorld());
	FNavLocation PatrolPoint = FNavLocation();

	AActor* TargetActor = Cast<AActor>(
		OwnerComp.GetBlackboardComponent()->GetValueAsObject(TargetToPatrol.SelectedKeyName));

	if (TargetActor)
	{
		ATDRL_AISplineTool* TargetSpline = Cast<ATDRL_AISplineTool>(TargetActor);

		if (TargetSpline)
		{
			const int32 nPoints = TargetSpline->GetSplineComponent()->GetNumberOfSplinePoints();

			if (nPoints < 1)
			{
				if (!NavSys->GetRandomReachablePointInRadius(TargetActor->GetActorLocation(), Tollerance, PatrolPoint))
				{
					return EBTNodeResult::Failed;
				}
			}

			const bool SplineIsClosedLoop = TargetSpline->GetSplineComponent()->IsClosedLoop();

			int32 SelectedPointIndex = 0;
			if (OwnerComp.GetBlackboardComponent()->GetValueAsBool(UseRandomPoints.SelectedKeyName))
			{
				const int32 LastRandomIndex = OwnerComp.GetBlackboardComponent()->GetValueAsInt(
					StoredAIPointIndex.SelectedKeyName);
				SelectedPointIndex = LastRandomIndex;

				// Avoid choosing the same point
				while (LastRandomIndex == SelectedPointIndex)
				{
					SelectedPointIndex = FMath::RandRange(
						0, TargetSpline->GetSplineComponent()->GetNumberOfSplinePoints() - 1);
				}
			}
			else
			{
				const int32 NextIndex = OwnerComp.GetBlackboardComponent()->GetValueAsInt(
					StoredAIPointIndex.SelectedKeyName);
				if (SplineIsClosedLoop)
				{
					SelectedPointIndex = nPoints <= NextIndex ? 0 : NextIndex;
				}
				else
				{
					SelectedPointIndex = nPoints <= NextIndex ? -NextIndex + 2 : NextIndex;
				}
			}

			if (!NavSys->GetRandomReachablePointInRadius(
				TargetSpline->GetSplineComponent()->GetLocationAtSplinePoint(
					FMath::Abs(SelectedPointIndex), ESplineCoordinateSpace::World), Tollerance, PatrolPoint))
			{
				return EBTNodeResult::Failed;
			}

			OwnerComp.GetBlackboardComponent()->SetValueAsInt(StoredAIPointIndex.SelectedKeyName,
			                                                  SelectedPointIndex + (
				                                                  OwnerComp.GetBlackboardComponent()->GetValueAsBool(
					                                                  UseRandomPoints.SelectedKeyName)
					                                                  ? 0
					                                                  : 1));
			// If random, it's storing the last used. If sequence, it's storing the next to use
		}
		else
		{
			if (!NavSys->GetRandomReachablePointInRadius(TargetActor->GetActorLocation(), Tollerance, PatrolPoint))
			{
				return EBTNodeResult::Failed;
			}
		}
	}
	else
	{
		if (OwnerComp.GetBlackboardComponent()->IsVectorValueSet(TargetToPatrol.SelectedKeyName))
		{
			if (!NavSys->GetRandomReachablePointInRadius(
				OwnerComp.GetBlackboardComponent()->GetValueAsVector(TargetToPatrol.SelectedKeyName), Tollerance,
				PatrolPoint))
			{
				return EBTNodeResult::Failed;
			}
		}
		else
		{
			return EBTNodeResult::Failed;
		}
	}

	OwnerComp.GetBlackboardComponent()->SetValueAsVector(StoredLocation.SelectedKeyName, PatrolPoint.Location);
	return EBTNodeResult::Succeeded;
}

FString UTDRL_BTTask_NewPatrolLocation::GetStaticDescription() const
{
	return FString::Printf(
		TEXT("Target Patrol Key Is: %s%sTollerance: %s%sStored Location Key: %s%sStored AIPointIndex Key: %s"),
		*TargetToPatrol.SelectedKeyName.ToString(), LINE_TERMINATOR, *FString::SanitizeFloat(Tollerance),
		LINE_TERMINATOR, *StoredLocation.SelectedKeyName.ToString(), LINE_TERMINATOR,
		*StoredAIPointIndex.SelectedKeyName.ToString());
}
