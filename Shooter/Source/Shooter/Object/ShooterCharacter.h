// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

UCLASS()
class SHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void	BeginPlay() override;

public:	
	// Called every frame
	virtual void	Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void	SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual float	TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser);

	UFUNCTION(BlueprintPure)
		bool		IsDead() const;

	void			Shoot();

private:
	void			MoveForward(float AxisValue);
	void			MoveRight(float AxisValue);
	void			LookUp(float AxisValue);
	void			LookRight(float AxisValue);
	void			LookUpRate(float AxisValue);
	void			LookRightRate(float AxisValue);

private:
	UPROPERTY(EditAnywhere)
		float		RotationRate = 10.f;
	UPROPERTY(EditDefaultsOnly)
		float		MaxHp = 100.f;
	UPROPERTY(EditAnywhere)
		float		Hp;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class AGun> GunClass;

	UPROPERTY()
		class AGun* Gun;
};
