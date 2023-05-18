// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_PhysicsDoor.h"
#include "Components/BoxComponent.h"

#include "Net/UnrealNetwork.h"

#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "Components/StaticMeshComponent.h"

#include "NavModifierComponent.h"
#include "NavAreas/NavArea_Default.h"
#include "NavAreas/NavArea_Null.h"

// Sets default values
ATDRL_PhysicsDoor::ATDRL_PhysicsDoor()
	: Super()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetActorTickEnabled(false);
	bWantsToLock = false;
	bLocked = false;
	bStartLocked = false;
	NavClassOpen = UNavArea_Default::StaticClass();
	NavClassClose = UNavArea_Null::StaticClass();
	ActivationClasses = TSet<TSubclassOf<class AActor>>{APawn::StaticClass()};

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	RootMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RootMesh"));
	RootMesh->SetMobility(EComponentMobility::Static);
	RootMesh->SetupAttachment(Root);
	RootMesh->SetCollisionProfileName(FName("BlockAll"));
	RootMesh->SetGenerateOverlapEvents(false);

	ActivationArea = CreateDefaultSubobject<UBoxComponent>(TEXT("ActivationArea"));
	ActivationArea->SetupAttachment(Root);
	ActivationArea->SetCollisionProfileName(FName("Trigger"));
	ActivationArea->SetGenerateOverlapEvents(true);
	ActivationArea->SetCanEverAffectNavigation(false);

	Constraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(TEXT("Constraint"));
	Constraint->SetupAttachment(Root);

	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	DoorMesh->SetupAttachment(Constraint);
	DoorMesh->SetCollisionProfileName(CollisionProfileNameClose);
	DoorMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Ignore);
	DoorMesh->SetMobility(EComponentMobility::Movable);
	DoorMesh->SetEnableGravity(false);
	DoorMesh->SetGenerateOverlapEvents(false);
	DoorMesh->SetCanEverAffectNavigation(false);

	NavModifier = CreateDefaultSubobject<UNavModifierComponent>(TEXT("NavModifier"));
	NavModifier->SetAreaClass((bStartLocked) ? NavClassClose : NavClassOpen);
}

// Called when the game starts or when spawned
void ATDRL_PhysicsDoor::BeginPlay()
{
	Super::BeginPlay();
	ActivationArea->OnComponentBeginOverlap.AddDynamic(this, &ATDRL_PhysicsDoor::OverlapAreaBegin);
	ActivationArea->OnComponentEndOverlap.AddDynamic(this, &ATDRL_PhysicsDoor::OverlapAreaEnd);
	NavModifier->SetAreaClass((bStartLocked) ? NavClassClose : NavClassOpen);

	if (bStartLocked)
	{
		SetDoorLocked(true);
	}
}

void ATDRL_PhysicsDoor::OnRep_bIsOpen()
{
	if (bIsOpen && (bWantsToLock || bLocked))
	{
		return;
	}

	DoorMesh->SetCollisionProfileName((bIsOpen) ? CollisionProfileNameOpen : CollisionProfileNameClose);

	if (bIsOpen)
	{
		DoorMesh->SetCollisionResponseToChannel(RootMesh->GetCollisionObjectType(), ECollisionResponse::ECR_Overlap);
		Constraint->SetConstrainedComponents(RootMesh, FName(), DoorMesh, FName());
		Constraint->SetConstraintReferenceOrientation(EConstraintFrame::Frame2, FVector(0.0f), FVector(0.0f));
		SetActorTickEnabled(true);
	}

	DoorMesh->SetSimulatePhysics(bIsOpen);

	if (!bIsOpen)
	{
		DoorMesh->AttachToComponent(Constraint, FAttachmentTransformRules::KeepWorldTransform);
	}
}

void ATDRL_PhysicsDoor::GatherYawOnServer(const float DeltaTime)
{
	if (GetLocalRole() != ENetRole::ROLE_Authority)
	{
		return;
	}

	if (!DoorMesh)
	{
		return;
	}

	const float CurrentYaw = FRotator(
			Constraint->GetComponentTransform().InverseTransformRotation(DoorMesh->GetComponentRotation().Quaternion()))
		.
		Yaw;

	if (bIsOpen)
	{
		YawDoor = CurrentYaw;
	}
	else
	{
		if (!FMath::IsNearlyZero(CurrentYaw, 0.01f))
		{
			DoorMesh->SetRelativeRotation(FRotator(0.0f, FMath::FInterpTo(CurrentYaw, 0.0f, DeltaTime, 2.0f), 0.0f));
			YawDoor = CurrentYaw;
		}
		else
		{
			YawDoor = 0.0f;
			SetActorTickEnabled(false);
			if (bWantsToLock)
			{
				bLocked = true;
			}
		}
	}
}

