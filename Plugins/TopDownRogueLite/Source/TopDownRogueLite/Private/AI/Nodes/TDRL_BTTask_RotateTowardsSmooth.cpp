// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_BTTask_RotateTowardsSmooth.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "Kismet/KismetMathLibrary.h"

UTDRL_BTTask_RotateTowardsSmooth::UTDRL_BTTask_RotateTowardsSmooth()
	: Super()
{
	NodeName = "Smoothly Rotate Towards";

	bNotifyTick = true;

	Target.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UTDRL_BTTask_RotateTowardsSmooth, Target),
	                       AActor::StaticClass());
	Target.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UTDRL_BTTask_RotateTowardsSmooth, Target));
}

EBTNodeResult::Type UTDRL_BTTask_RotateTowardsSmooth::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	FRotator FinalRotator = FRotator();

	if (bUseAbsoluteWorldRotation)
	{
		FinalRotator.Yaw = AbsWorldRotationYaw;
	}
	else
	{
		FVector TargetLoc = FVector();
		if (OwnerComp.GetBlackboardComponent()->IsVectorValueSet(Target.SelectedKeyName))
		{
			TargetLoc = OwnerComp.GetBlackboardComponent()->GetValueAsVector(Target.SelectedKeyName);
		}
		else
		{
			const AActor* ActorPtr = Cast<AActor>(
				OwnerComp.GetBlackboardComponent()->GetValueAsObject(Target.SelectedKeyName));
			if (!ActorPtr)
			{
				return EBTNodeResult::Failed;
			}

			TargetLoc = ActorPtr->GetActorLocation();
		}

		FinalRotator = UKismetMathLibrary::FindLookAtRotation(OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation(),
		                                                      TargetLoc).GetNormalized();
		FinalRotator = FRotator(0.0f, FinalRotator.Yaw, 0.0f);
	}

	TargetRotation = FinalRotator;
	return EBTNodeResult::InProgress;
}

void UTDRL_BTTask_RotateTowardsSmooth::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory,
                                                float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	OwnerComp.GetAIOwner()->SetControlRotation(FMath::RInterpTo(OwnerComp.GetAIOwner()->GetControlRotation(),
	                                                            TargetRotation, DeltaSeconds, RotationSpeed));

	if (OwnerComp.GetAIOwner()->GetControlRotation().Equals(TargetRotation, Tollerance))
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	}
}

FString UTDRL_BTTask_RotateTowardsSmooth::GetStaticDescription() const
{
	if (bUseAbsoluteWorldRotation)
	{
		return FString::Printf(
			TEXT("World Rotation: %s%sRotationSpeed: %s%sTollerance: %s"), *FString::SanitizeFloat(AbsWorldRotationYaw),
			LINE_TERMINATOR, *FString::SanitizeFloat(RotationSpeed), LINE_TERMINATOR,
			*FString::SanitizeFloat(Tollerance));
	}

	return FString::Printf(
		TEXT("Target is: %s%sRotationSpeed: %s%sTollerance: %s"), *Target.SelectedKeyName.ToString(), LINE_TERMINATOR,
		*FString::SanitizeFloat(RotationSpeed), LINE_TERMINATOR, *FString::SanitizeFloat(Tollerance));
}
