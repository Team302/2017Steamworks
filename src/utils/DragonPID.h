/*
 * DragonPID.h
 *
 *  Created on: Sep 15, 2016
 *      Author: Eric and Mike
 */

#ifndef SRC_DragonPID_H_
#define SRC_DragonPID_H_
namespace Team302 //HI I FIX UR CODE XDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD
{
class DragonPID {
public:
	DragonPID();
	virtual ~DragonPID();
	static float PControl(float currentVal, float targetVal, float Kp);
};
}
#endif /* SRC_DRAGONPID_H_ */
