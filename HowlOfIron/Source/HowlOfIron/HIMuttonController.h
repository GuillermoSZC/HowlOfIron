// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "HIMuttonController.generated.h"

/**
 * 
 */
UCLASS()
class HOWLOFIRON_API AHIMuttonController : public AAIController
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = "MuttonController")
		void HIUpdateNextWaypoint();

	UFUNCTION(BlueprintCallable, Category = "MuttonController")
		void HIShoot();

	UFUNCTION(BlueprintCallable, Category = "MuttonController")
		void HICheckNearbyEnemy();

public:
	UPROPERTY(EditAnywhere)
	float hitRadius = 100.f;
	//UFUNCTION(BlueprintCallable, Category = "Ejercicio")
	//	void CheckNearbyEnemy();

	//UFUNCTION(BlueprintCallable, Category = "Ejercicio")
	//	EPathFollowingRequestResult::Type MoveToEnemy();

};
