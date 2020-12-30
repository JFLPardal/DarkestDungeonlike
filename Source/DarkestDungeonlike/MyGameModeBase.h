// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class DARKESTDUNGEONLIKE_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	AMyGameModeBase();

protected:
	void BeginPlay() override;
	void Tick(float DeltaSeconds) override;
private:
	void CalculateDamage(int Damage);
private:
	UPROPERTY(EditAnywhere, Category="Initialization") UClass* CharacterToSpawn = nullptr;

	AActor* Player = nullptr;
	AActor* Enemy = nullptr;

	bool IsPlayerTurn = true;
};
