// Fill out your copyright notice in the Description page of Project Settings.


#include "HIComboGameplayAbility.h"

void UHIComboGameplayAbility::K2_EndAbility()
{
	Super::K2_EndAbility();

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Ability Ended!"));
}
