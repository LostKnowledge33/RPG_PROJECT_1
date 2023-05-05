// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DA_Dialog.generated.h"


USTRUCT(BlueprintType)
struct FDialog_Response
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
		FString ButtonText;

	UPROPERTY(EditAnywhere)
		UDA_Dialog* followDialog;

};

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

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		TArray<FDialog_Response> Responses;
};
