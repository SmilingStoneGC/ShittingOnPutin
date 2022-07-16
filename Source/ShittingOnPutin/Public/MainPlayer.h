// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Poop.h"
#include "Sound/SoundCue.h"
#include "Kismet/GameplayStatics.h"
#include "../Interface/InGameUI.h"
#include "../Interface/MainlevelHud.h"
#include "Components/SplineComponent.h"
#include "MainPlayer.generated.h"

UCLASS()
class SHITTINGONPUTIN_API AMainPlayer : public APawn
{
	GENERATED_BODY()
public:
	// Sets default values for this pawn's properties
	AMainPlayer();

protected:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "GeneralSettings")
		TSubclassOf <AActor> Burger;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "GeneralSettings")
		TSubclassOf <AActor> SplineActor;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "GeneralSettings")
		USoundCue *PoopSoundCue;
	//UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "GeneralSettings")
		//UAudioComponent	* PoopAudioComponent;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Components")
		USkeletalMeshComponent* Mesh;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Components")
		USceneComponent* Scene;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Components")
		UCameraComponent* Camera;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Components")
		UCapsuleComponent *Capsule;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "PoopSettings")
		TSubclassOf<APoop> poop;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "PoopSettings")
		FVector PoopSpawnLocation;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "PoopSettings")
		int poop_max;
	UPROPERTY(BlueprintReadWrite)
		int poop_count;
public:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Movement")
		float speed = 1;
	UPROPERTY(BlueprintReadWrite,Category = "Movement")
		FVector direction = FVector::ZeroVector;
	int times = 0;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Stats")
		float Score = 0;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable)
		bool is_poop_empty() {
		return poop_count > 0;
	}
	UFUNCTION(BlueprintCallable)
	
	void addScore(float power) {
		this->Score += power;
		UInGameUI *UI =Cast<UInGameUI>(Cast<AMainLevelHud>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD())->IngameGenerated);
		UI->SetScoreText(Score);
		times++;
		if (times == 3) {
			SpawnBurger();
			times = 0;
		}
	}
	UFUNCTION(BlueprintCallable)
	float getScore() {
		return Score;

	}
	UFUNCTION(BlueprintCallable)
		void renew_poop() {
		Cast<UInGameUI>(Cast<AMainLevelHud>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD())->IngameGenerated)->SetPoopAvilable(true);
			poop_count = poop_max;
		}
	UFUNCTION(BlueprintCallable)
		void SpawnPoop();
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	private:
		void SpawnBurger();
		//friend ADefaultPlayerController;

};
