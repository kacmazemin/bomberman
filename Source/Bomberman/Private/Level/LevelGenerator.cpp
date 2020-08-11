// Fill out your copyright notice in the Description page of Project Settings.

#include "LevelGenerator.h"

bool ULevelGenerator::GenerateMap(const UObject* WorldContextObject,
                                  const TSubclassOf<AActor> BlockActorClass,
                                  const TSubclassOf<AActor> WalkableActorClass)
{
    auto* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull);
    if(!World) { return false; }

    for(auto y = -5; y <= 5; ++y) {
        for(auto x = -5; x <= 5; ++x) {
            FVector Location{x * 100.f, y * 100.f, 0.f};
            auto* Walkable = World->SpawnActor(WalkableActorClass.Get());
            Walkable->SetActorLocation(Location);

            if(FMath::FRand() < .2f) {
                auto* Blocking = World->SpawnActor(BlockActorClass.Get());
                Blocking->SetActorLocation(Location);
            }
        }
    }
    
    return true;
}
