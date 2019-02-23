// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyTurret.h"
#include "Engine/Engine.h"

// Sets default values
AEnemyTurret::AEnemyTurret()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyTurret::BeginPlay()
{
	Super::BeginPlay();
	
	MoveDirection = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation() - GetActorLocation();
	MoveDirection.Normalize(); //Smooth 
	SetActorRotation(MoveDirection.Rotation());
}

// Called every frame
void AEnemyTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	NewLocation += (MoveDirection * Speed * DeltaTime);
	SetActorLocation(NewLocation);

	CurrentTurnDelay -= DeltaTime;
	///Turns the enemy after some time:
	if (CurrentTurnDelay < 0.f)
	{
		MoveDirection = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation() - GetActorLocation();
		// MoveDirection.Normalize();
		SetActorRotation(MoveDirection.Rotation());

		CurrentTurnDelay = FMath::FRandRange(TurnDelayMin, TurnDelayMax);
	}
}