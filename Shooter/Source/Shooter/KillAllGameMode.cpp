// Fill out your copyright notice in the Description page of Project Settings.


#include "KillAllGameMode.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "ShooterAIController.h"

void AKillAllGameMode::PawnKilled(APawn* Pawn)
{
	Super::PawnKilled(Pawn);

	auto* PlayerController = Cast<APlayerController>(Pawn->GetController());
	if (PlayerController)
	{
		EndGame(false);
	}

	for (auto* Controller : TActorRange<AShooterAIController>(GetWorld()))
	{
		if (false == Controller->IsDead())
			return;
	}

	EndGame(true);
}

void AKillAllGameMode::EndGame(bool IsPlayerWinner)
{
	for (auto* Controller : TActorRange<AController>(GetWorld()))
	{
		bool IsWinner = Controller->IsPlayerController() == IsPlayerWinner;
		Controller->GameHasEnded(Controller->GetPawn(), IsWinner);
	}
}
