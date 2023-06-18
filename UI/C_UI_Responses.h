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

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true", BindWidget))
		class UVerticalBox* ResponseBox;

	TSubclassOf<UC_UI_ResponseLine> UI_ResponseLine_Class;

	UC_UI_ResponseLine* UI_ResponseLine_Widget;

	TArray<UC_UI_ResponseLine*> TArr_UI_ResponseLines;

public:

	UC_UI_Responses(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float DeltaTime) override;
	
	void SetResponses(TArray<FDialog_Response> Responses);
	void ResetWidget();


	UFUNCTION()
		void OnButtonClicked();

};
