// Copyright Epic Games, Inc. All Rights Reserved.

#include "RPG_PROJECT_1GameMode.h"
#include "Global.h"

#include "UObject/ConstructorHelpers.h"

ARPG_PROJECT_1GameMode::ARPG_PROJECT_1GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Script/Engine.Blueprint'/Game/Blueprints/Player/BP_Player.BP_Player_C'"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}