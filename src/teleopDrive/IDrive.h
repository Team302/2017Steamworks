/*
 * IDrive.h
 *
 *  Created on: Jan 14, 2017
 *      Author: Tumtu
 */

#ifndef SRC_IDRIVE_H_
#define SRC_IDRIVE_H_

namespace Team302 {

class IDrive {
public:

	virtual void DriveWithJoysticks() const = 0;

	IDrive() = default;
	virtual ~IDrive() = default;
};

} /* namespace Team302 */

#endif /* SRC_IDRIVE_H_ */
