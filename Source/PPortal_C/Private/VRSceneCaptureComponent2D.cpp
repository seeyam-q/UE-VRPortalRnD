// Fill out your copyright notice in the Description page of Project Settings.


#include "VRSceneCaptureComponent2D.h"

//FMatrix UVRSceneCaptureComponent2D::GetLeftEyeMatrix()
//{
//	if (GEngine->StereoRenderingDevice->IsStereoEnabled())
//	{
//		return GEngine->StereoRenderingDevice->GetStereoProjectionMatrix(EStereoscopicPass::eSSP_LEFT_EYE);
//	}
//	return FMatrix::Identity;
//}
//
//FMatrix UVRSceneCaptureComponent2D::GetRightEyeMatrix()
//{
//	if (GEngine->StereoRenderingDevice->IsStereoEnabled())
//	{
//		return GEngine->StereoRenderingDevice->GetStereoProjectionMatrix(EStereoscopicPass::eSSP_RIGHT_EYE);
//	}
//	return FMatrix::Identity;
//}
//
//FMatrix UVRSceneCaptureComponent2D::GetLeftEyeSideMatrix()
//{
//	if (GEngine->StereoRenderingDevice->IsStereoEnabled())
//	{
//		return GEngine->StereoRenderingDevice->GetStereoProjectionMatrix(EStereoscopicPass::eSSP_LEFT_EYE_SIDE);
//	}
//	return FMatrix::Identity;
//}
//
//FMatrix UVRSceneCaptureComponent2D::GetRightEyeSideMatrix()
//{
//	if (GEngine->StereoRenderingDevice->IsStereoEnabled())
//	{
//		return GEngine->StereoRenderingDevice->GetStereoProjectionMatrix(EStereoscopicPass::eSSP_RIGHT_EYE_SIDE);
//	}
//	return FMatrix::Identity;
//}