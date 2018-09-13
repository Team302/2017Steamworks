/*
 * EightyGyro.h
 *
 *  Created on: Mar 27, 2017
 *      Author: Tumtu
 */

#ifndef SRC_SUBSYS_EIGHTYBOT_EIGHTYGYRO_H_
#define SRC_SUBSYS_EIGHTYBOT_EIGHTYGYRO_H_

#include <subsys/interfaces/IGyro.h>
#include <AnalogGyro.h>
#include <WPILib.h>

namespace Team302 {

class EightyGyro : public IGyro
{
public:

	double GetRawAngle() override;
	void ResetAngle() override;
	void ResetGyro() override;

	EightyGyro();
	virtual ~EightyGyro() = default;

private:
	AnalogGyro* m_gyro;
};

} /* namespace Team302 */

#endif /* SRC_SUBSYS_EIGHTYBOT_EIGHTYGYRO_H_ */
