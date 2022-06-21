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
};
