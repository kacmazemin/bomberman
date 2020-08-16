// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

class UCameraComponent;
class UInputComponent;
class ABomb;

UCLASS()
class BOMBERMAN_API ABaseCharacter : public ACharacter {
    GENERATED_BODY()

public:
    ABaseCharacter();

    void Tick(float DeltaTime) override;
    void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

protected:
    void BeginPlay() override;

private:
    
    UPROPERTY()
    ABomb* bomb;    
    
    UPROPERTY(EditAnywhere, Category= "Camera")
    UCameraComponent* CameraComponent = nullptr;

    void MoveRight(float Value);
    void MoveForward(float Value);

    void PlantBomb();
};
