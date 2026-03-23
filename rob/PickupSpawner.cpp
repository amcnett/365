#include "PickupSpawner.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/World.h"

APickupSpawner::APickupSpawner()
{
    PrimaryActorTick.bCanEverTick = false;
}

void APickupSpawner::BeginPlay()
{
    Super::BeginPlay();

    if (!PickupClass)
    {
        UE_LOG(LogTemp, Warning, TEXT("PickupSpawner: No PickupClass assigned!"));
        return;
    }

    UWorld* World = GetWorld();
    if (!World)
        return;

    for (int32 i = 0; i < NumberToSpawn; i++)
    {
        FVector SpawnLocation = GetRandomPointInRadius();
        FRotator SpawnRotation = FRotator::ZeroRotator;

        World->SpawnActor<AActor>(PickupClass, SpawnLocation, SpawnRotation);
    }
}

FVector APickupSpawner::GetRandomPointInRadius() const
{
    FVector Origin = GetActorLocation();
    FVector RandomOffset = UKismetMathLibrary::RandomUnitVector() * FMath::FRandRange(0.f, SpawnRadius);
    return Origin + RandomOffset;
}
