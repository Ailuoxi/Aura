// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase,public IEnemyInterface
{
	GENERATED_BODY()
public:
	virtual void HighlightEnemy() override;//高亮
	virtual void UnHighlightEnemy() override;//取消高亮

	//是否高亮
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	bool bHighlight = false;
};
