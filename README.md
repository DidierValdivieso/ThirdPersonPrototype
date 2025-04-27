# 🎮 Third Person Prototype

Este proyecto es un **prototipo de lógica en tercera persona** desarrollado en **Unreal Engine 5** utilizando **C++**.

El enfoque principal fue construir una base sólida de **programación de gameplay**, priorizando la **arquitectura del código** y la **claridad lógica**.

---

## 🎥 Demo en acción

![Gameplay Demo](ThirdPersonPrototype.gif)

---

## 🛠️ Características principales

- 🚶‍♂️ **Movimiento de personaje:**
  - Movimiento, carrera y salto controlados en C++.
  - Código limpio y modular.

  ```cpp
  void AThirdPersonPrototypeCharacter::Move(const FInputActionValue& Value)
  {
      FVector2D MovementVector = Value.Get<FVector2D>();
      AddMovementInput(GetActorForwardVector(), MovementVector.Y);
      AddMovementInput(GetActorRightVector(), MovementVector.X);
  }

