/*
 * GearFactory.cpp
 *
 *  Created on: Jan 16, 2017
 *      Author: Tumtu
 */

#include <subsys/factories/Gearfactory.h>
#include <RobotDefn.h>
#include <subsys/CompBot/CompBotGearer.h>
#include <subsys/interfaces/IGearer.h>
#include <subsys/SWBot/SWBotGearer.h>
#include <subsys/EightyBot/EightyGearer.h>

#include <SmartDashboard/SmartDashboard.h>


namespace Team302 {

GearFactory* GearFactory::m_instance = nullptr;

GearFactory*    GearFactory::GetInstance()
{
    if ( GearFactory::m_instance == nullptr )
    {
        GearFactory::m_instance = new GearFactory();
    }
    return GearFactory::m_instance;
}

GearFactory::GearFactory() : m_gearer(nullptr)
{
}

GearFactory::~GearFactory() //destructs many things
{
	GearFactory::m_instance = nullptr;
}

IGearer*   GearFactory::GetIGearer()
{
    if ( m_gearer == nullptr )
    {
        switch ( ROBOT_CONFIGURATION )
        {
            case SOFTWARE_BOT:
                m_gearer = new SWBotGearer();
                break;

            case COMP_BOT:
            	m_gearer = new CompBotGearer();
                break;

            case EIGHTY_BOT:
            	m_gearer = new EightyGearer();
            	break;
            default:
    			frc::SmartDashboard::PutString( "Gear Factory ", "Failed " );
                break;
        }
    }
    return m_gearer;
}

} /* namespace Team302 */
