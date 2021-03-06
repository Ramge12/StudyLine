// Fill out your copyright notice in the Description page of Project Settings.

#include "ABCharacter.h"


// Sets default values
AABCharacter::AABCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));
	// 각가의 컴포넌트 에서 새롭게 만듭니다.

	SpringArm->SetupAttachment(GetCapsuleComponent());
	// SpringArm을 Capsule의 자식으로 넣습니다.
	Camera->SetupAttachment(SpringArm);
	// Camera를 SpringArm의 자식으로 넣습니다.

	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f),FRotator(0.0f,-90.0f,0.0f));
	// Mesh의 초기 위치와 회전값을 조저합니다.
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->SetRelativeRotation(FRotator(-15.0f, 0.0f, 0.0f));
	// SpringArm의 길이와 회전값을 조정합니다.

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_CARDBOAD(TEXT("/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Cardboard.SK_CharM_Cardboard"));
	if (SK_CARDBOAD.Succeeded()) {
		GetMesh()->SetSkeletalMesh(SK_CARDBOAD.Object);
		// 사용할 SkeletaMesh 경로정보를 불러오며, 불러오는데 성공했다면, Mesh에 적용합니다.
	}
	
	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	// Mesh에 AnimationBlueprint(블루프린트를 사용하는 애니메이션 조절)을 생성합니다.
	static ConstructorHelpers::FClassFinder<UAnimInstance>WARRIOR_ANIM(TEXT("/Game/Book/Animation/WarriorAnimBlueprint.WarriorAnimBlueprint_C"));
	if (WARRIOR_ANIM.Succeeded()) {
		GetMesh()->SetAnimInstanceClass(WARRIOR_ANIM.Class);
		// 사용할 UAnimInstance 경로정보를 불러오며, 불러오는데 성공했다면, Mesh에 적용합니다.
	}
	
	SetControlMode(EControlMode::DIABLO);
	// 컨트롤 모드의 초기값으로 DIABLO을 줍니다.

	ArmLengthSpeed = 3.0f;
	// 팔을 바꾸는 속도 3
	ArmRotationSpeed = 10.0f;
	// 파을 회전시키는 속도 10

	GetCharacterMovement()->JumpZVelocity = 800.0f;
	// CharacterMovement의 점프 값을 800으로 바꾸어줍니다.
}

// Called when the game starts or when spawned
void AABCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AABCharacter::SetControlMode(int32 ControlMode)
{
	if (ControlMode == 0) {
		// SpringArm : 카메라 지지대에 관한 설정
		SpringArm->TargetArmLength = 450.0f;
		// SpringArm의 타겟으로 부터의 거리 450
		SpringArm->SetRelativeRotation(FRotator::ZeroRotator);
		// SpringArm의 초기 회전값 Zero
		SpringArm->bUsePawnControlRotation = true;
		// SpringArm의 Pawn에서의 회전 사용여부 true
		SpringArm->bInheritRoll = true;
		SpringArm->bInheritPitch = true;
		SpringArm->bInheritYaw = true;
		// Roll = X축 , Pitch = Y축, Yaw = Z축 회전값 사용 여부 모두 True
		SpringArm->bDoCollisionTest = true;
		// SPringArm이 충돌시 카메라를 장애물 앞으로 줌인한다.
		bUseControllerRotationYaw = false;
		// 컨트롤러의 Z출 회전을 사용하지않습니다.

		GetCharacterMovement()->bOrientRotationToMovement = true;
		// 캐릭터를 자동으로 회전시켜주는 OrientRotationToMovement를 사용합니다.
		GetCharacterMovement()->RotationRate = FRotator(0.0f,720.0f, 0.0f);
		// 캐릭터를 회전할 속도
	}
}

