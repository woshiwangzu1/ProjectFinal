// Copyright Epic Games, Inc. All Rights Reserved.


#include "ProjectFinalGameModeBase.h"

#include "Character/PlayerCharacter.h"

AProjectFinalGameModeBase::AProjectFinalGameModeBase()
{
	// TSubclassOf<APlayerCharacter> PlayerPawnClass = LoadClass<APlayerCharacter>(this,TEXT("Blueprint'/Game/ProjectFinal/Character/Player/BP_PlayerCharacter.BP_PlayerCharacter_C'"));
	ConstructorHelpers::FClassFinder<APlayerCharacter> PlayerClass(TEXT("Blueprint'/Game/ProjectFinal/Character/Player/BP_PlayerCharacter.BP_PlayerCharacter_C'"));
	DefaultPawnClass = PlayerClass.Class;
}
