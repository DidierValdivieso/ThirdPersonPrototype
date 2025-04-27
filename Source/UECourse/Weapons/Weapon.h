#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

/** Representa un arma en el juego. */
UCLASS()
class UECOURSE_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	/** Constructor del arma. */
	AWeapon();

protected:
	/** Se llama cuando el arma comienza el juego o es spawneada. */
	virtual void BeginPlay() override;
};
