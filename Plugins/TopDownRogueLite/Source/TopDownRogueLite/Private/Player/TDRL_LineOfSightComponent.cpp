// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_LineOfSightComponent.h"
#include "TDRL_Character.h"
#include "TDRL_BFL_Global.h"

#include "GameFramework/Pawn.h"
#include "Kismet/KismetRenderingLibrary.h"
#include "Kismet/KismetMaterialLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/CanvasRenderTarget2D.h"
#include "Engine/Canvas.h"
#include "Engine/StaticMeshActor.h"
#include "Animation/SkeletalMeshActor.h"
#include "Materials/MaterialInstanceDynamic.h"

#include "Interfaces/IPluginManager.h"

// Sets default values for this component's properties
UTDRL_LineOfSightComponent::UTDRL_LineOfSightComponent()
	: Super()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTDRL_LineOfSightComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UTDRL_LineOfSightComponent::PerformInitialHideActorsBasedOnClass()
{
	if (!SightParameters.bUseHideActorsBasedOnClass)
	{
		return;
	}

	TArray<AActor*> ActorsToHide = TArray<AActor*>();

	for (auto& ActClass : SightParameters.HideClasses)
	{
		TArray<AActor*> ThisActorsToHide = TArray<AActor*>();
		UGameplayStatics::GetAllActorsOfClass(this, ActClass, ThisActorsToHide);

		if (ThisActorsToHide.Num() > 0)
		{
			ActorsToHide.Append(ThisActorsToHide);
		}
	}

	for (auto& Act : ActorsToHide)
	{
		if (Act)
		{
			if (!Cast<APawn>(Act->GetOwner()) && Act != GetOwner())
			{
				UTDRL_BFL_Global::SetActorHiddenInGameWithAttached(this, Act, true);
			}
		}
	}
}

void UTDRL_LineOfSightComponent::PerformFinalUnhideActorsBasedOnClass()
{
	TArray<AActor*> ActorsToHide = TArray<AActor*>();

	for (auto& ActClass : SightParameters.HideClasses)
	{
		TArray<AActor*> ThisActorsToHide = TArray<AActor*>();
		UGameplayStatics::GetAllActorsOfClass(this, ActClass, ThisActorsToHide);

		if (ThisActorsToHide.Num() > 0)
		{
			ActorsToHide.Append(ThisActorsToHide);
		}
	}

	for (auto& Act : ActorsToHide)
	{
		if (Act)
		{
			UTDRL_BFL_Global::SetActorHiddenInGameWithAttached(this, Act, false);
		}
	}
}

// Called every frame
void UTDRL_LineOfSightComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                               FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	const APawn* PawnRef = Cast<APawn>(GetOwner());

	if (!IsActive() || !PawnRef->IsPlayerControlled() || !PawnRef->IsLocallyControlled() || PawnRef->GetLocalRole() ==
		ENetRole::ROLE_SimulatedProxy)
	{
		return;
	}

	if (!PawnRef)
	{
		return;
	}
	else
	{
		if (!PawnRef->IsLocallyControlled() || PawnRef->GetLocalRole() == ENetRole::ROLE_SimulatedProxy)
		{
			return;
		}
	}

	UKismetMaterialLibrary::SetVectorParameterValue(this, SightParameters.Collector, FName("PlayerLocation"),
	                                                FLinearColor(GetOwner()->GetActorLocation()));
	UKismetRenderingLibrary::ClearRenderTarget2D(this, CanvasInUse, FLinearColor::Black);
	DrawTriangles(TraceSight());

	TickAccum = TickAccum + DeltaTime;
}

