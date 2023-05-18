// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_BTDecorator_ByChance.h"
#include "..\..\..\Public\AI\Nodes\TDRL_BTDecorator_ByChance.h"

UTDRL_BTDecorator_ByChance::UTDRL_BTDecorator_ByChance()
	: Super()
{
	NodeName = "By Chance";
}

bool UTDRL_BTDecorator_ByChance::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	if (Chances > FMath::RandRange(0, 99))
	{
		return true;
	}

	return false;
}

void UTDRL_BTDecorator_ByChance::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::OnBecomeRelevant(OwnerComp, NodeMemory);

	if (!CalculateRawConditionValue(OwnerComp, NodeMemory))
	{
		OwnerComp.RequestExecution(this);
	}
}

FString UTDRL_BTDecorator_ByChance::GetStaticDescription() const
{
	return FString::Printf(TEXT("%sChances: %i/100"), *Super::GetStaticDescription(), Chances);
}
