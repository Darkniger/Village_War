// Fill out your copyright notice in the Description page of Project Settings.

#include "Myactor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Classes/Components/ShapeComponent.h"
#include "Classes/Components/BoxComponent.h"

// Sets default values
AMyactor::AMyactor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->AttachToComponent(Root, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

	ChopBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Chopbox"));
	ChopBox->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
	ChopBox->SetGenerateOverlapEvents(true);
	ChopBox->OnComponentBeginOverlap.AddDynamic(this, &AMyactor::Chopwood);
	ChopBox->AttachToComponent(Root, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
}

// Called when the game starts or when spawned
void AMyactor::BeginPlay()
{
	Super::BeginPlay();
	
	//mCurrentMeshLocation = Mesh->GetRelativeTransform().GetLocation();
}

// Called every frame
void AMyactor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//float distance = this->GetDistanceTo(Player);
	//FVector meshLocation = mCurrentMeshLocation;
	//if (distance < 250)
	//{
	//	mCurrentMeshLocation.Z += 80;
	//}
	//Mesh->SetRelativeLocation(meshLocation);
}

void AMyactor::Chopwood(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{

	// Initialize the Python Interpreter
	Destroy();
}


