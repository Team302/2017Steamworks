/*
 * PrimitiveFactory.h
 *
 *  Created on: Jan 19, 2017
 *      Author: Tyler
 */

#ifndef SRC_PRIMITIVEFACTORY_H_
#define SRC_PRIMITIVEFACTORY_H_

#include <auton/IPrimitive.h>
#include <auton/PrimitiveParams.h>
#include <auton/PrimitiveParser.h>

namespace Team302 {

class PrimitiveFactory {
public:
    PrimitiveFactory();
    virtual ~PrimitiveFactory();
    static PrimitiveFactory* GetInstance();
    IPrimitive* GetIPrimitive(PrimitiveParams* primitivePasser);

    //------------------------------------------------------------------------------
    // Method:          GetGearPrim
    // Description:     Get the gear primitive
    // Returns:         Gear Primitive
    //------------------------------------------------------------------------------
    IPrimitive* GetGearPrim();

    //------------------------------------------------------------------------------
    // Method:          GetFuelPrim
    // Description:     Get the fuel primitive
    // Returns:         fuel Primitive
    //------------------------------------------------------------------------------
    IPrimitive* GetFuelPrim();
    enum
    {
        DO_NOTHING,			//0
        DRIVE_TIME,			//1
        DRIVE_DISTANCE,		//2
        TURN_ANGLE,			//3
        HOLD_POSITION,		//4
        GEAR,				//5
        FUEL,				//6
        DRIVE_PEG,			//7
        MAX_PRIMITIVES		//8 (dont use)
    };

private:
    static PrimitiveFactory* m_instance;
    IPrimitive* m_doNothing;
    IPrimitive* m_driveTime;
    IPrimitive* m_driveDistance;
    IPrimitive* m_turnAngle;
    IPrimitive* m_holdPosition;
    IPrimitive* m_gear;
    IPrimitive* m_fuel;
    IPrimitive* m_peg;
};

} /* namespace Team302 */

#endif /* SRC_PRIMITIVEFACTORY_H_ */
