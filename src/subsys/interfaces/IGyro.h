/*
 * IGyro.h
 *
 *  Created on: Mar 27, 2017
 *      Author: Tumtu
 */

#ifndef SRC_SUBSYS_INTERFACES_IGYRO_H_
#define SRC_SUBSYS_INTERFACES_IGYRO_H_

namespace Team302 {

class IGyro {
public:

	virtual double GetRawAngle() = 0;
	virtual void ResetAngle() = 0;				//Software reset: effective instantly, doesn't get rid of yaw drift
	virtual void ResetGyro() = 0;				//Hardware reset: takes a couple seconds, should only be used in robot init

	IGyro() = default;
	virtual ~IGyro() = default;
};

} /* namespace Team302 */

#endif /* SRC_SUBSYS_INTERFACES_IGYRO_H_ */
