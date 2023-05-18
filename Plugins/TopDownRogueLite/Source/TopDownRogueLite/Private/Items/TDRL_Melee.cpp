// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_Melee.h"
#include "TDRL_BFL_Global.h"
#include "TDRL_Character.h"
#include "TDRL_AUData_MeleeTraceFilter.h"

#include "Components/ShapeComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/PawnNoiseEmitterComponent.h"
#include "Components/SkeletalMeshComponent.h"

#include "Perception/AISense_Hearing.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Animation/AnimMontage.h"

ATDRL_Melee::ATDRL_Melee()
	: Super()
{
	//Init
}

UAnimMontage* ATDRL_Melee::GetAttackMontageBasedOnDirection()
{
	if (!EquippedCharacter)
	{
		return nullptr;
	}

	if (EquippedCharacter->GetVelocity().Length() == 0)
	{
		return (MeleeStaticData.AnimMontages.Still.Num() > 0)
			       ? MeleeStaticData.AnimMontages.Still[FMath::RandRange(
				       0, MeleeStaticData.AnimMontages.Still.Num() - 1)]
			       : nullptr;
	}

	const FVector AttachDir = EquippedCharacter->GetActorRotation().UnrotateVector(EquippedCharacter->GetVelocity()).
	                                             GetSafeNormal();
	const float Angle = AttachDir.Rotation().Yaw;

	if (EquippedCharacter->GetCharacterMovement()->IsFalling())
	{
		return (MeleeStaticData.AnimMontages.Falling.Num() > 0)
			       ? MeleeStaticData.AnimMontages.Falling[FMath::RandRange(
				       0, MeleeStaticData.AnimMontages.Falling.Num() - 1)]
			       : nullptr;
	}

	if (FMath::Abs(Angle) <= 45.0f)
	{
		return (MeleeStaticData.AnimMontages.Forward.Num() > 0)
			       ? MeleeStaticData.AnimMontages.Forward[FMath::RandRange(
				       0, MeleeStaticData.AnimMontages.Forward.Num() - 1)]
			       : nullptr;
	}

	if (FMath::Abs(Angle) > 135.0f)
	{
		return (MeleeStaticData.AnimMontages.Backward.Num() > 0)
			       ? MeleeStaticData.AnimMontages.Backward[FMath::RandRange(
				       0, MeleeStaticData.AnimMontages.Backward.Num() - 1)]
			       : nullptr;
	}

	if (Angle > 0.0f)
	{
		return (MeleeStaticData.AnimMontages.Right.Num() > 0)
			       ? MeleeStaticData.AnimMontages.Right[FMath::RandRange(
				       0, MeleeStaticData.AnimMontages.Right.Num() - 1)]
			       : nullptr;
	}
	else
	{
		return (MeleeStaticData.AnimMontages.Left.Num() > 0)
			       ? MeleeStaticData.AnimMontages.Left[FMath::RandRange(0, MeleeStaticData.AnimMontages.Left.Num() - 1)]
			       : nullptr;
	}

	return nullptr;
}

void ATDRL_Melee::MeleeHit_Effects_Implementation(const FHitResult Hit)
{
	TArray<USceneComponent*> CurrentGeneratedVFXs = TArray<USceneComponent*>();
	UTDRL_BFL_Global::SpawnHitVFXsFromHit(this, Hit, MeleeStaticData.HitVFXs, CurrentGeneratedVFXs);
}

void ATDRL_Melee::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GlobalTimerCountdownHandle.IsValid() && AttackTimerWindowHandle.IsValid())
	{
		TraceAttack();
	}
}

void ATDRL_Melee::PickedUp_Implementation(class ATDRL_Character* InteractingCharacter)
{
	Super::PickedUp_Implementation(InteractingCharacter);
}

void ATDRL_Melee::Dropped_Implementation(class ATDRL_Character* InteractingCharacter)
{
	Super::Dropped_Implementation(InteractingCharacter);
}

void ATDRL_Melee::Equipped_Implementation(class ATDRL_Character* InteractingCharacter)
{
	Super::Equipped_Implementation(InteractingCharacter);
}

void ATDRL_Melee::Holstered_Implementation(class ATDRL_Character* InteractingCharacter)
{
	Super::Holstered_Implementation(InteractingCharacter);
}

