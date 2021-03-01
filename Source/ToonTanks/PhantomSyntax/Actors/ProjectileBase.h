// All rights reserved, 2021, Phantom Syntax

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileBase.generated.h"

class UProjectileMovementComponent;

UCLASS()
class TOONTANKS_API AProjectileBase : public AActor
{
	GENERATED_BODY()

	
public:	
	// Sets default values for this actor's properties
	AProjectileBase();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))	
	UProjectileMovementComponent* ProjectileMovement;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* ProjectileMesh;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float MovementSpeed = 250.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage", meta = (AllowPrivateAccess = "true"))
	float Damage = 50.0f;
	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	TSubclassOf<UDamageType> DamageType;

	// Particles
	UPROPERTY(EditAnywhere, Category = "Effects")
	UParticleSystem* HitParticle;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effects", meta = (AllowPrivateAccess = "true"))
	UParticleSystemComponent* BulletTrail;

	// SFX
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sound Effects", meta = (AllowPrivateAccess = "true"))
	USoundBase* LaunchSound;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sound Effects", meta = (AllowPrivateAccess = "true"))
	USoundBase* HitSound;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// From PrimitiveComponent.h to be used with Dynamic Delegate - DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_FiveParams
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};