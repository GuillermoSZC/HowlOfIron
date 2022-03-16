// Fill out your copyright notice in the Description page of Project Settings.


#include "HIComboQueue.h"

UHIComboQueue::UHIComboQueue()
{
	
}

bool UHIComboQueue::Dequeue(HIComboAbility& ability_)
{
	return abilitiesQueue.Dequeue(ability_);
}

bool UHIComboQueue::Enqueue(const HIComboAbility& _ability)
{

	if (IsFull() == false) {
		bool success = abilitiesQueue.Enqueue(_ability);

		if (success) {
			freeWeight -= _ability.GetAbilityWeight();
		}

		return success;
	}
	
	return false;
}

void UHIComboQueue::Empty()
{
	abilitiesQueue.Empty();

	freeWeight = maxWeight;
}

bool UHIComboQueue::IsEmpty()
{
	return abilitiesQueue.IsEmpty() && freeWeight == maxWeight;
}

bool UHIComboQueue::IsFull()
{
	return freeWeight <= 0;
}

const int UHIComboQueue::GetMaxWeight() const
{
	return maxWeight;
}

void UHIComboQueue::SetMaxWeight(int newMaxWeight)
{
	maxWeight = newMaxWeight;
}
