/*
 * PrimitiveParser.cpp
 *
 *  Created on: Jan 17, 2017
 *      Author: Tyler
 */
#include <auton/PrimitiveParser.h>
#include <auton/PrimitiveParams.h>
#include <auton/AutonSelector.h>
#include <SmartDashboard/SmartDashboard.h>
#include <stdio.h>
#include <stdlib.h>

namespace Team302
{

std::vector<PrimitiveParams*> PrimitiveParser::Parse
(
		std::string filename       //Passing the filename
)
{
	std::vector<PrimitiveParams*> paramVector;

	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;


	std::string dir = "/home/lvuser/auton/";
	std::string test = dir + filename;
	char *converted = new char[test.length() + 1];
	std::strcpy(converted, test.c_str());
//	delete[] directoryChar;
//  TODO: need to delete, currently leaking memory

	stream = fopen(converted, "r"); //TODO: the code works right now, but i don't know what "r" does and i can't remove it lol
	if (stream == NULL)
	{
		//error lel
	}

	while ((read = getline(&line, &len, stream)) != -1)
	{
		int id = 0;
		float time = 0;
		float distance = 0;
		float angle = 0;
		float driveSpeed = 0;
		bool deployGear = false;
		bool shoot = false;
		float shooterSpeed = 0.0;
		bool intakeFuel = false;

		std::stringstream lineStream(line);           //create a stream for each line
		std::string token;                            //create a string for each value
		int tokenNum = 0;
		while (std::getline(lineStream, token, ',')) //Parse the line at every comma
		{
			std::string::size_type size;
			float val = std::stof(token, &size);    //convert to float

			switch(tokenNum)                     //determines which character we are at in the string
			{
			case ID:
				id = std::stoi(token, &size);
				break;

			case TIME:
				time = val;
				break;

			case DISTANCE:
				distance = val;
				break;

			case ANGLE:
				angle = val;
				break;

			case DRIVESPEED:
				driveSpeed = val;
				break;

			case GEAR:
				deployGear = ( val > 0.5 );
				break;

			case SHOOTERSPEED:
				shooterSpeed=val;
				break;

			case SHOOT:
				shoot= ( val > 0.5 );
				break;

			case INTAKE:
				intakeFuel= ( val > 0.5);
				break;

			default:
				break;
			}
			tokenNum++;
		}

		paramVector.emplace_back( new PrimitiveParams(id, time, distance, angle, driveSpeed, deployGear, shooterSpeed, shoot, intakeFuel)); //create a primitives vector for primitiveparams class
	}

	free(line);
	fclose(stream);
	return paramVector;
}


} /* namespace Team302 */
