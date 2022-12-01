// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
    PrimaryActorTick.bCanEverTick = true;

    SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
    Super::BeginPlay();

    if (HasAuthority())
    {
        SetReplicates(true);
        SetReplicatingMovement(true);
    }  
}

void AMovingPlatform::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (HasAuthority())
    {
        FVector Location = GetActorLocation();
        FVector GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
        FVector Direction = (GlobalTargetLocation - Location).GetSafeNormal();
        Location += Speed * Direction * DeltaTime;
        SetActorLocation(Location);
    }
    
}

