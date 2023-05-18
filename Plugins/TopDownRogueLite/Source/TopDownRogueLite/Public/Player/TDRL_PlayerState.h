// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"

#include "TDRL_GameplayTypes.h"
#include "TDRL_PlayerState.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNROGUELITE_API ATDRL_PlayerState : public APlayerState
{
	GENERATED_BODY()
	ATDRL_PlayerState();

public:
	UPROPERTY(ReplicatedUsing = OnRep_CosmeticList, BlueprintReadWrite, Category = "TDRL|PlayerState|Cosmetic")
	struct FCosmeticParameterList CosmeticList;
	UPROPERTY(BlueprintReadOnly, Category = "TDRL|PlayerState|Cosmetic")
	USkeletalMesh* GeneratedCosmetic;

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnRep_CosmeticList(const FCosmeticParameterList OldValue);
	UFUNCTION()
	virtual void GemerateCosmetic();

	UFUNCTION(Server, Reliable)
	virtual void SetCosmeticList_Serv(FCosmeticParameterList InCosmeticList);
	UFUNCTION()
	virtual void SetCosmeticList_Implementation(FCosmeticParameterList InCosmeticList);

public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void ClientInitialize(AController* InController) override;

	UFUNCTION(BlueprintCallable, Category = "TDRL|PlayerState|Cosmetic",
		meta = (DisplayName = "SetCosmeticList", Keywords = "Set Cosmetic List TDRL"))
	void SetCosmeticList(FCosmeticParameterList InCosmeticList);
	UFUNCTION(BlueprintCallable, Category = "TDRL|PlayerState|Cosmetic",
		meta = (DisplayName = "ApplyCosmetic", Keywords = "Apply Cosmetic TDRL"))
	virtual void ApplyCosmetic();
};
