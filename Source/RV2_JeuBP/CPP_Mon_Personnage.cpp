// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Mon_Personnage.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "Engine/LocalPlayer.h"


// Sets default values
ACPP_Mon_Personnage::ACPP_Mon_Personnage()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_Mon_Personnage::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_Mon_Personnage::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPP_Mon_Personnage::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* eicComponents = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	eicComponents->BindAction(iaSauter, ETriggerEvent::Triggered, this, &ACPP_Mon_Personnage::Sauter);
	eicComponents->BindAction(iaSauter, ETriggerEvent::Completed, this, &ACPP_Mon_Personnage::StopSauter);
	eicComponents->BindAction(iaBougerGaucheDroite, ETriggerEvent::Triggered, this, &ACPP_Mon_Personnage::BougerGaucheDroite);
	eicComponents->BindAction(iaBougerAvantarriere, ETriggerEvent::Triggered, this, &ACPP_Mon_Personnage::BougerAvantArriere);
	eicComponents->BindAction(iaRegarderAvantArriere, ETriggerEvent::Triggered, this, &ACPP_Mon_Personnage::RegarderAvantArriere);
	eicComponents->BindAction(iaRegarderGaucheDroite, ETriggerEvent::Triggered, this, &ACPP_Mon_Personnage::RegarderGaucheDroite);
	eicComponents->BindAction(iaLancerboulleFeu, ETriggerEvent::Triggered, this, &ACPP_Mon_Personnage::LancerboulleFeu);
	
	
}

void ACPP_Mon_Personnage::Sauter()
{
	Jump();
}

void ACPP_Mon_Personnage::StopSauter()
{
	StopJumping();
}


void ACPP_Mon_Personnage::BougerGaucheDroite(const FInputActionValue& Value)
{
	FRotator rotator = Controller->GetControlRotation();
	FVector vector = FRotationMatrix(rotator).GetScaledAxis(EAxis::Y);
	AddMovementInput(vector, Value.Get<float>());
}

void ACPP_Mon_Personnage::BougerAvantArriere(const FInputActionValue& Value)
{
	FRotator rotator = Controller->GetControlRotation();
	FVector vector = FRotationMatrix(rotator).GetScaledAxis(EAxis::X);
	AddMovementInput(vector, Value.Get<float>());
}

void ACPP_Mon_Personnage::RegarderGaucheDroite(const FInputActionValue& Value)
{
	AddControllerYawInput(Value.Get<float>());
}

void ACPP_Mon_Personnage::RegarderAvantArriere(const FInputActionValue& Value)
{
	AddControllerPitchInput(Value.Get<float>());
}

void ACPP_Mon_Personnage::LancerboulleFeu()
{
	UWorld* Mon_Niveau = GetWorld();
	if (IsValid(Mon_Niveau))
	{
		FRotator personnageRotator;
		FVector personnageLocation;
		FVector offset = FVector(250.0f, 0.0f, 0.0f);
		GetActorEyesViewPoint(personnageLocation, personnageRotator);
		FVector personnageVecteurRotation = FTransform(personnageRotator).TransformVector(offset);
		FVector locationFinale = personnageLocation + FTransform(personnageRotator).TransformVector(offset);

		FActorSpawnParameters SpawnParametre;
		Mon_Niveau->SpawnActor<ACPP_Sphere_feu>(ACPP_Sphere_feu::StaticClass(), locationFinale, personnageRotator ,SpawnParametre);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Une sphere a ete cree!"));
	}
}

