// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "TDRL_GameplayTypes.h"
#include "TDRL_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNROGUELITE_API ATDRL_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATDRL_PlayerController();

#pragma region Utility

	UFUNCTION(BlueprintCallable, Category = "TDRL|PlayerController|Utility",
		meta = (DisplayName = "Get Actors Of Class In Radius Under Mouse", Keywords =
			"Get Actors Of Class In Radius Under Mouse TDRL"))
	virtual bool GetActorsOfClassInRadiusUnderMouse(const TArray<TSubclassOf<AActor>> Classes, const float Radius,
	                                                const TArray<TEnumAsByte<EObjectTypeQuery>>& Channels,
	                                                const TArray<AActor*>& IgnoreActors, TArray<AActor*>& OutActors,
	                                                const bool bDebug) const;

	UFUNCTION(BlueprintCallable, Category = "TDRL|PlayerController|Utility",
		meta = (DisplayName = "Get Closest Actor Of Class In Radius Under Mouse", Keywords =
			"Get Closest Actor Of Class In Radius Under Mouse TDRL"))
	virtual AActor* GetClosestActorOfClassInRadiusUnderMouse(const TArray<TSubclassOf<AActor>> Classes,
	                                                         const float Radius,
	                                                         const TArray<TEnumAsByte<EObjectTypeQuery>>& Channels,
	                                                         const TArray<AActor*>& IgnoreActors,
	                                                         const bool bDebug) const;

#pragma endregion

#pragma region ControlRotation

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDRL|PlayerController")
	EControlRotationType ControlRotationType;
	UFUNCTION(BlueprintCallable, Category = "TDRL|PlayerController",
		meta = (DisplayName = "Get Control Rotation Type", Keywords = "Get Control Rotation Type TDRL"))
	virtual EControlRotationType GetControlRotationType() const;
	UFUNCTION(BlueprintCallable, Category = "TDRL|PlayerController",
		meta = (DisplayName = "Set Control Rotation Type", Keywords = "Set Control Rotation Type TDRL"))
	virtual void SetControlRotationType(const EControlRotationType NewValue);

protected:
	UPROPERTY()
	FVector LocationTarget = FVector(0.0f);

public:
	UFUNCTION(BlueprintPure, Category = "TDRL|PlayerController",
		meta = (DisplayName = "Get Location Target", Keywords = "Get Location Target TDRL"))
	virtual FVector GetLocationTarget() const;
	UFUNCTION(BlueprintCallable, Category = "TDRL|PlayerController",
		meta = (DisplayName = "Set Location Target", Keywords = "Set Location Target TDRL"))
	virtual void SetLocationTarget(const FVector TargetLocation);

#pragma endregion

#pragma region LockTarget

protected:
	UPROPERTY()
	class AActor* LockedTarget = nullptr;

public:
	UFUNCTION(BlueprintCallable, Category = "TDRL|PlayerController|AimOffset",
		meta = (DisplayName = "Get Locked Target", Keywords = "Get Locked Target TDRL"))
	virtual AActor* GetLockedTarget() const;
	UFUNCTION(BlueprintCallable, Category = "TDRL|PlayerController|AimOffset",
		meta = (DisplayName = "Set Locked Target", Keywords = "Set Locked Target TDRL"))
	virtual void SetLockedTarget(class AActor* NewTarget);

#pragma endregion

#pragma region Possess

public:
	UPROPERTY(Replicated, VisibleDefaultsOnly, BlueprintReadWrite, Category = "TDRL|PlayerController|Runtime")
	class ATDRL_Character* PossessedTDRLCharacter;

protected:
	UFUNCTION(Server, Reliable)
	virtual void TDRLCharacterChanged_Server(APawn* InPawn);

#pragma endregion

#pragma region Overrides

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;
	virtual void BeginPlayingState() override;
	virtual void AcknowledgePossession(APawn* InPawn) override;
	virtual void ServerAcknowledgePossession_Implementation(APawn* InPawn) override;

public:
	virtual void Tick(float DeltaTime) override;
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

#pragma endregion

#pragma region TickUpdates

public:
	UPROPERTY(BlueprintReadOnly, Category = "TDRL|PlayerController|Runtime")
	FHitResult LastValidHitUnderMouse;
	UPROPERTY(BlueprintReadOnly, Category = "TDRL|PlayerController|Runtime")
	uint8 bBlockingUnderMouse : 1;

protected:
	UFUNCTION()
	virtual void UpdateTraceUnderMouse();
	UFUNCTION()
	virtual void UpdateControlRotation();

#pragma endregion

#pragma region Aim Offset

public:
	UPROPERTY(BlueprintReadOnly, Category = "TDRL|PlayerController")
	float AimOffsetUpdateTime = 0.2f;

protected:
	UFUNCTION(BlueprintCallable, Category = "TDRL|PlayerController|AimOffset",
		meta = (DisplayName = "UpdateAimOffset", Keywords = "Update Aim Offset Value TDRL"))
	virtual void UpdateAimOffsetValue(const FVector2D NewValue);
	UFUNCTION(Server, Unreliable)
	virtual void UpdateAimOffsetValue_Serv(const FVector2D NewValue);

	UFUNCTION()
	virtual void UpdateOnServerTimerOver();

	UPROPERTY()
	FTimerHandle UpdateAimOffsetServerHandle;
	UPROPERTY()
	uint8 bShouldUsePitch : 1;

public:
	UFUNCTION(BlueprintPure, Category = "TDRL|PlayerController",
		meta = (DisplayName = "GetShouldUsePitch", CompactNodeTitle = "UsePitch", Keywords = "Get Should Use Pitch TDRL"
		))
	virtual bool GetShouldUsePitch() const
	{
		return bShouldUsePitch;
	}

	UFUNCTION(BlueprintCallable, Category = "TDRL|PlayerController",
		meta = (DisplayName = "SetShouldUsePitch", Keywords = "Set Should Use Pitch TDRL"))
	virtual void SetShouldUsePitch(const bool Enable)
	{
		bShouldUsePitch = Enable;
	}

#pragma endregion

#pragma region Cosmetics

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDRL|PlayerController")
	struct FCosmeticParameterList UnloadedCosmeticParameter;
	UFUNCTION(BlueprintPure, Category = "TDRL|PlayerController|Cosmetic",
		meta = (DisplayName = "GetDefaultCharacterCosmetic", Keywords = "Get Default Character Cosmetic TDRL"))
	virtual struct FCosmeticParameterList GetDefaultCharacterCosmetic();

#pragma endregion

#pragma region Spawn

public:
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "TDRL|PlayerController|Runtime")
	FName LatestValidStartTag = FName();

	UFUNCTION(BlueprintNativeEvent, Category = "TDRL|PlayerController|Respawn",
		meta = (DisplayName = "PlayersSpawnAreaOverlapped", Keywords = "Players Spawn Area Overlapped TDRL"))
	void PlayersSpawnAreaOverlapped(class ATDRL_PlayersSpawn* Spawner);

#pragma endregion
};
