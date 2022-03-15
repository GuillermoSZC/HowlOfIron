// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HIComboQueue.h"
#include "ComboActor.generated.h"

UCLASS()
class HOWLOFIRON_API AComboActor : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* body;

	UPROPERTY(VisibleAnywhere)
	UHIComboQueue* comboQueue;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UGameplayAbility> abilityClass;

	HIComboAbility comboAbility;
	
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
	void EnqueueAbility();

};
