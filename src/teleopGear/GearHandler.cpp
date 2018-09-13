/*
 * GearHandler.cpp
 *
 *  Created on: Jan 23, 2017
 *      Author: Team302
 */

#include "teleopGear/GearHandler.h"
#include <subsys/factories/GearFactory.h>
#include <subsys/interfaces/IGearer.h>
#include <driverInputs/OI.h>
#include <driverInputs/DragonXbox.h>
#include <SmartDashboard/SmartDashboard.h>
#include <WPILib.h>
using namespace Team302; 

void GearHandler::UseJoystickGearFunctions()
{
	//	bool openupperflap = OI::GetInstance()->GetButton(OI::OPEN_UPPER_FLAP);
	//	bool openlowerflap = OI::GetInstance()->GetButton(OI::DEPLOY_GEAR);
	IGearer* gear = GearFactory::GetInstance()->GetIGearer();
	
	bool openupperflap = DragonXbox::GetCopilot()->GetButton(DragonXbox::X_BUTTON);
	gear->OpenUpperFlaps(openupperflap);
	
	bool openlowerflap = DragonXbox::GetCopilot()->GetButton(DragonXbox::B_BUTTON);
	gear->OpenLowerFlaps(openlowerflap);

//	if (gear->IsPegPresent())
//	{
//		DragonXbox::GetDriver()->SetRumble(1.0, 1.0);
//		DragonXbox::GetCopilot()->SetRumble(1.0, 1.0);
//	}
//	else
//	{
//		DragonXbox::GetDriver()->SetRumble(0.0, 0.0);
//		DragonXbox::GetCopilot()->SetRumble(0.0, 0.0);
//	} //maybe add something to switch it off

}


