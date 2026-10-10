// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraCharacter.h"
#include "../../../../../../../Source/Runtime/Engine/Classes/GameFramework/CharacterMovementComponent.h"

AAuraCharacter::AAuraCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;//使角色吸附到平面上
	GetCharacterMovement()->bSnapToPlaneAtStart = true;//使角色开始时吸附到平面上

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

}
