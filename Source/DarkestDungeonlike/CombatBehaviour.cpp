// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatBehaviour.h"

// Sets default values for this component's properties
UCombatBehaviour::UCombatBehaviour()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	CurrentHP = InitialHP;
	// ...
}


// Called when the game starts
void UCombatBehaviour::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("current hp on begin play: %d "), CurrentHP);
	// ...
	
}


// Called every frame
void UCombatBehaviour::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

int UCombatBehaviour::TakeAction() const
{
	//UE_LOG(LogTemp, Warning, TEXT("%s: Attacking for %d damage"), *GetFName().ToString(), Damage);
	return Damage;
}

bool UCombatBehaviour::IsCharacterDead() const
{

	UE_LOG(LogTemp, Warning, TEXT("hp before damage: %d "), CurrentHP);
	return CurrentHP <= 0;
}

void UCombatBehaviour::TakeDamage(int DamageAmount)
{
	UE_LOG(LogTemp, Warning, TEXT("hp before taking damage: %d "), CurrentHP);
	CurrentHP -= DamageAmount;
}

