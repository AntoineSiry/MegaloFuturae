// Fill out your copyright notice in the Description page of Project Settings.


#include "MEGCardWidget.h"
#include "MEGCellWidget.h"
#include "MEGCardData.h"
#include "MEG_GameMode.h"
#include "Kismet/GameplayStatics.h"

void UMEGCardWidget::UpdateCard(int32 CardID)
{
	AMEG_GameMode* Gamemode = Cast<AMEG_GameMode>(UGameplayStatics::GetGameMode(this));
	if (!ensure(Gamemode != nullptr))
		return;

	for (TPair<EMEGCellPosition, UMEGCellWidget*> cellPair : CellWidgets)
	{
		FMEGCardData cardData = Gamemode->Cards[CardID];
		cellPair.Value->UpdateCell(cardData.Cells[cellPair.Key].DistrictType);
	}
}

void UMEGCardWidget::NativeConstruct()
{
	FillCellWidgets();
}

void UMEGCardWidget::FillCellWidgets()
{
	CellWidgets.Add({ EMEGCellPosition::UL, CellUL });
	CellWidgets.Add({ EMEGCellPosition::UR, CellUL });
	CellWidgets.Add({ EMEGCellPosition::DR, CellDR });
	CellWidgets.Add({ EMEGCellPosition::DL, CellDL });
}