bool ATDRL_Melee::StartAttack()
{
	bIsAttacking = true;

	if (GlobalTimerCountdownHandle.IsValid() || AttackTimerWindowHandle.IsValid())
	{
		return false;
	}

	GetAttackMontageBasedOnDirection();
	EquippedCharacter->GetMesh()->VisibilityBasedAnimTickOption =
		EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;

	UAnimMontage* SelectedMontage = GetAttackMontageBasedOnDirection();

	TagFilter.Empty();
	if (SelectedMontage)
	{
		UTDRL_AUData_MeleeTraceFilter* CAssetData = Cast<UTDRL_AUData_MeleeTraceFilter>(
			SelectedMontage->GetAssetUserDataOfClass(UTDRL_AUData_MeleeTraceFilter::StaticClass()));

		if (CAssetData)
		{
			TagFilter.Append(CAssetData->TagFilters);
		}

		const float TotalDuration = MeleeStaticData.Delay + MeleeStaticData.TimeWindow;
		const float AttackMontageDuration = SelectedMontage->GetPlayLength();

		PlayAnimMontageOnOwningCharacter(SelectedMontage, AttackMontageDuration / TotalDuration);
	}

	if (MeleeStaticData.Delay > 0.0f)
	{
		GetWorld()->GetTimerManager().SetTimer(AttackTimerWindowDelayHandle, this, &ATDRL_Melee::OpenAttackWindow,
		                                       MeleeStaticData.Delay, false, -1.0f);
	}
	else
	{
		OpenAttackWindow();
	}

	GetWorld()->GetTimerManager().SetTimer(GlobalTimerCountdownHandle, this, &ATDRL_Melee::AttackCountdownOverTimer,
	                                       MeleeStaticData.Countdown, false, -1.0f);

	return true;
}

void ATDRL_Melee::StopAttack()
{
	bIsAttacking = false;
}

void ATDRL_Melee::TraceAttack()
{
	for (uint16 Idx = 0; Idx < DamageBodies.Num(); Idx++)
	{
		bool bNotifyFilter = false;
		if (MeleeStaticData.bUseTagFilter)
		{
			if (TagFilter.Num() > 0)
			{
				for (int32 i2 = 0; i2 < TagFilter.Num(); i2++)
				{
					if (DamageBodies[Idx]->ComponentHasTag(TagFilter[i2]))
					{
						bNotifyFilter = true;
						break;
					}
				}
			}
			else
			{
				bNotifyFilter = true;
			}
		}
		else
		{
			bNotifyFilter = true;
		}

		if (!bNotifyFilter)
		{
			continue;
		}

		if (DamageBodies[Idx])
		{
			if (ExcludeFromFutureHit.Num() == 0)
			{
				ExcludeFromFutureHit.Add(GetOwner());
				TArray<AActor*> AttachedActors = TArray<AActor*>{this, GetOwner()};
				GetAttachedActors(AttachedActors, false, true);
				GetOwner()->GetAttachedActors(AttachedActors, false, true);
				ExcludeFromFutureHit.Append(AttachedActors);
			}

			FCollisionQueryParams CollisionParams;
			CollisionParams.AddIgnoredActors(ExcludeFromFutureHit);
			CollisionParams.bReturnPhysicalMaterial = true;

			const FTransform CompTransf = DamageBodies[Idx]->GetComponentTransform();
			const uint16 CurrentBodyIndex = DamageBodies.IndexOfByKey(DamageBodies[Idx]);
			FVector StartTraceLocation = LastTraceLocations[CurrentBodyIndex];

			if (StartTraceLocation.IsNearlyZero(1.0f))
			{
				StartTraceLocation = CompTransf.GetLocation() - FVector(0.0f, 0.0f, 1.0f);
			}

			FCollisionShape ColShape = DamageBodies[Idx]->GetCollisionShape();

			TArray<FHitResult> CCollisionHit;
			// Multi swipe
			GetWorld()->SweepMultiByChannel(
				CCollisionHit,
				StartTraceLocation,
				CompTransf.GetLocation(),
				CompTransf.GetRotation(),
				ECC_Visibility,
				ColShape,
				CollisionParams);

			// 
			if (bEnableVisualDebug)
			{
				if (ColShape.IsSphere())
				{
					DrawDebugSphere(GetWorld(), StartTraceLocation, ColShape.GetSphereRadius(), 6,
					                CCollisionHit.Num() > 0 ? FColor::Green : FColor::Orange, false, 0.1f);
				}
				else if (ColShape.IsBox())
				{
					DrawDebugBox(GetWorld(), CompTransf.GetLocation(), ColShape.GetExtent(),
					             CCollisionHit.Num() > 0 ? FColor::Green : FColor::Orange, false, 0.1f);
				}
				else if (ColShape.IsCapsule())
				{
					DrawDebugCapsule(GetWorld(), CompTransf.GetLocation(), ColShape.GetCapsuleHalfHeight(),
					                 ColShape.GetCapsuleRadius(), CompTransf.GetRotation(),
					                 CCollisionHit.Num() > 0 ? FColor::Green : FColor::Orange, false, 0.1f);
				}
			}

			for (int32 i2 = 0; i2 < CCollisionHit.Num(); i2++)
			{
				if (CCollisionHit[i2].bBlockingHit)
				{
					FHitResult CheckHitTrace = FHitResult();
					FCollisionQueryParams CollisionCheckParams;
					TArray<AActor*> ActorsToIgnoreCheck = TArray<AActor*>{this, GetOwner()};
					GetAttachedActors(ActorsToIgnoreCheck, false, true);
					GetOwner()->GetAttachedActors(ActorsToIgnoreCheck, false, true);
					CollisionCheckParams.AddIgnoredActors(ActorsToIgnoreCheck);

					// Check free way
					GetWorld()->LineTraceSingleByChannel(
						CheckHitTrace,
						GetOwner()->GetActorLocation(),
						CCollisionHit[i2].ImpactPoint + (UKismetMathLibrary::GetDirectionUnitVector(
							GetOwner()->GetActorLocation(), CCollisionHit[i2].ImpactPoint) * 5.0f),
						ECC_Visibility,
						CollisionCheckParams);

					if (bEnableVisualDebug)
					{
						DrawDebugLine(GetWorld(), GetOwner()->GetActorLocation(),
						              CCollisionHit[i2].ImpactPoint + (UKismetMathLibrary::GetDirectionUnitVector(
							              GetOwner()->GetActorLocation(), CCollisionHit[i2].ImpactPoint) * 5.0f),
						              CheckHitTrace.bBlockingHit ? FColor::Green : FColor::Red, false, 1.0f);
					}

					if (CheckHitTrace.GetActor() == CCollisionHit[i2].GetActor())
					{
						if (!ExcludeFromFutureHit.Contains(CCollisionHit[i2].GetActor()))
						{
							ExcludeFromFutureHit.Add(CCollisionHit[i2].GetActor());
							CollisionParams.AddIgnoredActor(CCollisionHit[i2].GetActor());
							MeleeHit(CCollisionHit[i2]);
						}
					}
				}
			}

			LastTraceLocations[CurrentBodyIndex] = CompTransf.GetLocation();
		}
	}
}

