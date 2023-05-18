// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_PlayerState.h"
#include "TDRL_BFL_Global.h"

#include "Components/SkeletalMeshComponent.h"
#include "PhysicsEngine/PhysicsAsset.h"

#include "GameFramework/Character.h"
#include "Net/UnrealNetwork.h"

ATDRL_PlayerState::ATDRL_PlayerState()
	: Super()
{
}

void ATDRL_PlayerState::BeginPlay()
{
	if (GeneratedCosmetic)
	{
		ApplyCosmetic();
	}
}

void ATDRL_PlayerState::OnRep_CosmeticList(const FCosmeticParameterList OldValue)
{
	GemerateCosmetic();
}

void ATDRL_PlayerState::GemerateCosmetic()
{
	USkeletalMesh* CGenMesh = UTDRL_BFL_Global::MergeSkeletalMeshes(
		this, UTDRL_BFL_Global::CosmeticParamToMergeParam(this, CosmeticList));

	if (CGenMesh)
	{
		GeneratedCosmetic = CGenMesh;
		ApplyCosmetic();
	}
}

void ATDRL_PlayerState::ApplyCosmetic()
{
	ACharacter* CharPtr = Cast<ACharacter>(GetPawn());

	if (CharPtr)
	{
		if (CharPtr->GetMesh()->GetSkeletalMeshAsset() != GeneratedCosmetic)
		{
			if (GeneratedCosmetic)
			{
				const bool bCapsShadow = GeneratedCosmetic->GetShadowPhysicsAsset()->IsValidLowLevelFast();
				CharPtr->GetMesh()->SetCastCapsuleDirectShadow(bCapsShadow);
				CharPtr->GetMesh()->SetCastCapsuleIndirectShadow(bCapsShadow);
			}

			CharPtr->GetMesh()->SetSkeletalMesh(GeneratedCosmetic, false);
		}
	}
}

void ATDRL_PlayerState::SetCosmeticList_Serv_Implementation(FCosmeticParameterList InCosmeticList)
{
	SetCosmeticList_Implementation(InCosmeticList);
}

void ATDRL_PlayerState::SetCosmeticList_Implementation(FCosmeticParameterList InCosmeticList)
{
	CosmeticList = InCosmeticList;
	GemerateCosmetic();
}

void ATDRL_PlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(ATDRL_PlayerState, CosmeticList, COND_None, REPNOTIFY_OnChanged);
}

void ATDRL_PlayerState::ClientInitialize(AController* InController)
{
	Super::ClientInitialize(InController);
}

void ATDRL_PlayerState::SetCosmeticList(FCosmeticParameterList InCosmeticList)
{
	if (GetLocalRole() == ROLE_Authority)
	{
		SetCosmeticList_Implementation(InCosmeticList);
	}
	else
	{
		SetCosmeticList_Serv(InCosmeticList);
	}
}
