// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_RenewPlayerLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"
#include "AIController.h"

UBTService_RenewPlayerLocation::UBTService_RenewPlayerLocation()
{
	NodeName = "Renew Player Location";
}

void UBTService_RenewPlayerLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	auto* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (nullptr == Player)
		return; 
	
	auto* AIOwner = OwnerComp.GetAIOwner();
	if (nullptr == AIOwner)
		return;

	if (AIOwner->LineOfSightTo(Player))
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), Player->GetActorLocation());
	}
	else
	{
		OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
	}
}