void ATDRL_Melee::AttackWindowOverTimer()
{
	if (AttackTimerWindowHandle.IsValid())
	{
		AttackTimerWindowHandle.Invalidate();
	}

	ExcludeFromFutureHit.Empty();

	LastTraceLocations.Empty();
	LastTraceLocations.Init(FVector(0.0f), DamageBodies.Num());

	if (bIsAttacking)
	{
		StartAttack();
	}
}

void ATDRL_Melee::AttackCountdownOverTimer()
{
	if (GlobalTimerCountdownHandle.IsValid())
	{
		GlobalTimerCountdownHandle.Invalidate();
	}

	if (bIsAttacking)
	{
		StartAttack();
	}
	else
	{
		EquippedCharacter->GetMesh()->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPose;
	}
}

void ATDRL_Melee::OpenAttackWindow()
{
	GetWorld()->GetTimerManager().SetTimer(AttackTimerWindowHandle, this, &ATDRL_Melee::AttackWindowOverTimer,
	                                       MeleeStaticData.TimeWindow, false, -1.0f);
	UAISense_Hearing::ReportNoiseEvent(this, GetActorLocation(), MeleeStaticData.Loudness, GetInstigator(), 0.0f,
	                                   MeleeStaticData.NoiseTag);
}

void ATDRL_Melee::MeleeHit(const FHitResult Hit)
{
	UGameplayStatics::ApplyPointDamage(Hit.GetActor(), MeleeStaticData.Damage, Hit.Normal * -1.0f, Hit,
	                                   GetOwner()->GetInstigatorController(), this, MeleeStaticData.DamageType);
	MeleeHit_Effects(Hit);
	UAISense_Hearing::ReportNoiseEvent(this, GetActorLocation(), MeleeStaticData.HitLoudness, GetInstigator(), 0.0f,
	                                   MeleeStaticData.HitNoiseTag);
}
