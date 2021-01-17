// Fill out your copyright notice in the Description page of Project Settings.


#include "AICombatBehaviour.h"

void UAICombatBehaviour::TakeAction()
{
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UAICombatBehaviour::PickActionToUse, 1.f, false);
}

 void UAICombatBehaviour::PickActionToUse()
{
	 FSkill SkillToUse;
	 SkillToUse.Damage = 1;
	 ChooseAction(SkillToUse);
}