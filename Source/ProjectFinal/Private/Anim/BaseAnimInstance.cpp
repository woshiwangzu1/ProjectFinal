// Fill out your copyright notice in the Description page of Project Settings.


#include "Anim/BaseAnimInstance.h"

#include "BaseCharacter.h"

void UBaseAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	FVector Dir;
	
	GetOwningActor()->GetVelocity().ToDirectionAndLength(Dir,Speed);
	if (ABaseCharacter* BaseCharacter = Cast<ABaseCharacter>(TryGetPawnOwner()))
	{
		bSprint = BaseCharacter->IsSprinting();
	}
	
}
