// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "EnhancedInputComponent.h"
#include "CPP_Sphere_feu.h"
#include "CPP_Mon_Personnage.generated.h"

UCLASS()
class RV2_JEUBP_API ACPP_Mon_Personnage : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACPP_Mon_Personnage();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION()
	void Sauter();

	UFUNCTION()
	void StopSauter();

	UFUNCTION()
	void BougerGaucheDroite(const FInputActionValue& Value);

	UFUNCTION()
	void BougerAvantArriere(const FInputActionValue& Value);

	UFUNCTION()
	void RegarderGaucheDroite(const FInputActionValue& Value);

	UFUNCTION()
	void RegarderAvantArriere(const FInputActionValue& Value);

	UFUNCTION()
	void LancerboulleFeu();



	UPROPERTY(EditAnywhere, Category = " Yassine")
	UInputMappingContext* imccontext;

	UPROPERTY(EditAnywhere, Category = " Yassine")
	UInputAction* iaSauter;

	UPROPERTY(EditAnywhere, Category = " Yassine")
	UInputAction* iaBougerGaucheDroite;

	UPROPERTY(EditAnywhere, Category = " Yassine")
	UInputAction* iaBougerAvantarriere;

	UPROPERTY(EditAnywhere, Category = " Yassine")
	UInputAction* iaRegarderAvantArriere;

	UPROPERTY(EditAnywhere, Category = " Yassine")
	UInputAction* iaRegarderGaucheDroite;

	UPROPERTY(EditAnywhere, Category = " Yassine")
	UInputAction* iaLancerboulleFeu;
};
