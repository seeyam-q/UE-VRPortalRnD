// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IXRTrackingSystem.h"
#include "Engine/LevelStreaming.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UVastBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class PPORTAL_C_API UUVastBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintPure, Category="XR")
	static FVector GetCurrentXRCameraPosition()
	{
		if (GEngine->XRSystem)
		{
			return GEngine->XRSystem->GetBasePosition();
		}

		return FVector();
	}

	UFUNCTION(BlueprintPure, Category="XR")
static FRotator GetCurrentXRCameraRotation()
	{
		if (GEngine->XRSystem)
		{
			return GEngine->XRSystem->GetBaseRotation();
		}

		return FRotator();
	}

	UFUNCTION(BlueprintPure, Category = "Game")
static FName GetStreamingLevelNameFromActor(AActor* Actor)
	{
		if (Actor != nullptr)
		{
			return Actor->GetLevel()->GetOuter()->GetFName();
		}

		return NAME_None;
	}

	UFUNCTION(BlueprintCallable, Category = "Level Streaming")
	static void SetActorsLevelTransform(AActor* Actor, FTransform Transform)
	{
		if (Actor == nullptr)
		{
			return;
		}

		auto Level = Actor->GetLevel();
		Level->ApplyWorldOffset(Transform.GetLocation(), false);
		Actor->GetWorld()->UpdateLevelStreaming();
	}
};
