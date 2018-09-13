/*
 * DoNothing.cpp
 *
 *  Created on: Jan 18, 2017
 *      Author: Mike, josh?????@@?@?@?@?@222@?@!?!?!
 *      Documentation: The Realest of Authors
 */

#include <auton/DoNothing.h>
#include <CANTalon.h>
#include <auton/PrimitiveParams.h>
#include <subsys/factories/ChassisFactory.h>
#include <auton/IPrimitive.h>

namespace Team302 {
	DoNothing::DoNothing() : m_maxTime( 0.0 ),
							 m_currentTime( 0.0 ),
							 m_chassis( ChassisFactory::GetInstance()->GetIChassis() )
	{
	}
	void DoNothing::Init(PrimitiveParams*	parms)
	{
		m_chassis->SetControlMode(DragonTalon::THROTTLE); //set chassis to use normal throttle control
		/* This gets the instance of chassis factory, sets the max time
		 * based on Parms time, and sets the current time to 0 */
		m_maxTime = parms->GetTime();
		m_currentTime = 0.0;
	}
	void DoNothing::Run()
	{
		/* This changes the powers of each time to absolutely nothing then
		 * it adds time to the current time */
		m_chassis->SetLeftPower(0.0);
		m_chassis->SetRightPower(0.0);
		m_currentTime += LOOP_LENGTH; //Incrememt by 20 ms
	}
	bool DoNothing::IsDone()
	{
		/* This does a thing i'm not 100% sure about, but it probably
		 * stops the robot if the current time is greater than the max time */
		return m_currentTime >= m_maxTime;
	}
} /* namespace Team302 */


