// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "PlayerAttributes.generated.h"

/**
 * 
 */
UCLASS()
class HOWLOFIRON_API UPlayerAttributes : public UAttributeSet
{
	GENERATED_BODY()

public:
	UPROPERTY(Category = "Abilities/Stats", EditAnywhere, BlueprintReadWrite)
	    FGameplayAttributeData Speed;

    UPROPERTY(Category = "Abilities/Stats", EditAnywhere, BlueprintReadWrite)
        FGameplayAttributeData DamageMod;

    UPROPERTY(Category = "Abilities/Stats", EditAnywhere, BlueprintReadWrite)
        FGameplayAttributeData Health;

    UFUNCTION(Category = "Attribute Functions")
        FGameplayAttribute SpeedAttribute();
    UFUNCTION(Category="Attribute Functions")
        FGameplayAttribute DamageModAttribute();
    UFUNCTION(Category="Attribute Functions")
        FGameplayAttribute HealthAttribute();
};
