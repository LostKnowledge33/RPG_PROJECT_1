// Copyright Epic Games, Inc. All Rights Reserved.

#include "RPG_PROJECT_1GameMode.h"
#include "Global.h"
#include "System/C_DialogSystem.h"


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

void ARPG_PROJECT_1GameMode::PlayDialog(UDA_Dialog* Dialog)
{
	if (DialogSystem == nullptr)
	{
		DialogSystem = GetWorld()->SpawnActor<AC_DialogSystem>();
		DialogSystem->BeginDialog(Dialog);
	}
}

void ARPG_PROJECT_1GameMode::ResetDialog()
{

}
