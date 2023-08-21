// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_RenewPlayerLocation.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTER_API UBTService_RenewPlayerLocation : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTService_RenewPlayerLocation();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

};
