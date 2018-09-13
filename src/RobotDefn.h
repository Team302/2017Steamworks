/*
 * RobotDefn.h
 *
 *  Created on: Jan 12, 2017
 *      Author: Tumtu
 */

#ifndef SRC_ROBOTDEFN_H_
#define SRC_ROBOTDEFN_H_

namespace Team302 {

    // These are all of the robots that can be deployed to
    const int COMP_BOT = 302;
    const int SOFTWARE_BOT = 2017;
    const int EIGHTY_BOT = 2020;


// Uncomment the line below to select the robot that the software is being deployed to
// Then the ROBOT_CONFIGURATION will be set correctly (so the factories create the correct
// targets

//#define RUN_SOFTWARE_BOT
//#define RUN_YEAR1_BOT // ignore
#define RUN_COMP_BOT
//#define RUN_EIGHTY_BOT


#ifdef RUN_SOFTWARE_BOT
    const int ROBOT_CONFIGURATION           = SOFTWARE_BOT;
#else
    #ifdef RUN_COMP_BOT
        const int ROBOT_CONFIGURATION       = COMP_BOT;
    #else
        #ifdef RUN_EIGHTY_BOT
            const int ROBOT_CONFIGURATION   = EIGHTY_BOT;
        #endif
    #endif
#endif

} /* namespace Team302 */

#endif /* SRC_ROBOTDEFN_H_ */
