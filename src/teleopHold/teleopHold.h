/*
 * teleopHold.h
 *
 *  Created on: Mar 11, 2017
 *      Author: Tumtu
 */

#ifndef SRC_TELEOPHOLD_TELEOPHOLD_H_
#define SRC_TELEOPHOLD_TELEOPHOLD_H_

#include <subsys/interfaces/IChassis.h>
#include <subsys/factories/ChassisFactory.h>
#include <cmath>
#include <utils/DragonPID.h>
#include <SmartDashboard/SmartDashboard.h>

namespace Team302 {

class teleopHold
{
public:
	teleopHold();
	virtual ~teleopHold() = default;
	void UseJoystickHoldFunction();
private:
	const float kP = 50;
	const float kI = 0.0;
	const float kD = 0.0;
	const float kF = 0.0;
	//Objects
	IChassis* m_chassis;

	bool m_reset;
};

} /* namespace Team302 */

#endif /* SRC_TELEOPHOLD_TELEOPHOLD_H_ */
