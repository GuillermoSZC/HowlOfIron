// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "HITaskMuttonShoot.generated.h"

/**
 * 
 */
UCLASS()
class HOWLOFIRON_API UHITaskMuttonShoot : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UHITaskMuttonShoot();

private:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);

	virtual FString GetStaticDescription() const override;
};
