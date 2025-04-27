#include "UECourseGameModeBase.h"

#include "Characters/MainCharacter.h"
#include "Controllers/MainController.h"

/**
 * Esta clase define el comportamiento principal del modo de juego.
 *
 * - Establece el DefaultPawnClass en AMainCharacter, lo que significa
 *   que este ser� el personaje que los jugadores controlar�n por defecto.
 * - Establece el PlayerControllerClass en AMainController, definiendo
 *   el controlador que manejar� la l�gica de entrada del jugador.
 */
AUECourseGameModeBase::AUECourseGameModeBase()
{
	DefaultPawnClass = AMainCharacter::StaticClass();
	PlayerControllerClass = AMainController::StaticClass();
}