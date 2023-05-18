// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_BTDecorator_IsFacing.h"
#include "TDRL_BFL_AI.h"

#include "AIController.h"
#include "Kismet/KismetMathLibrary.h"

UTDRL_BTDecorator_IsFacing::UTDRL_BTDecorator_IsFacing()
	: Super()
{
	NodeName = "Is Facing";

	bAllowAbortChildNodes = true;
	bNotifyTick = true;
	bTickIntervals = true;
	bNotifyBecomeRelevant = true;

	TargetToFace.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UTDRL_BTDecorator_IsFacing, TargetToFace),
	                             AActor::StaticClass());
	TargetToFace.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UTDRL_BTDecorator_IsFacing, TargetToFace));
}

bool UTDRL_BTDecorator_IsFacing::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	const FVector PawnFrw = OwnerComp.GetAIOwner()->GetPawn()->GetActorForwardVector().GetSafeNormal();
	FVector TargetDir = FVector();

	if (!bUseAbsoluteWorldRotation)
	{
		FVector TargetLoc = FVector();
		if (!UTDRL_BFL_AI::GetLocationFromActorOrVectorFromBB(OwnerComp.GetOwner(), OwnerComp.GetBlackboardComponent(),
		                                                      TargetToFace, TargetLoc))
		{
			return true;
		}

		TargetDir = UKismetMathLibrary::GetDirectionUnitVector(OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation(),
		                                                       TargetLoc).GetSafeNormal();
	}
	else
	{
		TargetDir = AbsWorldRotation.Vector().GetSafeNormal();
	}

	return UKismetMathLibrary::MapRangeClamped(PawnFrw.Dot(TargetDir), 1.0f, -1.0f, 0.0f, 180.0f) <
		FMath::Abs(Tollerance);
}

void UTDRL_BTDecorator_IsFacing::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
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

void UTDRL_BTDecorator_IsFacing::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
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

FString UTDRL_BTDecorator_IsFacing::GetStaticDescription() const
{
	if (bUseAbsoluteWorldRotation)
	{
		if (TickCheckInterval > 0.0f)
		{
			return FString::Printf(
				TEXT("%sWorld Rotation: %s%sTollerance: %s%sTick every: %ss"), *Super::GetStaticDescription(),
				*AbsWorldRotation.ToString(), LINE_TERMINATOR, *FString::SanitizeFloat(Tollerance), LINE_TERMINATOR,
				*FString::SanitizeFloat(TickCheckInterval));
		}
		else
		{
			return FString::Printf(
				TEXT("%sWorld Rotation: %s%sTollerance: %s"), *Super::GetStaticDescription(),
				*AbsWorldRotation.ToString(), LINE_TERMINATOR, *FString::SanitizeFloat(Tollerance));
		}
	}

	if (TickCheckInterval > 0.0f)
	{
		return FString::Printf(
			TEXT("%sTarget Rotation Key: %s%sTollerance: %s%sTick every: %ss"), *Super::GetStaticDescription(),
			*TargetToFace.SelectedKeyName.ToString(), LINE_TERMINATOR, *FString::SanitizeFloat(Tollerance),
			LINE_TERMINATOR, *FString::SanitizeFloat(TickCheckInterval));
	}

	return FString::Printf(
		TEXT("%sTarget Rotation Key: %s%sTollerance: %s"), *Super::GetStaticDescription(),
		*TargetToFace.SelectedKeyName.ToString(), LINE_TERMINATOR, *FString::SanitizeFloat(Tollerance));
}
