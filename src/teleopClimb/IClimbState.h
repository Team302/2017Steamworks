/*
 * IClimbHandler.h
 *
 *  Created on: Feb 2, 2017
 *      Author: neeth
 */

#ifndef SRC_TELEOPCLIMB_ICLIMBSTATE_H_
#define SRC_TELEOPCLIMB_ICLIMBSTATE_H_
#include <string>
namespace Team302
{


	enum CLIMB_STATE_IDENTIFIER
	{
		AT_ROPE, //At Rope class
		SPIN_WINCH, //Spin winch class
		CLIMB_ROPE, //climbrope class
		STOP_WINCH, //stopwinch class
		NUM_CLIMB_STATES
	};

	const float AT_ROPE_WINCH_POWER = 0.0;
	const float SPIN_WINCH_POWER = 1.0;
	const float CLIMB_WINCH_POWER = 1.0;
	const float STOP_WINCH_POWER = 0.0;

	class IClimbState
	{

		public:
			virtual void  InitState() = 0;//initialize state class
			virtual void  RunState() = 0;//run state class
			virtual std::string GetName() const = 0;

			IClimbState() = default;
			virtual ~IClimbState() = default;

	};

}

#endif /* SRC_TELEOPCLIMB_ICLIMBSTATE_H_ */
