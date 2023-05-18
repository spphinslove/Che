// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"

#include "TDRL_AITypes.h"
#include "TDRL_BTTask_SwitchWeapon.generated.h"

/**
 * 
 */
UCLASS(meta = (DisplayName = "Switch Weapon Slot"))
class TOPDOWNROGUELITE_API UTDRL_BTTask_SwitchWeapon : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UTDRL_BTTask_SwitchWeapon();

	/*Which weapon should be selected?*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task")
	EAISwitchWeaponMethod Method;

	/*Specific slot to select*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task",
		meta = (EditCondition = "Method == EAISwitchWeaponMethod::ASW_SpecificSlot"))
	uint8 SpecificSlot;
	/*Specific class to select*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Task",
		meta = (EditCondition = "Method == EAISwitchWeaponMethod::ASW_WeaponClass"))
	TSubclassOf<class ATDRL_Item> ItemClass;

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
	virtual FString GetStaticDescription() const override;
};
