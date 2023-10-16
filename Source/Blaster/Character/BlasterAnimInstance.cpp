// Fill out your copyright notice in the Description page of Project Settings.


#include "BlasterAnimInstance.h"
#include "BlasterCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"


void UBlasterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	m_BlasterCharacter = Cast< ABlasterCharacter >(TryGetPawnOwner());
}

void UBlasterAnimInstance::NativeUpdateAnimation(float deltaTime)
{
	Super::NativeUpdateAnimation(deltaTime);

	if (m_BlasterCharacter == nullptr) 
	{
		m_BlasterCharacter = Cast< ABlasterCharacter >(TryGetPawnOwner());
	}

	if (m_BlasterCharacter == nullptr) 
		return;

	FVector velocity = m_BlasterCharacter->GetVelocity();
	velocity.Z = 0.f;
	m_Speed = velocity.Size();

	// 점프 상태인지
	m_IsInAire = m_BlasterCharacter->GetCharacterMovement()->IsFalling();

	// 가속 상태인지 여부
	m_IsAccelerating = m_BlasterCharacter->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f ? true : false;
}
