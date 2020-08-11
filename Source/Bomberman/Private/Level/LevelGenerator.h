// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LevelGenerator.generated.h"

UCLASS()
class ULevelGenerator : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category="Map Generator", meta=(WorldContext="WorldContextObject"))
	static bool GenerateMap(const UObject* WorldContextObject,
				TSubclassOf<AActor> BlockActorClass,
	            TSubclassOf<AActor> WalkableActorClass);
};
