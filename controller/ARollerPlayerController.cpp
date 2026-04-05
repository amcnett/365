// Fill out your copyright notice in the Description page of Project Settings.

#include "RollerPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "RollerCharacter.h"

void ARollerPlayerController::BeginPlay()
{
    Super::BeginPlay();

    if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
        ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
    {
        Subsystem->AddMappingContext(DefaultMappingContext, 0);
    }
}

void ARollerPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(InputComponent))
    {
        EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ARollerPlayerController::Move);
        EIC->BindAction(LookAction, ETriggerEvent::Triggered, this, &ARollerPlayerController::Look);

        EIC->BindAction(JumpAction, ETriggerEvent::Started, this, &ARollerPlayerController::StartJump);
        EIC->BindAction(JumpAction, ETriggerEvent::Completed, this, &ARollerPlayerController::StopJump);
    }
}

void ARollerPlayerController::Move(const FInputActionValue& Value)
{
    if (ARollerCharacter* Char = Cast<ARollerCharacter>(GetPawn()))
    {
        Char->Move(Value);
    }
}

void ARollerPlayerController::Look(const FInputActionValue& Value)
{
    if (ARollerCharacter* Char = Cast<ARollerCharacter>(GetPawn()))
    {
        Char->Look(Value);
    }
}

void ARollerPlayerController::StartJump()
{
    if (ARollerCharacter* Char = Cast<ARollerCharacter>(GetPawn()))
    {
        Char->Jump();
    }
}

void ARollerPlayerController::StopJump()
{
    if (ARollerCharacter* Char = Cast<ARollerCharacter>(GetPawn()))
    {
        Char->StopJumping();
    }
}
