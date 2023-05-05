// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DataAsset/DA_Dialog.h"
#include "System/C_DialogSystem.h"

#include "RPG_PROJECT_1GameMode.generated.h"

UCLASS(minimalapi)
class ARPG_PROJECT_1GameMode : public AGameModeBase
{
	GENERATED_BODY()

private:

	class AC_DialogSystem* DialogSystem;

public:

	ARPG_PROJECT_1GameMode();


	void PlayDialog(UDA_Dialog* Dialog);
	void ResetDialog();


	FORCEINLINE AC_DialogSystem* GetDialogSystem() { return DialogSystem; }

};



