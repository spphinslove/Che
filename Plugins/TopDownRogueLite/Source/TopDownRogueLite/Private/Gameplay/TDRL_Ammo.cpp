// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_Ammo.h"
#include "TDRL_Character.h"
#include "TDRL_Firearm.h"

#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SceneComponent.h"


// Sets default values
ATDRL_Ammo::ATDRL_Ammo()
	: Super()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);

	Trigger = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Trigger"));
	Trigger->SetupAttachment(Mesh);
}

// Called when the game starts or when spawned
void ATDRL_Ammo::BeginPlay()
{
	Super::BeginPlay();

	Trigger->OnComponentBeginOverlap.AddDynamic(this, &ATDRL_Ammo::OverlapAreaBegin);
}

void ATDRL_Ammo::OverlapAreaBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                  UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
                                  const FHitResult& Hit)
{
	ATDRL_Character* OverlappedChar = Cast<ATDRL_Character>(OtherActor);

	if (OverlappedChar)
	{
		RefillCharacter(OverlappedChar);
	}
}

// Called every frame
void ATDRL_Ammo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATDRL_Ammo::RefillCharacter(ATDRL_Character* InChar)
{
	if (!InChar)
	{
		return;
	}

	ATDRL_Firearm* EquippedFirearm = Cast<ATDRL_Firearm>(InChar->GetEquippedItem());
	bool bShouldDestroy = false;

	if (EquippedFirearm)
	{
		if (EquippedFirearm->FirearmStaticData.AmmoTag == AmmoTag)
		{
			switch (RefillMethod)
			{
			case EAmmoRefillMethod::ARM_Percentage:
				bShouldDestroy = EquippedFirearm->RefillAmmo(
					FMath::CeilToInt((EquippedFirearm->FirearmStaticData.MaxAmmo / 100.0f) * RefillPercentage));
				break;
			case EAmmoRefillMethod::ARM_Exact:
				bShouldDestroy = EquippedFirearm->RefillAmmo(RefillExact);
				break;
			case EAmmoRefillMethod::ARM_Full:
				bShouldDestroy = EquippedFirearm->RefillAmmo(EquippedFirearm->FirearmStaticData.MaxAmmo);
				break;
			}
		}
	}

	if (bShouldDestroy)
	{
		Destroy();
	}
}
