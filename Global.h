#pragma once

#include "Utilities/CHelpers.h"
#include "Utilities/Timer.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetStringLibrary.h"
#include "KismetAnimationLibrary.h"

#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

#include "RPG_PROJECT_1GameMode.h"

#define PRINT(s) UKismetSystemLibrary::PrintString(GetWorld(), s)
#define GAMEMODE Cast<ARPG_PROJECT_1GameMode>(UGameplayStatics::GetGameMode(GetWorld()))

#define PLAYERCHARACTER(x) UGameplayStatics::GetPlayerCharacter(GetWorld(), x)
#define PLAYERCONTROLLER(x) UGameplayStatics::GetPlayerController(GetWorld(), x)

#define SUBSYSTEM(T) CHelpers::GetSubSystem<T>(GetWorld())