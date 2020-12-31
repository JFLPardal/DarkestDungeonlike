// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"

#include "CombatBehaviour.h"

AMyGameModeBase::AMyGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
}


void AMyGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
	// spawn player
	FTransform playerSpawnLocation;
	playerSpawnLocation.SetLocation(FVector(240, -160, 90));
	FActorSpawnParameters playerSpawnParams;
	playerSpawnParams.Name = "Player";
	Player = GetWorld()->SpawnActor(CharacterToSpawn, &playerSpawnLocation, playerSpawnParams);
	
	//spawn enemy
	FTransform enemySpawnLocation;
	enemySpawnLocation.SetLocation(FVector(240, 160, 90));
	FActorSpawnParameters enemySpawnParams;
	enemySpawnParams.Name = "Enemy";
	Enemy = GetWorld()->SpawnActor(CharacterToSpawn, &enemySpawnLocation, enemySpawnParams);

	// subscribe to enemy and player take action events with a function that calculates Damage and checks if combat should be over
	Enemy->FindComponentByClass<UCombatBehaviour>()->ActionTaken.AddUObject<AMyGameModeBase>(this, &AMyGameModeBase::CharacterTookAction);
	Player->FindComponentByClass<UCombatBehaviour>()->ActionTaken.AddUObject<AMyGameModeBase>(this, &AMyGameModeBase::CharacterTookAction);
	
	// get the turns started
	Player->FindComponentByClass<UCombatBehaviour>()->TakeAction();
}

void AMyGameModeBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (IsCombatOver)
	{
		UE_LOG(LogTemp, Warning, TEXT("COMBAT OVER"));
	}
}

void AMyGameModeBase::ApplyDamage(int Damage)
{
	if (IsPlayerTurn)
	{
		Enemy->FindComponentByClass<UCombatBehaviour>()->TakeDamage(Damage);
	}
	else
	{
		Player->FindComponentByClass<UCombatBehaviour>()->TakeDamage(Damage);
	}
}

void AMyGameModeBase::CharacterTookAction(int32 Damage)
{
	auto EnemyCombat = Enemy->FindComponentByClass<UCombatBehaviour>();
	auto PlayerCombat = Player->FindComponentByClass<UCombatBehaviour>();
	check(EnemyCombat != nullptr && PlayerCombat != nullptr);
	
	ApplyDamage(Damage);

	if (IsPlayerTurn)
	{
		IsCombatOver = EnemyCombat->IsCharacterDead();
	}
	else
	{
		IsCombatOver = PlayerCombat->IsCharacterDead();
	}

	if (IsCombatOver)
	{
		UE_LOG(LogTemp, Warning, TEXT("COMBAT IS NOW OVER"));
	}
	else
	{
		IsPlayerTurn = !IsPlayerTurn;
		if (IsPlayerTurn)
		{
			PlayerCombat->TakeAction();
		}
		else
		{
			EnemyCombat->TakeAction();
		}
	}
}