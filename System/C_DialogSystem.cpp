// Fill out your copyright notice in the Description page of Project Settings.


#include "System/C_DialogSystem.h"
#include "Global.h"
#include "UI/C_UI_Dialog.h"

#include "Blueprint/UserWidget.h"
#include "GameFramework/Character.h"

// Sets default values
AC_DialogSystem::AC_DialogSystem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CHelpers::GetClass<UC_UI_Dialog>(&UI_Dialog_Class, "/Script/UMGEditor.WidgetBlueprint'/Game/Blueprints/UI/Dialog/UI_Dialogue.UI_Dialogue_C'");
	CHelpers::GetClass<UC_UI_Responses>(&UI_Response_Class, "/Script/UMGEditor.WidgetBlueprint'/Game/Blueprints/UI/Dialog/UI_Responses.UI_Responses_C'");
}

// Called when the game starts or when spawned
void AC_DialogSystem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AC_DialogSystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AC_DialogSystem::BeginDialog(UDA_Dialog* _Dialog)
{
	UI_Dialog_Widget = CreateWidget<UC_UI_Dialog>(GetWorld(), UI_Dialog_Class);
	
	if (UI_Dialog_Widget == nullptr)
	{
		PRINT("Dialog is NULL");
		return;
	}

	UI_Dialog_Widget->AddToViewport();

	UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->DisableInput(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->bShowMouseCursor = true;

	Dialog = _Dialog;

	UI_Dialog_Widget->SetDialogName(Dialog->NpcName);

	NextLine();
}

void AC_DialogSystem::EndDialog()
{

}

void AC_DialogSystem::NextLine()
{
	iLineIndex++;

	if (iLineIndex >= Dialog->Lines.Num())
	{
		if (!Dialog->Responses.IsEmpty())
		{
			UI_Response_Widget = CreateWidget<UC_UI_Responses>(GetWorld(), UI_Response_Class);
			UI_Response_Widget->SetResponses(Dialog->Responses);
			UI_Response_Widget->AddToViewport();
			PRINT("Create Widget");
		}
		
		return;
	}
	
	UI_Dialog_Widget->UpdateLine(Dialog->Lines[iLineIndex]);
}

