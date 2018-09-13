/*
 * SWChassisTest.cpp
 *
 *  Created on: Feb 4, 2017
 *      Author: jonah shader
 */

#include <test/SWBotChassisTest.h>
#include <SmartDashboard/SmartDashboard.h>

namespace Team302
{

SWBotChassisTest::SWBotChassisTest() : m_chassis(new SWBotChassis()), m_time(0.0), m_brakeModeOn(true)
{
}

void SWBotChassisTest::ChassisInit()
{
	m_chassis->ResetDistance();
	m_time = 0.0;
	m_brakeModeOn = true;
}

void SWBotChassisTest::ChassisPeriodic()
{
	if(m_time > (0.0 * TIME_MULTIPLIER) && m_time < (1.0 * TIME_MULTIPLIER))
	{
		//Turn on left motors
		m_chassis->SetLeftPower(0.75);
		m_chassis->SetRightPower(0.0);
	}
	else if(m_time > (2.0 * TIME_MULTIPLIER) && m_time < (3.0 * TIME_MULTIPLIER))
	{
		//Turn on left motors
		m_chassis->SetLeftPower(0.0);
		m_chassis->SetRightPower(0.75);
	}
	else if(m_time > (4.0 * TIME_MULTIPLIER))
	{
		m_brakeModeOn = !m_brakeModeOn; //the next sequence will have the opposite brake mode
		m_chassis->SetBrakeMode(m_brakeModeOn);
		m_time = 0.0; //Reset time so the above sequence loops. Reset at 4 seconds (scaled by TIME_MULTIPLIER)
	}
	else
	{
		//Set motors to 0
		m_chassis->SetLeftPower(0.0);
		m_chassis->SetRightPower(0.0);
	}
	frc::SmartDashboard::PutNumber("left  front enc: ", m_chassis->GetLeftFrontDistance());
	frc::SmartDashboard::PutNumber("left  back  enc: ", m_chassis->GetLeftBackDistance());
	frc::SmartDashboard::PutNumber("right front enc: ", m_chassis->GetRightFrontDistance());
	frc::SmartDashboard::PutNumber("right back  enc: ", m_chassis->GetRightBackDistance());

	frc::SmartDashboard::PutNumber("left  front vel: ", m_chassis->GetLeftFrontVelocity());
	frc::SmartDashboard::PutNumber("left  back  vel: ", m_chassis->GetLeftBackVelocity());
	frc::SmartDashboard::PutNumber("right front vel: ", m_chassis->GetRightFrontVelocity());
	frc::SmartDashboard::PutNumber("right back  vel: ", m_chassis->GetRightBackVelocity());

	frc::SmartDashboard::PutNumber("left  distance : ", m_chassis->GetLeftDistance());
	frc::SmartDashboard::PutNumber("right distance : ", m_chassis->GetRightDistance());

	frc::SmartDashboard::PutNumber("left  velocity : ", m_chassis->GetLeftVelocity());
	frc::SmartDashboard::PutNumber("right velocity : ", m_chassis->GetRightVelocity());

	m_time += 0.020; // 20 ms. I dont feel like including IPrimitive
}

} /* namespace Team302 */
