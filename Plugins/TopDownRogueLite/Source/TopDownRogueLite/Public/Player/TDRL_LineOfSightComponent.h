// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TDRL_LineOfSightComponent.generated.h"

USTRUCT(BlueprintType)
struct TOPDOWNROGUELITE_API FLineOfSightParam
{
	GENERATED_USTRUCT_BODY()

	/*Trace channels for occlusion sight*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "LineOfSight")
	TSet<TEnumAsByte<EObjectTypeQuery>> TraceChannels;
	//= TSet<TEnumAsByte<ECollisionChannel>>{ ECollisionChannel::ECC_WorldStatic };
	/*Angle of sight*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "LineOfSight")
	int32 SightAngle = 180;
	/*Increase the trace resolution, quality doubles for each SubAngle*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "LineOfSight")
	uint8 SubAngles = 0;
	/*Max distance traced from the character*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "LineOfSight")
	float MaxDistance = 2500.0f;
	/*Material Parameter Collection to use (follow the example)*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "LineOfSight")
	class UMaterialParameterCollection* Collector;
	/*Texture target resolution to use*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "LineOfSight")
	float TextureResolution = 2048.0f;
	/*Canvas render target to use for sight drawing*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "LineOfSight")
	class UCanvasRenderTarget2D* Canvas;
	/*Scale the area covered by the texture target*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "LineOfSight")
	float AreaScale;

	/*Should hide a list of classes and use this trace to unhide them when they're in sight?*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "LineOfSight")
	uint8 bUseHideActorsBasedOnClass : 1;
	/*Time between two traces for hidden actors*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "LineOfSight")
	float TickTraceForActorsEvery = 0.1f;
	/*Use the capsule size of this character as base size for the capsule trace. Scale it by this value (X/Z)*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "LineOfSight")
	FVector2D TraceBodyRelativeScale = FVector2D(0.25f, 4.0f);
	/*Test radius around actor to show hidden classes*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "LineOfSight")
	float TestRadiusAroundOwner = 75.0f;
	/*Classes the system need to hide/unhide when enabled*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "LineOfSight")
	TArray<TSubclassOf<AActor>> HideClasses = TArray<TSubclassOf<AActor>>();
	/*Collision channels the system need to trace for actors*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "LineOfSight")
	TSet<TEnumAsByte<EObjectTypeQuery>> TraceForActorsChannels;
	// = TSet<TEnumAsByte<ECollisionChannel>>{ ECollisionChannel::ECC_Pawn };

	FLineOfSightParam()
	{
		SightAngle = 180.0f;
		SubAngles = 0;
		MaxDistance = 2500.0f;
		Collector = nullptr;
		TextureResolution = 2048.0f;
		Canvas = nullptr;
		AreaScale = 1.0f;

		bUseHideActorsBasedOnClass = false;
		TraceBodyRelativeScale = FVector2D(0.25f, 4.0f);
		TestRadiusAroundOwner = 75.0f;
		HideClasses = TArray<TSubclassOf<AActor>>();
		//TraceForActorsChannels = TSet<TEnumAsByte<ECollisionChannel>>{ ECollisionChannel::ECC_Pawn };
	}
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent, ImplementedBy = "ATDRL_Character"))
class TOPDOWNROGUELITE_API UTDRL_LineOfSightComponent : public UActorComponent
{
	GENERATED_BODY()

	UTDRL_LineOfSightComponent();

public:
	/*Sight parameters to use*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TDRL|LineOfSight")
	FLineOfSightParam SightParameters;
	/*Should enable debugging?*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TDRL|LineOfSight")
	uint8 bEnableDebug : 1;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY()
	TArray<AActor*> UnhiddenActors = TArray<AActor*>();
	UPROPERTY()
	class UCanvasRenderTarget2D* CanvasInUse;
	UPROPERTY()
	float TickAccum;

	UFUNCTION()
	virtual TArray<FVector> TraceSight();
	UFUNCTION()
	virtual void TraceSightForActors(const TArray<FVector>& EndPoints);
	UFUNCTION()
	virtual void DrawTriangles(const TArray<FVector> InSightTraces);

	UFUNCTION()
	virtual void PerformInitialHideActorsBasedOnClass();
	UFUNCTION()
	virtual void PerformFinalUnhideActorsBasedOnClass();

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	virtual void Activate(bool bReset) override;
	virtual void Deactivate() override;
};