void AABCharacter::SetControlMode(EControlMode NewControlMode)
{
	CurrentControlMode = NewControlMode;
	// CurrentControlMode에 입력된 값을 저장합니다.
	switch (CurrentControlMode) {
	case EControlMode::GTA:
		/*SpringArm->TargetArmLength = 450.0f;
		SpringArm->SetRelativeRotation(FRotator::ZeroRotator);*/
		ArmLengthTo = 450.0f;
		// 팔의 길이를 450으로 바꿉니다.
		SpringArm->bUsePawnControlRotation = true;
		SpringArm->bInheritRoll = true;
		SpringArm->bInheritPitch = true;
		SpringArm->bInheritYaw = true;
		SpringArm->bDoCollisionTest = true;
		bUseControllerRotationYaw = false;

		GetCharacterMovement()->bOrientRotationToMovement = true;
		GetCharacterMovement()->bUseControllerDesiredRotation = false;
		// bUseControllerDesiredRotation 를 체크하면 컨트롤 회전이 가리키는 방향으로 부드럽게 회전한다.
		// GTA모드에서는 별도의 회전값을 가지기 떄문에 체크하지 않는다.
		GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);
		break;
	case EControlMode::DIABLO:
		/*SpringArm->TargetArmLength = 800.0f;
		SpringArm->SetRelativeRotation(FRotator(-45.0f,0.0f,0.0f));*/
		ArmLengthTo = 800.0f;
		//팔의 길이를 800으로 바꿉니다
		ArmRotationTo = FRotator(-45.0f, 0.0f, 0.0f);
		// 팔의 회전 초기값을 -45로 잡습니다.
		SpringArm->bUsePawnControlRotation = false;
		// SpringArm의 Pawn에서의 회전 사용여부 false
		SpringArm->bInheritRoll = false;
		SpringArm->bInheritPitch = false;
		SpringArm->bInheritYaw = false;
		// Roll = X축 , Pitch = Y축, Yaw = Z축 회전값 사용 여부 모두 false
		SpringArm->bDoCollisionTest = false;
		// SPringArm이 충돌시 카메라를 장애물 앞으로 줌인하지않는다.
		bUseControllerRotationYaw = false;
		// 컨트롤러의 Z출 회전을 사용하지 않습니다

		GetCharacterMovement()->bOrientRotationToMovement = false;
		// 캐릭터를 자동으로 회전시켜주는 OrientRotationToMovement를 사용하지 않는다.
		GetCharacterMovement()->bUseControllerDesiredRotation = true;
		// bUseControllerDesiredRotation 를 체크해제하면 컨트롤 회전이 가리키는 방향으로 부드럽게 회전한다.
		GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);
		// 회전속도를 지정해줍니다.
		break;
	}
}

// Called every frame
void AABCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SpringArm->TargetArmLength = FMath::FInterpTo(SpringArm->TargetArmLength, ArmLengthTo, DeltaTime, ArmLengthSpeed);
	//SrpingArm의 길이는 현재 SpringArm의 길이부터 ArmLengthTo의 길이까지 DeltaTime주기로 바뀐다.

	switch (CurrentControlMode) {
	case EControlMode::DIABLO:
		SpringArm->RelativeRotation = FMath::RInterpTo(SpringArm->RelativeRotation, ArmRotationTo, DeltaTime, ArmRotationSpeed);
		// SptringArm의 회전값은 DIABLO모드일때만 회전하며, 현재 SpringArm의 회전갑셍서 ArmRotationTo의 값으로
		// DeltaTime에 따라 서서히 바뀐다.
		break;
	}

	switch (CurrentControlMode) {
	case EControlMode::DIABLO:
		if (DirectionToMove.SizeSquared() > 0.0f) {
			GetController()->SetControlRotation(FRotationMatrix::MakeFromX(DirectionToMove).Rotator());
			AddMovementInput(DirectionToMove);
			// 디아브로 모드 일때
			// DirectionToMove.SizeSquared() => 입력값의 크기가 0보다 크다면
			// DirectionToMove에 캐릭터의 이동 벡터를 담고
			// 카메라가 DirectionToMode를 향해 움직입니다.
		}
		break;
	}
	
	//// Pawn에서 instance를 통해 애니메이션을 조절하는 방법
	//auto ABAnimInstance = Cast<UABAnimInstance>(GetMesh()->GetAnimInstance());
	//if (nullptr != ABAnimInstance) {
	//	ABAnimInstance->SetPawnSpeed(GetVelocity().Size());
	//	// 인스탄스에 Pawn의 정보를 넘긴다.
	//}

}

