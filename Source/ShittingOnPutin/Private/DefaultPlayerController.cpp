// Fill out your copyright notice in the Description page of Project Settings.


#include "DefaultPlayerController.h"
#include "../Interface/MainLevelHud.h"
#include "../Interface/InGameUI.h"
ADefaultPlayerController::ADefaultPlayerController()
{
	PrimaryActorTick.bCanEverTick = false;
	
	
	
}

void ADefaultPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	
	
		
	TArray<AActor*> arr;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMainPlayer::StaticClass(), arr);
	if (arr.IsValidIndex(0))
		Possess(Cast<APawn>(arr[0]));
	SetShowMouseCursor(true);
	WaveSpawn();

}
void ADefaultPlayerController::Tick(float DeltaTime){
	Super::Tick(DeltaTime);
	
}



void ADefaultPlayerController::SpawnPutin(TSubclassOf<APutin> ActorToSpawn, FPutinSpawnParams &SpawnParams)
{
	APutin* Huilo = GetWorld()->SpawnActorDeferred<APutin>(ActorToSpawn, FTransform());
	Huilo->SetTimeToDone(SpawnParams.Current_Speed);
	UGameplayStatics::FinishSpawningActor(Huilo, FTransform());
	SpawnParams.count_to_spawn--;
}

void ADefaultPlayerController::WaveSpawn()
{
	if (StartWaveSound.Num()>0) {
		UGameplayStatics::SpawnSound2D(this, StartWaveSound[FMath::Rand() % StartWaveSound.Num()], 1, 1);
	}
	if(CurrentWave>1)
		for (int i = 0; i < Putins.Num(); i++) {
			Rules[i].UpdateData(CurrentWave);
		}

	GetWorld()->GetTimerManager().SetTimer(Timer, this, &ADefaultPlayerController::Spawner, SpawnPeriod, true);
	CanEndWave = false;
}

void ADefaultPlayerController::Spawner()
{
	for (int i = 0; i < Putins.Num(); i++) {
		if (Rules[i].count_to_spawn != 0) {
			SpawnPutin(Putins[i], Rules[i]);
			return;
		}
	}
	GetWorld()->GetTimerManager().ClearTimer(Timer);
	CurrentWave++;
	
	CanEndWave = true;
}