void UTDRL_LineOfSightComponent::Activate(bool bReset)
{
	Super::Activate(bReset);

	ATDRL_Character* CharPtr = Cast<ATDRL_Character>(GetOwner());

	if (!CharPtr || !SightParameters.Canvas)
	{
		return;
	}

	if (!CharPtr->IsLocallyControlled() || CharPtr->GetLocalRole() == ENetRole::ROLE_SimulatedProxy || !CharPtr->
		IsPlayerControlled())
	{
		return;
	}

	UKismetMaterialLibrary::SetScalarParameterValue(this, SightParameters.Collector, FName("TextureResolution"),
	                                                SightParameters.TextureResolution);
	UKismetMaterialLibrary::SetScalarParameterValue(this, SightParameters.Collector, FName("AreaScale"),
	                                                SightParameters.AreaScale);

	CanvasInUse = DuplicateObject(SightParameters.Canvas, this,
	                              MakeUniqueObjectName(this, UCanvasRenderTarget2D::StaticClass(),
	                                                   SightParameters.Canvas->GetFName(),
	                                                   EUniqueObjectNameOptions::GloballyUnique));
	CharPtr->ApplyDynamicMaterialPostProcess();

	if (!CharPtr->PostProcessInUse)
	{
		return;
	}

	TArray<AActor*> ActorsWithSightMat = TArray<AActor*>();
	UGameplayStatics::GetAllActorsWithTag(this, FName("SightMaterial"), ActorsWithSightMat);

	for (auto& Act : ActorsWithSightMat)
	{
		TArray<UMeshComponent*> VisualComps;
		Act->GetComponents<UMeshComponent>(VisualComps); //Act->GetComponentsByClass(UMeshComponent::StaticClass());

		if (VisualComps.Num() == 0)
		{
			continue;
		}

		for (auto& Comp : VisualComps)
		{
			UMeshComponent* CurrentMeshComp = Cast<UMeshComponent>(Comp);
			if (!CurrentMeshComp)
			{
				continue;
			}

			int32 MatIndex = 0;
			for (auto& Mat : CurrentMeshComp->GetMaterials())
			{
				UMaterialInstanceDynamic* DynMat = Cast<UMaterialInstanceDynamic>(Mat);
				if (!DynMat)
				{
					DynMat = UKismetMaterialLibrary::CreateDynamicMaterialInstance(this, Mat);
				}
				DynMat->SetTextureParameterValue("SightRenderTarget", CanvasInUse);
				DynMat->SetScalarParameterValue("SightEnabled", 1.0f);
				CurrentMeshComp->SetMaterial(MatIndex, DynMat);
				MatIndex++;
			}
		}
	}

	CharPtr->PostProcessInUse->SetTextureParameterValue(FName("SightRenderTarget"), CanvasInUse);
	CharPtr->PostProcessInUse->SetScalarParameterValue(FName("EnableLineOfSight"), 1.0f);

	if (SightParameters.bUseHideActorsBasedOnClass)
	{
		PerformInitialHideActorsBasedOnClass();
	}
}

void UTDRL_LineOfSightComponent::Deactivate()
{
	Super::Deactivate();

	ATDRL_Character* CharPtr = Cast<ATDRL_Character>(GetOwner());

	if (!CharPtr)
	{
		return;
	}

	if (!CharPtr->IsLocallyControlled() || CharPtr->GetLocalRole() == ENetRole::ROLE_SimulatedProxy || !CharPtr->
		IsPlayerControlled())
	{
		return;
	}

	if (CanvasInUse)
	{
		CanvasInUse->ConditionalBeginDestroy();
		CanvasInUse = nullptr;
	}

	TArray<AActor*> ActorsWithSightMat = TArray<AActor*>();
	UGameplayStatics::GetAllActorsWithTag(this, FName("SightMaterial"), ActorsWithSightMat);

	for (auto& Act : ActorsWithSightMat)
	{
		TArray<UMeshComponent*> VisualComps;
		Act->GetComponents<UMeshComponent>(VisualComps);

		if (VisualComps.Num() == 0)
		{
			continue;
		}

		for (auto& Comp : VisualComps)
		{
			UMeshComponent* CurrentMeshComp = Cast<UMeshComponent>(Comp);
			if (!CurrentMeshComp)
			{
				continue;
			}

			int32 MatIndex = 0;
			for (auto& Mat : CurrentMeshComp->GetMaterials())
			{
				UMaterialInstanceDynamic* DynMat = Cast<UMaterialInstanceDynamic>(Mat);
				if (!DynMat)
				{
					continue;
				}

				DynMat->SetScalarParameterValue("SightEnabled", 0.0f);
				CurrentMeshComp->SetMaterial(MatIndex, DynMat);
				MatIndex++;
			}
		}
	}

	CharPtr->RemoveDynamicMaterialPostProcess();

	if (SightParameters.bUseHideActorsBasedOnClass)
	{
		PerformFinalUnhideActorsBasedOnClass();
	}
}

