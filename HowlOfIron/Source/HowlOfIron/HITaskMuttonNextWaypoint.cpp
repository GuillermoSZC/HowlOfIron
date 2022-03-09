// Fill out your copyright notice in the Description page of Project Settings.


#include "HITaskMuttonNextWaypoint.h"
#include "HIMuttonController.h"

UHITaskMuttonNextWaypoint::UHITaskMuttonNextWaypoint()
{
	bNotifyTick = true;
}

EBTNodeResult::Type UHITaskMuttonNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AHIMuttonController* muttonController = Cast<AHIMuttonController>(OwnerComp.GetOwner());

	muttonController->HIUpdateNextWaypoint();

	return EBTNodeResult::Succeeded;
}

FString UHITaskMuttonNextWaypoint::GetStaticDescription() const
{
	return TEXT("Update the next waypoint");
}
