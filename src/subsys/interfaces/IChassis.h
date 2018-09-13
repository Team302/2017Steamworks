/*
 * IChassis.h
 *
 *  Created on: Jan 12, 2017
 *      Author: jonah shader
 */

#ifndef SRC_SUBSYS_INTERFACES_ICHASSIS_H_
#define SRC_SUBSYS_INTERFACES_ICHASSIS_H_

#include <utils/DragonTalon.h>

namespace Team302 {

class IChassis
{
public:
//	enum ChassisMotorMode {a, b};
//	virtual void setMotorMode(ChassisMotorMode) = 0;
	//Getters
	virtual float GetLeftVelocity() const = 0;
	virtual float GetRightVelocity() const = 0;
	virtual float GetLeftDistance() const = 0;
	virtual float GetRightDistance() const = 0;

	virtual float GetRightFrontDistance() const = 0;
	virtual float GetRightBackDistance() const = 0;
	virtual float GetLeftFrontDistance() const = 0;
	virtual float GetLeftBackDistance() const = 0;

	virtual float GetRightFrontVelocity() const = 0;
	virtual float GetRightBackVelocity() const = 0;
	virtual float GetLeftFrontVelocity() const = 0;
	virtual float GetLeftBackVelocity() const = 0;

	//Setters
	virtual void SetLeftPower(float power) = 0;//power from -1 to 1
	virtual void SetRightPower(float power) = 0;//power from -1 to 1
	virtual void SetBrakeMode(bool mode) = 0;
	virtual void EnableCurrentLimiting() = 0;
	virtual void DisableCurrentLimiting() = 0;
	virtual void SetCurrentLimit(int amps) = 0;
	virtual void ResetDistance() = 0;
	virtual void SetControlMode(DragonTalon::DRAGON_CONTROL_MODE mode) = 0;
	virtual void SetPositionParams(double kP, double kI, double kD, double kF, double leftTarget, double rightTarget) = 0;
	virtual void SetVelocityParams(double kP, double kI, double kD, double kF, double leftTarget, double rightTarget) = 0;

	IChassis() = default;
	virtual ~IChassis() = default;
};

} /* namespace Team302 */

#endif /* SRC_SUBSYS_INTERFACES_ICHASSIS_H_ */
