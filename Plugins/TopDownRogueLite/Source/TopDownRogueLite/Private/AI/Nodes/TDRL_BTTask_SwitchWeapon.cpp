// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_BTTask_SwitchWeapon.h"
#include "TDRL_Item.h"
#include "TDRL_Character.h"

#include "AIController.h"
#include "..\..\..\Public\AI\Nodes\TDRL_BTTask_SwitchWeapon.h"

UTDRL_BTTask_SwitchWeapon::UTDRL_BTTask_SwitchWeapon()
	: Super()
{
	NodeName = "Switch Weapon Slot";
}

EBTNodeResult::Type UTDRL_BTTask_SwitchWeapon::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	ATDRL_Character* CharRef = Cast<ATDRL_Character>(OwnerComp.GetAIOwner()->GetPawn());

	if (!CharRef)
	{
		return EBTNodeResult::Failed;
	}

	uint8 SelectSlot = 0;
	switch (Method)
	{
	case EAISwitchWeaponMethod::ASW_Main:
		break;
	case EAISwitchWeaponMethod::ASW_BestRarity:
		SelectSlot = CharRef->GetHigestRarityItemSlot(false);
		break;
	case EAISwitchWeaponMethod::ASW_WorstRarity:
		SelectSlot = CharRef->GetHigestRarityItemSlot(false);
		break;
	case EAISwitchWeaponMethod::ASW_SpecificSlot:
		SelectSlot = SpecificSlot;
		break;
	case EAISwitchWeaponMethod::ASW_WeaponClass:
		TArray<uint8> ClassIndexes = CharRef->GetSlotsOccupiedByItemClass(ItemClass);
		if (ClassIndexes.Num() == 0)
		{
			return EBTNodeResult::Failed;
		}
		SelectSlot = ClassIndexes[0];
		break;
	}

	if (CharRef->SelectedItemSlot != SelectSlot)
	{
		CharRef->SelectItemSlot(SelectSlot);
	}

	return EBTNodeResult::Succeeded;
}

FString UTDRL_BTTask_SwitchWeapon::GetStaticDescription() const
{
	switch (Method)
	{
	case EAISwitchWeaponMethod::ASW_Main:
		return FString::Printf(TEXT("Method: Main Weapon"));
	case EAISwitchWeaponMethod::ASW_BestRarity:
		return FString::Printf(TEXT("Method: Best Rarity"));
	case EAISwitchWeaponMethod::ASW_WorstRarity:
		return FString::Printf(TEXT("Method: Worst Rarity"));
	case EAISwitchWeaponMethod::ASW_SpecificSlot:
		return FString::Printf(TEXT("Method: Specific Slot%sSelected Slot: %i"), LINE_TERMINATOR, SpecificSlot);
	case EAISwitchWeaponMethod::ASW_WeaponClass:
		FString OutString = "Invalid";
		if (ItemClass)
		{
			OutString = ItemClass->GetFName().ToString();
		}
		return FString::Printf(TEXT("Method: Weapon Class%sWeapon Class: %s"), LINE_TERMINATOR, *OutString);
	}

	return FString::Printf(TEXT("Method invalid"));
}
