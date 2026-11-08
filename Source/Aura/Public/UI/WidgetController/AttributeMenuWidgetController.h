// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/AuraWidgetController.h"
#include "AttributeMenuWidgetController.generated.h"

class UAttributeInfo;
struct FAuraAttributeInfo;
/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAttributeInfoSignature,const FAuraAttributeInfo&,AttributeInfo);


UCLASS(BlueprintType,Blueprintable)
class AURA_API UAttributeMenuWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()
public:
	virtual void BroadcastInitialValue() override;
	
	virtual void BindCallbackToDependencies() override;

	UPROPERTY(EditDefaultsOnly,Category="GAS|Attribute")
	TObjectPtr<UAttributeInfo> AttributeInfo;
	
	UPROPERTY(BlueprintAssignable)
	FAttributeInfoSignature AttributeInfoDelegate;
	
};
