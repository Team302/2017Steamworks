/*
 * EightyClimber.cpp
 *
 *  Created on: Feb 13, 2017
 *      Author: 0wen
 */

#include <subsys/EightyBot/EightyClimber.h>
#include <utils/DragonTalon.h>
#include <subsys/EightyBot/EightyMap.h>

namespace Team302 {

bool EightyClimber::IsRobotLifting()
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

float EightyClimber::GetRPM()
{
	return m_climbMotor->GetSpeed(); //Should return encoder speed in RPM according to configEncoderCodesPerRev in constructor}
}

float EightyClimber::GetRotations()
{
	return m_climbMotor->GetPosition(); //Should return encoder position in whole rotations according to configEncoderCodesPerRev in constructor}
}

void EightyClimber::SetPower(float power)
{
	m_climbMotor->SetControlMode(DragonTalon::THROTTLE); //make sure we are in throttle control mode
	m_climbMotor->Set(power); //sets power to motor
}

void EightyClimber::ResetDistance()
{
	m_climbMotor->Reset(); //resets encoder distance
}

EightyClimber::EightyClimber():
	//declare all of the motors
		m_climbMotor(new DragonTalon(CLIMB_MOTOR))
	{
		//set inversions on motor directions
		m_climbMotor->SetInverted (IS_CLIMB_MOTOR_INVERTED);

		m_climbMotor->ConfigEncoderCodesPerRev(CLIMB_COUNTS_PER_ROTATION), // defines encoder counts per revolution
		m_climbMotor->SetSensorDirection (IS_CLIMB_ENCODER_INVERTED); //inverts encoder sensor direction as needed
}

} /* namespace Team302 */




