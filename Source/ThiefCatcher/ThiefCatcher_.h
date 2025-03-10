// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "ThiefCatcher_.generated.h"

/**
 * 
 */
UCLASS()
class THIEFCATCHER_API AThiefCatcher_ : public AMainCharacter
{
	GENERATED_BODY()

public:
    AThiefCatcher_();
	
    UPROPERTY(VisibleAnywhere)
	   USpringArmComponent* SpringArm;

    UPROPERTY(VisibleAnywhere)
	   UCameraComponent* Camera;
	  
};
