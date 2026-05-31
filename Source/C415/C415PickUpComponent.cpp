// Copyright Epic Games, Inc. All Rights Reserved.

#include "C415PickUpComponent.h"

UC415PickUpComponent::UC415PickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UC415PickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &UC415PickUpComponent::OnSphereBeginOverlap);
}

void UC415PickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	AC415Character* Character = Cast<AC415Character>(OtherActor);
	if(Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);
	}
}
