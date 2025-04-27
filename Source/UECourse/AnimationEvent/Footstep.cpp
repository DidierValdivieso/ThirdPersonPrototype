#include "Footstep.h"

#include <Components/SkeletalMeshComponent.h>
#include <Engine/World.h>
#include <PhysicalMaterials/PhysicalMaterial.h>
#include <Kismet/GameplayStatics.h>

/**
 * L�gica de la notificaci�n de pasos.
 *
 * Se lanza un raycast desde el hueso especificado hacia abajo.
 * Si se detecta una colisi�n con un objeto est�tico del mundo y tiene un material f�sico asociado,
 * se reproduce un sonido basado en el tipo de superficie detectada.
 */
void UFootstep::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	const auto ray_start = MeshComp->GetBoneLocation(bone_name_);
	const auto ray_end = ray_start + FVector::DownVector * length_;

	FHitResult hit_result{};
	FCollisionQueryParams collision_query_params{};
	collision_query_params.bReturnPhysicalMaterial = true;

	// Realiza el raycast para detectar la superficie
	if (GetWorld()->LineTraceSingleByObjectType(
		hit_result,
		ray_start,
		ray_end,
		FCollisionObjectQueryParams{ ECollisionChannel::ECC_WorldStatic },
		collision_query_params
	)) {
		const auto surface_type = UPhysicalMaterial::DetermineSurfaceType(hit_result.PhysMaterial.Get());
		// Busca el sonido correspondiente al tipo de superficie y lo reproduce
		if (const auto sound = sound_container_.Find(surface_type))
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), *sound, hit_result.ImpactPoint);
	}
}
