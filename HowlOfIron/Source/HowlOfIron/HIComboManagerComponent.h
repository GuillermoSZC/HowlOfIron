// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <AbilitySystemComponent.h>
#include "HIComboQueue.h"
#include <Abilities/GameplayAbility.h>
#include "HIComboAbility.h"
#include "HIComboManagerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HOWLOFIRON_API UHIComboManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UHIComboManagerComponent();

private:

	UPROPERTY(VisibleAnywhere)
	UAbilitySystemComponent* abilitySystem;

	UPROPERTY(VisibleAnywhere)
	UHIComboQueue* comboQueue;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UGameplayAbility> basicAbilityClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UGameplayAbility> strongAbilityClass;

	HIComboAbility basicAbility;
	HIComboAbility strongAbility;

	bool launchingAbility;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void EnqueueBasicAbility();

	void EnqueueStrongAbility();

	FTimerHandle updateTimer;

	UFUNCTION() 
	void OnComboAbilityActivated(UGameplayAbility* launchedAbility);

	UFUNCTION()
	void OnComboAbilityEnded(UGameplayAbility* launchedAbility);
};
