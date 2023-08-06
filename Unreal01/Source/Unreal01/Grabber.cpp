// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	auto* PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (nullptr == PhysicsHandle)
		return;

	auto* GrabComponent = PhysicsHandle->GetGrabbedComponent();
	if (GrabComponent)
	{
		FVector TargetLocation = GetComponentLocation() + GetForwardVector() * HoldDistance;
		PhysicsHandle->SetTargetLocationAndRotation(TargetLocation, GetComponentRotation());
	}
}

void UGrabber::Grab()
{
	UPhysicsHandleComponent* PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	UE_LOG(LogTemp, Display, TEXT("name : %s"), *GetOwner()->GetName());

	if (nullptr == PhysicsHandle)
		return;

	FHitResult HitResult;
	bool isHit = GetGrabbableInReach(HitResult);

	if (isHit)
	{
		auto* HitComponent = HitResult.GetComponent();
		HitComponent->SetSimulatePhysics(true);
		HitComponent->WakeAllRigidBodies();

		auto* HitActor = HitResult.GetActor();
		HitActor->Tags.Add("Grabbed");
		HitActor->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);

		PhysicsHandle->GrabComponentAtLocationWithRotation(
			HitResult.GetComponent()
			, NAME_None
			, HitResult.ImpactPoint
			, GetComponentRotation()
		);
	}
}

void UGrabber::Release()
{
	UPhysicsHandleComponent* PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (nullptr == PhysicsHandle)
		return;

	auto* GrabComponent = PhysicsHandle->GetGrabbedComponent();
	if (GrabComponent)
	{
		auto* GrabbedActor = PhysicsHandle->GetGrabbedComponent()->GetOwner();
		GrabbedActor->Tags.Remove("Grabbed");

		GrabComponent->WakeAllRigidBodies();
		PhysicsHandle->ReleaseComponent();
	}
}

bool UGrabber::GetGrabbableInReach(FHitResult& OutHitResult) const
{
	FVector Start = GetComponentLocation();
	FVector End = Start + GetForwardVector() * MaxGrabDistance;

	FCollisionShape Sphere = FCollisionShape::MakeSphere(GrabRange);
	return GetWorld()->SweepSingleByChannel(
		OutHitResult
		, Start
		, End
		, FQuat::Identity
		, ECC_GameTraceChannel2
		, Sphere);
}

