/*
 * TestPrims.cpp
 *
 *  Created on: Feb 3, 2017
 *      Author: witcpale
 */

#include <test/TestPrims.h>
#include <auton/PrimitiveFactory.h>
#include <auton/PrimitiveParams.h>
#include <auton/IPrimitive.h>
#include <subsys/factories/ChassisFactory.h>
#include <subsys/interfaces/IChassis.h>
#include <vector>
#include <string>

using namespace Team302;

TestPrims* TestPrims::m_instance = nullptr;//Init the instance to nullptr

//----------------------------------------------------------------------------------
// Method:      GetInstance
// Description: If there isn't an instance of desired this class, create it.
//              Otherwise, hand out the single instance.
// Returns:     TestDragonXbox*    TestDragonStick singleton
//----------------------------------------------------------------------------------
TestPrims* TestPrims::GetInstance()
{
    if (TestPrims::m_instance == nullptr)
    {
        TestPrims::m_instance = new TestPrims();
    }
    return TestPrims::m_instance;
}


//-----------------------------------------------------------------------
// Method:      Init
// Description: Initializes the OI for the test.   This should
//              be called from the appropriate Init method in Robot.cpp
//
//              Note: all tests are described with their enum and have a
//              deadband eliminated.
// Returns:     void
//-----------------------------------------------------------------------
void TestPrims::Init
(
        PRIM_TEST_SCENARIO    type    // <I> - test to run
)
{
    int     primID          = PrimitiveFactory::MAX_PRIMITIVES;
    float   time            = 0.0;
    float   distance        = 0.0;
    float   angle           = 0.0;
    float   driveSpeed      = 0.0;
//    bool    intakeOn        = false;
//    float   shooterSpeed    = 0.0;
//    bool    deployFuel      = false;

    switch ( type )
    {
        case TEST_DO_NOTHING:
            primID = PrimitiveFactory::DO_NOTHING;
            m_primParam.emplace_back( new PrimitiveParams( primID, time, distance, angle, driveSpeed, false, 0.0, false, false ) );
            break;

        case TEST_DRIVE_TIME:
            primID = PrimitiveFactory::DRIVE_TIME;
            time        = 2.0;      // half a second
            driveSpeed  = 3.0;      // 3 feet per second
            m_primParam.emplace_back( new PrimitiveParams( primID, time, distance, angle, driveSpeed, false, 0.0, false, false ) );
            break;

        case TEST_DRIVE_DISTANCE:
            primID      = PrimitiveFactory::DRIVE_DISTANCE;
            distance    = 6.5;      // 7 feet
            driveSpeed  = 3.0;      // 3 feet per second
            m_primParam.emplace_back( new PrimitiveParams( primID, time, distance, angle, driveSpeed, false, 0.0, false, false ) );
            break;

        case TEST_HOLD_POSITION:
            primID  = PrimitiveFactory::HOLD_POSITION;
            time    = 0.5;          // half a second
            m_primParam.emplace_back( new PrimitiveParams( primID, time, distance, angle, driveSpeed, false, 0.0, false, false ) );
            break;

        case TEST_TURN_ANGLE:
            primID = PrimitiveFactory::TURN_ANGLE;
            angle       = 45.0;     // 45 degrees
            driveSpeed  = 3.0;      // 3 feet per second
            m_primParam.emplace_back( new PrimitiveParams( primID, time, distance, angle, driveSpeed, false, 0.0, false, false ) );
            break;

        case TEST_DRIVE_PEG:
        	primID = PrimitiveFactory::DRIVE_PEG;
        	driveSpeed 	= 3;
        	time		= 5;
        	m_primParam.emplace_back( new PrimitiveParams( primID, time, distance, angle, driveSpeed, false, 0.0, false, false ) );
        	break;

        case TEST_DRIVE_DISTANCE_HOLD_POSITION:
            primID      = PrimitiveFactory::DRIVE_PEG;
            time 		= 5.0;      // 7 feet
            driveSpeed  = 3.0;      // 3 feet per second
            m_primParam.emplace_back( new PrimitiveParams( primID, time, distance, angle, driveSpeed, false, 0.0, false, false ) );

            primID      = PrimitiveFactory::HOLD_POSITION;
            time        = 0.5;          // half a second
            distance    = 0.0;
            driveSpeed  = 0.0;
            m_primParam.emplace_back( new PrimitiveParams( primID, time, distance, angle, driveSpeed, false, 0.0, false, false ) );
            break;
        case TEST_DRIVE_DISTANCE_HOLD_POSITION_TURN_ANGLE:
            primID      = PrimitiveFactory::DRIVE_DISTANCE;
            distance    = 7.0;      // 7 feet
            driveSpeed  = 3.0;      // 3 feet per second
            m_primParam.emplace_back( new PrimitiveParams( primID, time, distance, angle, driveSpeed, false, 0.0, false, false ) );

            primID      = PrimitiveFactory::HOLD_POSITION;
            time        = 0.5;          // half a second
            distance    = 0.0;
            driveSpeed  = 0.0;
            m_primParam.emplace_back( new PrimitiveParams( primID, time, distance, angle, driveSpeed, false, 0.0, false, false ) );

            primID = PrimitiveFactory::TURN_ANGLE;
            time        = 0.0;
            angle       = 45.0;     // 45 degrees
            driveSpeed  = 3.0;      // 3 feet per second
            m_primParam.emplace_back( new PrimitiveParams( primID, time, distance, angle, driveSpeed, false, 0.0, false, false ) );

            primID      = PrimitiveFactory::HOLD_POSITION;
            time        = 0.5;          // half a second
            distance    = 0.0;
            angle       = 0.0;
            driveSpeed  = 0.0;
            m_primParam.emplace_back( new PrimitiveParams( primID, time, distance, angle, driveSpeed, false, 0.0, false, false ) );
            break;

        default:
            break;

    }
    if ( !m_primParam.empty() )
    {
        m_currPrimSlot = 0;
        PrimitiveParams* param =  m_primParam[ m_currPrimSlot ];
        m_currPrim = PrimitiveFactory::GetInstance()->GetIPrimitive( param );
        if ( m_currPrim != nullptr )
        {
            m_currPrim->Init( param );
        }
    }
}

