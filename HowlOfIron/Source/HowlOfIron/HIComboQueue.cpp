// Fill out your copyright notice in the Description page of Project Settings.


#include "HIComboQueue.h"

UHIComboQueue::UHIComboQueue()
{
	
}

void UHIComboQueue::Update(float deltaTime)
{
	if (IsEmpty() == false) {
		timeFilled += deltaTime;

		if (timeFilled >= queueResetCooldown) {
			Empty();
			timeFilled = 0.f;
		}
	}
	
}

bool UHIComboQueue::Dequeue(HIComboAbility& ability_)
{
	if (abilitiesArray.Num() > 0) {
		ability_ = abilitiesArray.Pop();

		return true;
	}
	
	return false;
}

bool UHIComboQueue::Enqueue(const HIComboAbility& _ability)
{

	if (IsFull() == false) {
		abilitiesArray.Add(_ability);
		freeWeight -= _ability.GetAbilityWeight();
		timeFilled = 0.f;

		return true;
	}
	else {

		if (abilitiesArray.Num() > 0) {
			abilitiesArray[abilitiesArray.Num() - 1] = _ability;
		}
		
	}
	
	return false;
}

void UHIComboQueue::Empty()
{
	abilitiesArray.Empty();

	freeWeight = maxWeight;
}

bool UHIComboQueue::IsEmpty()
{
	return freeWeight == maxWeight;
}

bool UHIComboQueue::IsFull()
{
	return freeWeight <= 0;
}

const int UHIComboQueue::GetMaxWeight() const
{
	return maxWeight;
}

const int UHIComboQueue::GetQueueResetCooldown() const
{
	return queueResetCooldown;
}

void UHIComboQueue::SetMaxWeight(int newMaxWeight)
{
	maxWeight = newMaxWeight;
}

void UHIComboQueue::SetQueueResetCooldown(float newQueueResetCooldown)
{
	queueResetCooldown = newQueueResetCooldown;
}
