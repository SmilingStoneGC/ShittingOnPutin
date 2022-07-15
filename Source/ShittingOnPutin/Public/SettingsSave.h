// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SettingsSave.generated.h"

/**
 * 
 */
UCLASS()
class SHITTINGONPUTIN_API USettingsSave : public USaveGame
{
	GENERATED_BODY()

		USettingsSave(){};
	public:
		UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="Volume")
			float MusicVolume = 1.0f;
		UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Volume")
			float EffectVolume = 1.0f;
		UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "GraphicsSettings")
			int32 AAmethod = 1;

		
};
