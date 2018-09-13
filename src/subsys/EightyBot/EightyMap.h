/*
 * EightyMap.h
 *
 *  Created on: Feb 5, 2017
 *      Author: Tumtu
 */

#ifndef SRC_SUBSYS_SWBOT_EIGHTYMAP_H_
#define SRC_SUBSYS_SWBOT_EIGHTYMAP_H_

namespace Team302
{

	//============================================================================
	// CAN PORTS
	//============================================================================

	// Driving
	const int LEFT_FRONT_DRIVE_MOTOR			= 1;
	const int LEFT_BACK_DRIVE_MOTOR				= 2;
	const int RIGHT_FRONT_DRIVE_MOTOR			= 3; //invert
	const int RIGHT_BACK_DRIVE_MOTOR			= 4; //invert

	//Other Things
	const int CLIMB_MOTOR						= 6; //invert

	const int INTAKE_MOTOR						= 7; // invert
	const int LIFT_CONVEYER_MOTOR				= 8; // invert
	const int MASTER_SHOOTER_MOTOR				= 9;
	const int LOWER_CONVEYER_MOTOR				= 10; //invert
	const int SLAVE_SHOOTER_MOTOR		        = 11;
	//const int SOMETHING GOES HERE				= 12;

	//============================================================================
	// TALON Motor- inversion settings
	//============================================================================

	const bool IS_LEFT_FRONT_DRIVE_MOTOR_INVERTED	   	    = false;
	const bool IS_LEFT_BACK_DRIVE_MOTOR_INVERTED		    = false;
	const bool IS_RIGHT_FRONT_DRIVE_MOTOR_INVERTED			= true;
	const bool IS_RIGHT_BACK_DRIVE_MOTOR_INVERTED		    = true;

	const bool IS_CLIMB_MOTOR_INVERTED		      		    = true;

	const bool IS_INTAKE_MOTOR_INVERTED						= true;
	const bool IS_LIFT_CONVEYER_MOTOR_INVERTED	            = true;
	const bool IS_MASTER_SHOOTER_MOTOR_INVERTED		 		= false;
	const bool IS_LOWER_CONVEYER_MOTOR_INVERTED				= true;
	const bool IS_SLAVE_SHOOTER_MOTOR_INVERTED				= false;
	//const bool IS_PUTSOMETHINGHERE_INVERTED					= false

	//============================================================================
	// TALON Encoder- sensor inversion settings
	//============================================================================

	const bool IS_LEFT_BACK_DRIVE_ENCODER_INVERTED		    = true;
	const bool IS_RIGHT_BACK_DRIVE_ENCODER_INVERTED		    = true;

	const bool IS_SHOOTER_ENCODER_INVERTED					= true;

	const bool IS_CLIMB_ENCODER_INVERTED					= false; //TODO: Encoder inversion might change so check that when we get robit

	//==========================================================================================
	// Drive Encoder conversion rates to convert from counts to feet and feet per second
	//==========================================================================================
		//TODO all conversions need to be checked
	//	const float ENCODER_DISTANCE_CONVERSION = 0.0010908307638889; // encoder counts to feet
	const float ENCODER_DISTANCE_CONVERSION = 0.0011038745998455;
	const float ENCODER_VELOCITY_CONVERSION = 0.0109083076388889; // encoder counts per 0.1 sec to feet per second
	const float DRIVE_COUNTS_PER_REVOLUTION = 360; //encoder counts per rotation of drive motors
	const float FPS_TO_RPM = 38.197097020626; //conversion from feet per second to rpm for use with talon velocity PID control
	const float FEET_TO_ROTATIONS = 1.5707963267948966; //conversion from feet to rotations for use witl talon position PID control
	const float SHOOTER_COUNTS_PER_ROTATION = 1024; //number of encoder counts per rotation of the shooter wheels
	const float INTAKE_COUNTS_PER_ROTATION = 1024; //number of encoder counts per rotation of the intake
	const float CLIMB_COUNTS_PER_ROTATION = 450; // TODO: Should be checked
//	TODO: Actually calculate following line for this robot
	const float DEGREES_PER_PULSE = 1; //90 degrees divided by delta counts (left - right) from calibrated turn times for to convert to quad encoding. degrees/(counts * encoding)


	//=============================================================================================
	// Digital IO
	//=============================================================================================
	const int GEAR_PRESENT_SENSOR							= 1;
	const int GEAR_POST_PRESENT_SENSOR						= 0;
	const int UPPER_FLAP_SENSOR								= 3;
	const int LOWER_FLAP_SENSOR								= 2;

	//=============================================================================================
	// Digital IO
	//=============================================================================================
	const int GYRO_SENSOR									= 1;

	//=============================================================================================
	// Pneumatics
	//=============================================================================================
	const int GEAR_DEPLOYMENT_SOL							= 0;
	const int RAMP_MOVEMENT_SOL								= 1;

} /* namespace Team302 */

#endif /* SRC_SUBSYS_SWBOT_EIGHTYMAP_H_ */
