// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "bullet.generated.h"

UCLASS()
class NEONBULLET_01_API Abullet : public AActor
{
	GENERATED_BODY()
	

private:
	UPROPERTY(EditAnywhere)
	float Speed{400.f};

	UPROPERTY(EditAnywhere)
	float TimeBeforeDestroy{5.f};

	float TimeAlive{0};

	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
		UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult &SweepResult);

public:	
	// Sets default values for this actor's properties
	Abullet();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
