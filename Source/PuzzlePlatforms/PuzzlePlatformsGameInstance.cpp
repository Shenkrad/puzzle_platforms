// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePlatformsGameInstance.h"



UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance(const FObjectInitializer & ObjectInitializer)
{
    UE_LOG(LogTemp, Warning, TEXT("Constructor alert"));
}

void UPuzzlePlatformsGameInstance::Init()
{
    UE_LOG(LogTemp, Warning, TEXT("Init alert"));
}

void UPuzzlePlatformsGameInstance::Host()
{
    UEngine* Engine = GetEngine();
    if (!ensure(Engine != nullptr)) return;

    Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, TEXT("Hosting"));

    UWorld* World = GetWorld();
    if (!ensure(World != nullptr)) return;

    World->ServerTravel("/Game/ThirdPerson/Maps/ThirdPersonMap?listen");

}

void UPuzzlePlatformsGameInstance::Join(const FString& Address)
{
    UEngine* Engine = GetEngine();
    if (!ensure(Engine != nullptr)) return;

    Engine->AddOnScreenDebugMessage(0, 5, FColor::Green, FString::Printf(TEXT("Joining %s..."), *Address));

    APlayerController* PlayerController = GetFirstLocalPlayerController();
    if (!ensure(PlayerController != nullptr)) return;

    PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);

}
