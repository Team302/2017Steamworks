/*
  * ILED.h
 *
 *  Created on: Feb 19, 2017
 *      Author: Elite
 */

#ifndef SRC_SUBSYS_INTERFACES_ILED_H_
#define SRC_SUBSYS_INTERFACES_ILED_H_

namespace Team302 {

class ILED{
public:

	enum COLOR
	{
		OFF,
		RED,
		GREEN,
		BLUE,
		YELLOW,
		PURPLE,
		TEAL,
		WHITE
	};

	virtual void SetColor(COLOR color) = 0;
	ILED() = default;
	virtual ~ILED() = default;

private:


};

} /* namespace Team302 */

#endif /* SRC_SUBSYS_INTERFACES_ILED_H_ */
