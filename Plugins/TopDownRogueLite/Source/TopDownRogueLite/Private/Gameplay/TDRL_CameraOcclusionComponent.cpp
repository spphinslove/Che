// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_CameraOcclusionComponent.h"

#include "Engine/StaticMeshActor.h"

// Sets default values for this component's properties
UTDRL_CameraOcclusionComponent::UTDRL_CameraOcclusionComponent()
	: Super()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	// ...
}


// Called when the game starts
void UTDRL_CameraOcclusionComponent::BeginPlay()
{
	Super::BeginPlay();

	if (GetOwner()->GetClass() == AStaticMeshActor::StaticClass())
	{
		AStaticMeshActor* CStaticMeshActor = Cast<AStaticMeshActor>(GetOwner());
		if (CStaticMeshActor)
		{
			AddAffectedComponent((UPrimitiveComponent*)CStaticMeshActor->GetRootComponent());
			OnOcclusionChanged.AddDynamic(this, &UTDRL_CameraOcclusionComponent::DefaultOcclusionEvent);
		}
	}
}

void UTDRL_CameraOcclusionComponent::SetOcclusionEnabled(const bool Enabled)
{
	for (int32 Idx = 0; Idx < AffectedComponents.Num(); Idx++)
	{
		if (AffectedComponents[Idx])
		{
			TArray<USceneComponent*> TotalComps = TArray<USceneComponent*>{AffectedComponents[Idx]};
			TotalComps.Append(AffectedComponents[Idx]->GetAttachChildren());

			OnOcclusionChanged.Broadcast(Enabled, TotalComps);
		}
	}
}

void UTDRL_CameraOcclusionComponent::DefaultOcclusionEvent(const bool Occluded,
                                                           TArray<class USceneComponent*> OcclusionComps)
{
	for (auto& CComp : OcclusionComps)
	{
		UPrimitiveComponent* CurPrim = Cast<UPrimitiveComponent>(CComp);

		if (CurPrim)
		{
			CurPrim->SetVisibility(!Occluded);
			CurPrim->bCastHiddenShadow = Occluded;
			CurPrim->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility,
			                                       (Occluded)
				                                       ? ECollisionResponse::ECR_Ignore
				                                       : ECollisionResponse::ECR_Block);
		}
	}
}
