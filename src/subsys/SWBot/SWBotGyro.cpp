/*
 * SWBotGyro.cpp
 *
 *  Created on: Mar 27, 2017
 *      Author: Tumtu
 */

#include <subsys/SWBot/SWBotGyro.h>
#include <subsys/SWBot/SWMap.h>
#include <AnalogGyro.h>
#include <WPILib.h>

namespace Team302 {

SWBotGyro::SWBotGyro() :
		m_gyro ( new AnalogGyro ( GYRO_SENSOR ) )
{
}

double SWBotGyro::GetRawAngle()
{
	return m_gyro->GetAngle();
}

void SWBotGyro::ResetAngle()
{
	m_gyro->Reset();
}

void SWBotGyro::ResetGyro()
{

}

} /* namespace Team302 */
