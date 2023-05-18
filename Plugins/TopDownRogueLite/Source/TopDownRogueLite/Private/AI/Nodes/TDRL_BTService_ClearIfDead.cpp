// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_BTService_ClearIfDead.h"
#include "TDRL_Character.h"
#include "BehaviorTree/BlackboardComponent.h"

UTDRL_BTService_ClearIfDead::UTDRL_BTService_ClearIfDead()
	: Super()
{
	NodeName = "Clear Blackboard Key if Dead";

	bNotifyTick = true;

	Target.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UTDRL_BTService_ClearIfDead, Target), AActor::StaticClass());
}

void UTDRL_BTService_ClearIfDead::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	if (OwnerComp.GetBlackboardComponent())
	{
		ATDRL_Character* CharPtr = Cast<ATDRL_Character>(
			OwnerComp.GetBlackboardComponent()->GetValueAsObject(Target.SelectedKeyName));
		if (CharPtr)
		{
			if (CharPtr->GetIsDead())
			{
				OwnerComp.GetBlackboardComponent()->ClearValue(Target.SelectedKeyName);
			}
		}
	}
}

FString UTDRL_BTService_ClearIfDead::GetStaticDescription() const
{
	return FString::Printf(TEXT("Actor Target Key: %s"), *Target.SelectedKeyName.ToString());
}