void ATDRL_PhysicsDoor::AdjustYawOnClients(const float DeltaTime)
{
	if (GetLocalRole() == ENetRole::ROLE_Authority)
	{
		return;
	}

	if (!DoorMesh)
	{
		return;
	}

	const float CurrentYaw = FRotator(
			Constraint->GetComponentTransform().InverseTransformRotation(DoorMesh->GetComponentRotation().Quaternion()))
		.
		Yaw;

	if (bIsOpen)
	{
		if (!FMath::IsNearlyEqual(CurrentYaw, YawDoor, 0.1f))
		{
			DoorMesh->AddAngularImpulseInDegrees(
				FRotator(0.0f, YawDoor - FMath::FInterpTo(CurrentYaw, YawDoor, DeltaTime, 6.0f), 0.0f).Euler(),
				FName("Door"), true);
		}
	}
	else
	{
		if (!FMath::IsNearlyZero(CurrentYaw, 0.1f))
		{
			DoorMesh->SetRelativeRotation(FRotator(0.0f, FMath::FInterpTo(CurrentYaw, 0.0f, DeltaTime, 2.0f), 0.0f));
		}
		else
		{
			SetActorTickEnabled(false);
		}
	}
}

void ATDRL_PhysicsDoor::OverlapAreaBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                         UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
                                         const FHitResult& Hit)
{
	if (GetLocalRole() != ENetRole::ROLE_Authority)
	{
		return;
	}

	if (!bIsOpen)
	{
		bool bShouldOpen = false;

		for (auto& CClass : ActivationClasses.Array())
		{
			if (CClass == OtherActor->GetClass() || OtherActor->GetClass()->IsChildOf(CClass))
			{
				bShouldOpen = true;
				break;
			}
		}

		if (bShouldOpen)
		{
			SetDoorOpen(true);
		}
	}
}

void ATDRL_PhysicsDoor::OverlapAreaEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                                       UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (GetLocalRole() != ENetRole::ROLE_Authority)
	{
		return;
	}

	if (bIsOpen)
	{
		bool bKeepOpen = false;

		for (auto& CClass : ActivationClasses.Array())
		{
			TArray<AActor*> OverlappingActorsThisClass = TArray<AActor*>();
			ActivationArea->GetOverlappingActors(OverlappingActorsThisClass, CClass);

			if (OverlappingActorsThisClass.Num() > 0)
			{
				bKeepOpen = true;
				break;
			}
		}

		if (!bKeepOpen)
		{
			SetDoorOpen(false);
		}
	}
}

#if WITH_EDITOR
void ATDRL_PhysicsDoor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	if (PropertyChangedEvent.Property)
	{
		if (PropertyChangedEvent.Property->GetFName() == FName("bStartLocked"))
		{
			NavModifier->SetAreaClass((bStartLocked) ? NavClassClose : NavClassOpen);
		}
	}
}
#endif

// Called every frame
void ATDRL_PhysicsDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	GatherYawOnServer(DeltaTime);
	AdjustYawOnClients(DeltaTime);
}

void ATDRL_PhysicsDoor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ATDRL_PhysicsDoor, YawDoor);
	DOREPLIFETIME_CONDITION_NOTIFY(ATDRL_PhysicsDoor, bIsOpen, COND_None, REPNOTIFY_OnChanged);
}

void ATDRL_PhysicsDoor::SetDoorOpen(const bool bOpen)
{
	if (GetLocalRole() != ENetRole::ROLE_Authority)
	{
		return;
	}

	if (bOpen && (bWantsToLock || bLocked))
	{
		return;
	}

	bIsOpen = bOpen;

	if (bOpen)
	{
		DoorMesh->SetCollisionProfileName(CollisionProfileNameOpen);
		DoorMesh->SetCollisionResponseToChannel(RootMesh->GetCollisionObjectType(), ECollisionResponse::ECR_Overlap);
		Constraint->SetConstrainedComponents(RootMesh, FName(), DoorMesh, FName());
		Constraint->SetConstraintReferenceOrientation(EConstraintFrame::Frame2, FVector(0.0f), FVector(0.0f));
		DoorMesh->SetSimulatePhysics(true);
		SetActorTickEnabled(true);
	}
	else
	{
		DoorMesh->SetSimulatePhysics(false);
		DoorMesh->AttachToComponent(Constraint, FAttachmentTransformRules::KeepWorldTransform);
		DoorMesh->SetCollisionProfileName(CollisionProfileNameClose);
	}
}

void ATDRL_PhysicsDoor::SetDoorLocked(const bool InLocked)
{
	if (GetLocalRole() != ENetRole::ROLE_Authority)
	{
		return;
	}

	if (bWantsToLock == InLocked)
	{
		return;
	}

	if (InLocked)
	{
		bWantsToLock = true;
		NavModifier->SetAreaClass(NavClassClose);
		SetDoorOpen(false);
	}
	else
	{
		bWantsToLock = false;
		bLocked = false;
		NavModifier->SetAreaClass(NavClassOpen);

		bool bShouldOpen = false;

		for (auto& CClass : ActivationClasses)
		{
			TArray<AActor*> OverlappingActorsThisClass = TArray<AActor*>();
			ActivationArea->GetOverlappingActors(OverlappingActorsThisClass, CClass);

			if (OverlappingActorsThisClass.Num() > 0)
			{
				bShouldOpen = true;
				break;
			}
		}

		if (bShouldOpen)
		{
			SetDoorOpen(true);
		}
	}
}

void ATDRL_PhysicsDoor::AddImpulseAtLocation_Multicast_Implementation(const FVector Impulse, const FVector Location)
{
	DoorMesh->AddImpulseAtLocation(Impulse, Location, FName());
}
