// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyDroneCharacter.h"
#include "Engine/Engine.h"

// Sets default values
AEnemyDroneCharacter::AEnemyDroneCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyDroneCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	MoveDirection = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation() - GetActorLocation();
	MoveDirection.Normalize(); //Smooth 
	SetActorRotation(MoveDirection.Rotation());
}

// Called every frame
void AEnemyDroneCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyDroneCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

