// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTFINAL_API APlayerCharacter : public ABaseCharacter
{
	GENERATED_BODY()
public:
	APlayerCharacter();
protected:
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void LookUp(float Value);
	void Turn(float Value);

protected:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComponent;
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComponent;
};
