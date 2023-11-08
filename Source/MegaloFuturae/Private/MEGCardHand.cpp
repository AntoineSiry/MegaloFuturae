// Fill out your copyright notice in the Description page of Project Settings.


#include "MEGCardHand.h"
#include "MEG_GameMode.h"
#include "Kismet/GameplayStatics.h"

void UMEGCardHand::UpdateHand()
{
	AMEG_GameMode* Gamemode = Cast<AMEG_GameMode>(UGameplayStatics::GetGameMode(this));
	if (!ensure(Gamemode != nullptr))
		return;

	int32 NumCardsInHands = Gamemode->DrawCardsId.Num();

	for (int32 Index = 0; Index < NumCardsInHands; Index++)
	{
		if (Index >= NumCardsInHands) {
			CardWidgets[Index]->SetVisibility(ESlateVisibility::Collapsed);
			continue;
		}

		CardWidgets[Index]->UpdateCard(Gamemode->DrawCardsId[Index]);
	}

}

void UMEGCardHand::FillCardWidgets()
{
	CardWidgets.Add(FirstCard);
	CardWidgets.Add(SecondCard);
	CardWidgets.Add(ThirdCard);
}

void UMEGCardHand::NativeConstruct()
{
	FillCardWidgets();

	AMEG_GameMode* Gamemode = Cast<AMEG_GameMode>(UGameplayStatics::GetGameMode(this));
	if (!ensure(Gamemode != nullptr))
		return;

	Gamemode->OnCardHandUpdatedDelegate.BindUObject(this, &UMEGCardHand::UpdateHand);
}

void UMEGCardHand::NativeDestruct()
{
	AMEG_GameMode* Gamemode = Cast<AMEG_GameMode>(UGameplayStatics::GetGameMode(this));
	if (!ensure(Gamemode != nullptr))
		return;

	Gamemode->OnCardHandUpdatedDelegate.Unbind();
}
