// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzlePlatformsGameInstance.h"

UPuzlePlatformsGameInstance::UPuzlePlatformsGameInstance(const FObjectInitializer& ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Constructor"))
}

void UPuzlePlatformsGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Init"))
}

void UPuzlePlatformsGameInstance::Host() 
{
	UEngine* Engine = GetEngine();

	if (!Engine) {
		return;
	}

	Engine->AddOnScreenDebugMessage(0, 3, FColor::Green, TEXT("Hosting..."));

	UWorld* World = GetWorld();
	if (!World) {
		return;
	}

	World->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
}

void UPuzlePlatformsGameInstance::Join(const FString& Address)
{
	UEngine* Engine = GetEngine();

	if (!Engine) {
		return;
	}

	Engine->AddOnScreenDebugMessage(0, 3, FColor::Green, FString::Printf(TEXT("Joining %s"), *Address));

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!PlayerController) {
		return;
	}

	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}