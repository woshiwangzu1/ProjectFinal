// Fill out your copyright notice in the Description page of Project Settings.


#include "Anim/BaseAnimInstance.h"

void UBaseAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	FVector Dir;
	
	GetOwningActor()->GetVelocity().ToDirectionAndLength(Dir,Speed);
}
