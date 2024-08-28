// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "IKPawn.generated.h"

UENUM()
enum class ETrackerType : uint8
{
	Head = 0,
	Pelvis = 1, // spine
	LHand = 2,
	RHand = 3,
	LFoot = 4,
	RFoot = 5,
	Nozzle = 6
};

USTRUCT()
struct FTrackerTickData
{
	GENERATED_BODY()

	// We use 6 Marker, both optitrack and viveut
	UPROPERTY()	FTransform Trans[6];
};

USTRUCT()
struct FTrackerTickContainer
{
	// Container is managing and saving data of class
	GENERATED_BODY()

	UPROPERTY()	TArray<FTrackerTickData> Data_Array;
	UPROPERTY()	int32 Array_Max;
	UPROPERTY()	bool Active;

	FTrackerTickContainer() :
		Array_Max(1000), Active(false) {
	}

	// Calculate function 
	// maybe called once
	float Calcurate_Head_Foot_Dist();
	float Calcurate_Hand_RtoL_Dist();
	float Calcurate_Foot_RtoL_Dist();
	float Calcurate_Foot_Pelvis_Dist();

	void Calcurate();

	// Calculate value for motion capture IK Withcout Calibration
	float Distance_Head_Foot;
	float Distance_Hand_RtoL;
	float Distance_Foot_RtoL;
	float Distance_Foot_Pelvis;
	float Head_Height;
	float Head_Height_Avarage;
};

UCLASS()
class IKRESEARCH_API AIKPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AIKPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
