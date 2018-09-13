/*
 * PrimitiveParams.h
 *
 *  Created on: Jan 17, 2017
 *      Author: Jonah Shader
 */

#ifndef SRC_PRIMITIVEPARAMS_H_
#define SRC_PRIMITIVEPARAMS_H_

namespace Team302
{

class PrimitiveParams
{
public:
	//Some getters
	int GetID() const;
	float GetTime() const;
	float GetDistance() const;
	float GetAngle() const;
	float GetDriveSpeed() const;
	bool GetDeployGear() const;
	bool GetShoot() const;
	bool GetIntakeFuel() const;
	float GetShooterSpeed() const;
	PrimitiveParams(
			int id,
			float time,
			float distance,
			float angle,
			float driveSpeed,
			bool deployGear,
			float shooterSpeed,
			bool shoot,
			bool intakeFuel
			);//Constructor. Takes in all parameters
	virtual ~PrimitiveParams();//Destructor

private:
	int m_id; //Primitive ID
	//Primitive Parameters
	float m_time;
	float m_distance;
	float m_angle;
	float m_driveSpeed;
	bool m_deployGear;
	float m_shooterSpeed;
	bool m_shoot;
	bool m_intakeFuel;
};

} /* namespace Team302 */

#endif /* SRC_PRIMITIVEPARAMS_H_ */
