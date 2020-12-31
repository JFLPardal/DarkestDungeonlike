// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombatBehaviour.generated.h"

DECLARE_EVENT_OneParam(UCombatBehaviour, FCharacterActionTakenSignature, int32);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DARKESTDUNGEONLIKE_API UCombatBehaviour : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCombatBehaviour();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void TakeAction();
	bool IsCharacterDead() const;
	void TakeDamage(int DamageAmount);

	FCharacterActionTakenSignature ActionTaken;
private:
	void ChooseAction() const;
private:
	UPROPERTY(EditAnywhere, Category = "Stats") int32 InitialHP = 10;
	int32 CurrentHP = InitialHP;
	UPROPERTY(EditAnywhere, Category = "Stats") int32 Damage = 10;

	FTimerHandle TimerHandle;
};
