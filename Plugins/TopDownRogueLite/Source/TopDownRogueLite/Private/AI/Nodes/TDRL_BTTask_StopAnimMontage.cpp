// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_BTTask_StopAnimMontage.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "GameFramework/Character.h"
#include "Animation/AnimMontage.h"
#include "..\..\..\Public\AI\Nodes\TDRL_BTTask_StopAnimMontage.h"

UTDRL_BTTask_StopAnimMontage::UTDRL_BTTask_StopAnimMontage()
	: Super()
{
	NodeName = "Stop AnimMontage";

	AnimKey.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UTDRL_BTTask_StopAnimMontage, AnimKey),
	                        UAnimMontage::StaticClass());
}

EBTNodeResult::Type UTDRL_BTTask_StopAnimMontage::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	ACharacter* CharPointer = OwnerComp.GetAIOwner()->GetCharacter();

	if (!CharPointer)
	{
		return EBTNodeResult::Failed;
	}

	if (!CharPointer->GetCurrentMontage())
	{
		return EBTNodeResult::Succeeded;

		if (bUseBlackboardKey && bClearBBValue)
		{
			OwnerComp.GetBlackboardComponent()->ClearValue(AnimKey.GetSelectedKeyID());
		}
	}

	UAnimMontage* MontageToStop = nullptr;

	if (bStopSpecificAnimMontage)
	{
		MontageToStop = AnimMontageAsset;
	}
	else
	{
		if (bUseBlackboardKey)
		{
			MontageToStop = Cast<UAnimMontage>(
				OwnerComp.GetBlackboardComponent()->GetValueAsObject(AnimKey.SelectedKeyName));

			if (!MontageToStop)
			{
				return EBTNodeResult::Failed;
			}
		}
	}

	CharPointer->StopAnimMontage(MontageToStop);

	if (bUseBlackboardKey && bClearBBValue)
	{
		OwnerComp.GetBlackboardComponent()->ClearValue(AnimKey.GetSelectedKeyID());
	}

	return EBTNodeResult::Succeeded;
}

FString UTDRL_BTTask_StopAnimMontage::GetStaticDescription() const
{
	if (bUseBlackboardKey)
	{
		return FString::Printf(TEXT("Anim Key Is: %s%sClearBBValue: %s"), *AnimKey.SelectedKeyName.ToString(),
		                       LINE_TERMINATOR, (bClearBBValue) ? *FString("true") : *FString("false"));
	}
	else
	{
		if (bStopSpecificAnimMontage)
		{
			FString MontageName = "Invalid";
			if (AnimMontageAsset)
			{
				return FString::Printf(TEXT("AnimMontage Is: %s"), *AnimMontageAsset->GetFName().ToString());
			}
		}
	}

	return FString::Printf(TEXT("Stop any AnimMontage"));
}
