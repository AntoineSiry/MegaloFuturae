// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM()
enum class EMEGDistrict
{
	Parc,
	Commercial,
	Industrie,
	Dwellings
};

/**
 * 
 */
class MEGALOFUTURAE_API FMEG_CellData
{
public:

	EMEGDistrict DistrictType;

};
