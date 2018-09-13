/*
 * IGearer.h
 *
 *  Created on: Jan 12, 2017
 *      Author: Tumtu
 */

#ifndef SRC_SUBSYS_INTERFACES_IGEARER_H_
#define SRC_SUBSYS_INTERFACES_IGEARER_H_

namespace Team302 {

class IGearer {
public:

	virtual bool HasGear() = 0;
	virtual bool IsPegPresent() = 0;
	virtual bool IsUpperFlapOpen() = 0;
	virtual bool IsLowerFlapOpen() = 0;

	virtual float GetPressure() = 0;

	virtual void OpenUpperFlaps(bool OpenFlaps ) = 0;
	virtual void OpenLowerFlaps(bool OpenFlaps ) = 0;
	virtual void ResetFlaps () = 0;
	IGearer() = default;
	virtual ~IGearer() = default;

	bool flapOutput = false;
};

} /* namespace Team302 */

#endif /* SRC_SUBSYS_INTERFACES_IGEARER_H_ */
