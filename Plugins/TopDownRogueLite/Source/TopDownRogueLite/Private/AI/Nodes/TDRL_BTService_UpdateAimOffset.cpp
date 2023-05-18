// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_BTService_UpdateAimOffset.h"
#include "AIController.h"

#include "TDRL_Character.h"
#include "TDRL_BFL_AI.h"

#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "Kismet/KismetMathLibrary.h"
#include "..\..\..\Public\AI\Nodes\TDRL_BTService_UpdateAimOffset.h"

UTDRL_BTService_UpdateAimOffset::UTDRL_BTService_UpdateAimOffset()
	: Super()
{
	NodeName = "Update AnimOffset";

	bNotifyCeaseRelevant = true;
	bNotifyTick = true;

	AimOffsetTarget.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UTDRL_BTService_UpdateAimOffset, AimOffsetTarget),
	                                AActor::StaticClass());
	AimOffsetTarget.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UTDRL_BTService_UpdateAimOffset, AimOffsetTarget));
}

void UTDRL_BTService_UpdateAimOffset::OnCeaseRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::OnCeaseRelevant(OwnerComp, NodeMemory);

	ATDRL_Character* MyCharacter = Cast<ATDRL_Character>(OwnerComp.GetAIOwner()->GetPawn());
	if (MyCharacter)
	{
		MyCharacter->SetAimOffsetValue(FVector2D(0.0f));
	}
}

void UTDRL_BTService_UpdateAimOffset::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	ATDRL_Character* MyCharacter = Cast<ATDRL_Character>(OwnerComp.GetAIOwner()->GetPawn());
	FVector EndingPoint = FVector();
	if (!UTDRL_BFL_AI::GetLocationFromActorOrVectorFromBB(OwnerComp.GetAIOwner(), OwnerComp.GetBlackboardComponent(),
	                                                      AimOffsetTarget, EndingPoint))
	{
		MyCharacter->SetAimOffsetValue(FVector2D(0.0f));
		return;
	}

	const FRotator NewAimOffsetRot = UKismetMathLibrary::NormalizedDeltaRotator(
		UKismetMathLibrary::FindLookAtRotation(MyCharacter->GetActorLocation(), EndingPoint),
		MyCharacter->GetActorRotation());

	MyCharacter->SetAimOffsetValue(FVector2D(NewAimOffsetRot.Yaw, NewAimOffsetRot.Pitch));
}

FString UTDRL_BTService_UpdateAimOffset::GetStaticDescription() const
{
	return FString::Printf(
		TEXT("Actor Target Key: %s%sTick every: %ss - %ss"), *AimOffsetTarget.SelectedKeyName.ToString(),
		LINE_TERMINATOR, *FString::SanitizeFloat(FMath::Max(0.0f, Interval - RandomDeviation)),
		*FString::SanitizeFloat(Interval + RandomDeviation));
}
