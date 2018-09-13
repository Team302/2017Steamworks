/*
 * EightyGyro.cpp
 *
 *  Created on: Mar 27, 2017
 *      Author: Tumtu
 */

#include <subsys/EightyBot/EightyGyro.h>
#include <subsys/EightyBot/EightyMap.h>
#include <AnalogGyro.h>
#include <WPILib.h>

namespace Team302 {

EightyGyro::EightyGyro() :
	m_gyro ( new AnalogGyro( GYRO_SENSOR ) )
{
}

double EightyGyro::GetRawAngle()
{
	return m_gyro->GetAngle();
}

void EightyGyro::ResetAngle()
{
	m_gyro->Reset();
}

void EightyGyro::ResetGyro()
{

}

} /* namespace Team302 */
