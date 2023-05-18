// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_NPCSpawn.h"
#include "TDRL_AISplineTool.h"
#include "TDRL_Character.h"
#include "TDRL_NPCController.h"
#include "TDRL_BFL_Global.h"

#include "Components/CapsuleComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/BillboardComponent.h"
#include "Components/TextRenderComponent.h"
#include "Components/SkeletalMeshComponent.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISense_Hearing.h"

#include "Kismet/GameplayStatics.h"
#include "Engine/TriggerVolume.h"
#include "TimerManager.h"

#include "Engine/Selection.h"

#if WITH_EDITOR
#include "Editor/EditorEngine.h"
#endif

// Sets default values
ATDRL_NPCSpawn::ATDRL_NPCSpawn()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->SetMobility(EComponentMobility::Static);
	Capsule->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Capsule->SetCapsuleHalfHeight(92.0f);
	Capsule->SetCapsuleRadius(28.0f);
	SetRootComponent(Capsule);

	Direction = CreateDefaultSubobject<UArrowComponent>(TEXT("Direction"));
	Direction->SetMobility(EComponentMobility::Static);
	Direction->SetupAttachment(Capsule);

	SpawnTitle = CreateDefaultSubobject<UTextRenderComponent>(TEXT("SpawnTitle"));
	SpawnTitle->SetRelativeLocation(FVector(0.0f, 0.0f, 100.0f));
	SpawnTitle->SetMobility(EComponentMobility::Static);
	SpawnTitle->SetHiddenInGame(true);
	SpawnTitle->SetHorizontalAlignment(EHorizTextAligment::EHTA_Left);
	SpawnTitle->SetupAttachment(Capsule);

	RefreshSpawnName();

	Billboard = CreateDefaultSubobject<UBillboardComponent>(TEXT("Billboard"));
	Billboard->SetMobility(EComponentMobility::Static);
	Billboard->SetupAttachment(Capsule);
}

// Called when the game starts or when spawned
void ATDRL_NPCSpawn::BeginPlay()
{
	Super::BeginPlay();

	if (GetLocalRole() == ENetRole::ROLE_Authority)
	{
		if (Triggers.Num() == 0)
		{
			SpawnNPC();
		}
		else
		{
			for (int32 i = 0; i < Triggers.Num(); i++)
			{
				if (Triggers[i])
				{
					if (Triggers[i]->OnActorBeginOverlap.IsBound())
						Triggers[i]->OnActorBeginOverlap.RemoveAll(this);
					if (Triggers[i]->OnActorEndOverlap.IsBound())
						Triggers[i]->OnActorEndOverlap.RemoveAll(this);

					Triggers[i]->OnActorBeginOverlap.AddDynamic(this, &ATDRL_NPCSpawn::OverlapTriggerBegin);
					Triggers[i]->OnActorEndOverlap.AddDynamic(this, &ATDRL_NPCSpawn::OverlapTriggerEnd);
				}
			}
		}
	}
}

void ATDRL_NPCSpawn::OverlapTriggerBegin(AActor* ThisActor, AActor* OtherActor)
{
	if (bCharacterIsDead)
	{
		return;
	}

	if (GetLocalRole() != ENetRole::ROLE_Authority)
	{
		return;
	}

	if (DespawnDelayHandle.IsValid())
	{
		GetWorld()->GetTimerManager().ClearTimer(DespawnDelayHandle);
		DespawnDelayHandle.Invalidate();
	}

	if (!SpawnedCharacter)
	{
		SpawnNPC();
	}
}

void ATDRL_NPCSpawn::OverlapTriggerEnd(AActor* ThisActor, AActor* OtherActor)
{
	if (bCharacterIsDead)
	{
		return;
	}

	if (GetLocalRole() != ENetRole::ROLE_Authority || bDisableDespawn)
	{
		return;
	}

	if (SpawnedCharacter)
	{
		bool bCharStillOverlapping = false;

		for (int32 i = 0; i < Triggers.Num() && !bCharStillOverlapping; i++)
		{
			TArray<AActor*> CArr = TArray<AActor*>();
			Triggers[i]->GetOverlappingActors(CArr, ATDRL_Character::StaticClass());

			for (int32 i2 = 0; i2 < CArr.Num(); i2++)
			{
				if (CArr[i2]->GetInstigatorController())
				{
					if (CArr[i2]->GetInstigatorController()->IsPlayerController())
					{
						bCharStillOverlapping = true;
						break;
					}
				}
			}
		}

		if (!bCharStillOverlapping)
		{
			if (DespawnDelay > 0.0f)
			{
				GetWorld()->GetTimerManager().SetTimer(DespawnDelayHandle, this, &ATDRL_NPCSpawn::DespawnNPC,
				                                       DespawnDelay, false);
			}
			else
			{
				DespawnNPC();
			}
		}
	}
}

