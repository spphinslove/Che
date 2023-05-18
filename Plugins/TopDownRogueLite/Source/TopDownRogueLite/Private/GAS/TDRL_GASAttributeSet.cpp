// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_GASAttributeSet.h"
#include "Net/UnrealNetwork.h"

UTDRL_GASAttributeSet::UTDRL_GASAttributeSet()
	: Super()
{
}

void UTDRL_GASAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UTDRL_GASAttributeSet, CustomAttribute1, COND_None, REPNOTIFY_OnChanged);
}

void UTDRL_GASAttributeSet::OnRep_CustomAttribute1(const FGameplayAttributeData& Old)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UTDRL_GASAttributeSet, CustomAttribute1, Old);
}

void UTDRL_GASAttributeSet::OnRep_CustomAttribute2(const FGameplayAttributeData& Old)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UTDRL_GASAttributeSet, CustomAttribute2, Old);
}

void UTDRL_GASAttributeSet::OnRep_CustomAttribute3(const FGameplayAttributeData& Old)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UTDRL_GASAttributeSet, CustomAttribute3, Old);
}
