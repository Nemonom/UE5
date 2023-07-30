// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Mover.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREAL01_API UMover : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMover();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
		FVector DestLocation = FVector(0, 0, 0);

	UPROPERTY(EditAnywhere)
		float MoveTime = 4.f;

	UPROPERTY(EditAnywhere)
		bool ShouldMove = false;

	UPROPERTY(EditAnywhere)
		FVector OriginalLocation = FVector(0, 0, 0);
};