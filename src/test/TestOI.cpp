/*
 * TestOI.cpp
 *
 *  Created on: Feb 3, 2017
 *      Author: witcpale
 */

#include <test/TestOI.h>
#include <driverInputs/OI.h>
#include <SmartDashboard/SmartDashboard.h>
#include <vector>
#include <string>

using namespace Team302;
using namespace frc;

TestOI* TestOI::m_instance = nullptr;//Init the instance to nullptr

//----------------------------------------------------------------------------------
// Method:      GetInstance
// Description: If there isn't an instance of desired this class, create it.
//              Otherwise, hand out the single instance.
// Returns:     TestDragonXbox*    TestDragonStick singleton
//----------------------------------------------------------------------------------
TestOI* TestOI::GetInstance()
{
	if (TestOI::m_instance == nullptr)
	{
		TestOI::m_instance = new TestOI();
	}
	return TestOI::m_instance;
}


//-----------------------------------------------------------------------
// Method:		Init
// Description:	Initializes the OI for the test.   This should
//				be called from the appropriate Init method in Robot.cpp
//
//				Note: all tests are described with their enum and have a
//				deadband eliminated.
// Returns:		void
//-----------------------------------------------------------------------
void TestOI::Init
(
		OI_TEST_SCENARIO	type	// <I> - test to run
)
{
	OI::AXIS_SENSITIVITY_CURVE curve = OI::AXIS_LINEAR;

	float					   scale = 1.0;

	switch ( type )
	{
		case TANK_DRIVE_LINEAR:
			m_test.resize( 2 );
			m_test[0] = OI::TANK_DRIVE_LEFT_CONTROL;
			m_test[1] = OI::TANK_DRIVE_RIGHT_CONTROL;
			break;

		case TANK_DRIVE_CUBIC:
			m_test.resize( 2 );
			m_test[0] = OI::TANK_DRIVE_LEFT_CONTROL;
			m_test[1] = OI::TANK_DRIVE_RIGHT_CONTROL;
			curve = OI::AXIS_CUBIC;
			break;

		case SCALED_TANK_DRIVE_LINEAR:
			m_test.resize( 2 );
			m_test[0] = OI::TANK_DRIVE_LEFT_CONTROL;
			m_test[1] = OI::TANK_DRIVE_RIGHT_CONTROL;
			scale = 0.5;
			break;

		case SCALED_TANK_DRIVE_CUBIC:
			m_test.resize( 2 );
			m_test[0] = OI::TANK_DRIVE_LEFT_CONTROL;
			m_test[1] = OI::TANK_DRIVE_RIGHT_CONTROL;
			scale = 0.5;
			curve = OI::AXIS_CUBIC;
			break;

		case ARCADE_DRIVE_LINEAR:
			m_test.resize( 2 );
			m_test[0] = OI::ARCADE_DRIVE_THROTTLE;
			m_test[1] = OI::ARCADE_DRIVE_STEER;
			break;

		case ARCADE_DRIVE_CUBIC:
			m_test.resize( 2 );
			m_test[0] = OI::ARCADE_DRIVE_THROTTLE;
			m_test[1] = OI::ARCADE_DRIVE_STEER;
			curve = OI::AXIS_CUBIC;
			break;
		case SCALED_ARCADE_DRIVE_LINEAR:
			m_test.resize( 2 );
			m_test[0] = OI::ARCADE_DRIVE_THROTTLE;
			m_test[1] = OI::ARCADE_DRIVE_STEER;
			scale = 0.5;
			break;

		case SCALED_ARCADE_DRIVE_CUBIC:
			m_test.resize( 2 );
			m_test[0] = OI::ARCADE_DRIVE_THROTTLE;
			m_test[1] = OI::ARCADE_DRIVE_STEER;
			curve = OI::AXIS_CUBIC;
			scale = 0.5;
			break;

		default:
			break;

	}

	for ( unsigned int inx=0; inx<m_test.size(); ++inx )
	{
		m_oi->SetScaleFactor( m_test[inx], scale );
		m_oi->SetCurve( m_test[inx], curve );
	}
}

//-----------------------------------------------------------------------
// Method:		Run
// Description:	This displays the joystick axis values and button states
//				to the dashboard
// Returns:		void
//-----------------------------------------------------------------------
void TestOI::Run()
{

	for ( unsigned int inx=0; inx<m_test.size(); ++inx )
	{
		std::string label = "OI function " + std::to_string( inx ) + " Axis : ";
		SmartDashboard::PutNumber( label, m_oi->GetAxis( m_test[inx] ) );

		std::string label2 = "OI function " + std::to_string( inx ) + " Button : ";
		SmartDashboard::PutBoolean( label2, m_oi->GetButton( m_test[inx] ) );
	}
}


TestOI::TestOI() : m_oi( OI::GetInstance() ),
				   m_test()
{
}

TestOI::~TestOI()
{
}

