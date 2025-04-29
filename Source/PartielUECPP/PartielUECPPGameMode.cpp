// Copyright Epic Games, Inc. All Rights Reserved.

#include "PartielUECPPGameMode.h"
#include "PartielUECPPCharacter.h"
#include "UObject/ConstructorHelpers.h"

APartielUECPPGameMode::APartielUECPPGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
