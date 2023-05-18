// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"

#include "TDRL_SpawnVolume.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNROGUELITE_API ATDRL_SpawnVolume : public ATriggerVolume
{
	GENERATED_BODY()

public:
	ATDRL_SpawnVolume();

#if WITH_EDITOR
	/*Select all the related NPCSpawns*/
	UFUNCTION(CallInEditor, Category = "TDRL", meta = (DisplayName = "Select Related NPCSpawns"))
	void SelectRelatedNPCSpawns();
#endif

protected:
};
