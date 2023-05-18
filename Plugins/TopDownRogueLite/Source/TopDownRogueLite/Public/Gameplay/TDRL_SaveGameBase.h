// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"

#include "TDRL_GameplayTypes.h"
#include "TDRL_SaveGameBase.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNROGUELITE_API UTDRL_SaveGameBase : public USaveGame
{
	GENERATED_BODY()
	UTDRL_SaveGameBase();

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TDRL|Savegame")
	struct FCosmeticParameterList DefaultCosmetics;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TDRL|Savegame")
	TMap<FName, float> Currencies;
	// Should be used with DataTable ( See TDRL_GameplayTypes->FCurrenciesList : public FTableRowBase )

protected:

public:
};
