/*
 * IClimber.h
 *
 *  Created on: Jan 12, 2017
 *      Author: Tumtu
 */

#ifndef SRC_SUBSYS_INTERFACES_ICLIMBER_H_
#define SRC_SUBSYS_INTERFACES_ICLIMBER_H_

namespace Team302 {

class IClimber {
public:
	// getters
	virtual bool IsRobotLifting() = 0;
	virtual float GetRPM() = 0;
	virtual float GetRotations() = 0;
	// setters
	virtual void SetPower(float power) = 0;		// power is -1 to 1
	virtual void ResetDistance() = 0;

	IClimber() = default;
	virtual ~IClimber() = default;

	bool isLifting = false;
	const float LIFTING_CURRENT = 40;
};

} /* namespace Team302 */

#endif /* SRC_SUBSYS_INTERFACES_ICLIMBER_H_ */
