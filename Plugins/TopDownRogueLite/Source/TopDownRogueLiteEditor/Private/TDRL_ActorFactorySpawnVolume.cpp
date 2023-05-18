// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_ActorFactorySpawnVolume.h"

#include "TDRL_SpawnVolume.h"
#include "TDRL_NPCSpawn.h"

UTDRL_ActorFactorySpawnVolume::UTDRL_ActorFactorySpawnVolume(const FObjectInitializer& ObjInit)
	:Super(ObjInit) {

	bShowInEditorQuickMenu = true;
	DisplayName = FText::FromString("SpawnVolume");
	NewActorClass = ATDRL_SpawnVolume::StaticClass();	

}