// All rights reserved, 2021, Phantom Syntax


#include "ToonTanks/PhantomSyntax/Components/HealthComponent.h"

#include "Kismet/GameplayStatics.h"
#include "ToonTanks/PhantomSyntax/GameModes/TankGameModeBase.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	Health = DefaultHealth;
	GameModeBase = Cast<ATankGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	// Add delegate to call TakeDamage whenever Owner takes any damage
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::TakeDamage);
	
}

void UHealthComponent::TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (Damage == 0 || Health <= 0.0f)
	{
		return;	
	}

	Health = FMath::Clamp(Health - Damage, 0.0f, DefaultHealth);

	if (Health <= 0.0f)
	{
		if (GameModeBase)
		{
			GameModeBase->ActorDied(GetOwner());	
		}
		else UE_LOG(LogTemp, Error, TEXT("No valid GameMode reference!"));
	}
}