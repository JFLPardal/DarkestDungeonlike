// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Skill.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct DARKESTDUNGEONLIKE_API FSkill
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Damage = -1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FName Name = "";
};
