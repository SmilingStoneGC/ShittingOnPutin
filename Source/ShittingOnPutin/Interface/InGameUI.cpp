// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameUI.h"
#include "../Public/MainPlayer.h"
#include "../Public/MainGameInstance.h"
void UInGameUI::NativeConstruct()
{
	
	if (Cast<AMainPlayer>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn())) {
		SetScoreText(Cast<AMainPlayer>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn())->getScore());
		SetPoopAvilable(Cast<AMainPlayer>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn())->is_poop_empty());
		UpdatePercent(Cast<AMainPlayer>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn())->get_poop_count_percent());
		if (Cast<UMainGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()))) {
			FString b = FString::Printf(TEXT("%s: %1.0f"), *DefaultBestScoreText, Cast<UMainGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()))->ASaveObj->High_Score);
			BestScoreText->SetText(FText::FromString(b));
		}
	}
	else { SetScoreText(0); 
		UpdatePercent(1);
		if (Cast<UMainGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()))){
			FString b = FString::Printf(TEXT("%s: %1.0f"), *DefaultBestScoreText, Cast<UMainGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()))->ASaveObj->High_Score);
			BestScoreText->SetText(FText::FromString(b));
		}
		SetPoopAvilable(true);
	}
}

void UInGameUI::SetScoreText(float score)
{
	
	FString b = FString::Printf(TEXT("%s: %1.0f"), *DefaultScoreText, score);
	ScoreText->SetText(FText::FromString(b));
	
}

void UInGameUI::SetPoopAvilable(bool Aviable)
{
	PoopButton->SetIsEnabled(Aviable);
	if (Aviable)
	{
		PoopAviableImage->SetVisibility(ESlateVisibility::Visible);
		PoopUnaviableImage->SetVisibility(ESlateVisibility::Hidden);
		
	}
	else {
		PoopAviableImage->SetVisibility(ESlateVisibility::Hidden);
		PoopUnaviableImage->SetVisibility(ESlateVisibility::Visible);
	}
}

void UInGameUI::UpdatePercent(float Percent)
{
	UE_LOG(LogTemp, Display, TEXT("UpdatePercent %f"), Percent);
	PoopCountBar->SetPercent(Percent);
}
