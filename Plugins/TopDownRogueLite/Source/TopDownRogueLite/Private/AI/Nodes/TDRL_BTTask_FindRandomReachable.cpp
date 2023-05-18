// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_BTTask_FindRandomReachable.h"

#include "BehaviorTree/BlackboardComponent.h"

#include "AIController.h"
#include "GameFramework/Pawn.h"
#include "NavigationSystem.h"
#include "..\..\..\Public\AI\Nodes\TDRL_BTTask_FindRandomReachable.h"

UTDRL_BTTask_FindRandomReachable::UTDRL_BTTask_FindRandomReachable()
	: Super()
{
	NodeName = "Find Random Reachable Location";

	TargetOrigin.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UTDRL_BTTask_FindRandomReachable, TargetOrigin),
	                             AActor::StaticClass());
	TargetOrigin.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UTDRL_BTTask_FindRandomReachable, TargetOrigin));
	TargetOrigin.AllowNoneAsValue(true);

	TargetKeyVector.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UTDRL_BTTask_FindRandomReachable, TargetKeyVector));
}

EBTNodeResult::Type UTDRL_BTTask_FindRandomReachable::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	FVector Origin = FVector();

	if (!OwnerComp.GetBlackboardComponent()->IsVectorValueSet(TargetOrigin.SelectedKeyName) && !OwnerComp.
		GetBlackboardComponent()->GetValueAsObject(TargetOrigin.SelectedKeyName))
	{
		const APawn* MyPawn = OwnerComp.GetAIOwner()->GetPawn();

		if (!MyPawn)
		{
			return EBTNodeResult::Failed;
		}

		Origin = MyPawn->GetActorLocation();
	}
	else
	{
		if (OwnerComp.GetBlackboardComponent()->IsVectorValueSet(TargetOrigin.SelectedKeyName))
		{
			Origin = OwnerComp.GetBlackboardComponent()->GetValueAsVector(TargetOrigin.SelectedKeyName);
		}
		else
		{
			AActor* TargetActor = Cast<AActor>(
				OwnerComp.GetBlackboardComponent()->GetValueAsObject(TargetOrigin.SelectedKeyName));

			if (!TargetActor)
			{
				return EBTNodeResult::Failed;
			}

			Origin = TargetActor->GetActorLocation();
		}
	}

	UNavigationSystemV1* NavSys = UNavigationSystemV1::GetCurrent(GetWorld());
	FNavLocation RandomPoint;

	if (!NavSys->GetRandomReachablePointInRadius(Origin, ReachRadius, RandomPoint))
	{
		return EBTNodeResult::Failed;
	}

	OwnerComp.GetBlackboardComponent()->SetValueAsVector(TargetKeyVector.SelectedKeyName, RandomPoint.Location);
	return EBTNodeResult::Succeeded;
}

FString UTDRL_BTTask_FindRandomReachable::GetStaticDescription() const
{
	return FString::Printf(
		TEXT("Target Origin Key Is: %s%sTarget Location Key Is: %s%sRadius: %s"),
		*TargetOrigin.SelectedKeyName.ToString(), LINE_TERMINATOR, *TargetKeyVector.SelectedKeyName.ToString(),
		LINE_TERMINATOR, *FString::SanitizeFloat(ReachRadius));
}
