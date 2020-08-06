// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "Camera/CameraComponent.h"


// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	bUseControllerRotationYaw = false;

	cameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	cameraComponent->AttachTo(RootComponent);
	cameraComponent->SetRelativeLocation(FVector(0,0,200));
	cameraComponent->SetRelativeRotation(FRotator(-80,0,0));
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveForward", this, &ABaseCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ABaseCharacter::MoveRight);

	InputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &ABaseCharacter::Jump);
	
}

void ABaseCharacter::MoveRight(const float value)
{
	if(value)
	{
		AddMovementInput(GetActorRightVector(), value);
	}
}

void ABaseCharacter::MoveForward(const float value)
{
	if(value)
	{
		AddMovementInput(GetActorForwardVector(), value);
	}
}

void ABaseCharacter::jumpAction()
{
	Jump();
}

