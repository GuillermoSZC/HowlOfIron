// Fill out your copyright notice in the Description page of Project Settings.


#include "HIMuttonController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BrainComponent.h"
#include "DrawDebugHelpers.h"
#include "HIAICharacter.h"
#include "HIMuttonWaypoint.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Runtime/Engine/Public/EngineUtils.h"

void AHIMuttonController::HIUpdateNextWaypoint()
{
	// Obtiene la referencia al BlackboardComponent del AIController
	UBlackboardComponent* blackboardComponent = BrainComponent->GetBlackboardComponent();	
	
	TArray<AActor*> waypointsArray;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AHIMuttonWaypoint::StaticClass(), waypointsArray);

	int32 targetPointIndex = (blackboardComponent->GetValueAsInt("WaypointIndex") + 1) % waypointsArray.Num();
	blackboardComponent->SetValueAsInt("WaypointIndex", targetPointIndex);

	for (AActor* waypoint : waypointsArray)
	{
		AHIMuttonWaypoint* muttonWaypoint = Cast<AHIMuttonWaypoint>(waypoint);

		if (muttonWaypoint->allowedAccess.Find(Cast<AHIAICharacter>(GetPawn())) != -1 && targetPointIndex == muttonWaypoint->waypointIndex)
		{
			blackboardComponent->SetValueAsVector("WaypointPosition", muttonWaypoint->GetActorLocation());
			break;
		}
	}

	//blackboardComponent->SetValueAsInt("WaypointIndex", targetPointIndex + 1);
}

void AHIMuttonController::HIShoot()
{
	// Obtiene la referencia al BlackboardComponent del AIController
	UBlackboardComponent* blackboardComponent = BrainComponent->GetBlackboardComponent();

	AActor* actorToFollow = Cast<AActor>(blackboardComponent->GetValueAsObject("TargetActorToFollow"));
	APawn* pawn = GetPawn();
	// Mirar a player
	pawn->SetActorRotation(UKismetMathLibrary::FindLookAtRotation(pawn->GetActorLocation(), actorToFollow->GetActorLocation()));
	
	FVector distanceFromPlayer = pawn->GetActorLocation() - actorToFollow->GetActorLocation();
	if (distanceFromPlayer.Size() <= Cast<AHIAICharacter>(pawn)->distanceToStop)
	{
		// Animacion ir para atras
		Cast<AHIAICharacter>(pawn)->HIChangeAnimationToGoBack();
		// Move hacia atras
		distanceFromPlayer.Normalize();
		pawn->SetActorLocation(pawn->GetActorLocation() + distanceFromPlayer * 2.f);
	}
	else
	{
		// Animacion de apuntar
		Cast<AHIAICharacter>(pawn)->HIChangeAnimationToAim();
	}
}

void AHIMuttonController::HICheckNearbyEnemy()
{
	// Pawn del NPC
	APawn* pawn = GetPawn();

	FVector multiSphereStart = pawn->GetActorLocation();

	FVector multiSphereEnd = multiSphereStart + FVector(0.f, 0.f, 15.0f);

	TArray<TEnumAsByte<EObjectTypeQuery> > objectTypes;
	objectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));

	TArray<AActor*> actorsToIgnore;
	actorsToIgnore.Add(pawn);

	TArray<FHitResult> outHits;

	bool result = UKismetSystemLibrary::SphereTraceMultiForObjects(GetWorld(),
		multiSphereStart,
		multiSphereEnd,
		hitRadius,
		objectTypes,
		false,
		actorsToIgnore,
		//EDrawDebugTrace::ForDuration,
		EDrawDebugTrace::None,
		outHits,
		true);

	//TArray<UBlackboardComponent*> blackboardComponents;// = GetBlackboardComponent();// BrainComponent->GetBlackboardComponent();

	TArray<AActor*> muttonControllers;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AHIMuttonController::StaticClass(), muttonControllers);

	if (result)
	{
		for (int32 i = 0; i < outHits.Num(); ++i)
		{
			FHitResult Hit = outHits[i];

			APawn* playerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

			if (Hit.GetActor() == playerPawn)
			{
				FCollisionQueryParams FQParams;
				FQParams.AddIgnoredActor(pawn);

				// Ray to the target (extra)
				FHitResult OutHit;
				bool result2 = GetWorld()->LineTraceSingleByChannel(OutHit,
					pawn->GetActorLocation(),
					playerPawn->GetActorLocation(),
					ECollisionChannel::ECC_Camera,
					FQParams);
				// Draw the line (optional)
				//DrawDebugLine(GetWorld(),
				//	pawn->GetActorLocation(),
				//	playerPawn->GetActorLocation(),
				//	FColor::Yellow,
				//	false,
				//	2.f);

				if (result2 && OutHit.GetActor() == playerPawn)
				{
					for (AActor* muttonController : muttonControllers)
					{
						Cast<AHIMuttonController>(muttonController)->GetBlackboardComponent()->SetValueAsObject("TargetActorToFollow", playerPawn);
						Cast<AHIMuttonController>(muttonController)->GetBlackboardComponent()->SetValueAsBool("IsAlert", true);
						// if this -> muere
						if (muttonController == this)
						{
							Cast<AHIMuttonController>(muttonController)->GetBlackboardComponent()->SetValueAsBool("IsDead", true);
							Cast<AHIAICharacter>(pawn)->HIDie();
						}
						/*else
						{
						}*/
					}
					break;
				}
				else
				{
					//for (AActor* muttonController : muttonControllers)
					//{
					//	Cast<AHIMuttonController>(muttonController)->GetBlackboardComponent()->SetValueAsObject("TargetActorToFollow", NULL);
					//	Cast<AHIMuttonController>(muttonController)->GetBlackboardComponent()->SetValueAsBool("IsAlert", false);
					//}
					break;
				}
			}
		}
	}
	else
	{
		//for (AActor* muttonController : muttonControllers)
		//{
		//	Cast<AHIMuttonController>(muttonController)->GetBlackboardComponent()->SetValueAsObject("TargetActorToFollow", NULL);
		//	Cast<AHIMuttonController>(muttonController)->GetBlackboardComponent()->SetValueAsBool("IsAlert", false);
		//}
	}
}