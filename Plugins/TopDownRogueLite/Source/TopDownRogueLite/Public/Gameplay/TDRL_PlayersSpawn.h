// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TDRL_PlayersSpawn.generated.h"

UCLASS()
class TOPDOWNROGUELITE_API ATDRL_PlayersSpawn : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATDRL_PlayersSpawn();

	/*PlayerStartTag for this spawn (customized version of the default "PlayerStartTag" from APlayerStart*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TDRL|PlayersSpawn", meta = (ClampMin = "1", UIMin = "1"))
	FName PlayerStartTag = FName();
	/*Number of APlayerStart to spawn in grid*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TDRL|PlayersSpawn", meta = (ClampMin = "1", UIMin = "1"))
	int32 SpawnsNumber = 16;
	/*APlayerStart grid distancing*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TDRL|PlayersSpawn",
		meta = (ClampMin = "50.0", UIMin = "50.0"))
	float InitialGridSize = 100.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class USceneComponent* Root;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* ActivationArea;

	UPROPERTY()
	TArray<class UChildActorComponent*> SpawnPoints;

	UFUNCTION()
	virtual void OverlapAreaBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	                              UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
	                              const FHitResult& Hit);
	UFUNCTION()
	virtual void OverlapAreaEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
	                            class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:
	UFUNCTION()
	void RefreshSpawnPoints();
	UFUNCTION()
	void RefreshAllPlayerStartTags();
	UFUNCTION()
	void RefreshLocationSpawnPoints();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void OnConstruction(const FTransform& Transform) override;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

	/*Return a random APlayerStart actor operating for this PayersSpawn*/
	UFUNCTION(BlueprintPure, Category = "TDRL|PlayersSpawn",
		meta = (DisplayName = "GetRandomPlayerStartActor", CompactNodeTitle = "GetRandomStart", Keywords =
			"Get Random Player Start Actor Spawn TDRL"))
	virtual APlayerStart* GetRandomPlayerStartActor() const;
};
