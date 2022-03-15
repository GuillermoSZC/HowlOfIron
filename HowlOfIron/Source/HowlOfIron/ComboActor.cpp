// Fill out your copyright notice in the Description page of Project Settings.


#include "ComboActor.h"

// Sets default values
AComboActor::AComboActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	body = CreateDefaultSubobject<UStaticMeshComponent>("body");

	comboAbility.SetGameplayAbility(abilityClass);
	comboAbility.SetAbilityActivationDelay(0.f);
	comboAbility.SetAbilityPriority(1);
	comboAbility.SetAbilityWeight(1);

	comboQueue = CreateDefaultSubobject<UHIComboQueue>("comboQueue");
	comboQueue->SetMaxWeight(3);
}

// Called when the game starts or when spawned
void AComboActor::BeginPlay()
{
	Super::BeginPlay();

	comboQueue->Empty();
}

// Called every frame
void AComboActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AComboActor::EnqueueAbility()
{
	comboQueue->Enqueue(comboAbility);
}

