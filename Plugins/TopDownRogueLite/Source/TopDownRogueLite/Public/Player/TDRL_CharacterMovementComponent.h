// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TDRL_GameplayTypes.h"
#include "TDRL_CharacterMovementComponent.generated.h"

/**
 * 
 */

/** Custom movement modes for Characters. */
UENUM(BlueprintType)
enum ECustomMovementMode
{
	CMOVE_Dash UMETA(DisplayName = "Dash"),
	CMOVE_MAX UMETA(Hidden),
};

UCLASS(BlueprintType, meta = (BlueprintSpawnableComponent, ImplementedBy = "ATDRL_Character"))
class TOPDOWNROGUELITE_API UTDRL_CharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

	friend class FSavedMove_My;

public:
	UTDRL_CharacterMovementComponent();

	/*Main walking speed in cm/s*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDRL|Movements|Walk")
	float SpeedA = 600.0f;
	/*Alternative walking speed in cm/s*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDRL|Movements|Walk")
	float SpeedB = 250.0f;
	/*Main walking acceleration*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDRL|Movements|Walk")
	float AccelerationA = 4096.0f;
	/*Alternative walking acceleration*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDRL|Movements|Walk")
	float AccelerationB = 2048.0f;
	/*Max amount of Sprints this character can do before waiting for recharge*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TDRL|Movements|Dash")
	uint8 MaxDash = 1;
	/*Trace channels to test for movement prevision*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TDRL|Movements|Dash")
	TSet<TEnumAsByte<EObjectTypeQuery>> DashGroundTestChannels;
	// = TSet<TEnumAsByte<ECollisionChannel>>{ ECollisionChannel::ECC_WorldStatic };
	/*Dash speed in cm/s*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TDRL|Movements|Dash")
	float DashSpeed = 4096.0f;
	/*Acceleration when dashing*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TDRL|Movements|Dash")
	float DashAcceleration = 8192.0f;
	/*Dash length in seconds*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TDRL|Movements|Dash")
	float DashLength = 0.15f;
	/*Time needed to recharge the dash function*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TDRL|Movements|Dash")
	float DashCountdown = 1.0f;
	/*Force applied to any physics simulated body in front of the character while dashing*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TDRL|Movements|Dash")
	float DashForce = 100.0f;
	/*Channels to test while tracing for push*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TDRL|Movements|Dash")
	TSet<TEnumAsByte<EObjectTypeQuery>> TraceForActorsPushChannels;
	//= TSet<TEnumAsByte<ECollisionChannel>>{ ECollisionChannel::ECC_WorldDynamic,  ECollisionChannel::ECC_Pawn, ECollisionChannel::ECC_PhysicsBody, ECollisionChannel::ECC_Destructible, ECollisionChannel::ECC_Vehicle };

protected:
	/*Dash effects when dashing (VFX and SFX)*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TDRL|Movements|Dash")
	struct FDashEffect DashEffects;
	/*Show debug*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TDRL|Movements|Dash")
	uint8 bShowVisualDebug : 1;

public:
	/*Return remaining Dash Countdown*/
	UFUNCTION(BlueprintPure, Category = "TDRL|Movements",
		meta = (DisplayName = "GetRemainingDashCountdown", CompactNodeTitle = "DashCountdown", Keywords =
			"Get Remaining Dash Countdown TDRL"))
	float GetRemainingDashCD() const;
	/*Return remaining Dash Countoun as percentage*/
	UFUNCTION(BlueprintPure, Category = "TDRL|Movements",
		meta = (DisplayName = "GetRemainingDashCountdownPercent", CompactNodeTitle = "DashCountdownPercent", Keywords =
			"Get Remaining Dash Countdown Percent TDRL"))
	float GetRemainingDashCDPercent() const;

	/*Return number of dashes left before the character will need to wait the countown before being able to dash again*/
	UFUNCTION(BlueprintPure, Category = "TDRL|Movements",
		meta = (DisplayName = "GetDashLeft", Keywords = "Get Dash Left TDRL"))
	uint8 GetDashLeft() const
	{
		return MaxDash - DashCount;
	};
	/*Return true if character is currently dashin*/
	UFUNCTION(BlueprintPure, Category = "TDRL|Movements",
		meta = (DisplayName = "IsDashing", Keywords = "Get Is Dashing TDRL"))
	bool IsDashing() const
	{
		return WantsToDash;
	};

	/*Enable or disable alternative walk settings*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|Movements",
		meta = (DisplayName = "SetAlternativeWalk", Keywords = "Set Alternative Walk TDRL"))
	void SetAlternativeWalk(const bool Enable);

	/* Requests that the character begins dashing. */
	UFUNCTION(BlueprintCallable, Category = "TDRL|Movements", meta = (DisplayName = "Dash", Keywords = "Set Dash TDRL"))
	void Dash(const bool Enable);
	UFUNCTION()
	void DashCDReset();
	UFUNCTION()
	FVector FindDashDirection() const;
	UFUNCTION()
	bool IsCustomMovementMode(uint8 custom_movement_mode) const;