void ATDRL_NPCSpawn::SpawnNPC()
{
	if (bCharacterIsDead)
	{
		return;
	}

	if (SpawnedCharacter || AIController || !AIControllerClass || !SpawnClass)
	{
		return;
	}

	FActorSpawnParameters NewNPCParam = FActorSpawnParameters();
	NewNPCParam.bAllowDuringConstructionScript = false;
	NewNPCParam.bNoFail = true;

	AIController = GetWorld()->SpawnActor<ATDRL_NPCController>(AIControllerClass, GetActorTransform(), NewNPCParam);
	SpawnedCharacter = GetWorld()->SpawnActor<ATDRL_Character>(SpawnClass, GetActorTransform(), NewNPCParam);

	SpawnedCharacter->OnDeath.AddDynamic(this, &ATDRL_NPCSpawn::CharacterDied);

	if (!SpawnedCharacter || !AIController)
	{
		return;
	}

	UTDRL_BFL_Global::ApplyCustomProperties(this, CharacterCustomProperties, SpawnedCharacter);
	UTDRL_BFL_Global::ApplyCustomProperties(this, ControllerCustomProperties, AIController);

	AIController->RunBehaviorTree(AIBehavior);
	UBlackboardComponent* OutComp = nullptr;
	AIController->UseBlackboard(AIBlackBoard, OutComp);
	AIController->Possess(SpawnedCharacter);

	if (PatrolTarget)
	{
		AIController->SetPatrolTarget(PatrolTarget);
		AIController->SetUseRandomAISplineToolPoints(bUseAISplineToolRandomPoints);
	}

	for (int32 i = 0; i < SpawnInventory.Num() && i < SpawnedCharacter->InitialInventorySlots; i++)
	{
		if (!SpawnInventory[i])
		{
			continue;
		}

		ATDRL_Item* NewItem = GetWorld()->SpawnActor<ATDRL_Item>(SpawnInventory[i], GetActorTransform(), NewNPCParam);

		if (NewItem)
		{
			SpawnedCharacter->PickupItem(NewItem);
		}
	}

	if (SpawnCosmeticParameter.IsValidCosmeticData())
	{
		SpawnedCharacter->GetMesh()->SetSkeletalMesh(
			UTDRL_BFL_Global::MergeSkeletalMeshes(
				this, UTDRL_BFL_Global::CosmeticParamToMergeParam(this, SpawnCosmeticParameter)), false);
	}

	//SpawnedCharacter->GetPerceptionComponent()->SetSenseEnabled(UAISense_Hearing::StaticClass(), true);
	SpawnedCharacter->GetMesh()->SetCustomDepthStencilValue(StencilValue);
	SpawnedCharacter->GetCharacterMovement()->SetAvoidanceEnabled(true);

	if (bSpawnInSightArea)
	{
		UTDRL_BFL_Global::SetActorHiddenInGameWithAttached(this, SpawnedCharacter, true);
	}

	NPCSpawned(SpawnedCharacter);
}

void ATDRL_NPCSpawn::DespawnNPC()
{
	if (bCharacterIsDead)
	{
		return;
	}

	if (!SpawnedCharacter)
	{
		return;
	}

	NPCDespawning(SpawnedCharacter);
	SpawnedCharacter->DestroyAllItems(true);
	SpawnedCharacter->OnDeath.RemoveAll(this);
	SpawnedCharacter->Destroy();
	SpawnedCharacter = nullptr;

	AIController->Destroy();
	AIController = nullptr;
}

void ATDRL_NPCSpawn::RefreshSpawnName()
{
	FString OutName;

	OutName.Append("CLASS");
	OutName.Append(LINE_TERMINATOR);

	if (SpawnClass)
	{
		OutName.Append(SpawnClass->GetFName().ToString());
	}
	else
	{
		OutName.Append("No Character Class");
	}

	OutName.Append(LINE_TERMINATOR);

	if (AIControllerClass)
	{
		OutName.Append(AIControllerClass->GetFName().ToString());
	}
	else
	{
		OutName.Append("No Controller Class");
	}

	OutName.Append(LINE_TERMINATOR);

	if (Triggers.Num() > 0)
	{
		OutName.Append(LINE_TERMINATOR);
		OutName.Append("TRIGGERS");
		OutName.Append(LINE_TERMINATOR);

		for (auto& Trig : Triggers)
		{
			if (Trig)
			{
				OutName.Append(Trig->GetActorNameOrLabel());
				OutName.Append(LINE_TERMINATOR);
			}
		}
	}

	OutName.Append("---");
	OutName.Append(LINE_TERMINATOR);

	if (bDisableDespawn)
	{
		OutName.Append("Do not despawn");
		OutName.Append(LINE_TERMINATOR);
	}
	else
	{
		OutName.Append("Despawn time is: ");
		OutName.Append(FString::SanitizeFloat(DespawnDelay));
		OutName.Append(LINE_TERMINATOR);
	}


	SpawnTitle->SetText(FText::FromString(OutName));
}

