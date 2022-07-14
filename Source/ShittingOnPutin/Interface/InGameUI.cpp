// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameUI.h"
#include "../Public/MainPlayer.h"
void UInGameUI::NativeConstruct()
{
	
	if (Cast<AMainPlayer>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn()))
		SetScoreText(Cast<AMainPlayer>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn())->getScore());
	else SetScoreText(0);
}

void UInGameUI::SetScoreText(float score)
{
	
	FString b = FString::Printf(TEXT("%s: %1.0f"), *DefaultScoreText, score);
	ScoreText->SetText(FText::FromString(b));
	
}
