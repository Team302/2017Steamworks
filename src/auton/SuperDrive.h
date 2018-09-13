/*
 * SuperDrive.h
 *
 *  Created on: Mar 6, 2017
 *      Author: Jonah S.
 */

#ifndef SRC_AUTON_SUPERDRIVE_H_
#define SRC_AUTON_SUPERDRIVE_H_

#include <auton/IPrimitive.h>
#include <subsys/interfaces/IChassis.h>
#include <subsys/interfaces/IGyro.h>

namespace Team302
{

class SuperDrive : public IPrimitive
{
public:
	void Init(PrimitiveParams* params) override;
	void Run() override;
	bool IsDone() override;

protected:
	SuperDrive();
	virtual ~SuperDrive() = default;

private:
	const float PROPORTIONAL_COEFF  = 0.5;
	const float INTREGRAL_COEFF     = 0.0;
	const float DERIVATIVE_COEFF    = 0.0;
	const float FEET_FORWARD_COEFF  = 0.0;

	const float GYRO_CORRECTION_CONSTANT = .1;
//	const float GYRO_CORRECTION_CONSTANT = .75; // eighty bot always comment out unless using said bot

	IChassis* m_chassis;					//Robot chassis
	IGyro*	m_gyro;

	float m_targetSpeed;
	float m_speedOffset;

	float m_leftSpeed;
	float m_rightSpeed;

	double m_currentAngle;
	double m_startAngle;
};

} /* namespace Team302 */

#endif /* SRC_AUTON_SUPERDRIVE_H_ */
