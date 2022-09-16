// Fill out your copyright notice in the Description page of Project Settings.

#include "Portal.h"

#include "IXRTrackingSystem.h"
#include "XRThreadUtils.h"

// Sets default values
APortal::APortal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APortal::BeginPlay()
{
	Super::BeginPlay();

	if (bExecuteOnRenderThread)
	{
		ExecuteOnRenderThread_DoNotWait([this]()
		{
			UpdateAndCaptureScene();
		});
	}
}

// Called every frame
void APortal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APortal::UpdateAndCaptureScene()
{
	if(!IsInGameThread() && !bExecuteOnRenderThread)
	{
		return;
	}
	
	FQuat HmdQuaternion;
	FRotator HmdRotation = FRotator::ZeroRotator;
	FVector HmdPosition = FVector::ZeroVector;

	IXRTrackingSystem* TrackingSys = GEngine->XRSystem.Get();
	if (TrackingSys)
	{
		TrackingSys->GetCurrentPose(TrackingSys->HMDDeviceId,HmdQuaternion, HmdPosition);
		HmdRotation = FRotator(HmdQuaternion);
		HmdPosition = TrackingSys->GetTrackingToWorldTransform().TransformPosition(HmdPosition);

		const FVector sceneCapturePosition = HmdPosition - NearDoor->GetComponentLocation() + AwayDoor->GetComponentLocation();
		const FRotator sceneCaptureRotation = HmdRotation;
		SceneCaptureRoot->SetWorldLocationAndRotation(sceneCapturePosition, sceneCaptureRotation);
		// This part cannot be called on render thread :(
		// UWorld* World = GetWorld();
		// if (World && World->Scene)
		// {
		// 	SceneCaptureLeftEye->UpdateSceneCaptureContents(World->Scene);
		// 	SceneCaptureRightEye->UpdateSceneCaptureContents(World->Scene);
		// }	
	}
}


