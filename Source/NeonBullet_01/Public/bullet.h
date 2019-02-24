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
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this actor's properties
	Abullet();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
