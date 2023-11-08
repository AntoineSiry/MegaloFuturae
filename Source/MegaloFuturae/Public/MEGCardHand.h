// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MEGCardWidget.h"
#include "MEGCardHand.generated.h"

/**
 * 
 */
UCLASS()
class MEGALOFUTURAE_API UMEGCardHand : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

protected:

	void UpdateHand();

	void FillCardWidgets();

	TArray<UMEGCardWidget*> CardWidgets;

	UPROPERTY(meta = (BindWidget))
	class UMEGCardWidget* FirstCard;

	UPROPERTY(meta = (BindWidget))
	class UMEGCardWidget* SecondCard;

	UPROPERTY(meta = (BindWidget))
	class UMEGCardWidget* ThirdCard;
	
};
