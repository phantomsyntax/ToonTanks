// All rights reserved, 2021, Phantom Syntax

#pragma once

#include "CoreMinimal.h"
#include "ToonTanks/PhantomSyntax/Pawns/BasePawn.h"
#include "PawnTurret.generated.h"

class APawnTank;
// Forward Declarations
struct FTimerHandle;

UCLASS()
class TOONTANKS_API APawnTurret : public ABasePawn
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void RotateTurret(FVector LookAtTarget) override;
	virtual void Fire() override;
	
public:
	APawnTurret();

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void HandleDestruction() override;

private:
	FTimerHandle FireRateTimerHandler;
	void CheckFireCondition();
	float ReturnPlayerDistance();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float FireRate = 2.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float FireRange = 500.0f;

	APawnTank* PlayerPawn;
};
