// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TDRL_Melee.h"
#include "TDRL_ItemTypes.h"
#include "TDRL_Firearm.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNROGUELITE_API ATDRL_Firearm : public ATDRL_Melee
{
	GENERATED_BODY()

public:
	ATDRL_Firearm();
	/* Static Data structure for FirearmItems*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDRL|Data|Firearm")
	FFirearmStaticData FirearmStaticData;

	/*Current amount of ammunition for this weapon (excluding magazine)*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDRL|Firearm")
	int32 Ammunition = 0;
	/*Current amount of ammunition for this weapon in the magazine*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDRL|Firearm")
	int32 MagazineAmmunition = 0;

protected:
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class USceneComponent* Muzzle;

	UPROPERTY()
	uint8 BurstCount;
	UPROPERTY()
	FTimerHandle FireRateTimerHandle;
	UPROPERTY()
	uint8 bShotQueued : 1;
	UPROPERTY()
	uint8 bIsFiring : 1;

public:
	/*This Firearm is currently firing?*/
	UFUNCTION(BlueprintPure, Category = "TDRL|Firearm",
		meta = (DisplayName = "IsFiring", Keywords = "Is Firing Firearm Weapon TDRL"))
	virtual bool IsFiring() const
	{
		return bIsFiring;
	}

	/*This Firearm has a queued shot? Used with burst > 0*/
	UFUNCTION(BlueprintPure, Category = "TDRL|Firearm",
		meta = (DisplayName = "HasQueuedShot", Keywords = "Has Queued Shot Firearm Weapon TDRL"))
	virtual bool HasQueuedShot() const
	{
		return bShotQueued;
	}

	/*Return the Muzzle component*/
	UFUNCTION(BlueprintPure, Category = "TDRL|Components",
		meta = (DisplayName = "GetMuzzleComponent", Keywords = "Get Muzzle Component Firearm Weapon TDRL"))
	virtual USceneComponent* GetMuzzleComponent() const
	{
		return Muzzle;
	}

	/*Return the Muzzle transform*/
	UFUNCTION(BlueprintPure, Category = "TDRL|Firearm",
		meta = (DisplayName = "GetMuzzleTransform", Keywords = "Get Muzzle Transform Firearm Weapon TDRL"))
	virtual FTransform GetMuzzleTransform() const
	{
		return Muzzle->GetComponentTransform();
	}

	// Overrides
	virtual void PickedUp_Implementation(class ATDRL_Character* InteractingCharacter) override;
	virtual void Dropped_Implementation(class ATDRL_Character* InteractingCharacter) override;
	virtual void Equipped_Implementation(class ATDRL_Character* InteractingCharacter) override;
	virtual void Holstered_Implementation(class ATDRL_Character* InteractingCharacter) override;
	virtual void RAction_Implementation(const bool Enabled) override;

	/*Start firing*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|Firearm",
		meta = (DisplayName = "StartFiring", Keywords = "Start Firing Firearm Weapon TDRL"))
	bool StartFiring();
	/*Stop firing*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|Firearm",
		meta = (DisplayName = "StopFiring", Keywords = "Stop FiringFirearm Weapon TDRL"))
	void StopFiring();

	UFUNCTION()
	void FireBullet();
	UFUNCTION()
	void FireRateTimerOver();
	UFUNCTION()
	void MagazineEmpty();

	/*Reload*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|Firearm",
		meta = (DisplayName = "ReloadWeapon", Keywords = "Reload Firearm Weapon TDRL"))
	bool ReloadWeapon();
	UFUNCTION()
	void ReloadCountdownOverTimer();

	/*Refill Ammo*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|Firearm",
		meta = (DisplayName = "ReloadWeapon", Keywords = "Reload Firearm Weapon TDRL"))
	bool RefillAmmo(const int32 Ammo);
};
