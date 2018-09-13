/*
 * DragonPID.cpp
 *
 *  Created on: Sep 15, 2016
 *      Author: Eric and Mike
 */
#include <utils/DragonPID.h>
namespace Team302{
DragonPID::DragonPID(){}
DragonPID::~DragonPID(){}
/**
*This function is used as a pid controller, but only with a p term, so it's just a p controller.
*
*@param targetValue
*@param currentValue
*@param kP
*@return output
*/
float DragonPID::PControl(float currentVal, float targetVal, float Kp)
{
	float output = 0.0;
	float error = 0.0;

	error = targetVal - currentVal;
	output = error * Kp;

	return output;
}

}
