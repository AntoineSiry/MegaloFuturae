// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MEGCardWidget.generated.h"


class UMEGCellWidget;
/**
 * 
 */
UCLASS()
class MEGALOFUTURAE_API UMEGCardWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	void UpdateCard(int32 CardID);

	virtual void NativeConstruct() override;

protected:

	void FillCellWidgets();

	TMap<enum class EMEGCellPosition, UMEGCellWidget*> CellWidgets;

	UPROPERTY(meta=(BindWidget))
	UMEGCellWidget* CellUL;

	UPROPERTY(meta=(BindWidget))
	UMEGCellWidget* CellUR;

	UPROPERTY(meta=(BindWidget))
	UMEGCellWidget* CellDR;

	UPROPERTY(meta=(BindWidget))
	UMEGCellWidget* CellDL;
};
