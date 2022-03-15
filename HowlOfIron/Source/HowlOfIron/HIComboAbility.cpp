// Fill out your copyright notice in the Description page of Project Settings.


#include "HIComboAbility.h"

unsigned int HIComboAbility::comboAbilitySequence = 0;;

HIComboAbility::HIComboAbility() : COMBO_ABILITY_ID(comboAbilitySequence)
{
	++comboAbilitySequence;
}

const TSubclassOf<UGameplayAbility> HIComboAbility::GetGameplayAbility() const
{
	return gameplayAbility;
}

const int HIComboAbility::GetAbilityWeight() const
{
	return abilityWeight;
}

const int HIComboAbility::GetAbilityPriority() const
{
	return abilityPriority;
}

const float HIComboAbility::GetAbilityActivationDelay() const
{
	return abilityActivationDelay;
}

const unsigned int HIComboAbility::GetComboAbilityID() const
{
	return COMBO_ABILITY_ID;
}

void HIComboAbility::SetGameplayAbility(TSubclassOf<UGameplayAbility>& newGameplayAbility)
{
	gameplayAbility = newGameplayAbility;
}

void HIComboAbility::SetAbilityWeight(int newAbilityWeight)
{
	abilityWeight = newAbilityWeight;
}

void HIComboAbility::SetAbilityPriority(int newAbilityPriority)
{
	abilityPriority = newAbilityPriority;
}

void HIComboAbility::SetAbilityActivationDelay(float newAbilityActivationDelay)
{
	abilityActivationDelay = newAbilityActivationDelay;
}

bool operator==(const HIComboAbility& lhs, const HIComboAbility& rhs)
{
	return lhs.COMBO_ABILITY_ID == rhs.COMBO_ABILITY_ID;
}

HIComboAbility& HIComboAbility::operator=(const HIComboAbility& other)
{
	gameplayAbility = other.gameplayAbility;
	abilityActivationDelay = other.abilityActivationDelay;
	abilityPriority = other.abilityPriority;
	abilityWeight = other.abilityWeight;

	return *this;
}