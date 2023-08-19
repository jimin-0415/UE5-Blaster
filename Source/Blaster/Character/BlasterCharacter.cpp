// Fill out your copyright notice in the Description page of Project Settings.


#include "BlasterCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
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

// Called when the game starts or when spawned
void ABlasterCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABlasterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABlasterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

