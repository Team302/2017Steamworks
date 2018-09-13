/*
 * Fuel.h
 *
 *  Created on: Feb 14, 2017
 *      Author: Team302
 */

#ifndef SRC_AUTON_FUEL_H_
#define SRC_AUTON_FUEL_H_

#include <teleopFuel/FuelManip.h>
#include <subsys/interfaces/IFuelHandler.h>
#include <auton/PrimitiveParams.h>
#include <auton/IPrimitive.h>
namespace Team302
{
class Fuel : public IPrimitive
{
public:
	void Init(PrimitiveParams*	Parms) override;
	void Run() override;
	bool IsDone() override;
	Fuel();
	virtual ~Fuel() = default;
private:
	IFuelHandler* m_fuelHandler;
	const float kIntakePower = 0.75;
	const float kLiftPower = 0.4;
	const float kLowerPower = 0.4;
	const float kShooterVolts = 8.2;	// 8.0, 10.8
	bool m_intakeFuel;
	bool m_shoot;
	float m_shooterSpeed;
	const float LOOPS = 0.02;
	float m_time;
};

} /* namespace Team302 */

#endif /* SRC_AUTON_FUEL_H_ */
