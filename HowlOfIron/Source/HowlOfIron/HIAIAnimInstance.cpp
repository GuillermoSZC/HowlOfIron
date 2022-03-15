// Fill out your copyright notice in the Description page of Project Settings.


#include "HIAIAnimInstance.h"
#include "HIAICharacter.h"

UHIAIAnimInstance::UHIAIAnimInstance()
{
	speed = 0.f;
}

void UHIAIAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	AHIAICharacter* aiCharacter = Cast<AHIAICharacter>(TryGetPawnOwner());
	
	if (aiCharacter)
	{
		FRotator baseRotation = aiCharacter->GetActorRotation();
		FVector velocity = aiCharacter->GetVelocity();
		speed = velocity.Size();
		direction = CalculateDirection(velocity, baseRotation);
	}

}

//bool UHIAIAnimInstance::CanJump(bool _shouldJump)
//{
//	return (!enableJump && _shouldJump);
//}