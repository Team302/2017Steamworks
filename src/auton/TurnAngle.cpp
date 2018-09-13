/*
 * TurnAngle.cpp
 *
 *  Created on: Mar 11, 2017
 *      Author: Elite
 */

#include <auton/TurnAngle.h>
#include <subsys/factories/ChassisFactory.h>
#include <auton/PrimitiveFactory.h>
#include <SmartDashboard/SmartDashboard.h>
#include <cmath>
#include <subsys/CompBot/CompMap.h>

namespace Team302 {

TurnAngle::TurnAngle() :
        m_gyro( GyroFactory::GetInstance()->GetIGyro() ),
        m_chassis(ChassisFactory::GetInstance()->GetIChassis()),
        m_targetAngle(0.0),
        m_targetSpeed(0.0),
        m_leftSpeed(0.0),
        m_rightSpeed(0.0),
		m_speedMultiplier(0.0)
{
}

void TurnAngle::Init(PrimitiveParams* params)
{
    m_chassis->SetControlMode(DragonTalon::VELOCITY); //set chassis to use throttle control
    m_chassis->ResetDistance();
    m_targetAngle = params->GetAngle();
    m_speedMultiplier = std::abs(params->GetDriveSpeed() / 75.0); // TODO: 75 should be a constant //get target rotation speed from primitives
//    float deltaAngle = m_targetAngle - m_gyro->GetRawAngle();  // JW - renamed not a member attribute

    // JW - At this point, this code doesn't do anything to optimize the turn angle (e.g. it always
    //      turns right or turns left based on the delta angle && speed combo

    // JW - Not correct (see below)
    // Case 1:  Target Angle = 20 starting from 0 (turn right)
    //          currentAngle = 0
    //          deltaAngle = 20
    //          slowDownAngle:
    //              originally:  2
    //              updated:     18
    //          m_slowDownDelta: 2
    //
    // Case 2:  Target Angle = -20 starting from 20 (turn left)
    //          currentAngle = 20
    //          deltaAngle = -40
    //          slowDownAngle:
    //              originally:  -24
    //              updated:     -16
    //          m_slowDownDelta: 4
    //
    // Case 3:  Target Angle = 0 starting from -20 (turn right)
    //          currentAngle = -20
    //          deltaAngle = 20
    //          slowDownAngle:
    //              originally:  -18
    //              updated:     -2
    //          m_slowDownDelta: 2
    //
    // Case 4:  Target Angle = -20 starting from 0 (turn left)
    //          currentAngle = 0
    //          deltaAngle = -20
    //          slowDownAngle:
    //              originally:  -2
    //              updated:     -18
    //          m_slowDownDelta: 2
    //
    // Case 5:  Target Angle = 20 starting from -20 (turn right)
    //          currentAngle = -20
    //          deltaAngle = 40
    //          slowDownAngle:
    //              originally:  -16
    //              updated:     16
    //          m_slowDownDelta: 4
    //
    // Case 6:  Target Angle = 0 starting from 20 (turn left)
    //          currentAngle = 20
    //          deltaAngle = -20
    //          slowDownAngle:
    //              originally:  -2
    //              updated:     2
    //          m_slowDownDelta: 2
    //
    // Case 7:  Target Angle = 60 starting from 0 (turn right)
    //          currentAngle = 0->60
    //          deltaAngle = 60
    //          slowDownAngle:
    //              originally:  6
    //              updated:     54
    //          m_slowDownDelta: 6
    //
    // Case 8:  Target Angle = -60 starting from 0 (turn right)
    //          currentAngle = 0->-60
    //          deltaAngle = -60
    //          slowDownAngle:
    //              originally:  6
    //              updated:     -54
    //          m_slowDownDelta: 6
    //

    frc::SmartDashboard::PutNumber( "Target Speed For Turning", m_speedMultiplier );
    frc::SmartDashboard::PutNumber( "Target Angle For Turning", m_targetAngle );

    //Set target speeds for left and right to rotate. Left side is negated to spin different directions at same speed
    m_chassis->SetVelocityParams(kP, kI, kD, kF, m_leftSpeed, m_rightSpeed); // JW updated
//  SmartDashboard::PutNumber("targetSpeed" , m_targetSpeed);
}

void TurnAngle::Run() //best method ever. Does nothing, and should do nothing... NOT ANYMORE, BUDDY!
{
	float deltaAngle = m_targetAngle - m_gyro->GetRawAngle();
	m_leftSpeed = deltaAngle * m_speedMultiplier;
	m_rightSpeed = -deltaAngle * m_speedMultiplier;

	if (deltaAngle > 0)
	{
		m_leftSpeed += MINIMUM_SPEED;
		m_rightSpeed -= MINIMUM_SPEED;
	}
	else
	{
		m_leftSpeed -= MINIMUM_SPEED;
		m_rightSpeed += MINIMUM_SPEED;
	}

    frc::SmartDashboard::PutNumber( "Run left speed", m_leftSpeed );
    frc::SmartDashboard::PutNumber( "Run right speed", m_rightSpeed );

    m_chassis->SetVelocityParams(kP, kI, kD, kF, m_leftSpeed, m_rightSpeed);
}

bool TurnAngle::IsDone()
{
    bool isDone = false;

    float absDeltaAngle = std::abs(m_targetAngle - m_gyro->GetRawAngle());
    if ( absDeltaAngle < ANGLE_THRESH )
    {
        isDone = true;
        m_chassis->SetControlMode(DragonTalon::THROTTLE);
        m_chassis->SetLeftPower(0.0);
        m_chassis->SetRightPower(0.0);
    }

    return isDone;
}

TurnAngle::~TurnAngle()
{
}

} /* namespace Team302 */
