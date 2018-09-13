/*
 * GearHandler.h
 *
 *  Created on: Jan 23, 2017
 *      Author: Team302
 */

#ifndef GEARHANDLER_H_
#define GEARHANDLER_H_
#include <subsys/interfaces/IGearer.h>
#include <subsys/factories/GearFactory.h>
#include <WPILib.h>
#include <driverInputs/OI.h>
namespace Team302{
class GearHandler
{
public:

	GearHandler() = default;
	virtual ~GearHandler() = default;
	void UseJoystickGearFunctions();

private:


	GearHandler( const GearHandler& ) = delete;
	GearHandler& operator= (const GearHandler& ) = delete;
	explicit GearHandler( GearHandler* other ) = delete;



};
}

#endif /* GEARHANDLER_H_ */
