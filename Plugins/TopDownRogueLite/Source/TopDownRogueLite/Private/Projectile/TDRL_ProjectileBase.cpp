// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_ProjectileBase.h"
#include "TDRL_PlayerController.h"
#include "TDRL_NPCController.h"

#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"

#include "GameFramework/Character.h"
#include "GameFramework/PlayerController.h"
#include "TimerManager.h"

// Sets default values
ATDRL_ProjectileBase::ATDRL_ProjectileBase()
	: Super()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bEnableDebug = false;
	bReplicates = true;
}

// Called when the game starts or when spawned
void ATDRL_ProjectileBase::BeginPlay()
{
	Super::BeginPlay();

	const ACharacter* CharOwn = Cast<ACharacter>(GetOwner());
	if (CharOwn)
	{
		if (CharOwn->IsLocallyControlled())
		{
			switch (CharOwn->GetLocalRole())
			{
			case ENetRole::ROLE_Authority:
				GatherInstancesDirection();
				break;
			case ENetRole::ROLE_AutonomousProxy:
				GatherInstancesDirection_Client();
				break;
			}
		}
	}

	if (ProjectileStaticData.SoundEffect)
	{
		UGameplayStatics::SpawnSoundAtLocation(GetWorld(), (USoundBase*)ProjectileStaticData.SoundEffect,
		                                       GetActorLocation(), GetActorRotation());
	}

	if (ProjectileStaticData.MuzzleEffectNiagara)
	{
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), ProjectileStaticData.MuzzleEffectNiagara,
		                                               GetActorLocation(), GetActorRotation(), FVector(1.0f), true,
		                                               true);
	}

	if (ProjectileStaticData.MuzzleEffectParticle)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ProjectileStaticData.MuzzleEffectParticle,
		                                         FTransform(GetActorRotation(), GetActorLocation(), FVector(1.0f)));
	}

	if (ProjectileStaticData.Lifetime > 0.0f)
	{
		GetWorld()->GetTimerManager().SetTimer(LifeTimerHandle, this, &ATDRL_ProjectileBase::DestroyProjectile,
		                                       ProjectileStaticData.Lifetime, false, -1.0f);
	}
}

// Called every frame
void ATDRL_ProjectileBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATDRL_ProjectileBase::GatherInstancesDirection()
{
	if (!GetOwner())
	{
		return;
	}

	const ACharacter* OwningChar = Cast<ACharacter>(GetOwner());

	if (!OwningChar)
	{
		return;
	}

	if (!OwningChar->GetController())
	{
		return;
	}

	const ATDRL_PlayerController* OwningContr = Cast<ATDRL_PlayerController>(OwningChar->GetController());

	FHitResult CursorHitResult;
	if (OwningContr)
	{
		switch (OwningContr->GetControlRotationType())
		{
		case EControlRotationType::UnderMouse:
			OwningContr->GetHitResultUnderCursorByChannel(
				UEngineTypes::ConvertToTraceType(ECollisionChannel::ECC_Visibility), false, CursorHitResult);
			break;
		case EControlRotationType::LockedTarget:
			if (OwningContr->GetLockedTarget())
			{
				CursorHitResult.bBlockingHit = true;
				CursorHitResult.Location = OwningContr->GetLockedTarget()->GetActorLocation();
			}
			break;
		case EControlRotationType::TargetLocation:
			CursorHitResult.bBlockingHit = true;
			CursorHitResult.Location = OwningContr->GetLockedTarget()->GetTargetLocation();
			break;
		}

		if (!OwningContr->GetShouldUsePitch())
		{
			CursorHitResult.Location = FVector(CursorHitResult.Location.X, CursorHitResult.Location.Y,
			                                   GetActorLocation().Z);
		}
	}
	else
	{
		const ATDRL_NPCController* AIContr = Cast<ATDRL_NPCController>(OwningChar->GetController());

		if (AIContr)
		{
			if (AIContr->GetAlertThreat())
			{
				CursorHitResult.bBlockingHit = true;
				CursorHitResult.Location = AIContr->GetAlertThreat()->GetActorLocation();
			}
		}
	}

	RegisterInstancesDirection(CursorHitResult);
}

void ATDRL_ProjectileBase::GatherInstancesDirection_Client_Implementation()
{
	GatherInstancesDirection();
}

void ATDRL_ProjectileBase::RegisterInstancesDirection_Implementation(const FHitResult MainDirectionHit)
{
	InstancesDirection.SetNumUninitialized(ProjectileStaticData.Instances, true);

	const FVector ForwardCharacterVector = GetRootComponent()->GetForwardVector();
	TArray<AActor*> AvoidActors;
	GetOwner()->GetAttachedActors(AvoidActors, true, true);
	AvoidActors.Add(GetOwner());

	ParallelFor(ProjectileStaticData.Instances, [&](uint8 Idx)
	{
		FVector CDir = FVector(0.0f);

		if (MainDirectionHit.bBlockingHit)
		{
			CDir = UKismetMathLibrary::GetDirectionUnitVector(GetActorLocation(), MainDirectionHit.Location);
		}
		else
		{
			CDir = ForwardCharacterVector;
		}

		if (Cast<APawn>(GetOwner())->IsPlayerControlled())
		{
			CDir = AvoidActors.Contains(MainDirectionHit.GetActor()) ? ForwardCharacterVector : CDir;
		}

		CDir = CDir.GetSafeNormal();

		const FRotator VarianceDir = FRotator(
			FMath::RandRange(-ProjectileStaticData.TrajectoryVariance.Y, ProjectileStaticData.TrajectoryVariance.Y),
			FMath::RandRange(-ProjectileStaticData.TrajectoryVariance.X, ProjectileStaticData.TrajectoryVariance.X),
			0.0f);
		CDir = VarianceDir.RotateVector(CDir);

		InstancesDirection[Idx] = CDir;
	});
}

void ATDRL_ProjectileBase::DestroyProjectile()
{
	Destroy();
}
