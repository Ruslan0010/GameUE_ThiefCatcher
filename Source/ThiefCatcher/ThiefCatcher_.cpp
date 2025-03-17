// Fill out your copyright notice in the Description page of Project Settings.


#include "ThiefCatcher_.h"

AThiefCatcher_::AThiefCatcher_() : Super()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 500.0f;


	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	Camera->SetupAttachment(SpringArm);


	SpringArm->bUsePawnControlRotation = true;
	Camera->bUsePawnControlRotation = false;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}

void AThiefCatcher_::SetupPlayerInputComponent(UInputComponent* MyPlayerInput)
{
	Super::SetupPlayerInputComponent(MyPlayerInput);

	MyPlayerInput->BindAxis("MoveForwardBackward", this, &AThiefCatcher_::MoveForwardBackward);
	MyPlayerInput->BindAxis("MoveRightLeft", this, &AThiefCatcher_::MoveRightLeft);

	MyPlayerInput->BindAxis("Turn", this, &AThiefCatcher_::AddControllerYawInput);
	MyPlayerInput->BindAxis("LookUpDown", this, &AThiefCatcher_::AddControllerPitchInput);

	MyPlayerInput->BindAction("Jump", IE_Pressed, this, &AThiefCatcher_::Jump);
	MyPlayerInput->BindAction("Jump", IE_Released, this, &AThiefCatcher_::StopJump);


}

void AThiefCatcher_::MoveForwardBackward(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);

}

void AThiefCatcher_::MoveRightLeft(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);

}

void AThiefCatcher_::Jump()
{
	bPressedJump = true;
}

void AThiefCatcher_::StopJump()
{
	bPressedJump = false;
}
