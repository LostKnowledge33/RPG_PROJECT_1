// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/C_UI_Responses.h"
#include "Global.h"

#include "Components/VerticalBox.h"

void UC_UI_Responses::NativeConstruct()
{
	Super::NativeConstruct();

	CHelpers::GetClass<UC_UI_ResponseLine>(&UI_ResponseLine_Class, "/Script/UMGEditor.WidgetBlueprint'/Game/Blueprints/UI/Dialog/UI_ResponseLine.UI_ResponseLine_C'");

	for(int32 i = 0; i < Responses.Num(); i++)
	{
		UC_UI_ResponseLine* line = CreateWidget<UC_UI_ResponseLine>(GetWorld(), UI_ResponseLine_Class);
		ResponseBox->AddChildToVerticalBox(line);
		UI_ResponseLine_Widgets.Add(line);
		PRINT("Add");
	}
}

void UC_UI_Responses::NativeTick(const FGeometry& MyGeometry, float DeltaTime)
{
	Super::NativeTick(MyGeometry, DeltaTime);

}

