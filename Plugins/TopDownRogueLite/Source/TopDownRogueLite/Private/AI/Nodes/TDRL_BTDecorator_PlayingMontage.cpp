// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_BTDecorator_PlayingMontage.h"
#include "AIController.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Character.h"
#include "..\..\..\Public\AI\Nodes\TDRL_BTDecorator_PlayingMontage.h"

UTDRL_BTDecorator_PlayingMontage::UTDRL_BTDecorator_PlayingMontage()
	: Super()
{
	NodeName = "Is Playing Montage";

	bAllowAbortChildNodes = true;
	bNotifyTick = true;
	bTickIntervals = true;
	bNotifyBecomeRelevant = true;

	BBMontage.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UTDRL_BTDecorator_PlayingMontage, BBMontage),
	                          UAnimMontage::StaticClass());
	BBMontage.AllowNoneAsValue(true);
}

bool UTDRL_BTDecorator_PlayingMontage::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp,
                                                                  uint8* NodeMemory) const
{
	const UAnimMontage* CurAnimMont = OwnerComp.GetAIOwner()->GetCharacter()->GetCurrentMontage();

	if (!CurAnimMont)
	{
		return false;
	}
	else
	{
		if (!bSelectMontage)
		{
			return true;
		}
	}

	// No filters return (any anim montage)
	const UAnimMontage* SelectedBBMont = Cast<UAnimMontage>(
		OwnerComp.GetBlackboardComponent()->GetValueAsObject(BBMontage.SelectedKeyName));
	if (SpecificMontages.Num() == 0 && !SelectedBBMont)
	{
		return true;
	}

	if (SpecificMontages.Contains(CurAnimMont) || CurAnimMont == SelectedBBMont)
	{
		return true;
	}

	return false;
}

void UTDRL_BTDecorator_PlayingMontage::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::OnBecomeRelevant(OwnerComp, NodeMemory);

	CalculateRawConditionValue(OwnerComp, NodeMemory);

	if (TickCheckInterval > 0.0f)
	{
		SetNextTickTime(NodeMemory, TickCheckInterval);
	}
}

void UTDRL_BTDecorator_PlayingMontage::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory,
                                                float DeltaSeconds)
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

FString UTDRL_BTDecorator_PlayingMontage::GetStaticDescription() const
{
	if (bSelectMontage)
	{
		if (TickCheckInterval > 0.0f)
		{
			return FString::Printf(
				TEXT("%sAnimMontage Key: %s%sAnimMontage List: %i%sTick every: %ss"), *Super::GetStaticDescription(),
				*BBMontage.SelectedKeyName.ToString(), LINE_TERMINATOR, SpecificMontages.Num(), LINE_TERMINATOR,
				*FString::SanitizeFloat(TickCheckInterval));
		}
		else
		{
			return FString::Printf(
				TEXT("%sAnimMontage Key: %s%sAnimMontage List: %i"), *Super::GetStaticDescription(),
				*BBMontage.SelectedKeyName.ToString(), LINE_TERMINATOR, SpecificMontages.Num());
		}
	}

	if (TickCheckInterval > 0.0f)
	{
		return FString::Printf(TEXT("%sAny Montage%sTick every: %ss"), *Super::GetStaticDescription(), LINE_TERMINATOR,
		                       *FString::SanitizeFloat(TickCheckInterval));
	}
	return FString::Printf(TEXT("%sAny Montage"), *Super::GetStaticDescription());
}
