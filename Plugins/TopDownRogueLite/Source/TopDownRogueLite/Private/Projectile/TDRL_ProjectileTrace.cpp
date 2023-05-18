// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_ProjectileTrace.h"
#include "TDRL_ItemTypes.h"
#include "TDRL_BFL_Global.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/Character.h"
#include "Perception/AISense_Hearing.h"
#include "Engine/EngineTypes.h"

#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"

// Sets default values
ATDRL_ProjectileTrace::ATDRL_ProjectileTrace()
	: Super()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("SpawnPoint"));
	SetRootComponent(SpawnPoint);
}

// Called when the game starts or when spawned
void ATDRL_ProjectileTrace::BeginPlay()
{
	Super::BeginPlay();

	RegisterIgnoringActors();
	LastTraceLocations.Empty();
	LastTraceLocations.Init(GetActorLocation(), ProjectileStaticData.Instances);
}

void ATDRL_ProjectileTrace::SpawnVFXs_Implementation()
{
	for (int32 i = 0; i < ProjectileStaticData.Instances; i++)
	{
		TrailEffects.Add(UNiagaraFunctionLibrary::SpawnSystemAtLocation(
			this,
			BulletTrail,
			GetActorLocation(),
			GetActorRotation(),
			GetActorScale(),
			true, true));
	}

	TrailVFXSpawnComplete(TrailEffects);
}

void ATDRL_ProjectileTrace::UpdateVFXs_Implementation(const TArray<FVector>& NewLocation)
{
	for (int32 i = 0; i < NewLocation.Num(); i++)
	{
		if (TrailEffects.Num() > i)
		{
			if (TrailEffects[i])
			{
				TrailEffects[i]->SetWorldLocation(NewLocation[i], false, (FHitResult*)nullptr,
				                                  ETeleportType::TeleportPhysics);
			}
		}
	}
}

// Called every frame
void ATDRL_ProjectileTrace::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (InstancesDirection.Num() > 0)
	{
		TraceProjectile(DeltaTime);
	}
}

void ATDRL_ProjectileTrace::TrailVFXSpawnComplete_Implementation(
	const TArray<class UNiagaraComponent*>& SpawnedTrailEffects)
{
}

void ATDRL_ProjectileTrace::RegisterIgnoringActors()
{
	if (!GetOwner())
	{
		return;
	}

	ActorsToIgnoreWhenTracing.Empty();
	GetOwner()->GetAttachedActors(ActorsToIgnoreWhenTracing);
	ActorsToIgnoreWhenTracing.Add(GetOwner());
}

void ATDRL_ProjectileTrace::TraceProjectile(const float DeltaTime)
{
	if (InstancesDirection.Num() == 0)
	{
		return;
	}

	if (TrailEffects.Num() == 0)
	{
		SpawnVFXs();
	}

	const FCollisionShape MyColShape = FCollisionShape::MakeSphere(TraceRadius);
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActors(ActorsToIgnoreWhenTracing);
	CollisionParams.bReturnPhysicalMaterial = true;
	bool AnyValidDirection = false;
	TArray<FVector> NewLocations = TArray<FVector>();

	for (uint16 Idx = 0; Idx < InstancesDirection.Num(); Idx++)
	{
		if (InstancesDirection[Idx] == FVector(0.0f))
		{
			if (TrailEffects[Idx])
			{
				if (TrailEffects[Idx]->IsActive())
				{
					TrailEffects[Idx]->Deactivate();
				}
			}
			continue;
		}
		else
		{
			AnyValidDirection = true;
		}

		FHitResult CCollisionHit;
		const FVector TargetLocation = LastTraceLocations[Idx] + (InstancesDirection[Idx] * TraceSpeed * DeltaTime);

		FCollisionObjectQueryParams QParam;

		for (auto Iter = TraceChannels.CreateConstIterator(); Iter; ++Iter)
		{
			const ECollisionChannel& Channel = UCollisionProfile::Get()->ConvertToCollisionChannel(false, *Iter);
			QParam.AddObjectTypesToQuery(Channel);
		}

		GetWorld()->SweepSingleByObjectType(CCollisionHit, LastTraceLocations[Idx], TargetLocation, FQuat(), QParam,
		                                    MyColShape, CollisionParams);

		if (bEnableDebug)
		{
			DrawDebugLine(GetWorld(), LastTraceLocations[Idx], TargetLocation, FColor::Orange, false, 1.0f);
			DrawDebugSphere(GetWorld(), TargetLocation, TraceRadius, 6, FColor::Orange, false, 1.0f);
		}

		if (CCollisionHit.bBlockingHit)
		{
			ProjectileHit(CCollisionHit, Idx);
			NewLocations.Add(CCollisionHit.ImpactPoint);
			InstancesDirection[Idx] = FVector(0.0f);
		}
		else
		{
			NewLocations.Add(TargetLocation);
		}

		LastTraceLocations[Idx] = TargetLocation;
	}

	UpdateVFXs(NewLocations);

	if (!AnyValidDirection)
	{
		DestroyProjectile();
	}
}

void ATDRL_ProjectileTrace::ProjectileHit_Implementation(const FHitResult Hit, const int32 TraceIndex)
{
	if (bEnableDebug)
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit actor is: %s"), *Hit.GetActor()->GetFName().ToString());
	}

	// Apply damage
	TArray<USceneComponent*> CurrentGeneratedVFXs = TArray<USceneComponent*>();
	UTDRL_BFL_Global::SpawnHitVFXsFromHit(this, Hit, ProjectileStaticData.HitVFXs, CurrentGeneratedVFXs);

	if (TrailEffects.Num() > TraceIndex)
	{
		if (TrailEffects[TraceIndex])
		{
			if (TrailEffects[TraceIndex]->IsActive())
			{
				TrailEffects[TraceIndex]->Deactivate();
			}
		}
	}

	if (GetLocalRole() == ENetRole::ROLE_Authority)
	{
		UAISense_Hearing::ReportNoiseEvent(this, GetActorLocation(), ProjectileStaticData.HitLoudness, GetInstigator(),
		                                   0.0f, ProjectileStaticData.HitNoiseTag);
		UGameplayStatics::ApplyPointDamage(Hit.GetActor(), ProjectileStaticData.Damage, Hit.Normal * -1.0f, Hit,
		                                   GetOwner()->GetInstigatorController(), this,
		                                   ProjectileStaticData.DamageType);
	}
}
