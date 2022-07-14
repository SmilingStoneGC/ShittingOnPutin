// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Blueprint/UserWidget.h"
#include "MainLevelHud.generated.h"

/**
 * 
 */


UENUM()
enum modes { Game, Pause, Lose, Clear };
UCLASS()
class SHITTINGONPUTIN_API AMainLevelHud : public AHUD
{
	GENERATED_BODY()
public:
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Defaults")
		TSubclassOf<UUserWidget> InGame;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Defaults")
		TSubclassOf<UUserWidget> OnPause;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Defaults")
		TSubclassOf<UUserWidget> OnLose;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Defaults")
		TSubclassOf<UUserWidget> InMenu;
	AMainLevelHud();
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Runtime")
	UUserWidget *IngameGenerated;
	UPROPERTY(BlueprintReadWrite, Category = "Runtime")
		UUserWidget* Current_widget;
	UFUNCTION(BlueprintCallable)
	void ChangeMode(modes mode);
private:
	virtual void BeginPlay() override;
	
};
