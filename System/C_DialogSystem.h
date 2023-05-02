// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C_DialogSystem.generated.h"



UCLASS()
class RPG_PROJECT_1_API AC_DialogSystem : public AActor
{
	GENERATED_BODY()

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UDA_Dialog* Dialog;


	TSubclassOf<UUserWidget> UI_Dialog_Class;

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

};
