/*
 * FuelManip.cpp
 *
 *  Created on: Jan 14, 2017
 *      Author: Elite
 */

#include <teleopFuel/FuelManip.h>
#include <driverInputs/OI.h>
#include <driverInputs/DragonXbox.h>
#include <subsys/interfaces/IFuelHandler.h>
#include <subsys/factories/FuelHandlerFactory.h>
#include <SmartDashboard/SmartDashboard.h>
#include <auton/IPrimitive.h>

namespace Team302 {

//----------------------------------------------------------------------------------
// Method:      Run
// Description: Call this method to do fuel handling. It checks the OI for which
//				buttons are pressed and does the appropriate functions.
// Returns:		void
//----------------------------------------------------------------------------------
void FuelManip::Run()
{

	//following if statements check the buttons from the OI. If the button is pressed,
	//it calls the appropriate method within this class
	float intakePower = 0.0;
	float lowerConveyorPower = 0.0;

	if ( DragonXbox::GetCopilot()->GetButton( DragonXbox::LEFT_TRIGGER_PRESSED ))
	{
		intakePower = INTAKE_POWER;
		lowerConveyorPower = LOWER_CONVEYOR_POWER;
	}
	
	if ( DragonXbox::GetCopilot()->GetButton( DragonXbox::LEFT_BUMPER ))
	{
		intakePower = -INTAKE_POWER;
		lowerConveyorPower = -LOWER_CONVEYOR_POWER;
	}

	m_fuelHandler->SetIntakePower( intakePower );

	float shooterPower = 0.0;
	float shooterRPM = 0.0;
	float liftConveyorPower = 0.0;

	// TODO:  Currently using a number of loops the shooter wheels are spinning before starting the elevator
	//        and the conveyor.  Need to move to a velocity control.

	if ( DragonXbox::GetCopilot()->GetButton( DragonXbox::RIGHT_BUMPER ) )
	{
		liftConveyorPower = LIFT_CONVEYOR_POWER;
		shooterRPM = SHOOTER_RPM;
		
		float adjustment = DragonXbox::GetCopilot()->GetAxis(DragonXbox::Y_AXIS_LEFT_JOYSTICK);

		if (adjustment > 0.2)
		{
					adjustment -= 0.2;
				}
				else if (adjustment < -0.2)
				{
					adjustment += 0.2;
				}
				adjustment *= (1.0 / (1.0 - 0.2)) * SHOOTER_ADJUST_SCALE;
				frc::SmartDashboard::PutNumber("What Is Adjustment", adjustment);
			shooterPower = SHOOTER_VOLTAGE + adjustment;

		if (m_fuelHandler->GetShooterSpeed() > (SHOOTER_RPM * 0.7))//0.75, 0.8------------------.7
		{
			
//			lowerConveyorPower = LOWER_CONVEYOR_POWER;
			
			if (intervalTimer > CONVEYOR_PAUSE_TIME)
			{
				liftConveyorPower = LIFT_CONVEYOR_POWER;
				lowerConveyorPower = LOWER_CONVEYOR_POWER;
			}
			else if (intervalTimer > 0)
			{
				liftConveyorPower = 0;
				lowerConveyorPower = 0;
				liftConveyorPower = LIFT_CONVEYOR_POWER;
				lowerConveyorPower = LOWER_CONVEYOR_POWER;
			}
			else
			{
				intervalTimer = CONVEYOR_PAUSE_TIME + CONVEYOR_PAUSE_INTERVAL;
			}
		}	else if ( DragonXbox::GetCopilot()->GetButton( DragonXbox::RIGHT_TRIGGER ))
	{
		liftConveyorPower = LIFT_CONVEYOR_POWER;

		m_fuelHandler->SetLiftConveyerPower( liftConveyorPower );
	}

		loops++;
		intervalTimer -= LOOP_LENGTH;

		if (loops<75)
		{
			intakePower = INTAKE_POWER;
		}
		else if (loops < 150)
		{
			intakePower = 0.0;
		}
		else
		{
			loops = 0;
		}
	}

	else
	{
		m_numLoopsShooterRunning = 0;
	}
	if (!shooterRPM == 0)
	{
		m_fuelHandler->SetShooterPower( shooterPower );
	}
	else
	{
		m_fuelHandler->SetShooterPower(0.0);
	}

	if ( DragonXbox::GetCopilot()->GetButton( DragonXbox::Y_BUTTON ) )
	{
		lowerConveyorPower = LOWER_CONVEYOR_POWER;
	}
	
	m_fuelHandler->SetLiftConveyerPower( liftConveyorPower );
	m_fuelHandler->SetLowerConveyerPower( lowerConveyorPower );
	m_fuelHandler->SetIntakePower(intakePower);

	frc::SmartDashboard::PutNumber("Conveyor speed", lowerConveyorPower);
	frc::SmartDashboard::PutNumber("Shooter Counts", m_fuelHandler->GetShooterSpeed());
	frc::SmartDashboard::PutNumber("Adujustment Speed", shooterPower);
}

//----------------------------------------------------------------------------------
// Method:      ActivateIntake
// Description: Turns on the intake to a speed set in .h file
// Returns:		void
//----------------------------------------------------------------------------------
void FuelManip::ActivateIntake()
{
	m_fuelHandler->SetIntakePower( INTAKE_POWER );
}

//----------------------------------------------------------------------------------
// Method:      StopIntake
// Description: Turns off intake motor
// Returns:		void
//----------------------------------------------------------------------------------
void FuelManip::StopIntake()
{
	m_fuelHandler->SetIntakePower(0.0);
}

//----------------------------------------------------------------------------------
// Method:      ActivateLoad
// Description: Turns on both of the conveyers to a preset speed in the .h file
// Returns:		void
//----------------------------------------------------------------------------------
void FuelManip::ActivateLoad()
{
	m_fuelHandler->SetLowerConveyerPower( LOWER_CONVEYOR_POWER );
	m_fuelHandler->SetLiftConveyerPower( LIFT_CONVEYOR_POWER );
}

//----------------------------------------------------------------------------------
// Method:      StopLoad
// Description: Turns off the conveyer motors
// Returns:		void
//----------------------------------------------------------------------------------
void FuelManip::StopLoad()
{
	m_fuelHandler->SetLowerConveyerPower(0.0);
	m_fuelHandler->SetLiftConveyerPower(0.0);
}

//----------------------------------------------------------------------------------
// Method:      ActivateIntake
// Description: Turns on the intake to a speed set in .h file
//				Uses PID control
// Returns:		void
//----------------------------------------------------------------------------------
void FuelManip::ActivateShooter()
{
	m_fuelHandler->SetShooterPower(SHOOTER_VOLTAGE);
}

//----------------------------------------------------------------------------------
// Method:      StopShooter
// Description: Turns off the shooter motors
// Returns:		void
//----------------------------------------------------------------------------------
void FuelManip::StopShooter()
{
	m_fuelHandler->SetShooterPower(0.0);
}


FuelManip::FuelManip() : m_OI( OI::GetInstance()) ,
						 m_fuelHandler( FuelHandlerFactory::GetInstance()->GetIFuelHandler()),
						 m_numLoopsShooterRunning( 0 ),
						 intervalTimer(CONVEYOR_PAUSE_INTERVAL + CONVEYOR_PAUSE_TIME)
{
	m_OI->SetCurve( OI::CONTROL_SHOOTER_SPEED, OI::AXIS_CUBIC );
	DragonXbox::GetCopilot()->SetCurve( DragonXbox::Y_AXIS_LEFT_JOYSTICK, DragonXbox::AXIS_LINEAR );
}

FuelManip::~FuelManip()
{

}

} /* namespace Team302 */
