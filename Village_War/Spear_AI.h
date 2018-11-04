// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Spear_AI.generated.h"

/**
 * 
 */
UCLASS()
class VILLAGE_WAR_API ASpear_AI : public AAIController
{
	GENERATED_BODY()

		UPROPERTY(transient)
		class UBlackboardComponent *BlackboardComp;

		UPROPERTY(transient)
		class UBehaviorTreeComponent *BehaviorComp;

public:
		//ASpearAI();

		virtual void Possess(APawn *InPawn) override;

		uint8 SpearKeyID;
};
