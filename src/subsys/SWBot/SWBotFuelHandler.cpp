/*
 * SWBotFuelHandler.cpp
 *
 *  Created on: Jan 16, 2017
 *      Author: Neethan Punniyamoorthy
 */
//#include <driverInputs/DragonXbox.h>		TODO:: not here
#include <subsys/SWBot/SWBotFuelHandler.h>
#include <subsys/SWBot/SWMap.h>
#include <SmartDashboard/SmartDashboard.h>
#include <utils/DragonTalon.h>

namespace Team302 {

float SWBotFuelHandler::GetShooterSpeed() const
{
	float speed = static_cast<float>(m_shooterMotor->GetEncVel());
//	float speed = m_shooterMotor->GetSpeed();
	return ( speed* ENCODER_VELOCITY_CONVERSION);
}

float SWBotFuelHandler::GetIntakeSpeed() const
{
	return -1;
}

float SWBotFuelHandler::GetRange() const
{
	///TODO:unsure for the positioning stuff, should get halp
	return 0.0; // TODO: fix
}


void SWBotFuelHandler::SetLowerConveyerPower(float power) 		// JW - added
{
	m_lowerConveyerMotor->SetControlMode(DragonTalon::THROTTLE); //sets motor to throttle control mode
	m_lowerConveyerMotor->Set(power);
}
void SWBotFuelHandler::SetLiftConveyerPower(float power) 			// JW - added
{
	m_liftConveyerMotor->SetControlMode(DragonTalon::THROTTLE); //sets motor to throttle control mode
	m_liftConveyerMotor->Set(power);
}

void SWBotFuelHandler::SetIntakePower(float power)
{
	m_intakeMotor->SetControlMode(DragonTalon::THROTTLE); //sets motor to throttle control mode
	m_intakeMotor->Set(power);
}

void SWBotFuelHandler::SetShooterPower(float power)
{
	m_shooterMotor->SetControlMode(DragonTalon::THROTTLE); //sets motor to throttle control mode
	m_shooterMotor->Set(power);
}


void SWBotFuelHandler::SetShooterVelocity(float target) 		// JW - added
{
	m_shooterMotor->SetControlMode(DragonTalon::VELOCITY); //sets motor to PID control mode
	m_shooterMotor->Set(target); //sets target for velocity control
}

SWBotFuelHandler::SWBotFuelHandler()
{
	//declare motors
	m_shooterMotor = new DragonTalon(SHOOTER_MOTOR);
	m_intakeMotor = new DragonTalon(INTAKE_MOTOR);
	m_lowerConveyerMotor = new DragonTalon(LOWER_CONVEYER_MOTOR);
	m_liftConveyerMotor = new DragonTalon(LIFT_CONVEYER_MOTOR);

	//set up encoder feedback on shooter and intake
	m_shooterMotor->SetFeedbackDevice(DragonTalon::CtreMagEncoder_Relative); //sets the shooter talon to use encoder as sensor
	m_shooterMotor->ConfigEncoderCodesPerRev(SHOOTER_COUNTS_PER_ROTATION); //sets number of encoder counts per rotation for velocity control use
	m_intakeMotor->SetFeedbackDevice(DragonTalon::CtreMagEncoder_Relative); //sets the intake talon to use encoder as sensor
	m_intakeMotor->ConfigEncoderCodesPerRev(INTAKE_COUNTS_PER_ROTATION); //sets number of encoder counts per rotation for velocity control and feedback

	//invert shooter motor accordingly
	m_shooterMotor->SetSensorDirection(IS_SHOOTER_ENCODER_INVERTED);

	m_shooterMotor->SetClosedLoopParams(kP, kI, kD, kF);
}

SWBotFuelHandler::~SWBotFuelHandler()
{
	delete m_shooterMotor;
		m_shooterMotor = nullptr;
	delete m_intakeMotor;
		m_intakeMotor = nullptr;
	delete m_lowerConveyerMotor;
		m_lowerConveyerMotor = nullptr;
	delete m_liftConveyerMotor;
		m_liftConveyerMotor = nullptr;
}

} /* namespace Team302 */
