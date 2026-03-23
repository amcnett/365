#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickupSpawner.generated.h"

UCLASS()
class YOURGAME_API APickupSpawner : public AActor
{
    GENERATED_BODY()

public:
    APickupSpawner();

protected:
    virtual void BeginPlay() override;

public:

    // The Blueprint pickup to spawn
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawning")
    TSubclassOf<AActor> PickupClass;

    // How many pickups to spawn
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawning")
    int32 NumberToSpawn = 5;

    // Radius around the spawner to scatter pickups
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawning")
    float SpawnRadius = 300.f;

private:
    FVector GetRandomPointInRadius() const;
};
