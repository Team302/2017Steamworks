/*
 * CompBotChassis.h
 *
 *  Created on: Jan 16, 2017
 *      Author: Tumtu/Neethan Punniyamoorthy
 */

#ifndef SRC_SUBSYS_COMPBOT_COMPBOTCHASSIS_H_
#define SRC_SUBSYS_COMPBOT_COMPBOTCHASSIS_H_

#include <utils/DragonTalon.h>
#include <subsys/interfaces/IChassis.h>


namespace Team302 {

class CompBotChassis: public IChassis
{
	// Drive Motors
	DragonTalon*	m_leftSlaveMotor;
	DragonTalon*	m_rightSlaveMotor;
	DragonTalon*	m_leftMasterMotor;
	DragonTalon*	m_rightMasterMotor;

public:
	//Getters
	float GetLeftVelocity() const override;
	float GetRightVelocity() const override;
	float GetLeftDistance()const override;
	float GetRightDistance() const override;

	float GetRightFrontDistance() const override;
	float GetRightBackDistance() const override;
	float GetLeftBackDistance() const override;
	float GetLeftFrontDistance() const override;

	float GetLeftBackVelocity() const override;
	float GetLeftFrontVelocity() const override;
	float GetRightBackVelocity() const override;
	float GetRightFrontVelocity() const override;

	//Setters
	void SetLeftPower(float power) override;//power from -1 to 1
	void SetRightPower(float power) override;//power from -1 to 1
	void SetBrakeMode(bool mode) override;
	void ResetDistance() override;
	void SetControlMode(DragonTalon::DRAGON_CONTROL_MODE mode) override;
	void SetPositionParams(double kP, double kI, double kD, double kF, double leftTarget, double rightTarget) override;
	void SetVelocityParams(double kP, double kI, double kD, double kF, double leftTarget, double rightTarget) override;
	void EnableCurrentLimiting() override;
	void DisableCurrentLimiting() override;
	void SetCurrentLimit(int amps) override;

	CompBotChassis();				//constructor
	virtual ~CompBotChassis() = default;		//destructor


private:

   int TALON_CURRENT_LIMIT = 50;
};

} /* namespace Team302 */

#endif /* SRC_SUBSYS_COMPBOT_COMPBOTCHASSIS_H_ */
