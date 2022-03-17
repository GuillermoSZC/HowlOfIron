// Fill out your copyright notice in the Description page of Project Settings.


#include "HIAICharacter.h"
#include "HIMuttonController.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "HowlOfIronCharacter.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundCue.h"
#include "HIAIAnimInstance.h"
#include "Particles/ParticleEmitter.h"
#include "Particles/ParticleSystem.h"

// Sets default values
AHIAICharacter::AHIAICharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TP_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("TP_Gun"));
	TP_Gun->SetupAttachment(GetMesh(), TEXT("hand_rSocket"));

	static ConstructorHelpers::FObjectFinder<USoundCue> dieSoundCueObject(TEXT("SoundCue'/Game/RESOURCES/CHARACTER/ENEMIES/SFX/Enemy_death_Cue.Enemy_death_Cue'"));
	if (dieSoundCueObject.Succeeded())
	{
		dieSoundCue = dieSoundCueObject.Object;

		dieAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("DieAudioComponent"));
		dieAudioComponent->SetupAttachment(RootComponent);
	}

	static ConstructorHelpers::FObjectFinder<UParticleSystem> particleSystemClass(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));
	particleSystem = particleSystemClass.Object;
}

// Called when the game starts or when spawned
void AHIAICharacter::BeginPlay()
{
	Super::BeginPlay();

	if (dieSoundCue && dieAudioComponent)
	{
		dieAudioComponent->SetSound(dieSoundCue);
	}
	
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
	//HIChangeAnimationToTakeDamage();
	UHIAIAnimInstance* animInstance = Cast<UHIAIAnimInstance>(GetMesh()->GetAnimInstance());
	animInstance->takingDamage = true;
	GetWorld()->GetTimerManager().SetTimer(DelayToStopAnimation, this, &AHIAICharacter::HIStopAnimationTakingDamage, 0.2f, false);

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
		//PlayAnimMontage();
		//UHIAIAnimInstance* animInstance = Cast<UHIAIAnimInstance>(GetMesh()->GetAnimInstance());
		//if (animInstance)
		//{
		//	animInstance->Montage_Play()
		//}
		animInstance->isDead = true;
		//HIDie();
		//dieAudioComponent->Play();
	}
}

void AHIAICharacter::HIStopAnimationTakingDamage()
{
	UHIAIAnimInstance* animInstance = Cast<UHIAIAnimInstance>(GetMesh()->GetAnimInstance());
	animInstance->takingDamage = false;
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
	UE_LOG(LogTemp, Warning, TEXT("instakill"));
    Cast<AAIController>(GetController())->GetBlackboardComponent()->SetValueAsBool("IsDead", true);
    //HIDie();
	UHIAIAnimInstance* animInstance = Cast<UHIAIAnimInstance>(GetMesh()->GetAnimInstance());
	animInstance->isDead = true;
	//dieAudioComponent->Play();


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

void AHIAICharacter::HISpawnParticles()
{
	UE_LOG(LogTemp, Warning, TEXT("Spawn Particles"));
	FVector particlesLocation = TP_Gun->GetBoneLocation(FName(TEXT("b_gun_muzzleflash")));
	FTransform particlesTransform;
	particlesTransform.SetLocation(particlesLocation);
	particlesTransform.SetScale3D(particlesScale);
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), particleSystem, particlesTransform, true);
}