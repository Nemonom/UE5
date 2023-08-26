// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShooterPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTER_API AShooterPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void	GameHasEnded(class AActor* EndGameFocus = nullptr, bool IsWinner = false) override;

private:
	UPROPERTY(EditAnywhere)
		TSubclassOf<class UUserWidget>	LoseUIClass;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class UUserWidget>	WinUIClass;

	UPROPERTY(EditAnywhere)
		float							RestartTime = 5.f;

	FTimerHandle						RestartTimer;
};
