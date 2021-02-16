// All rights reserved, 2021, Phantom Syntax


#include "ToonTanks/PhantomSyntax/Pawns/PawnTurret.h"

#include "PawnTank.h"
#include "Kismet/GameplayStatics.h"

APawnTurret::APawnTurret()
{
	
}

// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();
	// Starts firing sequence/timer
	GetWorldTimerManager().SetTimer(FireRateTimerHandler, this, &APawnTurret::CheckFireCondition, FireRate, true);

	// Populate player pawn
	PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
	UE_LOG(LogTemp, Warning, TEXT("%s"), *PlayerPawn->GetName());
	
}

void APawnTurret::RotateTurret(FVector LookAtTarget)
{
	Super::RotateTurret(LookAtTarget);
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (ReturnPlayerDistance() <= FireRange)
	{
		RotateTurret(PlayerPawn->GetActorLocation());
	}
}

void APawnTurret::CheckFireCondition()
{
		UE_LOG(LogTemp, Warning, TEXT("Fire Condition Checked"));

}

float APawnTurret::ReturnPlayerDistance()
{
	return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
}
