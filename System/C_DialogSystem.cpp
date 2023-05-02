// Fill out your copyright notice in the Description page of Project Settings.


#include "System/C_DialogSystem.h"
#include "Global.h"

#include "Blueprint/UserWidget.h"
#include "GameFramework/Character.h"

// Sets default values
AC_DialogSystem::AC_DialogSystem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CHelpers::GetClass<UUserWidget>(&UI_Dialog_Class, "/Script/UMGEditor.WidgetBlueprint'/Game/Blueprints/UI/Dialog/ui_Dialogue.ui_Dialogue_C'");
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
	UUserWidget* ui_Dialog = CreateWidget<UUserWidget>(GetWorld(), UI_Dialog_Class);
	
	if (ui_Dialog == nullptr)
	{
		PRINT("Dialog is NULL");
		return;
	}

	ui_Dialog->AddToViewport();

	UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->DisableInput(UGameplayStatics::GetPlayerController(GetWorld(), 0));
}

void AC_DialogSystem::EndDialog()
{

}

