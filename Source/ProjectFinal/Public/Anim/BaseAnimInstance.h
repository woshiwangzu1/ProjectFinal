// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "BaseAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTFINAL_API UBaseAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
protected:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
protected:
	UPROPERTY(BlueprintReadWrite)
	float Speed;
	UPROPERTY(BlueprintReadWrite)
	uint8 bSprint:1 ;
	UPROPERTY(BlueprintReadWrite)
	float Dir;
	UPROPERTY(BlueprintReadWrite)
	uint8 bHoldWeapon:1;
	UPROPERTY(BlueprintReadWrite)
	uint8 bIsFalling:1;
	UPROPERTY(BlueprintReadWrite)
	float AimPitch;
	UPROPERTY(BlueprintReadWrite)
	float AimYaw;
};
