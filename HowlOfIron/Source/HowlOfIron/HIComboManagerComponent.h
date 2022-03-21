// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <AbilitySystemComponent.h>
#include "HIComboQueue.h"
#include <Abilities/GameplayAbility.h>
#include "HIComboAbility.h"
#include <Components/InputComponent.h>
#include "HIComboManagerComponent.generated.h"

UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
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

	const int MAX_WEIGHT = 3;
	const float QUEUE_RESET_COOLDOWN = 2.f;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UGameplayAbility> basicAbilityClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UGameplayAbility> strongAbilityClass;

	UPROPERTY(EditAnywhere)
		TSubclassOf<UGameplayAbility> cancelAbilityClass;

	HIComboAbility basicAbility;
	HIComboAbility strongAbility;
	HIComboAbility cancelAbility;

	bool launchingAbility;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetInputBindings(class UInputComponent* inputComponent);

	void AttachAbilitySystem(UAbilitySystemComponent* attachedAbilitySystem);

	void EnqueueAbility(HIComboAbility& comboAbility);

	void ResetComboAndEnqueueAbility(HIComboAbility& comboAbility);

	void EnqueueBasicAbility();

	void EnqueueStrongAbility();

	void EnqueueCancelAbility();

	UFUNCTION() 
	void OnComboAbilityActivated(UGameplayAbility* launchedAbility);

	UFUNCTION()
	void OnComboAbilityEnded(UGameplayAbility* launchedAbility);
};
