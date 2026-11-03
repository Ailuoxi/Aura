// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AttributeInfo.h"

FAuraAttributeInfo UAttributeInfo::FindAttributeInfoForTag(const FGameplayTag& AttributeTag, bool bLogNotFind)
{
	for (const FAuraAttributeInfo& Info : AttributeInformation)
	{
		if(Info.AttributeTag.MatchesTagExact(AttributeTag))
		{
			return Info;
		}
	}
	if (bLogNotFind)
	{
		UE_LOG(LogTemp,Warning,TEXT("Not Find Attribute"));
	}
	return FAuraAttributeInfo();
}
