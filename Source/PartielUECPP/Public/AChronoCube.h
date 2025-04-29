// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "AChronoCube.generated.h"

UCLASS()
class PARTIELUECPP_API AAChronoCube : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAChronoCube();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Shape_Cube;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component", meta = (AllowPrivateAccess = "true"))
	UBoxComponent* BoxCollision;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Materials", meta = (AllowPrivateAccess = "true"))
	UMaterialInterface* BaseMaterial;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Materials", meta = (AllowPrivateAccess = "true"))
	UMaterialInstanceDynamic* material;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Color", meta = (AllowPrivateAccess = "true"))
	TArray<FLinearColor> colors;
	
	float timer = 5.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
	bool blsActive = false;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
