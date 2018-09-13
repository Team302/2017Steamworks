/*
 * Gear.cpp
 *
 *  Created on: Jan 18, 2017
 *      Author: Magic Mike Wazowski
 */
#include <auton/Gear.h>
#include <CANTalon.h>
#include <auton/PrimitiveParams.h>
#include <subsys/factories/GearFactory.h>
#include <subsys/interfaces/IGearer.h>

namespace Team302 {
Gear::Gear():
		m_gearer(GearFactory::GetInstance()->GetIGearer()),
		m_deploy(false),
		m_timeRemaining(0)
{
}

void Gear::Init(PrimitiveParams* parms)
{
	m_deploy=parms->GetDeployGear();
	m_timeRemaining = 2.0;
}

void Gear::Run()
{
	if(m_deploy && m_gearer->IsPegPresent() == true)
	{
		m_gearer->OpenLowerFlaps( true );
	} else
	{
		m_gearer->OpenLowerFlaps( false );
	}

	m_timeRemaining -= IPrimitive::LOOP_LENGTH;
}

bool Gear::IsDone()
{
	if (!m_deploy) {		//If deploy == false, return true because we don't need to do anything :D
//		m_gearer->OpenLowerFlaps( false );
		return true;
	}
	bool isFinished = ( !m_gearer->IsPegPresent() == false ) && (m_timeRemaining <= IPrimitive::LOOP_LENGTH / 2.0);

	if (isFinished)
	{
		m_gearer->OpenLowerFlaps( false );
	}

	return isFinished;
}
Gear::~Gear()
{
	
}
} /* namespace Team302 */


