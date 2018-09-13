/*
 * SpinWinch.cpp
 *
 *  Created on: Feb 4, 2017
 *      Author: Mike
 */
#include <teleopClimb/SpinWinch.h>
#include <subsys/factories/ClimberFactory.h>
#include <subsys/interfaces/IClimber.h>
#include <driverInputs/OI.h>
#include <teleopClimb/ClimbHandler.h>
#include <driverInputs/DragonXbox.h>
#include <SmartDashboard/SmartDashboard.h>
using namespace Team302;
SpinWinch::SpinWinch():IClimbState(), m_climber( ClimberFactory::GetInstance()->GetIClimber())
{
}
void  SpinWinch::InitState()
{
	m_climber->SetPower(SPIN_WINCH_POWER);
}
void  SpinWinch::RunState()
{
//	if(OI::GetInstance()->GetButton(OI::START_WINCH))
	if ( DragonXbox::GetCopilot()->GetButton( DragonXbox::A_BUTTON ) )
	{
		if(m_climber->IsRobotLifting())
		{
			ClimbHandler::GetInstance()->SetCurrentState(CLIMB_ROPE);
		}
		else
		{
			m_climber->SetPower(SPIN_WINCH_POWER);
		}
	}
	else
	{
		ClimbHandler::GetInstance()->SetCurrentState(STOP_WINCH);
	}
}

std::string SpinWinch::GetName() const
{
	return std::string( "Spin Winch");
}
