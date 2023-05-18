// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_BTTask_RotateTowardsRandom.h"
#include "AIController.h"
#include "Kismet/KismetSystemLibrary.h"

#include "..\..\..\Public\AI\Nodes\TDRL_BTTask_RotateTowardsRandom.h"

UTDRL_BTTask_RotateTowardsRandom::UTDRL_BTTask_RotateTowardsRandom()
	: Super()
{
	NodeName = "Rotate Toward Random";

	bNotifyTick = true;
}

EBTNodeResult::Type UTDRL_BTTask_RotateTowardsRandom::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (!OwnerComp.GetAIOwner())
	{
		return EBTNodeResult::Aborted;
	}
	else
	{
		if (!OwnerComp.GetAIOwner()->GetPawn())
		{
			return EBTNodeResult::Aborted;
		}
	}

	const float CYaw = bUseExactAngle ? ExactAngle : FMath::RandRange(ClampRandomAngle.X, ClampRandomAngle.Y);;
	switch (Method)
	{
	case ERandRotDirection::RRD_None:
		return EBTNodeResult::Succeeded;
	case ERandRotDirection::RRD_Right:
		TargetRotation = FRotator(0.0f, CYaw, 0.0f) + OwnerComp.GetAIOwner()->GetControlRotation();
		break;
	case ERandRotDirection::RRD_Left:
		TargetRotation = FRotator(0.0f, -CYaw, 0.0f) + OwnerComp.GetAIOwner()->GetControlRotation();
		break;
	case ERandRotDirection::RRD_Random:
		TargetRotation = FRotator(0.0f, CYaw * (FMath::RandBool() ? 1 : -1), 0.0f) + OwnerComp.GetAIOwner()->
			GetControlRotation();
		break;
	}

	TargetRotation = TargetRotation.GetNormalized();

	return EBTNodeResult::InProgress;
}

void UTDRL_BTTask_RotateTowardsRandom::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory,
                                                float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	const FRotator CurContRot = OwnerComp.GetAIOwner()->GetControlRotation();
	if (CurContRot.Equals(TargetRotation, 1.0f))
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	}

	OwnerComp.GetAIOwner()->SetControlRotation(
		FMath::RInterpTo(CurContRot, TargetRotation, DeltaSeconds, RotationSpeed));
}

FString UTDRL_BTTask_RotateTowardsRandom::GetStaticDescription() const
{
	FString SMethod = FString();

	switch (Method)
	{
	case ERandRotDirection::RRD_None:
		SMethod = FString("None");
		break;
	case ERandRotDirection::RRD_Right:
		SMethod = FString("Right");
		break;
	case ERandRotDirection::RRD_Left:
		SMethod = FString("Left");
		break;
	case ERandRotDirection::RRD_Random:
		SMethod = FString("Random");;
		break;
	}

	if (bUseExactAngle)
	{
		return FString::Printf(TEXT("Rotate: %s%sSpeed: %s%sAngle: %s"), *SMethod, LINE_TERMINATOR,
		                       *FString::SanitizeFloat(RotationSpeed), LINE_TERMINATOR,
		                       *FString::SanitizeFloat(ExactAngle));
	}

	return FString::Printf(
		TEXT("Rotate: %s%sSpeed: %s%sAngle Range - From: %s To: %s"), *SMethod, LINE_TERMINATOR,
		*FString::SanitizeFloat(RotationSpeed), LINE_TERMINATOR, *FString::SanitizeFloat(ClampRandomAngle.X),
		*FString::SanitizeFloat(ClampRandomAngle.Y));
}
