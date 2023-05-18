// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_GameStateBase.h"
#include "TDRL_BFL_Global.h"
#include "TDRL_PlayerController.h"
#include "TDRL_PlayerState.h"
#include "TDRL_GameModeBase.h"

#include "GameFramework/Character.h"
#include "GameFramework/PlayerState.h"
#include "Net/UnrealNetwork.h"

ATDRL_GameStateBase::ATDRL_GameStateBase()
	: Super()
{
}

void ATDRL_GameStateBase::AddPlayerState(APlayerState* PlayerState)
{
	Super::AddPlayerState(PlayerState);
}

void ATDRL_GameStateBase::RemovePlayerState(APlayerState* PlayerState)
{
	Super::RemovePlayerState(PlayerState);
}


void ATDRL_GameStateBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}
