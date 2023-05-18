// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_Fists.h"
#include "Components/SphereComponent.h"

ATDRL_Fists::ATDRL_Fists()
	: Super()
{
	RightFist = CreateDefaultSubobject<USphereComponent>(TEXT("RightFist"));
	RightFist->SetupAttachment(GetRootComponent());
	RightFist->SetCollisionProfileName("NoCollision");
	RightFist->SetSphereRadius(16.0f);
	RightFist->ComponentTags.Add("hand_r");

	LeftFist = CreateDefaultSubobject<USphereComponent>(TEXT("LeftFist"));
	LeftFist->SetupAttachment(GetRootComponent());
	LeftFist->SetCollisionProfileName("NoCollision");
	LeftFist->SetSphereRadius(16.0f);
	LeftFist->ComponentTags.Add("hand_l");
}

void ATDRL_Fists::BeginPlay()
{
	Super::BeginPlay();
	AddDamageBodies(TArray<UShapeComponent*>{RightFist, LeftFist});
}
