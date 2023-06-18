// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/C_UI_ResponseLine.h"

#include "Components/TextBlock.h"

void UC_UI_ResponseLine::NativeConstruct()
{
	Super::NativeConstruct();

}

void UC_UI_ResponseLine::NativeTick(const FGeometry& MyGeometry, float DeltaTime)
{
	Super::NativeTick(MyGeometry, DeltaTime);

}

void UC_UI_ResponseLine::SetButtonText(FText text)
{
	TXT_Response->SetText(text);
}
