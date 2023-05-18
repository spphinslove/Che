// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_BTTask_PlayAnimMontage.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "GameFramework/Character.h"

#include "TimerManager.h"

UTDRL_BTTask_PlayAnimMontage::UTDRL_BTTask_PlayAnimMontage()
	: Super()
{
	NodeName = "Play AnimMontage";

	AnimMontage.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UTDRL_BTTask_PlayAnimMontage, AnimMontage),
	                            UAnimMontage::StaticClass());
}

EBTNodeResult::Type UTDRL_BTTask_PlayAnimMontage::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	UAnimMontage* MontageToPlay = nullptr;
	if (bUseAnimMontageAsset)
	{
		if (!AnimMontageAsset)
		{
			return EBTNodeResult::Failed;
		}

		MontageToPlay = AnimMontageAsset;
	}
	else
	{
		MontageToPlay = Cast<UAnimMontage>(
			OwnerComp.GetBlackboardComponent()->GetValueAsObject(AnimMontage.SelectedKeyName));

		if (!MontageToPlay)
		{
			return EBTNodeResult::Failed;
		}
	}

	OwnerComp.GetAIOwner()->GetCharacter()->PlayAnimMontage(MontageToPlay, AnimPlayRate, FName());

	FTimerDelegate TimerDel;
	TimerDel.BindUFunction(this, FName("AnimIsOver"), &OwnerComp);
	GetWorld()->GetTimerManager().SetTimer(AnimEndHandle, TimerDel, MontageToPlay->GetPlayLength() / AnimPlayRate,
	                                       false);

	return EBTNodeResult::InProgress;
}

EBTNodeResult::Type UTDRL_BTTask_PlayAnimMontage::AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::AbortTask(OwnerComp, NodeMemory);

	if (bStopMontageOnAbort)
	{
		if (OwnerComp.GetAIOwner())
			if (OwnerComp.GetAIOwner()->GetCharacter())
				OwnerComp.GetAIOwner()->GetCharacter()->StopAnimMontage();
	}

	if (bClearBBValue)
	{
		OwnerComp.GetBlackboardComponent()->ClearValue(AnimMontage.GetSelectedKeyID());
	}

	return EBTNodeResult::Succeeded;
}

FString UTDRL_BTTask_PlayAnimMontage::GetStaticDescription() const
{
	if (bUseAnimMontageAsset)
	{
		FString CurAssetName;
		if (AnimMontageAsset)
		{
			CurAssetName = AnimMontageAsset->GetFName().ToString();
		}
		else
		{
			CurAssetName = "Invalid";
		}

		return FString::Printf(
			TEXT("Asset Is: %s%sAnimPlayRate: %s%sStopMontageOnAbort: %s"), *CurAssetName, LINE_TERMINATOR,
			*FString::SanitizeFloat(AnimPlayRate), LINE_TERMINATOR,
			(bStopMontageOnAbort) ? *FString("true") : *FString("false"));
	}

	return FString::Printf(
		TEXT("Asset Key Is: %s%sAnimPlayRate: %s%sStopMontageOnAbort: %s"), *AnimMontage.SelectedKeyName.ToString(),
		LINE_TERMINATOR, *FString::SanitizeFloat(AnimPlayRate), LINE_TERMINATOR,
		(bStopMontageOnAbort) ? *FString("true") : *FString("false"));
}

void UTDRL_BTTask_PlayAnimMontage::AnimIsOver(UBehaviorTreeComponent* OwnerComp)
{
	if (bClearBBValue)
	{
		OwnerComp->GetBlackboardComponent()->ClearValue(AnimMontage.GetSelectedKeyID());
	}

	return FinishLatentTask(*OwnerComp, EBTNodeResult::Succeeded);
}
