#pragma once

#include <CoreMinimal.h>
#include <GameFramework/Character.h>

#include "MainCharacter.generated.h"

/**
 * Personaje principal que incluye una cámara y un brazo de resorte (Spring Arm).
 */
UCLASS()
class AMainCharacter : public ACharacter {
	GENERATED_BODY()

public:
	/** Constructor que configura los componentes básicos del personaje. */
	AMainCharacter();

private:
	/** Brazo de resorte que sostiene la cámara detrás del personaje. */
	TObjectPtr<class USpringArmComponent> SpringArm{};
	/** Cámara principal del personaje. */
	TObjectPtr<class UCameraComponent> Camera{};
};