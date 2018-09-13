#include <iostream>
#include <memory>
#include <string>

#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

#include <RobotDefn.h>

#include <subsys/CompBot/CompBotGearer.h>
#include <subsys/factories/ChassisFactory.h>
#include <subsys/interfaces/IChassis.h>

#include <subsys/interfaces/IFuelHandler.h>
#include <subsys/factories/FuelHandlerFactory.h>

#include <subsys/interfaces/IGyro.h>
#include <subsys/factories/GyroFactory.h>

#include <teleopDrive/IDrive.h>
#include <teleopDrive/ArcadeDrive.h>
#include <teleopDrive/TankDrive.h>

#include <teleopClimb/ClimbHandler.h>

#include <teleopFuel/FuelManip.h>

#include <teleopGear/GearHandler.h>
#include <subsys/factories/GearFactory.h>
#include <subsys/interfaces/IGearer.h>
#include <driverInputs/DragonXbox.h>

#include <test/SWBotChassisTest.h>
#include <test/TestDragonXbox.h>
#include <test/TestOI.h>
#include <test/TestPrims.h>
#include <test/TestIChassis.h>
#include <test/TestFactories.h>
#include <auton/CyclePrimitives.h>
#include <utils/DragonTalon.h>
#include <Solenoid.h>
#include <Compressor.h>
#include <teleopHold/teleopHold.h>

#include <Relay.h>

using namespace Team302;

class Robot: public frc::IterativeRobot {
public:
	int autonInits = 0;
	bool BlinkLED = false;
	void RobotInit()
	{

		m_primCycler = new CyclePrimitives();
		//--------------------------------------------------------
		// Put the robot name and number on the dashboard
		//--------------------------------------------------------
		std::string robotName = "unknown";
		switch ( ROBOT_CONFIGURATION )
		{
		case SOFTWARE_BOT:
			robotName = "Software Bot";
			break;

		case COMP_BOT:
			robotName = "Competition Bot";
			break;

		case EIGHTY_BOT:
			robotName = "Eighty Bot";
			break;

		default:
			//TODO: print error somewhere (not really important)
			break;
		}

		//		frc::SmartDashboard::PutString("Robot Name: ",  robotName );
		//		frc::SmartDashboard::PutNumber("Robot Number: ",  ROBOT_CONFIGURATION );
		m_testNumber = -1;

		m_drive = new ArcadeDrive();
		//		m_drive = new TankDrive();
		m_climb = ClimbHandler::GetInstance();
		m_fuel  = new FuelManip();
		m_gear  = new GearHandler();
		m_teleHold = new teleopHold();

		m_chassis = ChassisFactory::GetInstance()->GetIChassis();
		m_gearer = GearFactory::GetInstance()->GetIGearer();
		m_gyro = GyroFactory::GetInstance()->GetIGyro();

		m_LED = new Relay( 0, Relay::Direction::kBothDirections );
		// White Wire = red light
		// Red Wire = voltage
		// Yellow Wire = blue

		joe = new Compressor(0);
		//		m_primCycler->Init();
		m_chassis->SetControlMode(DragonTalon::DRAGON_CONTROL_MODE::THROTTLE);

		m_gyro->ResetGyro();
	}

	/*
	 * This autonomous (along with the chooser code above) shows how to select
	 * between different autonomous modes using the dashboard. The sendable
	 * chooser code works with the Java SmartDashboard. If you prefer the
	 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
	 * GetString line to get the auto name from the text box below the Gyro.
	 *
	 * You can add additional auto modes by adding additional comparisons to the
	 * if-else structure below with additional strings. If using the
	 * SendableChooser make sure to add them to the chooser code above as well.
	 */
	void AutonomousInit() override
	{
		m_gyro->ResetAngle();
		autonInits++;
		m_primCycler->Init();

		//		PRIM_TEST_SCENARIO primTest = (PRIM_TEST_SCENARIO) ( 5 );
		//		TestPrims::GetInstance()->Init( primTest );
	}

	void AutonomousPeriodic()
	{
		frc::SmartDashboard::PutNumber( "Gyro Auton Angle", m_gyro->GetRawAngle());

		m_primCycler->RunCurrentPrimitive();
		//		TestPrims::GetInstance()->Run();
		//		frc::SmartDashboard::PutNumber("autonInits", autonInits);
	}


	void TeleopInit()
	{
		m_chassis->SetControlMode(DragonTalon::DRAGON_CONTROL_MODE::THROTTLE);
		m_gyro->ResetAngle();
	}

	void TeleopPeriodic()
	{
		m_drive->DriveWithJoysticks();
		m_fuel->Run();
		m_gear->UseJoystickGearFunctions();
		m_climb->RunState();
		m_teleHold->UseJoystickHoldFunction();

		if ( m_gearer->HasGear() )
		{
			m_LED->Set(Relay::Value::kReverse);
		}
		else if ( DragonXbox::GetCopilot()->GetButton( DragonXbox::PRESS_LEFT_STICK ) )
		{
			m_LED->Set(Relay::Value::kForward );
		}
		else
		{
			m_LED->Set( Relay::Value::kOn );
		}

		frc::SmartDashboard::PutBoolean("Peg", m_gearer->IsPegPresent());
		frc::SmartDashboard::PutBoolean("Gear", m_gearer->HasGear());

		SmartDashboard::PutNumber("Pressure", m_gearer->GetPressure());
		frc::SmartDashboard::PutNumber( "Current gyro Angle", m_gyro->GetRawAngle() );

		joe->Start();
	}

