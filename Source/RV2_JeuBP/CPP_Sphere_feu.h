#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Particles/ParticleSystem.h"
#include "CPP_Sphere_feu.generated.h"

UCLASS()
class RV2_JEUBP_API ACPP_Sphere_feu : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACPP_Sphere_feu();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* smCube;

	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* psParticles;
};
