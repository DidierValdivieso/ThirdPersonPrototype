#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MainAnimator.generated.h"

/**
 * Esta clase se encarga de actualizar los datos de entrada, velocidad y estado de apuntado del personaje,
 * y ajusta la rotación del esqueleto basado en la cámara del jugador para mejorar la inmersión.
 */
UCLASS()
class UECOURSE_API UMainAnimator : public UAnimInstance
{
	GENERATED_BODY()
	
private:
	/** Llamado automáticamente en cada frame para actualizar la animación. */
	void NativeUpdateAnimation(float delta_seconds) override;

	/** Datos de entrada del jugador (X = Adelante/atrás, Y = Izquierda/derecha). */
	UPROPERTY(BlueprintReadOnly, Category = "Core", meta = (AllowPrivateAccess = "true"))
	FVector input_data_{};

	/** Velocidad actual del personaje. */
	UPROPERTY(BlueprintReadOnly, Category = "Core", meta = (AllowPrivateAccess = "true"))
	float speed_{};

	/** Indica si el personaje está en modo de apuntado. */
	UPROPERTY(BlueprintReadOnly, Category = "Core", meta = (AllowPrivateAccess = "true"))
	bool is_aiming_{};
};
