/*
 * StopWinch.cpp
 *
 *  Created on: February 4, 2017
 *      Author: Magic Mike Wazowski
 */
#include <teleopClimb/StopWinch.h>
#include <driverInputs/OI.h>
#include <subsys/factories/ClimberFactory.h>
#include <teleopClimb/ClimbHandler.h>
#include <driverInputs/DragonXbox.h>
using namespace Team302;
StopWinch::StopWinch(): IClimbState(), m_climber( ClimberFactory::GetInstance()->GetIClimber())
{
	
}
void  StopWinch::InitState()
{
	m_climber->SetPower(STOP_WINCH_POWER);
}
void  StopWinch::RunState()
{
//	if(OI::GetInstance()->GetButton(OI::START_WINCH))
	if ( DragonXbox::GetCopilot()->GetButton( DragonXbox::A_BUTTON ) )
	{
		ClimbHandler::GetInstance()->SetCurrentState(SPIN_WINCH);
	}
	m_climber->SetPower(STOP_WINCH_POWER);
}

std::string StopWinch::GetName() const
{
	return std::string( "Stop Winch");
}