// Fill out your copyright notice in the Description page of Project Settings.

#include "bullet.h"
#include "NeonBullet_01.h"
#include "EnemyDrone.h"
#include "EnemyTurret.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

// Sets default values
Abullet::Abullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USphereComponent>(TEXT("MySphere"));
	Cast<UShapeComponent>(RootComponent)->OnComponentBeginOverlap.AddDynamic(this, &Abullet::OnOverlap);

}

// Called when the game starts or when spawned
void Abullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Abullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	NewLocation += GetActorForwardVector() * Speed * DeltaTime;
	SetActorLocation(NewLocation);

	TimeAlive += DeltaTime;
	if (TimeAlive > TimeBeforeDestroy)
	{
		this->Destroy();
	}

}

void Abullet::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
	UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult &SweepResult)
{
	if (OtherActor->IsA(AEnemyDrone::StaticClass()))
	{
		Cast<AEnemyDrone>(OtherActor)->isHit();

		Destroy();
	}
}