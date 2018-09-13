/*
 * TestIChassis.h
 *
 *  Created on: Feb 15, 2017
 *      Author: witcpale
 */

#ifndef SRC_TEST_TESTICHASSIS_H_
#define SRC_TEST_TESTICHASSIS_H_

#include <subsys/interfaces/IChassis.h>

namespace Team302
{
	enum ICHASSIS_TEST_SCENARIO
	{
		CHASSIS_FORWARD,
		CHASSIS_BACKWARD,
		CHASSIS_SPIN_CW,
		CHASSIS_SPIN_CCW,
		CHASSIS_RIGHT_ONLY,
		CHASSIS_LEFT_ONLY,
		NUM_ICHASSIS_TEST_SCENARIOS
	};

	class TestIChassis
	{
		public:

			//----------------------------------------------------------------------------------
			// Method:      GetInstance
			// Description: If there isn't an instance of desired this class, create it.
			//              Otherwise, hand out the single instance.
			// Returns:     TestDragonXbox*    TestDragonStick singleton
			//----------------------------------------------------------------------------------
			static TestIChassis* GetInstance();

			//-----------------------------------------------------------------------
			// Method:		Init
			// Description:	Initializes the test.   This should be called from the
			//				appropriate Init method in Robot.cpp
			//
			//				Note: all tests are described with their enum.
			// Returns:		void
			//-----------------------------------------------------------------------
			void Init
			(
					ICHASSIS_TEST_SCENARIO	type	// <I> - test to run
			);

			//-----------------------------------------------------------------------
			// Method:		Run
			// Description:	This displays the joystick axis values and button states
			//				to the dashboard
			// Returns:		void
			//-----------------------------------------------------------------------
			void Run();

		private:
			//-----------------------------------------------------------------------
			// Method:		<<constructor>>
			// Description:	creates the test environment attributes
			//-----------------------------------------------------------------------
			TestIChassis();

			//-----------------------------------------------------------------------
			// Method:		<<destructor>>
			// Description:	cleans up other objects
			//-----------------------------------------------------------------------
			virtual ~TestIChassis();

			static TestIChassis* 							m_instance; //make a singleton

			IChassis*										m_chassis;
			float 											m_leftPower;
			float											m_rightPower;

			const float COMPARE_TOLERANCE =	0.1;


	};

} /* namespace Team302 */

#endif /* SRC_TEST_TESTICHASSIS_H_ */
