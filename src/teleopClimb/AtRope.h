/*
 * AtRope.h
 *
 *  Created on: Feb 4, 2017
 *      Author: Mike
 */
#ifndef SRC_TELEOPCLIMB_ATROPE_H_
#define SRC_TELEOPCLIMB_ATROPE_H_
#include <driverInputs/OI.h>
#include <teleopClimb/ClimbHandler.h>
#include <subsys/interfaces/IClimber.h>
#include <teleopClimb/IClimbState.h>
namespace Team302
{

	class AtRope : public IClimbState
	{
		public:
			void InitState() override;//initialize state class
			void RunState() override;//run state class
			std::string GetName() const override;

			AtRope();
			~AtRope() override = default;

		private:
			IClimber* m_climber;


	};
}

#endif /* SRC_TELEOPCLIMB_ATROPE_H_ */
