// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_PlayersSpawn.h"
#include "TDRL_PlayerController.h"
#include "TDRL_PlayerState.h"
#include "TDRL_BFL_Global.h"

#include "Components/BoxComponent.h"
#include "GameFramework/PlayerStart.h"

#include "TimerManager.h"


// Sets default values
ATDRL_PlayersSpawn::ATDRL_PlayersSpawn()
	: Super()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	Root->SetMobility(EComponentMobility::Static);
	SetRootComponent(Root);


	ActivationArea = CreateDefaultSubobject<UBoxComponent>(TEXT("ActivationArea"));
	ActivationArea->SetMobility(EComponentMobility::Static);
	ActivationArea->SetupAttachment(Root);
	ActivationArea->SetCollisionProfileName(FName("Trigger"));
	ActivationArea->SetGenerateOverlapEvents(true);
	ActivationArea->SetCanEverAffectNavigation(false);
	ActivationArea->SetRelativeLocation(FVector(0.0f, 0.0f, 200.0f));
	ActivationArea->SetBoxExtent(FVector(200.0f));
}

// Called when the game starts or when spawned
void ATDRL_PlayersSpawn::BeginPlay()
{
	Super::BeginPlay();
	ActivationArea->OnComponentBeginOverlap.AddDynamic(this, &ATDRL_PlayersSpawn::OverlapAreaBegin);
	ActivationArea->OnComponentEndOverlap.AddDynamic(this, &ATDRL_PlayersSpawn::OverlapAreaEnd);
}

void ATDRL_PlayersSpawn::OverlapAreaBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                          UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
                                          const FHitResult& Hit)
{
	APawn* PawnFilter = Cast<APawn>(OtherActor);
	if (PawnFilter)
	{
		ATDRL_PlayerController* ContrPtr = Cast<ATDRL_PlayerController>(PawnFilter->GetController());
		if (ContrPtr)
		{
			ContrPtr->LatestValidStartTag = PlayerStartTag;
			ContrPtr->PlayersSpawnAreaOverlapped(this);
		}
	}
}

void ATDRL_PlayersSpawn::OverlapAreaEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                                        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void ATDRL_PlayersSpawn::RefreshSpawnPoints()
{
	if (!GetWorld())
	{
		return;
	}

	if (SpawnPoints.Num() >= SpawnsNumber)
	{
		TArray<UChildActorComponent*> NewSpawnPoints;

		for (int32 i = 0; i < SpawnPoints.Num(); i++)
		{
			if (i < SpawnsNumber)
			{
				if (SpawnPoints[i])
				{
					NewSpawnPoints.Add(SpawnPoints[i]);
				}
			}
			else
			{
				if (SpawnPoints[i])
				{
					SpawnPoints[i]->DestroyComponent();
				}
			}
		}

		SpawnPoints = NewSpawnPoints;
	}
	else
	{
		const float CurrentSpawned = SpawnPoints.Num();
		for (int32 Idx = 0; Idx < SpawnsNumber; Idx++)
		{
			if (Idx > CurrentSpawned - 1)
			{
				UChildActorComponent* SpawnedStart = NewObject<UChildActorComponent>(
					this, UChildActorComponent::StaticClass(), MakeUniqueObjectName(
						this, UChildActorComponent::StaticClass(), FName("PlayerStart"),
						EUniqueObjectNameOptions::GloballyUnique));
				//GetWorld()->SpawnActor<APlayerStart>(APlayerStart::StaticClass(), GetActorLocation(), FRotator(0.0f), SpawnParam);

				if (SpawnedStart)
				{
					SpawnedStart->SetChildActorClass(APlayerStart::StaticClass());
					SpawnedStart->CreateChildActor();
					SpawnedStart->SetupAttachment(Root);
					SpawnedStart->RegisterComponent();
					SpawnedStart->SetMobility(EComponentMobility::Static);

					Cast<APlayerStart>(SpawnedStart->GetChildActor())->PlayerStartTag = PlayerStartTag;

					SpawnPoints.Add(SpawnedStart);
				}
			}
		}
	}

	GetWorld()->GetTimerManager().SetTimerForNextTick(this, &ATDRL_PlayersSpawn::RefreshLocationSpawnPoints);
}

void ATDRL_PlayersSpawn::RefreshAllPlayerStartTags()
{
	ParallelFor(SpawnPoints.Num(), [&](int32 Idx)
	{
		if (SpawnPoints[Idx])
		{
			if (SpawnPoints[Idx]->GetChildActor())
			{
				APlayerStart* PlayerStatPtr = Cast<APlayerStart>(SpawnPoints[Idx]->GetChildActor());
				if (PlayerStatPtr)
				{
					PlayerStatPtr->PlayerStartTag = PlayerStartTag;
				}
			}
		}
	});
}

void ATDRL_PlayersSpawn::RefreshLocationSpawnPoints()
{
	const int32 Columns = FMath::CeilToInt32(FMath::Sqrt(static_cast<float>(SpawnsNumber)));
	const FVector CenterOffset = FVector((Columns - 1) * InitialGridSize / 2.0f, (Columns - 1) * InitialGridSize / 2.0f,
	                                     -100.0f);

	for (int32 Idx = 0; Idx < SpawnPoints.Num(); Idx++)
	{
		const int32 CRow = FMath::FloorToInt32(static_cast<float>(Idx / Columns));
		const int32 CColumn = Idx - (CRow * Columns);

		if (SpawnPoints[Idx])
		{
			SpawnPoints[Idx]->SetRelativeLocation(
				FVector(CColumn * InitialGridSize, CRow * InitialGridSize, 0.0f) - CenterOffset);
		}
	}

	if (ActivationArea->GetRelativeLocation().Equals(FVector(0.0f, 0.0f, 200.0f), 1.0f) && ActivationArea->
		GetRelativeScale3D().Equals(FVector(1.0f)))
	{
		ActivationArea->SetBoxExtent(FVector(Columns * InitialGridSize, Columns * InitialGridSize, 200.0f));
	}
}

// Called every frame
void ATDRL_PlayersSpawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATDRL_PlayersSpawn::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	if (!GetWorld())
	{
		return;
	}

	if (SpawnPoints.Num() == 0)
	{
		RefreshSpawnPoints();
	}
	else
	{
		if (!SpawnPoints[0] || SpawnPoints.Num() != SpawnsNumber)
		{
			RefreshSpawnPoints();
		}
	}

	RefreshAllPlayerStartTags();
}

#if WITH_EDITOR
void ATDRL_PlayersSpawn::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.Property)
	{
		TArray<FName> ExludedVar = TArray<FName>{"PlayerStartTag"};

		if (PropertyChangedEvent.Property->GetFName() == FName("PlayerStartTag"))
		{
			RefreshAllPlayerStartTags();
			return;
		}
		if (!ExludedVar.Contains(PropertyChangedEvent.Property->GetFName()))
		{
			RefreshSpawnPoints();
			return;
		}
	}
}
#endif

APlayerStart* ATDRL_PlayersSpawn::GetRandomPlayerStartActor() const
{
	if (SpawnPoints.Num() == 0)
	{
		return nullptr;
	}

	const int32 RandomIdx = FMath::RandRange(0, SpawnPoints.Num() - 1);

	return Cast<APlayerStart>(SpawnPoints[RandomIdx]->GetChildActor());
}
