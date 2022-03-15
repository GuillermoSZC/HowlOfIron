// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "HIAIAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class HOWLOFIRON_API UHIAIAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UHIAIAnimInstance();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	float speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	float direction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	bool enableJump;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	bool jumping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	bool crouching;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	bool goBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	bool isDead;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	bool takingDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	bool aiming;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	//bool CanJump(bool _shouldJump);
};
