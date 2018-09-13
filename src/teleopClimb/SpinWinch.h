/*
 * SpinWinch.h
 *
 *  Created on: Feb 2, 2017
 *      Author: neeth
 */

#ifndef SRC_TELEOPCLIMB_SPINWINCH_H_
#define SRC_TELEOPCLIMB_SPINWINCH_H_

#include <teleopClimb/ClimbHandler.h>
#include <subsys/interfaces/IClimber.h>
#include <driverInputs/OI.h>
#include <teleopClimb/IClimbState.h>

using namespace Team302;
class SpinWinch:public IClimbState
{
public:
	void InitState() override;//initialize state class
	void RunState() override;//run state class
	std::string GetName() const override;

	SpinWinch();
	virtual ~SpinWinch() = default;
private:
	IClimber* m_climber;
};

#endif /* SRC_TELEOPCLIMB_SPINWINCH_H_ */
