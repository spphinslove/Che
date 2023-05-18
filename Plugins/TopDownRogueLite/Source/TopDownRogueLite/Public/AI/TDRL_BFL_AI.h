// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TDRL_BFL_AI.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNROGUELITE_API UTDRL_BFL_AI : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/*Useful conversion for BTTasks etc...*/
	UFUNCTION(BlueprintPure, Category = "TDRL|AILibrary",
		meta = (DisplayName = "ExecuteAI Conversion", Keywords = "AI Execute Conversion Task Decorator Service",
			WorldContext = "WorldContextObject"))
	static void ExecuteAIToTDRLExecuteAI(UObject* WorldContextObject, AAIController* ControllerIn, APawn* PawnIn,
	                                     ATDRL_NPCController* & ControllerOut, ATDRL_Character*& CharacterOut);
	/*Will return the same value if the selector is Vector type. Otherwise this function will find the location of the Object store in this blackboard selector and will return it.*/
	UFUNCTION(BlueprintPure, Category = "TDRL|AILibrary",
		meta = (DisplayName = "GetLocationFromBlackboardVectorOrActor", Keywords = "AI Blackboard Vector Actor Location"
			, WorldContext = "WorldContextObject"))
	static bool GetLocationFromActorOrVectorFromBB(UObject* WorldContextObject,
	                                               const class UBlackboardComponent* BBComp,
	                                               const struct FBlackboardKeySelector KeySelector,
	                                               FVector& OutLocation);
};
