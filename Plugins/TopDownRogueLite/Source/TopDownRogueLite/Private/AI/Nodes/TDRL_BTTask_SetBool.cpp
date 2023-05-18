// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_BTTask_SetBool.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "..\..\..\Public\AI\Nodes\TDRL_BTTask_SetBool.h"

UTDRL_BTTask_SetBool::UTDRL_BTTask_SetBool()
	: Super()
{
	NodeName = "Set BB Bool";

	BBBool.AddBoolFilter(this, GET_MEMBER_NAME_CHECKED(UTDRL_BTTask_SetBool, BBBool));
}

EBTNodeResult::Type UTDRL_BTTask_SetBool::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	OwnerComp.GetBlackboardComponent()->SetValueAsBool(BBBool.SelectedKeyName, NewValue);
	return EBTNodeResult::Succeeded;
}

FString UTDRL_BTTask_SetBool::GetStaticDescription() const
{
	return FString::Printf(TEXT("Bool Key Is: %s%sNew value: %s"), *BBBool.SelectedKeyName.ToString(), LINE_TERMINATOR,
	                       (NewValue) ? *FString("true") : *FString("false"));
}
