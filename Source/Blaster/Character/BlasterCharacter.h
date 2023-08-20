// Fill out your copyright notice in the Description page of Project Settings.


#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BlasterCharacter.generated.h"


UCLASS()
class BLASTER_API ABlasterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABlasterCharacter();

	// Called every frame
	virtual void Tick( float DeltaTime ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent( class UInputComponent* PlayerInputComponent ) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/// Axis X [Direction] 방향으로 움직입니다.
	void MoveForward( float value );

	/// Axis Y 방향으로 움직입입니다.
	void MoveRight( float value );

	/// Yaw 기준으로 회전합니다.
	void Turn( float value );

	/// Pitch 기준으로 회전합니다.
	void LookUp( float value );

private:
	/// Spring Arm Component
	UPROPERTY( VisibleAnyWhere, Category = Camera )
		class USpringArmComponent* m_CameraBoom;

	/// Camera Component
	UPROPERTY( VisibleAnyWhere, Category = Camera )
		class UCameraComponent* m_FollowCamera;
};
