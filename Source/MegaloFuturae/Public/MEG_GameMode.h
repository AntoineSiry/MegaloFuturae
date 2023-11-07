// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MEGCardData.h"
#include "MEG_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class MEGALOFUTURAE_API AMEG_GameMode : public AGameModeBase
{
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly)
	TArray<FMEGCardData> Cards;
};
