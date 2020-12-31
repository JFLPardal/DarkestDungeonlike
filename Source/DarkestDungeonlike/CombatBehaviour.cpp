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

void UCombatBehaviour::TakeAction()
{
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UCombatBehaviour::ChooseAction, 1.f, false);
}

void UCombatBehaviour::ChooseAction() const
{
	ActionTaken.Broadcast(Damage);
}

bool UCombatBehaviour::IsCharacterDead() const
{
	return CurrentHP <= 0;
}

void UCombatBehaviour::TakeDamage(int DamageAmount)
{
	UE_LOG(LogTemp, Warning, TEXT("hp before taking damage: %d "), CurrentHP);
	CurrentHP -= DamageAmount;
}

