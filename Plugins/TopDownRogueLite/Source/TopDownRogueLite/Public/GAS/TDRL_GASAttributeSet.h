// Copyright 2023 Henry Galimberti. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "TDRL_GASAttributeSet.generated.h"


//To use this in your game you can define something like this, and then add game - specific functions as necessary :

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class TOPDOWNROGUELITE_API UTDRL_GASAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

	UTDRL_GASAttributeSet();

public:
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	/*Custom Attribute 1*/
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_CustomAttribute1)
	FGameplayAttributeData CustomAttribute1;
	ATTRIBUTE_ACCESSORS(UTDRL_GASAttributeSet, CustomAttribute1);
	UFUNCTION()
	virtual void OnRep_CustomAttribute1(const FGameplayAttributeData& Old);

	/*Custom Attribute 2*/
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_CustomAttribute2)
	FGameplayAttributeData CustomAttribute2;
	ATTRIBUTE_ACCESSORS(UTDRL_GASAttributeSet, CustomAttribute2);
	UFUNCTION()
	virtual void OnRep_CustomAttribute2(const FGameplayAttributeData& Old);

	/*Custom Attribute 3*/
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_CustomAttribute3)
	FGameplayAttributeData CustomAttribute3;
	ATTRIBUTE_ACCESSORS(UTDRL_GASAttributeSet, CustomAttribute3);
	UFUNCTION()
	virtual void OnRep_CustomAttribute3(const FGameplayAttributeData& Old);

protected:

public:
};
