/*
 * ArcadeDrive.h
 *
 *  Created on: Jan 14, 2017
 *      Author: Tumtu
 */

#ifndef SRC_ARCADEDRIVE_H_
#define SRC_ARCADEDRIVE_H_

#include <teleopDrive/IDrive.h>
#include <subsys/interfaces/IChassis.h>
#include <driverInputs/OI.h>
namespace Team302
{

	class IChassis;
	class OI;

	class ArcadeDrive: public IDrive
	{
		public:

			ArcadeDrive();      // constructor

			void DriveWithJoysticks() const override;
			virtual ~ArcadeDrive(); // destructor

		protected:

		private:
			// Attributes
			IChassis*               m_chassis;
			OI*      m_oi;

			const float NUDGE_AMOUNT = 10;

			// Default methods we don't want the compiler to implement
			ArcadeDrive( const ArcadeDrive& ) = delete;
			ArcadeDrive& operator= ( const ArcadeDrive& ) = delete;
			explicit ArcadeDrive( ArcadeDrive* other ) = delete;

	};

}

/* namespace Team302 */

#endif /* SRC_ARCADEDRIVE_H_ */
