// All rights reserved, 2021, Phantom Syntax


#include "ToonTanks/PhantomSyntax/GameModes/TankGameModeBase.h"

#include "Kismet/GameplayStatics.h"
#include "ToonTanks/PhantomSyntax/Pawns/PawnTank.h"
#include "ToonTanks/PhantomSyntax/Pawns/PawnTurret.h"


void ATankGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	HandleGameStart();
}

void ATankGameModeBase::HandleGameStart()
{
	// Build array of all the Turrets in the world/scene
	TArray<AActor*> TurretActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APawnTurret::StaticClass(), TurretActors);
	TargetTurrets = TurretActors.Num();

	PlayerTank = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));

	GameStart();
}

void ATankGameModeBase::HandleGameOver(bool PlayerWon)
{
	GameOver(PlayerWon);
}

void ATankGameModeBase::ActorDied(AActor* DeadActor)
{
	if (DeadActor == PlayerTank)
	{
		PlayerTank->HandleDestruction();
		HandleGameOver(false);
	}
	else if (APawnTurret* DeadTurret = Cast<APawnTurret>(DeadActor))
	{
		DeadTurret->HandleDestruction();
		if (--TargetTurrets == 0)
		{
			HandleGameOver(true);	
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("%s has died."), *DeadActor->GetName());
}
