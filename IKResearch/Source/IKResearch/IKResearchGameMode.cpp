// Copyright Epic Games, Inc. All Rights Reserved.

#include "IKResearchGameMode.h"
#include "IKResearchCharacter.h"
#include "UObject/ConstructorHelpers.h"

AIKResearchGameMode::AIKResearchGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
