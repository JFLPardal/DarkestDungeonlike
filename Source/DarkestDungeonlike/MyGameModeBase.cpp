// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"

#include "CombatBehaviour.h"

AMyGameModeBase::AMyGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
	if (CanEverTick())
	{
		UE_LOG(LogTemp, Warning, TEXT("GAME MODE INITIALIZED"));
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("GAME MODE INITIALIZED NOT TICKING"));
	

}


void AMyGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("GAME MODE BEGIN"));
	
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

}

void AMyGameModeBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	static bool IsCombatOver = false;
	if (!IsCombatOver)
	{
		auto EnemyCombat = Enemy->FindComponentByClass<UCombatBehaviour>();
		auto PlayerCombat = Player->FindComponentByClass<UCombatBehaviour>();
		check(EnemyCombat != nullptr && PlayerCombat != nullptr);
		if (IsPlayerTurn)
		{
			int characterAction = PlayerCombat->TakeAction();
			CalculateDamage(characterAction);
			IsCombatOver = EnemyCombat->IsCharacterDead();
		}
		else
		{
			int characterAction = EnemyCombat->TakeAction();
			CalculateDamage(characterAction);
			IsCombatOver = PlayerCombat->IsCharacterDead();
		}
		if (IsCombatOver)
		{
			UE_LOG(LogTemp, Warning, TEXT("COMBAT IS NOW OVER"));
		}
		else
		{
			IsPlayerTurn = !IsPlayerTurn;
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("COMBAT OVER"));
	}
}

void AMyGameModeBase::CalculateDamage(int Damage)
{
	if (IsPlayerTurn)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player attacking for %d damage"), Damage);
		Enemy->FindComponentByClass<UCombatBehaviour>()->TakeDamage(Damage);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Enemy attacking for %d damage"), Damage);
		Player->FindComponentByClass<UCombatBehaviour>()->TakeDamage(Damage);
	}
}