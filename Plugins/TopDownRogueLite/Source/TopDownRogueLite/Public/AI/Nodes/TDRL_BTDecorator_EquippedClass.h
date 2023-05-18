// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TDRL_BTDecorator.h"
#include "TDRL_BTDecorator_EquippedClass.generated.h"

/**
 * 
 */
UCLASS(meta = (DisplayName = "Item Class is Equipped"))
class TOPDOWNROGUELITE_API UTDRL_BTDecorator_EquippedClass : public UTDRL_BTDecorator
{
	GENERATED_BODY()

public:
	UTDRL_BTDecorator_EquippedClass();

	/*Will return true if the equipped item is equal to this class*/
	UPROPERTY(EditAnywhere, Category = "Condition")
	TSubclassOf<class ATDRL_Item> ParentClass;
	/*Can be a subclass of ParentClass*/
	UPROPERTY(EditAnywhere, Category = "Condition")
	uint8 bCanBeSubclass : 1;

	UPROPERTY(EditAnywhere, Category = "Tick")
	float TickCheckInterval = 1.0f;

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
	virtual void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	virtual FString GetStaticDescription() const override;
};
