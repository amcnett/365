// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "EnemyAIController.generated.h"

class UAISenseConfig_Sight;
/**
 * 
 */
UCLASS()
class ROLLER_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
public:
    AEnemyAIController();

protected:
    virtual void OnPossess(APawn* InPawn) override;

    /** Perception component */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AI")
    UAIPerceptionComponent* PerceptionComp;

    /** Sight configuration */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AI")
    UAISenseConfig_Sight* SightConfig;

    /** Called when perception updates */
    UFUNCTION()
    void OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

private:
    APawn* ControlledPawn;
	
};
