// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/C_UI_Dialog.h"
#include "Global.h"

#include "System/C_SS_DialogSystem.h"
#include "UI/C_UI_ResponseLine.h"

#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Components/VerticalBox.h"


UC_UI_Dialog::UC_UI_Dialog(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	CHelpers::GetClass<UC_UI_ResponseLine>(&UI_ResponseLine_Class, "/Script/UMGEditor.WidgetBlueprint'/Game/Blueprints/UI/Dialog/UI_ResponseLine.UI_ResponseLine_C'");
}

void UC_UI_Dialog::NativeConstruct()
{
	Super::NativeConstruct();

	BTN_NextLine->OnClicked.AddDynamic(SUBSYSTEM(UC_SS_DialogSystem), &UC_SS_DialogSystem::NextLine);

}

void UC_UI_Dialog::NativeTick(const FGeometry& MyGeometry, float DeltaTime)
{
	Super::NativeTick(MyGeometry, DeltaTime);

	if (iTextIndex == CurrentLine.Len()) return;
	iTextIndex++;

	TXT_DialogueLine->SetText(FText::FromString(CurrentLine.Left(iTextIndex)));

	FTimerHandle temp;
	//GetWorld()->GetTimerManager().SetTimer(temp, this, &UC_UI_Dialog::SetResponses, 1, false,)

	///Timer::SetTimer(FString("Test"), &UC_UI_Dialog::SetResponses);
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

void UC_UI_Dialog::SetResponses(const TArray<FDialog_Response> Responses)
{
	if (TArr_UI_ResponseLines.Num()) return;

	for (int32 i = 0; i < Responses.Num(); i++)
	{
		UC_UI_ResponseLine* line = CreateWidget<UC_UI_ResponseLine>(GetWorld(), UI_ResponseLine_Class);
		TArr_UI_ResponseLines.Add(line);
		ResponseBox->AddChildToVerticalBox(line);
		//line->SetButtonText(FText::FromString(Responses[i].ButtonText));
		//line->GetButton()->OnClicked.AddDynamic(this, &UC_UI_Responses::OnButtonClicked);
	}
}

void UC_UI_Dialog::ResetResponses()
{
	for (int32 i = 0; i < TArr_UI_ResponseLines.Num(); i++)
	{
		TArr_UI_ResponseLines[i]->Destruct();
	}
}

