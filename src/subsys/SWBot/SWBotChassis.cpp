/*
 * SWBotChassis.cpp
 *
 *  Created on: Jan 16, 2017
 *      Author: Tumtu
 */

#include <CANTalon.h>
#include <utils/DragonTalon.h>
#include <utils/LimitValue.h>
#include <subsys/interfaces/IChassis.h>
#include <subsys/SWBot/SWBotChassis.h>
#include <subsys/SWBot/SWMap.h>
#include <SmartDashboard/SmartDashboard.h>

namespace Team302
{

	float SWBotChassis::GetLeftVelocity() const
	{
//		float frontLeftMotorVel = m_leftSlaveMotor->GetEncVel();
//		float rearLeftMotorVel = m_leftMasterMotor->GetEncVel();
//
//		return ((( frontLeftMotorVel + rearLeftMotorVel ) / 2 ) * ENCODER_VELOCITY_CONVERSION );

		float rearLeftMotorVel = m_leftMasterMotor->GetEncVel();
		return ((rearLeftMotorVel) * ENCODER_VELOCITY_CONVERSION );
	}

	float SWBotChassis::GetRightVelocity() const
	{
//		float frontRightMotorVel = m_rightSlaveMotor->GetEncVel();
		float rearRightMotorVel = m_rightMasterMotor->GetEncVel();

		return ((rearRightMotorVel) * ENCODER_VELOCITY_CONVERSION);
//
//		float frontRightMotorVel = m_rightSlaveMotor->GetEncVel();
//		float rearRightMotorVel = m_rightMasterMotor->GetEncVel();
//
//		return ((( frontRightMotorVel + rearRightMotorVel) / 2) * ENCODER_VELOCITY_CONVERSION);
	}

	void SWBotChassis::ResetDistance()
	{
//		m_leftSlaveMotor->Reset();
		m_leftMasterMotor->Reset();
//		m_rightSlaveMotor->Reset();
		m_rightMasterMotor->Reset();
	}

	void SWBotChassis::SetLeftPower(float power)
	{
		//Make sure the left side speed is within range and then set both left motors to this speed
		float leftSpeed = LimitValue::ForceInRange( power, -0.98, 0.98 );
		m_leftMasterMotor->Set( leftSpeed );
	}

	void SWBotChassis::SetRightPower(float power)
	{
		// Make sure the right side speed is within range and then set both right motors to this speed
		float rightSpeed = LimitValue::ForceInRange( power, -0.98, 0.98 );
		m_rightMasterMotor->Set( rightSpeed);
	}

	void SWBotChassis::SetBrakeMode(bool mode)
	{
		if(mode)
		{
//			m_leftSlaveMotor->ConfigNeutralMode( frc::CANSpeedController::kNeutralMode_Brake );
//			m_rightSlaveMotor->ConfigNeutralMode( frc::CANSpeedController::kNeutralMode_Brake );
			m_leftMasterMotor->ConfigNeutralMode( frc::CANSpeedController::kNeutralMode_Brake );
			m_rightMasterMotor->ConfigNeutralMode( frc::CANSpeedController::kNeutralMode_Brake );
		}
		else
		{
//			m_leftSlaveMotor->ConfigNeutralMode( frc::CANSpeedController::kNeutralMode_Coast );
//			m_rightSlaveMotor->ConfigNeutralMode( frc::CANSpeedController::kNeutralMode_Coast );
			m_leftMasterMotor->ConfigNeutralMode( frc::CANSpeedController::kNeutralMode_Coast );
			m_rightMasterMotor->ConfigNeutralMode( frc::CANSpeedController::kNeutralMode_Coast );
		}
	}

	SWBotChassis::SWBotChassis():

