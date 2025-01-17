// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class SHOOTER_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();
	void			PullTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void	BeginPlay() override;

private:
	bool			Trace(FHitResult& HitResult, FVector& ShotDirection);
	AController*	GetOwnerController() const;

public:	
	// Called every frame
	virtual void	Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
		USceneComponent*		Root;

	UPROPERTY(VisibleAnywhere)
		USkeletalMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
		UParticleSystem*		MuzzleFlash;

	UPROPERTY(EditAnywhere)
		UParticleSystem*		ImpactEffect;

	UPROPERTY(EditAnywhere)
		USoundBase*				MuzzleSound;

	UPROPERTY(EditAnywhere)
		USoundBase*				ImpactSound;

	UPROPERTY(EditAnywhere)
		float					MaxRange = 1000.f;

	UPROPERTY(EditAnywhere)
		float					Damage = 10.f;
};
