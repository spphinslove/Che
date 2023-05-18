// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_AISplineTool.h"
#include "Components/SplineComponent.h"

// Sets default values
ATDRL_AISplineTool::ATDRL_AISplineTool()
	: Super()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Spline = CreateDefaultSubobject<USplineComponent>(TEXT("Spline"));
	Spline->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void ATDRL_AISplineTool::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATDRL_AISplineTool::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
