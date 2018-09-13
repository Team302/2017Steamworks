/*
 * LEDFactory.h
 *
 *  Created on: Feb 19, 2017
 *      Author: Elite
 */

#ifndef SRC_SUBSYS_FACTORIES_LEDFACTORY_H_
#define SRC_SUBSYS_FACTORIES_LEDFACTORY_H_

#include <subsys/interfaces/ILED.h>
#include "RobotDefn.h"

namespace Team302 {

class LEDFactory {
public:

	static LEDFactory* GetInstance();

	ILED* GetILED();

	LEDFactory();
	virtual ~LEDFactory();

private:

	static LEDFactory* m_instance; //The factory
	ILED*               m_LED;

	LEDFactory(const LEDFactory&) = delete;
	LEDFactory& operator = (const LEDFactory* other) = delete;
	explicit LEDFactory(LEDFactory* other) = delete;

};

} /* namespace Team302 */

#endif /* SRC_SUBSYS_FACTORIES_LEDFACTORY_H_ */
