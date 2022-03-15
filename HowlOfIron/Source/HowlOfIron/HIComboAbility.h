// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include <Abilities/GameplayAbility.h>

/**
 * 
 */
class HIComboAbility 
{

public:
	HIComboAbility();
	
private:
	static unsigned int comboAbilitySequence;

	const unsigned int COMBO_ABILITY_ID = 0;

	TSubclassOf<UGameplayAbility> gameplayAbility;

	int abilityWeight;

	int abilityPriority;

	float abilityActivationDelay;

public:

#pragma region GETTERS

	const unsigned int GetComboAbilityID() const;

	const TSubclassOf<UGameplayAbility> GetGameplayAbility() const;

	const int GetAbilityWeight() const;

	const int GetAbilityPriority() const;

	const float GetAbilityActivationDelay() const;

#pragma endregion

#pragma region SETTERS
	void SetGameplayAbility(TSubclassOf<UGameplayAbility>& newGameplayAbility);

	void SetAbilityWeight(int newAbilityWeight);

	void SetAbilityPriority(int newAbilityPriority);

	void SetAbilityActivationDelay(float newAbilityActivationDelay);
#pragma endregion

#pragma region OPERATORS
	friend bool operator==(const HIComboAbility& lhs, const HIComboAbility& rhs);
	HIComboAbility& operator=(const HIComboAbility& other);
#pragma  endregion
};