protected:
	virtual void BeginPlay() override;
	virtual void OnComponentDestroyed(bool bDestroyingHierarchy) override;

	UFUNCTION()
	virtual void SpawnDashEffects();

public:
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void UpdateFromCompressedFlags(uint8 Flags) override;
	virtual void OnMovementModeChanged(EMovementMode PreviousMovementMode, uint8 PreviousCustomMode) override;
	virtual void PhysCustom(float deltaTime, int32 Iterations) override;
	void DashAction(float deltaTime, int32 Iterations);
	virtual float GetMaxSpeed() const override;
	virtual float GetMaxAcceleration() const override;
	virtual void ProcessLanded(const FHitResult& Hit, float remainingTime, int32 Iterations) override;
	virtual FNetworkPredictionData_Client* GetPredictionData_Client() const override;

private:
	UPROPERTY()
	FTimerHandle DashTimerHandle;

	/* Requests */
	UPROPERTY()
	uint8 DashRequired : 1;
	UPROPERTY()
	uint8 AlternativeWalkRequired : 1;

	/* States */
	UPROPERTY()
	uint8 WantsToAlternativeWalk : 1;
	UPROPERTY(ReplicatedUsing = OnRep_WantsToDash)
	uint8 WantsToDash : 1;
	UFUNCTION()
	virtual void OnRep_WantsToDash(const bool OldValue);

	/* Actions data */
	UPROPERTY()
	float DashPast;
	UPROPERTY()
	FVector DashDirection;
	UPROPERTY()
	uint8 DashCount = 0;
};

class FSavedMove_My : public FSavedMove_Character
{
public:
	typedef FSavedMove_Character Super;

	// Resets all saved variables.
	virtual void Clear() override;
	// Store input commands in the compressed flags.
	virtual uint8 GetCompressedFlags() const override;
	// This is used to check whether or not two moves can be combined into one.
	// Basically you just check to make sure that the saved variables are the same.
	virtual bool CanCombineWith(const FSavedMovePtr& NewMovePtr, ACharacter* Character, float MaxDelta) const override;
	// Sets up the move before sending it to the server. 
	virtual void SetMoveFor(ACharacter* Character, float InDeltaTime, FVector const& NewAccel,
	                        class FNetworkPredictionData_Client_Character& ClientData) override;
	// Sets variables on character movement component before making a predictive correction.
	virtual void PrepMoveFor(class ACharacter* Character) override;

private:
	uint8 SavedWantsToAlternativeWalk : 1;
	uint8 SavedWantsToDash : 1;
	uint8 SavedDashCount;
	float SavedDashPast;
};

class FNetworkPredictionData_Client_My : public FNetworkPredictionData_Client_Character
{
public:
	typedef FNetworkPredictionData_Client_Character Super;

	// Constructor
	FNetworkPredictionData_Client_My(const UCharacterMovementComponent& ClientMovement);

	//brief Allocates a new copy of our custom saved move
	virtual FSavedMovePtr AllocateNewMove() override;
};
