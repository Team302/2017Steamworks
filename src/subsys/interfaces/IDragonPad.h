/*
 * IDragonPad.h
 *
 *  Created on: Jan 25, 2017
 *      Author: Elite
 */

#ifndef SRC_DRIVERINPUTS_IDRAGONPAD_H_
#define SRC_DRIVERINPUTS_IDRAGONPAD_H_

namespace Team302 {

enum AXIS_IDENTIFIER
{
	X_AXIS,
	Y_AXIS,
	Z_AXIS,
    X_AXIS_LEFT_JOYSTICK,
    Y_AXIS_LEFT_JOYSTICK,
    LEFT_TRIGGER,
    RIGHT_TRIGGER,
    X_AXIS_RIGHT_JOYSTICK,
    Y_AXIS_RIGHT_JOYSTICK,
	NULL_AXIS
};

enum BUTTON_IDENTIFIER
{
    A_BUTTON,
    B_BUTTON,
    X_BUTTON,
    Y_BUTTON,
    LEFT_BUMPER,
    RIGHT_BUMPER,
    BACK_BUTTON,
    START_BUTTON,
    PRESS_LEFT_STICK,
    PRESS_RIGHT_STICK,
    LEFT_TRIGGER_PRESSED,
    RIGHT_TRIGGER_PRESSED,
    POV_0_PRESSED,
    POV_45_PRESSED,
    POV_90_PRESSED,
    POV_135_PRESSED,
    POV_180_PRESSED,
    POV_225_PRESSED,
    POV_270_PRESSED,
    POV_315_PRESSED,
	NULL_BUTTON
};

enum CURVE //enum for selecting linear or cubic axis profile
{
	LINEAR,
	CUBIC
};

enum BUTTON_STATE
{
    BUTTON_NOT_PRESSED, // previous check the button wasn't pressed and it still isn't
    BUTTON_PRESSED,     // previous check the button wasn't pressed and now it is
    BUTTON_HELD,        // previous check the button was pressed and it still is
    BUTTON_RELEASED     // previous check the button was pressed and now it isn't
};

class IDragonPad {
public:

	//getters
	virtual double GetAxis(AXIS_IDENTIFIER axis) const = 0;
	virtual bool GetButton(BUTTON_IDENTIFIER button) const = 0;
	//setters
	virtual void SetCurve(AXIS_IDENTIFIER axis, CURVE curve) = 0;
	virtual void SetScale(AXIS_IDENTIFIER axis, float scaleFactor) = 0;

	IDragonPad() = default;
	virtual ~IDragonPad() = default;
};

} /* namespace Team302 */

#endif /* SRC_DRIVERINPUTS_IDRAGONPAD_H_ */
