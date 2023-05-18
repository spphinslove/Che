// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "Animation/AnimMontage.h"

#include "TDRL_AITypes.generated.h"

UENUM(BlueprintType)
enum class EMathComparisonMethod : uint8
{
	MCM_Equal UMETA(DisplayName = "Equal"),
	MCM_Less UMETA(DisplayName = "Less"),
	MCM_LessOrEqual UMETA(DisplayName = "LessOrEqual"),
	MCM_Greater UMETA(DisplayName = "Greater"),
	MCM_GreaterOrEqual UMETA(DisplayName = "GreaterOrEqual")
};

UENUM(BlueprintType)
enum class EAISwitchWeaponMethod : uint8
{
	ASW_Main UMETA(DisplayName = "Main"),
	ASW_BestRarity UMETA(DisplayName = "Best Rarity"),
	ASW_WorstRarity UMETA(DisplayName = "Worst Rarity"),
	ASW_SpecificSlot UMETA(DisplayName = "Specific Slot"),
	ASW_WeaponClass UMETA(DisplayName = "Weapon Class"),
};

UENUM(BlueprintType)
enum class EItemSlotNative : uint8
{
	ISN_Slot_0 UMETA(DisplayName = "Slot_0"),
	ISN_Slot_1 UMETA(DisplayName = "Slot_1"),
	ISN_Slot_2 UMETA(DisplayName = "Slot_2"),
	ISN_Slot_3 UMETA(DisplayName = "Slot_3"),
	ISN_Slot_4 UMETA(DisplayName = "Slot_4"),
	ISN_Slot_5 UMETA(DisplayName = "Slot_5"),
	ISN_Slot_6 UMETA(DisplayName = "Slot_6"),
	ISN_Slot_7 UMETA(DisplayName = "Slot_7"),
	ISN_Slot_8 UMETA(DisplayName = "Slot_8"),
	ISN_Slot_9 UMETA(DisplayName = "Slot_9")
};

USTRUCT(BlueprintType)
struct TOPDOWNROGUELITE_API FAIRandomAnimMontageList
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations", meta = (BlueprintSpawnableComponent))
	TArray<TSoftObjectPtr<class UAnimMontage>> Montages;

	FAIRandomAnimMontageList()
	{
		Montages = TArray<TSoftObjectPtr<class UAnimMontage>>();
	}
};

UCLASS(BlueprintType, Abstract, Blueprintable)
class TOPDOWNROGUELITE_API UAIAnimMontageContainer : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations", meta = (Set = "AddUnique"))
	TSet<class UAnimMontage*> MontageList;

	UFUNCTION(BlueprintPure, Category = "MontageContainer")
	bool bHasValues() const
	{
		return MontageList.Num() > 0;
	};
	UFUNCTION(BlueprintPure, Category = "MontageContainer")
	float GetNum() const
	{
		return MontageList.Num();
	};
	UFUNCTION(BlueprintPure, Category = "MontageContainer")
	bool GetRandomAnimationMontageIndex(uint8& OutIndex) const
	{
		if (!bHasValues())
		{
			OutIndex = 0;
			return false;
		}

		OutIndex = FMath::RandRange(0, FMath::Min(MontageList.Num() - 1, 255));
		return true;
	};
	UFUNCTION(BlueprintPure, Category = "MontageContainer")
	UAnimMontage* GetRandomAnimationMontage() const
	{
		uint8 AnimIndex = 0;
		if (!bHasValues() || !GetRandomAnimationMontageIndex(AnimIndex))
		{
			return nullptr;
		}

		return MontageList.Array()[AnimIndex];
	};
	UFUNCTION(BlueprintPure, Category = "MontageContainer")
	UAnimMontage* GetRandomAnimationMontageLength(EMathComparisonMethod InMethod, float InLength) const
	{
		TArray<class UAnimMontage*> SelectedMontages = TArray<class UAnimMontage*>();
		for (auto& CAnim : MontageList.Array())
		{
			const float CLength = CAnim->CalculateSequenceLength();

			bool OutResult = false;
			switch (InMethod)
			{
			case EMathComparisonMethod::MCM_Equal:
				OutResult = CLength == InLength;
				break;
			case EMathComparisonMethod::MCM_Greater:
				OutResult = CLength > InLength;
				break;
			case EMathComparisonMethod::MCM_GreaterOrEqual:
				OutResult = CLength >= InLength;
				break;
			case EMathComparisonMethod::MCM_Less:
				OutResult = CLength < InLength;
				break;
			case EMathComparisonMethod::MCM_LessOrEqual:
				OutResult = CLength <= InLength;
				break;

				if (OutResult)
				{
					SelectedMontages.Add(CAnim);
				}
			}
		}

		return SelectedMontages[FMath::RandRange(0, FMath::Min(MontageList.Num() - 1, 255))];
	};
};

/**
 * 
 */
class TOPDOWNROGUELITE_API TDRL_AITypes
{
public:
	TDRL_AITypes();
	~TDRL_AITypes();
};
