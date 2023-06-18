// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/Character.h"
#include "Components/TimeLineComponent.h"

#include "Player/C_Character_Base.h"
#include "NPC/C_NPC_Interactive.h"

#include "C_Player.generated.h"

UCLASS()
class RPG_PROJECT_1_API AC_Player : public AC_Character_Base
{
	GENERATED_BODY()

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;

	/// Enhanced Input ===================================
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		class UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		class UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		class UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		class UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		class UInputAction* InteractAction;

	/// Enhanced Input End ================================


	/// Interaction =======================================
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "_Interaction", meta = (AllowPrivateAccess = "true"))
		class AC_NPC_Interactive* CurrentInteractable;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "_Interaction", meta = (AllowPrivateAccess = "true"))
		bool bIsInteractable = false;

	/// Interaction End ====================================

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "_Timeline", Meta = (AllowPrivateAccess = "true"))
		UCurveFloat* CurveF_TalkCameraMove;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "_Timeline", meta = (AllowPrivateAccess = "true"))
		float LerpTimelineLength;

	FTimeline LerpTimeline;


	bool bCameraMove = false;

	FTransform tf_OldCameraTransform;

private:

	UFUNCTION()
		void TalkCameraMove(float curveData);

protected:

	virtual void BeginPlay() override;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	void Interact();

public:

	AC_Player();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	void RegisterInteractable(class AC_NPC_Interactive* Interactable);
	void UnRegisterInteractable();

private:

	UFUNCTION(BlueprintCallable, meta = (AllowPrivateAccess = "true"))
		void SetCurrentInteractable(class AC_NPC_Interactive* _CurrentInteractable) { CurrentInteractable = _CurrentInteractable; }

	UFUNCTION(BlueprintCallable, meta = (AllowPrivateAccess = "true"))
		void SetIsInteractable(bool _bIsInteractable) { bIsInteractable = _bIsInteractable; }

public:

	UFUNCTION(BlueprintImplementableEvent)
		void ShowTalkButton();

	UFUNCTION(BlueprintImplementableEvent)
		void HideTalkButton();

};
