// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_BTService_WalkOnDistance.h"
#include "AIController.h"

#include "TDRL_Character.h"
#include "TDRL_BFL_AI.h"
#include "..\..\..\Public\AI\Nodes\TDRL_BTService_WalkOnDistance.h"

UTDRL_BTService_WalkOnDistance::UTDRL_BTService_WalkOnDistance()
	: Super()
{
	NodeName = "Start Walking on Distance";

	bNotifyCeaseRelevant = true;
	bNotifyTick = true;

	Target.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UTDRL_BTService_WalkOnDistance, Target),
	                       AActor::StaticClass());
	Target.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UTDRL_BTService_WalkOnDistance, Target));
}

void UTDRL_BTService_WalkOnDistance::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	ATDRL_Character* CharRef = Cast<ATDRL_Character>(OwnerComp.GetAIOwner()->GetPawn());

	if (!CharRef)
	{
		return;
	}

	FVector TargetLocation = FVector();
	if (!UTDRL_BFL_AI::GetLocationFromActorOrVectorFromBB(CharRef, OwnerComp.GetBlackboardComponent(), Target,
	                                                      TargetLocation))
	{
		return;
	}

	const float CDist = FVector::Dist(TargetLocation, CharRef->GetActorLocation());

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

	CharRef->Input_AlternativeWalk(OutResult);
}

void UTDRL_BTService_WalkOnDistance::OnCeaseRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ATDRL_Character* CharRef = Cast<ATDRL_Character>(OwnerComp.GetAIOwner()->GetPawn());

	if (bRestoreWhenFinish && CharRef)
	{
		CharRef->Input_AlternativeWalk(false);
	}
}

FString UTDRL_BTService_WalkOnDistance::GetStaticDescription() const
{
	FString StrMethod = "none";

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

	if (RandomDeviation == 0.0f)
	{
		return FString::Printf(
			TEXT("Location Key: %s%sMethod: %s%sDistance: %s%sRestore when finish: %s%sTick every: %ss"),
			*Target.SelectedKeyName.ToString(), LINE_TERMINATOR, *StrMethod, LINE_TERMINATOR,
			*FString::SanitizeFloat(Distance), LINE_TERMINATOR,
			(bRestoreWhenFinish) ? *FString("true") : *FString("false"), LINE_TERMINATOR,
			*FString::SanitizeFloat(Interval));
	}

	return FString::Printf(
		TEXT("Location Key: %s%sMethod: %s%sDistance: %s%sRestore when finish: %s%sTick every: %ss - %ss"),
		*Target.SelectedKeyName.ToString(), LINE_TERMINATOR, *StrMethod, LINE_TERMINATOR,
		*FString::SanitizeFloat(Distance), LINE_TERMINATOR, (bRestoreWhenFinish) ? *FString("true") : *FString("false"),
		LINE_TERMINATOR, *FString::SanitizeFloat(FMath::Max(0.0f, Interval - RandomDeviation)),
		*FString::SanitizeFloat(Interval + RandomDeviation));
}
