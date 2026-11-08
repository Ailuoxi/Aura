// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystemComponent.h"
#include "AuraGameplayTags.h"
#include "GameplayAbilitySpec.h"
#include "AbilitySystem//Ability/AuraGameplayAbility.h"
void UAuraAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this,&UAuraAbilitySystemComponent::EffectApplied);
	
	FAuraGameplayTags& Gameplaytag =FAuraGameplayTags::Get();
}

void UAuraAbilitySystemComponent::AddGameplayAbilities(TArray<TSubclassOf<UAuraGameplayAbility>> Abilities)
{
	for (TSubclassOf<UAuraGameplayAbility> Ability : Abilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(Ability,1);
        GiveAbilityAndActivateOnce(AbilitySpec);
	
	}
}

void UAuraAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* ASC, const FGameplayEffectSpec& EffectSpec,
                                                FActiveGameplayEffectHandle EffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);
	EffectAssetTagContainer.Broadcast(TagContainer);
}
