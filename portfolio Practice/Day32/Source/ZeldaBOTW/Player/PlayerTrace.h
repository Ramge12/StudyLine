// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ZeldaBOTW.h"
#include "Components/ActorComponent.h"
#include "PlayerTrace.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ZELDABOTW_API UPlayerTrace : public UActorComponent
{
	GENERATED_BODY()

private:

	bool ThrowValue = false;
	UPROPERTY(Category = Trace, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool ViewDebugLine = false;
	UPROPERTY(Category = Trace, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool TraceClose = false;
	UPROPERTY(Category = Trace, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool TraceForward = false;
	UPROPERTY(Category = Trace, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool TracePush = false;
	UPROPERTY(Category = Trace, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool TraceClimming = false;
	UPROPERTY(Category = Trace, EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool TraceHeights = false;
public:
	UPlayerTrace();

protected:
	//virtual void BeginPlay() override;

public:
	// virtual void Tick(float DeltaTime) override;
	void PlayerTraceCheck(FVector playerLocation, FVector playerForwardVector, AActor* playerActer);
	void PlayerForwardTrace(FVector playerLocation, FVector playerForwardVector, AActor* playerActer);
	void PlayerCloseForwardTrace(FVector playerLocation, FVector playerForwardVector, AActor* playerActer);
	void PlayerHeightTrace(FVector playerLocation, FVector playerForwardVector, AActor* playerActer);
	void PlayerCounterAttack(FVector playerLocation, FVector playerForwardVector, AActor* playerActer);

	void TraceCheckActor(FHitResult TraceActorHitResult, AActor* PlayerActor);
	void ThrowObject();

	bool getTraceClose() { return TraceClose; }
	bool getTraceForward() { return TraceForward; }
	bool getTracePush() { return TracePush; }
	bool getTraceClimming() { return TraceClimming; }
	bool getTraceHeight() { return TraceHeights; }
};
