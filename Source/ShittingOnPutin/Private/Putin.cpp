// Fill out your copyright notice in the Description page of Project Settings.


#include "Putin.h"

// Sets default values
APutin::APutin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Scene = CreateDefaultSubobject<USceneComponent>("Root");
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>("Putin's Body");
	SetRootComponent(Scene);
	Mesh->SetupAttachment(Scene);
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("Putin's collision");
	CapsuleComponent->SetupAttachment(Scene);
	
	
}


// Called when the game starts or when spawned
void APutin::BeginPlay()
{
	Super::BeginPlay();
	TArray<AActor*>Way;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), SplineClass, Way);
	if(Way.Num())
	DirectlyNahui = Way[FMath::Rand()%Way.Num()]->FindComponentByClass<USplineComponent>();
	if (DirectlyNahui == NULL) Destroy();
	start_time = GetWorld()->TimeSeconds;
	CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &APutin::Uebalsa);
	//UE_LOG(LogTemp, Display, L"%f", time_to_done);
}

void APutin::Uebalsa(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//UE_LOG(LogTemp, Display, L"Collision detected")
		APoop* to_srat = Cast<APoop>(OtherActor);
	if (to_srat) {
		to_srat->destroy_cube();
		Cast<AMainPlayer>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn())->addScore(10);
		Destroy();
	}
	
}

// Called every frame
void APutin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	float time_pos = GetWorld()->TimeSeconds-start_time;
	if (time_pos > time_to_done) {
		Destroy(); 
		return;
	}
	SetActorLocation(DirectlyNahui->GetLocationAtTime(time_pos/(time_to_done *DirectlyNahui->Duration), ESplineCoordinateSpace::World));
	
}

