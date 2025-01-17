// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREAL01_API UGrabber : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
		void Grab();

	UFUNCTION(BlueprintCallable)
		void Release();

private:
	bool GetGrabbableInReach(FHitResult& OutHitResult) const;

private:
	UPROPERTY(EditAnywhere)
		float MaxGrabDistance = 400.f;

	UPROPERTY(EditAnywhere)
		float GrabRange = 100.f;

	UPROPERTY(EditAnywhere)
		float HoldDistance = 200.f;
};
