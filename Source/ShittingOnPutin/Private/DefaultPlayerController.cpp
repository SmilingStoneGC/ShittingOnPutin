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


}
void ADefaultPlayerController::Tick(float DeltaTime){
	Super::Tick(DeltaTime);
	
}

void ADefaultPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	
}

void ADefaultPlayerController::SpawnPutin(TSubclassOf<APutin> ActorToSpawn, FPutinSpawnParams SpawnParams)
{
	APutin* Huilo = GetWorld()->SpawnActorDeferred<APutin>(ActorToSpawn, FTransform());
	Huilo->SetTimeToDone(SpawnParams.Current_Speed);
	UGameplayStatics::FinishSpawningActor(Huilo, FTransform());
}



