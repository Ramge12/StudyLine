// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ZeldaBOTW.h"
#include "Weapon/Weapon_Arrow.h"
#include "Weapon/Weapon_Equip.h"
#include "GameFramework/Actor.h"
#include "PlayerWeapon.generated.h"
#define ArrowNum 6

UENUM()
enum class E_Weapon : uint8 {
	Weapon_None			UMETA(DisplayName = "Weapon_NONE"),
	Weapon_BOW			UMETA(DisplayName = "Weapon_BOW"),
	Weapon_ARROW_BAG	UMETA(DisplayName = "Weapon_ARROW_BAG"),
	Weapon_SWORD		UMETA(DisplayName = "Weapon_SWORD"),
	Weapon_SHIELD		UMETA(DisplayName = "Weapon_SHIELD")
};

UCLASS()
class ZELDABOTW_API APlayerWeapon : public AActor
{
	GENERATED_BODY()

private:
	int32 ArrowCount = 6;

public:
	UPROPERTY(VisibleAnywhere, Category = Weapon)
	AWeapon_Equip*  Weapon_Bow;
	UPROPERTY(VisibleAnywhere, Category = Weapon)
	TArray<AWeapon_Equip*> Weapon_BowList;

	UPROPERTY(VisibleAnywhere, Category = Weapon)
	AWeapon_Equip*  Weapon_Shield;
	UPROPERTY(VisibleAnywhere, Category = Weapon)
	TArray<AWeapon_Equip*> Weapon_ShieldList;

	UPROPERTY(EditAnywhere, Category = Weapon)
	TArray<AWeapon_Equip*> Weapon_SwordList;
	UPROPERTY(VisibleAnywhere, Category = Weapon)
	AWeapon_Equip* Weapon_Sword;

	UPROPERTY(VisibleAnywhere, Category = Weapon)
	USkeletalMeshComponent*  ArrowBag;
	//UPROPERTY(VisibleAnywhere, Category = Weapon)
	//USkeletalMeshComponent*  ArrowBagBP;

	UPROPERTY(VisibleAnywhere, Category = Weapon)
	UStaticMeshComponent* Show_Arrow;
	UPROPERTY(VisibleAnywhere, Category = Weapon)
	TSubclassOf<class AWeapon_Arrow> Weapon_Arrows;

	UPROPERTY(VisibleAnywhere, Category = Weapon)
	int32 WeaponSwordNum = 0;
	UPROPERTY(VisibleAnywhere, Category = Weapon)
	int32 WeaponShieldNum = 0;
	UPROPERTY(VisibleAnywhere, Category = Weapon)
	int32 WeaponBowNum = 0;
public:	
	APlayerWeapon();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	void setWeaponComponent(E_Weapon Weapon, USkeletalMeshComponent* MeshComponent, const TCHAR * Socket);
	void FireArrow(FVector location, FRotator Rotation, FVector Forward);

	void ShowArrowLocationRotation(FVector Location, FRotator Rotation, bool aimOnOFf);

	bool getWeaponVisible(E_Weapon Weapon);
	void setWeaponVisible(E_Weapon Weapon, bool check);

	void ChangeWeapon(E_Weapon weaponType,bool Upvalue);
	void AddSwordList(AWeapon_Equip* sword);
	void AddBowdList(AWeapon_Equip* sword);
	void AddShieldList(AWeapon_Equip* sword);

	bool checkParentComponent(E_Weapon Weapon, const TCHAR * Socket);

	AWeapon_Equip* getPlayerSworld() { return Weapon_Sword; }
	TArray<AWeapon_Equip*> getPlayerBowList() { return Weapon_BowList; }
	TArray<AWeapon_Equip*> getPlayerSwordList() { return Weapon_SwordList; }
	TArray<AWeapon_Equip*> getPlayerShieldList() { return Weapon_ShieldList; }
};
