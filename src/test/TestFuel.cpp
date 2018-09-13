/*
 * TestFuel.cpp
 *
 *  Created on: Feb 15, 2017
 *      Author: witcpale
 */

#include <test/TestFuel.h>
#include <subsys/factories/FuelHandlerFactory.h>
#include <subsys/interfaces/IFuelHandler.h>
#include <SmartDashboard/SmartDashboard.h>

using namespace Team302;
using namespace frc;

TestFuel* TestFuel::m_instance = nullptr;//Init the instance to nullptr

//----------------------------------------------------------------------------------
// Method:      GetInstance
// Description: If there isn't an instance of desired this class, create it.
//              Otherwise, hand out the single instance.
// Returns:     TestDragonXbox*    TestDragonStick singleton
//----------------------------------------------------------------------------------
TestFuel* TestFuel::GetInstance()
{
	if (TestFuel::m_instance == nullptr)
	{
		TestFuel::m_instance = new TestFuel();
	}
	return TestFuel::m_instance;
}


//-----------------------------------------------------------------------
// Method:		Init
// Description:	Initializes the test.   This should be called from the
//				appropriate Init method in Robot.cpp
//
//				Note: all tests are described with their enum.
// Returns:		void
//-----------------------------------------------------------------------
void TestFuel::Init
(
		IFUELHANDLER_TEST_SCENARIO	type	// <I> - test to run
)
{
	switch ( type )
	{
		case IFUEL_INTAKE_TEST:
			m_fuel->SetIntakePower( 1.0 );
			break;

		case IFUEL_SHOOTER_POWER_TEST:
			m_fuel->SetShooterPower( 0.5 );
			break;

		case IFUEL_SHOOTER_VELOCITY_TEST:
			m_fuel->SetShooterVelocity( 20 );
			break;

		case IFUEL_CONVEYOR_TEST:
			m_fuel->SetLowerConveyerPower( 1.0 );
			break;

		case IFUEL_LIFT_TEST:
			m_fuel->SetLiftConveyerPower( 1.0 );
			break;

		case IFUEL_SHOOT_CYCLE_TEST:
			m_fuel->SetShooterVelocity( 1.0 );
			m_fuel->SetLiftConveyerPower( .75 );
			m_fuel->SetLowerConveyerPower( 0.5 );
			break;

		default:
			break;

	}
}


//-----------------------------------------------------------------------
// Method:		Run
// Description:	This displays the joystick axis values and button states
//				to the dashboard
// Returns:		void
//-----------------------------------------------------------------------
void TestFuel::Run()
{

	float shooterSpeed = m_fuel->GetShooterSpeed();
	SmartDashboard::PutNumber( "TestFuel shooter speed: ", shooterSpeed );

	float range = m_fuel->GetRange();
	SmartDashboard::PutNumber( "TestFuel range: ", range );

}


TestFuel::TestFuel() : m_fuel( FuelHandlerFactory::GetInstance()->GetIFuelHandler() )
{
	// TODO Auto-generated constructor stub

}

TestFuel::~TestFuel()
{
	// TODO Auto-generated destructor stub
}

