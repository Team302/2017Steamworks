/*
 * PrimitiveParser.h
 *
 *  Created on: Jan 17, 2017
 *      Author: Tyler
 */

#ifndef SRC_PRIMITIVEPARSER_H_
#define SRC_PRIMITIVEPARSER_H_

#include <fstream>
#include <string>
#include <sstream>
#include <auton/PrimitiveParams.h>
#include <iostream>
#include <vector>

namespace Team302
{

    class PrimitiveParser
    {
        public:
            static std::vector<PrimitiveParams*> Parse(std::string filename);
            PrimitiveParser() = delete;
            virtual ~PrimitiveParser() = delete;
            enum
            	{
            		ID,
            		TIME,
            		DISTANCE,
            		ANGLE,
            		DRIVESPEED,
            		GEAR,
            		SHOOTERSPEED,
            		SHOOT,
            		INTAKE,
            	};
        private:

    };

} /* namespace Team302 */

#endif /* SRC_PRIMITIVEPARSER_H_ */