TArray<FVector> UTDRL_LineOfSightComponent::TraceSight()
{
	const float AnglesFactor = SightParameters.SubAngles + 1;
	const FVector StartVector = FRotator(0.0f, SightParameters.SightAngle / 2.0f, 0.0f).RotateVector(
		GetOwner()->GetActorForwardVector());

	FCollisionQueryParams NewParams;
	TArray<AActor*> IgnoreActors = TArray<AActor*>();
	GetOwner()->GetAttachedActors(IgnoreActors, false, true);
	IgnoreActors.Add(GetOwner());
	NewParams.AddIgnoredActors(IgnoreActors);
	FCollisionObjectQueryParams ObjCollParams;

	for (auto Iter = SightParameters.TraceChannels.CreateConstIterator(); Iter; ++Iter)
	{
		const ECollisionChannel& Channel = UCollisionProfile::Get()->ConvertToCollisionChannel(false, *Iter);
		ObjCollParams.AddObjectTypesToQuery(Channel);
	}

	TArray<FVector> SightTraces = TArray<FVector>();
	SightTraces.Init(FVector(0.0f), SightParameters.SightAngle * AnglesFactor);

	ParallelFor(SightTraces.Num(), [&](int32 Idx)
	{
		FHitResult HitOut = FHitResult();

		GetWorld()->LineTraceSingleByObjectType(
			HitOut,
			GetOwner()->GetActorLocation(),
			GetOwner()->GetActorLocation() + FRotator(0.0f, (-Idx / AnglesFactor), 0.0f).RotateVector(StartVector) *
			SightParameters.MaxDistance, ObjCollParams,
			NewParams);

		SightTraces[Idx] = (HitOut.bBlockingHit) ? (HitOut.Location - (HitOut.ImpactNormal * 5.0f)) : HitOut.TraceEnd;
	});

	if (SightParameters.bUseHideActorsBasedOnClass && TickAccum >= SightParameters.TickTraceForActorsEvery)
	{
		TraceSightForActors(SightTraces);
		TickAccum = 0.0f;
	}

	if (bEnableDebug)
	{
		for (auto& CPoint : SightTraces)
		{
			DrawDebugLine(GetWorld(),
			              GetOwner()->GetActorLocation(),
			              CPoint,
			              FColor::Cyan, false, 0.001f);
		}
	}

	return SightTraces;
}

