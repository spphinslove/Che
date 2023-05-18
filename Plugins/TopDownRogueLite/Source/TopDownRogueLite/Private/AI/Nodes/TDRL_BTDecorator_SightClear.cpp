// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_BTDecorator_SightClear.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "DrawDebugHelpers.h"

UTDRL_BTDecorator_SightClear::UTDRL_BTDecorator_SightClear()
	: Super()
{
	NodeName = "Is Sight Clear";

	bAllowAbortChildNodes = true;
	bNotifyTick = true;
	bTickIntervals = true;
	bNotifyBecomeRelevant = true;

	CachedBool.AddBoolFilter(this, GET_MEMBER_NAME_CHECKED(UTDRL_BTDecorator_SightClear, CachedBool));
	CachedBool.AllowNoneAsValue(true);

	Target.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UTDRL_BTDecorator_SightClear, Target), AActor::StaticClass());
	Target.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UTDRL_BTDecorator_SightClear, Target),
	                       USceneComponent::StaticClass());
	Target.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UTDRL_BTDecorator_SightClear, Target));
}

bool UTDRL_BTDecorator_SightClear::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp,
                                                              uint8* NodeMemory) const
{
	bool OutValue = false;
	FHitResult OutHit = FHitResult();
	FCollisionQueryParams TraceParam;
	TraceParam.AddIgnoredActor(OwnerComp.GetAIOwner()->GetPawn());
	TArray<AActor*> IgnoreActors = TArray<AActor*>{OwnerComp.GetAIOwner()->GetPawn()};
	OwnerComp.GetAIOwner()->GetPawn()->GetAttachedActors(IgnoreActors, false, true);
	TraceParam.AddIgnoredActors(IgnoreActors);
	const FVector PawnLoc = OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation();
	FVector TargetLocation = PawnLoc;

	if (OwnerComp.GetBlackboardComponent()->IsVectorValueSet(Target.SelectedKeyName))
	{
		TargetLocation = OwnerComp.GetBlackboardComponent()->GetValueAsVector(Target.SelectedKeyName);
		GetWorld()->SweepSingleByChannel(OutHit, PawnLoc, TargetLocation, FQuat::Identity,
		                                 ECollisionChannel::ECC_Visibility, FCollisionShape::MakeSphere(TraceRadius),
		                                 TraceParam);

		if (OutHit.bBlockingHit)
		{
			if (Tollerance > 0.0f)
			{
				if (FVector::Dist(PawnLoc, OutHit.Location) < Tollerance)
				{
					OutValue = true;
				}
			}
		}
		else
		{
			OutValue = true;
		}
	}
	else
	{
		USceneComponent* CSceneTarg = Cast<USceneComponent>(
			OwnerComp.GetBlackboardComponent()->GetValueAsObject(Target.SelectedKeyName));

		if (!CSceneTarg)
		{
			const AActor* CActorTarg = Cast<AActor>(
				OwnerComp.GetBlackboardComponent()->GetValueAsObject(Target.SelectedKeyName));
			if (CActorTarg)
			{
				CSceneTarg = CActorTarg->GetRootComponent();
			}
		}

		// No target
		if (!CSceneTarg)
		{
			return false;
		}

		TargetLocation = CSceneTarg->GetComponentLocation();
		GetWorld()->SweepSingleByChannel(OutHit, PawnLoc, TargetLocation, FQuat::Identity,
		                                 ECollisionChannel::ECC_Visibility, FCollisionShape::MakeSphere(TraceRadius),
		                                 TraceParam);

		DrawDebugLine(GetWorld(), PawnLoc, TargetLocation, FColor::Purple, false, 0.25f);

		if (OutHit.bBlockingHit)
		{
			if (OutHit.GetActor() == CSceneTarg->GetOwner() || OutHit.GetActor()->IsAttachedTo(CSceneTarg->GetOwner()))
			{
				OutValue = true;
			}
			else
			{
				if (Tollerance > 0.0f)
				{
					if (FVector::Dist(PawnLoc, OutHit.Location) < Tollerance)
					{
						OutValue = true;
					}
				}
			}
		}
		else
		{
			OutValue = true;
		}
	}

	if (!CachedBool.IsNone())
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsBool(CachedBool.SelectedKeyName, OutValue);
	}

	return OutValue;
}

void UTDRL_BTDecorator_SightClear::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::OnBecomeRelevant(OwnerComp, NodeMemory);

	if (TickCheckInterval > 0.0f)
	{
		SetNextTickTime(NodeMemory, TickCheckInterval);
	}

	if (!CalculateRawConditionValue(OwnerComp, NodeMemory))
	{
		OwnerComp.RequestExecution(this);
	}
}

void UTDRL_BTDecorator_SightClear::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	if (TickCheckInterval > 0.0f)
	{
		SetNextTickTime(NodeMemory, TickCheckInterval);
	}

	if (!CalculateRawConditionValue(OwnerComp, NodeMemory))
	{
		OwnerComp.RequestExecution(this);
	}
}

FString UTDRL_BTDecorator_SightClear::GetStaticDescription() const
{
	if (TickCheckInterval > 0.0f)
	{
		return FString::Printf(
			TEXT("%sTarget Key: %s%sTraceRadius: %s%sTollerance: %s%sTick every: %ss"), *Super::GetStaticDescription(),
			*Target.SelectedKeyName.ToString(), LINE_TERMINATOR, *FString::SanitizeFloat(TraceRadius), LINE_TERMINATOR,
			*FString::SanitizeFloat(Tollerance), LINE_TERMINATOR, *FString::SanitizeFloat(TickCheckInterval));
	}

	return FString::Printf(
		TEXT("%sTarget Key: %s%sTraceRadius: %s%sTollerance: %s"), *Super::GetStaticDescription(),
		*Target.SelectedKeyName.ToString(), LINE_TERMINATOR, *FString::SanitizeFloat(TraceRadius), LINE_TERMINATOR,
		*FString::SanitizeFloat(Tollerance));
}
