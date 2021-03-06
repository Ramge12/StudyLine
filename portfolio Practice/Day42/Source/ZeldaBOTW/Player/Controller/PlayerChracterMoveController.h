#pragma once

#include "ZeldaBOTW.h"
#include "GameFramework/PlayerController.h"
#include "PlayerChracterMoveController.generated.h"

UCLASS()
class ZELDABOTW_API APlayerChracterMoveController : public APlayerController
{
	GENERATED_BODY()
private:
	class APlayerCharacter* PlayerCharacter;
	class UPlayerCharacterState* PlayerCharacterState;
	class UPlayerTrace* PlayerTrace;

private:
	bool IsClimming;
	bool IsJump;
	bool IsMove;
	bool IsPush;
	float playerSpeed = 0.0f;
	float playerCurSpeed = 0.0f;
public:
	APlayerChracterMoveController();
	
	virtual void Tick(float DeltaTime) override;
	void PlayerMoveSetting(class APlayerCharacter* Character, class UPlayerCharacterState* Sate, class UPlayerTrace* Trace);
	void KeyDownCheck();

	void PlayerStaminCheck();
	void PlayerJumpCheck();

	void PlayerJump();

	void PlayerRunStart();
	void PlayerRunStop();

	void PlayerCrouch();
	void PlayerUnCrouch();

	void PlayerTracePushCheck();
	void PlayerPushStart();
	void PlayerPushEnd();

	void PlayerTraceClimmingCheck();
	void PlayerClimmingStart();
	void PlayerClimmingEnd();

	void PlayerExtraState();

	bool getIsMove() { return IsMove; }
	bool getIsClimming() { return IsClimming; }
	float getCurSpeed() { return playerCurSpeed; }
	void setIsMoveValue(bool value) { IsMove = value; }
	void setIIsClimmingValue(bool value) { IsClimming = value; }
};
