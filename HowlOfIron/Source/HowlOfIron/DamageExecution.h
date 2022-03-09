// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerAttributes.h"
#include "AbilitySystemComponent.h"
#include "GameplayTagsModule.h"
#include "GameplayEffectExecutionCalculation.h"
#include "DamageExecution.generated.h"

/**
 * 
 */
struct AttStruct
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(Health);
	DECLARE_ATTRIBUTE_CAPTUREDEF(DamageMod);
	//hola
	AttStruct()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UPlayerAttributes, Health, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UPlayerAttributes, DamageMod, Source, true);
	}
};

UCLASS()
class HOWLOFIRON_API UDamageExecution : public UGameplayEffectExecutionCalculation
{
	GENERATED_UCLASS_BODY()

    virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,
        OUT FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
};
