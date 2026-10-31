// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/ModMagCalc/MMC_MaxHealth.h"

#include "AbilitySystem/AuraAttributeSet.h"
#include "Interaction/CombatInterface.h"

UMMC_MaxHealth::UMMC_MaxHealth()
{
	VigorDef.AttributeToCapture = UAuraAttributeSet::GetVigorAttribute();
	VigorDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	VigorDef.bSnapshot=false;
	
	RelevantAttributesToCapture.Add(VigorDef);
}

float UMMC_MaxHealth::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	const FGameplayTagContainer* SourceContainer = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetContainer = Spec.CapturedTargetTags.GetAggregatedTags();
	
	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags=SourceContainer;
	EvaluateParameters.TargetTags=TargetContainer;
	float Vigor=0;
	
	GetCapturedAttributeMagnitude(VigorDef,Spec,EvaluateParameters,Vigor);
	ICombatInterface* CombatInterface=Cast<ICombatInterface>(Spec.GetContext().GetSourceObject());
	check(CombatInterface)
	int32 PlayerLevel = CombatInterface->GetCharacterLevel();
	
	return 80.f + Vigor*2.5 + PlayerLevel*10;
}
