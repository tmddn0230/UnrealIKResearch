// Fill out your copyright notice in the Description page of Project Settings.


#include "Framework/IKPawn.h"

// Sets default values
AIKPawn::AIKPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AIKPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AIKPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AIKPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float FTrackerTickContainer::Calcurate_Head_Foot_Dist()
{
	TArray<FTrackerTickData>& array = Data_Array;
	
	float head_height = 0;
	float head_height_average = 0.1; 
	int32 head_data_count = 0;

	float dist_foot_head_average = 0;
	float dist_foot_head_max = 0.1;

	// calcurate scale
	for (auto& it : array) {
		auto lfoot_loc = it.Trans[(int32)ETrackerType::LFoot].GetLocation();
		auto rfoot_loc = it.Trans[(int32)ETrackerType::RFoot].GetLocation();
		auto head_loc = it.Trans[(int32)ETrackerType::Head].GetLocation();

		float foot_low = (lfoot_loc.Z < rfoot_loc.Z) ? lfoot_loc.Z : rfoot_loc.Z;

		float dist_foot_head = head_loc.Z - foot_low;
		if (dist_foot_head > dist_foot_head_max) {
			dist_foot_head_max = dist_foot_head; // update max value 
		}
		dist_foot_head_average += dist_foot_head;

		// height
		if (head_loc.Z - dist_foot_head < 15.0f) //15cm 보다 크면 유효하지 않다고 판단.
		{
			if (head_loc.Z > head_height) {
				head_height = head_loc.Z;
			}
			head_height_average += head_loc.Z;
			++head_data_count;

		}
	}


	return 0.0f;
}

float FTrackerTickContainer::Calcurate_Hand_RtoL_Dist()
{
	return 0.0f;
}

float FTrackerTickContainer::Calcurate_Foot_RtoL_Dist()
{
	return 0.0f;
}

float FTrackerTickContainer::Calcurate_Foot_Pelvis_Dist()
{
	return 0.0f;
}

void FTrackerTickContainer::Calcurate()
{
	Distance_Head_Foot   = Calcurate_Head_Foot_Dist();
	Distance_Hand_RtoL   = Calcurate_Hand_RtoL_Dist();
	Distance_Foot_RtoL   = Calcurate_Foot_RtoL_Dist();
	Distance_Foot_Pelvis = Calcurate_Foot_Pelvis_Dist();
}
