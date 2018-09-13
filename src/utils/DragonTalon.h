/*
 * DragonTalon.h
 *
 *  Created on: Feb 6, 2017
 *      Author: derekw
 */

#ifndef SRC_UTILS_DRAGONTALON_H_
#define SRC_UTILS_DRAGONTALON_H_

#include <CanTalon.h>

class DragonTalon : public CANTalon
{
	public:

	enum DRAGON_CONTROL_MODE
	{
		POSITION,
		VELOCITY,
		THROTTLE,
		FOLLOWER,
		VOLTAGE
	};

		//------------------------------------------------------------------------------
		// Method:		<<constructor>>
		// Description:	Since we have methods on the CANTalon that don't appear to be
		// 				working, we have
		//------------------------------------------------------------------------------
		DragonTalon
		(
			int deviceID				// <I> - CAN ID
		);


		//------------------------------------------------------------------------------
		// Method:		Reset
		// Description:	Store the current encoder positon, so GetEncoderPos will be
		//				relative to this value.
		// Returns:		void
		//------------------------------------------------------------------------------
		void Reset() override;


		void SetControlMode(DRAGON_CONTROL_MODE mode);

		void SetClosedLoopParams(double kP, double kI, double kD, double kF);

		//------------------------------------------------------------------------------
		// Method:		<<destructor>>
		// Description:	clean up
		//------------------------------------------------------------------------------
		virtual ~DragonTalon() = default;


	private:
		int				m_zeroPos;						// Position when encoder was reset
		bool			m_sensorInverted;				// sensor is inverted
};



#endif /* SRC_SUBSYS_DRAGONTALON_H_ */
