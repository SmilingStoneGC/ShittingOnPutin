#pragma once

#include "CoreMinimal.h"
#include "Components/SplineComponent.h"

#include "GameFramework/Actor.h"
#include "Poop.generated.h"

UCLASS()
class SHITTINGONPUTIN_API APoop : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APoop();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	USceneComponent* Scene;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	USplineComponent* Spline;
	int32 power = 1;
public:	
	float StartTime = 0;
	UPROPERTY(EditAnywhere, Category = "Components")
		UStaticMeshComponent* Mesh;
	void set_power(int32 power_) {
		this->power = power_;
	}
	void destroy_cube() {
		if (--power) return;
		Destroy();
	}

	// Called every frame
	UPROPERTY(EditAnywhere,Category = "Movement")
	float Time_To_Go = 10;
	virtual void Tick(float DeltaTime) override;
	
};
