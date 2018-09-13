/*
 * CompBotGyro.h
 *
 *  Created on: Mar 27, 2017
 *      Author: Tumtu
 */

#ifndef SRC_SUBSYS_COMPBOT_COMPBOTGYRO_H_
#define SRC_SUBSYS_COMPBOT_COMPBOTGYRO_H_

#include <subsys/interfaces/IGyro.h>
#include <AnalogGyro.h>
#include <WPILib.h>

namespace Team302 {

class CompBotGyro : public IGyro
{
public:

	double GetRawAngle() override;
	void ResetGyro() override;
	void ResetAngle() override;

	CompBotGyro();
	virtual ~CompBotGyro() = default;

private:
	 AnalogGyro* m_gyro;
	 double resetAngle;
};

} /* namespace Team302 */

#endif /* SRC_SUBSYS_COMPBOT_COMPBOTGYRO_H_ */
