// Fill out your copyright notice in the Description page of Project Settings.


#include "BlasterCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"


////////////////////////////////////////////////////////////////////////////
/// Sets default values
////////////////////////////////////////////////////////////////////////////
ABlasterCharacter::ABlasterCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Spring Arm
	m_CameraBoom = CreateDefaultSubobject< USpringArmComponent>( TEXT( "CameraBoom" ) );
	m_CameraBoom->SetupAttachment( GetMesh() );
	m_CameraBoom->TargetArmLength = 600.f;
	m_CameraBoom->bUsePawnControlRotation = true;

	//Follow Camera
	m_FollowCamera = CreateDefaultSubobject<UCameraComponent>( TEXT( "FollowCamera" ) );
	m_FollowCamera->SetupAttachment( m_CameraBoom, USpringArmComponent::SocketName );
	m_FollowCamera->bUsePawnControlRotation = false;
}

////////////////////////////////////////////////////////////////////////////
/// Called to bind functionality to input
////////////////////////////////////////////////////////////////////////////
void ABlasterCharacter::SetupPlayerInputComponent( UInputComponent* PlayerInputComponent )
{
	Super::SetupPlayerInputComponent( PlayerInputComponent );

	PlayerInputComponent->BindAction( "Jump", IE_Pressed, this, &ACharacter::Jump );

	PlayerInputComponent->BindAxis( "MoveForward", this, &ABlasterCharacter::MoveForward );
	PlayerInputComponent->BindAxis( "MoveRight", this, &ABlasterCharacter::MoveRight );
	PlayerInputComponent->BindAxis( "Turn", this, &ABlasterCharacter::Turn );
	PlayerInputComponent->BindAxis( "LookUp", this, &ABlasterCharacter::LookUp );
}

////////////////////////////////////////////////////////////////////////////
/// Called when the game starts or when spawned
////////////////////////////////////////////////////////////////////////////
void ABlasterCharacter::BeginPlay()
{
	Super::BeginPlay();

}

////////////////////////////////////////////////////////////////////////////
/// Axis X [Direction] 방향으로 움직입니다.
////////////////////////////////////////////////////////////////////////////
void ABlasterCharacter::MoveForward( float value )
{
	if ( Controller != nullptr && value != 0.0f )
	{
		const FRotator yawRoation( 0.f, Controller->GetControlRotation().Yaw, 0.f );
		const FVector direction( FRotationMatrix( yawRoation ).GetUnitAxis( EAxis::X ) );
		AddMovementInput( direction, value );
	}
}

////////////////////////////////////////////////////////////////////////////
/// Axis Y 방향으로 움직입입니다.
////////////////////////////////////////////////////////////////////////////
void ABlasterCharacter::MoveRight( float value )
{
	if ( Controller != nullptr && value != 0.0f )
	{
		const FRotator yawRoation( 0.f, Controller->GetControlRotation().Yaw, 0.f );
		const FVector direction( FRotationMatrix( yawRoation ).GetUnitAxis( EAxis::Y ) );
		AddMovementInput( direction, value );
	}
}

////////////////////////////////////////////////////////////////////////////
/// Yaw 기준으로 회전합니다.
////////////////////////////////////////////////////////////////////////////
void ABlasterCharacter::Turn( float value )
{
	AddControllerYawInput( value );
}

////////////////////////////////////////////////////////////////////////////
/// Pitch 기준으로 회전합니다.
////////////////////////////////////////////////////////////////////////////
void ABlasterCharacter::LookUp( float value )
{
	AddControllerPitchInput( value );
}

////////////////////////////////////////////////////////////////////////////
/// Called every frame
////////////////////////////////////////////////////////////////////////////
void ABlasterCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}
