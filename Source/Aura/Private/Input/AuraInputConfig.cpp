// Fill out your copyright notice in the Description page of Project Settings.


#include "Input/AuraInputConfig.h"

const UInputAction* UAuraInputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFind) const
{
	for (FAuraInputData Pair : InputActions)
	{
		if (Pair.InputTag == InputTag) return Pair.InputAction;
	}
	if (bLogNotFind)
	{
		FGameplayTag Tag = InputTag;
		UE_LOG(LogTemp,Error,TEXT("Not Find Ability InputTag [%s]"),*Tag.ToString());
	}
 	return nullptr;
}
