/*
 * SWBotClimber.cpp
 *
 *  Created on: Jan 12, 2017
 *      Author: Tumtu
 */

#include <subsys/SWBot/SWBotClimber.h>
#include <utils/DragonTalon.h>
#include <subsys/SWBot/SWMap.h>
#include <SmartDashboard/SmartDashboard.h>

namespace Team302 {

bool SWBotClimber::IsRobotLifting()
{
	double current = m_climbMotor->GetOutputCurrent(); //get amperage of motor

	if (current > LIFTING_CURRENT)
	{
		isLifting = true;
	} else
	{
		isLifting = false;
	}

	return isLifting;
}

float SWBotClimber::GetRPM()
{
	return m_climbMotor->GetSpeed(); //Should return encoder speed in RPM according to configEncoderCodesPerRev in constructor
}

float SWBotClimber::GetRotations()
{
	return m_climbMotor->GetPosition(); //Should return encoder position in whole rotations according to configEncoderCodesPerRev in constructor
}

void SWBotClimber::SetPower(float power)
{
	m_climbMotor->SetControlMode(DragonTalon::THROTTLE); //make sure we are in throttle control mode
	m_climbMotor->Set(power); //sets power to motor
}

void SWBotClimber::ResetDistance()
{
	m_climbMotor->Reset(); //resets encoder distance
}

SWBotClimber::SWBotClimber():
	//declare all of the motors
	m_climbMotor(new DragonTalon(CLIMB_MOTOR))
{
	//set inversions on motor directions
	m_climbMotor->SetInverted (IS_CLIMB_MOTOR_INVERTED);
	m_climbMotor->ConfigEncoderCodesPerRev(CLIMB_COUNTS_PER_ROTATION), // defines encoder counts per revolution
	m_climbMotor->SetSensorDirection (IS_CLIMB_ENCODER_INVERTED); //inverts encoder sensor direction as needed
//	double loopTime = 0; //counter to be used for timer on start climb

}

} /* namespace Team302 */
