// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Object/ShooterCharacter.h"

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
	}
}

bool AShooterAIController::IsDead() const
{
	auto* ControlledCharacter = Cast<AShooterCharacter>(GetPawn());
	if (ControlledCharacter)
		return ControlledCharacter->IsDead();
	
	return true;
}

void AShooterAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
