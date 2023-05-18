// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_Firearm.h"
#include "TDRL_Character.h"
#include "TDRL_PlayerController.h"
#include "TDRL_NPCController.h"
#include "TDRL_BFL_Global.h"
#include "TDRL_HUD.h"

#include "Components/SkeletalMeshComponent.h"

#include "Perception/AISense_Hearing.h"
#include "Kismet/KismetMathLibrary.h"

#include "TimerManager.h"

ATDRL_Firearm::ATDRL_Firearm()
	: Super()
{
	// Init

	Muzzle = CreateDefaultSubobject<USceneComponent>(TEXT("Muzzle"));
	Muzzle->SetupAttachment(GetMeshComponent());
}

void ATDRL_Firearm::BeginPlay()
{
	Super::BeginPlay();

	// Check class limitations
	if (MagazineAmmunition > FirearmStaticData.MagazineSize)
	{
		MagazineAmmunition = FirearmStaticData.MagazineSize;
	}
	if (Ammunition > FirearmStaticData.MaxAmmo)
	{
		Ammunition = FirearmStaticData.MaxAmmo;
	}
}

void ATDRL_Firearm::PickedUp_Implementation(class ATDRL_Character* InteractingCharacter)
{
	Super::PickedUp_Implementation(InteractingCharacter);
}

void ATDRL_Firearm::Dropped_Implementation(class ATDRL_Character* InteractingCharacter)
{
	Super::Dropped_Implementation(InteractingCharacter);
}

void ATDRL_Firearm::Equipped_Implementation(class ATDRL_Character* InteractingCharacter)
{
	Super::Equipped_Implementation(InteractingCharacter);
}

void ATDRL_Firearm::Holstered_Implementation(class ATDRL_Character* InteractingCharacter)
{
	Super::Holstered_Implementation(InteractingCharacter);

	if (EquippedCharacter)
	{
		EquippedCharacter->GetMesh()->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPose;
	}
}

void ATDRL_Firearm::RAction_Implementation(const bool Enabled)
{
	Super::RAction_Implementation(Enabled);

	if (EquippedCharacter)
	{
		EquippedCharacter->GetMesh()->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPose;
	}
}

bool ATDRL_Firearm::StartFiring()
{
	bIsFiring = true;

	if (GlobalTimerCountdownHandle.IsValid() || FireRateTimerHandle.IsValid())
	{
		float RemaningT = 0.0f;
		if (GlobalTimerCountdownHandle.IsValid())
		{
			RemaningT = GetWorld()->GetTimerManager().GetTimerRemaining(GlobalTimerCountdownHandle);
		}
		if (FireRateTimerHandle.IsValid())
		{
			const float FireRateRem = GetWorld()->GetTimerManager().GetTimerRemaining(FireRateTimerHandle);
			if (FireRateRem > RemaningT)
			{
				RemaningT = FireRateRem;
			}
		}

		if (BurstCount + 1 >= FirearmStaticData.Burst && RemaningT < 1.0f)
		{
			bShotQueued = true;
		}
		return false;
	}

	EquippedCharacter->GetMesh()->VisibilityBasedAnimTickOption =
		EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;
	GetWorld()->GetTimerManager().SetTimerForNextTick(this, &ATDRL_Firearm::FireBullet);
	return true;
}

void ATDRL_Firearm::StopFiring()
{
	bIsFiring = false;
}

void ATDRL_Firearm::FireBullet()
{
	if (!FirearmStaticData.ProjectileClass || !EquippedCharacter)
	{
		return;
	}

	if (EquippedCharacter->GetIsDead())
	{
		return;
	}

	if (MagazineAmmunition == 0)
	{
		MagazineEmpty();
		BurstCount = 0;
		return;
	}

	TArray<FHitResult> CheckRes = TArray<FHitResult>();
	FCollisionQueryParams QCheckParam = FCollisionQueryParams::DefaultQueryParam;
	TArray<AActor*> IgnoreTraces = TArray<AActor*>{EquippedCharacter};
	EquippedCharacter->GetAttachedActors(IgnoreTraces, false, true);
	QCheckParam.AddIgnoredActors(IgnoreTraces);

	GetWorld()->LineTraceMultiByChannel(
		CheckRes,
		EquippedCharacter->GetActorLocation(),
		GetMuzzleTransform().GetLocation(),
		ECC_Visibility,
		QCheckParam);

	FTransform ProjTransform = GetMuzzleTransform();
	for (int32 i = 0; i < CheckRes.Num(); i++)
	{
		if (CheckRes[i].bBlockingHit)
		{
			const TSubclassOf<AActor> CheckClassActor = CheckRes[i].GetActor()->GetClass();
			bool bShouldChangeSpawnPoint = true;

			for (int32 i2 = 0; i2 < FirearmStaticData.MuzzleObstructionCheckIgnore.Num(); i2++)
			{
				if (CheckClassActor == FirearmStaticData.MuzzleObstructionCheckIgnore[i2] || CheckClassActor->IsChildOf(
					FirearmStaticData.MuzzleObstructionCheckIgnore[i2]))
				{
					bShouldChangeSpawnPoint = false;
					break;
				}
			}

			if (bShouldChangeSpawnPoint)
			{
				ProjTransform.SetLocation(CheckRes[i].Location);
				break;
			}
		}
	}

	// Spawn...
	if (FirearmStaticData.AnimMontages.Primary)
	{
		PlayAnimMontageOnOwningCharacter(FirearmStaticData.AnimMontages.Primary);
	}

	AActor* ProjActor = (AActor*)GetWorld()->SpawnActorDeferred<ATDRL_ProjectileBase>(
		FirearmStaticData.ProjectileClass, ProjTransform);
	ProjActor->SetOwner(EquippedCharacter);
	ProjActor->SetInstigator(GetInstigator());
	ProjActor->FinishSpawning(ProjTransform);

	UAISense_Hearing::ReportNoiseEvent(this, GetActorLocation(), FirearmStaticData.Loudness, GetInstigator(), 0.0f,
	                                   FirearmStaticData.NoiseTag);
	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &ATDRL_Firearm::FireRateTimerOver,
	                                       1 / FirearmStaticData.FireRate, false, -1.0f);

	bShotQueued = false;
	MagazineAmmunition--;
	BurstCount++;

	ATDRL_Character* CharPtr = Cast<ATDRL_Character>(EquippedCharacter);
	if (CharPtr)
	{
		if (EquippedCharacter->GetInstigatorController())
		{
			if (EquippedCharacter->GetInstigatorController()->IsLocalPlayerController())
			{
				// Update HUD
				ATDRL_HUD* CHud = UTDRL_BFL_Global::GetTDRLHUD(EquippedCharacter);
				if (CHud)
				{
					CHud->RefreshAmmoSlot(CharPtr->SelectedItemSlot - 1);
				}
			}
		}
	}

	if (!EquippedCharacter->IsPlayerControlled() && MagazineAmmunition == 0)
	{
		ReloadWeapon();
	}
}

