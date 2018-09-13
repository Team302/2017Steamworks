/*
 * EightyGearer.cpp
 *
 *  Created on: Feb 5, 2017
 *      Author: Tumtu
 */

#include <WPILib.h>
#include <subsys/EightyBot/EightyGearer.h>
#include <subsys/EightyBot/EightyMap.h>

using namespace frc;

namespace Team302 {

EightyGearer::EightyGearer()
{
	m_upperFlapSolenoid = new Solenoid(13, RAMP_MOVEMENT_SOL);
	m_lowerFlapSolenoid = new Solenoid(13, GEAR_DEPLOYMENT_SOL);
	m_pressureGauge = new AnalogInput( 0 );
	m_upperFlapSensor = new DigitalInput(UPPER_FLAP_SENSOR);
	m_lowerFlapSensor = new DigitalInput(LOWER_FLAP_SENSOR);
	m_gearSensor = new DigitalInput(GEAR_PRESENT_SENSOR);
	m_pegSensor = new DigitalInput(GEAR_POST_PRESENT_SENSOR);
	m_pressure = 0.0;
	vOut = 0.0;
}

bool EightyGearer::HasGear()
{
	return m_gearSensor->Get();
}
;
bool EightyGearer::IsPegPresent()
{
	return m_pegSensor->Get();
}

bool EightyGearer::IsUpperFlapOpen()
{
	return m_upperFlapSensor->Get();
}

bool EightyGearer::IsLowerFlapOpen()
{

	bool flapOutput = false;

	if(m_lowerFlapSensor->Get() == false)
	{
		flapOutput = true;
	} else if (m_lowerFlapSensor->Get() == true)
	{
		flapOutput = false;
	}

	return flapOutput;
}

void EightyGearer::OpenUpperFlaps(bool OpenFlaps)
{
	m_upperFlapSolenoid->Set(OpenFlaps);

}

void EightyGearer::OpenLowerFlaps(bool OpenFlaps)
{
	m_lowerFlapSolenoid->Set(OpenFlaps);
}

void EightyGearer::ResetFlaps()
{
	m_lowerFlapSolenoid->Set(m_reset);
	m_upperFlapSolenoid->Set(m_reset);
}

float EightyGearer::GetPressure()
{
	vOut = m_pressureGauge->GetVoltage();
	m_pressure = ( vOut * 41.98 );

	return m_pressure;
}

EightyGearer::~EightyGearer()
{

}

} /* namespace Team302 */
