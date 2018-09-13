/*
 * TestPrims.h
 *
 *  Created on: Feb 3, 2017
 *      Author: witcpale
 */

#ifndef SRC_TEST_TESTPRIM_H_
#define SRC_TEST_TESTPRIM_H_

#include <vector>
#include <auton/IPrimitive.h>
#include <auton/PrimitiveParams.h>

namespace Team302
{
    enum PRIM_TEST_SCENARIO
    {
        TEST_DO_NOTHING,
        TEST_DRIVE_TIME,
        TEST_DRIVE_DISTANCE,
        TEST_HOLD_POSITION,
        TEST_TURN_ANGLE,
		TEST_DRIVE_PEG,
        TEST_DRIVE_DISTANCE_HOLD_POSITION,
        TEST_DRIVE_DISTANCE_HOLD_POSITION_TURN_ANGLE,
        NUM_PRIM_TEST_SCENARIOS
    };

    class TestPrims
    {
        public:

            //----------------------------------------------------------------------------------
            // Method:      GetInstance
            // Description: If there isn't an instance of desired this class, create it.
            //              Otherwise, hand out the single instance.
            // Returns:     TestPrims*    TestPrims singleton
            //----------------------------------------------------------------------------------
            static TestPrims* GetInstance();

            //-----------------------------------------------------------------------
            // Method:      Init
            // Description: Initializes the OI for the test.   This should
            //              be called from the appropriate Init method in Robot.cpp
            //
            //              Note: all tests are described with their enum and have a
            //              deadband eliminated.
            // Returns:     void
            //-----------------------------------------------------------------------
            void Init
            (
                    PRIM_TEST_SCENARIO    type    // <I> - test to run
            );

            //-----------------------------------------------------------------------
            // Method:      Run
            // Description: This displays the joystick axis values and button states
            //              to the dashboard
            // Returns:     void
            //-----------------------------------------------------------------------
            void Run();

        private:
            //-----------------------------------------------------------------------
            // Method:      <<constructor>>
            // Description: creates the test environment attributes
            //-----------------------------------------------------------------------
            TestPrims();


            //-----------------------------------------------------------------------
            // Method:      <<destructor>>
            // Description: cleans up other objects
            //-----------------------------------------------------------------------
            virtual ~TestPrims();

            static TestPrims*                       m_instance; //make a singleton
            std::vector<PrimitiveParams*>           m_primParam;
            int                                     m_currPrimSlot;
            IPrimitive*                             m_currPrim;


    };

} /* namespace Team302 */

#endif /* SRC_TEST_TESTPRIM_H_ */
