// Fill out your copyright notice in the Description page of Project Settings.


#include "Anim/BaseAnimInstance.h"

#include "BaseCharacter.h"
#include "Kismet/KismetMathLibrary.h"

void UBaseAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	
	FVector Dirction;
	
	GetOwningActor()->GetVelocity().ToDirectionAndLength(Dirction,Speed);
	
	if (ABaseCharacter* BaseCharacter = Cast<ABaseCharacter>(TryGetPawnOwner()))
	{
		bSprint = BaseCharacter->IsSprinting();
		bHoldWeapon = BaseCharacter->IsHoldWeapon();
		if (Speed>0)
		{
			Dir = CalculateDirection(GetOwningActor()->GetVelocity(),BaseCharacter->GetActorForwardVector().Rotation());
		}
		
		bIsFalling = BaseCharacter->GetMovementComponent()->IsFalling();

		FRotator OffsetRotator = UKismetMathLibrary::NormalizedDeltaRotator(BaseCharacter->GetControlRotation(),BaseCharacter->GetActorRotation());
		AimYaw = OffsetRotator.Yaw;
		AimPitch = OffsetRotator.Pitch;
	}
	
	
}


