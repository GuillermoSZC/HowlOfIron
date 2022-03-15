// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include <Containers/Queue.h>
#include "HIComboAbility.h"
#include "HIComboQueue.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class HOWLOFIRON_API UHIComboQueue : public UObject
{
	GENERATED_BODY()

public:
	UHIComboQueue();

private:

	TQueue<HIComboAbility> abilitiesQueue;

	UPROPERTY(VisibleAnywhere, Category = "Combo")
	int maxWeight;

	UPROPERTY(VisibleAnywhere, Category = "Combo")
	int freeWeight;

public:

	/// <summary>
	/// Removes and returns the ability from the tail of the queue.
	/// </summary>
	/// <param name="ability"> variable where tail ability is going to be copied </param>
	/// <returns> true if the value was successfully copied, else return false </returns>
	bool Dequeue(HIComboAbility& ability_);

	/// <summary>
	/// Adds an ability to the head of the queue
	/// </summary>
	/// <param name="_ability"> Ability that is going to be added </param>
	/// <returns> true if ability was successfully added, else returns false </returns>
	bool Enqueue(const HIComboAbility& _ability);

	/// <summary>
	/// Clears queue content
	/// </summary>
	void Empty();

	/// <summary>
	/// Checks if the queue is empty
	/// </summary>
	/// <returns> true if the queue is empty, false if is not </returns>
	bool IsEmpty();

	/// <summary>
	/// Checks if queue is at maximum capacity
	/// </summary>
	/// <returns> returns true if queue is full, else return false </returns>
	bool IsFull();

#pragma region GETTERS
	UFUNCTION()
	const int GetMaxWeight() const;
#pragma  endregion

#pragma region SETTERS
	UFUNCTION()
	void SetMaxWeight(int newMaxWeight);
#pragma endregion
};
