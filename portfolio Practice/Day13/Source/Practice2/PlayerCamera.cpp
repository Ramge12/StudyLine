// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCamera.h"
#include "DrawDebugHelpers.h"
#include "P2PlayerController.h"
UPlayerCamera::UPlayerCamera()
{
	PrimaryComponentTick.bCanEverTick = true;

	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	this->SetupAttachment(SpringArm);
	SpringArm->TargetArmLength =150.0f;
	ArmLengthTo = SpringArm->TargetArmLength;
	SpringArm->SetRelativeRotation(FRotator(-30.0f, 0.0f, 0.0f));
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->bInheritPitch = true;
	SpringArm->bInheritRoll = true;
	SpringArm->bInheritYaw = true;
	SpringArm->bDoCollisionTest = false;
	ViewState = PlayerViewState::View_IDLE;
	ArmRotationSpeed = 5.0f;

}

void UPlayerCamera::setSpringArmCameraInRoot(UCapsuleComponent * root)
{
	SpringArm->SetupAttachment(root);
}

void UPlayerCamera::ChangeView(PlayerViewState view)
{
	switch (view) {
	case PlayerViewState::View_IDLE:
		ArmLengthTo = 150.0f;
		ViewState = PlayerViewState::View_IDLE;
		SpringArm->SetRelativeRotation(FRotator(-30.0f, 0.0f, 0.0f));
		SpringArm->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		SpringArm->bUsePawnControlRotation = true;
		SpringArm->bInheritPitch = true;
		SpringArm->bInheritRoll = true;
		SpringArm->bInheritYaw = true;
		SpringArm->bDoCollisionTest = false;
		break;
	case PlayerViewState::View_SHOT:
		ArmLengthTo = 50.0f;
		ViewState = PlayerViewState::View_SHOT;
		SpringArm->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
		SpringArm->SetRelativeLocation(FVector(37.5f, 0.0f, 30.0f));
		SpringArm->bUsePawnControlRotation = true;
		SpringArm->bInheritPitch = true;
		SpringArm->bInheritRoll = true;
		SpringArm->bInheritYaw = true;
		SpringArm->bDoCollisionTest = false;
		break;
	}
}

void UPlayerCamera::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	SpringArm->TargetArmLength = FMath::FInterpTo(SpringArm->TargetArmLength, ArmLengthTo, DeltaTime, ArmRotationSpeed);

}

void UPlayerCamera::CameraVector()
{
	FHitResult* HitResult = new FHitResult();
	float TraceRange = 10.0f;
	float TraceRadius = 5.0f;
	
	FVector StartTrace = this->GetComponentLocation();
	FVector ForwardVector = this->GetForwardVector();
	FVector EndTrace = ((ForwardVector*5000.0f) + StartTrace);
	FCollisionQueryParams* TraceParams = new FCollisionQueryParams();

	if (GetWorld()->LineTraceSingleByChannel(*HitResult, StartTrace, EndTrace, ECC_Visibility, *TraceParams))
	{
		DrawDebugLine(GetWorld(), StartTrace, EndTrace, FColor(255, 0, 0), true);
	}

}
