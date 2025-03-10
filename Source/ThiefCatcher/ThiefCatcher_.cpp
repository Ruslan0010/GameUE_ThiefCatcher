// Fill out your copyright notice in the Description page of Project Settings.


#include "ThiefCatcher_.h"

AThiefCatcher_::AThiefCatcher_() : Super()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 500.0f;


	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	Camera->SetupAttachment(SpringArm);

}