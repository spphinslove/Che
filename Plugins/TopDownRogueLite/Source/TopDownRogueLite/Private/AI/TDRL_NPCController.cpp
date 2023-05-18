// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_NPCController.h"
#include "TDRL_AISplineTool.h"

#include "Perception/AIPerceptionComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "TimerManager.h"

ATDRL_NPCController::ATDRL_NPCController()
	: Super()
{
	Perception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception"));
	SetPerceptionComponent(*Perception);
}

void ATDRL_NPCController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	PossessedTDRLCharacter = Cast<ATDRL_Character>(InPawn);
}

void ATDRL_NPCController::OnUnPossess()
{
	Super::OnUnPossess();
	PossessedTDRLCharacter = nullptr;
}

ATDRL_Character* ATDRL_NPCController::GetPossessedTDRLCharacter() const
{
	return PossessedTDRLCharacter;
}

#pragma region BlackboardValues

uint8 ATDRL_NPCController::GetAlertState() const
{
	if (!GetBlackboardComponent())
	{
		return 0;
	}

	return GetBlackboardComponent()->GetValueAsEnum(BBName_AlertState);
}

bool ATDRL_NPCController::SetAlertState(uint8 NewState)
{
	if (GetBlackboardComponent())
	{
		GetBlackboardComponent()->SetValueAsEnum(BBName_AlertState, NewState);
		return true;
	}

	return false;
}

uint8 ATDRL_NPCController::GetMobilityState() const
{
	return GetBlackboardComponent()->GetValueAsEnum(BBName_MobilityState);
}

bool ATDRL_NPCController::SetMobilityState(uint8 NewState)
{
	if (GetBlackboardComponent())
	{
		GetBlackboardComponent()->SetValueAsEnum(BBName_MobilityState, NewState);
		return true;
	}

	return false;
}

AActor* ATDRL_NPCController::GetPatrolTarget() const
{
	return Cast<AActor>(GetBlackboardComponent()->GetValueAsObject(BBName_PatrolTarget));
}

bool ATDRL_NPCController::SetPatrolTarget(AActor* ActorToFollow)
{
	if (GetBlackboardComponent())
	{
		GetBlackboardComponent()->SetValueAsObject(BBName_PatrolTarget, ActorToFollow);
		return true;
	}

	return false;
}

AActor* ATDRL_NPCController::GetAlertThreat() const
{
	if (!GetBlackboardComponent())
	{
		return nullptr;
	}

	return Cast<AActor>(GetBlackboardComponent()->GetValueAsObject(BBName_AlertThreat));
}

bool ATDRL_NPCController::SetAlertThreat(AActor* AlertThreat)
{
	if (GetBlackboardComponent())
	{
		GetBlackboardComponent()->SetValueAsObject(BBName_AlertThreat, AlertThreat);
		return true;
	}

	return false;
}

bool ATDRL_NPCController::GetUseRandomAISplineToolPoints() const
{
	if (GetBlackboardComponent())
	{
		return GetBlackboardComponent()->GetValueAsBool(BBName_AISplineToolRandomPoints);
	}
	return false;
}

bool ATDRL_NPCController::SetUseRandomAISplineToolPoints(const bool NewValue)
{
	if (GetBlackboardComponent())
	{
		GetBlackboardComponent()->SetValueAsBool(BBName_AISplineToolRandomPoints, NewValue);
		return true;
	}
	return false;
}

uint8 ATDRL_NPCController::ModifyAlertLevel(const int32 DeltaLevel, const int32 MaxAlertStateIndex)
{
	if (DeltaLevel == 0)
	{
		return GetAlertState();
	}

	return SetAlertState(FMath::Min(FMath::Max(GetAlertState() + DeltaLevel, 0), FMath::Max(MaxAlertStateIndex, 0)));
}

void ATDRL_NPCController::ReduceAlertLevelWithTimer()
{
	if (AlertReductionTimerHandle.IsValid())
	{
		AlertReductionTimerHandle.Invalidate();
	}

	const uint8 CurrentState = GetAlertState();
	if (CurrentState == 0)
	{
		return;
	}

	const uint8 NewState = CurrentState - 1;
	SetAlertState(NewState);

	if (NewState > 0)
	{
		EnableReduceAlertLevelWithTimer(true);
	}
}

bool ATDRL_NPCController::EnableReduceAlertLevelWithTimer(const bool Enabled)
{
	if (Enabled)
	{
		/*if (AlertReductionTimerHandle.IsValid()) {
			return true;
		}*/

		if (GetAlertState() > 0)
		{
			const float CDelay = TimeForEachAlarmLevel.Num() >= GetAlertState()
				                     ? TimeForEachAlarmLevel[GetAlertState() - 1]
				                     : FMath::Max(DefaultTimeForEachAlarmLevel, 0.01f);

			if (CDelay > 0.0f)
			{
				GetWorld()->GetTimerManager().SetTimer(AlertReductionTimerHandle, this,
				                                       &ATDRL_NPCController::ReduceAlertLevelWithTimer, CDelay, false);
				return true;
			}
		}
	}

	if (AlertReductionTimerHandle.IsValid() && !Enabled)
	{
		GetWorld()->GetTimerManager().ClearTimer(AlertReductionTimerHandle);
		AlertReductionTimerHandle.Invalidate();
	}

	return false;
}

#pragma endregion

bool ATDRL_NPCController::RefreshReduceAlertLevelWithTimer()
{
	if (AlertReductionTimerHandle.IsValid())
	{
		GetWorld()->GetTimerManager().ClearTimer(AlertReductionTimerHandle);
		AlertReductionTimerHandle.Invalidate();

		return EnableReduceAlertLevelWithTimer(true);
	}

	return false;
}
