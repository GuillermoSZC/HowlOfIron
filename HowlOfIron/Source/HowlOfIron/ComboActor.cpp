// Fill out your copyright notice in the Description page of Project Settings.


#include "ComboActor.h"

// Sets default values
AComboActor::AComboActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("body"));

	comboManagerComponent = CreateDefaultSubobject<UHIComboManagerComponent>("comboManagerComponent");
}

// Called when the game starts or when spawned
void AComboActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AComboActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AComboActor::EnqueueAbility()
{
	comboManagerComponent->EnqueueAbility();
}

