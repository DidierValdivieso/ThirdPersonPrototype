#pragma once

#include <CoreMinimal.h>
#include <GameFramework/PlayerController.h>

#include "MainController.generated.h"

/**
 * Controlador principal del jugador. Se encarga de manejar el movimiento, la cámara, el salto y el apuntado.
 */
UCLASS()
class AMainController : public APlayerController {
	GENERATED_BODY()

public:
	/** Constructor que activa el tick. */
	AMainController();

	/** Devuelve el vector de entrada actual (movimiento). */
	FVector2d input_data() const
	{
		return input_data_;
	}

	/** Devuelve si el jugador está apuntando o no. */
	bool is_aiming() const
	{
		return is_aiming_;
	}

private:
	/** Configura las acciones de entrada del jugador. */
	void SetupInputComponent() override;

	/** Maneja el movimiento basado en la entrada. */
	void move(const struct FInputActionValue&);

	/** Maneja la rotación de la cámara basada en la entrada. */
	void look(const struct FInputActionValue&);

	/** Hace que el personaje salte. */
	void jump();

	/** Detiene el salto del personaje. */
	void stop_jump();

	/** Cambia el estado de apuntado. */
	void aim();

	// Acciones de entrada
	TObjectPtr<class UInputAction> move_action_{};
	TObjectPtr<class UInputAction> look_action_{};
	TObjectPtr<class UInputAction> jump_action_{};
	TObjectPtr<class UInputAction> aim_action_{};

	// Modificadores y disparadores de entrada
	TObjectPtr<class UInputModifierSwizzleAxis> swizzle_modifier_{};
	TObjectPtr<class UInputModifierNegate> negate_modifier_{};
	TObjectPtr<class UInputTrigger> trigger_{};

	// Contexto de mapeo de entradas
	TObjectPtr<class UInputMappingContext> mapping_context_{};

	// Datos de entrada de movimiento
	FVector2d input_data_{};

	// Estado de apuntado
	bool is_aiming_{};
};