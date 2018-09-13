/*
 * DragonTalon.cpp
 *
 *  Created on: Feb 6, 2017
 *      Author: derekw
 */

#include <utils/DragonTalon.h>
#include <CANTalon.h>

//------------------------------------------------------------------------------
// Method:		<<constructor>>
// Description:	Since we have methods on the CANTalon that don't appear to be
// 				working, we have
//------------------------------------------------------------------------------
DragonTalon::DragonTalon
(
	int 	deviceID					// <I> - CAN ID
) : CANTalon( deviceID ),
	m_zeroPos( 0 ),
	m_sensorInverted( false )
{
}

//------------------------------------------------------------------------------
// Method:		Reset
// Description:	Store the current encoder positon, so GetEncoderPos will be
//				relative to this value.
// Returns:		void
//------------------------------------------------------------------------------
void DragonTalon::Reset()
{
	CANTalon::SetEncPosition(0.0);
}

//Note: for posision, it takes rotations as target.
//For velocity, it takes desired RPM.
//Counts per rotation is set in chassis in accordance with constant in chassis map
void DragonTalon::SetControlMode(DRAGON_CONTROL_MODE mode)
{
	switch(mode)
	{
		case THROTTLE:
			CANTalon::SetControlMode(CANSpeedController::kPercentVbus);
			break;

		case FOLLOWER:
			CANTalon::SetControlMode(CANSpeedController::kFollower);
			break;

		case VELOCITY:
			CANTalon::SetControlMode(CANSpeedController::kSpeed);
			break;

		case POSITION:
			CANTalon::SetControlMode(CANSpeedController::kPosition);
			break;

		case VOLTAGE:
			CANTalon::SetControlMode(CANSpeedController::kVoltage);
			break;

		default:
			CANTalon::SetControlMode(CANSpeedController::kPercentVbus);
			break;

	}

}

void DragonTalon::SetClosedLoopParams(double kP, double kI, double kD, double kF)
{
	CANTalon::SetAllowableClosedLoopErr(0); /* always servo */

	CANTalon::SetF(kF); //set feed-forward gain
	CANTalon::SetP(kP); //set p-gain
	CANTalon::SetI(kI); //set i-gain
	CANTalon::SetD(kD); //set d-gain
}