// Called to bind functionality to input
void AABCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("ViewChange"), EInputEvent::IE_Pressed, this, &AABCharacter::ViewChange);
	// 버튼이 눌렀는지(IE_Pressed)안 눌렀는지(IE_Released)에 대한 체크를 할 수 있다.

	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &AABCharacter::Jump);
	// 액션 이벤트에 존재하는 점프를 검사합니ㅏ.

	PlayerInputComponent->BindAction(TEXT("Attack"), EInputEvent::IE_Pressed, this, &AABCharacter::Attack);

	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AABCharacter::UpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AABCharacter::LeftRight);
	// InputComponent의 값을 AABCharactor의 UpDown과 LeftRight 함수에 준다.

	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AABCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AABCharacter::Turn);
	// InputComponent의 값을 AABCharacter의 LookUp과 Turn에 줍니다.
}

void AABCharacter::UpDown(float NewAxisValue)
{
	switch (CurrentControlMode) {
	case EControlMode::GTA:
		AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::X), NewAxisValue);
		// 입력받은 NewAxisVlaue의 값으로 캐릭터의 전, 후 방향으로 움직입니다.
		// 캐릭터의 이동방향 ControlRotation의 값을 사용해
		// 마우스의 회전값을 계산하여 캐릭터를 이동벡터를 회전시킵니다.(캐릭터 모델은 회전하지 않습니다)
		break;
	case EControlMode::DIABLO:
		DirectionToMove.X = NewAxisValue;
		// 입력받은 NewXisValue의 값을 DirectionToMove.X에게 줍니다
		break;
	}
}

void AABCharacter::LeftRight(float NewAxisValue)
{
	switch (CurrentControlMode) {
	case EControlMode::GTA:
		AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::Y), NewAxisValue);
		// 입력받은 NewAxisValue의 값으로 캐릭터의 좌우 방향으로 움직입니다.
		// 캐릭터의 이동방향 ControlRotation의 값을 사용해
		// 마우스의 회전값을 계산하여 캐릭터를 이동벡터를 회전시킵니다.(캐릭터 모델은 회전하지 않습니다)
		break;
	case EControlMode::DIABLO:
		DirectionToMove.Y = NewAxisValue;
		// 입력받은 NewXisValue의 값을 DirectionToMove.Y에게 줍니다
		break;
	}
}

void AABCharacter::LookUp(float NewAxisValue)
{
	switch (CurrentControlMode) {
	case EControlMode::GTA:
		AddControllerPitchInput(NewAxisValue);
		// 컨트롤러에 NewAxisValue의 값을 줍니다.
		break;
	}
}

void AABCharacter::Turn(float NewAixsValue)
{
	switch (CurrentControlMode) {
	case EControlMode::GTA:
		AddControllerYawInput(NewAixsValue);
		// 컨트롤러에 newAxisValue의 값을 주어 회전시킵니다.
		break;
	}
}

void AABCharacter::ViewChange()
{
	switch (CurrentControlMode) {
	case EControlMode::GTA:
		GetController()->SetControlRotation(GetActorRotation());
		// GTA에서 DIABLO모드로 바뀌는 경우
		// 컨트롤러의 회전값을 Actor의 회전값으로 바꾼다.
		SetControlMode(EControlMode::DIABLO);
		// 현재 게임모드가 GTA일 경우 DIABLO로 바꾼다.
		break;
	case EControlMode::DIABLO:
		GetController()->SetControlRotation(SpringArm->RelativeRotation);
		// DIABLO에서 GTA로 바꾸는 경우
		// 컨트롤러의 회전값을 SpringArm의 회전값으로 바꿉니다.
		SetControlMode(EControlMode::GTA);
		// 현재 게임모드가 DIABLO일경우 GTA로 바꾼다.
		break;
	}
}

void AABCharacter::Attack()
{
	//ABLOG_S(Warning);
	auto AnimInstance = Cast<UABAnimInstance>(GetMesh()->GetAnimInstance());
	// AnimInstance를 불러옵니다.
	if (nullptr == AnimInstance)return;
	//없을 경우 그냥 return
	AnimInstance->PlayAttackMontage();
	// Instance가 있다면 재생합니다.
}

