#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MainAnimator.generated.h"

/**
 * Esta clase se encarga de actualizar los datos de entrada, velocidad y estado de apuntado del personaje,
 * y ajusta la rotaci�n del esqueleto basado en la c�mara del jugador para mejorar la inmersi�n.
 */
UCLASS()
class UECOURSE_API UMainAnimator : public UAnimInstance
{
	GENERATED_BODY()
	
private:
	/** Llamado autom�ticamente en cada frame para actualizar la animaci�n. */
	void NativeUpdateAnimation(float delta_seconds) override;

	/** Datos de entrada del jugador (X = Adelante/atr�s, Y = Izquierda/derecha). */
	UPROPERTY(BlueprintReadOnly, Category = "Core", meta = (AllowPrivateAccess = "true"))
	FVector input_data_{};

	/** Velocidad actual del personaje. */
	UPROPERTY(BlueprintReadOnly, Category = "Core", meta = (AllowPrivateAccess = "true"))
	float speed_{};

	/** Indica si el personaje est� en modo de apuntado. */
	UPROPERTY(BlueprintReadOnly, Category = "Core", meta = (AllowPrivateAccess = "true"))
	bool is_aiming_{};
};
