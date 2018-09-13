/*
 * CompBotChassis.cpp
 *
 *  Created on: Jan 16, 2017
 *      Author: Austin/Neethan
 */

#include <utils/DragonTalon.h>
#include <utils/LimitValue.h>
#include <subsys/CompBot/CompBotChassis.h>
#include <subsys/CompBot/CompMap.h>
#include <subsys/interfaces/IChassis.h>
#include <SmartDashboard/SmartDashboard.h>

namespace Team302 {

float CompBotChassis::GetLeftDistance() const
{
	return GetRightDistance();
}

float CompBotChassis::GetRightDistance() const
{
	float rightPos = m_rightMasterMotor->GetEncPosition();
	frc::SmartDashboard::PutNumber("encoder distance conversion", ENCODER_DISTANCE_CONVERSION);
	return ((rightPos) * ENCODER_DISTANCE_CONVERSION );
}

float CompBotChassis::GetLeftBackDistance() const
{
	return GetRightBackDistance();
}

float CompBotChassis::GetLeftFrontDistance() const
{
	return GetRightFrontDistance();
}

float CompBotChassis::GetRightBackDistance() const
{
	return GetRightDistance();
}

float CompBotChassis::GetRightFrontDistance() const
{
	return GetRightDistance();
}


float CompBotChassis::GetLeftVelocity() const
{
	return GetRightVelocity();
}

float CompBotChassis::GetRightVelocity() const
{
	float rightMotorVel = m_rightMasterMotor->GetEncVel();
	return ((rightMotorVel) * ENCODER_VELOCITY_CONVERSION );
}

float CompBotChassis::GetLeftBackVelocity() const
{
	return GetRightBackVelocity();
}

float CompBotChassis::GetLeftFrontVelocity() const
{
	return GetRightFrontVelocity();;
}

float CompBotChassis::GetRightBackVelocity() const
{
	return GetRightVelocity();
}

float CompBotChassis::GetRightFrontVelocity() const
{
	return GetRightVelocity();
}

void CompBotChassis::ResetDistance()
{
	m_leftSlaveMotor->Reset();
	m_leftMasterMotor->Reset();
	m_rightSlaveMotor->Reset();
	m_rightMasterMotor->Reset();

}

void CompBotChassis::SetLeftPower(float power)
{
	//Make sure the left side speed is within range and then set both left motors to this speed
	float leftSpeed = LimitValue::ForceInRange( power, -0.98, 0.98 );
	m_leftMasterMotor->Set( leftSpeed );

}

void CompBotChassis::SetRightPower(float power)
{
	// Make sure the right side speed is within range and then set both right motors to this speed
	float rightSpeed = LimitValue::ForceInRange( power, -0.98, 0.98 );
	m_rightMasterMotor->Set( rightSpeed );
}

void CompBotChassis::SetBrakeMode(bool mode)
{
	if(mode)
	{
		m_leftSlaveMotor->ConfigNeutralMode( frc::CANSpeedController::kNeutralMode_Brake );
		m_rightSlaveMotor->ConfigNeutralMode( frc::CANSpeedController::kNeutralMode_Brake );
		m_leftMasterMotor->ConfigNeutralMode( frc::CANSpeedController::kNeutralMode_Brake );
		m_rightMasterMotor->ConfigNeutralMode( frc::CANSpeedController::kNeutralMode_Brake );
	}
	else
	{
		m_leftSlaveMotor->ConfigNeutralMode( frc::CANSpeedController::kNeutralMode_Coast );
		m_rightSlaveMotor->ConfigNeutralMode( frc::CANSpeedController::kNeutralMode_Coast );
		m_leftMasterMotor->ConfigNeutralMode( frc::CANSpeedController::kNeutralMode_Coast );
		m_rightMasterMotor->ConfigNeutralMode( frc::CANSpeedController::kNeutralMode_Coast );
	}
}

void CompBotChassis::SetControlMode(DragonTalon::DRAGON_CONTROL_MODE mode)
{
	switch (mode)
	{
	case DragonTalon::POSITION:
		m_rightMasterMotor->SetControlMode(DragonTalon::POSITION);
		m_leftMasterMotor->SetControlMode(DragonTalon::POSITION);
		break;

	case DragonTalon::VELOCITY:
		m_rightMasterMotor->SetControlMode(DragonTalon::VELOCITY);
		m_leftMasterMotor->SetControlMode(DragonTalon::VELOCITY);
		break;

	case DragonTalon::THROTTLE:
		m_rightMasterMotor->SetControlMode(DragonTalon::THROTTLE);
		m_leftMasterMotor->SetControlMode(DragonTalon::THROTTLE);
		break;

	case DragonTalon::FOLLOWER:
		m_rightMasterMotor->SetControlMode(DragonTalon::FOLLOWER);
		m_leftMasterMotor->SetControlMode(DragonTalon::FOLLOWER);
		break;

	default:
		m_rightMasterMotor->SetControlMode(DragonTalon::THROTTLE);
		m_leftMasterMotor->SetControlMode(DragonTalon::THROTTLE);
	}

}

//----------------------------------------------------------------------------------
// Method:      SetControlParams
// Description: Sets PID and F factors to the motors and sets target. Target is
//				double for position in feet. Make sure to set
//				motor to POSITION control first. Once target is set,
//				motor will immediately start using it for position control
// Params:		double kP - proportional-gain value
//				double kI - integral-gain value
//				double kD - derivative-gain value
//				double kF - feed-forward factor
//				double leftTarget - target position in feet for left
//				double rightTarget - target position in feet for right
//----------------------------------------------------------------------------------
void CompBotChassis::SetPositionParams(double kP, double kI, double kD, double kF, double leftTarget, double rightTarget)
{
	m_rightMasterMotor->SetF(kF); //set feed-forward gain
	m_rightMasterMotor->SetP(kP); //set p-gain
	m_rightMasterMotor->SetI(kI); //set i-gain
	m_rightMasterMotor->SetD(kD); //set d-gain

	m_leftMasterMotor->SetF(kF); //set feed-forward gain
	m_leftMasterMotor->SetP(kP); //set p-gain
	m_leftMasterMotor->SetI(kI); //set i-gain
	m_leftMasterMotor->SetD(kD); //set d-gain

	m_rightMasterMotor->Set(rightTarget * FEET_TO_ROTATIONS); //set target position in rotations
	m_leftMasterMotor->Set(leftTarget * FEET_TO_ROTATIONS); //set target position in rotations
}

//----------------------------------------------------------------------------------
// Method:      SetVelocityParams
// Description: Sets PID and F factors to the motors and sets target. Target is
//				double for velocity in feet per second. Make sure to set
//				motor to VELOCITY control first. Once target is set,
//				motor will immediately start using it for velocity control
// Params:		double kP - proportional-gain value
//				double kI - integral-gain value
//				double kD - derivative-gain value
//				double kF - feed-forward factor
//				double leftTarget - target speed in feet per second for left
//				double rightTarget - target speed in feet per second for right
//----------------------------------------------------------------------------------
void CompBotChassis::SetVelocityParams(double kP, double kI, double kD, double kF, double leftTarget, double rightTarget)
{
	//	SetControlMode(DragonTalon::VELOCITY);
	m_rightMasterMotor->SetF(kF); //set feed-forward gain
	m_rightMasterMotor->SetP(kP); //set p-gain
	m_rightMasterMotor->SetI(kI); //set i-gain
	m_rightMasterMotor->SetD(kD); //set d-gain

	m_leftMasterMotor->SetF(kF); //set feed-forward gain
	m_leftMasterMotor->SetP(kP); //set p-gain
	m_leftMasterMotor->SetI(kI); //set i-gain
	m_leftMasterMotor->SetD(kD); //set d-gain

	m_rightMasterMotor->Set(rightTarget * FPS_TO_RPM); //set target speed, converts from feet per second to rpm for talon use
	m_leftMasterMotor->Set(leftTarget * FPS_TO_RPM); //set target speed, converts from feet per second to rpm for talon use
}

void CompBotChassis::EnableCurrentLimiting() //Y key on driver
{
	//Enable current limit
	m_leftMasterMotor->EnableCurrentLimit(true);
	m_leftSlaveMotor->EnableCurrentLimit(true);
	m_rightMasterMotor->EnableCurrentLimit(true);
	m_rightSlaveMotor->EnableCurrentLimit(true);
}

void CompBotChassis::DisableCurrentLimiting() //A key on driver
{
	//Disable current limiting
	m_leftMasterMotor->EnableCurrentLimit(false);
	m_leftSlaveMotor->EnableCurrentLimit(false);
	m_rightMasterMotor->EnableCurrentLimit(false);
	m_rightSlaveMotor->EnableCurrentLimit(false);
}

void CompBotChassis::SetCurrentLimit(int amps)
{
	//Set current limit
	m_leftMasterMotor->SetCurrentLimit(amps);
	m_leftSlaveMotor->SetCurrentLimit(amps);
	m_rightMasterMotor->SetCurrentLimit(amps);
	m_rightSlaveMotor->SetCurrentLimit(amps);
}

CompBotChassis::CompBotChassis():
		//declare all of the motors
		m_leftSlaveMotor(new DragonTalon(LEFT_FRONT_DRIVE_MOTOR)),
		m_rightSlaveMotor(new DragonTalon(RIGHT_FRONT_DRIVE_MOTOR)),
		m_leftMasterMotor(new DragonTalon(LEFT_BACK_DRIVE_MOTOR)),
		m_rightMasterMotor(new DragonTalon(RIGHT_BACK_DRIVE_MOTOR))
{
	// Left Back Motor
	m_leftMasterMotor->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative); //sets the left master talon to use encoder as sensor
	m_leftMasterMotor->ConfigEncoderCodesPerRev(DRIVE_COUNTS_PER_REVOLUTION), // defines encoder counts per revolution
	m_leftMasterMotor->SetInverted (IS_LEFT_BACK_DRIVE_MOTOR_INVERTED);
	m_leftMasterMotor->SetSensorDirection (IS_LEFT_BACK_DRIVE_ENCODER_INVERTED);

