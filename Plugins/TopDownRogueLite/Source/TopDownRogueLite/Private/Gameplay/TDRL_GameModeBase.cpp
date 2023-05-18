// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_GameModeBase.h"
#include "TDRL_GameStateBase.h"
#include "TDRL_PlayersSpawn.h"
#include "TDRL_BFL_Global.h"
#include "TDRL_PlayerState.h"
#include "TDRL_PlayerController.h"

#include "GameFramework/Controller.h"
#include "Kismet/GameplayStatics.h"

#include "EngineUtils.h"
#include "GameFramework/PlayerStart.h"

ATDRL_GameModeBase::ATDRL_GameModeBase()
	: Super()
{
}

void ATDRL_GameModeBase::BeginPlay()
{
	Super::BeginPlay();
}

void ATDRL_GameModeBase::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

APlayerController* ATDRL_GameModeBase::Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal,
                                             const FString& Options, const FUniqueNetIdRepl& UniqueId,
                                             FString& ErrorMessage)
{
	return Super::Login(NewPlayer, InRemoteRole, *DefaultPlayerSpawnTag.ToString(), Options, UniqueId, ErrorMessage);
}

void ATDRL_GameModeBase::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
}

void ATDRL_GameModeBase::HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer)
{
	Super::HandleStartingNewPlayer_Implementation(NewPlayer);
}

void ATDRL_GameModeBase::Logout(AController* Exiting)
{
	Super::Logout(Exiting);
}

AActor* ATDRL_GameModeBase::ChoosePlayerStart_Implementation(AController* Player)
{
	return Super::ChoosePlayerStart_Implementation(Player);
}

AActor* ATDRL_GameModeBase::FindPlayerStart_Implementation(AController* Player, const FString& IncomingName)
{
	UWorld* World = GetWorld();

	// If incoming start is specified, then just use it
	if (!IncomingName.IsEmpty())
	{
		TArray<APlayerStart*> StartFound = TArray<APlayerStart*>();
		const FName IncomingPlayerStartTag = FName(*IncomingName);
		for (TActorIterator<APlayerStart> It(World); It; ++It)
		{
			APlayerStart* Start = *It;
			if (Start && Start->PlayerStartTag == IncomingPlayerStartTag)
			{
				StartFound.Add(Start);
			}
		}

		if (StartFound.Num() > 0)
		{
			int32 OutIndex = -1;
			TArray<int32> TestedIndexes = TArray<int32>();
			FCollisionObjectQueryParams NewQParam = FCollisionObjectQueryParams();
			NewQParam.AddObjectTypesToQuery(ECollisionChannel::ECC_Pawn);

			while (TestedIndexes.Num() < StartFound.Num())
			{
				const int32 TestIndex = FMath::RandRange(0, StartFound.Num() - 1);
				if (TestedIndexes.Contains(TestIndex))
				{
					continue;
				}

				if (!GetWorld()->SweepTestByObjectType(
					StartFound[TestIndex]->GetActorLocation(),
					StartFound[TestIndex]->GetActorLocation() + FVector(0.0f, 0.0f, 1.0f),
					FQuat::Identity,
					NewQParam,
					FCollisionShape::MakeCapsule(StartFound[TestIndex]->GetRootComponent()->Bounds.BoxExtent.X,
					                             StartFound[TestIndex]->GetRootComponent()->Bounds.BoxExtent.Z)))
				{
					return StartFound[TestIndex];
				}
				else
				{
					TestedIndexes.Add(TestIndex);
				}
			}
		}
	}

	// Always pick StartSpot at start of match
	if (ShouldSpawnAtStartSpot(Player))
	{
		if (AActor* PlayerStartSpot = Player->StartSpot.Get())
		{
			return PlayerStartSpot;
		}
		else
		{
			UE_LOG(LogGameMode, Error,
			       TEXT("FindPlayerStart: ShouldSpawnAtStartSpot returned true but the Player StartSpot was null."));
		}
	}

	AActor* BestStart = ChoosePlayerStart(Player);
	if (BestStart == nullptr)
	{
		// No player start found
		UE_LOG(LogGameMode, Log, TEXT("FindPlayerStart: PATHS NOT DEFINED or NO PLAYERSTART with positive rating"));

		// This is a bit odd, but there was a complex chunk of code that in the end always resulted in this, so we may as well just 
		// short cut it down to this.  Basically we are saying spawn at 0,0,0 if we didn't find a proper player start
		BestStart = World->GetWorldSettings();
	}

	return BestStart;
}

ATDRL_GameStateBase* ATDRL_GameModeBase::GetGameStateTDRL() const
{
	return GetGameState<ATDRL_GameStateBase>();
}