void UTDRL_LineOfSightComponent::TraceSightForActors(const TArray<FVector>& EndPoints)
{
	if (!SightParameters.bUseHideActorsBasedOnClass)
	{
		return;
	}

	FVector BoundsOrigin;
	FVector BoundsExtent;
	GetOwner()->GetActorBounds(true, BoundsOrigin, BoundsExtent, false);

	FCollisionShape CapsShape = FCollisionShape::MakeCapsule(BoundsExtent * FVector(
		SightParameters.TraceBodyRelativeScale.X, SightParameters.TraceBodyRelativeScale.X,
		SightParameters.TraceBodyRelativeScale.Y));

	FCollisionObjectQueryParams ObjActorsCollParams;

	for (auto Iter = SightParameters.TraceForActorsChannels.CreateConstIterator(); Iter; ++Iter)
	{
		const ECollisionChannel& Channel = UCollisionProfile::Get()->ConvertToCollisionChannel(false, *Iter);
		ObjActorsCollParams.AddObjectTypesToQuery(Channel);
	}

	FCollisionQueryParams NewParams;
	TArray<AActor*> IgnoreActors = TArray<AActor*>();
	GetOwner()->GetAttachedActors(IgnoreActors, false, true);
	IgnoreActors.Add(GetOwner());
	NewParams.AddIgnoredActors(IgnoreActors);

	TArray<AActor*> CUnhide = TArray<AActor*>();

	TArray<FHitResult> FinalHitOut = TArray<FHitResult>();
	FCriticalSection Mutex;

	ParallelFor(EndPoints.Num(), [&](int32 EndPointsIdx)
	{
		const bool bShouldContinue = EndPointsIdx == 0 || EndPointsIdx == EndPoints.Num() - 1 || EndPointsIdx % (3 *
			SightParameters.SubAngles + 1) == 0.0f; // Constant number of actors multitraces even with more SubAngles
		if (!bShouldContinue)
		{
			return;
		}

		TArray<FHitResult> HitOut = TArray<FHitResult>();
		GetWorld()->SweepMultiByObjectType(
			HitOut,
			BoundsOrigin,
			EndPoints[EndPointsIdx],
			FQuat::Identity,
			ObjActorsCollParams,
			CapsShape,
			NewParams);

		if (HitOut.Num() > 0)
		{
			Mutex.Lock();
			if (bEnableDebug)
			{
				DrawDebugCapsule(GetWorld(), (HitOut.Num() > 0) ? HitOut.Last().Location : EndPoints[EndPointsIdx],
				                 BoundsExtent.Z * SightParameters.TraceBodyRelativeScale.Y,
				                 BoundsExtent.X * SightParameters.TraceBodyRelativeScale.X, FQuat::Identity,
				                 (HitOut.Num() > 0) ? FColor::Emerald : FColor::Orange, false, 0.01f);
			}

			FinalHitOut.Append(HitOut);
			Mutex.Unlock();
		}
	});

	TArray<AActor*> TracedAndNewIgnore = TArray<AActor*>();
	TracedAndNewIgnore.Init(nullptr, FinalHitOut.Num());

	ParallelFor(FinalHitOut.Num(), [&](uint32 Idx)
	{
		TracedAndNewIgnore[Idx] = FinalHitOut[Idx].GetActor();
	});

	NewParams.AddIgnoredActors(TracedAndNewIgnore);
	for (int32 i = 0; i < FinalHitOut.Num(); i++)
	{
		if (FinalHitOut[i].bBlockingHit)
		{
			bool bIsInList = false;

			for (int32 Idx = 0; Idx < SightParameters.HideClasses.Num(); Idx++)
			{
				bIsInList = SightParameters.HideClasses[Idx] == FinalHitOut[i].GetActor()->GetClass();

				if (!bIsInList)
				{
					bIsInList = FinalHitOut[i].GetActor()->GetClass()->IsChildOf(SightParameters.HideClasses[Idx]);
				}

				if (bIsInList)
				{
					break;
				}
			}

			if (bIsInList)
			{
				Mutex.Lock();
				CUnhide.Add(FinalHitOut[i].GetActor());
				Mutex.Unlock();
			}
		}
	}

	TArray<FHitResult> HitOut = TArray<FHitResult>();
	CapsShape = FCollisionShape::MakeCapsule(FVector(SightParameters.TestRadiusAroundOwner * 2.0f,
	                                                 SightParameters.TestRadiusAroundOwner * 2.0f,
	                                                 BoundsExtent.Z * SightParameters.TraceBodyRelativeScale.Y));

	GetWorld()->SweepMultiByObjectType(
		HitOut,
		BoundsOrigin,
		BoundsOrigin + FVector(0.0f, 0.0f, 1.0f),
		FQuat::Identity,
		ObjActorsCollParams,
		CapsShape,
		NewParams);

	bool bIsInList = false;
	for (int32 i = 0; i < HitOut.Num(); i++)
	{
		NewParams.AddIgnoredActor(HitOut[i].GetActor());
		for (int32 Idx = 0; Idx < SightParameters.HideClasses.Num(); Idx++)
		{
			bIsInList = SightParameters.HideClasses[Idx] == HitOut[i].GetActor()->GetClass();

			if (!bIsInList)
			{
				bIsInList = HitOut[i].GetActor()->GetClass()->IsChildOf(SightParameters.HideClasses[Idx]);
			}

			if (bIsInList)
			{
				break;
			}
		}

		if (bIsInList)
		{
			if (!GetWorld()->LineTraceTestByObjectType(BoundsOrigin, HitOut[i].GetActor()->GetActorLocation(),
			                                           ObjActorsCollParams, NewParams))
			{
				Mutex.Lock();
				CUnhide.Add(HitOut[i].GetActor());
				Mutex.Unlock();
			}
		}
	}

	for (auto& UhAct : UnhiddenActors)
	{
		if (!CUnhide.Contains(UhAct) && UhAct)
		{
			if (!Cast<APawn>(UhAct->GetOwner()))
			{
				UTDRL_BFL_Global::SetActorHiddenInGameWithAttached(this, UhAct, true);
			}
		}
	}

	UnhiddenActors.Empty();

	for (auto& Act : CUnhide)
	{
		if (Act)
		{
			if (!Cast<APawn>(Act->GetOwner()))
			{
				UTDRL_BFL_Global::SetActorHiddenInGameWithAttached(this, Act, false);
				UnhiddenActors.Add(Act);
			}
		}
	}

	//UnhiddenActors = CUnhide;
}

