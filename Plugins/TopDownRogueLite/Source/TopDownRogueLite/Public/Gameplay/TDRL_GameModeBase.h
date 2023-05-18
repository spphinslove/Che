// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TDRL_GameplayTypes.h"
#include "TDRL_GameModeBase.generated.h"


/**
 * 
 */
UCLASS()
class TOPDOWNROGUELITE_API ATDRL_GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	ATDRL_GameModeBase();

public:
#pragma region Spawn

	/*StartTag to use on spawn. This will determine which spawn will be chosen.*/
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "TDRL|GameMode")
	FName DefaultPlayerSpawnTag = FName();

#pragma endregion

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual AActor* ChoosePlayerStart_Implementation(AController* Player) override;
	virtual AActor*
	FindPlayerStart_Implementation(AController* Player, const FString& IncomingName = TEXT("")) override;
	virtual void PostInitializeComponents() override;
	virtual APlayerController* Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal,
	                                 const FString& Options, const FUniqueNetIdRepl& UniqueId,
	                                 FString& ErrorMessage) override;
	virtual void PostLogin(APlayerController* NewPlayer) override;
	virtual void HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer) override;
	virtual void Logout(AController* Exiting);

	/*Returns the current TDRL Game State*/
	UFUNCTION(BlueprintPure, Category = "TDRL|GameMode",
		meta = (DisplayName = "GetGameState(TDRL)", Keywords = "Get Game State TDRL"))
	virtual ATDRL_GameStateBase* GetGameStateTDRL() const;
};
