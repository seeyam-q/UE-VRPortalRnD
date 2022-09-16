// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VRSceneCaptureComponent2D.h"
#include "GameFramework/Actor.h"
#include "Portal.generated.h"

UCLASS()
class PPORTAL_C_API APortal : public AActor
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bExecuteOnRenderThread;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* SceneCaptureRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* NearDoor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* AwayDoor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UVRSceneCaptureComponent2D* SceneCaptureLeftEye;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UVRSceneCaptureComponent2D* SceneCaptureRightEye;

public:	
	// Sets default values for this actor's properties
	APortal();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "VAST")
	void UpdateAndCaptureScene();
};
