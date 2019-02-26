// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyBullet.generated.h"

UCLASS()
class NEONBULLET_01_API AEnemyBullet : public AActor
{
	GENERATED_BODY()
	

private:
	UPROPERTY(EditAnywhere)
		float Speed{ 800.f };

	UPROPERTY(EditAnywhere)
		float TimeBeforeDestroy{ 5.f };

	float TimeAlive{ 0 };

	

public:
	// Sets default values for this actor's properties
	AEnemyBullet();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
