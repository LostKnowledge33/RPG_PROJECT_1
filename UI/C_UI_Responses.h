// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/C_UI_ResponseLine.h"
#include "DataAsset/DA_Dialog.h"

#include "C_UI_Responses.generated.h"

/**
 * 
 */
UCLASS()
class RPG_PROJECT_1_API UC_UI_Responses : public UUserWidget
{
	GENERATED_BODY()

private:

	TArray<struct FDialog_Response> Responses;
	
	TSubclassOf<UC_UI_ResponseLine> UI_ResponseLine_Class;
	TArray<UC_UI_ResponseLine*> UI_ResponseLine_Widgets;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true", BindWidget))
		class UVerticalBox* ResponseBox;
	
public:

	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float DeltaTime) override;
	

	FORCEINLINE void SetResponses(TArray<struct FDialog_Response> _Responses) { Responses = _Responses; }
};
