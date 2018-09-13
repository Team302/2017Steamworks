/*
 * EightyChassis.cpp
 *
 *  Created on: Feb 13, 2017
 *      Author: Tumtu
 */

#include <CANTalon.h>
#include <utils/DragonTalon.h>
#include <utils/LimitValue.h>
#include <subsys/interfaces/IChassis.h>
#include <subsys/EightyBot/EightyChassis.h>
#include <subsys/EightyBot/EightyMap.h>
#include <SmartDashboard/SmartDashboard.h>

namespace Team302 {

	EightyChassis::EightyChassis():

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

	}

	float EightyChassis::GetLeftVelocity() const
	{
		float leftMotorVel = m_leftMasterMotor->GetEncVel();
		//value is negated to flip left side because invertSensor doesn't change that. Right side is fine as is
		return - ((leftMotorVel) * ENCODER_VELOCITY_CONVERSION );
	}

	float EightyChassis::GetRightVelocity() const
	{
		float rightMotorVel = m_rightMasterMotor->GetEncVel();
		return ((rightMotorVel) * ENCODER_VELOCITY_CONVERSION );
	}

	void EightyChassis::ResetDistance()
	{
		m_leftSlaveMotor->Reset();
		m_leftMasterMotor->Reset();
		m_rightSlaveMotor->Reset();
		m_rightMasterMotor->Reset();
	}

	void EightyChassis::SetLeftPower(float power)
	{
		//Make sure the left side speed is within range and then set both left motors to this speed
		float leftSpeed = LimitValue::ForceInRange( power, -0.98, 0.98 );
		m_leftMasterMotor->Set( leftSpeed );
	}

	void EightyChassis::SetRightPower(float power)
	{
		// Make sure the right side speed is within range and then set both right motors to this speed
		float rightSpeed = LimitValue::ForceInRange( power, -0.98, 0.98 );
		m_rightMasterMotor->Set( rightSpeed );
	}

	void EightyChassis::SetBrakeMode(bool mode)
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


	float EightyChassis::GetLeftDistance() const
	{
		float leftPos = m_leftMasterMotor->GetEncPosition();
		//value is negated to flip left side because invertSensor doesn't change that. Right side is fine as is
		return - ((leftPos) * ENCODER_DISTANCE_CONVERSION );
	}

	float EightyChassis::GetRightDistance() const
	{
		float rightPos = m_rightMasterMotor->GetEncPosition();
		return ((rightPos) * ENCODER_DISTANCE_CONVERSION );
	}


	float EightyChassis::GetLeftFrontDistance() const
	{
		return GetLeftDistance();
	}

	float EightyChassis::GetLeftBackDistance() const
	{
		return GetLeftDistance();
	}

	float EightyChassis::GetRightFrontDistance() const
	{
		return GetRightDistance();
	}

	float EightyChassis::GetRightBackDistance() const
	{
		return GetRightDistance();
	}

	float EightyChassis::GetLeftFrontVelocity() const
	{
		return GetLeftVelocity();
	}

	float EightyChassis::GetLeftBackVelocity() const
	{
		return GetLeftVelocity();
	}

	float EightyChassis::GetRightFrontVelocity() const
	{
		return GetRightVelocity();
	}

	float EightyChassis::GetRightBackVelocity() const
	{
		return GetRightVelocity();
	}

	void EightyChassis::SetControlMode(DragonTalon::DRAGON_CONTROL_MODE mode)
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
	void EightyChassis::SetPositionParams(double kP, double kI, double kD, double kF, double leftTarget, double rightTarget)
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
	void EightyChassis::SetVelocityParams(double kP, double kI, double kD, double kF, double leftTarget, double rightTarget)
	{
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

	void EightyChassis::EnableCurrentLimiting() //Y key
	{
		//TODO: too lazy to put kode here, we don't use EightyChassis anymore.
	}

	void EightyChassis::DisableCurrentLimiting() //A key
	{

	}

	void EightyChassis::SetCurrentLimit(int amps)
	{

	}

} /* namespace Team302 */

