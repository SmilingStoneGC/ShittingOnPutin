// Fill out your copyright notice in the Description page of Project Settings.


#include "MainLevelHud.h"
#include "Kismet/GameplayStatics.h"

AMainLevelHud::AMainLevelHud()
{

}

void AMainLevelHud::ChangeMode(modes mode)
{
	
	Current_widget->RemoveFromViewport();
	Current_widget->RemoveFromParent();
	
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Blue, *FString("Removed from parent"));
	switch (mode) {
		case Game:
			
			IngameGenerated = Current_widget = CreateWidget<UUserWidget>(GetWorld(), InGame);
			UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetPause(0);
	
			break;
		case Pause:
			
			Current_widget = CreateWidget<UUserWidget>(GetWorld(), OnPause);
			UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetPause(1);
			break;
		case Lose:
			
			Current_widget = CreateWidget<UUserWidget>(GetWorld(), OnLose);
			UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetPause(1);
			break;
		case Clear:
			Current_widget = CreateWidget<UUserWidget>(GetWorld(), InMenu);
						
			break;
		case Settings:
			Current_widget = CreateWidget<UUserWidget>(GetWorld(), InSettings);
	}
	Current_widget->AddToViewport();
}

void AMainLevelHud::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Display, TEXT("%s"), *GetWorld()->GetMapName())
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetShowMouseCursor(true);
	if (GetWorld()->GetMapName() == FString(TEXT("UEDPIE_0_Menu")) || GetWorld()->GetMapName() == FString(TEXT("Menu"))) {
		
		IngameGenerated = CreateWidget<UUserWidget>(GetWorld(), InMenu);
		IngameGenerated->AddToViewport();
		Current_widget = IngameGenerated;
	}
	else {
		IngameGenerated = CreateWidget<UUserWidget>(GetWorld(), InGame);
		IngameGenerated->AddToViewport();
		Current_widget = IngameGenerated;
	}
}

