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
	AAuraEnemy();
	/* 敌人接口 */
	virtual void HighlightEnemy() override;//高亮
	virtual void UnHighlightEnemy() override;//取消高亮
    /*敌人接口结束*/
	//是否高亮
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	bool bHighlight = false;
	
	/*ICombat Interface*/
	virtual int32 GetCharacterLevel() override;
	
protected:
	virtual void BeginPlay() override;
	
	virtual void InitAbilityActorInfo() override;
	
private:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Character Level Default",meta=(AllowPrivateAccess=true))
	int32 Level=1;
};
