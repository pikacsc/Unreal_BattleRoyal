// Copyrights JasonChoi(SEONG_CHAN) 2019

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPP_PlayerBaseCharacter.generated.h"

UCLASS(config = Game)
class BATTLEROYAL_API ACPP_PlayerBaseCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* m_CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* m_FollowCamera;

	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent* m_CharacterMesh;

public:
	// Sets default values for this character's properties
	ACPP_PlayerBaseCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float m_fBaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float m_fBaseLookUpRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Control)
	float m_fMoveForward;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Control)
	float m_fMoveRight;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Status)
	bool m_bRifleEquipped;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Status)
	bool m_bAiming;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Status)
	float m_HP;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Mesh)
	UStaticMeshComponent* m_WeaponBack;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Mesh)
	UStaticMeshComponent* m_WeaponRight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Mesh)
	USkeletalMeshComponent* m_Helmet;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Mesh)
	USkeletalMeshComponent* m_Upper;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Mesh)
	USkeletalMeshComponent* m_Lower;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Mesh)
	USkeletalMeshComponent* m_Shoes;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float p_fValue);

	void MoveRight(float p_fValue);

	void TurnAtRate(float p_fRate);

	void LoopUpAtRate(float p_fRate);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



};
