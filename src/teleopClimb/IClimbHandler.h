/*
 * IClimbHandler.h
 *
 *  Created on: Feb 2, 2017
 *      Author: neeth
 */

#ifndef SRC_TELEOPCLIMB_ICLIMBHANDLER_H_
#define SRC_TELEOPCLIMB_ICLIMBHANDLER_H_
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
	const float SPIN__WINCH_POWER = 1.0;
	const float CLIMB_WINCH_POWER = 1.0;
	const float STOP_WINCH_POWER = 0.0;

	class IClimbHandler
	{

		public:
			virtual void  SetCurrentStates( CLIMB_STATE_IDENTIFIER state ) = 0;//changes state class
			virtual void  InitState() = 0;//initialize state class
			virtual void  RunState() = 0;//run state class

			IClimbHandler() = default;
			virtual ~IClimbHandler() = default;

	};

}

#endif /* SRC_TELEOPCLIMB_ICLIMBHANDLER_H_ */
