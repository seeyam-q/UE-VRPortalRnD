// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneCaptureComponent2D.h"
#include <HeadMountedDisplayFunctionLibrary.h>

#include "IXRTrackingSystem.h"
#include "OculusFunctionLibrary.h"
#include "VRSceneCaptureComponent2D.generated.h"






/**
 * 
 */
UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class PPORTAL_C_API UVRSceneCaptureComponent2D : public USceneCaptureComponent2D
{
	GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Capture")
        bool bIsLeftEye;
    virtual void UpdateSceneCaptureContents(FSceneInterface* Scene) override
    {
    	if (GEngine->XRSystem)
    	{
    		FVector cameraPos = GEngine->XRSystem->GetBasePosition();
    		FRotator cameraRot = GEngine->XRSystem->GetBaseRotation();
    		// UE_LOG(LogTemp, Log, TEXT("CameraPos: [%s] CameraRot: [%s]"), *cameraPos.ToString(), *cameraRot.ToString());
    		//UE_LOG(LogTemp, Log, TEXT("Support late update %s"), ( GEngine->XRSystem->DoesSupportLateUpdate() ? TEXT("true") : TEXT("false")));
    		// SetWorldLocation(GEngine->XRSystem->GetBasePosition());
    		// SetWorldRotation(GEngine->XRSystem->GetBaseRotation());
    	}
    	
        // Apply eye matrix
        EStereoscopicPass StereoPass = bIsLeftEye ? EStereoscopicPass::eSSP_LEFT_EYE : eSSP_RIGHT_EYE;
    	
        if (GEngine->StereoRenderingDevice.IsValid() && GEngine->IsStereoscopic3D() && GEngine->StereoRenderingDevice->IsStereoEnabled())
        {
            this->bUseCustomProjectionMatrix = true;
            this->CustomProjectionMatrix = GEngine->StereoRenderingDevice->GetStereoProjectionMatrix(StereoPass);
            this->CaptureStereoPass = StereoPass;
        }

        // Apply eye offset

        // Apply late update

        // This pulls from the GetComponentToWorld so setting just prior to it should have worked    
        Super::UpdateSceneCaptureContents(Scene);
    }

};
