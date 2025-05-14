# 🎮 Third Person Prototype

This project is a **third-person logic prototype** developed in **Unreal Engine 5** using **C++**.

The goal was to build a solid foundation focused on **character movement**, **camera handling**, and **sound system**, prioritizing **code clarity** and **clean architecture**.

---

## 🔄 Demo in action

![Gameplay Demo](ThirdPersonPrototype.gif)

---

## 🛠️ Key Features

### 🏋️ Character Movement

Smooth third-person movement controlled entirely in C++.

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

🔹 *Allows you to walk in any direction relative to the camera.*

---

### 🎥 Third-person camera control

Free camera with vertical and horizontal rotation control.

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

🔹 *The player can freely look around with the mouse while moving.*

---

### 🔊 Sound Playback

Basic system for playing sounds during gameplay events.

```cpp
void AThirdPersonPrototypeCharacter::PlayFootstepSound()
{
    if (FootstepSound && GetWorld())
    {
        UGameplayStatics::PlaySoundAtLocation(this, FootstepSound, GetActorLocation());
    }
}
```

🔹 *Sounds of footsteps synchronized with movement.*

---

## 🧠 Development Approach

- **Modular and extensible code** designed for future growth.
- **Clear separation** between movement, camera, and sound.
- Ready to add mechanics such as:
- Object interaction
- Melee combat
- Advanced animations

---

## 🚀 Technologies used

- Unreal Engine 5
- C++
- Git + GitHub
