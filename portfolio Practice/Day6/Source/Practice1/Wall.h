// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Practice1.h"
#include "GameFramework/Actor.h"
#include "Wall.generated.h"

UCLASS()
class PRACTICE1_API AWall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	// Called every frame
	virtual void PostInitializeComponents() override;
public:
	UPROPERTY(VisibleAnywhere, Category = Box)
		UBoxComponent* Trigger;
	UPROPERTY(VisibleAnywhere, Category = Box)
		UStaticMeshComponent* Wall;
private:
	UFUNCTION()
		void OnCharacterOverlap(
			UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void EndCharacterOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
