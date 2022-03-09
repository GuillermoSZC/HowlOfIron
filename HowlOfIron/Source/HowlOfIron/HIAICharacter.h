// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HIAICharacter.generated.h"

UCLASS()
class HOWLOFIRON_API AHIAICharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHIAICharacter();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Fire();

	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION(BlueprintImplementableEvent)
	void ChangeAnimationToGoBack();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// This class is a predeclaration (to avoid the include)
	class UMaterialInstanceDynamic* m_pDynamicMat = nullptr;
};
