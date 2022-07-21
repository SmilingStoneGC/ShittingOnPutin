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
USTRUCT(BlueprintType)
struct FPutinSpawnParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	float AddEveryRound = 0;
	UPROPERTY(EditAnywhere)
	int32 count_to_spawn = 0;
	UPROPERTY(EditAnywhere)
	float SpeedMultiplier = 1;
	UPROPERTY(EditAnywhere)
	float Current_Speed = 15;
};
UCLASS()
class SHITTINGONPUTIN_API ADefaultPlayerController : public APlayerController
{

	GENERATED_BODY()
	

	public:
		ADefaultPlayerController();
		virtual void BeginPlay() override;
		virtual void Tick(float DeltaTime) override;
		virtual void OnPossess(APawn* InPawn) override;
		void SpawnPutin(TSubclassOf<APutin> ActorToSpawn, FPutinSpawnParams SpawnParams);
		
		
		
		UPROPERTY(EditAnywhere, Category = "Params")
			TArray<TSubclassOf<APutin>> Putins;
		UPROPERTY(EditAnywhere, Category = "Params")
			float SpawnPeriod = 2;

		UPROPERTY(EditAnywhere, Category = "Params")
			TArray<FPutinSpawnParams> Rules;


	private:
		int32 CurrentWave = 1;
};
