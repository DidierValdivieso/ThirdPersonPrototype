#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "Footstep.generated.h"

/**
 * Esta clase lanza un raycast desde un hueso específico hacia abajo para detectar el tipo de superficie
 * y reproducir un sonido apropiado de pisada.
 */
UCLASS()
class UFootstep final : public UAnimNotify
{
	GENERATED_BODY()
	
	/**
	 * Ejecutado cuando se activa la notificación en la animación.
	 * @param MeshComp Componente del esqueleto que ejecuta la animación.
	 * @param Animation Secuencia de animación que activa esta notificación.
	 */
	void Notify(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation) override;
	
	/** Nombre del hueso desde el cual se originará el raycast. */
	UPROPERTY(EditAnywhere, Category = "Core", meta = (DisplayName = "Bone Name"))
	FName bone_name_{};

	/** Longitud del raycast en centímetros. */
	UPROPERTY(EditAnywhere, Category = "Core", meta = (DisplayName = "Length", ClampMin = 0, ClampMax = 100))
	float length_{ 100.0f };

	/** Contenedor que asigna cada tipo de superficie física a su respectivo sonido de pisada. */
	UPROPERTY(EditAnywhere, Category = "Core", meta = (DisplayName = "Sound Container"))
	TMap<TEnumAsByte<EPhysicalSurface>, TObjectPtr<USoundBase>> sound_container_{};
};

