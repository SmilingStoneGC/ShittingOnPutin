// Fill out your copyright notice in the Description page of Project Settings.


#include "Poop.h"


// Sets default values
APoop::APoop()
{
	
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Scene = CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(Scene);
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(Scene);
	Spline = CreateDefaultSubobject<USplineComponent>("Spline");
	Spline->SetupAttachment(Scene);
	//Spline->SetDrawDebug(1);
	
	Spline->Duration = Time_To_Go;
}

// Called when the game starts or when spawned
void APoop::BeginPlay()
{
	Super::BeginPlay();
	Spline->RemoveSplinePoint(1);
	Spline->AddSplineWorldPoint(FVector(GetActorLocation().X, GetActorLocation().Y + 7345, 0));
	Spline->SetSplinePointType(0, ESplinePointType::Linear);
	Spline->SetSplinePointType(1, ESplinePointType::Linear);
	//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Cyan, *Spline->GetLocationAtSplinePoint(1, ESplineCoordinateSpace::World).ToString());
	StartTime = GWorld->GetTimeSeconds();
}

// Called every frame
void APoop::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	float since_moving = GWorld->GetTimeSeconds() - StartTime;
	if (Time_To_Go < since_moving) { Destroy(); return; }
	Mesh->SetWorldLocation(Spline->GetLocationAtTime(since_moving, ESplineCoordinateSpace::World));
	 
	Mesh->SetWorldRotation(Mesh->GetComponentRotation() + FRotator(0,0, 50 * DeltaTime));


}

