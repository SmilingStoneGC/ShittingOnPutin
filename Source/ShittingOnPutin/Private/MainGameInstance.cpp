// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
void UMainGameInstance::Init()
{
	Super::Init();
	//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, *FString("Error openning"));
	
	//PlaySound();
}
void UMainGameInstance::SaveGame()
{

	UGameplayStatics::SaveGameToSlot(ASaveObj, FString("AllData"), 0);
};

void UMainGameInstance::LoadGame()
{
	UDataSaver *TempSaver=Cast<UDataSaver>(UGameplayStatics::LoadGameFromSlot(FString("AllData"), 0));
	if (TempSaver) {
		ASaveObj = TempSaver;
	}
	else {
		ASaveObj = Cast<UDataSaver>(UGameplayStatics::CreateSaveGameObject(UDataSaver::StaticClass()));
	}
}

void UMainGameInstance::LoadSettings()
{
	USettingsSave* TempSaver = Cast<USettingsSave>(UGameplayStatics::LoadGameFromSlot(FString("SettingsData"), 0));
	if (TempSaver) {
		Settings = TempSaver;
	}
	else {
		Settings = Cast<USettingsSave>(UGameplayStatics::CreateSaveGameObject(USettingsSave::StaticClass()));
	}
}

void UMainGameInstance::SaveSettings()
{
	UGameplayStatics::SaveGameToSlot(Settings, FString("SettingsData"), 0);
}

void UMainGameInstance::PlaySound()
{
	if (!is_playing) {
		USoundWave* ASoundCue = LoadObject<USoundWave>(NULL, TEXT("/Game/Sound/Test_music.Test_music"));
		
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, *FString("Started"));
		if (ASoundCue)
			UGameplayStatics::SpawnSound2D(this, ASoundCue, 1, 1, 1, NULL, true, false);
		//else GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, *FString("Error openning"));
		is_playing = true;
	}
}

