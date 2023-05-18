// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "TDRL_BTDecorator.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNROGUELITE_API UTDRL_BTDecorator : public UBTDecorator
{
	GENERATED_BODY()

public:
	UTDRL_BTDecorator();

protected:
	virtual FString GetStaticDescription() const override;
};
