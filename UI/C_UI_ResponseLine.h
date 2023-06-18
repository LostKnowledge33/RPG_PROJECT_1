// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "C_UI_ResponseLine.generated.h"

/**
 * 
 */
UCLASS()
class RPG_PROJECT_1_API UC_UI_ResponseLine : public UUserWidget
{
	GENERATED_BODY()

private:

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true", BindWidget))
		class UTextBlock* TXT_Response;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true", BindWidget))
		class UButton* BTN_Respond;

public:

	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float DeltaTime) override;

	void SetButtonText(FText text);
	
	inline class UButton* GetButton() { return BTN_Respond; }
};
