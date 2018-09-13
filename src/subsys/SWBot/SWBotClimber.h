/*
 * SWBotClimber.h
 *
 *  Created on: Jan 12, 2017
 *      Author: Tumtu
 */

#include <subsys/interfaces/IClimber.h>
#include <utils/DragonTalon.h>

namespace Team302 {

#ifndef SRC_SWBOTCLIMBER_H_
#define SRC_SWBOTCLIMBER_H_

class SWBotClimber : public IClimber{

	DragonTalon* m_climbMotor;
public:

	bool IsRobotLifting();
	float GetRPM();
	float GetRotations();
	void SetPower(float power);
	void ResetDistance();

	SWBotClimber();
	virtual ~SWBotClimber() = default;

private:
	const double MIN_CLIMB_CURRENT = 0.5; //min current needed to trigger climb start
	const double MIN_CLIMB_START_TIME = 1.0; //min time in seconds before triggering climb start;
};

} /* namespace Team302 */

#endif /* SRC_SWBOTCLIMBER_H_ */
