#include "MainController.h"

#include <InputAction.h>
#include <InputModifiers.h>
#include <InputTriggers.h>
#include <InputMappingContext.h>
#include <EnhancedInputSubsystems.h>
#include <EnhancedInputComponent.h>
#include <GameFramework/Character.h>

AMainController::AMainController()
{
	// Activa el tick para este controlador
	PrimaryActorTick.bCanEverTick = true;
}

void AMainController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Crear acciones de entrada
	if (move_action_ = NewObject<UInputAction>(); move_action_)
		move_action_->ValueType = EInputActionValueType::Axis2D;

	if (look_action_ = NewObject<UInputAction>(); look_action_)
		look_action_->ValueType = EInputActionValueType::Axis2D;

	if (jump_action_ = NewObject<UInputAction>(); jump_action_)
		jump_action_->ValueType = EInputActionValueType::Boolean;

	if (aim_action_ = NewObject<UInputAction>(); aim_action_)
		aim_action_->ValueType = EInputActionValueType::Boolean;

	// Crear modificadores y trigger
	swizzle_modifier_ = NewObject<UInputModifierSwizzleAxis>();
	negate_modifier_ = NewObject<UInputModifierNegate>();
	trigger_ = NewObject<UInputTrigger>(this);

	// Crear y configurar el contexto de mapeo de entradas
	if (mapping_context_ = NewObject<UInputMappingContext>(); mapping_context_ && swizzle_modifier_ && negate_modifier_) {
		auto& move_forward = mapping_context_->MapKey(move_action_, EKeys::W);
		move_forward.Modifiers.Add(swizzle_modifier_);

		auto& move_backward = mapping_context_->MapKey(move_action_, EKeys::S);
		move_backward.Modifiers.Add(swizzle_modifier_);
		move_backward.Modifiers.Add(negate_modifier_);

		mapping_context_->MapKey(move_action_, EKeys::D);

		auto& move_left = mapping_context_->MapKey(move_action_, EKeys::A);
		move_left.Modifiers.Add(negate_modifier_);

		mapping_context_->MapKey(look_action_, EKeys::Mouse2D);
		mapping_context_->MapKey(jump_action_, EKeys::SpaceBar);
		
		auto& aim = mapping_context_->MapKey(aim_action_, EKeys::RightMouseButton);
		aim.Triggers.Add(trigger_);

		// Registrar el contexto de entrada en el subsistema
		if (auto* const subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer())) {
			subsystem->ClearAllMappings();
			subsystem->AddMappingContext(mapping_context_, 0);
		}

	}

	// Vincular acciones a funciones	
	if (auto* const enhanced_input_component = Cast<UEnhancedInputComponent>(InputComponent)) {
		enhanced_input_component->BindAction(move_action_, ETriggerEvent::Triggered, this, &AMainController::move);
		enhanced_input_component->BindAction(look_action_, ETriggerEvent::Triggered, this, &AMainController::look);
		enhanced_input_component->BindAction(jump_action_, ETriggerEvent::Started, this, &AMainController::jump);
		enhanced_input_component->BindAction(jump_action_, ETriggerEvent::Completed, this, &AMainController::stop_jump);
		enhanced_input_component->BindAction(aim_action_, ETriggerEvent::Completed, this, &AMainController::aim);
	}
		
}

void AMainController::move(const FInputActionValue& input_action_value)
{
	// Actualizar los datos de movimiento
	input_data_ = input_action_value.Get<FVector2d>();

	const auto move_direction = FVector{ input_data_.Y, input_data_.X, 0.0f };
	const auto control_rotation = FQuat::MakeFromRotator(FRotator{ 0.0f, GetControlRotation().Yaw, 0.0f });
	const auto movement = control_rotation * move_direction;

	GetCharacter()->AddMovementInput(movement.GetSafeNormal(), input_action_value.GetMagnitude());

}

void AMainController::look(const struct FInputActionValue& input_action_value)
{
	// Actualizar la rotación de la cámara
	const auto move_value = input_action_value.Get<FVector2d>();
	AddYawInput(move_value.X);
	AddPitchInput(-move_value.Y);
}

void AMainController::jump()
{
	// Hacer que el personaje salte
	GetCharacter()->Jump();
}

void AMainController::stop_jump()
{
	// Hacer que el personaje deje de saltar
	GetCharacter()->StopJumping();
}

void AMainController::aim()
{
	// Alternar el estado de apuntado
	is_aiming_ = !is_aiming_;
}
