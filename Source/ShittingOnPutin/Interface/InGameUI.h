// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "Components/ProgressBar.h"
#include "InGameUI.generated.h"

/**
 * 
 */
UCLASS()
class SHITTINGONPUTIN_API UInGameUI : public UUserWidget
{
	GENERATED_BODY()
		virtual void NativeConstruct()override;
	
	public:
	UFUNCTION(BlueprintCallable, Category = "My_UI_Funct")
		void SetScoreText(float score);
	UFUNCTION(BlueprintCallable, Category = "My_UI_Funct")
		void SetPoopAvilable(bool Aviable);
	UFUNCTION(BlueprintCallable, Category = "My_UI_Funct")
		void UpdatePercent(float Percent);
	UPROPERTY(BlueprintReadWrite,Category = "Settings")
		UButton *PoopButton;
	UPROPERTY(BlueprintReadWrite, Category = "Settings")
		UImage* PoopAviableImage;
	UPROPERTY(BlueprintReadWrite, Category = "Settings")
		UProgressBar* PoopCountBar;
	UPROPERTY(BlueprintReadWrite, Category = "Settings")
		UImage* PoopUnaviableImage;
	UPROPERTY(EditDefaultsOnly, Category = "Settings")
		FString DefaultScoreText;
	UPROPERTY(EditDefaultsOnly, Category = "Settings")
		FString DefaultBestScoreText;
	UPROPERTY(BlueprintReadWrite, Category = "Settings")
		UTextBlock* BestScoreText;
	UPROPERTY(BlueprintReadWrite, Category = "Settings")
		UTextBlock* ScoreText;
};
