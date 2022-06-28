// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

#include "Character/BaseMovementComponent.h"


ABaseCharacter::ABaseCharacter(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer.SetDefaultSubobjectClass<UBaseMovementComponent>(CharacterMovementComponentName))
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

bool ABaseCharacter::IsSprinting()
{
	if (!IsHoldWeapon())
	{
		return bSprint;
	}
	return bSprint && FVector::DotProduct(GetVelocity().GetSafeNormal2D(), GetActorForwardVector()) > 0.9;
}

void ABaseCharacter::SetLockPlayerView(bool Lock)
{
	UE_LOG(LogTemp, Log, TEXT("Lock===%d"),Lock);
	if (Lock)
	{
		if (UBaseMovementComponent* BaseMovementComponent = Cast<UBaseMovementComponent>(GetMovementComponent()))
		{
			BaseMovementComponent->bOrientRotationToMovement = false;
			bUseControllerRotationYaw = true;
		}
	}else
	{
		if (UBaseMovementComponent* BaseMovementComponent = Cast<UBaseMovementComponent>(GetMovementComponent()))
		{
			BaseMovementComponent->bOrientRotationToMovement = true;
			bUseControllerRotationYaw = false;
		}
	}
}
