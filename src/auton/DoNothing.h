/*
 * DoNothing.h
 *
 *  Created on: Jan 18, 2017
 *      Author: The Realest of Authors
 *      Documentation: The Realest of Authors
 */

#ifndef DONOTHING_H_
#define DONOTHING_H_

#include <auton/IPrimitive.h>
#include <auton/PrimitiveParams.h>
#include <subsys/interfaces/IChassis.h>

namespace Team302 {
class DoNothing : public IPrimitive
{
public:
	DoNothing();
	virtual ~DoNothing() = default;
	void Init(PrimitiveParams*	Parms) override;
	void Run() override;
	bool IsDone() override;

private:
	float m_maxTime;				// target time
	float m_currentTime;			// time since the target time was set
	IChassis* m_chassis;			// chassis
};
} /* namespace Team302 */


#endif /* DONOTHING_H_ */
