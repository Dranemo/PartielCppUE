// Fill out your copyright notice in the Description page of Project Settings.
#include "PartielUECPP/Public/AChronoCube.h"

// Sets default values
AAChronoCube::AAChronoCube()
{
	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Shape_Cube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Shape_Cube"));
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	


	RootComponent = Shape_Cube;
	BoxCollision->SetupAttachment(Shape_Cube);

}

// Called when the game starts or when spawned
void AAChronoCube::BeginPlay()
{
	Super::BeginPlay();

	if (BaseMaterial)
	{
		material = UMaterialInstanceDynamic::Create(BaseMaterial, this);
        
		if (Shape_Cube)
		{
			Shape_Cube->SetMaterial(0, material); 
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, "haha non");

		}
		else
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, "haha presque");

	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, "haha non");

	}
	
	if (BoxCollision)
	{
		BoxCollision->SetEnableGravity(false);
	}
}

// Called every frame
void AAChronoCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(blsActive)
	{
		timer -= DeltaTime;

		if(material)
			material->SetVectorParameterValue("BaseColor", colors[timer - 1]);
	}
}




