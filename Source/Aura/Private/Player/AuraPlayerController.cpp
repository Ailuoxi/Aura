// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerController.h"
#include "../../../../../../../Plugins/EnhancedInput/Source/EnhancedInput/Public/EnhancedInputSubsystems.h"
#include "../../../../../../../Plugins/EnhancedInput/Source/EnhancedInput/Public/EnhancedInputComponent.h"
#include "../../../../../../../Plugins/EnhancedInput/Source/EnhancedInput/Public/InputActionValue.h"
#include "Interaction/EnemyInterface.h"

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(AuraContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->AddMappingContext(AuraContext, 0);
	}
	

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputMode.SetHideCursorDuringCapture(false);
	SetInputMode(InputMode);
}

void AAuraPlayerController::SetupInputComponent()
{
     Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputCompnent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputCompnent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);

}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

void AAuraPlayerController::CursorTrace()
{
	FHitResult CursorHit;

	GetHitResultUnderCursor(ECC_Visibility, false,CursorHit);
	if (!CursorHit.bBlockingHit) return;

	LastActor = ThisActor;
	ThisActor=Cast<IEnemyInterface>(CursorHit.GetActor());
	/*
	* 有以下几种情况
	* 1.上一帧和当前帧都是空的
	*    -我们什么也不做
	* 2.上一帧是空的，但是当前帧是有效的
	*    -对当前帧的actor进行高亮
	* 3.上一帧是有效的但是当前帧是空的
	*    -对上一帧的actor取消高亮
	* 4.上一帧和当前帧都是有效的，但是不一样
	*    -上一帧取消高亮，当前帧高亮
	* 5.上一帧和当前帧一样
	*    -什么也不做
	*/

	if (LastActor == nullptr)
	{
		if (ThisActor != nullptr)
		{
			ThisActor->HighlightEnemy();
		}
	}
	else {
		if (ThisActor == nullptr)
		{
			LastActor->UnHighlightEnemy();
		}
		else {
			if (LastActor != ThisActor)
			{
				LastActor->UnHighlightEnemy();
				ThisActor->HighlightEnemy();
			}
		}
	}
}

void AAuraPlayerController::Move(const struct FInputActionValue& Value)
{
	FVector2D MoveDirection = Value.Get<FVector2D>();

	FRotator Rotation = GetControlRotation();
	FRotator YawRotation = FRotator(0.f, Rotation.Yaw, 0.f);
	FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if(APawn* ControlledPawn = GetPawn())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, MoveDirection.Y);
		ControlledPawn->AddMovementInput(RightDirection, MoveDirection.X);
	}
}
