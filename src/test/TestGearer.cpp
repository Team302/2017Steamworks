/*
 * TestGearer.cpp
 *
 *  Created on: Feb 13, 2017
 *      Author: neeth
 */

#include <test/TestGearer.h>
#include <SmartDashboard/SmartDashboard.h>
namespace Team302
{

TestGearer::TestGearer() : m_gearer(new EightyGearer()),m_upperflapopen(true),m_lowerflapopen(false)
{

}

void TestGearer::GearerInit()
{
	m_gearer->ResetFlaps();
	m_upperflapopen = false;
	m_lowerflapopen = false;

}

void TestGearer::GearerPeriodic()
{
	if (m_upperflapopen &! m_lowerflapopen)
	{
	m_gearer->OpenUpperFlaps(true);
	m_gearer->OpenLowerFlaps(false);
	}
	else if (m_lowerflapopen &! m_upperflapopen )
	{
	m_gearer->OpenUpperFlaps(false);
	m_gearer->OpenLowerFlaps(true);
	}
	else if (m_upperflapopen &&  m_lowerflapopen)
	{
	m_gearer->OpenUpperFlaps(true);
	m_gearer->OpenLowerFlaps(true);
	}
	else
	{
	m_gearer->OpenUpperFlaps(false);
	m_gearer->OpenLowerFlaps(false);
	}

	frc::SmartDashboard::PutNumber("Is Gear Present", m_gearer->HasGear());
	frc::SmartDashboard::PutNumber("Is Peg Present", m_gearer->IsPegPresent());

}


} /* namespace Team302 */
