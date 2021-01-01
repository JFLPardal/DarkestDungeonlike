// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CombatBehaviour.h"
#include "PlayerCombatBehaviour.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class DARKESTDUNGEONLIKE_API UPlayerCombatBehaviour : public UCombatBehaviour
{
	GENERATED_BODY()
public:
	UPlayerCombatBehaviour();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
public:
	void TakeAction() override;
	void HasFirstAction(bool HasFirstMove);

protected:
	virtual void BeginPlay() override;
	void UpdateIsPlayerTurn();

private:
	bool IsPlayerTurn = true;
};
