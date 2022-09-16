// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IXRTrackingSystem.h"
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
};
