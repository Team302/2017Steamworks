/*
 * CompBotLED.h
 *
 *  Created on: Feb 19, 2017
 *      Author: Elite
 */

#ifndef SRC_SUBSYS_COMPBOT_COMPBOTLED_H_
#define SRC_SUBSYS_COMPBOT_COMPBOTLED_H_

#include <subsys/interfaces/ILED.h>
#include <Relay.h>

namespace Team302 {

class CompBotLED : public ILED
{
public:
	void SetColor(ILED::COLOR color);

	CompBotLED();
	virtual ~CompBotLED() = default;

private:
	Relay* m_relay0; //first relay for controlling LEDs
	Relay* m_relay1; //second relay for controlling LEDs

};

} /* namespace Team302 */

#endif /* SRC_SUBSYS_COMPBOT_COMPBOTLED_H_ */
