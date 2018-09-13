/*
 * EightyChassisTest.h
 *
 *  Created on: Feb 13, 2017
 *      Author: Tumtu
 */

#ifndef SRC_TEST_EIGHTYCHASSISTEST_H_
#define SRC_TEST_EIGHTYCHASSISTEST_H_

#include <subsys/EightyBot/EightyChassis.h>

namespace Team302
{

class EightyChassisTest
{
public:
	void ChassisPeriodic();
	void ChassisInit();

	EightyChassisTest();
	virtual ~EightyChassisTest() = default;

private:
	EightyChassis* m_chassis;
	float m_time; //in seconds
	bool m_brakeModeOn;

	//Default sequence duration is 4 seconds (8 including brake mode switch). if you want to make it longer, turn up the TIME_MULTIPLIER
	const float TIME_MULTIPLIER = 1.0;

};

} /* namespace Team302 */
#endif /* SRC_TEST_EIGHTYCHASSISTEST_H_ */
