#pragma once

#include <CoreMinimal.h>
#include <GameFramework/Character.h>

#include "MainCharacter.generated.h"

/**
 * Personaje principal que incluye una c�mara y un brazo de resorte (Spring Arm).
 */
UCLASS()
class AMainCharacter : public ACharacter {
	GENERATED_BODY()

public:
	/** Constructor que configura los componentes b�sicos del personaje. */
	AMainCharacter();

private:
	/** Brazo de resorte que sostiene la c�mara detr�s del personaje. */
	TObjectPtr<class USpringArmComponent> SpringArm{};
	/** C�mara principal del personaje. */
	TObjectPtr<class UCameraComponent> Camera{};
};