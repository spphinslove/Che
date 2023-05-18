// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TDRL_PhysicsDoor.generated.h"

UCLASS()
class TOPDOWNROGUELITE_API ATDRL_PhysicsDoor : public AActor
{
	GENERATED_BODY()

public:
	ATDRL_PhysicsDoor();

	/*Should start locked?*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDRL|PhysDoor")
	uint8 bStartLocked : 1;
	/*Which classes are accepted for physics activation*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDRL|PhysDoor")
	TSet<TSubclassOf<class AActor>> ActivationClasses;
	/*Collision profile when open*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDRL|PhysDoor|Open")
	FName CollisionProfileNameOpen = FName("BlockAllDynamic");
	/*NavMesh class when open*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDRL|PhysDoor|Open")
	TSubclassOf<class UNavArea> NavClassOpen;
	/*Collision profile when closed*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDRL|PhysDoor|Close")
	FName CollisionProfileNameClose = FName("BlockAll");
	/*NavMesh class when closed*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TDRL|PhysDoor|Close")
	TSubclassOf<class UNavArea> NavClassClose;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class USceneComponent* Root;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* RootMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* ActivationArea;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UPhysicsConstraintComponent* Constraint;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* DoorMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UNavModifierComponent* NavModifier;

	UPROPERTY(Replicated)
	float YawDoor;
	UPROPERTY(ReplicatedUsing = OnRep_bIsOpen)
	uint8 bIsOpen : 1;
	UFUNCTION()
	virtual void OnRep_bIsOpen();

	UFUNCTION()
	virtual void GatherYawOnServer(const float DeltaTime);
	UFUNCTION()
	virtual void AdjustYawOnClients(const float DeltaTime);

	UFUNCTION()
	virtual void OverlapAreaBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	                              UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
	                              const FHitResult& Hit);
	UFUNCTION()
	virtual void OverlapAreaEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
	                            class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY()
	uint8 bWantsToLock : 1;
	UPROPERTY()
	uint8 bLocked : 1;

public:
	/*Get the static mesh component for this door*/
	UFUNCTION(BlueprintPure, Category = "TDRL|PhysDoor|Components",
		meta = (DisplayName = "GetDoorMesh", Keywords = "Get Door Mesh TDRL"))
	class UStaticMeshComponent* GetDoorMesh() const
	{
		return DoorMesh;
	}

	/*Returns true if it's open (is simulating physics)*/
	UFUNCTION(BlueprintPure, Category = "TDRL|PhysDoor",
		meta = (DisplayName = "GetIsOpen", Keywords = "Get Is Open TDRL"))
	bool GetIsOpen() const
	{
		return bIsOpen;
	}

	/*Returns true if it's locked*/
	UFUNCTION(BlueprintPure, Category = "TDRL|PhysDoor",
		meta = (DisplayName = "GetIsLocked", Keywords = "Get Is Locked TDRL"))
	bool GetIsLocked() const
	{
		return bLocked;
	}

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

	/*Open or close this door*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|PhysDoor", BlueprintAuthorityOnly,
		meta = (DisplayName = "SetDoorOpen", Keywords = "Set Door Open TDRL"))
	virtual void SetDoorOpen(const bool bOpen);
	/*Lock or unlock this door*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|PhysDoor", BlueprintAuthorityOnly,
		meta = (DisplayName = "SetDoorLocked", Keywords = "Set Door Locked TDRL"))
	virtual void SetDoorLocked(const bool InLocked);

	UFUNCTION(NetMulticast, Reliable)
	virtual void AddImpulseAtLocation_Multicast(const FVector Impulse, const FVector Location);
};
