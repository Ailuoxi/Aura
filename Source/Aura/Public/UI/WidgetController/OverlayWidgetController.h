// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/AuraWidgetController.h"
#include "OverlayWidgetController.generated.h"

struct FOnAttributeChangeData;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealChangedSignature, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealChangedSignature,float,NewMaxHealth);

UCLASS(BlueprintType,Blueprintable)
class AURA_API UOverlayWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()
public:
	virtual void BroadcastInitialValue() override;
	virtual void BindCallbackToDependencies() override;
	
	
	UPROPERTY(BlueprintAssignable,Category="GAS|Attributes")
	FOnHealChangedSignature OnHealthChanged;//生命值改变委托
	
	UPROPERTY(BlueprintAssignable,Category="GAS|Attributes")
	FOnMaxHealChangedSignature OnMaxHealthChanged;//最大生命值改变委托
	
protected:
	void HealthChanged(const FOnAttributeChangeData& Data) const;
	void MaxHealthChanged(const FOnAttributeChangeData& Data) const;
	
};