//-----------------------------------------------------------------------
// Method:      Run
// Description: This displays the joystick axis values and button states
//              to the dashboard
// Returns:     void
//-----------------------------------------------------------------------
void TestPrims::Run()
{
    if ( m_currPrim != nullptr )
    {
        m_currPrim->Run();
        if ( m_currPrim->IsDone() )
        {
            m_currPrimSlot++;
            PrimitiveParams* param =  m_primParam[ m_currPrimSlot ];
            m_currPrim = ( m_currPrimSlot < (int)m_primParam.size() ) ? PrimitiveFactory::GetInstance()->GetIPrimitive( param ) : nullptr;
            if ( m_currPrim != nullptr )
            {
                m_currPrim->Init( param );
            } else
            {
            	IChassis* chassis = ChassisFactory::GetInstance()->GetIChassis();
            	float speed = 0.0;
            	if ( std::abs( chassis->GetLeftBackVelocity() ) < 0.05  )
            	{
            		speed = 1.0;
            	}
            	ChassisFactory::GetInstance()->GetIChassis()->SetLeftPower( speed );
            	ChassisFactory::GetInstance()->GetIChassis()->SetRightPower(speed );
            }
        }
    }
    else
    {
    	IChassis* chassis = ChassisFactory::GetInstance()->GetIChassis();
    	float speed = 0.0;
    	if ( std::abs( chassis->GetLeftBackVelocity() ) < 0.05  )
    	{
    		speed = 1.0;
    	}
    	ChassisFactory::GetInstance()->GetIChassis()->SetLeftPower( speed );
    	ChassisFactory::GetInstance()->GetIChassis()->SetRightPower(speed );
    }
}


TestPrims::TestPrims() : m_primParam( ),
                         m_currPrimSlot( -1 ),
                         m_currPrim( nullptr )
{
}

TestPrims::~TestPrims()
{
    for ( unsigned int inx=0; inx<m_primParam.size(); ++inx )
    {
        delete m_primParam[inx];
        m_primParam[inx] = nullptr;
    }
    m_primParam.clear();
}

