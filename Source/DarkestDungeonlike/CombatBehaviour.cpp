// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatBehaviour.h"


// Sets default values for this component's properties
UCombatBehaviour::UCombatBehaviour()
{
	PrimaryComponentTick.bCanEverTick = true;
	CurrentHP = InitialHP;
}

// Called when the game starts
void UCombatBehaviour::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UCombatBehaviour::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UCombatBehaviour::ChooseAction(FSkill ChosenSkill) const
{
	ActionTaken.Broadcast(ChosenSkill);
}

bool UCombatBehaviour::IsCharacterDead() const
{
	return CurrentHP <= 0;
}

void UCombatBehaviour::TakeDamage(int DamageAmount)
{
	CurrentHP -= DamageAmount;
	UE_LOG(LogTemp, Warning, TEXT("hp after taking damage: %d "), CurrentHP);
}

const TArray<FSkill>& UCombatBehaviour::GetCharacterSkills() const
{
	return Skills;
}

