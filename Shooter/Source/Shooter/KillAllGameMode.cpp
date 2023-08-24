// Fill out your copyright notice in the Description page of Project Settings.


#include "KillAllGameMode.h"

void AKillAllGameMode::PawnKilled(APawn* Pawn)
{
	Super::PawnKilled(Pawn);

	auto* PlayerController = Cast<APlayerController>(Pawn->GetController());
	if (PlayerController)
	{
		PlayerController->GameHasEnded(nullptr, false);
	}
}
