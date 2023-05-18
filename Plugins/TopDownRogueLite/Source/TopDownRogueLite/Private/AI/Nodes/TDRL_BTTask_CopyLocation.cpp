// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_BTTask_CopyLocation.h"
#include "TDRL_BFL_AI.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "..\..\..\Public\AI\Nodes\TDRL_BTTask_CopyLocation.h"

UTDRL_BTTask_CopyLocation::UTDRL_BTTask_CopyLocation()
	: Super()
{
	NodeName = "Copy BB Location";

	From.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UTDRL_BTTask_CopyLocation, From), AActor::StaticClass());
	From.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UTDRL_BTTask_CopyLocation, From));

	Target.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UTDRL_BTTask_CopyLocation, Target));
}

EBTNodeResult::Type UTDRL_BTTask_CopyLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	FVector TargetLocation = FVector();

	if (!UTDRL_BFL_AI::GetLocationFromActorOrVectorFromBB(OwnerComp.GetOwner(), OwnerComp.GetBlackboardComponent(),
	                                                      From, TargetLocation))
	{
		return EBTNodeResult::Aborted;
	}

	OwnerComp.GetBlackboardComponent()->SetValueAsVector(Target.SelectedKeyName, TargetLocation);
	return EBTNodeResult::Succeeded;
}

FString UTDRL_BTTask_CopyLocation::GetStaticDescription() const
{
	return FString::Printf(TEXT("From: %s%sTo: %s"), *From.SelectedKeyName.ToString(), LINE_TERMINATOR,
	                       *Target.SelectedKeyName.ToString());
}
