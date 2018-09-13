/*
 * PrimitiveFactory.cpp
 *
 *  Created on: Jan 19, 2017
 *      Author: Tyler
 */

#include <auton/DoNothing.h>
#include <auton/DriveDistance.h>
#include <auton/DriveTime.h>
#include <auton/PrimitiveFactory.h>
#include <auton/PrimitiveParser.h>
#include <auton/DriveDistance.h>
#include <auton/IPrimitive.h>
#include <auton/Fuel.h>
#include <auton/HoldPosition.h>
#include <auton/Gear.h>
#include <auton/TurnAngle.h>
#include <auton/DriveToPeg.h>
#include <SmartDashboard/SmartDashboard.h>

namespace Team302 {

PrimitiveFactory* PrimitiveFactory::m_instance = nullptr; 			//Inititialize the instance variable to nullptr

PrimitiveFactory* PrimitiveFactory::GetInstance()					//
{
	if (PrimitiveFactory::m_instance == nullptr)					//If we do not have an instance
	{
		PrimitiveFactory::m_instance = new PrimitiveFactory();		//Create a new instance
	}
	return PrimitiveFactory::m_instance;							//Return said instance
}

PrimitiveFactory::PrimitiveFactory():
		m_doNothing(nullptr),
		m_driveTime(nullptr),
		m_driveDistance(nullptr),
		m_turnAngle(nullptr),
		m_holdPosition(nullptr),
		m_gear(nullptr),
		m_fuel(nullptr),
		m_peg(nullptr)
{

}
PrimitiveFactory::~PrimitiveFactory()								//Destructor
{
	PrimitiveFactory::m_instance = nullptr;
}
IPrimitive* PrimitiveFactory::GetIPrimitive(PrimitiveParams* primitivePasser)
{
	IPrimitive* primitive = nullptr;
//	SmartDashboard::PutNumber("Primitive Factory" , primitivePasser->GetID());
	switch (primitivePasser->GetID())				//Decides which primitive to get or make
	{
	case DO_NOTHING:
		if (m_doNothing == nullptr)
		{
			m_doNothing = new DoNothing();
		}
		primitive =  m_doNothing;
		break;

	case DRIVE_TIME:
		if (m_driveTime == nullptr)
		{
			m_driveTime = new DriveTime();
		}
		primitive = m_driveTime;
		break;

	case DRIVE_DISTANCE:
		if (m_driveDistance == nullptr)
		{
			m_driveDistance = new DriveDistance();
		}
		primitive = m_driveDistance;
		break;

	case TURN_ANGLE:
		if (m_turnAngle == nullptr)
		{
			m_turnAngle = new TurnAngle();
		}
		primitive = m_turnAngle;
		break;

	case HOLD_POSITION:
		if (m_holdPosition == nullptr)
		{
			m_holdPosition = new HoldPosition();
		}
		primitive = m_holdPosition;
		break;

	case GEAR:
		if (m_gear == nullptr)
		{
			m_gear= new Gear();
		}
		primitive = m_gear;
		break;

	case FUEL:
		if (m_fuel == nullptr)
		{
			m_fuel = new Fuel();
		}
		primitive=m_fuel;
		break;

	case DRIVE_PEG:
			if (m_peg == nullptr)
			{
				m_peg = new DriveToPeg();
			}
			primitive=m_peg;
			break;
	default:
		break;
	}
	return primitive;

}

//------------------------------------------------------------------------------
// Method:  		GetGearPrim
// Description:		Get the gear primitive
// Returns:			Gear Primitive
//------------------------------------------------------------------------------
IPrimitive* PrimitiveFactory::GetGearPrim()
{
	if (m_gear == nullptr)
	{
		m_gear= new Gear();
	}
	return m_gear;
}

//------------------------------------------------------------------------------
// Method:  		GetFuelPrim
// Description:		Get the fuel primitive
// Returns:			fuel Primitive
//------------------------------------------------------------------------------
IPrimitive* PrimitiveFactory::GetFuelPrim()
{
	if (m_fuel == nullptr)
	{
		m_fuel = new Fuel();
	}
	return m_fuel;
}


} /* namespace Team302 */
