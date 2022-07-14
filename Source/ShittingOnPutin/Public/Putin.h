// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SplineComponent.h"
#include "MainPlayer.h"
#include "Poop.h"
#include "Components/CapsuleComponent.h"
#include "Putin.generated.h"

UCLASS()
class SHITTINGONPUTIN_API APutin : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APutin();
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category="Components")
	USkeletalMeshComponent* Mesh;
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	USceneComponent* Scene;
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AActor> SplineClass;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
		UCapsuleComponent* CapsuleComponent;
	USplineComponent* DirectlyNahui;
	UPROPERTY(BlueprintReadWrite, Category = "Movement")
		float time_to_done = 20;
	float start_time;
	UFUNCTION()
	void Uebalsa(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
public:	
	// Called every frame
	void SetTimeToDone(float Time) {
		this->time_to_done = Time;
	}
	virtual void Tick(float DeltaTime) override;

};
