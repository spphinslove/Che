// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TDRL_HUD.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNROGUELITE_API ATDRL_HUD : public AHUD
{
	GENERATED_BODY()

public:
	ATDRL_HUD();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "TDRL|HUD")
	uint8 SelectedSlotUI;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "TDRL|HUD")
	void CreateInGameUI();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "TDRL|HUD")
	void SetSlotsAmount(const uint8 Slot);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "TDRL|HUD")
	void SelectSlotUI(const uint8 Slot);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "TDRL|HUD")
	void RefreshIcons();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "TDRL|HUD")
	void RefreshAmmoSlot(const uint8 Slot);
};
