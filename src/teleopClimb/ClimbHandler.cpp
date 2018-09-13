/*
 * ClimbHandler.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: Mike
 */
#include <teleopClimb/ClimbHandler.h>
#include <teleopClimb/AtRope.h>
#include <teleopClimb/SpinWinch.h>
#include <teleopClimb/StopWinch.h>
#include <teleopClimb/ClimbRope.h>
#include <teleopClimb/IClimbState.h>

#include <SmartDashboard/SmartDashboard.h>

using namespace Team302;


ClimbHandler* ClimbHandler::m_instance = nullptr;

ClimbHandler*    ClimbHandler::GetInstance()
{
    if ( ClimbHandler::m_instance == nullptr )
    {
    	ClimbHandler::m_instance = new ClimbHandler();
    }
    return ClimbHandler::m_instance;
}
void ClimbHandler::InitState()//initialize state class
{
	if ( m_currentState == nullptr )
	{
		SetCurrentState( AT_ROPE );
	}
	m_currentState->InitState();
}
void ClimbHandler::RunState()//run methods in current state class's "run state" method
{
	if ( m_currentState == nullptr )
	{
		SetCurrentState( AT_ROPE );
	}
	m_currentState->RunState();
}
void ClimbHandler::SetCurrentState(CLIMB_STATE_IDENTIFIER state)//change state classes
{
	switch (state)
	{
	case SPIN_WINCH:
		m_currentState=new SpinWinch();
		break;
	case CLIMB_ROPE:
		m_currentState=new ClimbRope();
		break;
	case STOP_WINCH:
		m_currentState=new StopWinch();
		break;
	default:
		m_currentState = new AtRope();
		break;
	}
	m_currentState->InitState();
}

ClimbHandler::ClimbHandler():
		m_currentState( nullptr )
{
//	SetCurrentState( AT_ROPE ); 
}
ClimbHandler::~ClimbHandler()
{

}
