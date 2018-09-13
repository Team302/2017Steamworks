/*
 * TestFactories.cpp
 *
 *  Created on: Feb 18, 2017
 *      Author: derekw
 */

#include <test/TestFactories.h>

#include <subsys/factories/ChassisFactory.h>
#include <subsys/factories/ClimberFactory.h>
#include <subsys/factories/FuelHandlerFactory.h>
#include <subsys/factories/GearFactory.h>

#include <subsys/interfaces/IChassis.h>
#include <subsys/interfaces/IClimber.h>
#include <subsys/interfaces/IFuelHandler.h>
#include <subsys/interfaces/IGearer.h>

#include <SmartDashboard/SmartDashboard.h>

using namespace Team302;
using namespace frc;

TestFactories* TestFactories::m_instance = nullptr;//Init the instance to nullptr

//----------------------------------------------------------------------------------
// Method:      GetInstance
// Description: If there isn't an instance of desired class, create it.
//              Otherwise, hand out the single instance.
// Returns:     TestFactories*    TestDragonStick singleton
//----------------------------------------------------------------------------------
TestFactories* TestFactories::GetInstance()
{
	if (TestFactories::m_instance == nullptr)
	{
		TestFactories::m_instance = new TestFactories();
	}
	return TestFactories::m_instance;
}


//-----------------------------------------------------------------------
// Method:		Run
// Description:	This displays the pass/fail with the factory
// Returns:		void
//-----------------------------------------------------------------------
void TestFactories::Run()
{
	std::string pass = "Pass";
	std::string fail = "Fail";

	std::string factoryName;
	std::string status;

	IChassis* chassis = ChassisFactory::GetInstance()->GetIChassis();
	factoryName = "ChassisFactory: ";
	status = ( chassis != nullptr ) ? pass : fail;
	SmartDashboard::PutString( factoryName, status );

	IClimber* climber = ClimberFactory::GetInstance()->GetIClimber();
	factoryName = "ClimberFactory: ";
	status = ( climber != nullptr ) ? pass : fail;
	SmartDashboard::PutString( factoryName, status );

	IFuelHandler* fuel = FuelHandlerFactory::GetInstance()->GetIFuelHandler();
	factoryName = "FuelHandlerFactory: ";
	status = ( fuel != nullptr ) ? pass : fail;
	SmartDashboard::PutString( factoryName, status );

	IGearer* gear = GearFactory::GetInstance()->GetIGearer();
	factoryName = "GearFactory: ";
	status = ( gear != nullptr ) ? pass : fail;
	SmartDashboard::PutString( factoryName, status );
}
