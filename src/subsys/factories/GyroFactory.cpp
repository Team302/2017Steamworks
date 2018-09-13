/*
 * GyroFactory.cpp
 *
 *  Created on: Mar 27, 2017
 *      Author: Tumtu
 */

#include <subsys/factories/GyroFactory.h>
#include <subsys/CompBot/CompBotGyro.h>
#include <subsys/EightyBot/EightyGyro.h>
#include <subsys/SWBot/SWBotGyro.h>
#include <RobotDefn.h>

namespace Team302 {

GyroFactory* GyroFactory::m_instance = nullptr;

GyroFactory*	GyroFactory::GetInstance()
{
	if ( GyroFactory::m_instance == nullptr )
	{
		GyroFactory::m_instance = new GyroFactory();
	}

	return GyroFactory::m_instance;
}

GyroFactory::GyroFactory() : m_gyro(nullptr)
{
}

GyroFactory::~GyroFactory()
{
	GyroFactory::m_instance = nullptr;
}

IGyro*	GyroFactory::GetIGyro()
{
	if ( m_gyro == nullptr )
	{
		switch ( ROBOT_CONFIGURATION )
		{
		case SOFTWARE_BOT:
			m_gyro = new SWBotGyro();
			break;
		case COMP_BOT:
			m_gyro = new CompBotGyro();
			break;
		case EIGHTY_BOT:
			m_gyro = new EightyGyro();
			break;
		default:
			frc::SmartDashboard::PutString( "Gyro Factory ", "Failed" );
			break;
		}
	}

	return m_gyro;
}

} /* namespace Team302 */
