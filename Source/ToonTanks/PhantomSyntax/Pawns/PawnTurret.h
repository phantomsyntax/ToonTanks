// All rights reserved, 2021, Phantom Syntax

#pragma once

#include "CoreMinimal.h"
#include "ToonTanks/PhantomSyntax/Pawns/BasePawn.h"
#include "PawnTurret.generated.h"

// Forward Declarations
struct FTimerHandle;

UCLASS()
class TOONTANKS_API APawnTurret : public ABasePawn
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:
	APawnTurret();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FTimerHandle FireRateTimerHandler;
	void CheckFireCondition();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float FireRate = 2.0f;
};
