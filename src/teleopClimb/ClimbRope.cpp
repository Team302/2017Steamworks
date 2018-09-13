/*
 * ClimbRope.cpp
 *
 *  Created on: Feb 4, 2017
 *      Author: Mike
 */

#include <teleopClimb/ClimbRope.h>
#include <subsys/factories/ClimberFactory.h>
#include <driverInputs/OI.h>
#include <teleopClimb/ClimbHandler.h>
#include <driverInputs/DragonXbox.h>
using namespace Team302;
ClimbRope::ClimbRope() : IClimbState(), m_climber( ClimberFactory::GetInstance()->GetIClimber())
{
}
void  ClimbRope::InitState()
{
	m_climber->SetPower(CLIMB_WINCH_POWER);
}
void  ClimbRope::RunState()
{
//	if(!OI::GetInstance()->GetButton(OI::START_WINCH))
	if ( !DragonXbox::GetCopilot()->GetButton( DragonXbox::A_BUTTON ) )
	{
		ClimbHandler::GetInstance()->SetCurrentState(STOP_WINCH);
	}
	m_climber->SetPower(CLIMB_WINCH_POWER);
}

std::string ClimbRope::GetName() const
{
	return std::string( "Climb Rope");
}