/*
 * Gear.h
 *
 *  Created on: Feb 11, 2017
 *      Author: Mike
 */

#ifndef SRC_AUTON_GEAR_H_
#define SRC_AUTON_GEAR_H_

#include <subsys/interfaces/IGearer.h>
#include <auton/IPrimitive.h>

namespace Team302
{

class Gear : public IPrimitive
{
public:
	void Init(PrimitiveParams*	Parms) override;
	void Run() override;
	bool IsDone() override;
	Gear();
	virtual ~Gear();

private:
	IGearer* m_gearer;
	bool m_deploy;
	float m_timeRemaining;
};

} /* namespace Team302 */

#endif /* SRC_AUTON_GEAR_H_ */
