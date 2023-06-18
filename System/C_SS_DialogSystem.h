// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/C_UI_Dialog.h"
#include "UI/C_UI_Responses.h"
#include "UI/C_UI_ResponseLine.h"

#include "Subsystems/GameInstanceSubsystem.h"
#include "C_SS_DialogSystem.generated.h"

/**
 * 
 */
UCLASS()
class RPG_PROJECT_1_API UC_SS_DialogSystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

private:

	// UI ======================
	TSubclassOf<UC_UI_Dialog> UI_Dialog_Class;
	TSubclassOf<UC_UI_Responses> UI_Response_Class;
	

	UC_UI_Dialog* UI_Dialog_Widget;
	UC_UI_Responses* UI_Response_Widget;

	// UI ======================

	TArray<struct FDialog_Response> Responses;
	

	class UDA_Dialog* Dialog;

	int32 iLineIndex = -1;
	//int32 iTextIndex = 0;

	ACharacter* Player;
	APlayerController* Controller;


private:

	UC_SS_DialogSystem();
	/** Implement this for initialization of instances of the system */
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/** Implement this for deinitialization of instances of the system */
	virtual void Deinitialize() override;

public:

	void BeginDialog(class UDA_Dialog* _Dialog, ACharacter* _Player);
	void EndDialog();

	UFUNCTION()
		void NextLine();
};
