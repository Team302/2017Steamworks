/*
 * TankDrive.cpp
 *
 *  Created on: Jan 14, 2017
 *      Author: Tumtu
 */

#include <teleopDrive/TankDrive.h>
#include <subsys/factories/ChassisFactory.h>
#include <driverInputs/OI.h>
#include <subsys/interfaces/IChassis.h>

using namespace Team302;

TankDrive::TankDrive() :
m_oi( OI::GetInstance())
{
	m_oi->SetCurve( OI::TANK_DRIVE_LEFT_CONTROL, OI::AXIS_LINEAR );
	m_oi->SetCurve( OI::TANK_DRIVE_RIGHT_CONTROL, OI::AXIS_LINEAR );
	m_chassis = ChassisFactory::GetInstance()->GetIChassis();

}

void TankDrive::DriveWithJoysticks() const
{
	float leftSideSpeed= m_oi->GetAxis( OI::TANK_DRIVE_LEFT_CONTROL );
	float rightSideSpeed= m_oi->GetAxis( OI::TANK_DRIVE_RIGHT_CONTROL );
	m_chassis->SetLeftPower(leftSideSpeed);
	m_chassis->SetRightPower(rightSideSpeed);
}

TankDrive::~TankDrive()
{

}

