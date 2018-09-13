/*
 * ArcadeDrive.cpp
 *
 *  Created on: Jan 14, 2017
 *      Author: Owen
 *      Note: how to do code please??
 */

#include <teleopDrive/ArcadeDrive.h>
#include <subsys/interfaces/IChassis.h> //updated to new dir -J.S
#include <subsys/factories/ChassisFactory.h> //updated to new dir -J.S
#include <teleopDrive/IDrive.h> //updated to new dir -J.S
#include <driverInputs/OI.h>
#include <driverInputs/DragonXbox.h>

using namespace Team302;

void ArcadeDrive::DriveWithJoysticks() const
{
    // Read the motor speeds needed
	float steer = DragonXbox::GetDriver()->GetAxis( DragonXbox::X_AXIS_RIGHT_JOYSTICK );
	float throttle = DragonXbox::GetDriver()->GetAxis( DragonXbox::Y_AXIS_LEFT_JOYSTICK );

    // Tell the robot how to speed
    float leftSpeed  = throttle + steer;
    float rightSpeed = throttle - steer;

    bool leftNudge = DragonXbox::GetDriver()-> GetButton(DragonXbox::X_BUTTON);
    bool rightNudge = DragonXbox::GetDriver()-> GetButton(DragonXbox::B_BUTTON);

    leftSpeed += rightNudge ? NUDGE_AMOUNT : 0;
    rightSpeed -= rightNudge ? NUDGE_AMOUNT : 0;
    leftSpeed -= leftNudge ? NUDGE_AMOUNT : 0;
    rightSpeed += leftNudge ? NUDGE_AMOUNT : 0;

    // Check current limiting buttons, Y: enable, A: disable
    if (DragonXbox::GetDriver()->GetButton(DragonXbox::Y_BUTTON))
	{
    	m_chassis->EnableCurrentLimiting();
	}
    else if (DragonXbox::GetDriver()->GetButton(DragonXbox::A_BUTTON))
	{
    	m_chassis->DisableCurrentLimiting();
	}

    // Set the motors
    m_chassis->SetLeftPower( leftSpeed );
    m_chassis->SetRightPower( rightSpeed );
}

ArcadeDrive::ArcadeDrive() : m_oi( OI::GetInstance())
{
	DragonXbox::GetDriver()->SetCurve( DragonXbox::X_AXIS_RIGHT_JOYSTICK,DragonXbox::AXIS_CUBIC );
	DragonXbox::GetDriver()->SetCurve( DragonXbox::Y_AXIS_LEFT_JOYSTICK, DragonXbox::AXIS_CUBIC );

	m_chassis = ChassisFactory::GetInstance()->GetIChassis();
}

ArcadeDrive::~ArcadeDrive()
{
}

