/*
 * TestIChassis.cpp
 *
 *  Created on: Feb 15, 2017
 *      Author: witcpale
 */

#include <test/TestIChassis.h>
#include <subsys/factories/ChassisFactory.h>
#include <subsys/interfaces/IChassis.h>
#include <SmartDashboard/SmartDashboard.h>

using namespace Team302;
using namespace frc;

TestIChassis* TestIChassis::m_instance = nullptr;//Init the instance to nullptr

//----------------------------------------------------------------------------------
// Method:      GetInstance
// Description: If there isn't an instance of desired this class, create it.
//              Otherwise, hand out the single instance.
// Returns:     TestDragonXbox*    TestDragonStick singleton
//----------------------------------------------------------------------------------
TestIChassis* TestIChassis::GetInstance()
{
	if (TestIChassis::m_instance == nullptr)
	{
		TestIChassis::m_instance = new TestIChassis();
	}
	return TestIChassis::m_instance;
}

//-----------------------------------------------------------------------
// Method:		Init
// Description:	Initializes the test.   This should be called from the
//				appropriate Init method in Robot.cpp
//
//				Note: all tests are described with their enum.
// Returns:		void
//-----------------------------------------------------------------------
void TestIChassis::Init
(
		ICHASSIS_TEST_SCENARIO	type	// <I> - test to run
)
{
	switch ( type )
	{
		case CHASSIS_FORWARD:
			m_leftPower  = 1.0;
			m_rightPower = 1.0;
			break;

		case CHASSIS_BACKWARD:
			m_leftPower  = -1.0;
			m_rightPower = -1.0;
			break;

		case CHASSIS_SPIN_CW:
			m_leftPower  =  1.0;
			m_rightPower = -1.0;
			break;

		case CHASSIS_SPIN_CCW:
			m_leftPower  = -1.0;
			m_rightPower =  1.0;
			break;

		case CHASSIS_RIGHT_ONLY:
			m_leftPower  = 0.0;
			m_rightPower = 1.0;
			break;

		case CHASSIS_LEFT_ONLY:
			m_leftPower  = 1.0;
			m_rightPower = 0.0;
			break;

		default:
			break;

	}

	m_chassis->ResetDistance();
	m_chassis->SetLeftPower( m_leftPower );
	m_chassis->SetRightPower( m_rightPower );
}

//-----------------------------------------------------------------------
// Method:		Run
// Description:	This displays the joystick axis values and button states
//				to the dashboard
// Returns:		void
//-----------------------------------------------------------------------
void TestIChassis::Run()
{

	float leftVel = m_chassis->GetLeftVelocity();
	SmartDashboard::PutNumber( "TestIChassis Left Velocity: ", leftVel );

	float leftBackVel = m_chassis->GetLeftBackVelocity();
	SmartDashboard::PutNumber( "TestIChassis Left Back Velocity: ", leftBackVel );

	float leftFrontVel = m_chassis->GetLeftFrontVelocity();
	SmartDashboard::PutNumber( "TestIChassis Left Front Velocity: ", leftFrontVel );

	float rightVel = m_chassis->GetRightVelocity();
	SmartDashboard::PutNumber( "TestIChassis Right Velocity: ", rightVel );

	float rightBackVel = m_chassis->GetRightBackVelocity();
	SmartDashboard::PutNumber( "TestIChassis Right Back Velocity: ", rightBackVel );

	float rightFrontVel = m_chassis->GetRightFrontVelocity();
	SmartDashboard::PutNumber( "TestIChassis Right Front Velocity: ", rightFrontVel );

	float leftDist = m_chassis->GetLeftDistance();
	SmartDashboard::PutNumber( "TestIChassis Left Distance: ", leftDist );

	float leftBackDist = m_chassis->GetLeftBackDistance();
	SmartDashboard::PutNumber( "TestIChassis Left Back Distance: ", leftBackDist );

	float leftFrontDist = m_chassis->GetLeftFrontDistance();
	SmartDashboard::PutNumber( "TestIChassis Left Front Distance: ", leftFrontDist );

	float rightDist = m_chassis->GetRightDistance();
	SmartDashboard::PutNumber( "TestIChassis Right Distance: ", rightDist );

	float rightBackDist = m_chassis->GetRightBackDistance();
	SmartDashboard::PutNumber( "TestIChassis Right Back Distance: ", rightBackDist );

	float rightFrontDist = m_chassis->GetRightFrontDistance();
	SmartDashboard::PutNumber( "TestIChassis Right Front Distance: ", rightFrontDist );

	if ( ( m_leftPower - COMPARE_TOLERANCE ) > 0.0 )  // leftside moving forward
	{
		if ( leftVel > 0.0 && leftBackVel > 0.0 && leftFrontVel > 0.0 && leftDist > 0.0 && leftBackDist > 0.0 && leftFrontDist > 0.0 )
		{
			SmartDashboard::PutString( "Left Side Tests : ", "PASSED" );
		}
		else
		{
			SmartDashboard::PutString( "Left Side Tests : ", "FAILED" );
		}
	}
	else if ( ( m_leftPower + COMPARE_TOLERANCE ) >  0.0 ) // leftside stationary
	{
		if ( leftVel > 0.0 && leftBackVel > 0.0 && leftFrontVel > 0.0 && leftDist > 0.0 && leftBackDist > 0.0 && leftFrontDist > 0.0 )
		{
			SmartDashboard::PutString( "Left Side Tests : ", "PASSED" );
		}
		else
		{
			SmartDashboard::PutString( "Left Side Tests : ", "FAILED" );
		}
	}
	else // leftside moving backward
	{
		if ( leftVel < 0.0 && leftBackVel < 0.0 && leftFrontVel < 0.0 && leftDist < 0.0 && leftBackDist < 0.0 && leftFrontDist < 0.0 )
		{
			SmartDashboard::PutString( "Left Side Tests : ", "PASSED" );
		}
		else
		{
			SmartDashboard::PutString( "Left Side Tests : ", "FAILED" );
		}
	}


}

TestIChassis::TestIChassis() : m_chassis( ChassisFactory::GetInstance()->GetIChassis() ),
							   m_leftPower( 0.0 ),
							   m_rightPower( 0.0 )
{
// TODO Auto-generated constructor stub

}

TestIChassis::~TestIChassis()
{
// TODO Auto-generated destructor stub
}

