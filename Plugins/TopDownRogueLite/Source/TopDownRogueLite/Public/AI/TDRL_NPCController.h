// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TDRL_AITypes.h"
#include "TDRL_NPCController.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNROGUELITE_API ATDRL_NPCController : public AAIController
{
	GENERATED_BODY()

public:
	ATDRL_NPCController();

	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;

	/*Return the current possessed TDRL_Character*/
	UFUNCTION(BlueprintPure, Category = "TDRL|Character",
		meta = (DisplayName = "GetPossessedCharacter(TDRL)", Keywords = "Possess Possessed Character TDRL Top Down"))
	virtual ATDRL_Character* GetPossessedTDRLCharacter() const;

#pragma region BlackboardValues
	/*(Enum) The blackboard's key name for the alert state status (ie. normal, suspicius, alerted...).*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TDRL|AIController|VariablesName")
	FName BBName_AlertState = FName("AlertState");
	/*(Enum) The blackboard's key name for the mobility status*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TDRL|AIController|VariablesName")
	FName BBName_MobilityState = FName("MobilityState");
	/*(Object) The blackboard's key name for the current main Patrol target actor*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TDRL|AIController|VariablesName")
	FName BBName_PatrolTarget = FName("PatrolTarget");
	/*(Bool) The blackboard's key name for using random points when "PatrolTarget" is "AISplineTool"*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TDRL|AIController|VariablesName")
	FName BBName_AISplineToolRandomPoints = FName("AISplineToolRandomPoints");
	/*(Object) The blackboard's key name for the current main AlertThreat target actor (should be the main enemy target to attack)*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TDRL|AIController|VariablesName")
	FName BBName_AlertThreat = FName("AlertThreat");


	/*Random AnimMontage containers, used by nodes like "QueueRandomAnimMontagetoBB" in the Behavior Tree*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TDRL|AIController|Animations")
	TMap<FName, TSubclassOf<UAIAnimMontageContainer>> RandomMontages = TMap<
		FName, TSubclassOf<UAIAnimMontageContainer>>();

	/*Will use GroupName to select a random AnimMontage from a specific group of "RandomMontages"*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|AIController",
		meta = (DisplayName = "GetRandomMontageFromGroup", Keywords = "Random Montage Group AI Behavior"))
	UAnimMontage* GetRandomMontageFromGroup(const FName GroupName)
	{
		if (RandomMontages.Num() == 0)
		{
			return nullptr;
		}

		UAnimMontage* OutMontage = nullptr;
		TSubclassOf<UAIAnimMontageContainer> Subclass = RandomMontages.FindRef(GroupName);

		if (!Subclass)
		{
			Subclass = RandomMontages.Array()[0].Value;
		}

		if (!Subclass)
		{
			return nullptr;
		}

		UAIAnimMontageContainer* ContainerPtr = NewObject<UAIAnimMontageContainer>(this, Subclass.Get());
		OutMontage = ContainerPtr->GetRandomAnimationMontage();

		return OutMontage;
	}

	/*Return current AlertState as byte*/
	UFUNCTION(BlueprintPure, Category = "TDRL|AIController",
		meta = (DisplayName = "GetAlertState", Keywords = "Get Alert State AI Behavior"))
	uint8 GetAlertState() const;
	/*Set current AlertState as byte*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|AIController",
		meta = (DisplayName = "SetAlertState", Keywords = "Set Alert State AI Behavior"))
	bool SetAlertState(uint8 NewState);

	/*Return current MobilityState as byte*/
	UFUNCTION(BlueprintPure, Category = "TDRL|AIController",
		meta = (DisplayName = "GetMobilityState", Keywords = "Get Mobility State AI Behavior"))
	uint8 GetMobilityState() const;
	/*Set current MobilityState as byte*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|AIController",
		meta = (DisplayName = "SetMobilityState", Keywords = "Set Mobility State AI Behavior"))
	bool SetMobilityState(uint8 NewState);

	/*Return current Patrol Target*/
	UFUNCTION(BlueprintPure, Category = "TDRL|AIController",
		meta = (DisplayName = "GetPatrolTarget", Keywords = "Get Patrol Target AI Behavior"))
	AActor* GetPatrolTarget() const;
	/*Set current Patrol Target*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|AIController",
		meta = (DisplayName = "SetPatrolTarget", Keywords = "Set Patrol Target AI Behavior"))
	bool SetPatrolTarget(AActor* ActorToFollow);

	/*Return current Alert Threat.*/
	UFUNCTION(BlueprintPure, Category = "TDRL|AIController",
		meta = (DisplayName = "GetAlertThreat", Keywords = "Get Alert Threat AI Behavior"))
	AActor* GetAlertThreat() const;
	/*Set current Alert Threat.*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|AIController",
		meta = (DisplayName = "SetAlertThreat", Keywords = "Set Alert Threat AI Behavior"))
	bool SetAlertThreat(AActor* AlertThreat);

	/*Return current Alert Threat.*/
	UFUNCTION(BlueprintPure, Category = "TDRL|AIController",
		meta = (DisplayName = "GetUseRandomAISplineToolPoints", Keywords =
			"Get Use Random AI Spline Tool Points AI Behavior"))
	bool GetUseRandomAISplineToolPoints() const;
	/*Set current Alert Threat.*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|AIController",
		meta = (DisplayName = "SetUseRandomAISplineToolPoints", Keywords =
			"Set Use Random AI Spline Tool Points AI Behavior"))
	bool SetUseRandomAISplineToolPoints(const bool NewValue);

#pragma endregion

#pragma region Timers
	/*Time used for any Alert Level reduction, you can override it using "TimeForEachAlarmLevel" and following the Alert (Enum) order.*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TDRL|AIBehavior")
	float DefaultTimeForEachAlarmLevel = 60.0f;
	/*Time used for each specific Alert Level reduction, follows the Alert (Enum) order.*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TDRL|AIBehavior")
	TArray<float> TimeForEachAlarmLevel = TArray<float>();

	/*Alert Reduction TimerHandle.*/
	UPROPERTY(BlueprintReadOnly, Category = "TDRL|AIBehavior|Runtime")
	FTimerHandle AlertReductionTimerHandle;

	/*Modify the current Alert Level to a specific new level.*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|AIBehavior",
		meta = (DisplayName = "ModifyAlertLevel", Keywords = "Alert Level Modify AI Behavior"))
	uint8 ModifyAlertLevel(const int32 DeltaLevel, const int32 MaxAlertStateIndex = 2);

	UFUNCTION()
	virtual void ReduceAlertLevelWithTimer();
	/*Will enable the timer for Alert Level reduction. This timer will consider "DefaultTimeForEachAlarmLevel" and "TimeForEachAlarmLevel".*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|AIBehavior",
		meta = (DisplayName = "ReduceAlertLevelWithTimer", Keywords = "Reduce Alert Level Timer AI Behavior"))
	virtual bool EnableReduceAlertLevelWithTimer(const bool Enabled);
	/*Will refresh the current Alert Level reduction timer. Used to prevent level reduction while the enemy can be seen, the system will keep refreshing the timer until the AI enemy is no longer in its sight.*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|AIBehavior",
		meta = (DisplayName = "RefreshAlertLevelTimer", Keywords = "Refresh Alert Level Timer AI Behavior"))
	virtual bool RefreshReduceAlertLevelWithTimer();

#pragma endregion

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UAIPerceptionComponent* Perception;

	UPROPERTY()
	class ATDRL_Character* PossessedTDRLCharacter;

public:
};