			//declare all of the motors
			m_leftSlaveMotor(new DragonTalon(LEFT_FRONT_DRIVE_MOTOR)),
			m_rightSlaveMotor(new DragonTalon(RIGHT_FRONT_DRIVE_MOTOR)),
			m_leftMasterMotor(new DragonTalon(LEFT_BACK_DRIVE_MOTOR)),
			m_rightMasterMotor(new DragonTalon(RIGHT_BACK_DRIVE_MOTOR))
	{
			m_leftSlaveMotor->SetControlMode(DragonTalon::FOLLOWER); //sets the front left slave to follow output of the master
			m_leftSlaveMotor->Set(LEFT_BACK_DRIVE_MOTOR); //specifies that the left slave will follow master
			m_rightSlaveMotor->SetControlMode(DragonTalon::FOLLOWER); //sets the front right to follow output of the master
			m_rightSlaveMotor->Set(RIGHT_BACK_DRIVE_MOTOR); //specifies that the right slave will follow master

			m_leftMasterMotor->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative); //sets the left master talon to use encoder as sensor
			m_leftMasterMotor->ConfigEncoderCodesPerRev(DRIVE_COUNTS_PER_REVOLUTION), // defines encoder counts per revolution
			m_rightMasterMotor->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative); //sets the right master talon to use encoder as sensor
			m_rightMasterMotor->ConfigEncoderCodesPerRev(DRIVE_COUNTS_PER_REVOLUTION), // defines encoder counts per revolution

			m_leftSlaveMotor->SetInverted(IS_LEFT_FRONT_DRIVE_MOTOR_INVERTED);
			m_leftSlaveMotor->SetSensorDirection (IS_LEFT_FRONT_DRIVE_ENCODER_INVERTED);
			m_rightSlaveMotor->SetInverted (IS_RIGHT_FRONT_DRIVE_MOTOR_INVERTED);
			m_rightSlaveMotor->SetSensorDirection (IS_RIGHT_BACK_DRIVE_ENCODER_INVERTED);

			m_leftMasterMotor->SetInverted (IS_LEFT_BACK_DRIVE_MOTOR_INVERTED);
			m_leftMasterMotor->SetSensorDirection (IS_LEFT_BACK_DRIVE_ENCODER_INVERTED);
			m_rightMasterMotor->SetInverted (IS_RIGHT_BACK_DRIVE_MOTOR_INVERTED);
			m_rightMasterMotor->SetSensorDirection (IS_RIGHT_BACK_DRIVE_ENCODER_INVERTED);
	}


	float SWBotChassis::GetLeftDistance() const
	{
//		float FrontLeftPos = m_leftSlaveMotor->GetEncPosition();
		float RearLeftPos = m_leftMasterMotor->GetEncPosition();

		//value is negated to flip left side because invertSensor doesn't change that. Right side is fine as is
//		return - ((( FrontLeftPos + RearLeftPos) / 2 ) * ENCODER_DISTANCE_CONVERSION );
		return - (((RearLeftPos) / 1.0 ) * ENCODER_DISTANCE_CONVERSION );
	}

	float SWBotChassis::GetRightDistance() const
	{
//		float FrontRightPos = m_rightSlaveMotor->GetEncPosition();
		float RearRightPos = m_rightMasterMotor->GetEncPosition();

//		return ((( FrontRightPos + RearRightPos) / 2 ) * ENCODER_DISTANCE_CONVERSION );
		return (((RearRightPos) / 1.0 ) * ENCODER_DISTANCE_CONVERSION );
	}

	float SWBotChassis::GetLeftFrontDistance() const
	{
//		float leftFrontEncoderPos = static_cast<float>(m_leftSlaveMotor->GetEncPosition());

		//value is negated to flip left side because invertSensor doesn't change that. Right side is fine as is
//		return - (leftFrontEncoderPos * ENCODER_DISTANCE_CONVERSION);
		return GetLeftBackDistance();
	}

	float SWBotChassis::GetLeftBackDistance() const
	{
		float leftBackEncoderPos = static_cast<float>(m_leftMasterMotor->GetEncPosition());

		//value is negated to flip left side because invertSensor doesn't change that. Right side is fine as is
		return - (leftBackEncoderPos * ENCODER_DISTANCE_CONVERSION);
	}

	float SWBotChassis::GetRightFrontDistance() const
	{
//		float rightFrontEncoderPos = static_cast<float>(m_rightSlaveMotor->GetEncPosition());
//		return (rightFrontEncoderPos * ENCODER_DISTANCE_CONVERSION);
		return GetRightFrontDistance();
	}

	float SWBotChassis::GetRightBackDistance() const
	{
		float rightBackEncoderPos = static_cast<float>(m_rightMasterMotor->GetEncPosition());
		return (rightBackEncoderPos * ENCODER_DISTANCE_CONVERSION);
	}

	float SWBotChassis::GetLeftFrontVelocity() const
	{
//		float leftFrontEncoderVel = static_cast<float>(m_leftSlaveMotor->GetEncVel());
		//value is negated to flip left side because invertSensor doesn't change that. Right side is fine as is
//		return - (leftFrontEncoderVel * ENCODER_VELOCITY_CONVERSION);
		return GetLeftBackVelocity();
	}

	float SWBotChassis::GetLeftBackVelocity() const
	{
		float leftBackEncoderVel = static_cast<float>(m_leftMasterMotor->GetEncVel());
		//value is negated to flip left side because invertSensor doesn't change that. Right side is fine as is
		return - (leftBackEncoderVel * ENCODER_VELOCITY_CONVERSION);
	}

	float SWBotChassis::GetRightFrontVelocity() const
	{
//		float RightFrontEncoderVel = static_cast<float>(m_rightSlaveMotor->GetEncVel());
//		return (RightFrontEncoderVel * ENCODER_VELOCITY_CONVERSION);
		return GetRightBackVelocity();
	}

	float SWBotChassis::GetRightBackVelocity() const
	{
		float RightBackEncoderVel = static_cast<float>(m_rightMasterMotor->GetEncVel());
		return (RightBackEncoderVel * ENCODER_VELOCITY_CONVERSION);
	}

	void SWBotChassis::SetControlMode(DragonTalon::DRAGON_CONTROL_MODE mode)
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
//			m_rightMasterMotor->SetControlMode(DragonTalon::FOLLOWER);
//			m_leftMasterMotor->SetControlMode(DragonTalon::FOLLOWER);
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
	void SWBotChassis::SetPositionParams(double kP, double kI, double kD, double kF, double leftTarget, double rightTarget)
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
	void SWBotChassis::SetVelocityParams(double kP, double kI, double kD, double kF, double leftTarget, double rightTarget)
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

	void SWBotChassis::EnableCurrentLimiting()
	{
		//todo:
	}

	void SWBotChassis::DisableCurrentLimiting()
	{
		//todo:
	}

	void SWBotChassis::SetCurrentLimit(int amps)
	{
		//todo:
	}

} /* namespace Team302 */
