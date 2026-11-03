// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraGameplayTags.h"

#include "GameplayTagsManager.h"


FAuraGameplayTags FAuraGameplayTags::GameplayTags;

void FAuraGameplayTags::InitializeNativeGameplayTags()
{
	//声明本地标签
	//Primary Attribute
	GameplayTags.Attribute_Primary_Strength=UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attribute.Primary.Strength"),
	FString("Increasing Physical Damage")
	);
	
	GameplayTags.Attribute_Primary_Intelligence=UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attribute.Primary.Intelligence"),
	FString("Increasing Magical Damage")
	);
	
	GameplayTags.Attribute_Primary_Resilience=UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attribute.Primary.Resilience"),
	FString("Increasing Armor and Armor Penetration")
	);
	
	GameplayTags.Attribute_Primary_Vigor=UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attribute.Primary.Vigor"),
	FString("Increasing Health")
	);
	
	//Secondary Attribute
	GameplayTags.Attribute_Secondary_Armor=UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Secondary.Armor"),
		FString("Reduce Damage Taken,improve Block Chance")
		);
	
	GameplayTags.Attribute_Secondary_ArmorPenetration=UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attribute.Secondary.ArmorPenetration"),
	FString("Ignore Armor of enemy")
	);
	
	GameplayTags.Attribute_Secondary_BlockChance=UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attribute.Secondary.BlockChance"),
	FString("Chance to cut incoming damage in half")
	);
	
	GameplayTags.Attribute_Secondary_CriticalHitChance=UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attribute.Secondary.CriticalHitChance"),
	FString("Critical Chance")
	);
	
	GameplayTags.Attribute_Secondary_CriticalHitDamage=UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attribute.Secondary.CriticalHitDamage"),
	FString("Exported Damage")
	);
	
	GameplayTags.Attribute_Secondary_CriticalHitResistance=UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attribute.Secondary.CriticalHitResistance"),
	FString("Reduce Critical Chance of enemy")
	);
	
	GameplayTags.Attribute_Secondary_HealthRegeneration=UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attribute.Secondary.HealthRegeneration"),
	FString("1 second,Regenerate Health value")
	);
	
	GameplayTags.Attribute_Secondary_ManaRegeneration=UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attribute.Secondary.ManaRegeneration"),
	FString("1 second,Regenerate Mana value")
	);
	
	GameplayTags.Attribute_Secondary_MaxHealth=UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attribute.Secondary.MaxHealth"),
	FString("Max Health value")
	);
	
	GameplayTags.Attribute_Secondary_MaxMana=UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attribute.Secondary.MaxMana"),
	FString("Max Mana Value")
	);
	
}
