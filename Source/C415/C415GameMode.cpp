// Copyright Epic Games, Inc. All Rights Reserved.

#include "C415GameMode.h"
#include "C415Character.h"
#include "UObject/ConstructorHelpers.h"

AC415GameMode::AC415GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
