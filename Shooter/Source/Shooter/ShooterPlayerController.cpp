// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

void AShooterPlayerController::GameHasEnded(AActor* EndGameFocus, bool IsWinner)
{
	Super::GameHasEnded(EndGameFocus, IsWinner);

	if (IsWinner)
	{
		auto* WinWidget = CreateWidget(this, WinUIClass);
		if (WinWidget)
			WinWidget->AddToViewport();
	}
	else
	{
		auto* LoseWidget = CreateWidget(this, LoseUIClass);
		if (LoseWidget)
			LoseWidget->AddToViewport();
	}

	GetWorldTimerManager().SetTimer(RestartTimer
		, this
		, &APlayerController::RestartLevel
		, RestartTime);
}
