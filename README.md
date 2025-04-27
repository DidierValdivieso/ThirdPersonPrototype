# 🎮 Third Person Prototype

Este proyecto es un **prototipo de lógica en tercera persona** desarrollado en **Unreal Engine 5** utilizando **C++**.

El objetivo fue construir una base sólida enfocada en **movimiento del personaje**, **manejo de la cámara** y **sistema de sonidos**, priorizando **claridad de código** y **arquitectura limpia**.

---

## 🔄 Demo en acción

![Gameplay Demo](ThirdPersonPrototype.gif)

---

## 🛠️ Características principales

### 🏋️ Movimiento del personaje

Movimiento suave en tercera persona controlado completamente en C++.

```cpp
void AThirdPersonPrototypeCharacter::Move(const FInputActionValue& Value)
{
    FVector2D MovementVector = Value.Get<FVector2D>();
    if (Controller != nullptr)
    {
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);

        const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
        const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

        AddMovementInput(ForwardDirection, MovementVector.Y);
        AddMovementInput(RightDirection, MovementVector.X);
    }
}
```

🔹 *Permite caminar en cualquier dirección relativa a la cámara.*

---

### 🎥 Control de cámara en tercera persona

Cámara libre con control de rotación vertical y horizontal.

```cpp
void AThirdPersonPrototypeCharacter::Look(const FInputActionValue& Value)
{
    FVector2D LookAxisVector = Value.Get<FVector2D>();
    if (Controller != nullptr)
    {
        AddControllerYawInput(LookAxisVector.X);
        AddControllerPitchInput(LookAxisVector.Y);
    }
}
```

🔹 *El jugador puede mirar libremente con el mouse mientras se desplaza.*

---

### 🔊 Reproducción de sonidos

Sistema básico para reproducir sonidos durante eventos de gameplay.

```cpp
void AThirdPersonPrototypeCharacter::PlayFootstepSound()
{
    if (FootstepSound && GetWorld())
    {
        UGameplayStatics::PlaySoundAtLocation(this, FootstepSound, GetActorLocation());
    }
}
```

🔹 *Sonidos de pasos sincronizados con el movimiento.*

---

## 🧠 Enfoque de desarrollo

- **Código modular y extensible** pensado para crecimiento futuro.
- **Separación clara** entre movimiento, cámara y sonido.
- Preparado para añadir mecánicas como:
  - Interacción con objetos
  - Combate cuerpo a cuerpo
  - Animaciones avanzadas

---

## 💂🏻‍♂️ Estructura general del proyecto

```
ThirdPersonPrototype/
├── Source/
│   └── ThirdPersonPrototype/
│       ├── ThirdPersonPrototypeCharacter.h/cpp
│       ├── ThirdPersonPrototypeGameMode.h/cpp
│       └── [Otros archivos de gameplay]
├── Config/
├── Content/
└── ThirdPersonPrototype.uproject
```

---

## 🚀 Tecnologías utilizadas

- Unreal Engine 5
- C++
- Git + GitHub
