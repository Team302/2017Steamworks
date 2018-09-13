/*
 * IFuelHandler.h
 *
 *  Created on: Jan 12, 2017
 *      Author: jonah shader
 */

#ifndef SRC_SUBSYS_INTERFACES_IFUELHANDLER_H_
#define SRC_SUBSYS_INTERFACES_IFUELHANDLER_H_

namespace Team302 {

class IFuelHandler
{
public:
	//Getters
	virtual float GetIntakeSpeed() const = 0;
	virtual float GetShooterSpeed() const = 0;
	virtual float GetRange() const = 0;
	//Setters
	virtual void SetLowerConveyerPower(float power) = 0;
	virtual void SetLiftConveyerPower(float power) = 0;
	virtual void SetIntakePower(float power) = 0;
	virtual void SetShooterPower(float power) = 0;
	virtual void SetShooterVelocity(float target) = 0;


	IFuelHandler() = default;
	virtual ~IFuelHandler() = default;
};

} /* namespace Team302 */

#endif /* SRC_SUBSYS_INTERFACES_IFUELHANDLER_H_ */
