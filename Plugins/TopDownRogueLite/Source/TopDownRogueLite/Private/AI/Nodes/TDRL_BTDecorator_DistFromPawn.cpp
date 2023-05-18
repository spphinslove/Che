// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_BTDecorator_DistFromPawn.h"
#include "AIController.h"
#include "NavigationSystemTypes.h"

#include "TDRL_BFL_AI.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "..\..\..\Public\AI\Nodes\TDRL_BTDecorator_DistFromPawn.h"

UTDRL_BTDecorator_DistFromPawn::UTDRL_BTDecorator_DistFromPawn()
	: Super()
{
	NodeName = "Distance from Pawn";

	bAllowAbortChildNodes = true;
	bNotifyTick = true;
	bTickIntervals = true;
	bTickIntervals = true;

	Target.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UTDRL_BTDecorator_DistFromPawn, Target),
	                       AActor::StaticClass());
	Target.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UTDRL_BTDecorator_DistFromPawn, Target));
}

bool UTDRL_BTDecorator_DistFromPawn::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp,
                                                                uint8* NodeMemory) const
{
	FVector TargetVector = FVector();
	if (!UTDRL_BFL_AI::GetLocationFromActorOrVectorFromBB(OwnerComp.GetAIOwner(), OwnerComp.GetBlackboardComponent(),
	                                                      Target, TargetVector))
	{
		return false;
	}

	const float CDist = FVector::Dist(OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation(), TargetVector);
	bool OutResult = false;

	switch (Method)
	{
	case EMathComparisonMethod::MCM_Equal:
		OutResult = CDist == Distance;
		break;
	case EMathComparisonMethod::MCM_Greater:
		OutResult = CDist > Distance;
		break;
	case EMathComparisonMethod::MCM_GreaterOrEqual:
		OutResult = CDist >= Distance;
		break;
	case EMathComparisonMethod::MCM_Less:
		OutResult = CDist < Distance;
		break;
	case EMathComparisonMethod::MCM_LessOrEqual:
		OutResult = CDist <= Distance;
		break;
	}

	return OutResult;
}

void UTDRL_BTDecorator_DistFromPawn::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::OnBecomeRelevant(OwnerComp, NodeMemory);

	CalculateRawConditionValue(OwnerComp, NodeMemory);

	if (TickCheckInterval > 0.0f)
	{
		SetNextTickTime(NodeMemory, TickCheckInterval);
	}
}

void UTDRL_BTDecorator_DistFromPawn::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	if (TickCheckInterval > 0.0f)
	{
		SetNextTickTime(NodeMemory, TickCheckInterval);
	}

	if (!CalculateRawConditionValue(OwnerComp, NodeMemory))
	{
		OwnerComp.RequestExecution(this);
	}
}

FString UTDRL_BTDecorator_DistFromPawn::GetStaticDescription() const
{
	FString StrMethod = "Invalid";

	switch (Method)
	{
	case EMathComparisonMethod::MCM_Equal:
		StrMethod = "Equal";
		break;
	case EMathComparisonMethod::MCM_Greater:
		StrMethod = "Greater";
		break;
	case EMathComparisonMethod::MCM_GreaterOrEqual:
		StrMethod = "Greater or Equal";
		break;
	case EMathComparisonMethod::MCM_Less:
		StrMethod = "Less";
		break;
	case EMathComparisonMethod::MCM_LessOrEqual:
		StrMethod = "Less or Equal";
		break;
	}

	if (TickCheckInterval > 0.0f)
	{
		return FString::Printf(
			TEXT("%sTarget: %s%sMethod: %s%sDistance: %s%sTick every: %ss"), *Super::GetStaticDescription(),
			*Target.SelectedKeyName.ToString(), LINE_TERMINATOR, *StrMethod, LINE_TERMINATOR,
			*FString::SanitizeFloat(Distance), LINE_TERMINATOR, *FString::SanitizeFloat(TickCheckInterval));
	}

	return FString::Printf(TEXT("%sTarget: %s%sMethod: %s%sDistance: %s"), *Super::GetStaticDescription(),
	                       *Target.SelectedKeyName.ToString(), LINE_TERMINATOR, *StrMethod, LINE_TERMINATOR,
	                       *FString::SanitizeFloat(Distance));
}
