// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "../../../../../../../Plugins/Runtime/GameplayAbilities/Source/GameplayAbilities/Public/AbilitySystemInterface.h"
#include "AuraCharacterBase.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;

UCLASS(Abstract)
class AURA_API AAuraCharacterBase : public ACharacter,public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	
	AAuraCharacterBase();
	//重写能力系统接口
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//获取属性集
	UAttributeSet* GetAttributeSet() const { return AttributeSet; };
protected:
	
	virtual void BeginPlay() override;
	
	virtual void InitAbilityActorInfo();

	UPROPERTY(EditAnywhere,Category="Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

	UPROPERTY()
	TObjectPtr<class UAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY()
	TObjectPtr<class UAttributeSet> AttributeSet;
};
