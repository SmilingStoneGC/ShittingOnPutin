// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayer.h"

// Sets default values
AMainPlayer::AMainPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Scene = CreateDefaultSubobject<USceneComponent>("RootScene");
	SetRootComponent(Scene);
	Capsule = CreateDefaultSubobject<UCapsuleComponent>("CapsuleCollision");
	Capsule->SetupAttachment(Scene);
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>("Mesh");
	Mesh->SetupAttachment(Capsule);
	Camera = CreateDefaultSubobject<UCameraComponent>("PlayerCamera");
	Camera->SetupAttachment(Scene);
	//PoopAudioComponent = CreateDefaultSubobject<UAudioComponent>("PoopAudioComponent");
	//PoopAudioComponent->SetupAttachment(Camera);
	//PoopAudioComponent->bAutoActivate = false;
	//PoopAudioComponent->SetSound(PoopSoundCue);

	
}

// Called when the game starts or when spawned
void AMainPlayer::BeginPlay()
{
	Super::BeginPlay();
	poop_count = poop_max;
	
}

// Called every frame
void AMainPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (direction != FVector::ZeroVector) {
		
		Capsule->SetWorldLocation(Capsule->GetComponentLocation() + direction * DeltaTime * speed, true);
	}
}

void AMainPlayer::SpawnPoop()
{
	FTransform trans(FRotator::ZeroRotator,Mesh->GetComponentLocation() + PoopSpawnLocation);
	
	
	if (poop_count) {
		
		APoop* spawnedpoop = (APoop*)GetWorld()->SpawnActorDeferred<APoop>(poop, trans);
		spawnedpoop->Time_To_Go = 10;
		spawnedpoop->set_power(1);
		UGameplayStatics::FinishSpawningActor(spawnedpoop, trans);
		poop_count--;
		//if (PoopSoundCue) {
			//PoopAudioComponent->Play();
		//}
		//UGameplayStatics::PlaySound2D(this, PoopSoundCue);
		
	}
	else {
		Cast<UInGameUI>(Cast<AMainLevelHud>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD())->IngameGenerated)->SetPoopAvilable(false);
	}

}

// Called to bind functionality to input
void AMainPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMainPlayer::SpawnBurger()
{
	TArray<AActor*>SplineActorarr;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), SplineActor, SplineActorarr);
	if (SplineActorarr.Num() > 0) {
		USplineComponent * Spline = Cast<USplineComponent>(SplineActorarr[0]->FindComponentByClass<USplineComponent>());
		FVector Location = Spline->GetLocationAtTime(FMath::FRand(), ESplineCoordinateSpace::World);
		GetWorld()->SpawnActor(Burger, &Location);
	}
	else UE_LOG(LogTemp, Display, TEXT("Getting error"));
}

