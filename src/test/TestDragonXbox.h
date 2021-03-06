/*
 * TestDragonXbox.h
 *
 *  Created on: Feb 3, 2017
 *      Author: witcpale
 */

#ifndef SRC_TEST_TESTDRAGONXBOX_H_
#define SRC_TEST_TESTDRAGONXBOX_H_

#include <driverInputs/DragonXbox.h>

namespace Team302
{
	enum DRAGONXBOX_TEST_SCENARIO
	{
		LINEAR_FULL_SCALE, 		// Both Joysticks have a range of -1.0 to 1.0 and a linear scale
		LINEAR_HALF_SCALE, 		// Both Joysticks have a range of -0.5 to 0.5 and a linear scale
		CUBIC_FULL_SCALE,		// Both Joysticks have a range of -1.0 to 1.0 and a cubic scale
		CUBIC_HALF_SCALE,		// Both Joysticks have a range of -0.5 to 0.5 and a cubic scale
		NUM_DRAGONXBOX_TEST_SCENARIOS
	};

	class TestDragonXbox
	{
		public:


			//----------------------------------------------------------------------------------
			// Method:      GetInstance
			// Description: If there isn't an instance of desired this class, create it.
			//              Otherwise, hand out the single instance.
			// Returns:     TestDragonXbox*    TestDragonStick singleton
			//----------------------------------------------------------------------------------
			static TestDragonXbox* GetInstance();


			//-----------------------------------------------------------------------
			// Method:		Init
			// Description:	Initializes the DragonXbox for the test.   This should
			//				be called from the appropriate Init method in Robot.cpp
			//
			//				Note: all tests are described with their enum and have a
			//				deadband eliminated.
			// Returns:		void
			//-----------------------------------------------------------------------
			void Init
			(
					DRAGONXBOX_TEST_SCENARIO	type	// <I> - test to run
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
			TestDragonXbox();

			//-----------------------------------------------------------------------
			// Method:		<<destructor>>
			// Description:	cleans up other objects
			//-----------------------------------------------------------------------
			virtual ~TestDragonXbox();


			static TestDragonXbox* m_instance; //make a singleton

			DragonXbox*		m_xboxController;
	};

} /* namespace Team302 */

#endif /* SRC_TEST_TESTDRAGONXBOX_H_ */
