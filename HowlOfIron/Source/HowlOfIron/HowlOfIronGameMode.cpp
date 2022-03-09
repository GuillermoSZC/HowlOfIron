// Copyright Epic Games, Inc. All Rights Reserved.

#include "HowlOfIronGameMode.h"
#include "HowlOfIronCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHowlOfIronGameMode::AHowlOfIronGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
