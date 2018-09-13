/*
 * SWBotGearer.h
 *
 *  Created on: Jan 12, 2017
 *      Author: Tumtu
 */

#ifndef SRC_SUBSYS_SWBOT_SWBOTGEARER_H_
#define SRC_SUBSYS_SWBOT_SWBOTGEARER_H_

#include <subsys/interfaces/IGearer.h>
#include <WPILib.h>


namespace Team302 {

class SWBotGearer : public IGearer{

public:


	bool HasGear() override;
	bool IsPegPresent() override;
	bool IsUpperFlapOpen() override;
	bool IsLowerFlapOpen() override;
	float GetPressure() override;

	void OpenUpperFlaps( bool OpenFlaps ) override;
	void OpenLowerFlaps( bool OpenFlaps ) override;
	void ResetFlaps() override;

	SWBotGearer();
	virtual ~SWBotGearer();

private:
	Solenoid* m_upperFlapSolenoid;
	Solenoid* m_lowerFlapSolenoid;

	AnalogInput* m_pressureGauge;

	DigitalInput* m_upperFlapSensor;
	DigitalInput* m_lowerFlapSensor;
	DigitalInput* m_gearSensor;
	DigitalInput* m_pegSensor;

	float m_pressure;
	float vOut;
};

} /* namespace Team302 */

#endif /* SRC_SUBSYS_SWBOT_SWBOTGEARER_H_ */
