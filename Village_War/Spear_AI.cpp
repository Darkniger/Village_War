// Fill out your copyright notice in the Description page of Project Settings.
#include "Spear_AI.h"
#include "Village_War.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "Spear.h"


//ASpear_AI::ASpearAI()
//{
//	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
//	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));
//}

void ASpear_AI::Possess(APawn *InPawn)
{
	Super::Possess(InPawn);
	ASpear *Char = Cast<ASpear>(InPawn);

	if (Char && Char->BotBehavior)
	{
		//BlackboardComp->InitializeBlackboard(*Char->BotBehavior->BlackboardAsset);

		SpearKeyID = BlackboardComp->GetKeyID("Target");

		//BehaviorComp->StartTree(*Char->BotBehavior);
	}
}