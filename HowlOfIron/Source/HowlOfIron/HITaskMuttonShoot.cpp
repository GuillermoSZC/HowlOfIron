// Fill out your copyright notice in the Description page of Project Settings.


#include "HITaskMuttonShoot.h"
#include "HIMuttonController.h"
#include "BehaviorTree/BlackboardComponent.h"

UHITaskMuttonShoot::UHITaskMuttonShoot()
{
	bNotifyTick = true;
}

EBTNodeResult::Type UHITaskMuttonShoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AHIMuttonController* muttonController = Cast<AHIMuttonController>(OwnerComp.GetOwner());

	muttonController->HIShoot();

	return EBTNodeResult::Succeeded;
}

FString UHITaskMuttonShoot::GetStaticDescription() const
{
	return TEXT("Shoot to the target");
}
