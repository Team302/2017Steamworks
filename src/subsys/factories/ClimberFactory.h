/*
 * ClimberFactory.h
 *
 *  Created on: Jan 12, 2017
 *      Author: Tumtu
 */

#ifndef SRC_CLIMBERFACTORY_H_
#define SRC_CLIMBERFACTORY_H_

#include <subsys/interfaces/IClimber.h>

namespace Team302 {

class ClimberFactory {
public:
	static ClimberFactory* GetInstance();
	IClimber* GetIClimber();

private:
	ClimberFactory();
	virtual ~ClimberFactory();

	static ClimberFactory* m_instance;//The factory
	IClimber*				m_climber;

	ClimberFactory(const ClimberFactory&) = delete;
	ClimberFactory& operator = (const ClimberFactory* other) = delete;
	explicit ClimberFactory(ClimberFactory* other) = delete;

};

} /* namespace Team302 */

#endif /* SRC_CLIMBERFACTORY_H_ */
