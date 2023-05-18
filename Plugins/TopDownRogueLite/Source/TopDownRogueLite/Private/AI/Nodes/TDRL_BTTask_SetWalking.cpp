// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_BTTask_SetWalking.h"
#include "AIController.h"

#include "TDRL_Character.h"
#include "TDRL_CharacterMovementComponent.h"
#include "..\..\..\Public\AI\Nodes\TDRL_BTTask_SetWalking.h"

UTDRL_BTTask_SetWalking::UTDRL_BTTask_SetWalking()
	: Super()
{
	NodeName = "Enable Walking";

	ShouldWalk = false;
}

EBTNodeResult::Type UTDRL_BTTask_SetWalking::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	ATDRL_Character* CharRef = Cast<ATDRL_Character>(OwnerComp.GetAIOwner()->GetPawn());

	if (!CharRef)
	{
		return EBTNodeResult::Aborted;
	}

	CharRef->GetTDRLMovementComponent()->SetAlternativeWalk(ShouldWalk);

	return EBTNodeResult::Succeeded;
}

FString UTDRL_BTTask_SetWalking::GetStaticDescription() const
{
	return FString::Printf(TEXT("ShouldWalk: %s"), (ShouldWalk) ? *FString("true") : *FString("false"));
}
