/*
 * DriveToPeg.h
 *
 *  Created on: Feb 20, 2017
 *      Author: Tumtu
 */

#ifndef SRC_AUTON_DRIVETOPEG_H_
#define SRC_AUTON_DRIVETOPEG_H_

#include <auton/IPrimitive.h>
#include <auton/PrimitiveParams.h>
#include <subsys/interfaces/IChassis.h>
#include <subsys/interfaces/IGearer.h>

#include <subsys/factories/GearFactory.h>
#include <subsys/factories/ChassisFactory.h>
#include <auton/SuperDrive.h>

namespace Team302
{

class DriveToPeg : public SuperDrive
{
public:
	DriveToPeg();
	virtual ~DriveToPeg() = default;

	void Init(PrimitiveParams*	Parms) override;
	bool IsDone() override;

private:
    const float PROPORTIONAL_COEFF  = 0.5;
    const float INTREGRAL_COEFF     = 0.0;
    const float DERIVATIVE_COEFF    = 0.0;
    const float FEET_FORWARD_COEFF  = 0.0;
    const float COMPENSATE_SCALE    = 3.0; //Multiplier for the IsDone compensation. 1.0 means it ends 1 loop early

    float m_done;

	IChassis* m_chassis;
	IGearer* m_gearer;

	bool m_pegPresent;
	bool m_pegWasPresent;

	float m_targetSpeed;
	float m_timeOut;
    float m_finalTime;
};

} /* namespace Team302 */

#endif /* SRC_AUTON_DRIVETOPEG_H_ */
