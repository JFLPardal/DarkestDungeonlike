// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCombatBehaviour.h"
#include "Kismet/GameplayStatics.h"
#include "MyGameModeBase.h"

UPlayerCombatBehaviour::UPlayerCombatBehaviour()
{
	Damage = 4;
}

void UPlayerCombatBehaviour::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (IsPlayerTurn)
	{
		UE_LOG(LogTemp, Warning, TEXT("player chose action"));
		ChooseAction();
	}
}

void UPlayerCombatBehaviour::BeginPlay()
{
	static_cast<AMyGameModeBase*>(UGameplayStatics::GetGameMode(GetWorld()))->TurnWasTaken.AddUObject<UPlayerCombatBehaviour>(this, &UPlayerCombatBehaviour::UpdateIsPlayerTurn);
}

void UPlayerCombatBehaviour::HasFirstAction(bool HasFirstMove)
{
	IsPlayerTurn = HasFirstMove;
}

void UPlayerCombatBehaviour::UpdateIsPlayerTurn()
{
	IsPlayerTurn = !IsPlayerTurn;
}

void UPlayerCombatBehaviour::TakeAction()
{
	UE_LOG(LogTemp, Warning, TEXT("is player turn"));
	ChooseAction();
}