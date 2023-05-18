// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TDRL_Weapon.h"
#include "TDRL_ItemTypes.h"
#include "TDRL_Melee.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNROGUELITE_API ATDRL_Melee : public ATDRL_Weapon
{
	GENERATED_BODY()

public:
	ATDRL_Melee();
	/* Static Data structure for MeleeItems*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDRL|Data|Melee")
	FMeleeStaticData MeleeStaticData;

	/*List of bodies used as reference for the melee trace*/
	UPROPERTY(BlueprintReadOnly, Category = "TDRL|Melee|Runtime")
	TArray<UShapeComponent*> DamageBodies;
	/*Cached pointers to all the GeneratedVFXs*/
	UPROPERTY(BlueprintReadOnly, Category = "TDRL|Melee|Runtime")
	TArray<UPrimitiveComponent*> GeneratedVFXs;
	/*True when this melee weapon is being used for attaking*/
	UPROPERTY(BlueprintReadOnly, Category = "TDRL|Melee|Runtime")
	uint8 bIsAttacking : 1;

	/*Add a body to the "DamageBodies" list*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|Melee")
	virtual void AddDamageBody(UShapeComponent* Item)
	{
		DamageBodies.Add(Item);
		LastTraceLocations.AddDefaulted(1);
	}

	/*Add multiple bodies to the "DamageBodies" list*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|Melee")
	virtual void AddDamageBodies(TArray<UShapeComponent*> Items)
	{
		DamageBodies.Append(Items);
		LastTraceLocations.AddDefaulted(Items.Num());
	}

	/*Remove a body from the "DamageBodies" list*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|Melee")
	virtual void RemoveDamageBody(UShapeComponent* Item)
	{
		if (DamageBodies.Num() < 1)
		{
			return;
		}

		DamageBodies.Remove(Item);
		DamageBodies.Shrink();

		if (LastTraceLocations.Num() < 1)
		{
			return;
		}

		LastTraceLocations.RemoveAt(0);
		LastTraceLocations.Shrink();
	}

	/*Remove multiple bodies from the "DamageBodies" list*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|Melee")
	virtual void RemoveDamageBodies(const TArray<UShapeComponent*> Items)
	{
		TArray<UShapeComponent*> NewDemageBodies;

		for (auto Body : DamageBodies)
		{
			if (!Items.Contains(Body))
			{
				NewDemageBodies.Add(Body);
			}
		}

		DamageBodies = NewDemageBodies;

		LastTraceLocations.Empty();
		LastTraceLocations.AddDefaulted(DamageBodies.Num());
	}

	/*Clear "DamageBodies" list*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|Melee")
	virtual void ClearDamageBodies()
	{
		DamageBodies.Empty();
		LastTraceLocations.Empty();
	}

	/*Return an attack montage based on the movement direction of the character using it*/
	UFUNCTION(BlueprintPure, Category = "TDRL|Melee")
	virtual UAnimMontage* GetAttackMontageBasedOnDirection();

protected:
	UPROPERTY()
	TArray<AActor*> ExcludeFromFutureHit;
	UPROPERTY()
	FTimerHandle AttackTimerWindowDelayHandle;
	UPROPERTY()
	FTimerHandle AttackTimerWindowHandle;
	UPROPERTY()
	TArray<FVector> LastTraceLocations = TArray<FVector>();
	UPROPERTY()
	TArray<FName> TagFilter;

	UFUNCTION(NetMulticast, Unreliable)
	virtual void MeleeHit_Effects(const FHitResult Hit);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void PickedUp_Implementation(class ATDRL_Character* InteractingCharacter) override;
	virtual void Dropped_Implementation(class ATDRL_Character* InteractingCharacter) override;
	virtual void Equipped_Implementation(class ATDRL_Character* InteractingCharacter) override;
	virtual void Holstered_Implementation(class ATDRL_Character* InteractingCharacter) override;

	/*Starts the melee attack*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|Melee",
		meta = (DisplayName = "StartAttack(Melee)", Keywords = "Start Melee Attack TDRL"))
	virtual bool StartAttack();
	/*Immediately stops the attack*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|Melee",
		meta = (DisplayName = "StopAttack(Melee)", Keywords = "Stop Melee Attack TDRL"))
	virtual void StopAttack();

	UFUNCTION()
	virtual void TraceAttack();
	UFUNCTION()
	virtual void AttackWindowOverTimer();
	UFUNCTION()
	virtual void AttackCountdownOverTimer();
	UFUNCTION()
	virtual void OpenAttackWindow();

	UFUNCTION()
	virtual void MeleeHit(const FHitResult Hit);
};
