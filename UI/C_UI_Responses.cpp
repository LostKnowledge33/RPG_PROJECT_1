// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/C_UI_Responses.h"
#include "Global.h"
#include "UI/C_UI_ResponseLine.h"

#include "Components/VerticalBox.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"


UC_UI_Responses::UC_UI_Responses(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	
}

void UC_UI_Responses::NativeConstruct()
{
	Super::NativeConstruct();

}

void UC_UI_Responses::NativeTick(const FGeometry& MyGeometry, float DeltaTime)
{
	Super::NativeTick(MyGeometry, DeltaTime);

}

void UC_UI_Responses::SetResponses(TArray<FDialog_Response> Responses)
{
	for (int32 i = 0; i < Responses.Num(); i++)
	{
		UC_UI_ResponseLine* line = CreateWidget<UC_UI_ResponseLine>(GetWorld(), UI_ResponseLine_Class);
		TArr_UI_ResponseLines.Add(line);
		ResponseBox->AddChildToVerticalBox(line);
		line->SetButtonText(FText::FromString(Responses[i].ButtonText));
		line->GetButton()->OnClicked.AddDynamic(this, &UC_UI_Responses::OnButtonClicked);
	}
}

void UC_UI_Responses::OnButtonClicked()
{

}

void UC_UI_Responses::ResetWidget()
{
	for (UC_UI_ResponseLine* line : TArr_UI_ResponseLines)
	{
		ResponseBox->RemoveChild(line);
		line->RemoveFromParent();
	}
	
	TArr_UI_ResponseLines.Empty();
}

