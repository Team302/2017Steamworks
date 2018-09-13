/*
 * ClimbRope.h
 *
 *  Created on: Feb 4, 2017
 *      Author: Mike
 */
#ifndef SRC_CLIMBROPE_H_
#define SRC_CLIMBROPE_H_
#include <driverInputs/OI.h>
#include <teleopClimb/ClimbHandler.h>
#include <subsys/interfaces/IClimber.h>
#include <teleopClimb/IClimbState.h>
using namespace Team302;
class ClimbRope:public IClimbState
{
public:
	ClimbRope();//constructor
	virtual ~ClimbRope() = default;//destructor
	void  InitState() override;//initialize state class
	void  RunState() override;//run state class
	std::string GetName() const override;
private:
	IClimber* m_climber;

};
#endif /* SRC_CLIMBROPE_H_ */
