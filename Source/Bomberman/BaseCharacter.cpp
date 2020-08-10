// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseCharacter.h"
#include "Camera/CameraComponent.h"

ABaseCharacter::ABaseCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    AutoPossessPlayer = EAutoReceiveInput::Player0;

    bUseControllerRotationYaw = false;

    CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    CameraComponent->SetupAttachment(RootComponent);
    CameraComponent->SetRelativeLocation(FVector(0, 0, 200));
    CameraComponent->SetRelativeRotation(FRotator(-80, 0, 0));
}

void ABaseCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void ABaseCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    InputComponent->BindAxis("MoveForward", this, &ABaseCharacter::MoveForward);
    InputComponent->BindAxis("MoveRight", this, &ABaseCharacter::MoveRight);

    InputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &ABaseCharacter::Jump);
}

void ABaseCharacter::MoveRight(const float Value)
{
    if(Value) {
        AddMovementInput(GetActorRightVector(), Value);
    }
}

void ABaseCharacter::MoveForward(const float Value)
{
    if(Value) {
        AddMovementInput(GetActorForwardVector(), Value);
    }
}
