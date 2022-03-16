// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <AbilitySystemComponent.h>
#include "HIComboManagerComponent.h"
#include "ComboActor.generated.h"

UCLASS()
class HOWLOFIRON_API AComboActor : public AActor
{
	GENERATED_BODY()

private:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* body;

	UPROPERTY(VisibleAnywhere)
	UHIComboManagerComponent* comboManagerComponent;

public:	
	// Sets default values for this actor's properties
	AComboActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void EnqueueAbility(bool attack);
};
