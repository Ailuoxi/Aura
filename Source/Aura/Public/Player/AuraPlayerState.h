// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "../../../../../../../Plugins/Runtime/GameplayAbilities/Source/GameplayAbilities/Public/AbilitySystemInterface.h"
#include "AuraPlayerState.generated.h"
/**
 * 
 */
class UAbilitySystemComponent;
class UAttributeSet;
UCLASS()
class AURA_API AAuraPlayerState : public APlayerState,public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	AAuraPlayerState();
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	//重写能力系统接口
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//获取属性集
	UAttributeSet* GetAttributeSet() const { return AttributeSet; };
	
	int32 GetPlayerLevel() const {return Level;};
protected:
	UPROPERTY(EditAnywhere)
	TObjectPtr<class UAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY()
	TObjectPtr<class UAttributeSet> AttributeSet;
	
private:
	UPROPERTY(VisibleAnywhere,ReplicatedUsing=OnRep_Level)
	int32 Level=1;
	
	UFUNCTION()
	void OnRep_Level(int32 OldLevel) const;
};
