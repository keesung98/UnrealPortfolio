// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/UFPlayerController.h"

void AUFPlayerController::BeginPlay()
{
	Super::BeginPlay();

	FInputModeGameOnly GameOnlyInputMode;
	SetInputMode(GameOnlyInputMode);
}