	void TestInit()
	{
//		TestFactories::GetInstance()->Run();
//
//		//-----------------------------------------------------------------
//		// Cycle through the test scenarios each time test is initialized
//		//-----------------------------------------------------------------
//		m_testNumber++;
//		std::string testType = "unknown";
//		if( m_testNumber < NUM_ICHASSIS_TEST_SCENARIOS )
//		{
//			ICHASSIS_TEST_SCENARIO chassisTest = (ICHASSIS_TEST_SCENARIO) m_testNumber;
//			testType = "IChassis test " + chassisTest;
//			TestIChassis::GetInstance()->Init( chassisTest );
//		}
//		else if ( m_testNumber < ( NUM_ICHASSIS_TEST_SCENARIOS + NUM_PRIM_TEST_SCENARIOS ) )
//		{
//			PRIM_TEST_SCENARIO primTest = (PRIM_TEST_SCENARIO) ( m_testNumber - NUM_ICHASSIS_TEST_SCENARIOS );
//			testType = "Primitive test " + primTest;
//			TestPrims::GetInstance()->Init( primTest );
//		}
//		else if ( m_testNumber < ( NUM_ICHASSIS_TEST_SCENARIOS + NUM_PRIM_TEST_SCENARIOS  + NUM_DRAGONXBOX_TEST_SCENARIOS) )
//		{
//			DRAGONXBOX_TEST_SCENARIO xboxTest = (DRAGONXBOX_TEST_SCENARIO) (m_testNumber - ( NUM_ICHASSIS_TEST_SCENARIOS + NUM_PRIM_TEST_SCENARIOS ) );
//			testType = "Dragon XBOX test " + xboxTest;
//			TestDragonXbox::GetInstance()->Init( xboxTest );
//		}
//		else if ( m_testNumber < ( NUM_ICHASSIS_TEST_SCENARIOS + NUM_PRIM_TEST_SCENARIOS  + NUM_DRAGONXBOX_TEST_SCENARIOS + NUM_OI_TEST_SCENARIOS ) )
//		{
//			OI_TEST_SCENARIO oiTest = (OI_TEST_SCENARIO) ( m_testNumber - ( NUM_ICHASSIS_TEST_SCENARIOS + NUM_PRIM_TEST_SCENARIOS - NUM_DRAGONXBOX_TEST_SCENARIOS ) );
//			testType = "OI test " + oiTest;
//			TestOI::GetInstance()->Init( oiTest );
//		}
//		else
//		{
//			m_testNumber = 0;
//			ICHASSIS_TEST_SCENARIO chassisTest = CHASSIS_FORWARD;
//			testType = "IChassis test " + chassisTest;
//			TestIChassis::GetInstance()->Init( chassisTest );
//		}
//		//		SmartDashboard::PutString( "Test Running: ", testType );  // Put the test name/number on the dashboard
	}

	void TestPeriodic()
	{
//		//-----------------------------------------------------------------
//		// Run the test scenario
//		//-----------------------------------------------------------------
//		if( m_testNumber < NUM_ICHASSIS_TEST_SCENARIOS )
//		{
//			TestIChassis::GetInstance()->Run();
//		}
//		else if ( m_testNumber < ( NUM_ICHASSIS_TEST_SCENARIOS + NUM_PRIM_TEST_SCENARIOS ) )
//		{
//			TestPrims::GetInstance()->Run();
//		}
//		else if ( m_testNumber < ( NUM_ICHASSIS_TEST_SCENARIOS + NUM_PRIM_TEST_SCENARIOS  + NUM_DRAGONXBOX_TEST_SCENARIOS) )
//		{
//			TestDragonXbox::GetInstance()->Run();
//		}
//		else if ( m_testNumber < ( NUM_ICHASSIS_TEST_SCENARIOS + NUM_PRIM_TEST_SCENARIOS  + NUM_DRAGONXBOX_TEST_SCENARIOS + NUM_OI_TEST_SCENARIOS ) )
//		{
//			TestOI::GetInstance()->Run();
//		}
//
//		lw->Run();

	}

private:
	frc::LiveWindow* lw = LiveWindow::GetInstance();
	frc::SendableChooser<std::string> chooser;
	const std::string autoNameDefault = "Default";
	const std::string autoNameCustom = "My Auto";
	std::string autoSelected;
	int 				m_testNumber;
	IDrive* 			m_drive;
	ClimbHandler*		m_climb;
	FuelManip*			m_fuel;
	GearHandler*		m_gear;
	teleopHold*			m_teleHold;
	CyclePrimitives*	m_primCycler;

	IChassis* 			m_chassis;
	IGearer*			m_gearer;
	IGyro*				m_gyro;

	Relay*				m_LED;

	Compressor*	joe;

};

START_ROBOT_CLASS(Robot)
