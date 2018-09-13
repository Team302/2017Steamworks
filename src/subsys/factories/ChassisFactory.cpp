/*
 * ChassisFactory.cpp
 *
 *  Created on: Jan 16, 2017
 *      Author: Jonah Shader
 */

//Team 302 includes
#include <subsys/factories/ChassisFactory.h>			// This Class
#include <RobotDefn.h>
#include <subsys/CompBot/CompBotChassis.h>
#include <subsys/interfaces/IChassis.h>
#include <subsys/SWBot/SWBotChassis.h>
#include <subsys/EightyBot/EightyChassis.h>

#include <SmartDashboard/SmartDashboard.h>


namespace Team302
{
ChassisFactory* ChassisFactory::m_instance = nullptr;//Init the instance to nullptr

//----------------------------------------------------------------------------------
// Method:      GetInstance
// Description: If there isn't an instance of desired ChassisFactory class, create it.
//              Otherwise, hand out the single instance.
// Returns:     ChassisFactory*    Chassis factory
//----------------------------------------------------------------------------------
ChassisFactory* ChassisFactory::GetInstance()
{
	if (ChassisFactory::m_instance == nullptr)
	{
		ChassisFactory::m_instance = new ChassisFactory();
	}
	return ChassisFactory::m_instance;
}

//--------------------------------------------------------------------
// Method:      ChassisFactory <<constructor>>
// Description: This method creates and initializes the objects
//--------------------------------------------------------------------
ChassisFactory::ChassisFactory() : m_chassis(nullptr) //Constructor
{
}

//--------------------------------------------------------------------
// Method:      ~ChassisFactory <<destructor>>
// Description: This method cleans up when the object gets deleted
//--------------------------------------------------------------------
ChassisFactory::~ChassisFactory() //Destructor
{
	ChassisFactory::m_instance = nullptr;
}

//----------------------------------------------------------------------------------
// Method:      GetIChassis
// Description: If there isn't an instance of desired IChassis class, create it.
//              Otherwise, hand out the single instance.
// Returns:     IChassis*   Chassis class
//----------------------------------------------------------------------------------
IChassis* ChassisFactory::GetIChassis()
{
	if (m_chassis == nullptr)
	{
		switch (ROBOT_CONFIGURATION)
		{
		case SOFTWARE_BOT:
			m_chassis = new SWBotChassis();
			break;

		case COMP_BOT:
			m_chassis = new CompBotChassis();
			break;

        case EIGHTY_BOT:
        	m_chassis = new EightyChassis();
        	break;

		default:
			SmartDashboard::PutString( "Chassis Factory ", "Failed " );
			break;
		}
	}
	return m_chassis;
}

} /* namespace Team302 */
