// All rights reserved, 2021, Phantom Syntax

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TankGameModeBase.generated.h"

class APawnTurret;
class APawnTank;
class APlayerControllerBase;

UCLASS()
class TOONTANKS_API ATankGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:
	void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Loop")
	int32 StartDelay = 3;
	
	UFUNCTION(BlueprintImplementableEvent)
	void GameStart();
	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool PlayerWon);
	
private:
	void HandleGameStart();
	void HandleGameOver(bool PlayerWon);

	APawnTank* PlayerTank;
	int32 TargetTurrets;
	APlayerControllerBase* PlayerControllerRef;
	FTimerHandle PlayerEnableHandle;
	

public:
	void ActorDied(AActor* DeadActor);

};
