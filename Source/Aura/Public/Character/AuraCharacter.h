// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()
public:
	AAuraCharacter();
	
	virtual void OnRep_PlayerState() override;//在客户端进行ASC和AS初始化
	virtual void PossessedBy(AController* NewController) override;//在服务器端进行ASC和AS初始化
private:
	virtual void InitAbilityActorInfo() override;
};
