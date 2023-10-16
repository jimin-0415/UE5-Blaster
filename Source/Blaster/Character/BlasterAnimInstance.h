// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "BlasterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class BLASTER_API UBlasterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	/// 애니메이션 초기화 함수
	virtual void NativeInitializeAnimation() override;

	/// 애니메이션을 갱신한다.
	virtual void NativeUpdateAnimation(float deltaTime) override;

private:
	/// 블래스터 캐릭터
	UPROPERTY( BlueprintReadOnly, Category = Character, meta = (AllowPrivateAccess = "true" ) )
	class ABlasterCharacter* m_BlasterCharacter;

	UPROPERTY(BlueprintReadOnly, Category = Character, meta = (AllowPrivateAccess = "true"))
	float m_Speed;

	UPROPERTY(BlueprintReadOnly, Category = Character, meta = (AllowPrivateAccess = "true"))
	bool m_IsInAire;

	UPROPERTY(BlueprintReadOnly, Category = Character, meta = (AllowPrivateAccess = "true"))
	bool m_IsAccelerating;

};
