#pragma once

#include "Global.h"
#include "CoreMinimal.h"
#include "Engine/World.h"

class RPG_PROJECT_1_API Timer
{

private:
	
	TMap<FString, FTimerHandle>  mTimers;

public:

	static void SetTimer(FString TimerName, UObject* Object, FString FunctionName, float TickPerSecond, bool IsLoop, float DelayedTime)
	{

		//FTimerHandle handle = UKismetSystemLibrary::K2_SetTimer(Object, FunctionName, TickPerSecond, IsLoop, DelayedTime);
		
		//mTimers[TimerName] = handle;
	}


};