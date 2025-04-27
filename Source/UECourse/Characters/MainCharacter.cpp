#include "MainCharacter.h"

#include <GameFramework/SpringArmComponent.h>
#include <Camera/CameraComponent.h>
#include <Components/CapsuleComponent.h>

AMainCharacter::AMainCharacter()
{
	// Crear el brazo de resorte y la cámara
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");

	// Configurar el brazo de resorte
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->SocketOffset = FVector{ 0.0f, 50.0f, 0.0f };
	SpringArm->SetRelativeLocation(FVector{ 0.0f, 0.0f, 50.0f });

	// Configurar la cámara unida al brazo de resorte
	Camera->SetupAttachment(SpringArm);

	// Asegurar que la cápsula sea visible en el juego
	GetCapsuleComponent()->SetHiddenInGame(false);

	// El personaje no rota automáticamente con el controlador
	bUseControllerRotationYaw = false;

	// Este actor no necesita actualizaciones en cada tick
	PrimaryActorTick.bCanEverTick = false;
}