// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DA_Dialog.generated.h"

/**
 * 
 */
UCLASS()
class RPG_PROJECT_1_API UDA_Dialog : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		FString NpcName;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		TArray<FString> Lines;

};
