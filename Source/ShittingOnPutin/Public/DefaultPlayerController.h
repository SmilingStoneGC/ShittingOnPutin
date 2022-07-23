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
		int32 FirstRoundCount = 0;
	UPROPERTY(EditAnywhere)
	int32 count_to_spawn = 0;
	UPROPERTY(EditAnywhere)
	float SpeedMultiplier = 1;
	UPROPERTY(EditAnywhere)
	float Current_Speed = 15;
	UPROPERTY(EditAnywhere)
		float Speed_Limit = 8;
	float current_count_float = 1;
	

	void UpdateData(int32 wave) {
		if(Current_Speed/SpeedMultiplier > Speed_Limit)
			Current_Speed /= SpeedMultiplier;
		count_to_spawn = (wave-1) * AddEveryRound+FirstRoundCount;

	};
};
UCLASS()
class SHITTINGONPUTIN_API ADefaultPlayerController : public APlayerController
{

	GENERATED_BODY()
	

	public:
		ADefaultPlayerController();
		virtual void BeginPlay() override;
		virtual void Tick(float DeltaTime) override;
		//virtual void OnPossess(APawn* InPawn) override;
		void SpawnPutin(TSubclassOf<APutin> ActorToSpawn, FPutinSpawnParams &SpawnParams);
		
		
		
		UPROPERTY(EditAnywhere, Category = "Params")
			TArray<TSubclassOf<APutin>> Putins;
		UPROPERTY(EditAnywhere, Category = "Params")
			float SpawnPeriod = 2;
		
		UPROPERTY(EditDefaultsOnly)
			TArray<USoundWave*> StartWaveSound;
		UPROPERTY(EditAnywhere, Category = "Params")
			TArray<FPutinSpawnParams> Rules;
		//UPROPERTY(EditAnywhere, Category = "Params")
			void WaveSpawn();
		void Spawner();
		
		UFUNCTION(BlueprintCallable)
		bool IsEndWave() const {
			return CanEndWave;
		}
		void StartNewWave() {
			GetWorld()->GetTimerManager().SetTimer(Timer, this, &ADefaultPlayerController::WaveSpawn, 5, 0, 5);
		}
	private:
		FTimerHandle Timer;
		int32 CurrentWave = 1;
		bool CanEndWave = false;
};
