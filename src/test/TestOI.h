/*
 * TestOI.h
 *
 *  Created on: Feb 3, 2017
 *      Author: witcpale
 */

#ifndef SRC_TEST_TESTOI_H_
#define SRC_TEST_TESTOI_H_

#include <vector>
#include <driverInputs/OI.h>

namespace Team302
{
	enum OI_TEST_SCENARIO
	{
		TANK_DRIVE_LINEAR,
		TANK_DRIVE_CUBIC,
		SCALED_TANK_DRIVE_LINEAR,
		SCALED_TANK_DRIVE_CUBIC,
		ARCADE_DRIVE_LINEAR,
		ARCADE_DRIVE_CUBIC,
		SCALED_ARCADE_DRIVE_LINEAR,
		SCALED_ARCADE_DRIVE_CUBIC,
		NUM_OI_TEST_SCENARIOS
	};

	class TestOI
	{
		public:

			//----------------------------------------------------------------------------------
			// Method:      GetInstance
			// Description: If there isn't an instance of desired this class, create it.
			//              Otherwise, hand out the single instance.
			// Returns:     TestDragonXbox*    TestDragonStick singleton
			//----------------------------------------------------------------------------------
			static TestOI* GetInstance();

			//-----------------------------------------------------------------------
			// Method:		Init
			// Description:	Initializes the OI for the test.   This should
			//				be called from the appropriate Init method in Robot.cpp
			//
			//				Note: all tests are described with their enum and have a
			//				deadband eliminated.
			// Returns:		void
			//-----------------------------------------------------------------------
			void Init
			(
					OI_TEST_SCENARIO	type	// <I> - test to run
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
			TestOI();


			//-----------------------------------------------------------------------
			// Method:		<<destructor>>
			// Description:	cleans up other objects
			//-----------------------------------------------------------------------
			virtual ~TestOI();

			static TestOI* 							m_instance; //make a singleton
			OI*										m_oi;
			std::vector<OI::FUNCTION_IDENTIFIER> 	m_test;


	};

} /* namespace Team302 */

#endif /* SRC_TEST_TESTOI_H_ */
