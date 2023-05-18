// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TDRL_Ammo.generated.h"

UENUM(BlueprintType)
enum class EAmmoRefillMethod : uint8
{
	ARM_Percentage UMETA(DisplayName = "Percentage"),
	ARM_Exact UMETA(DisplayName = "Exact"),
	ARM_Full UMETA(DisplayName = "Full"),
};

UCLASS()
class TOPDOWNROGUELITE_API ATDRL_Ammo : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATDRL_Ammo();

	/*Tag for ammo filtering. Setting this value to something different from "None" will force the player to equip a weapon with the same AmmoTag to be activated*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDRL|Ammo")
	FName AmmoTag = FName();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDRL|Ammo")
	EAmmoRefillMethod RefillMethod = EAmmoRefillMethod::ARM_Percentage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDRL|Ammo",
		meta = (EditCondition = "RefillMethod==EAmmoRefillMethod::ARM_Percentage", EditConditionHides))
	float RefillPercentage = 30.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDRL|Ammo",
		meta = (EditCondition = "RefillMethod==EAmmoRefillMethod::ARM_Exact", EditConditionHides))
	int32 RefillExact = 10;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* Mesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* Trigger;

	UFUNCTION()
	virtual void OverlapAreaBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	                              UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
	                              const FHitResult& Hit);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "TDRL|PhysDoor", BlueprintAuthorityOnly,
		meta = (DisplayName = "RefillCharacter", Keywords = "Refill Character Firearm Ammo TDRL"))
	virtual void RefillCharacter(class ATDRL_Character* InChar);
};
