// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TDRL_UserWidget.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNROGUELITE_API UTDRL_UserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UTDRL_UserWidget(const FObjectInitializer& ObjInit);

	/*Pointer to the current HUD actor*/
	UPROPERTY(BlueprintReadOnly, Category = "TDRL|HUD|Runtime", meta = (ExposeOnSpawn = "true"))
	class ATDRL_HUD* HUDReference;
	/*Set a new pointer to the current HUD actor*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|HUD",
		meta = (DisplayName = "SetHUDReference", Keywords = "Set HUD Reference TDRL"))
	void SetHUDReference(class ATDRL_HUD* Reference)
	{
		HUDReference = Reference;
	}

protected:

public:
};
