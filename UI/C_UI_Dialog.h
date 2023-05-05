// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAsset/DA_Dialog.h"

#include "Blueprint/UserWidget.h"
#include "C_UI_Dialog.generated.h"

/**
 * 
 */
UCLASS()
class RPG_PROJECT_1_API UC_UI_Dialog : public UUserWidget
{
	GENERATED_BODY()

private:

	UDA_Dialog* Current_Dialog;

	FString CurrentLine;
	FText DisplayLine;

	int32 iTextIndex = -1;
	
	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true", BindWidget))
		class UTextBlock* TXT_DialogueLine;
	
	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true", BindWidget))
		class UTextBlock* TXT_Name;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true", BindWidget))
		class UButton* BTN_NextLine;

		
public:

	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float DeltaTime) override;

	void UpdateLine(FString line);
	void SetDialogName(FString name);

};
