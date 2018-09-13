/*
 * Fuel.cpp
 *
 *  Created on: Feb 14, 2017
 *      Author: Mike
 */

#include <auton/Fuel.h>
#include <subsys/factories/FuelHandlerFactory.h>
#include <SmartDashboard/SmartDashboard.h>

namespace Team302
{
void Fuel::Init(PrimitiveParams* Parms)
{
	m_intakeFuel=Parms->GetIntakeFuel();
	m_shoot=Parms->GetShoot();
	m_shooterSpeed=Parms->GetShooterSpeed();
}
void Fuel::Run()
{
	float intakeSpeed = ( m_intakeFuel ) ? kIntakePower : 0.0;
	m_fuelHandler->SetIntakePower( intakeSpeed );

	// shooter is in volts 7.25 is good in teleop
	// shooter is in rpm 9500 is good in teleop
	float shootVolts = (m_shoot ) ? kShooterVolts : 0.0;
	m_fuelHandler->SetShooterPower( shootVolts );

	float liftSpeed = 0.0;
	float conveyorSpeed = 0.0;
	if( m_shoot && ( m_fuelHandler->GetShooterSpeed() > ( m_shooterSpeed * 0.9 )  ) )
	{
		liftSpeed = kLiftPower;
		conveyorSpeed = kLowerPower;
	} else if ( m_time > 100 )
	{
		liftSpeed = kLiftPower;
		conveyorSpeed = kLowerPower;
	}

	m_fuelHandler->SetLiftConveyerPower( liftSpeed );
	m_fuelHandler->SetLowerConveyerPower( conveyorSpeed );

//	frc::SmartDashboard::PutNumber("Shooter Sped", m_fuelHandler->GetShooterSpeed());

	m_time += LOOPS;
//if (m_shoot) {
//	m_fuelHandler->SetShooterPower(kShooterVolts);
//	m_fuelHandler->SetLiftConveyerPower(kLiftPower);
//	m_fuelHandler->SetLowerConveyerPower(kLowerPower);
//	m_fuelHandler->SetIntakePower(kIntakePower);
//}
//else
//{
//	m_fuelHandler->SetShooterPower(0.0);
//	m_fuelHandler->SetLiftConveyerPower(0.0);
//	m_fuelHandler->SetLowerConveyerPower(0.0);
//	m_fuelHandler->SetIntakePower(0.0);
//}
}
bool Fuel::IsDone()
{
	return true; //TODO: MIGHT CHECK IF THERE IS FUEL INSIDE THE ROBOT
}
Fuel::Fuel():
		m_fuelHandler(FuelHandlerFactory::GetInstance()->GetIFuelHandler()),
		m_intakeFuel(false),
		m_shoot(false),
		m_shooterSpeed(0.0),
		m_time(0.0)
{
	// TODO Auto-generated constructor stub
}
} /* namespace Team302 */
