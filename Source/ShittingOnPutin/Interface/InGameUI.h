// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"

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
	UPROPERTY(BlueprintReadWrite ,Category = "Settings")
		UButton *PoopButton;
	UPROPERTY(EditDefaultsOnly, Category = "Settings")
		FString DefaultScoreText;
	UPROPERTY(BlueprintReadWrite, Category = "Settings")
		UTextBlock* ScoreText;
};
