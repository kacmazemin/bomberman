// Copyright Epic Games, Inc. All Rights Reserved.

#include "BombermanGameModeBase.h"

#include "BaseCharacter.h"

ABombermanGameModeBase::ABombermanGameModeBase()
{
    DefaultPawnClass = ABaseCharacter::StaticClass();   
}
