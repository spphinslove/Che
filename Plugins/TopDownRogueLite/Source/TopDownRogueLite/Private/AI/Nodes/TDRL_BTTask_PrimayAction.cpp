// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_BTTask_PrimayAction.h"
#include "TDRL_Character.h"

#include "AIController.h"
#include "TimerManager.h"

UTDRL_BTTask_PrimayAction::UTDRL_BTTask_PrimayAction()
	: Super()
{
	NodeName = "Enable Primary Action";
}

EBTNodeResult::Type UTDRL_BTTask_PrimayAction::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	ATDRL_Character* CharRef = Cast<ATDRL_Character>(OwnerComp.GetAIOwner()->GetPawn());

	if (!CharRef)
	{
		return EBTNodeResult::Aborted;
	}

	CharRef->PerformPrimaryAction(Enable);

	if (StopAfter <= 0.0f || !Enable)
	{
		return EBTNodeResult::Succeeded;
	}
	else
	{
		FTimerHandle EndHandle;
		GetWorld()->GetTimerManager().SetTimer(
			EndHandle, FTimerDelegate::CreateUObject(this, &UTDRL_BTTask_PrimayAction::EndAttackTimer, &OwnerComp),
			StopAfter, false);
		return EBTNodeResult::InProgress;
	}
}

EBTNodeResult::Type UTDRL_BTTask_PrimayAction::AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (StopAfter > 0.0f)
	{
		GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
		ATDRL_Character* CharRef = Cast<ATDRL_Character>(OwnerComp.GetAIOwner()->GetPawn());

		if (CharRef)
		{
			CharRef->PerformPrimaryAction(false);
		}
	}

	return EBTNodeResult::Succeeded;
}

FString UTDRL_BTTask_PrimayAction::GetStaticDescription() const
{
	if (Enable)
	{
		if (StopAfter > 0.0f)
		{
			return FString::Printf(TEXT("Enable%sStop After: %s"), LINE_TERMINATOR, *FString::SanitizeFloat(StopAfter));
		}
		else
		{
			return FString::Printf(TEXT("Enable%sNever Stop"), LINE_TERMINATOR);
		}
	}

	return FString::Printf(TEXT("Disable"));
}

void UTDRL_BTTask_PrimayAction::EndAttackTimer(UBehaviorTreeComponent* OwnerComp)
{
	ATDRL_Character* CharRef = Cast<ATDRL_Character>(OwnerComp->GetAIOwner()->GetPawn());

	if (CharRef)
	{
		CharRef->PerformPrimaryAction(false);
	}

	FinishLatentTask(*OwnerComp, EBTNodeResult::Succeeded);
}
