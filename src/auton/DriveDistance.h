/*
 * DriveDistance.h
 *
 *  Created on: Jan 18, 2017
 *      Author: Jonah GLSL Shader
 */

#ifndef SRC_AUTON_PRIMITIVES_DRIVEDISTANCE_H_
#define SRC_AUTON_PRIMITIVES_DRIVEDISTANCE_H_

#include <auton/IPrimitive.h>
#include <auton/PrimitiveParams.h>
#include <subsys/factories/ChassisFactory.h>
#include <subsys/interfaces/IChassis.h>
#include <auton/SuperDrive.h>

namespace Team302
{

class DriveDistance : public SuperDrive
{

public:
    bool IsDone() override;
    void Init(PrimitiveParams* params) override;
    DriveDistance();
    virtual ~DriveDistance() = default;

private:
//    const float PROPORTIONAL_COEFF  = 0.5;
//    const float INTREGRAL_COEFF     = 0.0;
//    const float DERIVATIVE_COEFF    = 0.0;
//    const float FEET_FORWARD_COEFF  = 0.0;
    const float COMPENSATE_SCALE    = 9.5;

    const float DEFAULT_TIME_REMAINING = 4; //in seconds

//    const float CORRECTION_CONSTANT = 1;

    IChassis* m_chassis;      //Robot chassis
    float m_targetDistance;   //the distance the robot will travel  NOTE: relative distance, not actual distance
    float m_timeRemaining;
//    float m_startSpeed;
//
//    float m_targetAngle;
//
//    const float RIGHT_TURN = .2;
//    const float LEFT_TURN = -.2;

    int initCounts = 0;
    int constructCounts = 0;

};

} /* namespace Team302 */

#endif /* SRC_AUTON_PRIMITIVES_DRIVEDISTANCE_H_ */
