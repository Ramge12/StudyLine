// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerWeapon.h"
#include "Player/PlayerCharacter.h"
#include "Player/Controller/PlayerCharacterController.h"
#include "Player/PlayerUIWidget.h"

// Sets default values
APlayerWeapon::APlayerWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Show_Arrow = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Show_Arrow"));
	Weapon_Sword = CreateDefaultSubobject<AWeapon_Equip>(TEXT("Weapon_Sword"));
	Weapon_Shield = CreateDefaultSubobject<AWeapon_Equip>(TEXT("Weapon_Shield"));
	Weapon_Bow = CreateDefaultSubobject<AWeapon_Equip>(TEXT("Weapon_Bow"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh>SK_Arrow(TEXT("/Game/OBJECT/Bow/Arrow/WeaponArrow.WeaponArrow"));
	if (SK_Arrow.Succeeded()) {
		Show_Arrow->SetStaticMesh(SK_Arrow.Object);
	}
	static ConstructorHelpers::FObjectFinder<UClass>SK_ARROW_BAG(TEXT("/Game/OBJECT/Bow/BOWBag/ArrowBag.ArrowBag_C"));
	if (SK_ARROW_BAG.Succeeded()) {
		ArrowBagBP = SK_ARROW_BAG.Object;
	}

	Show_Arrow->SetCollisionProfileName(TEXT("NoCollision"));
	Weapon_Shield->getWeaponMesh()->SetCollisionProfileName(TEXT("NeCollision"));
	Weapon_Arrows = AWeapon_Arrow::StaticClass();
	//Weapon_ShieldClass = AWeapon_Shield::StaticClass();
	//Weapon_BowClass = AWeapon_Equip::StaticClass();
	ArrowCount = 6;
}

void APlayerWeapon::BeginPlay()
{
	Super::BeginPlay();
	ArrowBag = GetWorld()->SpawnActor<AActor>(ArrowBagBP, FVector::ZeroVector, FRotator::ZeroRotator);
	//Weapon_Shield = GetWorld()->SpawnActor<AWeapon_Shield>(Weapon_ShieldClass, FVector::ZeroVector, FRotator::ZeroRotator);
	//Weapon_Shield->setShieldMesh(TEXT("/Game/OBJECT/Shield/Deku_Shield_model.Deku_Shield_model"));
	//Weapon_Shield->getShieldMesh()->SetCollisionProfileName(TEXT("PlayerWeapon"));

	//Weapon_Bow = GetWorld()->SpawnActor<AWeapon_Bow>(Weapon_BowClass, FVector::ZeroVector, FRotator::ZeroRotator);
	//Weapon_Bow->setShieldMesh(TEXT("/Game/OBJECT/Bow/Bow/Travellers_Bow.Travellers_Bow"));
	//Weapon_Bow->getBowMesh()->SetCollisionProfileName(TEXT("PlayerWeapon"));
}

void APlayerWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerWeapon::setWeaponComponent(E_Weapon Weapon, USkeletalMeshComponent * MeshComponent, const TCHAR * Socket)
{
	switch (Weapon) {
	case E_Weapon::Weapon_BOW:
		Weapon_Bow->getWeaponMesh()->AttachToComponent(MeshComponent, FAttachmentTransformRules::SnapToTargetIncludingScale, Socket);
		if (IsValid(Weapon_Sword)) {
			Weapon_Sword->getWeaponMesh()->AttachToComponent(MeshComponent, FAttachmentTransformRules::KeepWorldTransform, TEXT("LeftUpLegSocket"));
			Weapon_Sword->getWeaponMesh()->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
			Weapon_Sword->getWeaponMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -10.0f));
		}
		Weapon_Shield->getWeaponMesh()->AttachToComponent(MeshComponent, FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("PlayerBackStorage"));
		Weapon_Shield->getWeaponMesh()->SetRelativeScale3D(FVector(0.015f, 0.015f, 0.015f));
		Weapon_Shield->getWeaponMesh()->SetRelativeRotation(FRotator(180.0f, 180.0f, 0.0f));
		Weapon_Shield->getWeaponMesh()->SetRelativeLocation(FVector(20.0f, -2.0f, 0.0f));
		break;
	case E_Weapon::Weapon_SWORD:
		Weapon_Bow->getWeaponMesh()->AttachToComponent(MeshComponent, FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("PlayerBackStorage"));
		if (IsValid(Weapon_Sword)) {
			Weapon_Sword->getWeaponMesh()->AttachToComponent(MeshComponent, FAttachmentTransformRules::KeepWorldTransform, Socket);
			Weapon_Sword->getWeaponMesh()->SetRelativeRotation(FRotator(180.0f, 0.0f, -60.0f));
			Weapon_Sword->getWeaponMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		}
		break;
	case E_Weapon::Weapon_SHIELD:
		Weapon_Shield->getWeaponMesh()->AttachToComponent(MeshComponent, FAttachmentTransformRules::SnapToTargetIncludingScale, Socket);
		Weapon_Shield->getWeaponMesh()->SetRelativeScale3D(FVector(0.015f, 0.015f, 0.015f));
		Weapon_Shield->getWeaponMesh()->SetRelativeRotation(FRotator(140.0f, 120.0f, 80.0f));
		Weapon_Shield->getWeaponMesh()->SetRelativeLocation(FVector(10.0f, -10.0f, 10.0f));
		break;
	case E_Weapon::Weapon_ARROW_BAG:
		ArrowBag->AttachToComponent(MeshComponent, FAttachmentTransformRules::SnapToTargetIncludingScale, Socket);
		ArrowBag->SetActorRelativeScale3D(FVector(0.4f, 0.4f, 0.4f));
		ArrowBag->SetActorRelativeLocation(FVector(0.0f, -2.0f, 0.0f));
		break;
	case E_Weapon::Weapon_None:
		if (IsValid(Weapon_Sword)) {
			Weapon_Sword->getWeaponMesh()->AttachToComponent(MeshComponent, FAttachmentTransformRules::KeepWorldTransform, TEXT("LeftUpLegSocket"));
			Weapon_Sword->getWeaponMesh()->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
			Weapon_Sword->getWeaponMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -10.0f));
		}
		Weapon_Shield->getWeaponMesh()->AttachToComponent(MeshComponent, FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("PlayerBackStorage"));
		Weapon_Shield->getWeaponMesh()->SetRelativeScale3D(FVector(0.015f, 0.015f, 0.015f));
		Weapon_Shield->getWeaponMesh()->SetRelativeRotation(FRotator(180.0f, 180.0f, 0.0f));
		Weapon_Shield->getWeaponMesh()->SetRelativeLocation(FVector(20.0f, -2.0f, 0.0f));

		break;
	}
}

