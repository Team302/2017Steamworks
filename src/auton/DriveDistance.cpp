/*
 * DriveDistance.cpp
 *
 *  Created on: Jan 18, 2017
 *      Author: Jonah Shader
 */

#include <auton/DriveDistance.h>
#include <auton/Gear.h>
#include <auton/Fuel.h>
#include <auton/PrimitiveFactory.h>
#include <subsys/factories/ChassisFactory.h>
#include <cmath>
#include <utils/DragonPID.h>
#include<SmartDashboard/SmartDashboard.h>

namespace Team302
{

DriveDistance::DriveDistance() : SuperDrive(),
		m_chassis(ChassisFactory::GetInstance()->GetIChassis()),
		m_targetDistance(0.0),
		m_timeRemaining(DEFAULT_TIME_REMAINING),
		initCounts(0)
{
	constructCounts ++;
//	SmartDashboard::PutNumber("Constructor" , constructCounts);
}

void DriveDistance::Init(PrimitiveParams* params)
{
	SuperDrive::Init(params);
	//Extract parameters from m_params
	m_targetDistance = params->GetDistance();
	initCounts ++;
//	SmartDashboard::PutNumber("Init times" , initCounts);
//	SmartDashboard::PutNumber("m_targetDistance" , m_targetDistance);
	m_chassis->ResetDistance();
	if (params->GetTime() > 0)	//Only set timeout when its not zero (or lower), m_timeRemaining is already set to the DEFAULT_TIME_REMAINING constant.
	{
		m_timeRemaining = params->GetTime();
	}
}

bool DriveDistance::IsDone() //Getter: gets m_done
{
    //average left and right distances for overall distance driven
    float currentDistance = (m_chassis->GetLeftBackDistance() + m_chassis->GetRightBackDistance()) / 2.0;
//  float currentDistance = m_chassis->GetRightBackDistance();
//    frc::SmartDashboard::PutNumber("distance", currentDistance);
//    frc::SmartDashboard::PutNumber( "Right Distance", m_chassis->GetRightBackDistance());
//    frc::SmartDashboard::PutNumber( "Left Distance", m_chassis->GetLeftBackDistance());
//    frc::SmartDashboard::PutNumber("target", m_targetDistance);
//    bool reachedTarget = std::abs(currentDistance) > ((std::abs(m_targetDistance) - (COMPENSATE_SCALE * std::abs(m_chassis->GetRightBackVelocity()) * IPrimitive::LOOP_LENGTH)));
    bool reachedTarget = std::abs(currentDistance) > (std::abs(m_targetDistance));
//    SmartDashboard::PutBoolean("ReachedTarget" , reachedTarget);
//    return ( reachedTarget &&
//    		 PrimitiveFactory::GetInstance()->GetGearPrim()->IsDone() &&
//    		 PrimitiveFactory::GetInstance()->GetFuelPrim()->IsDone() );//  return std::abs(currentDistance) > ((std::abs(m_targetDistance) + (COMPENSATE_SCALE * std::abs(m_chassis->GetRightBackVelocity()) * IPrimitive::LOOP_LENGTH)));

    reachedTarget = reachedTarget || m_timeRemaining < (IPrimitive::LOOP_LENGTH / 2.0);

    m_timeRemaining -= IPrimitive::LOOP_LENGTH;
    return reachedTarget;
}

} /* namespace Team302 */
