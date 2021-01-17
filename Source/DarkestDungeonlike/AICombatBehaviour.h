// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CombatBehaviour.h"
#include "AICombatBehaviour.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class DARKESTDUNGEONLIKE_API UAICombatBehaviour : public UCombatBehaviour
{
	GENERATED_BODY()
public:
	void TakeAction();
private:
	void PickActionToUse();
};
