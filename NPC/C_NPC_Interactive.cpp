// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC/C_NPC_Interactive.h"
#include "Player/C_Player.h"
#include "Global.h"

#include "Components/SphereComponent.h"



// Sets default values
AC_NPC_Interactive::AC_NPC_Interactive()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CHelpers::CreateComponent<USphereComponent>(this, &Sphere, "SphereCollision", GetMesh());
}

// Called when the game starts or when spawned
void AC_NPC_Interactive::BeginPlay()
{
	Super::BeginPlay();
	
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AC_NPC_Interactive::OnComponentBeginOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AC_NPC_Interactive::OnComponentEndOverlap);

	NewRotation = GetActorRotation();
}

// Called every frame
void AC_NPC_Interactive::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (bNewRotation)
	{
		SetActorRotation(FMath::RInterpTo(GetActorRotation(), NewRotation, DeltaTime, 10.f));

		if (GetActorRotation() == NewRotation) bNewRotation = false;
	}

}

// Called to bind functionality to input
void AC_NPC_Interactive::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AC_NPC_Interactive::RotateActor(const FRotator& _NewRotation)
{
	NewRotation = std::move(_NewRotation);

	bNewRotation = true;
}

void AC_NPC_Interactive::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AC_Player* player = Cast<AC_Player>(OtherActor);

	if (player == nullptr) return;

	player->RegisterInteractable(this);
}

void AC_NPC_Interactive::OnComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AC_Player* player = Cast<AC_Player>(OtherActor);

	if (player == nullptr) return;

	player->UnRegisterInteractable();
}

