/*
 * StopWinch.h
 *
 *  Created on: Feb 4, 2017
 *      Author: Mike
 *
 */
#ifndef SRC_STOPWINCH_H_
#define SRC_STOPWINCH_H_
#include <driverInputs/OI.h>
#include <teleopClimb/ClimbHandler.h>
#include <subsys/interfaces/IClimber.h>
#include <teleopClimb/IClimbState.h>
using namespace Team302;
class StopWinch : public IClimbState 
{
public:
	void InitState() override;//initialize state class
	void RunState() override;//run state class
	std::string GetName() const override;

	StopWinch();
	virtual ~StopWinch() = default;
private:
	IClimber* m_climber;

};

#endif /* SRC_STOPWINCH_H_ */
