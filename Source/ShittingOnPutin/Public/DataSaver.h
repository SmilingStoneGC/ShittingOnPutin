// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "UObject/ObjectMacros.h"
#include "DataSaver.generated.h"

/**
 * 
 */
UCLASS()
class SHITTINGONPUTIN_API UDataSaver : public USaveGame
{
	GENERATED_BODY()
public:
	UDataSaver() {};
	UPROPERTY(BlueprintReadWrite, Category="Stats")
		float High_Score = -1;
	UPROPERTY(BlueprintReadWrite, Category = "Developer_Info")
		bool Is_First_Time = 1;

	
	
};
