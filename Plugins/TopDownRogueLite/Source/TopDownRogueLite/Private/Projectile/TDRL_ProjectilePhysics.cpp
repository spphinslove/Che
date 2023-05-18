// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_ProjectilePhysics.h"
#include "GameFramework/ProjectileMovementComponent.h"

ATDRL_ProjectilePhysics::ATDRL_ProjectilePhysics()
	: Super()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MovementComponent"));
}

void ATDRL_ProjectilePhysics::BeginPlay()
{
	Super::BeginPlay();
}

void ATDRL_ProjectilePhysics::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATDRL_ProjectilePhysics::RegisterInstancesDirection_Implementation(const FHitResult MainDirectionHit)
{
	Super::RegisterInstancesDirection_Implementation(MainDirectionHit);

	if (InstancesDirection.Num() > 0)
	{
		ProjectileMovementComponent->Velocity = InstancesDirection[0].GetSafeNormal() * ProjectileMovementComponent->
			InitialSpeed;
	}
}