void APlayerWeapon::FireArrow(FVector location, FRotator Rotation, FVector Forward)
{
	if (ArrowCount > 0) {
		Show_Arrow->SetVisibility(false);
		ArrowCount--;
		auto Arrow = GetWorld()->SpawnActor<AWeapon_Arrow>(Weapon_Arrows, location, Rotation);
		if (Arrow) {
			FVector NewVelocity = Forward * 1000.0f;
			Arrow->setVelocity(NewVelocity);
			Arrow->setHitEnemy(true);
		}
		auto PlayerController = Cast< APlayerCharacterController>(GetWorld()->GetFirstPlayerController());
		auto PlayerUI = PlayerController->getPlayerCharacter()->getPlayerCamera()->getPlayerUI();

		PlayerUI->SetArrowCount(ArrowCount);
	}
}

void APlayerWeapon::ShowArrowLocationRotation(FVector Location, FRotator Rotation, bool aimOnOFf)
{
	if (aimOnOFf && ArrowCount > 0)
	{
		Show_Arrow->SetVisibility(aimOnOFf);
		Show_Arrow->SetRelativeLocation(Location);
		Show_Arrow->SetRelativeRotation(Rotation + FRotator(0.0f, -90.0f, 0.0f));
	}
}

bool APlayerWeapon::getWeaponVisible(E_Weapon Weapon)
{
	bool answer = false;
	switch (Weapon) {
	case E_Weapon::Weapon_BOW:
		answer = Weapon_Bow->getWeaponMesh()->IsVisible();
		break;
	}
	return answer;
}

void APlayerWeapon::setWeaponVisible(E_Weapon Weapon, bool check)
{
	switch (Weapon) {
	case E_Weapon::Weapon_BOW:
		Weapon_Bow->getWeaponMesh()->SetVisibility(check);
		break;
	}
}

void APlayerWeapon::ChangeWeapon(int value)
{
	if (Weapon_Sword) {
		Weapon_Sword->getWeaponMesh()->SetVisibility(false);
	}
	if (value == 1) {
		if (Weapon_SwordList.Num() - 1 > WeaponSwordNum) {
			WeaponSwordNum++;
		}
		else {
			WeaponSwordNum = 0;
		}
	}
	else if (value == 0) {
		if (0 == WeaponSwordNum && Weapon_SwordList.Num() > 0) {
			WeaponSwordNum = Weapon_SwordList.Num() - 1;
		}
		else {
			WeaponSwordNum--;
		}

	}
	Weapon_Sword = Weapon_SwordList[WeaponSwordNum];
	Weapon_Sword->getWeaponMesh()->SetCollisionProfileName(TEXT("PlayerWeapon"));
	Weapon_Sword->getWeaponMesh()->SetVisibility(true);

	Weapon_Bow = Weapon_SwordList[WeaponSwordNum];
	Weapon_Bow->getWeaponMesh()->SetCollisionProfileName(TEXT("PlayerWeapon"));
	Weapon_Bow->getWeaponMesh()->SetVisibility(true);

	Weapon_Shield = Weapon_SwordList[WeaponSwordNum];
	Weapon_Shield->getWeaponMesh()->SetCollisionProfileName(TEXT("PlayerWeapon"));
	Weapon_Shield->getWeaponMesh()->SetVisibility(true);

}

void APlayerWeapon::AddSwordList(AWeapon_Equip * sword)
{
	Weapon_SwordList.Add(sword);
}

void APlayerWeapon::AddBowdList(AWeapon_Equip * sword)
{
	Weapon_BowList.Add(sword);
}

void APlayerWeapon::AddShieldList(AWeapon_Equip * sword)
{
	Weapon_ShieldList.Add(sword);
}

bool APlayerWeapon::checkParentComponent(E_Weapon Weapon, const TCHAR * Socket)
{
	bool answer = false;
	FName socketNameString;

	switch (Weapon) {
	case E_Weapon::Weapon_BOW:
		socketNameString = Weapon_Bow->getWeaponMesh()->GetAttachSocketName();
		if (Socket == socketNameString) {
			answer = true;
		}
		break;
	case E_Weapon::Weapon_SWORD:
		if (IsValid(Weapon_Sword)) {
			socketNameString = Weapon_Sword->getWeaponMesh()->GetAttachSocketName();
			if (Socket == socketNameString) {
				answer = true;
			}
		}
		break;
	case E_Weapon::Weapon_SHIELD:
		socketNameString = Weapon_Shield->getWeaponMesh()->GetAttachSocketName();
		if (Socket == socketNameString) {
			answer = true;
		}
		break;
	}
	return answer;
}

