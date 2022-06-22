// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PlayerCharacter.h"

APlayerCharacter::APlayerCharacter(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
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
	PlayerInputComponent->BindAction(TEXT("Sprint"),IE_Pressed,this,&APlayerCharacter::DoSprint);
	PlayerInputComponent->BindAction(TEXT("Sprint"),IE_Released,this,&APlayerCharacter::StopSprint);
}

void APlayerCharacter::MoveForward(float Value)
{
	FRotator Rot(0,GetControlRotation().Yaw,Value);
	AddMovementInput(Rot.Quaternion().GetAxisX(),Value);
	
}

void APlayerCharacter::MoveRight(float Value)
{
	FRotator Rot(0,GetControlRotation().Yaw,Value);
	AddMovementInput(Rot.Quaternion().GetAxisY(),Value);
}

void APlayerCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value*GetWorld()->GetDeltaSeconds()*60);
}

void APlayerCharacter::Turn(float Value)
{
	AddControllerYawInput(Value*GetWorld()->GetDeltaSeconds()*60);
}

void APlayerCharacter::DoSprint()
{
	bSprint = true;
}

void APlayerCharacter::StopSprint()
{
	bSprint = false;
}
