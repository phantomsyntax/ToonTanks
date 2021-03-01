// All rights reserved, 2021, Phantom Syntax


#include "ToonTanks/PhantomSyntax/Actors/ProjectileBase.h"

#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AProjectileBase::AProjectileBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh"));
	// Add delegate to call OnHit when the Component hits another object
	ProjectileMesh->OnComponentHit.AddDynamic(this, &AProjectileBase::OnHit);
	RootComponent = ProjectileMesh;

	BulletTrail = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Projectile Trail"));
	BulletTrail->SetupAttachment(RootComponent);
	
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Component"));
	ProjectileMovement->InitialSpeed = MovementSpeed;
	ProjectileMovement->MaxSpeed = MovementSpeed;

	InitialLifeSpan = 3.0f;	
}

// Called when the game starts or when spawned
void AProjectileBase::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::SpawnSoundAtLocation(this, LaunchSound, GetActorLocation());
}

void AProjectileBase::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	AActor* MyOwner = GetOwner();
	if (!MyOwner)
	{
		return;
	}

	if (OtherActor && OtherActor != this && OtherActor != MyOwner)
	{
		UGameplayStatics::SpawnSoundAtLocation(this, HitSound, GetActorLocation());
		UGameplayStatics::ApplyDamage(OtherActor, Damage, MyOwner->GetInstigatorController(), this, DamageType);
		UGameplayStatics::SpawnEmitterAtLocation(this, HitParticle, GetActorLocation());
		Destroy();
	}
}
