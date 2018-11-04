// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "Village_WarGameMode.h"
#include "Village_WarPlayerController.h"
#include "Village_WarCharacter.h"
#include "UObject/ConstructorHelpers.h"

AVillage_WarGameMode::AVillage_WarGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AVillage_WarPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}