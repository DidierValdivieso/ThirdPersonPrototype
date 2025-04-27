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

---

### 🔥 Notas:

- Para poner el **GIF**, debes primero subirlo a GitHub.
- Si lo tienes localmente:
  - Lo subes como un archivo normal (por ejemplo en una carpeta `/Images/Gameplay.gif`).
  - Luego en el README pones:

    ```markdown
    ![Gameplay Demo](Images/Gameplay.gif)
    ```

¿Quieres que también te prepare el comando para subir el GIF fácilmente a tu repositorio? 🚀  
(Solo sería `git add`, `commit` y `push`, rapidísimo).
