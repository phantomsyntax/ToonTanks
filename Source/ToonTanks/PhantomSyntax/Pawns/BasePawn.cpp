// All rights reserved, 2021, Phantom Syntax


#include "ToonTanks/PhantomSyntax/Pawns/BasePawn.h"

#include "Kismet/GameplayStatics.h"
#include "ToonTanks/PhantomSyntax/Actors/ProjectileBase.h"

// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Add capsule, mesh and projectile spawn components
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComponent;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(RootComponent);
	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);
}

void ABasePawn::RotateTurret(FVector LookAtTarget)
{
	FVector Target = {LookAtTarget.X, LookAtTarget.Y, TurretMesh->GetComponentLocation().Z};
	FVector StartLocation = TurretMesh->GetComponentLocation();
	FRotator TurretRotation = FVector(Target - StartLocation).Rotation();
	TurretMesh->SetWorldRotation(TurretRotation);
}

void ABasePawn::Fire()
{
	if (ProjectileClass)
	{
		FVector ProjectileLocation = ProjectileSpawnPoint->GetComponentLocation();
		FRotator ProjectileRotation = ProjectileSpawnPoint->GetComponentRotation();
		AProjectileBase* TempProjectile = GetWorld()->SpawnActor<AProjectileBase>(ProjectileClass, ProjectileLocation, ProjectileRotation);
		TempProjectile->SetOwner(this);
	}
	// Shoot behavior
	UE_LOG(LogTemp, Warning, TEXT("Fire!"));
}

void ABasePawn::HandleDestruction()
{
	UGameplayStatics::SpawnSoundAtLocation(this, DestroySound, GetActorLocation());
	// Universal (s)pawn death particle
	UGameplayStatics::SpawnEmitterAtLocation(this, DeathParticle, GetActorLocation());
}
