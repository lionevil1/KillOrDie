// KillOrDie. All Rights Reserved.

#include "Player/KRDBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AKRDBaseCharacter::AKRDBaseCharacter()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
    SpringArmComponent->SetupAttachment(GetRootComponent());
    SpringArmComponent->bUsePawnControlRotation = true;

    CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
    CameraComponent->SetupAttachment(SpringArmComponent);
}

// Called when the game starts or when spawned
void AKRDBaseCharacter::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AKRDBaseCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AKRDBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &AKRDBaseCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &AKRDBaseCharacter::MoveRight);
    PlayerInputComponent->BindAxis("LookUp", this, &AKRDBaseCharacter::LookUp);
    PlayerInputComponent->BindAxis("TurnAround", this, &AKRDBaseCharacter::TurnAround);
}

void AKRDBaseCharacter::MoveForward(float Amount)
{
    AddMovementInput(GetActorForwardVector(), Amount);
}

void AKRDBaseCharacter::MoveRight(float Amount)
{
    AddMovementInput(GetActorRightVector(), Amount);
}

void AKRDBaseCharacter::LookUp(float Amount)
{
    AddControllerPitchInput(Amount);
}

void AKRDBaseCharacter::TurnAround(float Amount)
{
    AddControllerYawInput(Amount);
}