	// Left Front Motor
	m_leftSlaveMotor->SetControlMode(DragonTalon::FOLLOWER); //sets the front left slave to follow output of the master
	m_leftSlaveMotor->Set(LEFT_BACK_DRIVE_MOTOR); //specifies that the left slave will follow master
	m_leftSlaveMotor->SetInverted(IS_LEFT_FRONT_DRIVE_MOTOR_INVERTED);

	// Right Back Motor
	m_rightMasterMotor->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative); //sets the right master talon to use encoder as sensor
	m_rightMasterMotor->ConfigEncoderCodesPerRev(DRIVE_COUNTS_PER_REVOLUTION), // defines encoder counts per revolution
	m_rightMasterMotor->SetInverted (IS_RIGHT_BACK_DRIVE_MOTOR_INVERTED);
	m_rightMasterMotor->SetSensorDirection (IS_RIGHT_BACK_DRIVE_ENCODER_INVERTED);

	// Right Front Motor
	m_rightSlaveMotor->SetControlMode(DragonTalon::FOLLOWER); //sets the front right to follow output of the master
	m_rightSlaveMotor->Set(RIGHT_BACK_DRIVE_MOTOR); //specifies that the right slave will follow master
	m_rightSlaveMotor->SetInverted (IS_RIGHT_FRONT_DRIVE_MOTOR_INVERTED);

	SetCurrentLimit( TALON_CURRENT_LIMIT );
	EnableCurrentLimiting();

	//	//Enable current limit
	//	m_leftMasterMotor->EnableCurrentLimit(true);
	//	m_leftSlaveMotor->EnableCurrentLimit(true);
	//	m_rightMasterMotor->EnableCurrentLimit(true);
	//	m_rightSlaveMotor->EnableCurrentLimit(true);
	//
	//	//Set current limit
	//	m_leftMasterMotor->SetCurrentLimit(TALON_CURRENT_LIMIT);
	//	m_leftSlaveMotor->SetCurrentLimit(TALON_CURRENT_LIMIT);
	//	m_rightMasterMotor->SetCurrentLimit(TALON_CURRENT_LIMIT);
	//	m_rightSlaveMotor->SetCurrentLimit(TALON_CURRENT_LIMIT);
}

} /* namespace Team302 */
