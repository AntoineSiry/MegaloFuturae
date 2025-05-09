// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MEGCellData.h"
#include "MEGCellWidget.generated.h"

/**
 * 
 */
UCLASS()
class MEGALOFUTURAE_API UMEGCellWidget : public UUserWidget
{
	GENERATED_BODY()
public:

	void UpdateCell(EMEGDistrict InDistrictType);

	EMEGDistrict DistrictType;

protected:

	UPROPERTY(meta=(BindWidget))
	class UImage* DistrictImage;
};
