/*
 * TestDragonPad.cpp
 *
 *  Created on: Feb 3, 2017
 *      Author: witcpale
 */

#include <test/TestDragonXbox.h>
#include <driverInputs/DragonXbox.h>
#include <SmartDashboard/SmartDashboard.h>

using namespace Team302;
using namespace frc;

#define DRAGONXBOX_PORT 0

TestDragonXbox* TestDragonXbox::m_instance = nullptr;//Init the instance to nullptr

//----------------------------------------------------------------------------------
// Method:      GetInstance
// Description: If there isn't an instance of desired this class, create it.
//              Otherwise, hand out the single instance.
// Returns:     TestDragonStick*    TestDragonStick singleton
//----------------------------------------------------------------------------------
TestDragonXbox* TestDragonXbox::GetInstance()
{
	if (TestDragonXbox::m_instance == nullptr)
	{
		TestDragonXbox::m_instance = new TestDragonXbox();
	}
	return TestDragonXbox::m_instance;
}

//-----------------------------------------------------------------------
// Method:		<<constructor>>
// Description:	creates the test environment attributes
//-----------------------------------------------------------------------
TestDragonXbox::TestDragonXbox() : m_xboxController( new DragonXbox( DRAGONXBOX_PORT ) )
{
}

//-----------------------------------------------------------------------
// Method:		Init
// Description:	Initializes the DragonXbox for the test.   This should
//				be called from the appropriate Init method in Robot.cpp
//
//				Note: all tests are described with their enum and have a
//				deadband eliminated.
// Returns:		void
//-----------------------------------------------------------------------
void TestDragonXbox::Init
(
		DRAGONXBOX_TEST_SCENARIO	type	// <I> - test to run
)
{
	DragonXbox::AXIS_SENSITIVITY_CURVE curve = DragonXbox::AXIS_LINEAR;
	float					   scale = 1.0;

	switch ( type )
	{
		case LINEAR_FULL_SCALE:
			break;

		case LINEAR_HALF_SCALE:
			scale = 0.5;
			break;

		case CUBIC_FULL_SCALE:
			curve = DragonXbox::AXIS_CUBIC;
			break;

		case CUBIC_HALF_SCALE:
			curve = DragonXbox::AXIS_CUBIC;
			scale = 0.5;
			break;

		default:
			break;

	}

	m_xboxController->SetCurve( DragonXbox::X_AXIS_LEFT_JOYSTICK, curve );
	m_xboxController->SetScale( DragonXbox::X_AXIS_LEFT_JOYSTICK, scale );

	m_xboxController->SetCurve( DragonXbox::Y_AXIS_LEFT_JOYSTICK, curve );
	m_xboxController->SetScale( DragonXbox::Y_AXIS_LEFT_JOYSTICK, scale );

	m_xboxController->SetCurve( DragonXbox::LEFT_TRIGGER, curve );
	m_xboxController->SetScale( DragonXbox::LEFT_TRIGGER, scale );

	m_xboxController->SetCurve( DragonXbox::RIGHT_TRIGGER, curve );
	m_xboxController->SetScale( DragonXbox::RIGHT_TRIGGER, scale );

	m_xboxController->SetCurve( DragonXbox::X_AXIS_RIGHT_JOYSTICK, curve );
	m_xboxController->SetScale( DragonXbox::X_AXIS_RIGHT_JOYSTICK, scale );

	m_xboxController->SetCurve( DragonXbox::Y_AXIS_RIGHT_JOYSTICK, curve );
	m_xboxController->SetScale( DragonXbox::Y_AXIS_RIGHT_JOYSTICK, scale );
}



