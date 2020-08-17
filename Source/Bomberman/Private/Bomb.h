// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bomb.generated.h"


enum class ExplosionWay
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
};

UCLASS()
class ABomb : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABomb();

	void Init(const int bombPowerLevel = 1);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	UStaticMeshComponent* bombMesh;
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true), Category = "Mesh")
	class UInstancedStaticMeshComponent* cubeInstancedMeshComponent = nullptr;

private:

	bool isStartExplosion = false;
	int bombLevel = 1;

	FVector startLocation;
	FTransform startTransform;
	FTransform upTransform;
	FTransform downTransform;
	FTransform leftTransform;
	FTransform rightTransform;

	void GenerateSingleExplosion(ExplosionWay explosionWay);
};