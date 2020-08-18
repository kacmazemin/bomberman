// Fill out your copyright notice in the Description page of Project Settings.


#include "Bomb.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InstancedStaticMeshComponent.h"

// Sets default values
ABomb::ABomb()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	bombMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BombMesh"));
	cubeInstancedMeshComponent = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("InstanceStaticMesh"));

}

void ABomb::Init(const int bombPowerLevel)
{
	bombLevel = bombPowerLevel;

	//todo add bombLevel factor
	FTimerHandle TimerHandle;
	FTimerDelegate TimerDelegate;
	GetWorldTimerManager().SetTimer(TimerHandle, [this]()
    {
		bombMesh->SetHiddenInGame(true,false);
		
		cubeInstancedMeshComponent->AddInstance(startTransform);
		cubeInstancedMeshComponent->AddInstance(startTransform);
		cubeInstancedMeshComponent->AddInstance(startTransform);
		cubeInstancedMeshComponent->AddInstance(startTransform);

		isStartExplosion = true;
    }, 3.f, false);

}

// Called when the game starts or when spawned
void ABomb::BeginPlay()
{
	Super::BeginPlay();

	startTransform = GetActorTransform();
	startLocation = FVector(startTransform.GetLocation().X, startTransform.GetLocation().Y,50);
}

// Called every frame
void ABomb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if(isStartExplosion)
	{
		GenerateSingleExplosion(ExplosionWay::UP);
		GenerateSingleExplosion(ExplosionWay::DOWN);
		GenerateSingleExplosion(ExplosionWay::LEFT);
		GenerateSingleExplosion(ExplosionWay::RIGHT);
	}
	
}

void ABomb::GenerateSingleExplosion(ExplosionWay explosionWay)
{
	switch (explosionWay)
	{
		case ExplosionWay::UP:
			cubeInstancedMeshComponent->GetInstanceTransform(0, upTransform);
			upTransform.SetLocation(FVector(startLocation.X, upTransform.GetLocation().Y + speed  , startLocation.Z + 50));
		//todo add collisionCheck 
			if(upTransform.GetLocation().Y < startLocation.Y + ( 100 * bombLevel ) )
			{
				cubeInstancedMeshComponent->UpdateInstanceTransform(0, upTransform, false, true);
			}
			break;
		case ExplosionWay::DOWN:
			cubeInstancedMeshComponent->GetInstanceTransform(1, downTransform);
			downTransform.SetLocation(FVector(startLocation.X, downTransform.GetLocation().Y - speed , startLocation.Z + 50));
			if(downTransform.GetLocation().Y > startLocation.Y - (100 * bombLevel))
			{
				cubeInstancedMeshComponent->UpdateInstanceTransform(1, downTransform, false, true);
			}
			break;
		case ExplosionWay::LEFT:
			cubeInstancedMeshComponent->GetInstanceTransform(2, leftTransform);
			leftTransform.SetLocation(FVector(leftTransform.GetLocation().X - speed , startLocation.Y, startLocation.Z + 50));
			if(leftTransform.GetLocation().X > startLocation.X - (100 * bombLevel))
			{
				cubeInstancedMeshComponent->UpdateInstanceTransform(2, leftTransform, false, true);
			}
			break;
		case ExplosionWay::RIGHT:
			cubeInstancedMeshComponent->GetInstanceTransform(3, rightTransform);
			rightTransform.SetLocation(FVector(rightTransform.GetLocation().X + speed , startLocation.Y, startLocation.Z + 50));
			if(rightTransform.GetLocation().X < startLocation.X + (100 * bombLevel))
			{
				cubeInstancedMeshComponent->UpdateInstanceTransform(3, rightTransform, false, true);
			}
		default: 
			break;
	};
}
