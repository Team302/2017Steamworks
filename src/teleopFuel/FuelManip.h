/*

 * FuelManip.h
 *
 *  Created on: Jan 14, 2017
 *      Author: Elite
 */

#ifndef SRC_FUELMANIP_H_
#define SRC_FUELMANIP_H_

#include <subsys/interfaces/IFuelHandler.h>
#include <driverInputs/OI.h>

namespace Team302 {

class FuelManip{
public:
	void Run();
	void ActivateIntake();
	void StopIntake();
	void ActivateLoad();
	void StopLoad();
	void ActivateShooter();
	void StopShooter();
	void SetShooterPosition();

	FuelManip();
	virtual ~FuelManip();

private:
	OI* 			m_OI;
	IFuelHandler*   m_fuelHandler;
	int				m_numLoopsShooterRunning;

	const float SHOOTER_ADJUST_SCALE = 1.0;
	const float INTAKE_POWER = 0.75; //const for intake motor power
	const float LOWER_CONVEYOR_POWER = 0.5; //const for lower conveyer motor power--------------------.8
	const float LIFT_CONVEYOR_POWER = 1; //const for lift conveyer motor power //.55-------------------------.9
//	const float SHOOTER_VOLTAGE = 6.5; //const for shoot motor speed. Will probably change to PID or something.
//	const float SHOOTER_VOLTAGE = 7.5; //const for shoot motor speed. Will probably change to PID or something.
//	const float SHOOTER_VOLTAGE = 7.75;
	const float SHOOTER_VOLTAGE = 7.5;// 7.8, 7.25, 8.3-----------------------------------7.8
	const float SHOOTER_RPM = 9500; //const for shoot motor speed in RPM with PID control TODO: Was 10500
//	const float SHOOTER_RPM = 11000;//13000
	const int   NUM_LOOPS_BEFORE_CONVEYOR = 20;
	float loops = 0;

	float intervalTimer;

	const float LOOP_LENGTH = 0.020; //20 ms
	const float CONVEYOR_PAUSE_INTERVAL = 1.0; //Time on
	const float CONVEYOR_PAUSE_TIME = 0.25; //Time off
};

} /* namespace Team302 */

#endif /* SRC_FUELMANIP_H_ */
