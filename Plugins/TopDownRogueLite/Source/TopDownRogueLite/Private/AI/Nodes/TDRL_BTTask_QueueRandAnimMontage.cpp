// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_BTTask_QueueRandAnimMontage.h"
#include "TDRL_NPCController.h"

#include "BehaviorTree/BlackboardComponent.h"

UTDRL_BTTask_QueueRandAnimMontage::UTDRL_BTTask_QueueRandAnimMontage()
	: Super()
{
	NodeName = "Queue Random AnimMontage to BB";

	QueueAnimKey.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UTDRL_BTTask_QueueRandAnimMontage, QueueAnimKey),
	                             UAnimMontage::StaticClass());
}

EBTNodeResult::Type UTDRL_BTTask_QueueRandAnimMontage::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	/*if (!QueueAnimKey.IsSet()) {
		return EBTNodeResult::Failed;
	}*/

	ATDRL_NPCController* ControllerPtr = Cast<ATDRL_NPCController>(OwnerComp.GetAIOwner());

	if (!ControllerPtr)
	{
		return EBTNodeResult::Failed;
	}

	UAnimMontage* PickMontage = nullptr;

	if (bUseCustomContainer)
	{
		if (!CustomAnimMontageContainer)
		{
			return EBTNodeResult::Failed;
		}

		UAIAnimMontageContainer* ContainerInstance = Cast<UAIAnimMontageContainer>(
			CustomAnimMontageContainer.Get()->GetDefaultObject());

		if (!ContainerInstance || !ContainerInstance->bHasValues())
		{
			return EBTNodeResult::Failed;
		}

		PickMontage = ContainerInstance->GetRandomAnimationMontage();
	}
	else
	{
		PickMontage = ControllerPtr->GetRandomMontageFromGroup(GroupName);
	}

	if (!PickMontage)
	{
		return EBTNodeResult::Failed;
	}

	OwnerComp.GetBlackboardComponent()->SetValueAsObject(QueueAnimKey.SelectedKeyName, PickMontage);


	return EBTNodeResult::Succeeded;
}

FString UTDRL_BTTask_QueueRandAnimMontage::GetStaticDescription() const
{
	if (bUseCustomContainer)
	{
		if (CustomAnimMontageContainer)
		{
			return FString::Printf(
				TEXT("CustomAnimMontageContainer: %s"), *CustomAnimMontageContainer.Get()->GetFName().ToString());
		}
		else
		{
			return FString::Printf(TEXT("CustomAnimMontageContainer: Invalid"), *Super::GetStaticDescription());
		}
	}

	return FString::Printf(TEXT("Target Key Is: %s%sGroup: %s"), *QueueAnimKey.SelectedKeyName.ToString(),
	                       LINE_TERMINATOR, *GroupName.ToString());
}
