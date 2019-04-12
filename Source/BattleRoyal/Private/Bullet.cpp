// Copyrights JasonChoi(SEONG_CHAN) 2019

#include "Bullet.h"
#include "Components/StaticMeshComponent.h"
#include "ParticleDefinitions.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"
#include "BattleRoyal/Public/BulletMovement.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	m_pCollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Collision Mesh"));
	SetRootComponent(m_pCollisionMesh);
	m_pCollisionMesh->SetNotifyRigidBodyCollision(true);
	m_pCollisionMesh->SetVisibility(true);

	m_pBulletMovement = CreateDefaultSubobject<UBulletMovement>(FName("Bullet Movement"));
	m_pBulletMovement->bAutoActivate = false;

	m_pHitImpact = CreateDefaultSubobject<UParticleSystemComponent>(FName("Hit Impact"));
	m_pHitImpact->SetupAttachment(m_pCollisionMesh);
	m_pHitImpact->bAutoActivate = false;
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	m_pCollisionMesh->OnComponentHit.AddDynamic(this, &ABullet::OnHit);
}

void ABullet::LaunchBullet(float p_fSpeed)
{
	m_pBulletMovement->SetVelocityInLocalSpace(FVector::ForwardVector* p_fSpeed);
	m_pBulletMovement->Activate();
}

void ABullet::OnHit(UPrimitiveComponent * HitComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
{
	m_pHitImpact->Activate();

	SetRootComponent(m_pHitImpact);
	m_pCollisionMesh->DestroyComponent();

	FTimerHandle l_Timer;
	GetWorld()->GetTimerManager().SetTimer(l_Timer, this, &ABullet::OnTimerExpire, m_fDestroyDelay, false);
}

void ABullet::OnTimerExpire()
{
	Destroy();
}


