// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TDRL_CameraOcclusionComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnOcclusionChanged, bool, Occluded, TArray<class USceneComponent*>,
                                             OcclusionComps);


UCLASS(ClassGroup=TDRL,
	meta=(abstract, BlueprintSpawnableComponent, DisplayName = "CameraOcclusionManager", ShortTooltip =
		"This component will manage camera player's camera occlusion on the assigned object"))
class TOPDOWNROGUELITE_API UTDRL_CameraOcclusionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UTDRL_CameraOcclusionComponent();
	/*Time to wait before restoring visibility to the affected components*/
	UPROPERTY(EditAnywhere, Category = "TDRL|CameraOcclusion")
	float RestoreTimer = 1.0f;
	/*List of objects that will be affected by this component*/
	UPROPERTY(BlueprintReadOnly, Category = "TDRL|CameraOcclusion")
	TArray<UPrimitiveComponent*> AffectedComponents;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY()
	FTimerHandle VisibilityTimerHandle;

public:
	/*Returns all the visibility affected components*/
	UFUNCTION(BlueprintPure, Category = "TDRL|CameraOcclusion",
		meta = (DisplayName = "GetAffectedComponents", Keywords = "Get Affected Components Camera Occlusion"))
	virtual const TArray<UPrimitiveComponent*> GetAffectedComponents() const
	{
		return AffectedComponents;
	}

	/*Set affected components. These components will hide/hunide during the gameplay if they're on the way of the player's camera*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|CameraOcclusion",
		meta = (DisplayName = "SetAffectedComponents", Keywords = "Set Affected Components Camera Occlusion"))
	virtual void SetAffectedComponents(TArray<UPrimitiveComponent*> InComponents)
	{
		AffectedComponents = InComponents;
	}

	/*Add affected components. These components will hide/hunide during the gameplay if they're on the way of the player's camera*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|CameraOcclusion",
		meta = (DisplayName = "AddAffectedComponents", Keywords = "Add Affected Components Camera Occlusion"))
	virtual void AddAffectedComponents(TArray<UPrimitiveComponent*> InComponents)
	{
		AffectedComponents.Append(InComponents);
	}

	/*Set affected component. This component will hide/hunide during the gameplay if they're on the way of the player's camera*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|CameraOcclusion",
		meta = (DisplayName = "AddSingleAffectedComponent", Keywords = "Add Affected Component Camera Occlusion"))
	virtual void AddAffectedComponent(UPrimitiveComponent* InComponent)
	{
		AffectedComponents.Add(InComponent);
	}

	/*Enable or disable occlusion*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|CameraOcclusion",
		meta = (DisplayName = "SetOcclusionEnabled", Keywords = "Enabled Camera Occlusion"))
	virtual void SetOcclusionEnabled(const bool Enabled);

	UPROPERTY(BlueprintAssignable, Category = "VRPB|CameraOcclusion")
	FOnOcclusionChanged OnOcclusionChanged;

	/*Default occlusion function (simple hide/unhide)*/
	UFUNCTION(BlueprintCallable, Category = "TDRL|CameraOcclusion",
		meta = (DisplayName = "Default Occlusion Event", Keywords = "Default Occlusion Event TDRL"))
	void DefaultOcclusionEvent(const bool Occluded, TArray<class USceneComponent*> OcclusionComps);
};
