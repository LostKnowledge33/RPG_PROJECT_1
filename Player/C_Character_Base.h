// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "C_Character_Base.generated.h"

UCLASS()
class RPG_PROJECT_1_API AC_Character_Base : public ACharacter
{
	GENERATED_BODY()

public:

	AC_Character_Base();

protected:

	virtual void BeginPlay() override;

};
