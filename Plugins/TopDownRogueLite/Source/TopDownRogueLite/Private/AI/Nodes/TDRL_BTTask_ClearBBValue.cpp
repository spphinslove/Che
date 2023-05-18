// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_BTTask_ClearBBValue.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "..\..\..\Public\AI\Nodes\TDRL_BTTask_ClearBBValue.h"

UTDRL_BTTask_ClearBBValue::UTDRL_BTTask_ClearBBValue()
	: Super()
{
	NodeName = "Clear BB Value";

	bNotifyTick = false;
}

EBTNodeResult::Type UTDRL_BTTask_ClearBBValue::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	OwnerComp.GetBlackboardComponent()->ClearValue(BBEntry.SelectedKeyName);

	return EBTNodeResult::Succeeded;
}

FString UTDRL_BTTask_ClearBBValue::GetStaticDescription() const
{
	return FString::Printf(TEXT("Clear Target Key Is: %s"), *BBEntry.SelectedKeyName.ToString());
}