//-----------------------------------------------------------------------
// Method:		Run
// Description:	This displays the joystick axis values and button status
//				to the dashboard
// Returns:		void
//-----------------------------------------------------------------------
void TestDragonXbox::Run()
{
	SmartDashboard::PutNumber( "Left Joystick - X-Axis: ", m_xboxController->GetAxis( DragonXbox::X_AXIS_LEFT_JOYSTICK ) );
	SmartDashboard::PutNumber( "Left Joystick - Y-Axis: ", m_xboxController->GetAxis( DragonXbox::Y_AXIS_LEFT_JOYSTICK ) );

	SmartDashboard::PutNumber( "Left Joystick - Trigger: ", m_xboxController->GetAxis( DragonXbox::LEFT_TRIGGER ) );


	SmartDashboard::PutNumber( "Right Joystick - X-Axis: ", m_xboxController->GetAxis( DragonXbox::X_AXIS_RIGHT_JOYSTICK ) );
	SmartDashboard::PutNumber( "Right Joystick - Y-Axis: ", m_xboxController->GetAxis( DragonXbox::Y_AXIS_RIGHT_JOYSTICK ) );

	SmartDashboard::PutNumber( "Right Joystick - Trigger: ", m_xboxController->GetAxis( DragonXbox::RIGHT_TRIGGER ) );

	SmartDashboard::PutBoolean( "A Button: ", m_xboxController->GetButton( DragonXbox::A_BUTTON ) );
	SmartDashboard::PutBoolean( "B Button: ", m_xboxController->GetButton( DragonXbox::B_BUTTON ) );
	SmartDashboard::PutBoolean( "X Button: ", m_xboxController->GetButton( DragonXbox::X_BUTTON ) );
	SmartDashboard::PutBoolean( "Y Button: ", m_xboxController->GetButton( DragonXbox::Y_BUTTON ) );
	SmartDashboard::PutBoolean( "LEFT_BUMPER: ", m_xboxController->GetButton( DragonXbox::LEFT_BUMPER ) );
	SmartDashboard::PutBoolean( "RIGHT_BUMPER: ", m_xboxController->GetButton( DragonXbox::RIGHT_BUMPER ) );
	SmartDashboard::PutBoolean( "BACK_BUTTON: ", m_xboxController->GetButton( DragonXbox::BACK_BUTTON ) );
	SmartDashboard::PutBoolean( "START_BUTTON: ", m_xboxController->GetButton( DragonXbox::START_BUTTON ) );
	SmartDashboard::PutBoolean( "PRESS_LEFT_STICK: ", m_xboxController->GetButton( DragonXbox::PRESS_LEFT_STICK ) );
	SmartDashboard::PutBoolean( "PRESS_RIGHT_STICK: ", m_xboxController->GetButton( DragonXbox::PRESS_RIGHT_STICK ) );
	SmartDashboard::PutBoolean( "LEFT_TRIGGER_PRESSED: ", m_xboxController->GetButton( DragonXbox::LEFT_TRIGGER_PRESSED ) );
	SmartDashboard::PutBoolean( "RIGHT_TRIGGER_PRESSED: ", m_xboxController->GetButton( DragonXbox::RIGHT_TRIGGER_PRESSED ) );
//	SmartDashboard::PutBoolean( "POV_0_PRESSED: ", m_xboxController->GetButton( DragonXbox::POV_0_PRESSED ) );
//	SmartDashboard::PutBoolean( "POV_45_PRESSED: ", m_xboxController->GetButton( DragonXbox::POV_45_PRESSED ) );
//	SmartDashboard::PutBoolean( "POV_90_PRESSED: ", m_xboxController->GetButton( DragonXbox::POV_90_PRESSED ) );
//	SmartDashboard::PutBoolean( "POV_135_PRESSED: ", m_xboxController->GetButton( DragonXbox::POV_135_PRESSED ) );
//	SmartDashboard::PutBoolean( "POV_180_PRESSED: ", m_xboxController->GetButton( DragonXbox::POV_180_PRESSED ) );
//	SmartDashboard::PutBoolean( "POV_225_PRESSED: ", m_xboxController->GetButton( DragonXbox::POV_225_PRESSED ) );
//	SmartDashboard::PutBoolean( "POV_270_PRESSED: ", m_xboxController->GetButton( DragonXbox::POV_270_PRESSED ) );
//	SmartDashboard::PutBoolean( "POV_315_PRESSED: ", m_xboxController->GetButton( DragonXbox::POV_315_PRESSED ) );
}


//-----------------------------------------------------------------------
// Method:		<<destructor>>
// Description:	cleans up other objects
//-----------------------------------------------------------------------
TestDragonXbox::~TestDragonXbox()
{
	delete m_xboxController;
	m_xboxController = nullptr;
}
