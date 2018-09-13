/*
 * SWMap.h
 *
 *  Created on: Jan 14, 2017
 *      Author: Team302
 */

#ifndef SRC_SUBSYS_SWBOT_SWMAP_H_
#define SRC_SUBSYS_SWBOT_SWMAP_H_

	//============================================================================
	// CAN PORTS
	//============================================================================
	const int LEFT_FRONT_DRIVE_MOTOR			= 16;//gg ezNONONONONONO bad
	const int LEFT_BACK_DRIVE_MOTOR				= 2;
	const int RIGHT_BACK_DRIVE_MOTOR			= 1;
	const int RIGHT_FRONT_DRIVE_MOTOR			= 46;
	const int CLIMB_MOTOR						= 11;
	const int INTAKE_MOTOR						= 12;
	const int LOWER_CONVEYER_MOTOR				= 22;
	const int LIFT_CONVEYER_MOTOR				= 33;
	const int SHOOTER_MOTOR						= 44; //TODO FIX THE THINGS
	//============================================================================
	// TALON Motor- inversion settings
	//============================================================================
	//Right side of the robot is inverted so that the motors all go the same way
	const bool IS_LEFT_FRONT_DRIVE_MOTOR_INVERTED	   	    = false;
	const bool IS_LEFT_BACK_DRIVE_MOTOR_INVERTED		    = false;
	const bool IS_RIGHT_FRONT_DRIVE_MOTOR_INVERTED			= true;
	const bool IS_RIGHT_BACK_DRIVE_MOTOR_INVERTED		    = true;

	const bool IS_CLIMB_MOTOR_INVERTED          = false;
	const bool IS_INTAKE_MOTOR_INVERTED      = false;
	const bool IS_LOWER_CONVEYER_MOTOR_INVERTED = false;
	const bool IS_LIFT_CONVEYER_MOTOR_INVERTED	  = false;
	const bool IS_SHOOTER_MOTOR_INVERTED = false;

	//============================================================================
	// ENCODER - sensor inversion settings
	//============================================================================
	const bool IS_LEFT_FRONT_DRIVE_ENCODER_INVERTED	   	    = true;
	const bool IS_LEFT_BACK_DRIVE_ENCODER_INVERTED		    = true;
	const bool IS_RIGHT_FRONT_DRIVE_ENCODER_INVERTED		= true;
	const bool IS_RIGHT_BACK_DRIVE_ENCODER_INVERTED		    = true;

	const bool IS_SHOOTER_ENCODER_INVERTED					= false;
	const bool IS_CLIMB_ENCODER_INVERTED				= false;
	//==========================================================================================
	// Drive Encoder conversion rates to convert from counts to feet and feet per second
	//==========================================================================================
	const float ENCODER_DISTANCE_CONVERSION = 0.0010908307638889; // encoder counts to feet
	const float ENCODER_VELOCITY_CONVERSION = 0.0109083076388889; // encoder counts per 0.1 sec to feet per second
	const float DRIVE_COUNTS_PER_REVOLUTION = 360; //encoder counts per rotation of drive motors
	const float FPS_TO_RPM = 38.197097020626; //conversion from feet per second to rpm for use with talon velocity PID control
	const float FEET_TO_ROTATIONS = 1.5707963267948966; //conversion from feet to rotations for use witl talon position PID control

	//	TODO: Actually calculate following line for this robot
	const float DEGREES_PER_PULSE = 1; //90 degrees divided by delta counts (left - right) from calibrated turn times for to convert to quad encoding. degrees/(counts * encoding)

	//=============================================================================================
	// Digital IO
	//=============================================================================================
	const int GYRO_SENSOR									= 1;

	const float SHOOTER_COUNTS_PER_ROTATION = 1440; //number of encoder counts per rotation of the shooter wheels
	const float INTAKE_COUNTS_PER_ROTATION = 1440; //number of encoder counts per rotation of the intake
	const float CLIMB_COUNTS_PER_ROTATION = 1440; //number of encoder counts per rotation of the climber

	//Pneumatics

	const int UPPER_FLAP_SOLENOID		= 1;
	const int LOWER_FLAP_SOLENOID		= 2;

	const int GEAR_SENSOR				= 3;
	const int PEG_SENSOR				= 4;
	const int UPPER_FLAP_SENSOR			= 6;
	const int LOWER_FLAP_SENSOR			= 7;


#endif /* SRC_SUBSYS_SWBOT_SWMAP_H_ */
