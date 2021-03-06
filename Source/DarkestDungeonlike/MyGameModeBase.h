// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Skill.h"
#include "MyGameModeBase.generated.h"

class UCombatBehaviour;

DECLARE_EVENT(AMyGameModeBase, FTurnWasTakenSignature);
/**
 * 
 */
UCLASS()
class DARKESTDUNGEONLIKE_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	AMyGameModeBase();
public:
	FTurnWasTakenSignature TurnWasTaken;
	UFUNCTION(BlueprintCallable) void PlayerAction(FString SkillToBeUsed);
protected:
	void BeginPlay() override;
	void Tick(float DeltaSeconds) override;

private:
	void ApplyDamage(int Damage);

	UFUNCTION() void CharacterTookAction(FSkill ChosenSkill);
	UFUNCTION(BlueprintCallable) UCombatBehaviour* GetPlayerCharacterCombat();
private:
	UPROPERTY(EditAnywhere, Category="Initialization") UClass* EnemyCharacter = nullptr;
	UPROPERTY(EditAnywhere, Category="Initialization") UClass* PlayerCharacter = nullptr;

	AActor* Player = nullptr;
	AActor* Enemy = nullptr;

	bool IsPlayerTurn = true;
	bool IsCombatOver = false;
};
