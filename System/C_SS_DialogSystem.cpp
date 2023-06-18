// Fill out your copyright notice in the Description page of Project Settings.


#include "System/C_SS_DialogSystem.h"
#include "Global.h"
#include "UI/C_UI_Dialog.h"

#include "Blueprint/UserWidget.h"
#include "GameFramework/Character.h"
#include "Components/VerticalBox.h"

UC_SS_DialogSystem::UC_SS_DialogSystem()
{
	CHelpers::GetClass<UC_UI_Dialog>(&UI_Dialog_Class, "/Script/UMGEditor.WidgetBlueprint'/Game/Blueprints/UI/Dialog/UI_Dialogue.UI_Dialogue_C'");
	CHelpers::GetClass<UC_UI_Responses>(&UI_Response_Class, "/Script/UMGEditor.WidgetBlueprint'/Game/Blueprints/UI/Dialog/UI_Responses.UI_Responses_C'");
}

void UC_SS_DialogSystem::Initialize(FSubsystemCollectionBase& Collection)
{
	
}

void UC_SS_DialogSystem::Deinitialize()
{

}

void UC_SS_DialogSystem::BeginDialog(UDA_Dialog* _Dialog, ACharacter* _Player)
{
	Dialog = _Dialog;

	if (Dialog == nullptr)
	{
		PRINT("Dialog is NULL");
		return;
	}

	if (Player == nullptr)
	{
		Player = _Player;
		Controller = Cast<APlayerController>(Player->Controller);
	}

	// Init Widgets =============
	if (UI_Dialog_Widget == nullptr)
	{
		UI_Dialog_Widget = CreateWidget<UC_UI_Dialog>(GetWorld(), UI_Dialog_Class);
		UI_Dialog_Widget->AddToViewport();
	}
	// =========================== 

	UI_Dialog_Widget->SetVisibility(ESlateVisibility::Visible);
	UI_Dialog_Widget->SetDialogName(Dialog->NpcName);

	Player->DisableInput(nullptr);
	Controller->bShowMouseCursor = true;
	
	NextLine();
}

void UC_SS_DialogSystem::EndDialog()
{
	UI_Dialog_Widget->SetVisibility(ESlateVisibility::Hidden);
	UI_Dialog_Widget->ResetResponses();
	iLineIndex = -1;
}

void UC_SS_DialogSystem::NextLine()
{
	iLineIndex++;

	if (iLineIndex == Dialog->Lines.Num())
	{
		if (!Dialog->Responses.IsEmpty())
		{
			UI_Dialog_Widget->SetResponses(Dialog->Responses);
		}
		return;
	}
	else if (iLineIndex > Dialog->Lines.Num())
	{
		Controller->bShowMouseCursor = false;
		Player->EnableInput(Controller);

		EndDialog();
		return;
	}

	UI_Dialog_Widget->UpdateLine(Dialog->Lines[iLineIndex]);
}