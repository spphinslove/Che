// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "TDRL_GameplayTypes.h"
#include "TDRL_BFL_Global.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNROGUELITE_API UTDRL_BFL_Global : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
#pragma region HUD
	/*Returns the current TDRL_HUD actor for the local player*/
	UFUNCTION(BlueprintPure, Category = "TDRL|GlobalLibrary|HUD",
		meta = (DisplayName = "GetPlayerHUD(TDRL)", Keywords = "HUD GUI TDRL TopDown", WorldContext =
			"WorldContextObject"))
	static class ATDRL_HUD* GetTDRLHUD(UObject* WorldContextObject);

#pragma endregion

#pragma region Gameplay
	/*Returns the local player TDRL Character*/
	UFUNCTION(BlueprintPure, Category = "TDRL|GlobalLibrary|Gameplay",
		meta = (DisplayName = "GetPlayerCharacter(TDRL)", Keywords = "Character TopDown TDRL", WorldContext =
			"WorldContextObject"))
	static class ATDRL_Character* GetPlayerCharacterTDRL(UObject* WorldContextObject);
	/*Returns the TDRL Game Mode*/
	UFUNCTION(BlueprintPure, Category = "TDRL|GlobalLibrary|Gameplay",
		meta = (DisplayName = "GetGameMode(TDRL)", Keywords = "Character TopDown TDRL", WorldContext =
			"WorldContextObject"))
	static class ATDRL_GameModeBase* GetGameModeTDRL(UObject* WorldContextObject);
	/*Returns the TDRL Game State*/
	UFUNCTION(BlueprintPure, Category = "TDRL|GlobalLibrary|Gameplay",
		meta = (DisplayName = "GetGameState(TDRL)", Keywords = "Character TopDown TDRL", WorldContext =
			"WorldContextObject"))
	static class ATDRL_GameStateBase* GetGameStateTDRL(UObject* WorldContextObject);
	/*Returns all the TDRL PlayersSpawn in the current game*/
	UFUNCTION(BlueprintPure, Category = "TDRL|GlobalLibrary|Gameplay",
		meta = (DisplayName = "GetAllPlayersSpawn", Keywords = "Player Spawn All", WorldContext = "WorldContextObject"))
	static TArray<class ATDRL_PlayersSpawn*> GetAllPlayersSpawn(UObject* WorldContextObject);
	/*Returns if the following Stun data structure can be used*/
	UFUNCTION(BlueprintPure, Category = "TDRL|GlobalLibrary|Gameplay",
		meta = (DisplayName = "IsValidStun", Keywords = "Stun Valid", WorldContext = "WorldContextObject"))
	static bool IsValidStun(UObject* WorldContextObject, FStunParameters StunValue = FStunParameters());

#pragma endregion

#pragma region SkeletalMerge
	/*Merges Skeletal Meshes runtime. Morph target is not supported after merging*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|GlobalLibrary|SkeletalMerge",
		meta = (DisplayName = "MergeSkeletalMeshes", Keywords = "Merge Skeletal Meshes Mesh", WorldContext =
			"WorldContextObject"))
	static class USkeletalMesh* MergeSkeletalMeshes(UObject* WorldContextObject,
	                                                const FMergeSkeletalMeshesParameters& Params);
	/*Converts a simplified Cosmetic Structure Parameter into a MergeSkeletalMeshesParameters*/
	UFUNCTION(BlueprintPure, Category = "TDRL|GlobalLibrary|SkeletalMerge",
		meta = (DisplayName = "CosmeticParameterToMergeParameter", Keywords =
			"Merge Skeletal Meshes Mesh Parameter Conversion Cosmetic", WorldContext = "WorldContextObject"))
	static struct FMergeSkeletalMeshesParameters CosmeticParamToMergeParam(
		UObject* WorldContextObject, const FCosmeticParameterList& Params);

#pragma endregion

#pragma region Utility
	/*Apply custom properties to any actor. Specify the name of the property and its value in the list. Supports: bool, int, float, byte, name, string and vector3D*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|GlobalLibrary|Utility",
		meta = (DisplayName = "ApplyCustomProperties", Keywords = "Custom Properties Property", WorldContext =
			"WorldContextObject"))
	static void ApplyCustomProperties(UObject* WorldContextObject, const TMap<FName, FName> InProperties,
	                                  AActor* InActor);
	/*Set an actor hidden in game and propagates the effect to attached actors*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|GlobalLibrary|Utility",
		meta = (DisplayName = "SetActorHiddenInGameWithAttached", Keywords =
			"Hidden Attached Actor Visibility Visible Hide", WorldContext = "WorldContextObject"))
	static void SetActorHiddenInGameWithAttached(UObject* WorldContextObject, class AActor* InActor,
	                                             const bool bShouldHide);

#pragma endregion

#pragma region VFXs

	/*Spawn VFXs given an hit and a list of PhysMaterials/Effects*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|GlobalLibrary|VFXs",
		meta = (DisplayName = "SpawnVisualEffectsFromHit", Keywords = "VFX VFXs Hit Spawn Visual Effects", WorldContext
			= "WorldContextObject"))
	static void SpawnHitVFXsFromHit(UObject* WorldContextObject, FHitResult InHit, const UDataTable* EffectsDataTable,
	                                TArray<USceneComponent*>& GeneratedAssets);
	/*Spawn status VFXs (usually on character)*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|GlobalLibrary|VFXs",
		meta = (DisplayName = "SpawnStatusVFXs", Keywords = "VFX VFXs Spawn Status Visual Effects", WorldContext =
			"WorldContextObject"))
	static void SpawnStatusVFXs(UObject* WorldContextObject, const FStatusEffect Value, USceneComponent* TargetComp,
	                            const FName BoneName, TArray<USceneComponent*>& GeneratedAssets);

#pragma endregion
};
