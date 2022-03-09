// Fill out your copyright notice in the Description page of Project Settings.


#include "HIAICharacter.h"

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

void AHIAICharacter::Fire()
{
	// Get the animation object for the mesh
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	if (AnimInstance != NULL)
	{
		ChangeAnimationToGoBack();
		//AnimInstance->Montage_Play(TP_FireAnimation, 1.f);
		UE_LOG(LogTemp, Warning, TEXT("Disparo"));
	}
}

float AHIAICharacter::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	return 0.0f;
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

