#include "Weapon.h"
#include "../Inventory/Item.h"

AWeapon::AWeapon()
{
	// No necesita actualizaciones por frame
	PrimaryActorTick.bCanEverTick = false;
}

void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
	// El arma se destruirá automáticamente después de 5 segundos
	SetLifeSpan(5.0f);

	// Crear un objeto Item asociado al arma
	if (auto* const item = NewObject<UItem>(this)) {
		item->set_name("Medkit");
		UE_LOG(LogTemp, Warning, TEXT("Item name is: %s"), *item->name().ToString());
	}
}

