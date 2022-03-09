// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageExecution.h"

UDamageExecution::UDamageExecution(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
    AttStruct Attributes;
    RelevantAttributesToCapture.Add(Attributes.HealthDef);
    InvalidScopedModifierAttributes.Add(Attributes.HealthDef);

    RelevantAttributesToCapture.Add(Attributes.DamageModDef);

}

void UDamageExecution::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,
    OUT FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
    AttStruct Attributes;

    const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();

    UAbilitySystemComponent* TargetASC = ExecutionParams.GetTargetAbilitySystemComponent();
    UAbilitySystemComponent* SourceASC = ExecutionParams.GetSourceAbilitySystemComponent();

    AActor* TargetActor = TargetASC ? TargetASC->AvatarActor : nullptr;
    AActor* SourceActor = SourceASC ? SourceASC->AvatarActor : nullptr;

    const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();
    const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();

    FAggregatorEvaluateParameters EvaluationParameters;
    EvaluationParameters.TargetTags = TargetTags;
    EvaluationParameters.SourceTags = SourceTags;

    float Health = 0.f;
    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(Attributes.HealthDef, EvaluationParameters, Health);

    float DamageMod = 0.f;
    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(Attributes.DamageModDef, EvaluationParameters, DamageMod);

    float DamageDone = 10 * DamageMod;
    OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(Attributes.HealthProperty, EGameplayModOp::Additive, -DamageDone));
}