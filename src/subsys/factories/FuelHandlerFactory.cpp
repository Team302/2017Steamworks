/*
 * FuelHandlerFactory.cpp
 *
 *  Created on: Jan 12, 2017
 *      Author: Tumtu
 */

#include <subsys/factories/FuelHandlerFactory.h>
#include <RobotDefn.h>
#include <subsys/CompBot/CompBotFuelHandler.h>
#include <subsys/interfaces/IFuelHandler.h>
#include <subsys/SWBot/SWBotFuelHandler.h>
#include <subsys/EightyBot/EightyFuelHandler.h>

#include <SmartDashboard/SmartDashboard.h>


namespace Team302 {

FuelHandlerFactory* FuelHandlerFactory::m_instance = nullptr; // initialize the instance variable to nullptr

//----------------------------------------------------------------------------------
// Method:      GetInstance
// Description: If there isn't an instance of desired IShooterFactory class, create it.
//              Otherwise, hand out the single instance.
// Returns:     FuelHandlerFactory*    FuelHandler factory
//----------------------------------------------------------------------------------
FuelHandlerFactory*    FuelHandlerFactory::GetInstance()
{
    if ( FuelHandlerFactory::m_instance == nullptr )
    {
        FuelHandlerFactory::m_instance = new FuelHandlerFactory();
    }
    return FuelHandlerFactory::m_instance;
}

//--------------------------------------------------------------------
// Method:      FuelHandlerFactory <<constructor>>
// Description: This method creates and initializes the objects
//--------------------------------------------------------------------
FuelHandlerFactory::FuelHandlerFactory() : m_FuelHandler(nullptr) //sets to null because we don't have FuelHandlerer yet
{
}

//--------------------------------------------------------------------
// Method:      ~FuelHandlerFactory <<destructor>>
// Description: This method cleans up when the object gets deleted
//--------------------------------------------------------------------
FuelHandlerFactory::~FuelHandlerFactory() //destructs many things
{
	FuelHandlerFactory::m_instance = nullptr;
}

//----------------------------------------------------------------------------------
// Method:      GetIFuelHandlerer
// Description: If there isn't an instance of desired IFuelHandlerer class, create it.
//              Otherwise, hand out the single instance.
// Returns:     IFuelHandlerer*   Chassis class
//----------------------------------------------------------------------------------
IFuelHandler*   FuelHandlerFactory::GetIFuelHandler()
{
    if ( m_FuelHandler == nullptr )
    {
        switch ( ROBOT_CONFIGURATION )
        {
            case SOFTWARE_BOT:
                m_FuelHandler = new SWBotFuelHandler();
                break;

            case COMP_BOT:
                m_FuelHandler = new CompBotFuelHandler();
                break;

            case EIGHTY_BOT:
            	m_FuelHandler = new EightyFuelHandler();
            	break;

            default:
    			SmartDashboard::PutString( "FuelHandler Factory ", "Failed " );
                break;
        }
    }
    return m_FuelHandler;
}
} /* namespace Team302 */
