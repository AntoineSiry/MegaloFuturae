// Fill out your copyright notice in the Description page of Project Settings.


#include "MEG_GameMode.h"
#include "Blueprint/UserWidget.h"

#define MAX_CARDS_IN_HANDS 3

void AMEG_GameMode::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* HUDWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);

	if (!ensure(HUDWidget != nullptr))
		return;

	HUDWidget->AddToViewport();

	for (int32 Index = 0; Index < MAX_CARDS_IN_HANDS; Index++) {
		DrawCard();
	}

}

void AMEG_GameMode::DrawCard()
{
	const int32 DrawnCardId = GetAvailableCardId();

	if (DrawnCardId != INDEX_NONE)
		DrawCardsId.Add(DrawnCardId);

	OnCardHandUpdatedDelegate.ExecuteIfBound();
}

int AMEG_GameMode::GetAvailableCardId() const
{

	const TArray<FMEGCardData> AvailableCards = Cards.FilterByPredicate([this](const FMEGCardData& InCardData) {
		return !(DrawCardsId.Contains(InCardData.CardID)
			|| PlayedCardsId.Contains(InCardData.CardID)
			|| ScoringCardsId.Contains(InCardData.CardID));
		});

	if (AvailableCards.Num() == 0)
		return INDEX_NONE;

		const int32 CardIndex = rand() % AvailableCards.Num();
		return AvailableCards[CardIndex].CardID;	

}
