// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "PlayerAttributes.h"
#include "GameFramework/Character.h"
#include "HIComboManagerComponent.h"
#include "HowlOfIronCharacter.generated.h"

UCLASS(config=Game)
class AHowlOfIronCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
public:
	AHowlOfIronCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

    /** Returns CameraBoom subobject **/
    FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
    /** Returns FollowCamera subobject **/
    FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities", meta = (AllowPrivateAccess = "true"))
		class UAbilitySystemComponent* AbilitySystem;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Abilities")
		UDataTable* AttrDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities | Debugging")
		bool bAttDebugging;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities | Debugging")
		TArray<TSubclassOf<class UGameplayAbility>> DebuggingPassiveAbilities;
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
        TArray<TSubclassOf<class UGameplayAbility>> StartingPassiveAbilities;

private:

	UPROPERTY(VisibleAnywhere)
	UHIComboManagerComponent* comboManagerComponent;

protected:

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	void BeginPlay() override;

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface
	
private:
	UAbilitySystemComponent* GetAbilitySystemComponent() const override
	{
		return AbilitySystem;
	}


};

