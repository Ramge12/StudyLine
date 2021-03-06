// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "Animation/AnimInstance.h"
#include "ABAnimInstance.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnNextAttackCheckDelegate);
DECLARE_MULTICAST_DELEGATE(FOnAttackHitCheckDelegate);

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UABAnimInstance();
	virtual void NativeUpdateAnimation(float DeltaSeconds)override;
	// 매 Tick마다 호출되는, NativeUpdateAnimation함수, 

	// Pawn에서 instance를 통해 애니메이션을 조절하는 방법
	void SetPawnSpeed(float NewPawnSpeed);

	void PlayAttackMontage();
	// 몽타주를 실행하는 함수

	void JumpToAttackMontageSection(int32 NewSection);
	// 어택 몽타주에서 다음 세선으로 넘어가는 함수
public:
	FOnNextAttackCheckDelegate OnNextAttackCheck;
	FOnAttackHitCheckDelegate OnAttackHitCheck;
	// Delegate에서 호출할 함수

	void SetDeadAnim() { IsDead = true; }
private:
	UFUNCTION()
	void AnimNotify_AttackHitCheck();
	// 노티파이(애니메이션, 몽타주 도중 일정 구간에서 호출되는 함수)

	UFUNCTION()
	void AnimNotify_NextAttackCheck();
	// 노티파이(애니메이션, 몽타주 도중 일정 구간에서 호출되는 함수)

	FName GetAttackMontageSectionName(int32 Section);
	// 현재 Section의 Name을 가져온다.

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	float CurrentPawnSpeed;
	// 1. 에디터에서 수정이 가능하며
	// 2. 블루프린트에서 읽을 수 있고
	// 3. 카테고리는 Pawn
	// 4. private지면 에디터에서 접근할 수 있도록 Meta사용
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	bool IsInAir;
	// 1. 에디터에서 수정이 가능하고
	// 2. 블루프린트에서 읽을 수 있고
	// 3. 카테고리는 Pawn
	// 4. private지면 에디터에서 접근할 수 있도록 Meta사용

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	UAnimMontage* AttackMontage;
	// 1. 블루프린트 크래스 설계도에서만 보여지도록 VisibleDeaultsOnly를 사용
	// 2. 블루프린트에서 읽을 수 있다.
	// 3. 카테고리는 Attack
	// 4. private지만 에디터에서 접근할 수 있도록 Meta사용

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	bool IsDead;
	// 1. 에디터에서 수정이 가능하고
	// 2. 블루프린트에서 읽을 수 있고
	// 3. 카테고리는 Pawn
	// 4. private지면 에디터에서 접근할 수 있도록 Meta사용
	// 5. 죽음을 체크하기 위한 불값
};
