/*
 * DriveTime.cpp
 *
 *  Created on: Jan 18, 2017
 *      Author: Owen
 *
 */

#include <auton/DriveTime.h>
#include <auton/Gear.h>
#include <auton/Fuel.h>
#include <auton/PrimitiveFactory.h>
#include <CANTalon.h>
#include <auton/PrimitiveParams.h>
#include <subsys/factories/ChassisFactory.h>

namespace Team302
{
DriveTime::DriveTime() : SuperDrive(),
		m_timeRemaining(0.0)       //Value be changed in init
{
}

void DriveTime::Init(PrimitiveParams*   params)
{
	SuperDrive::Init(params);
	//Get timeRemaining from m_params
	m_timeRemaining = params->GetTime();
	PrimitiveFactory::GetInstance()->GetGearPrim()->Init(params);
	PrimitiveFactory::GetInstance()->GetFuelPrim()->Init(params);
}

bool DriveTime::IsDone()
{
	//Decrement time remaining
	m_timeRemaining -= LOOP_LENGTH;
	//Return true when the time runs out
	return ( ( m_timeRemaining <= (LOOP_LENGTH / 2.0)) &&
			PrimitiveFactory::GetInstance()->GetGearPrim()->IsDone() &&
			PrimitiveFactory::GetInstance()->GetFuelPrim()->IsDone() );
}
} /* namespace Team302 */


