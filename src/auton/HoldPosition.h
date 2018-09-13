/*
 * HoldPosition.h
 *
 *  Created on: Jan 25, 2017
 *      Author: Jonah Shader
 */

#ifndef SRC_AUTON_HOLDPOSITION_H_
#define SRC_AUTON_HOLDPOSITION_H_

#include <auton/IPrimitive.h>
#include <auton/PrimitiveParams.h>
#include <subsys/interfaces/IChassis.h>

namespace Team302
{

class HoldPosition : public IPrimitive
{
public:
	void Init(PrimitiveParams*	params) override;
	void Run() override;
	bool IsDone() override;
	HoldPosition();
	virtual ~HoldPosition() = default;

private:
	const float kP = 20; //50, /75
	const float kI = 0.0;
	const float kD = 0.0;
	const float kF = 0.0;
	//Objects
	IChassis* m_chassis;
	float m_timeRemaining; //In seconds

};

} /* namespace Team302 */

#endif /* SRC_AUTON_HOLDPOSITION_H_ */
