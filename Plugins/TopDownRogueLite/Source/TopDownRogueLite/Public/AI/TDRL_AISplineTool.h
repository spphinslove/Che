// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TDRL_AISplineTool.generated.h"

UCLASS(BlueprintType, Blueprintable,
	meta = (ShortTooltip =
		"AI Main Spline tool for movement managing. It can be assigned to AIs and can be used for custom logics."))
class TOPDOWNROGUELITE_API ATDRL_AISplineTool : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATDRL_AISplineTool();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class USceneComponent* Root;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class USplineComponent* Spline;

public:
#pragma region Components
	/*Return AI SplineComponent*/
	UFUNCTION(BlueprintPure, Category = "TDRL|Components", meta = (DisplayName = "GetSplineComponent"))
	virtual USplineComponent* GetSplineComponent() const
	{
		return Spline;
	}

#pragma endregion

	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
