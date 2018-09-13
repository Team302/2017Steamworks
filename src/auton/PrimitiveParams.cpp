/*
 * PrimitiveParams.cpp
 *
 *  Created on: Jan 17, 2017
 *      Author: Jonah Shader
 */

#include <auton/PrimitiveParams.h>

namespace Team302
{

PrimitiveParams::PrimitiveParams(
		int id,
		float time,
		float distance,
		float angle,
		float driveSpeed,
		bool deployGear,
		float shooterSpeed,
		bool shoot,
		bool intakeFuel
		):
		m_id(id),
		m_time(time),
		m_distance(distance),
		m_angle(angle),
		m_driveSpeed(driveSpeed),
		m_deployGear(deployGear),
		m_shooterSpeed(shooterSpeed),
		m_shoot(shoot),
		m_intakeFuel(intakeFuel)
{
}

PrimitiveParams::~PrimitiveParams()
{

}

float PrimitiveParams::GetTime() const
{
	return m_time;
}

float PrimitiveParams::GetAngle() const
{
	return m_angle;
}

float PrimitiveParams::GetDistance() const
{
	return m_distance;
}

float PrimitiveParams::GetDriveSpeed() const
{
	return m_driveSpeed;
}

int PrimitiveParams::GetID() const
{
	return m_id;
}
bool PrimitiveParams::GetDeployGear() const
{
	return m_deployGear;
}
float PrimitiveParams::GetShooterSpeed() const
{
	return m_shooterSpeed;
}
bool PrimitiveParams::GetIntakeFuel() const
{
	return m_intakeFuel;
}
bool PrimitiveParams::GetShoot() const
{
	return m_shoot;
}
} /* namespace Team302 */
