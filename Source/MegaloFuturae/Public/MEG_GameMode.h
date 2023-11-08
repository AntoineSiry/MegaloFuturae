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

public:

	virtual void BeginPlay() override;


	/********** Card Containers *************/


	TArray<int32> DrawCardsId;
	TArray<int32> PlayedCardsId;
	TArray<int32> ScoringCardsId;

	UPROPERTY(EditDefaultsOnly)
	TArray<FMEGCardData> Cards;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> HUDWidgetClass;

	DECLARE_DELEGATE(FOnCardHandUpdated)
	FOnCardHandUpdated OnCardHandUpdatedDelegate;

protected:

	void DrawCard();

	/* Returns a card id from a card which is available. Returns INDEX_NONE if no card left*/
	int GetAvailableCardId() const;

};
