// Fill out your copyright notice in the Description page of Project Settings.


#include "HIServiceCheckAlert.h"
#include "HIMuttonController.h"

void UHIServiceCheckAlert::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	AHIMuttonController* AIEnemyController = Cast<AHIMuttonController>(OwnerComp.GetOwner());

	AIEnemyController->HICheckNearbyEnemy();
}