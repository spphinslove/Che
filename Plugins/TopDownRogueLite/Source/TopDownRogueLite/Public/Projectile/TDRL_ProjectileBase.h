// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TDRL_ItemTypes.h"
#include "TDRL_ProjectileBase.generated.h"

UCLASS()
class TOPDOWNROGUELITE_API ATDRL_ProjectileBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATDRL_ProjectileBase();

	/*Projectile static data*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TDRL|Data|Projectile")
	FProjectileStaticData ProjectileStaticData;
	/*Enable visual debug*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TDRL|Projectile")
	uint8 bEnableDebug : 1;

	UPROPERTY(BlueprintReadOnly, Category = "TDRL|Projectile|Runtime")
	TArray<FVector> InstancesDirection = TArray<FVector>();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	FTimerHandle LifeTimerHandle;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	virtual void GatherInstancesDirection();
	UFUNCTION(Client, Reliable)
	virtual void GatherInstancesDirection_Client();
	UFUNCTION(Server, Reliable)
	virtual void RegisterInstancesDirection(const FHitResult MainDirectionHit);

	UFUNCTION()
	virtual void DestroyProjectile();
};
