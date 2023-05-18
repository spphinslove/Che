// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_SpawnVolume.h"
#include "TDRL_NPCSpawn.h"

#include "Kismet/GameplayStatics.h"
#include "Engine/Selection.h"

#if WITH_EDITOR
#include "Editor/EditorEngine.h"
#endif

ATDRL_SpawnVolume::ATDRL_SpawnVolume()
	: Super()
{
}

#if WITH_EDITOR

void ATDRL_SpawnVolume::SelectRelatedNPCSpawns()
{
	USelection* CurrSelect = GEditor->GetSelectedActors();
	TArray<AActor*> SelectedVolumes = TArray<AActor*>();
	CurrSelect->GetSelectedObjects<AActor>(SelectedVolumes);

	TArray<AActor*> NPCSpawns;
	UGameplayStatics::GetAllActorsOfClass(this, ATDRL_NPCSpawn::StaticClass(), NPCSpawns);
	TArray<AActor*> NPCSpawnsToSelect;

	for (auto& ASelec : NPCSpawns)
	{
		ATDRL_NPCSpawn* CSpawn = Cast<ATDRL_NPCSpawn>(ASelec);
		if (CSpawn)
		{
			for (auto& Trig : CSpawn->Triggers)
			{
				if (SelectedVolumes.Contains(Trig))
				{
					NPCSpawnsToSelect.AddUnique(CSpawn);
					break;
				}
			}
		}
	}

	for (auto& SpawnSel : NPCSpawnsToSelect)
	{
		if (!GEditor->GetSelectedActors()->IsSelected(SpawnSel))
		{
			GEditor->SelectActor(SpawnSel, true, false);
		}
	}

	TArray<ATriggerVolume*> RemoveVolumes = TArray<ATriggerVolume*>();
	CurrSelect->GetSelectedObjects<ATriggerVolume>(RemoveVolumes);

	for (auto& Desel : RemoveVolumes)
	{
		GEditor->SelectActor(Desel, false, Desel == RemoveVolumes.Last());
	}
}

#endif
