// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_BTDecorator_DistBBEntries.h"
#include "TDRL_BFL_AI.h"

#include "AIController.h"
#include "..\..\..\Public\AI\Nodes\TDRL_BTDecorator_DistBBEntries.h"

UTDRL_BTDecorator_DistBBEntries::UTDRL_BTDecorator_DistBBEntries()
	: Super()
{
	NodeName = "Distance between BB Entries";

	bAllowAbortChildNodes = true;
	bNotifyTick = true;
	bTickIntervals = true;
	bNotifyBecomeRelevant = true;

	Target1.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UTDRL_BTDecorator_DistBBEntries, Target1),
	                        AActor::StaticClass());
	Target1.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UTDRL_BTDecorator_DistBBEntries, Target1));

	Target2.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UTDRL_BTDecorator_DistBBEntries, Target2),
	                        AActor::StaticClass());
	Target2.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UTDRL_BTDecorator_DistBBEntries, Target2));
}

bool UTDRL_BTDecorator_DistBBEntries::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp,
                                                                 uint8* NodeMemory) const
{
	FVector Loc1;
	if (!UTDRL_BFL_AI::GetLocationFromActorOrVectorFromBB(OwnerComp.GetAIOwner(), OwnerComp.GetBlackboardComponent(),
	                                                      Target1, Loc1))
	{
		return false;
	}
	FVector Loc2;
	if (!UTDRL_BFL_AI::GetLocationFromActorOrVectorFromBB(OwnerComp.GetAIOwner(), OwnerComp.GetBlackboardComponent(),
	                                                      Target2, Loc2))
	{
		return false;
	}

	const float CDist = FVector::Dist(Loc1, Loc2);

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

void UTDRL_BTDecorator_DistBBEntries::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::OnBecomeRelevant(OwnerComp, NodeMemory);

	if (!CalculateRawConditionValue(OwnerComp, NodeMemory))
	{
		OwnerComp.RequestExecution(this);
	}

	if (TickCheckInterval > 0.0f)
	{
		SetNextTickTime(NodeMemory, TickCheckInterval);
	}
}

void UTDRL_BTDecorator_DistBBEntries::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	if (!CalculateRawConditionValue(OwnerComp, NodeMemory))
	{
		OwnerComp.RequestExecution(this);
	}

	if (TickCheckInterval > 0.0f)
	{
		SetNextTickTime(NodeMemory, TickCheckInterval);
	}
}

FString UTDRL_BTDecorator_DistBBEntries::GetStaticDescription() const
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
			TEXT("%sTarget1: %s%sTarget2: %s%sMethod: %s%sDistance: %s%sTick every: %ss"),
			*Super::GetStaticDescription(), *Target1.SelectedKeyName.ToString(), LINE_TERMINATOR,
			*Target2.SelectedKeyName.ToString(), LINE_TERMINATOR, *StrMethod, LINE_TERMINATOR,
			*FString::SanitizeFloat(Distance), LINE_TERMINATOR, *FString::SanitizeFloat(TickCheckInterval));
	}

	return FString::Printf(
		TEXT("%sTarget1: %s%sTarget2: %s%sMethod: %s%sDistance: %s"), *Super::GetStaticDescription(),
		*Target1.SelectedKeyName.ToString(), LINE_TERMINATOR, *Target2.SelectedKeyName.ToString(), LINE_TERMINATOR,
		*StrMethod, LINE_TERMINATOR, *FString::SanitizeFloat(Distance));
}
