// Copyrights JasonChoi(SEONG_CHAN) 2019

#include "BulletMovement.h"

UBulletMovement::UBulletMovement()
{
	InitialSpeed = 3500.f;
	MaxSpeed = 3500.f;

	bInitialVelocityInLocalSpace = true;

	ProjectileGravityScale = 0.05f;
}
