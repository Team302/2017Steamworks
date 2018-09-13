/*
 * AtRope.cpp
 *
 *  Created on: Feb 4, 2017
 *      Author: Mike
 */

#include <teleopClimb/AtRope.h>
#include <subsys/factories/ClimberFactory.h>
#include <driverInputs/OI.h>
#include <teleopClimb/ClimbHandler.h>
#include <driverInputs/DragonXbox.h>
using namespace Team302;
AtRope::AtRope(): IClimbState(), m_climber( ClimberFactory::GetInstance()->GetIClimber())
{
}


void  AtRope::InitState()
{
	m_climber->SetPower( AT_ROPE_WINCH_POWER);
}
void  AtRope::RunState()
{

//	if(OI::GetInstance()->GetButton(OI::START_WINCH))
	if ( DragonXbox::GetCopilot()->GetButton( DragonXbox::A_BUTTON ) )
	{
		ClimbHandler::GetInstance()->SetCurrentState( SPIN_WINCH );
	}
	else
	{
		m_climber->SetPower( AT_ROPE_WINCH_POWER );
	}
}

std::string AtRope::GetName() const
{
	return std::string( "At Rope");
}
