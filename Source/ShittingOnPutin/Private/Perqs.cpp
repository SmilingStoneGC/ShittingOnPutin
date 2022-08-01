// Fill out your copyright notice in the Description page of Project Settings.


#include "Perqs.h"

// Sets default values
APerqs::APerqs()
{
 	
	PrimaryActorTick.bCanEverTick = false;
	Mesh= CreateDefaultSubobject<UStaticMeshComponent>("Scene");
	SphereCollision = CreateDefaultSubobject<USphereComponent>("Collision");
	SetRootComponent(SphereCollision);
	Mesh->SetupAttachment(SphereCollision);
}

void APerqs::ComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	FTimerHandle Timerhandle;
	
	
	
	GetWorld()->GetTimerManager().SetTimer(Timerhandle, this,&APerqs::Destroyer, 5,0,5 );
}

// Called when the game starts or when spawned
void APerqs::BeginPlay()
{
	Super::BeginPlay();
	SphereCollision->OnComponentHit.AddDynamic(this, &APerqs::ComponentHit);
	SphereCollision->OnClicked.AddDynamic(this, &APerqs::OnClickActivate);
	SphereCollision->OnInputTouchBegin.AddDynamic(this, &APerqs::OnTouchActivate);
	
}

// Called every frame
void APerqs::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

