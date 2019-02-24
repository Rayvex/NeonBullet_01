// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NeonBullet_01.h"
#include "NeonBullet_01GameModeBase.h"
#include "GameFramework/Actor.h"
#include "EnemyDrone.generated.h"


UCLASS()
class NEONBULLET_01_API AEnemyDrone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyDrone();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FVector MoveDirection = FVector(1.f, 0.f, 0.f);

	void isHit();

	bool yeetEnemy{false};

private:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	float Speed = 20.f;

	UPROPERTY(EditAnywhere)
	float TurnDelayMax = 4.f;

	/*How long min till turn towards player*/
	UPROPERTY(EditAnywhere)
	float TurnDelayMin = 1.f;

	float CurrentTurnDelay = 0.f;
};
