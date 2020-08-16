// Fill out your copyright notice in the Description page of Project Settings.


#include "Bomb.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABomb::ABomb()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bombMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BombMesh"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> BombMeshAsset(TEXT("/Game/3DModels/Bomb_SM"));

	if(BombMeshAsset.Succeeded())
	{
		bombMesh->SetStaticMesh(BombMeshAsset.Object);
	}
}

void ABomb::Init(const int bombPowerLevel)
{
	bombLevel = bombPowerLevel;

	UE_LOG(LogTemp, Display, TEXT("BOMB POWER LEVEL %d"), bombLevel);
}

// Called when the game starts or when spawned
void ABomb::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABomb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

