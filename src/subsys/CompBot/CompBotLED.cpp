/*
 * CompBotLED.cpp
 *
 *  Created on: Feb 19, 2017
 *      Author: Elite
 */

#include <subsys/CompBot/CompBotLED.h>
#include <subsys/interfaces/ILED.h>
#include <Relay.h>

namespace Team302 {

void CompBotLED::SetColor(ILED::COLOR color)
{
	switch (color)
	{
	case ILED::OFF:
		m_relay0->Set(Relay::kOff);
		m_relay1->Set(Relay::kOff);
		break;
	case ILED::RED:
		m_relay0->Set(Relay::kForward);
		m_relay1->Set(Relay::kOff);
		break;
	case ILED::GREEN:
		m_relay0->Set(Relay::kReverse);
		m_relay1->Set(Relay::kOff);
		break;
	case ILED::BLUE:
		m_relay0->Set(Relay::kOff);
		m_relay1->Set(Relay::kForward);
		break;
	case ILED::YELLOW:
		m_relay0->Set(Relay::kOn);
		m_relay1->Set(Relay::kOff);
		break;
	case ILED::PURPLE:
		m_relay0->Set(Relay::kForward);
		m_relay1->Set(Relay::kForward);
		break;
	case ILED::TEAL:
		m_relay0->Set(Relay::kReverse);
		m_relay1->Set(Relay::kForward);
		break;
	case ILED::WHITE:
		m_relay0->Set(Relay::kOn);
		m_relay1->Set(Relay::kForward);
		break;
	default:
		m_relay0->Set(Relay::kOff);
		m_relay1->Set(Relay::kOff);
		break;
	}

}

CompBotLED::CompBotLED() :
	m_relay0(new Relay(0)),
	m_relay1(new Relay(1))
{
}


} /* namespace Team302 */
