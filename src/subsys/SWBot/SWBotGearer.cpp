/*
 * SWBotGearer.cpp
 *
 *  Created on: Jan 12, 2017
 *      Author: Tumtu
 */
#include <WPILib.h>
#include <subsys/SWBot/SWBotGearer.h>
#include <subsys/SWBot/SWMap.h>

namespace Team302 {

SWBotGearer::SWBotGearer()
{
	m_upperFlapSolenoid = new Solenoid(UPPER_FLAP_SOLENOID);
	m_lowerFlapSolenoid = new Solenoid(LOWER_FLAP_SOLENOID);
	m_pressureGauge = new AnalogInput( 0 );
	m_upperFlapSensor = new DigitalInput(UPPER_FLAP_SENSOR);
	m_lowerFlapSensor = new DigitalInput(LOWER_FLAP_SENSOR);
	m_gearSensor = new DigitalInput(GEAR_SENSOR);
	m_pegSensor = new DigitalInput(PEG_SENSOR);
	m_pressure = 0.0;
	vOut = 0.0;
}

bool SWBotGearer::HasGear()
{
	return m_gearSensor->Get();
}
;
bool SWBotGearer::IsPegPresent()
{
	return m_pegSensor->Get();
}

bool SWBotGearer::IsUpperFlapOpen()
{
	return m_upperFlapSensor->Get();
}

bool SWBotGearer::IsLowerFlapOpen()
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

void SWBotGearer::OpenUpperFlaps(bool OpenFlaps)
{
	m_upperFlapSolenoid->Set(OpenFlaps);

}

void SWBotGearer::OpenLowerFlaps(bool OpenFlaps)
{
	m_lowerFlapSolenoid->Set(OpenFlaps);
}

void SWBotGearer::ResetFlaps()
{
	m_lowerFlapSolenoid->Set( false );
	m_upperFlapSolenoid->Set( false );
}

float SWBotGearer::GetPressure()
{
	vOut = m_pressureGauge->GetVoltage();
	m_pressure = ( vOut * 41.98 );

	return m_pressure;
}

SWBotGearer::~SWBotGearer()
{

}

} /* namespace Team302 */
