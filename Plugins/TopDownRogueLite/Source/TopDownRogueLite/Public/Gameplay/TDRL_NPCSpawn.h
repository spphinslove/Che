// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "TDRL_GameplayTypes.h"
#include "TDRL_NPCSpawn.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSpawnedDeathDelegate, FDeathData, DeathData);

UCLASS()
class TOPDOWNROGUELITE_API ATDRL_NPCSpawn : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATDRL_NPCSpawn();

	/*Character class to spawn*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDRL|NPCSpawn")
	TSubclassOf<class ATDRL_Character> SpawnClass = nullptr;
	/*Controller class to spawn, this controller will possess the SpawnedCharacter*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDRL|NPCSpawn")
	TSubclassOf<class ATDRL_NPCController> AIControllerClass = nullptr;
	/*List of item to assign when the new character is spawned*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDRL|NPCSpawn")
	TArray<TSubclassOf<class ATDRL_Item>> SpawnInventory = TArray<TSubclassOf<class ATDRL_Item>>();

	/*Is this spawner in a "SightArea"? This will spawn the character as invisible and the Sight component will do the rest*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDRL|NPCSpawn")
	uint8 bSpawnInSightArea : 1;

	/*Trigger volumes used to enable this spawn*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDRL|NPCSpawn|Triggers")
	TArray<class ATriggerVolume*> Triggers = TArray<class ATriggerVolume*>();
	/*Should keep the character in the map, even if the player run away from the spawn area*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDRL|NPCSpawn|Triggers")
	uint8 bDisableDespawn : 1;
	/*Time to wait before despawning the character when the player exits the spawn area*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDRL|NPCSpawn|Triggers",
		meta = (EditCondition = "!bDisableDespawn"))
	float DespawnDelay = 5.0f;

	/*When spawned, assign this patrol target to the Character. Can be any actor but "AISplineTool" has many additional settings.*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDRL|NPCSpawn|Patrol")
	class AActor* PatrolTarget = nullptr;
	/*When spawned, if target is "AISplineTool", use random point order*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDRL|NPCSpawn|Patrol")
	uint8 bUseAISplineToolRandomPoints : 1;

	/*Use this behavior tree when spawned*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDRL|NPCSpawn|AI")
	class UBehaviorTree* AIBehavior = nullptr;
	/*Use this blackboard when spawned*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDRL|NPCSpawn|AI")
	class UBlackboardData* AIBlackBoard = nullptr;

	/*Which stencil value should be assigned to the skeletal mesh component?*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDRL|NPCSpawn|Stencil")
	int32 StencilValue = 253;

	/*Cosmetics to use when spawned. Cosmetics system will merge all the skeletal meshes together, reducing drawcalls*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDRL|NPCSpawn|Cosmetic")
	struct FCosmeticParameterList SpawnCosmeticParameter;

	/*Custom properties to apply once spawned (Character). Use the key value to identify the variable through its name. Use the value to set the parameter itself. Supports: bool, int, float, byte, name, string and vector3D*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDRL|NPCSpawn|CustomProperties")
	TMap<FName, FName> CharacterCustomProperties;
	/*Custom properties to apply once spawned (AIController). Use the key value to identify the variable through its name. Use the value to set the parameter itself. Supports: bool, int, float, byte, name, string and vector3D*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDRL|NPCSpawn|CustomProperties")
	TMap<FName, FName> ControllerCustomProperties;

	/*Death delegate*/
	UPROPERTY(BlueprintAssignable, Category = "TDRL|NPCSpawn|Delegates|Death")
	FOnSpawnedDeathDelegate OnSpawnedDeath;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* Capsule;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UArrowComponent* Direction;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UTextRenderComponent* SpawnTitle;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UBillboardComponent* Billboard;

	/*Runtime pointer to the spawned character*/
	UPROPERTY(BlueprintReadOnly, Category = "TDRL|NPCSpawn|Runtime")
	class ATDRL_Character* SpawnedCharacter = nullptr;
	/*Runtime pointer to the spawned controller*/
	UPROPERTY(BlueprintReadOnly, Category = "TDRL|NPCSpawn|Runtime")
	class ATDRL_NPCController* AIController = nullptr;

	UFUNCTION()
	virtual void OverlapTriggerBegin(AActor* ThisActor, AActor* OtherActor);
	UFUNCTION()
	virtual void OverlapTriggerEnd(AActor* ThisActor, AActor* OtherActor);

	UFUNCTION()
	virtual void SpawnNPC();
	UFUNCTION()
	virtual void DespawnNPC();

	UPROPERTY()
	FTimerHandle DespawnDelayHandle;

	UFUNCTION()
	virtual void RefreshSpawnName();

	UFUNCTION()
	virtual void CharacterDied(FDeathData OutDeathData);

	UPROPERTY()
	uint8 bCharacterIsDead : 1;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void OnConstruction(const FTransform& Transform) override;

