// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AuraAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UAuraAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;//属性注册并复制

	//属性
	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_Health,Category="Vital Attributes")
	FGameplayAttributeData Health;
	
	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_MaxHealth,Category="Vital Attributes")
	FGameplayAttributeData MaxHealth;

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_Mana,Category="Vital Attributes")
	FGameplayAttributeData Mana;
	
	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_MaxMana,Category="Vital Attributes")
	FGameplayAttributeData MaxMana;

	//复制时调用函数
	UFUNCTION()
	void OnRep_Health(FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_MaxHealth(FGameplayAttributeData& OldMaxHealth) const;

	UFUNCTION()
	void OnRep_Mana(FGameplayAttributeData& OldMana) const;

	UFUNCTION()
	void OnRep_MaxMana(FGameplayAttributeData& OldMaxMana) const;
};
