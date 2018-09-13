/*
 * ClimbHandler.h
 *
 *  Created on: Jan 28, 2017
 *      Author: Mike
 */
#ifndef TELEOPCLIMB_CLIMBHANDLER_H_
#define TELEOPCLIMB_CLIMBHANDLER_H_

#include <subsys/interfaces/IClimber.h>
#include <teleopClimb/IClimbState.h>


namespace Team302
{
	class ClimbHandler
	{
		public:
			static ClimbHandler* GetInstance();
			void  SetCurrentState( CLIMB_STATE_IDENTIFIER state );//changes state class
			void InitState();//initialize state class
			void RunState();//run state class
		
			
		protected:

		private:
			ClimbHandler();//constructor
			virtual ~ClimbHandler();//destructor

			static ClimbHandler* m_instance;
			IClimbState* m_currentState;
	
	};
}
#endif /* TELEOPCLIMB_CLIMBHANDLER_H_ */