#if WITH_EDITOR

	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

	/*Select all the NPCSpawns*/
	UFUNCTION(CallInEditor, Category = "TDRL", meta = (DisplayName = "Select All NPCSpawns"))
	void SelectAllNPCSpawns();
	/*Select all the NPCSpawns sharing at least one trigger*/
	UFUNCTION(CallInEditor, Category = "TDRL", meta = (DisplayName = "Select NPC Spawns Sharing One Trigger"))
	void SelectNPCSpawnsSharingOneTrigger();
	/*Select all the NPCSpawns sharing the same triggers list (order is not important)*/
	UFUNCTION(CallInEditor, Category = "TDRL", meta = (DisplayName = "Select NPCSpawns Matching Triggers"))
	void SelectNPCSpawnsMatchingTriggers();
	/*Select all triggers affecting this spawn*/
	UFUNCTION(CallInEditor, Category = "TDRL", meta = (DisplayName = "Select Triggers"))
	void SelectTriggers();

#endif

	/*Returns the spawned character pointer*/
	UFUNCTION(BlueprintPure, Category = "TDRL|NPCSpawn|Components",
		meta = (DisplayName = "GetSpawnedCharacter", CompactNodeTitle = "Character", Keywords =
			"Get Spawned Character TDRL NPCSpawn"))
	virtual class ATDRL_Character* GetSpawnedCharacter() const
	{
		return SpawnedCharacter;
	}

	/*Returns the spawned npc's controller pointer*/
	UFUNCTION(BlueprintPure, Category = "TDRL|NPCSpawn|Components",
		meta = (DisplayName = "GetSpawnedController", CompactNodeTitle = "AIController", Keywords =
			"Get Spawned Controller TDRL NPCSpawn"))
	virtual class ATDRL_NPCController* GetSpawnedController() const
	{
		return AIController;
	}

	/*This function will restore the spawn functions after its associated character is dead*/
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category = "TDRL|NPCSpawn",
		meta = (DisplayName = "Restore Spawn", Keywords = "Restore Spawn Reset TDRL"))
	virtual void RestoreSpawn();

	/*Called when the NPC is spawned*/
	UFUNCTION(BlueprintNativeEvent, Category = "TDRL|NPCSpawn")
	void NPCSpawned(ATDRL_Character* NPCCharacter);
	/*Called when the NPC is despawned (but still alive)*/
	UFUNCTION(BlueprintNativeEvent, Category = "TDRL|NPCSpawn")
	void NPCDespawning(ATDRL_Character* NPCCharacter);
	/*Called when the NPC is despawned (but still alive)*/
	UFUNCTION(BlueprintNativeEvent, Category = "TDRL|NPCSpawn")
	void NPCDied(ATDRL_Character* NPCCharacter);
	/*Called when the NPCSpawn instance is restored*/
	UFUNCTION(BlueprintNativeEvent, Category = "TDRL|NPCSpawn")
	void SpawnRestored();
};
