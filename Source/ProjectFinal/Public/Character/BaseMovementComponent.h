// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/MovementComponent.h"
#include "BaseMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTFINAL_API UBaseMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
public:
	UBaseMovementComponent();
	virtual float GetMaxSpeed() const override;
protected:
	UPROPERTY(EditAnywhere,Category="MoveSpeed")
	float SprintSpeed;
	UPROPERTY(EditAnywhere,Category="MoveSpeed")
	float MoveSpeed;

	


	
};
