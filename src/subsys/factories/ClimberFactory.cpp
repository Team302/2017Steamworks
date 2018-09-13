/*
 * ClimberFactory.cpp
 *
 *  Created on: Jan 12, 2017
 *      Author: Tumtu
 */

//Team 302 includes
#include <subsys/factories/ClimberFactory.h>			// This Class
#include <RobotDefn.h>
#include <subsys/CompBot/CompBotClimber.h>
#include <subsys/interfaces/IClimber.h>
#include <subsys/SWBot/SWBotClimber.h>
#include <subsys/EightyBot/EightyClimber.h>

#include <SmartDashboard/SmartDashboard.h>


namespace Team302
{
ClimberFactory* ClimberFactory::m_instance = nullptr;//Init the instance to nullptr

//----------------------------------------------------------------------------------
// Method:      GetInstance
// Description: If there isn't an instance of desired ClimberFactory class, create it.
//              Otherwise, hand out the single instance.
// Returns:     ClimberFactory*    Climber factory
//----------------------------------------------------------------------------------
ClimberFactory* ClimberFactory::GetInstance()
{
	if (ClimberFactory::m_instance == nullptr)
	{
		ClimberFactory::m_instance = new ClimberFactory();
	}
	return ClimberFactory::m_instance;
}

//--------------------------------------------------------------------
// Method:      ClimberFactory <<constructor>>
// Description: This method creates and initializes the objects
//--------------------------------------------------------------------
ClimberFactory::ClimberFactory() : m_climber(nullptr) //Constructor
{
}

//--------------------------------------------------------------------
// Method:      ~ClimberFactory <<destructor>>
// Description: This method cleans up when the object gets deleted
//--------------------------------------------------------------------
ClimberFactory::~ClimberFactory() //Destructor
{
	ClimberFactory::m_instance = nullptr;
}

//----------------------------------------------------------------------------------
// Method:      GetIClimber
// Description: If there isn't an instance of desired IClimber class, create it.
//              Otherwise, hand out the single instance.
// Returns:     IClimber*   Climber class
//----------------------------------------------------------------------------------
IClimber* ClimberFactory::GetIClimber()
{
	if (m_climber == nullptr)
	{
		switch (ROBOT_CONFIGURATION)
		{
		case SOFTWARE_BOT:
			m_climber = new SWBotClimber();
			break;

		case COMP_BOT:
			m_climber = new CompBotClimber();
			break;
			
        case EIGHTY_BOT:
			m_climber = new EightyClimber();
			break;

		default:
			SmartDashboard::PutString( "Climber Factory ", "Failed " );
			break;
		}
	}
	return m_climber;
}

} /* namespace Team302 */
