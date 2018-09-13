/*

 * CompBotFuelHandler.h
 *
 *  Created on: Jan 12, 2017
 *      Author: jonah shader
 */

#include <utils/DragonTalon.h>
#include <subsys/interfaces/IFuelHandler.h>

#ifndef SRC_COMPBOTFUELHANDLER_H_
#define SRC_COMPBOTFUELHANDLER_H_

using namespace frc;
namespace Team302 {

class CompBotFuelHandler : public IFuelHandler
{
public:
	//getters

	//----------------------------------------------------------------------------------
	// Method:      GetShooterSpeed
	// Description: Gets speed in RPM of shooter wheels
	// Returns:		float speed
	//----------------------------------------------------------------------------------
	float GetShooterSpeed() const override;

	//----------------------------------------------------------------------------------
	// Method:      GetIntakeSpeed
	// Description: Gets speed in RPM of intake
	// Returns:		float speed
	//----------------------------------------------------------------------------------
	float GetIntakeSpeed() const override;

	//----------------------------------------------------------------------------------
	// Method:      GetRange
	// Description: Gets rangefinder distance in inches
	// Returns:		float range
	//----------------------------------------------------------------------------------
	float GetRange() const override;

	//Setters
	//----------------------------------------------------------------------------------
	// Method:      SetLoweroConveyer
	// Description: Sets speed of lower conveyer belt from -1.0 to 1.0
	// Params:		float power
	//----------------------------------------------------------------------------------
	void SetLowerConveyerPower(float power) override;

	//---------------------------------------------------------------------------------
	// Method:      SetLiftConveyor
	// Description: Sets power from -1.0 to 1.0 for the lift conveyer belt
	// Params:		float power
	//----------------------------------------------------------------------------------
	void SetLiftConveyerPower(float power) override;

	//----------------------------------------------------------------------------------
	// Method:      SetIntakePower
	// Description: Sets power of intake motor. -1.0 to 1.0
	// Params:		float power
	//----------------------------------------------------------------------------------
	void SetIntakePower(float power) override;

	//----------------------------------------------------------------------------------
	// Method:      SetShooterPower
	// Description: Sets power to shooter motor. -1.0 to 1.0
	// Params:		float power
	//----------------------------------------------------------------------------------
	void SetShooterPower(float power) override;

	//----------------------------------------------------------------------------------
	// Method:      SetShooterVelocity
	// Description: Sets target velocity to shooter motor, will use PID control on talon
	// Params:		float target
	//----------------------------------------------------------------------------------
	void SetShooterVelocity(float power) override;

	CompBotFuelHandler();
	~CompBotFuelHandler() override;

private:
	DragonTalon* m_intakeMotor; //ball intake motor
	DragonTalon* m_lowerConveyerMotor; // lower conveyer motor
	DragonTalon* m_liftConveyerMotor; //lift conveyer motor
	DragonTalon* m_masterShooterMotor; //master shooter motor
	DragonTalon* m_slaveShooterMotor; //slave shooter motor

	double kP = 0.008; //0.016
	double kI = 0.00001;//0.000050
	double kD = 0.0;
	double kF = 0.0000;//0.0060
//	double kP = 0.016;
//	double kI = 0.000015;
//	double kD = 0.001;
//	double kF = 0.0072;

};

} /* namespace Team302 */

#endif /* SRC_COMPBOTFUELHANDLER_H_ */
