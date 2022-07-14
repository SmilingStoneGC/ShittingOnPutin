// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataSaver.h"
#include "SettingsSave.h"
#include "Engine/GameInstance.h"

#include "MainGameInstance.generated.h"

/**
 * 
 */

UCLASS()
class SHITTINGONPUTIN_API UMainGameInstance : public UGameInstance
{
	GENERATED_BODY()
	public:
		virtual void Init() override;
	UPROPERTY(BlueprintReadWrite, Category = "Params")
		UDataSaver* ASaveObj;
	UPROPERTY(BlueprintReadWrite, Category = "Params")
		USettingsSave* Settings;
	bool is_playing = false;
	UFUNCTION(BlueprintCallable, Category = "MNGR")
		void SaveGame();
	UFUNCTION(BlueprintCallable, Category = "MNGR")
		void LoadGame();
	UFUNCTION(BlueprintCallable, Category = "MNGR")
		void LoadSettings();
	UFUNCTION(BlueprintCallable, Category = "MNGR")
		void SaveSettings();
	UFUNCTION(BlueprintCallable, Category = "Sound")
		void PlaySound();

};
