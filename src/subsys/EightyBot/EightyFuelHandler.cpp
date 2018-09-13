/*
 * EightyFuelHandler.cpp
 *
 *  Created on: Feb 5, 2017
 *      Author: Elite
 */

#include <subsys/EightyBot/EightyFuelHandler.h>
#include <utils/DragonTalon.h>
#include <WPILib.h>
#include <CANTalon.h>
#include <subsys/EightyBot/EightyMap.h>
#include <SmartDashboard/SmartDashboard.h>
namespace Team302 {


	//----------------------------------------------------------------------------------
	// Method:      GetShooterSpeed
	// Description: Gets speed in RPM of shooter wheels
	// Returns:		float speed
	//----------------------------------------------------------------------------------
	float EightyFuelHandler::GetShooterSpeed() const
	{
		return m_masterShooterMotor->GetSpeed();
	}

	//----------------------------------------------------------------------------------
	// Method:      GetIntakeSpeed
	// Description: Gets speed in RPM of intake
	// Returns:		float speed
	//----------------------------------------------------------------------------------
	float EightyFuelHandler::GetIntakeSpeed() const
	{
		//this should return speed in RPM, because the GetSpeed method
		//uses the encoder counts per rotation set in the constructor
		return m_intakeMotor->GetSpeed();
	}

	//----------------------------------------------------------------------------------
	// Method:      GetRange
	// Description: Gets rangefinder distance in inches
	// Returns:		float range
	//----------------------------------------------------------------------------------
	float EightyFuelHandler::GetRange() const
	{

		return -1;
	}

	//Setters
	//----------------------------------------------------------------------------------
	// Method:      SetLowerConveyer
	// Description: Sets speed of lower conveyer belt from -1.0 to 1.0
	// Params:		float power
	//----------------------------------------------------------------------------------
	void EightyFuelHandler::SetLowerConveyerPower(float power)
	{
		m_lowerConveyerMotor->SetControlMode(DragonTalon::THROTTLE); //sets motor to throttle control mode
		m_lowerConveyerMotor->Set(power);
	}

	//---------------------------------------------------------------------------------
	// Method:      SetLiftConveyor
	// Description: Sets power from -1.0 to 1.0 for the lift conveyer belt
	// Params:		float power
	//----------------------------------------------------------------------------------
	void EightyFuelHandler::SetLiftConveyerPower(float power)
	{
		m_liftConveyerMotor->SetControlMode(DragonTalon::THROTTLE); //sets motor to throttle control mode
		m_liftConveyerMotor->Set(power);
	}

	//----------------------------------------------------------------------------------
	// Method:      SetIntakePower
	// Description: Sets power of intake motor. -1.0 to 1.0
	// Params:		float power
	//----------------------------------------------------------------------------------
	void EightyFuelHandler::SetIntakePower(float power)
	{
		m_intakeMotor->SetControlMode(DragonTalon::THROTTLE); //sets motor to throttle control mode
		m_intakeMotor->Set(power);
	}

	//----------------------------------------------------------------------------------
	// Method:      SetShooterPower
	// Description: Sets power to shooter motor. -1.0 to 1.0
	// Params:		float power
	//----------------------------------------------------------------------------------
	void EightyFuelHandler::SetShooterPower(float power)
	{
		m_masterShooterMotor->SetControlMode(DragonTalon::THROTTLE); //sets master shooter motor to PID control mode
//		m_masterShooterMotor->SetControlMode(DragonTalon::VOLTAGE);
		m_masterShooterMotor->Set(power);
	}

	//----------------------------------------------------------------------------------
	// Method:      SetShooterVelocity
	// Description: Sets target velocity to shooter motor, will use PID control on talon
	// Params:		float target
	//----------------------------------------------------------------------------------
	void EightyFuelHandler::SetShooterVelocity(float target)
	{
		m_masterShooterMotor->SetControlMode(DragonTalon::VELOCITY); //sets master shooter motor to PID control mode
		m_masterShooterMotor->Set(target); //sets target for velocity control
}

EightyFuelHandler::EightyFuelHandler()
{
	//definitions of all of the fuel motors
	m_intakeMotor = new DragonTalon(INTAKE_MOTOR);
	m_lowerConveyerMotor = new DragonTalon(LOWER_CONVEYER_MOTOR);
	m_liftConveyerMotor = new DragonTalon(LIFT_CONVEYER_MOTOR);
	m_masterShooterMotor = new DragonTalon(MASTER_SHOOTER_MOTOR);
	m_slaveShooterMotor = new DragonTalon(SLAVE_SHOOTER_MOTOR);

	//set inversions on all fuel motors
	m_intakeMotor->SetInverted(IS_INTAKE_MOTOR_INVERTED);
	m_lowerConveyerMotor->SetInverted(IS_LOWER_CONVEYER_MOTOR_INVERTED);
	m_liftConveyerMotor->SetInverted(IS_LIFT_CONVEYER_MOTOR_INVERTED);
	m_masterShooterMotor->SetInverted(IS_MASTER_SHOOTER_MOTOR_INVERTED);
//	m_slaveShooterMotor->SetInverted(IS_SLAVE_SHOOTER_MOTOR_INVERTED);
	m_slaveShooterMotor->SetClosedLoopOutputDirection(IS_SLAVE_SHOOTER_MOTOR_INVERTED);

	//invert needed encoders
	m_masterShooterMotor->SetSensorDirection(IS_SHOOTER_ENCODER_INVERTED);

	m_slaveShooterMotor->SetControlMode(DragonTalon::FOLLOWER); //sets the second shooter to follow output of the first
	m_slaveShooterMotor->Set(MASTER_SHOOTER_MOTOR); //specifies that the slave shooter will follow master

	m_masterShooterMotor->SetFeedbackDevice(DragonTalon::CtreMagEncoder_Relative); //sets the master talon to use encoder as sensor
//	m_masterShooterMotor->ConfigEncoderCodesPerRev(SHOOTER_COUNTS_PER_ROTATION); //sets number of encoder counts per rotation for velocity control use

	m_intakeMotor->SetFeedbackDevice(DragonTalon::CtreMagEncoder_Relative); //sets the intake to use encoder as sensor
//	m_intakeMotor->ConfigEncoderCodesPerRev(INTAKE_COUNTS_PER_ROTATION); //sets number of encoder counts per rotation for velocity control use

	m_masterShooterMotor->SetClosedLoopParams(kP, kI, kD, kF);
}

EightyFuelHandler::~EightyFuelHandler()
{
	delete m_slaveShooterMotor;
		m_slaveShooterMotor = nullptr;
	delete m_intakeMotor;
		m_intakeMotor = nullptr;
	delete m_masterShooterMotor;
		m_masterShooterMotor = nullptr;
	delete m_lowerConveyerMotor;
		m_lowerConveyerMotor = nullptr;
	delete m_liftConveyerMotor;
		m_liftConveyerMotor = nullptr;
}

} /* namespace Team302 */
