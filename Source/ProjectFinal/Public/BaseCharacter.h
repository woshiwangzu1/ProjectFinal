// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Character/BaseMovementComponent.h>

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS()
class PROJECTFINAL_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter(const FObjectInitializer& ObjectInitializer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	bool IsSprinting();
	bool IsHoldWeapon(){return bHoldWeapon;};
	
protected:
	void SetLockPlayerView(bool Lock);
protected:
	UPROPERTY(BlueprintReadWrite)
	uint8 bSprint:1;
	UPROPERTY(BlueprintReadWrite)
	uint8 bHoldWeapon:1;
	UAnimMontage* FireMontage;
};
