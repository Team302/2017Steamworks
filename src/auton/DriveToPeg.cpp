/*
 * DriveToPeg.cpp
 *
 *  Created on: Feb 20, 2017
 *      Author: Tumtu
 */

#include <auton/DriveToPeg.h>

namespace Team302 {

DriveToPeg::DriveToPeg() : SuperDrive(),
				m_done(false),
				m_chassis(ChassisFactory::GetInstance()->GetIChassis()),
				m_gearer(GearFactory::GetInstance()->GetIGearer()),
				m_pegPresent(false),
				m_pegWasPresent( false ),
				m_targetSpeed(0.0),
				m_timeOut(0.0),
				m_finalTime(0.0)
{
}

void DriveToPeg::Init(PrimitiveParams* params)
{
		m_done = false;
		SuperDrive::Init(params);
		m_targetSpeed = 2.0;
		m_timeOut =	params->GetTime();
		m_finalTime = 1.0;
}

bool DriveToPeg::IsDone()
{
	frc::SmartDashboard::PutBoolean("Peg is there", m_pegPresent);

	m_pegPresent = m_gearer->IsPegPresent();
	if (m_pegPresent) m_pegWasPresent = true;
	if ( m_timeOut <= ( LOOP_LENGTH / 2.0 ) ) m_done = true;

	if ( m_pegWasPresent )
	{
		if (m_finalTime <= (LOOP_LENGTH / 2.0) )
			m_done = true;
		else
			m_chassis->SetVelocityParams(PROPORTIONAL_COEFF, INTREGRAL_COEFF, DERIVATIVE_COEFF, FEET_FORWARD_COEFF, m_targetSpeed, m_targetSpeed);

		m_finalTime -= LOOP_LENGTH;
	} else if ( m_timeOut <= ( LOOP_LENGTH / 2.0 ) ) m_done = true;

	m_timeOut -= LOOP_LENGTH;

	frc::SmartDashboard::PutBoolean("m_done", m_done);
	frc::SmartDashboard::PutNumber("Final time", m_finalTime);
	frc::SmartDashboard::PutNumber(" m_timeOut", m_timeOut);
	frc::SmartDashboard::PutBoolean("Peg Was Present DP", m_pegWasPresent);

	return (m_done || (!m_gearer->HasGear()));
}

} /* namespace Team302 */
