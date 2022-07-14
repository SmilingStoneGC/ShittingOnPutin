// Fill out your copyright notice in the Description page of Project Settings.


#include "DefaultPlayerController.h"
#include "../Interface/MainLevelHud.h"
#include "../Interface/InGameUI.h"
ADefaultPlayerController::ADefaultPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
	
	
	
}

void ADefaultPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	FTimerDelegate Timer_delegate = FTimerDelegate::CreateUObject(this, &ADefaultPlayerController::SpawnPutin);
	SpawnPutin();
	
	GetWorldTimerManager().SetTimer(TimeHandle, Timer_delegate, Putin_Spawntime, true);
	GetWorldTimerManager().SetTimer(Time_Handle_Speed, this, &ADefaultPlayerController::ChangeSettings, 60, true, 60);
	GetWorldTimerManager().SetTimer(Time_Handle_CST,this, &ADefaultPlayerController::ChangeSpawnTime, 30, true, 30);
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

void ADefaultPlayerController::SpawnPutin()
{
	APutin* Huilo = GetWorld()->SpawnActorDeferred<APutin>(Putin, FTransform());
	Huilo->SetTimeToDone(Putin_Speed);
	UGameplayStatics::FinishSpawningActor(Huilo, FTransform());
}

void ADefaultPlayerController::ChangeSettings()
{
	//UE_LOG(LogTemp, Display, TEXT("%I'm in the ChangeSettings"))
		if (Putin_Speed > 3) {
			Putin_Speed *= 0.8;
			Cast<AMainPlayer>(GetPawn())->speed *= 1.2;
			
		}
		else {
			GetWorld()->GetTimerManager().ClearTimer(Time_Handle_Speed);
		}
}

void ADefaultPlayerController::ChangeSpawnTime()
{
	Putin_Spawntime *= 0.5f;
	if (Putin_Spawntime > 2)
		GetWorldTimerManager().ClearTimer(Time_Handle_CST);
	UE_LOG(LogTemp, Display, TEXT("Spawntime: %f %f"), GetWorldTimerManager().GetTimerRate(TimeHandle), Putin_Spawntime)
		GetWorldTimerManager().ClearTimer(TimeHandle);
	GetWorldTimerManager().SetTimer(TimeHandle,this, &ADefaultPlayerController::SpawnPutin, Putin_Spawntime, 1, 0);
}

