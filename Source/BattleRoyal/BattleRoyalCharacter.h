// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BattleRoyalCharacter.generated.h"

UCLASS(config=Game)
class ABattleRoyalCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

public:
	ABattleRoyalCharacter();

	virtual void BeginPlay() override;


	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera)
	float ForwardValue;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera)
	float RightValue;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Status)
	float HP;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Status)
	bool RifleEquipped;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Status)
	bool Aiming;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Character)
	UStaticMeshComponent* WeaponBack;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Character)
	UStaticMeshComponent* WeaponRight;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Character)
	USkeletalMeshComponent* Helmet;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Character)
	USkeletalMeshComponent* Shirt;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Character)
	USkeletalMeshComponent* Pants;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Character)
	USkeletalMeshComponent* Shoes;


protected:

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);
protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

