// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Skill.h"
#include "CombatBehaviour.generated.h"

DECLARE_EVENT_OneParam(UCombatBehaviour, FCharacterActionTakenSignature, int32);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DARKESTDUNGEONLIKE_API UCombatBehaviour : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCombatBehaviour();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
public:	
	virtual void TakeAction();
	bool IsCharacterDead() const;
	void TakeDamage(int DamageAmount);
public:
	FCharacterActionTakenSignature ActionTaken;

protected:
	virtual void BeginPlay() override;
protected:
	void ChooseAction() const;
protected:
	UPROPERTY(EditAnywhere, Category = "Stats") int32 Damage = 1;

public:
	UFUNCTION(BlueprintCallable) const TArray<FSkill>& GetCharacterSkills() const;
private:
	UPROPERTY(EditAnywhere, Category = "Stats") int32 InitialHP = 10;
	int32 CurrentHP = InitialHP;

	UPROPERTY(EditAnywhere, Category = "Skill") TArray<FSkill> Skills;

	FTimerHandle TimerHandle;
};
