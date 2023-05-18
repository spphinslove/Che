// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_BFL_AI.h"
#include "BehaviorTree/BlackboardComponent.h"

void UTDRL_BFL_AI::ExecuteAIToTDRLExecuteAI(UObject* WorldContextObject, AAIController* ControllerIn, APawn* PawnIn,
                                            ATDRL_NPCController* & ControllerOut, ATDRL_Character* & CharacterOut)
{
	ControllerOut = Cast<ATDRL_NPCController>(ControllerIn);
	CharacterOut = Cast<ATDRL_Character>(PawnIn);
}

bool UTDRL_BFL_AI::GetLocationFromActorOrVectorFromBB(UObject* WorldContextObject, const UBlackboardComponent* BBComp,
                                                      const FBlackboardKeySelector KeySelector, FVector& OutLocation)
{
	const AActor* ActorRef = Cast<AActor>(BBComp->GetValueAsObject(KeySelector.SelectedKeyName));

	if (ActorRef)
	{
		OutLocation = ActorRef->GetActorLocation();
	}
	else
	{
		if (!BBComp->IsVectorValueSet(KeySelector.SelectedKeyName))
		{
			return false;
		}

		OutLocation = BBComp->GetValueAsVector(KeySelector.SelectedKeyName);
	}

	return true;
}
