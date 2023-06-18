// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NPC/C_NPC_Base.h"

#include "C_NPC_Interactive.generated.h"

UCLASS()
class RPG_PROJECT_1_API AC_NPC_Interactive : public AC_NPC_Base
{
	GENERATED_BODY()

private:

	UPROPERTY(VisibleDefaultsOnly, Category = Interaction, meta = (AllowPrivateAccess = "true"))
		class USphereComponent* Sphere;

	FRotator NewRotation, OldRotation;

	bool bNewRotation = false;

public:
	// Sets default values for this character's properties
	AC_NPC_Interactive();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void RotateActor(const FRotator& _NewRotation);


	UFUNCTION()
		void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
		void OnComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
