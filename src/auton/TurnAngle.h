/*
 * TurnAngle.h
 *
 *  Created on: Mar 11, 2017
 *      Author: Elite
 */

#ifndef SRC_AUTON_TURNANGLE_H_
#define SRC_AUTON_TURNANGLE_H_

#include <subsys/interfaces/IChassis.h>
#include <auton/IPrimitive.h>
#include <subsys/interfaces/IChassis.h>
#include <subsys/interfaces/IGyro.h>
#include <subsys/factories/GyroFactory.h>

namespace Team302 {

class TurnAngle : public IPrimitive
{
public:
    TurnAngle();
    virtual ~TurnAngle();

    void Init(PrimitiveParams*  Parms) override;
    void Run() override;
    bool IsDone() override;


private:
    IGyro* m_gyro;
    IChassis* m_chassis;
    float m_targetAngle;
    float m_targetSpeed;
    float m_leftSpeed;
    float m_rightSpeed;
    float m_speedMultiplier;

    const float ANGLE_THRESH = 0.5; // +/- threshold for being at angle
    const float	MINIMUM_SPEED = 0.5; //feet per second

    const float kP = 2.0;
    const float kI = 0.0;
    const float kD = 0.0;
    const float kF = 0.0;

    const float CORRECTION = 1.5;
};

} /* namespace Team302 */

#endif /* SRC_AUTON_TURNANGLE_H_ */
