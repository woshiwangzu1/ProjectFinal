// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PlayerCharacter.h"

APlayerCharacter::APlayerCharacter()
{
	
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComponent->SetupAttachment(SpringArmComponent);
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->bUsePawnControlRotation = true;
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"),this,&APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"),this,&APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"),this,&APlayerCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("Turn"),this,&APlayerCharacter::Turn);
}

void APlayerCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(),Value);
	
}

void APlayerCharacter::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector(),Value);
}

void APlayerCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value*GetWorld()->GetDeltaSeconds()*60);
}

void APlayerCharacter::Turn(float Value)
{
	AddControllerYawInput(Value*GetWorld()->GetDeltaSeconds()*60);
}