void ATDRL_NPCSpawn::CharacterDied(FDeathData OutDeathData)
{
	bCharacterIsDead = true;
	OnSpawnedDeath.Broadcast(OutDeathData);
	NPCDied(SpawnedCharacter);
}

// Called every frame
void ATDRL_NPCSpawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATDRL_NPCSpawn::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	RefreshSpawnName();
}

#if WITH_EDITOR

void ATDRL_NPCSpawn::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.Property)
	{
		RefreshSpawnName();
	}
}

void ATDRL_NPCSpawn::SelectAllNPCSpawns()
{
	GEditor->SelectAllActorsWithClass(false);
}

void ATDRL_NPCSpawn::SelectNPCSpawnsSharingOneTrigger()
{
	TArray<AActor*> NPCSpawns;
	UGameplayStatics::GetAllActorsOfClass(this, ATDRL_NPCSpawn::StaticClass(), NPCSpawns);

	for (auto& ASelec : NPCSpawns)
	{
		ATDRL_NPCSpawn* CSpawn = Cast<ATDRL_NPCSpawn>(ASelec);

		if (CSpawn)
		{
			for (auto& TrigOut : CSpawn->Triggers)
			{
				if (Triggers.Contains(TrigOut))
				{
					GEditor->SelectActor(ASelec, true, false);
					break;
				}
			}
		}
	}
}

void ATDRL_NPCSpawn::SelectNPCSpawnsMatchingTriggers()
{
	TArray<AActor*> NPCSpawns;
	UGameplayStatics::GetAllActorsOfClass(this, ATDRL_NPCSpawn::StaticClass(), NPCSpawns);

	for (auto& ASelec : NPCSpawns)
	{
		ATDRL_NPCSpawn* CSpawn = Cast<ATDRL_NPCSpawn>(ASelec);

		if (CSpawn)
		{
			bool bMatching = true;

			if (CSpawn->Triggers.Num() == Triggers.Num())
			{
				for (auto& TrigOut : CSpawn->Triggers)
				{
					if (!Triggers.Contains(TrigOut))
					{
						bMatching = false;
						break;
					}
				}
			}
			else
			{
				bMatching = false;
			}

			if (bMatching)
			{
				GEditor->SelectActor(ASelec, true, true);
			}
		}
	}
}

void ATDRL_NPCSpawn::SelectTriggers()
{
	USelection* CurrSelect = GEditor->GetSelectedActors();
	TArray<ATDRL_NPCSpawn*> SelectedActors = TArray<ATDRL_NPCSpawn*>();
	CurrSelect->GetSelectedObjects<ATDRL_NPCSpawn>(SelectedActors);

	for (auto& CAct : SelectedActors)
	{
		for (auto& CTrig : CAct->Triggers)
		{
			GEditor->SelectActor(CTrig, true, false);
		}
	}

	TArray<ATDRL_NPCSpawn*> RemoveSpawns = TArray<ATDRL_NPCSpawn*>();
	CurrSelect->GetSelectedObjects<ATDRL_NPCSpawn>(RemoveSpawns);

	for (auto& Desel : RemoveSpawns)
	{
		GEditor->SelectActor(Desel, false, Desel == RemoveSpawns.Last());
	}
}

#endif

void ATDRL_NPCSpawn::RestoreSpawn()
{
	if (SpawnedCharacter)
	{
		SpawnedCharacter->Destroy();
	}

	if (AIController)
	{
		AIController->Destroy();
	}

	SpawnedCharacter = nullptr;
	AIController = nullptr;
	bCharacterIsDead = false;
	SpawnRestored();
}

void ATDRL_NPCSpawn::NPCDied_Implementation(ATDRL_Character* NPCCharacter)
{
}

void ATDRL_NPCSpawn::NPCSpawned_Implementation(ATDRL_Character* NPCCharacter)
{
}

void ATDRL_NPCSpawn::NPCDespawning_Implementation(ATDRL_Character* NPCCharacter)
{
}

void ATDRL_NPCSpawn::SpawnRestored_Implementation()
{
}
