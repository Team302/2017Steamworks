/*
 * TestFuel.h
 *
 *  Created on: Feb 15, 2017
 *      Author: witcpale
 */

#ifndef SRC_TEST_TESTFUEL_H_
#define SRC_TEST_TESTFUEL_H_

#include <subsys/interfaces/IFuelHandler.h>
namespace Team302
{

	enum IFUELHANDLER_TEST_SCENARIO
	{
		IFUEL_INTAKE_TEST,
		IFUEL_SHOOTER_POWER_TEST,
		IFUEL_SHOOTER_VELOCITY_TEST,
		IFUEL_CONVEYOR_TEST,
		IFUEL_LIFT_TEST,
		IFUEL_SHOOT_CYCLE_TEST,
		NUM_IFUEL_TEST_SCENARIOS
	};

	class TestFuel
	{

		public:
			//----------------------------------------------------------------------------------
			// Method:      GetInstance
			// Description: If there isn't an instance of desired this class, create it.
			//              Otherwise, hand out the single instance.
			// Returns:     TestFuel*    this class
			//----------------------------------------------------------------------------------
			static TestFuel* GetInstance();

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
					IFUELHANDLER_TEST_SCENARIO	type	// <I> - test to run
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
			TestFuel();

			//-----------------------------------------------------------------------
			// Method:		<<destructor>>
			// Description:	cleans up other objects
			//-----------------------------------------------------------------------
			virtual ~TestFuel();

			static TestFuel* 								m_instance; //make a singleton
			IFuelHandler*									m_fuel;

	};

} /* namespace Team302 */

#endif /* SRC_TEST_TESTFUEL_H_ */

