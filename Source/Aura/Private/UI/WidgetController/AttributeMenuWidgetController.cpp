// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/AttributeMenuWidgetController.h"

#include "AuraGameplayTags.h"
#include "AbilitySystem/AttributeInfo.h"
#include "AbilitySystem/AuraAttributeSet.h"

template<class T>
using AttributeFunction = T(*)();

void UAttributeMenuWidgetController::BroadcastInitialValue()
{
	const UAuraAttributeSet* AS=Cast<UAuraAttributeSet>(AttributeSet);
	check(AttributeInfo)
	
    for (auto Pair : AS->TagToAttributeMap )
    {
	    FAuraAttributeInfo Info=AttributeInfo->FindAttributeInfoForTag(Pair.Key);
    	Info.AttributeValue = Pair.Value().GetNumericValue(AS);
    	AttributeInfoDelegate.Broadcast(Info);
    }

}

void UAttributeMenuWidgetController::BindCallbackToDependencies()
{
	const UAuraAttributeSet* AS=Cast<UAuraAttributeSet>(AttributeSet);
	check(AttributeInfo)
	
	for (auto Pair : AS->TagToAttributeMap )
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Value()).AddLambda(
			[this,Pair,AS](const FOnAttributeChangeData& Data)
			{
				FAuraAttributeInfo Info=AttributeInfo->FindAttributeInfoForTag(Pair.Key);
				Info.AttributeValue = Data.NewValue;
				AttributeInfoDelegate.Broadcast(Info);
			}
			);
		
		
	}

}
