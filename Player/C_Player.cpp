// Fill out your copyright notice in the Description page of Project Settings.


#include "C_Player.h"
#include "Global.h"

#include "RPG_PROJECT_1GameMode.h"
#include "System/C_SS_DialogSystem.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"


// Sets default values
AC_Player::AC_Player()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true; 
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);

	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
}

void AC_Player::TalkCameraMove(float curveData)
{
	PRINT(FString::FromInt(curveData));
	FVector NewLoc = FollowCamera->GetRelativeLocation().ForwardVector * curveData;
	FollowCamera->SetRelativeLocation(NewLoc);

}

// Called when the game starts or when spawned
void AC_Player::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

	FOnTimelineFloat Curve1Callback;
	Curve1Callback.BindUFunction(this, FName("TalkCameraMove"));
	LerpTimeline.AddInterpFloat(CurveF_TalkCameraMove, Curve1Callback);
	LerpTimeline.SetTimelineLength(LerpTimelineLength);
	
	//FOnTimelineEvent LerpTimelineFinishedCallback;
	//LerpTimelineFinishedCallback.BindUFunction(this, FName("함수이름4"));
	//LerpTimeline.SetTimelineFinishedFunc(LerpTimelineFinishedCallback);
}

// Called every frame
void AC_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	LerpTimeline.TickTimeline(DeltaTime);

	if (bCameraMove)
	{

	}

}

// Called to bind functionality to input
void AC_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) 
	{
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AC_Player::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AC_Player::Look);

		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this, &AC_Player::Interact);
	}
}

void AC_Player::RegisterInteractable(AC_NPC_Interactive* Interactable)
{
	UnRegisterInteractable();

	bIsInteractable = true;
	CurrentInteractable = Interactable;

	ShowTalkButton();
}

void AC_Player::UnRegisterInteractable()
{
	if (CurrentInteractable == nullptr) return;

	bIsInteractable = false;
	CurrentInteractable = nullptr;

	HideTalkButton();
}

void AC_Player::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AC_Player::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		float rate = 30;

		AddControllerYawInput(LookAxisVector.X * rate * GetWorld()->GetDeltaSeconds());
		AddControllerPitchInput(LookAxisVector.Y * rate * GetWorld()->GetDeltaSeconds());
	}
}

void AC_Player::Interact()
{
	if (CurrentInteractable == nullptr) return;

	FRotator dir = UKismetMathLibrary::FindLookAtRotation(CurrentInteractable->GetActorLocation(), GetActorLocation());
	
	CurrentInteractable->RotateActor(dir);
	//LerpTimeline.PlayFromStart();

	//tf_OldCameraTransform = FollowCamera->GetRelativeTransform();
	//bCameraMove = true;
	
	SUBSYSTEM(UC_SS_DialogSystem)->BeginDialog(CurrentInteractable->GetCommonDialog(), this);
	UnRegisterInteractable();
}
