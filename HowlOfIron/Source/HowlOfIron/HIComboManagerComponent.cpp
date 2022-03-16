// Fill out your copyright notice in the Description page of Project Settings.


#include "HIComboManagerComponent.h"

// Sets default values for this component's properties
UHIComboManagerComponent::UHIComboManagerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

	abilitySystem = CreateDefaultSubobject<UAbilitySystemComponent>("abilitySystem");

	comboQueue = CreateDefaultSubobject<UHIComboQueue>("comboQueue");
	comboQueue->SetMaxWeight(3);
}


// Called when the game starts
void UHIComboManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	comboAbility.SetGameplayAbility(abilityClass);
	comboAbility.SetAbilityActivationDelay(0.f);
	comboAbility.SetAbilityPriority(1);
	comboAbility.SetAbilityWeight(1);

	comboQueue->Empty();
}


// Called every frame
void UHIComboManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	HIComboAbility launchedAbility;
	if (comboQueue->Dequeue(launchedAbility)) {
		FGameplayAbilitySpecHandle SpecHandle = abilitySystem->GiveAbility(FGameplayAbilitySpec(launchedAbility.GetGameplayAbility().GetDefaultObject(), 1, 0));
		abilitySystem->CallServerTryActivateAbility(SpecHandle, false, FPredictionKey());
	}
}

void UHIComboManagerComponent::EnqueueAbility()
{
	comboQueue->Enqueue(comboAbility);
}

