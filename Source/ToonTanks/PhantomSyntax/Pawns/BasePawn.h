// All rights reserved, 2021, Phantom Syntax

#pragma once

#include "CoreMinimal.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

class UCapsuleComponent;
class AProjectileBase;

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();
	virtual void HandleDestruction();

private:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCapsuleComponent* CapsuleComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint;	

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Projectiles", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AProjectileBase> ProjectileClass;

	// Particles
	UPROPERTY(EditAnywhere, Category = "Particles")
	UParticleSystem* DeathParticle;

	// SFX
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sound Effects", meta = (AllowPrivateAccess = "true"))
	USoundBase* DestroySound;
	
protected:
	virtual void RotateTurret(FVector LookAtTarget);
	virtual void Fire();
};
