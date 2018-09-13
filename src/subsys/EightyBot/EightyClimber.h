/*
 * EightyClimber.h
 *
 *  Created on: Feb 13, 2017
 *      Author: 0wen
 */

#include <subsys/interfaces/IClimber.h>
#include <utils/DragonTalon.h>

#ifndef SRC_EightyCLIMBER_H_
#define SRC_EightyCLIMBER_H_

namespace Team302 {

class EightyClimber : public IClimber{
public:

	bool IsRobotLifting();
	float GetRPM();
	float GetRotations();
	void SetPower(float power);
	void ResetDistance();

	EightyClimber();
	virtual ~EightyClimber() = default;

private:
	DragonTalon* m_climbMotor;

	const double MIN_CLIMB_CURRENT = 0.5; //min current needed to trigger climb start
	const double MIN_CLIMB_START_TIME = 1.0; //min time in seconds before triggering climb start
};

} /* namespace Team302 */

#endif /* SRC_EightyCLIMBER_H_ */
