// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AAuraPlayerController();

protected :
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

//输入绑定函数
	void Move(const struct FInputActionValue& Value);
public:
	//输入映射以及输入行为
	UPROPERTY(EditAnywhere,Category="Input")
	TObjectPtr<class UInputMappingContext> AuraContext;

	UPROPERTY(EditAnywhere,Category="Input")
	TObjectPtr<class UInputAction> MoveAction;

};
