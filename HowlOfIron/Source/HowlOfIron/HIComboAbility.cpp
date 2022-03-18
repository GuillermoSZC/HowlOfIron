// Fill out your copyright notice in the Description page of Project Settings.


#include "HIComboAbility.h"

unsigned int HIComboAbility::comboAbilitySequence = 0;;

HIComboAbility::HIComboAbility() : COMBO_ABILITY_ID(comboAbilitySequence)
{
	++comboAbilitySequence;
}

const FGameplayAbilitySpecHandle HIComboAbility::GetGameplayAbilityHandle() const
{
	return gameplayAbilityHandle;
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

void HIComboAbility::SetGameplayAbilityHandle(FGameplayAbilitySpecHandle& newGameplayAbility)
{
	gameplayAbilityHandle = newGameplayAbility;
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
	gameplayAbilityHandle = other.gameplayAbilityHandle;
	abilityActivationDelay = other.abilityActivationDelay;
	abilityPriority = other.abilityPriority;
	abilityWeight = other.abilityWeight;

	return *this;
}