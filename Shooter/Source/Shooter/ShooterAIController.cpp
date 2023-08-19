// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

void AShooterAIController::BeginPlay()
{
	Super::BeginPlay();

	auto* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (nullptr == Player)
		return;

	if (AIBehavior)
	{
		RunBehaviorTree(AIBehavior);
		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
		GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), Player->GetActorLocation());
	}
}

void AShooterAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*auto* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (nullptr == Player)
		return;

	if (LineOfSightTo(Player))
	{
		SetFocus(Player);
		MoveToActor(Player, AccaptableRadius);
	}
	else
	{
		ClearFocus(EAIFocusPriority::Gameplay);
		StopMovement();
	}
	*/
}