void UTDRL_LineOfSightComponent::DrawTriangles(const TArray<FVector> InSightTraces)
{
	if (InSightTraces.Num() == 0 || !CanvasInUse)
	{
		return;
	}

	const FVector OwnLoc = GetOwner()->GetActorLocation();
	const float Offset = SightParameters.TextureResolution / 2.0f;
	UCanvas* CurrentCanvas = nullptr;
	FVector2D CanvasSize = FVector2D(0.0f);
	FDrawToRenderTargetContext CanvasContext = FDrawToRenderTargetContext();
	UKismetRenderingLibrary::BeginDrawCanvasToRenderTarget(this, CanvasInUse, CurrentCanvas, CanvasSize, CanvasContext);

	TArray<FCanvasUVTri> TrianglesToDraw = TArray<FCanvasUVTri>();
	TrianglesToDraw.Empty();
	TrianglesToDraw.Init(FCanvasUVTri(), InSightTraces.Num() - 1);

	ParallelFor(TrianglesToDraw.Num() - 1, [&](int32 Idx)
	{
		FCanvasUVTri NewTri = FCanvasUVTri();
		//UE_LOG(LogTemp, Log, TEXT("InSightTraces are %i"), Idx);		

		const FVector Vertex1 = FVector(Offset) + ((OwnLoc - InSightTraces[Idx]) / SightParameters.AreaScale);
		const FVector Vertex2 = FVector(Offset) + ((OwnLoc - InSightTraces[Idx + 1]) / SightParameters.AreaScale);

		NewTri.V0_Pos = FVector2D(Offset);
		NewTri.V1_Pos = FVector2D(Vertex1.X, Vertex1.Y);
		NewTri.V2_Pos = FVector2D(Vertex2.X, Vertex2.Y);

		NewTri.V0_Color = FLinearColor::White;
		NewTri.V1_Color = FLinearColor::White;
		NewTri.V2_Color = FLinearColor::White;

		TrianglesToDraw[Idx] = NewTri;
	});


	CurrentCanvas->SetLinearDrawColor(FLinearColor::White);
	CurrentCanvas->K2_DrawTriangle(nullptr, TrianglesToDraw);
	UKismetRenderingLibrary::EndDrawCanvasToRenderTarget(this, CanvasContext);
}
