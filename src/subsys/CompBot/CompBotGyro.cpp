/*
 * CompBotGyro.cpp
 *
 *  Created on: Mar 27, 2017
 *      Author: Tumtu
 */

#include <subsys/CompBot/CompBotGyro.h>
#include <subsys/CompBot/CompMap.h>
#include <AnalogGyro.h>
#include <WPILib.h>

namespace Team302 {

CompBotGyro::CompBotGyro() :
		m_gyro ( new AnalogGyro( GYRO_SENSOR ) ), //TODO Change the Channel for m_gyro
		resetAngle(0.0)
{
}

double CompBotGyro::GetRawAngle()
{
	// Will only work if Gyro is centered on robot, otherwise, have to do maths
	// or maybe calibrate/reset Gyro and then get the angle
	return (-m_gyro->GetAngle()) - resetAngle;
}

void CompBotGyro::ResetAngle()  // Used to reset the current angle
{
//	m_gyro->Reset();
	resetAngle = (-m_gyro->GetAngle());
}

void CompBotGyro::ResetGyro()
{

}

} /* namespace Team302 */
