/*
 * teleopHold.cpp
 *
 *  Created on: Mar 11, 2017
 *      Author: Tumtu
 */

#include <teleopHold/teleopHold.h>
#include <driverInputs/DragonXbox.h>

namespace Team302 {

teleopHold::teleopHold() :
				m_chassis(ChassisFactory::GetInstance()->GetIChassis()),
				m_reset( false )
{
}

void teleopHold::UseJoystickHoldFunction()
{
	if( DragonXbox::GetDriver()->GetButton( DragonXbox::RIGHT_TRIGGER_PRESSED ) )
	{
		if (m_reset)
		{
			m_chassis->ResetDistance();
			m_reset = false;
		}

		m_chassis->SetBrakeMode(false);
		m_chassis->SetControlMode(DragonTalon::POSITION); //sets chassis to position hold control method
		m_chassis->SetPositionParams(kP, kI, kD, kF, 0.0, 0.0);
	} else
	{
		m_chassis->SetControlMode(DragonTalon::THROTTLE);
		m_reset = true;
	}
}

} /* namespace Team302 */
