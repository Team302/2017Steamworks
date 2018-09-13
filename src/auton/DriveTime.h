/*
 * DriveTime.h
 *
 *  Created on: Jan 18, 2017
 *      Author: Owen
 *not even my final form -frieza 2017
 */

#ifndef DRIVETIME_H_
#define DRIVETIME_H_
#include <auton/IPrimitive.h>
#include <subsys/interfaces/IChassis.h>
#include <auton/SuperDrive.h>

namespace Team302
{
    class DriveTime : public SuperDrive
    {
    public:
        DriveTime();
        virtual ~DriveTime() = default;
        void Init(PrimitiveParams*  Parms) override;
        bool IsDone() override;

    private:
        float m_timeRemaining;          //In seconds

    };
} /* namespace Team302 */


#endif /* DONOTHING_H_ */
