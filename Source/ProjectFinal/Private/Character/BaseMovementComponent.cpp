// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BaseMovementComponent.h"

#include "BaseCharacter.h"

UBaseMovementComponent::UBaseMovementComponent()
{
	SprintSpeed =600;
	MoveSpeed = 420;
}

float UBaseMovementComponent::GetMaxSpeed() const
{
	if (ABaseCharacter* Character = Cast<ABaseCharacter>(GetCharacterOwner()))
	{
		if (Character->IsSprinting())
		{
			return SprintSpeed;
		}
	}
	
	
	return MoveSpeed;
}
