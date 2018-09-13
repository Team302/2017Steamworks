/*
 * SWBotFuelHandler.h
 *
 *  Created on: Jan 16, 2017
 *      Author: Neethan Punniyamoorthy
 */

#include <utils/DragonTalon.h>
#include <subsys/interfaces/IFuelHandler.h>

#ifndef SRC_SWBOTFUELHANDLER_H_
#define SRC_SWBOTFUELHANDLER_H_

using namespace frc;
namespace Team302 {

class SWBotFuelHandler : public IFuelHandler
{
public:

	//Getters
	float GetIntakeSpeed () const override;
	float GetShooterSpeed() const override;
	float GetRange() const override;
	//Setters
	void SetLowerConveyerPower(float power) override;		// JW - added
	void SetLiftConveyerPower(float power) override;			// JW - added
	void SetIntakePower(float power) override;
	void SetShooterPower(float power) override;
	void SetShooterVelocity(float target) override;		// JW - added

	SWBotFuelHandler();
	virtual ~SWBotFuelHandler();

private:

	// Shooter
	DragonTalon* m_shooterMotor;
	// Intake
	DragonTalon* m_intakeMotor;
	//lower conveyer
	DragonTalon* m_lowerConveyerMotor;
	//lift conveyer
	DragonTalon* m_liftConveyerMotor;

	double kP = 0.5;
	double kI = 0.0;
	double kD = 0.0;
	double kF = 0.0;
};

} /* namespace Team302 */

#endif /* SRC_SWBOTFUELHANDLER_H_ */
