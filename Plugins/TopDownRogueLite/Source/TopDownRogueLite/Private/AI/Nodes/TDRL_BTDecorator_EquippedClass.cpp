// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_BTDecorator_EquippedClass.h"
#include "TDRL_Item.h"
#include "AIController.h"
#include "TDRL_Character.h"
#include "..\..\..\Public\AI\Nodes\TDRL_BTDecorator_EquippedClass.h"


UTDRL_BTDecorator_EquippedClass::UTDRL_BTDecorator_EquippedClass()
	: Super()
{
	NodeName = "Item Class is Equipped";

	bAllowAbortChildNodes = true;
	bNotifyBecomeRelevant = true;
	bNotifyTick = true;
	bTickIntervals = true;
}

bool UTDRL_BTDecorator_EquippedClass::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp,
                                                                 uint8* NodeMemory) const
{
	ATDRL_Character* CharPointer = Cast<ATDRL_Character>(OwnerComp.GetAIOwner()->GetPawn());

	if (!CharPointer)
	{
		return false;
	}

	if (!CharPointer->GetEquippedItem())
	{
		return false;
	}

	bool ReturnValue = CharPointer->GetEquippedItem()->GetClass() == ParentClass;
	if (!ReturnValue && bCanBeSubclass)
	{
		ReturnValue = CharPointer->GetEquippedItem()->GetClass()->IsChildOf(ParentClass);
	}

	return ReturnValue;
}

void UTDRL_BTDecorator_EquippedClass::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
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

void UTDRL_BTDecorator_EquippedClass::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
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

FString UTDRL_BTDecorator_EquippedClass::GetStaticDescription() const
{
	FString StrClass = "Invalid";
	if (ParentClass)
	{
		StrClass = ParentClass.Get()->GetFName().ToString();
	}

	if (TickCheckInterval > 0.0f)
	{
		return FString::Printf(
			TEXT("%sClass: %s%sCanBeSubclass: %s%sTick every: %ss"), *Super::GetStaticDescription(), *StrClass,
			LINE_TERMINATOR, (bCanBeSubclass) ? *FString("true") : *FString("false"), LINE_TERMINATOR,
			*FString::SanitizeFloat(TickCheckInterval));
	}

	return FString::Printf(TEXT("%sClass: %s%sCanBeSubclass: %s"), *Super::GetStaticDescription(), *StrClass,
	                       LINE_TERMINATOR, (bCanBeSubclass) ? *FString("true") : *FString("false"));
}
