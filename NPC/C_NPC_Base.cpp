// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC/C_NPC_Base.h"
#include "Global.h"

AC_NPC_Base::AC_NPC_Base()
{
	//PrimaryActorTick.bCanEverTick = true;

}

void AC_NPC_Base::BeginPlay()
{
	Super::BeginPlay();

	//SetActorTickEnabled(true);
}

void AC_NPC_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
