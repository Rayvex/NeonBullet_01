// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyTurret.generated.h"

UCLASS()
class NEONBULLET_01_API AEnemyTurret : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyTurret();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FVector MoveDirection = FVector(0.f, 0.f, 0.f);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
		float TurnDelayMax = 6.f;

	/*How long min till turn towards player*/
	UPROPERTY(EditAnywhere)
		float TurnDelayMin = 3.f;

	float CurrentTurnDelay = 5.f;


};
