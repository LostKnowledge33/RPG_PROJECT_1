// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/C_UI_Dialog.h"
#include "UI/C_UI_Responses.h"

#include "GameFramework/Actor.h"
#include "C_DialogSystem.generated.h"



UCLASS()
class RPG_PROJECT_1_API AC_DialogSystem : public AActor
{
	GENERATED_BODY()

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UDA_Dialog* Dialog;


	// UI ===========================================
	TSubclassOf<UC_UI_Dialog> UI_Dialog_Class;
	UC_UI_Dialog* UI_Dialog_Widget;

	TSubclassOf<UC_UI_Responses> UI_Response_Class;
	UC_UI_Responses* UI_Response_Widget;
	// UI ===========================================


	int32 iLineIndex = -1;
	//int32 iTextIndex = 0;

public:	
	// Sets default values for this actor's properties
	AC_DialogSystem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void BeginDialog(class UDA_Dialog* _Dialog);
	void EndDialog();

	UFUNCTION()
		void NextLine();

};
