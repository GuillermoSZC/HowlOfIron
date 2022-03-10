// Fill out your copyright notice in the Description page of Project Settings.


#include "HIAICharacter.h"
#include "HIMuttonController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "HowlOfIronCharacter.h"

// Sets default values
AHIAICharacter::AHIAICharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AHIAICharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

//void AHIAICharacter::GoBack()
//{
//	HIChangeAnimationToGoBack();
//	//AnimInstance->Montage_Play(TP_FireAnimation, 1.f);
//	UE_LOG(LogTemp, Warning, TEXT("Disparo"));
//}

void AHIAICharacter::HITakeDamage(AActor* _overlapedActor)
{
	health -= damageReceived;
	// take damage animation
	HIChangeAnimationToTakeDamage();

	// Alert the others
	if (!isAlerted)
	{
		TArray<AActor*> muttonsArray;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AHIAICharacter::StaticClass(), muttonsArray);
		for (AActor* mutton : muttonsArray)
		{
			AHIAICharacter* muttonCharacter = Cast<AHIAICharacter>(mutton);
			muttonCharacter->isAlerted = true;
			Cast<AAIController>(muttonCharacter->GetController())->GetBlackboardComponent()->SetValueAsObject("TargetActorToFollow", _overlapedActor);
			Cast<AAIController>(muttonCharacter->GetController())->GetBlackboardComponent()->SetValueAsBool("IsAlert", true);
		}
	}

	if (health <= 0)
	{
		Cast<AAIController>(GetController())->GetBlackboardComponent()->SetValueAsBool("IsDead", true);
		HIDie();
	}
}

// Called every frame
void AHIAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//// One shoot each 0.5 seconds
	//timer += DeltaTime;
	//if (isShooting && timer >= 0.5f)
	//{
	//	timer = 0.f;
	//	GetMesh()->GetAnimInstance()->Montage_Play(TP_FireAnimation, 1.f);
	//}
}

// Called to bind functionality to input
void AHIAICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AHIAICharacter::HIInstaKill()
{
	health = 0.f;
    if (health <= 0)
    {
        Cast<AAIController>(GetController())->GetBlackboardComponent()->SetValueAsBool("IsDead", true);
        HIDie();


        TArray<AActor*> muttonsArray;
        UGameplayStatics::GetAllActorsOfClass(GetWorld(), AHIAICharacter::StaticClass(), muttonsArray);
        for (AActor* mutton : muttonsArray)
        {
            AHIAICharacter* muttonCharacter = Cast<AHIAICharacter>(mutton);
            muttonCharacter->isAlerted = true;
            Cast<AAIController>(muttonCharacter->GetController())->GetBlackboardComponent()->SetValueAsObject("TargetActorToFollow", UGameplayStatics::GetActorOfClass(GetWorld(),AHowlOfIronCharacter::StaticClass()));
            Cast<AAIController>(muttonCharacter->GetController())->GetBlackboardComponent()->SetValueAsBool("IsAlert", true);
        }
    }

}