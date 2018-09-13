/*
 * TankDrive.h
 *
 *  Created on: Jan 14, 2017
 *      Author: Tumtu
 */

#ifndef SRC_TANKDRIVE_H_
#define SRC_TANKDRIVE_H_

#include <teleopDrive/IDrive.h>
#include <driverInputs/OI.h>
#include <subsys/interfaces/IChassis.h>

namespace Team302
{
	class IChassis;
	class OI;

	class TankDrive : public IDrive
	{
		public:

			void DriveWithJoysticks() const override;
			TankDrive();
			virtual ~TankDrive();

		private:
			//Atributes

			IChassis*	m_chassis;
			OI*			m_oi;
	};

} /* namespace Team302 */

#endif /* SRC_TANKDRIVE_H_ */
