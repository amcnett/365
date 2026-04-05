// Copyright Epic Games, Inc. All Rights Reserved.

#include "RollerGameMode.h"
#include "RollerPlayerController.h"
#include "UObject/ConstructorHelpers.h"

ARollerGameMode::ARollerGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_MyRollerPlayerController")); 
    if (PlayerControllerBPClass.Class != NULL)
    {
    	PlayerControllerClass = PlayerControllerBPClass.Class;
    }
	
	
}
