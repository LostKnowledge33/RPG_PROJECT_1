// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DataAsset/DA_Dialog.h"

#include "C_NPC_Base.generated.h"

/**
 * 
 */
UCLASS()
class RPG_PROJECT_1_API AC_NPC_Base : public ACharacter
{
	GENERATED_BODY()
	
private:

	UPROPERTY(EditDefaultsOnly, Category = NPC_Base, meta = (AllowPrivateAccess = "true"))
		int32 NID;

	UPROPERTY(EditDefaultsOnly, Category = NPC_Base, meta = (AllowPrivateAccess = "true"))
		UDA_Dialog* CommonDialog;
	
	FName NPC_Name;

public:

	AC_NPC_Base();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	inline UDA_Dialog* GetCommonDialog() { return CommonDialog; }


};
