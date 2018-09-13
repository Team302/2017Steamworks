/*
 * HoldPosition.cpp
 *
 *  Created on: Jan 25, 2017
 *      Author: Jonah Shader
 */

#include <auton/HoldPosition.h>
#include <auton/Gear.h>
#include <auton/Fuel.h>
#include <auton/PrimitiveParams.h>
#include <auton/PrimitiveFactory.h>
#include <subsys/factories/ChassisFactory.h>
#include <cmath>
#include <utils/DragonPID.h>
#include <SmartDashboard/SmartDashboard.h>

namespace Team302
{

HoldPosition::HoldPosition() :
		m_chassis(ChassisFactory::GetInstance()->GetIChassis()), //Get chassis from chassis factory
		m_timeRemaining(0.0)       //Value be changed in init
{
}

void HoldPosition::Init(PrimitiveParams*	params)
{
	//Get timeRemaining from m_params
	m_timeRemaining = params->GetTime();
	m_chassis->SetBrakeMode(false);
	m_chassis->ResetDistance();
	m_chassis->SetControlMode(DragonTalon::POSITION); //sets chassis to position hold control method
	m_chassis->SetPositionParams(kP, kI, kD, kF, 0.0, 0.0);

	PrimitiveFactory::GetInstance()->GetGearPrim()->Init( params );
	PrimitiveFactory::GetInstance()->GetFuelPrim()->Init( params );
}

void HoldPosition::Run()
{
	//Decrement time remaining
	m_timeRemaining -= LOOP_LENGTH;

	PrimitiveFactory::GetInstance()->GetGearPrim()->Run();
	PrimitiveFactory::GetInstance()->GetFuelPrim()->Run();
}

bool HoldPosition::IsDone()
{
	//Return true when the time runs out
	return ( ( m_timeRemaining <= (LOOP_LENGTH / 2.0)) &&
			   PrimitiveFactory::GetInstance()->GetGearPrim()->IsDone() &&
			   PrimitiveFactory::GetInstance()->GetFuelPrim()->IsDone() );
}

} /* namespace Team302 */
