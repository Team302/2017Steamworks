/*
 * CompBotGearer.h
 *
 *  Created on: Jan 12, 2017
 *      Author: Tumtu
 */

#ifndef SRC_SUBSYS_COMPBOT_COMPBOTGEARER_H_
#define SRC_SUBSYS_COMPBOT_COMPBOTGEARER_H_

#include <subsys/interfaces/IGearer.h>
#include <WPILib.h>


namespace Team302 {

class CompBotGearer : public IGearer{

public:


	bool HasGear() override;
	bool IsPegPresent() override;
	bool IsUpperFlapOpen() override;
	bool IsLowerFlapOpen() override;
	void DashboardInfo();

	float GetPressure() override;

	void OpenUpperFlaps( bool OpenFlaps ) override;
	void OpenLowerFlaps( bool OpenFlaps ) override;
	void ResetFlaps() override;
	CompBotGearer();
	virtual ~CompBotGearer();

private:
	Solenoid* m_upperFlapSolenoid;
	Solenoid* m_lowerFlapSolenoid;

	AnalogInput* m_pressureGauge;

	DigitalInput* m_upperFlapSensor;
	DigitalInput* m_lowerFlapSensor;
	DigitalInput* m_gearSensor;
	DigitalInput* m_pegSensor;

	bool m_upperSensed;
	bool m_lowerSensed;

	float m_pressure;

	bool m_reset = false;
	float vOut;
};

} /* namespace Team302 */

#endif /* SRC_SUBSYS_COMPBOT_COMPGEARER_H_ */
