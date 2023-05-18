// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Projectile/TDRL_ProjectileBase.h"
#include "TDRL_ProjectilePhysics.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNROGUELITE_API ATDRL_ProjectilePhysics : public ATDRL_ProjectileBase
{
	GENERATED_BODY()
	ATDRL_ProjectilePhysics();

public:
protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* Mesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UProjectileMovementComponent* ProjectileMovementComponent;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void RegisterInstancesDirection_Implementation(const FHitResult MainDirectionHit);
};