void ATDRL_Firearm::FireRateTimerOver()
{
	if (FireRateTimerHandle.IsValid())
	{
		FireRateTimerHandle.Invalidate();
	}

	if (bIsFiring && (BurstCount < FirearmStaticData.Burst || FirearmStaticData.Burst <= 0) && !
		GlobalTimerCountdownHandle.IsValid())
	{
		FireBullet();
	}
	else
	{
		BurstCount = 0;

		if (bShotQueued)
		{
			FireBullet();
		}
		else if (EquippedCharacter)
		{
			EquippedCharacter->GetMesh()->VisibilityBasedAnimTickOption =
				EVisibilityBasedAnimTickOption::AlwaysTickPose;
		}
	}
}

void ATDRL_Firearm::MagazineEmpty()
{
	if (!EquippedCharacter->IsPlayerControlled())
	{
		ReloadWeapon();
	}
}

bool ATDRL_Firearm::ReloadWeapon()
{
	if (Ammunition <= 0 || MagazineAmmunition == FirearmStaticData.MagazineSize || GlobalTimerCountdownHandle.IsValid())
	{
		return false;
	}

	if (FirearmStaticData.ReloadTime > 0)
	{
		if (FirearmStaticData.AnimMontages.Reload)
		{
			const float TotalDuration = FirearmStaticData.ReloadTime;
			const float AttackMontageDuration = FirearmStaticData.AnimMontages.Reload->GetPlayLength();

			PlayAnimMontageOnOwningCharacter(FirearmStaticData.AnimMontages.Reload,
			                                 AttackMontageDuration / TotalDuration);
		}

		GetWorld()->GetTimerManager().SetTimer(GlobalTimerCountdownHandle, this,
		                                       &ATDRL_Firearm::ReloadCountdownOverTimer, FirearmStaticData.ReloadTime,
		                                       false, -1.0f);
	}
	else
	{
		ReloadCountdownOverTimer();
	}

	return true;
}

void ATDRL_Firearm::ReloadCountdownOverTimer()
{
	if (Ammunition <= 0 || MagazineAmmunition == FirearmStaticData.MagazineSize)
	{
		return;
	}

	if (EquippedCharacter->IsPlayerControlled())
	{
		Ammunition = Ammunition + MagazineAmmunition;
		MagazineAmmunition = 0;
		MagazineAmmunition = Ammunition > FirearmStaticData.MagazineSize ? FirearmStaticData.MagazineSize : Ammunition;
		Ammunition = Ammunition - MagazineAmmunition;
	}
	else
	{
		MagazineAmmunition = Ammunition > FirearmStaticData.MagazineSize ? FirearmStaticData.MagazineSize : Ammunition;
	}

	if (GlobalTimerCountdownHandle.IsValid())
	{
		GlobalTimerCountdownHandle.Invalidate();
	}

	if (EquippedCharacter)
	{
		if (EquippedCharacter->GetInstigatorController())
		{
			if (EquippedCharacter->GetInstigatorController()->IsLocalPlayerController())
			{
				// Update HUD
				ATDRL_HUD* CHud = UTDRL_BFL_Global::GetTDRLHUD(EquippedCharacter);
				if (CHud)
				{
					CHud->RefreshAmmoSlot(EquippedCharacter->SelectedItemSlot - 1);
				}
			}
		}
	}
}

bool ATDRL_Firearm::RefillAmmo(const int32 Ammo)
{
	if (Ammo <= 0 || Ammunition == FirearmStaticData.MaxAmmo)
	{
		return false;
	}

	Ammunition = FMath::Min(Ammunition + FMath::Abs(Ammo), FirearmStaticData.MaxAmmo);

	if (EquippedCharacter)
	{
		ATDRL_HUD* CHud = UTDRL_BFL_Global::GetTDRLHUD(EquippedCharacter);
		if (CHud)
		{
			CHud->RefreshAmmoSlot(EquippedCharacter->SelectedItemSlot - 1);
		}
	}

	return true;
}
