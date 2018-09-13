/*
 * TestGearer.h
 *
 *  Created on: Feb 13, 2017
 *      Author: neeth
 */

#ifndef SRC_TEST_TESTGEARER_H_
#define SRC_TEST_TESTGEARER_H_

#include <subsys/EightyBot/EightyGearer.h>
namespace Team302 {

class TestGearer {
public:
	void GearerPeriodic();
	void GearerInit();

	TestGearer();
	virtual ~TestGearer() = default;

private:
	EightyGearer* m_gearer;
	bool m_upperflapopen;
	bool m_lowerflapopen;
};

} /* namespace Team302 */

#endif /* SRC_TEST_TESTGEARER_H_ */
