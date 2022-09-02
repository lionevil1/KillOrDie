// KillOrDie. All Rights Reserved.


#include "KRDGameModeBase.h"
#include "Player/KRDBaseCharacter.h"
#include "Player/KRDPlayerController.h"

AKRDGameModeBase::AKRDGameModeBase() 
{
    DefaultPawnClass = AKRDBaseCharacter::StaticClass();
    PlayerControllerClass = AKRDPlayerController::StaticClass();
}