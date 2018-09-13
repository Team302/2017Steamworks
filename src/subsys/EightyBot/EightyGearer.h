/*
 * EightyGearer.h
 *
 *  Created on: Feb 5, 2017
 *      Author: Tumtu
 */

#ifndef SRC_SUBSYS_EIGHTYBOT_EIGHTYGEARER_H_
#define SRC_SUBSYS_EIGHTYBOT_EIGHTYGEARER_H_

#include <subsys/interfaces/IGearer.h>
#include <WPILib.h>


namespace Team302 {

class EightyGearer : public IGearer{

public:


	bool HasGear() override;
	bool IsPegPresent() override;
	bool IsUpperFlapOpen() override;
	bool IsLowerFlapOpen() override;
	float GetPressure() override;

	void OpenUpperFlaps( bool OpenFlaps ) override;
	void OpenLowerFlaps( bool OpenFlaps ) override;
	void ResetFlaps() override;
	EightyGearer();
	virtual ~EightyGearer();

private:
	Solenoid* m_upperFlapSolenoid;
	Solenoid* m_lowerFlapSolenoid;

	AnalogInput* m_pressureGauge;

	DigitalInput* m_upperFlapSensor;
	DigitalInput* m_lowerFlapSensor;
	DigitalInput* m_gearSensor;
	DigitalInput* m_pegSensor;

	bool m_reset = false;

	float m_pressure;

	float vOut;
};

} /* namespace Team302 */

#endif /* SRC_SUBSYS_EightyBOT_EIGHTYGEARER_H_ */
