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
	bombMesh->SetWorldLocation(FVector(GetActorLocation().X, GetActorLocation().Y,-50));
	cubeInstancedMeshComponent = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("InstanceStaticMesh"));
	cubeInstancedMeshComponent->SetHiddenInGame(true,false);
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
		cubeInstancedMeshComponent->SetHiddenInGame(false);
		GenerateSingleExplosion(ExplosionWay::MIDDLE);
        GenerateSingleExplosion(ExplosionWay::UP);
        GenerateSingleExplosion(ExplosionWay::DOWN);
        GenerateSingleExplosion(ExplosionWay::RIGHT);
        GenerateSingleExplosion(ExplosionWay::LEFT);
    }, 3.f, false);


	//UE_LOG(LogTemp, Display, TEXT("BOMB POWER LEVEL %d"), bombLevel);
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

void ABomb::GenerateSingleExplosion(ExplosionWay explosionWay)
{
	FTransform transform;

	cubeInstancedMeshComponent->GetInstanceTransform(0, transform, false);
	auto meshDistance = transform.GetScale3D().X * cubeInstancedMeshComponent->GetStaticMesh()->GetBounds().GetBox().GetSize().X;
	float X = transform.GetLocation().X;
	float Y = transform.GetLocation().Y;
	
	switch (explosionWay)
	{
		case ExplosionWay::UP:
			transform.SetLocation(FVector(X,  Y + meshDistance,meshDistance * .5));
			cubeInstancedMeshComponent->AddInstance(transform);
			break;
		case ExplosionWay::DOWN:
			transform.SetLocation(FVector(X, Y - meshDistance,meshDistance * .5));
			cubeInstancedMeshComponent->AddInstance(transform);
			break;
		case ExplosionWay::LEFT:
			transform.SetLocation(FVector(X - meshDistance, Y,meshDistance * .5));
			cubeInstancedMeshComponent->AddInstance(transform);
			break;
		case ExplosionWay::RIGHT:
			transform.SetLocation(FVector(X + meshDistance, Y,meshDistance * .5));
			cubeInstancedMeshComponent->AddInstance(transform);
			break;
		case ExplosionWay::MIDDLE:
		default:
			transform.SetLocation(FVector(GetActorLocation().X, GetActorLocation().Y,meshDistance * .5));
			cubeInstancedMeshComponent->AddInstance(transform);
			break;
	}
	
	
}
