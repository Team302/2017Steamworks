/*
 * IPrimitive.h
 *
 *  Created on: Jan 12, 2017
 *      Author: The Realest of Authors
 */
/*I PLAY POKEMON GO EVERYDAY*/

#ifndef SRC_AUTON_IPRIMITIVE_H_
#define SRC_AUTON_IPRIMITIVE_H_

#include <auton/PrimitiveParams.h>

namespace Team302 {

class IPrimitive
{
public:
	const float LOOP_LENGTH = 0.020; //20 ms
	/*This literally is the same as the chassis, but IPrimitive. It also
	 * has Init, Run, and isDone*/
	IPrimitive() = default;
	virtual ~IPrimitive() = default;
	virtual void Init(PrimitiveParams*	Parms) = 0;
	virtual void Run() = 0;
	virtual bool IsDone() = 0;

};
} /* namespace Team302 */

#endif /* SRC_IPrimitive_H_ */
