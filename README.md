# UnrealPortfolio
Unreal final portfolio

## C++을 활용하여 간단한 RPG를 만드는 포트폴리오입니다.

---

### 캐릭터 IK

![Video Label](http://img.youtube.com/vi/9xf23JAV5D0/0.jpg)

(https://youtu.be/9xf23JAV5D0)

엔진을 사용하여 캐릭터 IK를 구현했습니다.
발이 골반 이상으로 올라가지는 못하게 만들었으며 위치에 따라 알맞게 동작하도록 구현했습니다.

---

### 캐릭터 이동

EnhancedInput을 사용하여 이동을 구현했습니다.

```cpp
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);

	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Move);
	EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Look);
}
```

---

### 아이템

주웠을 시 캐릭터 손에 달린 Socket으로 이동하게 만들었습니다.

```cpp
void AWeapon::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnSphereOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(OtherActor);
	if (PlayerCharacter)
	{
		FAttachmentTransformRules TransFormRules(EAttachmentRule::SnapToTarget,true);
		ItemMesh->AttachToComponent(PlayerCharacter->GetMesh(), TransFormRules,FName("RightHandSocket"));
	}
}
```
