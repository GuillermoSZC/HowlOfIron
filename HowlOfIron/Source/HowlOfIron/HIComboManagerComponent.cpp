// Fill out your copyright notice in the Description page of Project Settings.


#include "HIComboManagerComponent.h"
#include <Components/InputComponent.h>

// Sets default values for this component's properties
UHIComboManagerComponent::UHIComboManagerComponent() : launchingAbility(false)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

	comboQueue = CreateDefaultSubobject<UHIComboQueue>("comboQueue");
	comboQueue->SetMaxWeight(3);
	comboQueue->SetQueueResetCooldown(5.f);
}


// Called when the game starts
void UHIComboManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

	comboQueue->Empty();
}

// Called every frame
void UHIComboManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	if (abilitySystem) {
		HIComboAbility launchedAbility;
		if (!launchingAbility) {
			if (comboQueue->Dequeue(launchedAbility)) {
				abilitySystem->CallServerTryActivateAbility(launchedAbility.GetGameplayAbilityHandle(), false, FPredictionKey());
			}
		}
	}

	comboQueue->Update(DeltaTime);
}

void UHIComboManagerComponent::SetInputBindings(UInputComponent* inputComponent)
{
	inputComponent->BindAction("BasicAttack", IE_Pressed, this, &UHIComboManagerComponent::EnqueueBasicAbility);
	inputComponent->BindAction("StrongAttack", IE_Pressed, this, &UHIComboManagerComponent::EnqueueStrongAbility);
}

void UHIComboManagerComponent::AttachAbilitySystem(UAbilitySystemComponent* attachedAbilitySystem)
{
	abilitySystem = attachedAbilitySystem;

	abilitySystem->AbilityActivatedCallbacks.AddUFunction(this, FName("OnComboAbilityActivated"));
	abilitySystem->AbilityEndedCallbacks.AddUFunction(this, FName("OnComboAbilityEnded"));

	FGameplayAbilitySpecHandle basicAbilityHandle = abilitySystem->GiveAbility(FGameplayAbilitySpec(basicAbilityClass.GetDefaultObject(), 1, 0));
	FGameplayAbilitySpecHandle strongAbilityHandle = abilitySystem->GiveAbility(FGameplayAbilitySpec(strongAbilityClass.GetDefaultObject(), 1, 0));

	basicAbility.SetGameplayAbilityHandle(basicAbilityHandle);
	basicAbility.SetAbilityActivationDelay(0.f);
	basicAbility.SetAbilityPriority(1);
	basicAbility.SetAbilityWeight(1);

	strongAbility.SetGameplayAbilityHandle(strongAbilityHandle);
	strongAbility.SetAbilityActivationDelay(0.f);
	strongAbility.SetAbilityPriority(1);
	strongAbility.SetAbilityWeight(3);
}

void UHIComboManagerComponent::EnqueueBasicAbility()
{
	comboQueue->Enqueue(basicAbility);
}

void UHIComboManagerComponent::EnqueueStrongAbility()
{
	comboQueue->Enqueue(strongAbility);
}

void UHIComboManagerComponent::OnComboAbilityActivated(UGameplayAbility* launchedAbility)
{
	launchingAbility = true;
}

void UHIComboManagerComponent::OnComboAbilityEnded(UGameplayAbility* launchedAbility)
{
	launchingAbility = false;
}

