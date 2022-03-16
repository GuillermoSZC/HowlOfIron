// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "HIComboGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class HOWLOFIRON_API UHIComboGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

		virtual void K2_EndAbility() override;
};
