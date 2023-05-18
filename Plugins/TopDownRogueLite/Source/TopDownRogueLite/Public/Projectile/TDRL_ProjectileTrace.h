// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "TDRL_ProjectileBase.h"
#include "TDRL_ProjectileTrace.generated.h"

UCLASS()
class TOPDOWNROGUELITE_API ATDRL_ProjectileTrace : public ATDRL_ProjectileBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATDRL_ProjectileTrace();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TDRL|Projectile|Trace")
	float TraceRadius = 6.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TDRL|Projectile|Trace")
	float TraceSpeed = 4000.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TDRL|Projectile|Trace")
	class UNiagaraSystem* BulletTrail;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDRL|Projectile|Trace")
	TArray<TEnumAsByte<EObjectTypeQuery>> TraceChannels;
	// = TArray<TEnumAsByte<EObjectTypeQuery>>{ UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldStatic), UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldDynamic), UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn), UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Destructible), UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Vehicle), UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_PhysicsBody) };

	UPROPERTY(BlueprintReadOnly, Category = "TDRL|Projectile|Trace|VFX")
	TArray<class UNiagaraComponent*> TrailEffects = TArray<class UNiagaraComponent*>();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class USceneComponent* SpawnPoint;

	UFUNCTION(NetMulticast, Unreliable)
	virtual void SpawnVFXs();
	UFUNCTION(NetMulticast, Unreliable)
	virtual void UpdateVFXs(const TArray<FVector>& NewLocation);
	UFUNCTION(NetMulticast, Reliable)
	virtual void ProjectileHit(const FHitResult Hit, const int32 TraceIndex);

	UFUNCTION()
	virtual void RegisterIgnoringActors();
	UFUNCTION()
	virtual void TraceProjectile(const float DeltaTime);

	UPROPERTY()
	TArray<FVector> LastTraceLocations = TArray<FVector>();
	UPROPERTY()
	TArray<AActor*> ActorsToIgnoreWhenTracing = TArray<AActor*>();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/*Fired after all VFXs are spawned*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "TDRL|Projectile|Trace",
		meta = (DisplayName = "VFXs Spawn Complete", Keywords = "VFX Spawn Complete Trail TDRL"))
	void TrailVFXSpawnComplete(const TArray<class UNiagaraComponent*>& SpawnedTrailEffects);
};
