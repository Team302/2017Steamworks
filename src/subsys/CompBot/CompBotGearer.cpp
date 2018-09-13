/*
 * CompBotGearer.cpp
 *
 *  Created on: Jan 12, 2017
 *      Author: Tumtu
 */

#include <WPILib.h>
#include <subsys/CompBot/CompBotGearer.h>
#include <subsys/CompBot/CompMap.h>
#include <SmartDashboard/SmartDashboard.h>
#include <AnalogInput.h>

using namespace frc;

namespace Team302 {

CompBotGearer::CompBotGearer() :
			m_upperFlapSolenoid( new Solenoid( PCM_MODULE, RAMP_MOVEMENT_SOL ) ),
			m_lowerFlapSolenoid( new Solenoid(PCM_MODULE, GEAR_DEPLOYMENT_SOL ) ),
			m_pressureGauge ( new AnalogInput( 0 ) ),
			m_upperFlapSensor ( new DigitalInput( UPPER_FLAP_SENSOR ) ),
			m_lowerFlapSensor( new DigitalInput( LOWER_FLAP_SENSOR ) ),
			m_gearSensor( new DigitalInput( GEAR_PRESENT_SENSOR ) ),
			m_pegSensor( new DigitalInput( GEAR_POST_PRESENT_SENSOR ) ),
			m_upperSensed ( false ),
			m_lowerSensed ( false ),
			m_pressure( 0.0 ),
			vOut ( 0.0 )
{
}

bool CompBotGearer::HasGear()
{
	return !m_gearSensor->Get();
}

bool CompBotGearer::IsPegPresent() //Inverted
{
	return !m_pegSensor->Get();
}

bool CompBotGearer::IsUpperFlapOpen()	// Not Inverted
{
	if ( m_upperFlapSensor->Get() == true )
	{
		m_upperSensed = true;
	} else
	{
		m_upperSensed = false;
	}

//	SmartDashboard::PutBoolean("Upper Sensor REAL", m_upperSensed);

	return m_upperSensed;
}

bool CompBotGearer::IsLowerFlapOpen()	// Inverted
{

if( m_lowerFlapSensor->Get() == true )
	{
		m_lowerSensed = false;
	} else if ( m_lowerFlapSensor->Get() == false )
	{
		m_lowerSensed = true;
	}

//	SmartDashboard::PutBoolean("Lower Sensor REAL", m_lowerSensed);

	return m_lowerSensed;
}

void CompBotGearer::OpenUpperFlaps(bool OpenFlaps)
{
	m_upperFlapSolenoid->Set(OpenFlaps);
}

void CompBotGearer::OpenLowerFlaps(bool OpenFlaps)
{
	m_lowerFlapSolenoid->Set(OpenFlaps);
}

void CompBotGearer::ResetFlaps()
{
	m_lowerFlapSolenoid->Set(m_reset);
	m_upperFlapSolenoid->Set(m_reset);
}

float CompBotGearer::GetPressure()
{
vOut = m_pressureGauge->GetVoltage();
m_pressure = ( vOut * 41.98 );

return m_pressure;
}

CompBotGearer::~CompBotGearer()
{

}

} /* namespace Team302 */
