// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

UCLASS()
class THIEFCATCHER_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();


	UPROPERTY(EditDefaultsOnly, Category = "CharacterStamina")
	float CharacterStamina;

	bool bIsTired;


	float GetStaminaPercent();
	float AddStamina();
	float DecreaseStamina();

	bool StaminaIsZero(); //the function that is responsible for the death of a character 

	UPROPERTY(EditDefaultsOnly, Category = "CharacterStamina")
	USoundBase* TiredSound;

	UPROPERTY(EditDefaultsOnly, Category = "CharacterStamina")
	UAnimMontage* VertigoAnimation;

};
