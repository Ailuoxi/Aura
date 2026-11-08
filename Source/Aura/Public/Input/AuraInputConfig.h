// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "AuraInputConfig.generated.h"

class UInputAction;

USTRUCT()
struct FAuraInputData
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly)
	const UInputAction* InputAction;

	UPROPERTY(EditDefaultsOnly)
	FGameplayTag InputTag;
};

UCLASS()
class AURA_API UAuraInputConfig : public UDataAsset
{
	GENERATED_BODY()
	
public:
	const UInputAction* FindAbilityInputActionForTag(const FGameplayTag& InputTag,bool bLogNotFind = false) const;
	

	UPROPERTY(EditDefaultsOnly,Blueprintable)
	TArray<FAuraInputData> InputActions;
};
