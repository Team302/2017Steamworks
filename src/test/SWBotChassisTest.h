/*
 * SWChassisTest.h
 *
 *  Created on: Feb 4, 2017
 *      Author: jonah shader
 */

#ifndef SRC_TEST_SWBOTCHASSISTEST_H_
#define SRC_TEST_SWBOTCHASSISTEST_H_

#include <subsys/SWBot/SWBotChassis.h>

namespace Team302
{

class SWBotChassisTest
{
public:
	void ChassisPeriodic();
	void ChassisInit();

	SWBotChassisTest();
	virtual ~SWBotChassisTest() = default;

private:
	SWBotChassis* m_chassis;
	float m_time; //in seconds
	bool m_brakeModeOn;

	//Default sequence duration is 4 seconds (8 including brake mode switch). if you want to make it longer, turn up the TIME_MULTIPLIER
	const float TIME_MULTIPLIER = 1.0;

};

} /* namespace Team302 */

#endif /* SRC_TEST_SWBOTCHASSISTEST_H_ */
