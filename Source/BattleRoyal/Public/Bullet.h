// Copyrights JasonChoi(SEONG_CHAN) 2019

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

class UBulletMovement;

UCLASS()
class BATTLEROYAL_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void LaunchBullet(float p_fSpeed);


private:
	UBulletMovement* m_pBulletMovement = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* m_pCollisionMesh = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UParticleSystemComponent* m_pHitImpact = nullptr;
	
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float				m_fProjectileDamage = 20.f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float				m_fDestroyDelay = 10.f;


	UFUNCTION()
	void OnHit(UPrimitiveComponent * HitComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit);

	UFUNCTION()
	void OnTimerExpire();
};
