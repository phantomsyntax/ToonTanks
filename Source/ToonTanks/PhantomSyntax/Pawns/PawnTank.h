// All rights reserved, 2021, Phantom Syntax

#pragma once

#include "CoreMinimal.h"


#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "ToonTanks/PhantomSyntax/Pawns/BasePawn.h"
#include "PawnTank.generated.h"

// Forward Declarations
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class TOONTANKS_API APawnTank : public ABasePawn
{
	GENERATED_BODY()
	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Fire() override;

public:
	APawnTank();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
private:
	// Camera and Springarm
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera Components", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArmComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* PlayerCamera;

	void CalculateMovement(float Value);
	void CalculateRotation(float Value);
	void Move();
	void Rotate();

	FVector MoveDirection;
	FQuat RotationDirection;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Components", meta = (AllowPrivateAccess = "true"))
	float MoveSpeed = 150.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Components", meta = (AllowPrivateAccess = "true"))
	float RotateSpeed = 100.0f;
	
};
