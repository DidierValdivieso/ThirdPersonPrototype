#include "MainCharacter.h"

#include <GameFramework/SpringArmComponent.h>
#include <Camera/CameraComponent.h>
#include <Components/CapsuleComponent.h>

AMainCharacter::AMainCharacter()
{
	// Crear el brazo de resorte y la c�mara
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");

	// Configurar el brazo de resorte
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->SocketOffset = FVector{ 0.0f, 50.0f, 0.0f };
	SpringArm->SetRelativeLocation(FVector{ 0.0f, 0.0f, 50.0f });

	// Configurar la c�mara unida al brazo de resorte
	Camera->SetupAttachment(SpringArm);

	// Asegurar que la c�psula sea visible en el juego
	GetCapsuleComponent()->SetHiddenInGame(false);

	// El personaje no rota autom�ticamente con el controlador
	bUseControllerRotationYaw = false;

	// Este actor no necesita actualizaciones en cada tick
	PrimaryActorTick.bCanEverTick = false;
}