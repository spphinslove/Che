// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_HUD.h"
#include "TDRL_UserWidget.h"

ATDRL_HUD::ATDRL_HUD()
	: Super()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ATDRL_HUD::BeginPlay()
{
	Super::BeginPlay();
}

void ATDRL_HUD::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATDRL_HUD::CreateInGameUI_Implementation()
{
}

void ATDRL_HUD::RefreshIcons_Implementation()
{
}

void ATDRL_HUD::SetSlotsAmount_Implementation(const uint8 Slot)
{
}

void ATDRL_HUD::SelectSlotUI_Implementation(const uint8 Slot)
{
}

void ATDRL_HUD::RefreshAmmoSlot_Implementation(const uint8 Slot)
{
}
