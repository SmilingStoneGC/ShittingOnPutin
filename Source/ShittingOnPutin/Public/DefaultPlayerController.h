// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayer.h"
#include "Putin.h"
#include "DefaultPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SHITTINGONPUTIN_API ADefaultPlayerController : public APlayerController
{

	GENERATED_BODY()
	

	public:
		ADefaultPlayerController();
		virtual void BeginPlay() override;
		virtual void Tick(float DeltaTime) override;
		virtual void OnPossess(APawn* InPawn) override;
		void SpawnPutin();
		FTimerHandle TimeHandle, Time_Handle_Speed, Time_Handle_CST;
		
		void ChangeSettings();
		UPROPERTY(EditAnywhere, Category = "Params")
			TSubclassOf<APutin> Putin;
		UPROPERTY(EditAnywhere, Category = "Params")
		float Putin_Spawntime = 3;
		UPROPERTY(EditAnywhere, Category = "Params")
		float Putin_Speed = 30;
	private:
		void ChangeSpawnTime();
};
