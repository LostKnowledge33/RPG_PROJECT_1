#pragma once

#include "Utilities/CHelpers.h"

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