/*
 * SuperDrive.cpp
 *
 *  Created on: Mar 6, 2017
 *      Author: team302
 */

#include <auton/SuperDrive.h>
#include <auton/Gear.h>
#include <auton/Fuel.h>
#include <auton/PrimitiveFactory.h>
#include <subsys/factories/ChassisFactory.h>
#include <cmath>
#include <utils/DragonPID.h>
#include<SmartDashboard/SmartDashboard.h>
#include <subsys/factories/GyroFactory.h>

namespace Team302
{

SuperDrive::SuperDrive() :
		m_chassis(ChassisFactory::GetInstance()->GetIChassis()),
		m_gyro( GyroFactory::GetInstance()->GetIGyro()),
		m_targetSpeed ( 0.0 ),
		m_speedOffset(0.0),
		m_leftSpeed(0.0),
		m_rightSpeed(0.0),
		m_currentAngle(0.0),
		m_startAngle(0.0)
{

}

void SuperDrive::Init(PrimitiveParams* params)

{
	m_targetSpeed = params->GetDriveSpeed();

    m_leftSpeed = params->GetDriveSpeed();
    m_rightSpeed = params->GetDriveSpeed();

    m_startAngle = m_gyro->GetRawAngle();

    m_chassis->ResetDistance();
    m_chassis->SetBrakeMode(false);
    m_chassis->SetControlMode(DragonTalon::VELOCITY); //set chassis to use velocity profile control
	m_chassis->SetVelocityParams(PROPORTIONAL_COEFF, INTREGRAL_COEFF, DERIVATIVE_COEFF, FEET_FORWARD_COEFF, m_leftSpeed, m_rightSpeed);
	PrimitiveFactory::GetInstance()->GetGearPrim()->Init( params );
	PrimitiveFactory::GetInstance()->GetFuelPrim()->Init( params );

	m_speedOffset = m_targetSpeed > 0.0 ? GYRO_CORRECTION_CONSTANT : -GYRO_CORRECTION_CONSTANT;
}

void SuperDrive::Run()
{
//	frc::SmartDashboard::PutNumber("Drive,Super TargetSpeed", m_startSpeed);

	m_currentAngle = m_gyro->GetRawAngle() - m_startAngle;

	m_rightSpeed = m_targetSpeed;
	m_leftSpeed = m_targetSpeed;

//	m_leftSpeed = m_leftSpeed - ( GYRO_CORRECTION_CONSTANT * m_relativeAngle );
//	m_rightSpeed = m_rightSpeed + ( GYRO_CORRECTION_CONSTANT * m_relativeAngle );

	if ( m_currentAngle < 0 )
	{
		m_rightSpeed = m_targetSpeed - ( m_targetSpeed * m_speedOffset );	// + for Eighty ---------- Comp bot -
		m_leftSpeed = m_targetSpeed + ( m_targetSpeed * m_speedOffset ); // - for Eighty -------------- comp bot +
	}
	else
	{
		m_rightSpeed = m_targetSpeed + ( m_rightSpeed * m_speedOffset ); // + for Eighty ---------------- Comp bot +
		m_leftSpeed = m_targetSpeed - ( m_leftSpeed * m_speedOffset );	// - for Eighty ----------------- Comp bot -
	}

	m_chassis->SetVelocityParams(PROPORTIONAL_COEFF, INTREGRAL_COEFF, DERIVATIVE_COEFF, FEET_FORWARD_COEFF, m_leftSpeed, m_rightSpeed);
	//set p, i, d, and f terms and desired left and right speeds in feet per second

	PrimitiveFactory::GetInstance()->GetGearPrim()->Run();
	PrimitiveFactory::GetInstance()->GetFuelPrim()->Run();

	frc::SmartDashboard::PutNumber("Distance Driven", ( (m_chassis->GetRightBackDistance() + m_chassis->GetLeftBackDistance() ) / 2));
}

bool SuperDrive::IsDone()
{
	return false;
	//u better override this if u extend this class...
}

} /* namespace Team302 */
