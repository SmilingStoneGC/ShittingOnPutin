// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Perqs.generated.h"

UCLASS()
class SHITTINGONPUTIN_API APerqs : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APerqs();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Components")
		UStaticMeshComponent* Mesh;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
		USphereComponent* SphereCollision;

	UPROPERTY(EditDefaultsOnly, Category = "Params")
		float ActiveTime = 1.0f;
	void OnClickActivate(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed) { OnActivate(); };
	void OnTouchActivate(ETouchIndex::Type FingerIndex, UPrimitiveComponent* TouchedComponent) { OnActivate(); };
	 virtual void OnActivate() {};
	virtual void ComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	
	void Destroyer() {
		Destroy();
	}
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
