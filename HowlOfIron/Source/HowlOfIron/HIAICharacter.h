// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NiagaraComponent.h"
#include "HIAICharacter.generated.h"

UCLASS()
class HOWLOFIRON_API AHIAICharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHIAICharacter();

private:
	FTimerHandle DelayToStopAnimation;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float health = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float damageReceived = 40.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	bool isAlerted = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float distanceToStop = 1000.f;

	//UPROPERTY(EditAnywhere, Category = "Attributes")
	//class UNiagaraComponent* particleSystem;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USkeletalMeshComponent* TP_Gun;

	UPROPERTY(VisibleDefaultsOnly, Category = Sound)
	class USoundCue* dieSoundCue;

	UPROPERTY(VisibleDefaultsOnly, Category = Sound)
	class UAudioComponent* dieAudioComponent;



public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//void GoBack();

	UFUNCTION(BlueprintImplementableEvent)
	void HIChangeAnimationToAim();

	UFUNCTION(BlueprintImplementableEvent)
	void HIChangeAnimationToGoBack();

	UFUNCTION(BlueprintImplementableEvent)
	void HIChangeAnimationToTakeDamage();

	UFUNCTION(BlueprintImplementableEvent)
	void HIDie();

	UFUNCTION(BlueprintCallable)
	void HIInstaKill();

	UFUNCTION(BlueprintCallable)
	void HITakeDamage(AActor* _overlapedActor);

	UFUNCTION(BlueprintCallable)
	void HIStopAnimationTakingDamage();

	UFUNCTION(BlueprintCallable)
	void HISpawnParticles();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// This class is a predeclaration (to avoid the include)
	class UMaterialInstanceDynamic* m_pDynamicMat = nullptr;
};
