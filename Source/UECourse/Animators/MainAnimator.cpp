#include "MainAnimator.h"
#include "../Controllers/MainController.h"

#include <Kismet/GameplayStatics.h>
#include <Engine/World.h>

/**
 * Convierte un puntero normal en un TObjectPtr.
 */
template <typename T>
TObjectPtr<T> make_object_ptr(T* ptr)
{
	return { ptr };
}

/**
 * Crea una rotación (quaternion) usando solo el giro en el eje Z (Yaw).
 */
FQuat make_quat_from_z_rotation(FRotator rotator)
{
	return FQuat::MakeFromRotator(FRotator(0.0f, rotator.Yaw, 0.0f));
}

/**
 * - Actualiza datos de entrada y estado de apuntado a partir del controlador.
 * - Actualiza la velocidad basada en la magnitud de la velocidad del Pawn.
 * - Si el personaje se está moviendo o apuntando, interpola la rotación del esqueleto hacia la rotación de la cámara.
 */
void UMainAnimator::NativeUpdateAnimation(float delta_seconds)
{
	if (!IsValid(TryGetPawnOwner()))
		return;

	if (const auto main_controller = make_object_ptr(TryGetPawnOwner()->GetController<AMainController>())) {
		input_data_ = FVector{ main_controller->input_data(), 0.0f };
		is_aiming_ = main_controller->is_aiming();
		speed_ = TryGetPawnOwner()->GetVelocity().Length();
	}
	
	if (speed_ >= 5.0f || is_aiming_) {
		const auto camera_manager = make_object_ptr(UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0));
		if (camera_manager) {
			const auto camera_rotation = make_quat_from_z_rotation(camera_manager->GetCameraRotation());
			const auto mesh_rotation = make_quat_from_z_rotation(GetOwningComponent()->GetRelativeRotation());

			GetOwningComponent()->SetRelativeRotation(FQuat::Slerp(mesh_rotation, camera_rotation, 0.25));
		}
	}
}
