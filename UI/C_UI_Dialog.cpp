// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/C_UI_Dialog.h"
#include "Global.h"
#include "System/C_DialogSystem.h"

#include "Components/TextBlock.h"
#include "Components/Button.h"


void UC_UI_Dialog::NativeConstruct()
{
	Super::NativeConstruct();
	
	PRINT(BTN_NextLine->GetName());
	BTN_NextLine->OnClicked.AddDynamic(GAMEMODE->GetDialogSystem(), &AC_DialogSystem::NextLine);

	
}

void UC_UI_Dialog::NativeTick(const FGeometry& MyGeometry, float DeltaTime)
{
	Super::NativeTick(MyGeometry, DeltaTime);

	iTextIndex++;
	if (iTextIndex == CurrentLine.Len()) return;

	TXT_DialogueLine->SetText(FText::FromString(CurrentLine.Left(iTextIndex)));
}

void UC_UI_Dialog::UpdateLine(FString line)
{
	CurrentLine = line;
	iTextIndex = -1;
}

void UC_UI_Dialog::SetDialogName(FString name)
{
	TXT_Name->SetText(FText::FromString(name));
}
