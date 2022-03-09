// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TargetPoint.h"
#include "HIMuttonWaypoint.generated.h"

class AHIAICharacter;

/**
 * 
 */
UCLASS()
class HOWLOFIRON_API AHIMuttonWaypoint : public ATargetPoint
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Waypoints Attributes")
	int32 waypointIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Waypoints Attributes")
	TArray<AHIAICharacter*> allowedAccess;
};
