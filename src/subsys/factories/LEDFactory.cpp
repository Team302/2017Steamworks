/*
 * LEDFactory.cpp
 *
 *  Created on: Feb 19, 2017
 *      Author: Elite
 */

#include <subsys/factories/LEDFactory.h>
#include <subsys/CompBot/CompBotLED.h>
#include <SmartDashboard/SmartDashboard.h>

namespace Team302 {

LEDFactory* LEDFactory::m_instance = nullptr;//Init the instance to nullptr

//----------------------------------------------------------------------------------
// Method:      GetInstance
// Description: If there isn't an instance of desired LEDFactory class, create it.
//              Otherwise, hand out the single instance.
// Returns:     LEDFactory*    LED factory
//----------------------------------------------------------------------------------
LEDFactory* LEDFactory::GetInstance()
{
	if (LEDFactory::m_instance == nullptr)
	{
		LEDFactory::m_instance = new LEDFactory();
	}
	return LEDFactory::m_instance;
}

//--------------------------------------------------------------------
// Method:      LEDFactory <<constructor>>
// Description: This method creates and initializes the objects
//--------------------------------------------------------------------
LEDFactory::LEDFactory() : m_LED(nullptr) //Constructor
{
}

//--------------------------------------------------------------------
// Method:      ~LEDFactory <<destructor>>
// Description: This method cleans up when the object gets deleted
//--------------------------------------------------------------------
LEDFactory::~LEDFactory() //Destructor
{
	LEDFactory::m_instance = nullptr;
}

//----------------------------------------------------------------------------------
// Method:      GetILED
// Description: If there isn't an instance of desired ILED class, create it.
//              Otherwise, hand out the single instance.
// Returns:     ILED*   LED class
//----------------------------------------------------------------------------------
ILED* LEDFactory::GetILED()
{
	if (m_LED == nullptr)
	{
		switch (ROBOT_CONFIGURATION)
		{
		case SOFTWARE_BOT:
//			m_LED = new SWBotLED();
			break;

		case COMP_BOT:
			m_LED = new CompBotLED();
			break;

        case EIGHTY_BOT:
//        	m_LED = new EightyLED();
        	break;

		default:
			SmartDashboard::PutString( "LED Factory ", "Failed " );
			break;
		}
	}
	return m_LED;
}

} /* namespace Team302 */
