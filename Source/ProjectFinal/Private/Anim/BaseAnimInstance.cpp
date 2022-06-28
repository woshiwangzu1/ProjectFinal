// Fill out your copyright notice in the Description page of Project Settings.


#include "Anim/BaseAnimInstance.h"

#include "BaseCharacter.h"

void UBaseAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	
	FVector Dirction;
	
	GetOwningActor()->GetVelocity().ToDirectionAndLength(Dirction,Speed);
	
	if (ABaseCharacter* BaseCharacter = Cast<ABaseCharacter>(TryGetPawnOwner()))
	{
		bSprint = BaseCharacter->IsSprinting();
		bHoldWeapon = BaseCharacter->IsHoldWeapon();
		Dir = CalculateDirection(GetOwningActor()->GetVelocity(),BaseCharacter->GetActorForwardVector().Rotation());
		bIsFalling = BaseCharacter->GetMovementComponent()->IsFalling();
	}
	
	
}


