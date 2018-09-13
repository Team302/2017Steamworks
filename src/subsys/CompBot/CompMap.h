/*
 * CompMap.h
 *
 *  Created on: Jan 14, 2017
 *      Author: Team302
 */

#ifndef COMPMAP_H_
#define COMPMAP_H_

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
	const int CLIMB_MOTOR						= 5; //invert //TODO: Comp bot = 6, eighty bot = 5


//	const int LEFT_ENCODER_MOTOR				= 6;

	const int INTAKE_MOTOR						= 7; // invert
	const int LIFT_CONVEYER_MOTOR				= 8; // invert
	const int MASTER_SHOOTER_MOTOR				= 9;
	const int LOWER_CONVEYER_MOTOR				= 10; //invert
	const int SLAVE_SHOOTER_MOTOR		        = 11;
	//const int SOMETHING GOES HERE				= 12;

	//============================================================================
	// TALON Motor- inversion settings
	//============================================================================
	//TODO: in compBotChassis, we are currently only using 1 encoder for distance. we need to check all encoders and use as much as possible
	const bool IS_LEFT_FRONT_DRIVE_MOTOR_INVERTED	   	    = false;
	const bool IS_LEFT_BACK_DRIVE_MOTOR_INVERTED		    = false;
	const bool IS_RIGHT_FRONT_DRIVE_MOTOR_INVERTED			= true;
	const bool IS_RIGHT_BACK_DRIVE_MOTOR_INVERTED		    = true;

	const bool IS_CLIMB_MOTOR_INVERTED      		 	    = false;

	const bool IS_INTAKE_MOTOR_INVERTED						= true;
	const bool IS_LIFT_CONVEYER_MOTOR_INVERTED	            = true;
	const bool IS_MASTER_SHOOTER_MOTOR_INVERTED		 		= false;
	const bool IS_LOWER_CONVEYER_MOTOR_INVERTED				= true;
	const bool IS_SLAVE_SHOOTER_MOTOR_INVERTED				= true; //TODO: true on compBot
	//const bool IS_PUTSOMETHINGHERE_INVERTED					= false

	//============================================================================
	// TALON Encoder- sensor inversion settings
	//============================================================================

	const bool IS_LEFT_BACK_DRIVE_ENCODER_INVERTED		    = true;
	const bool IS_RIGHT_BACK_DRIVE_ENCODER_INVERTED		    = true;

	const bool IS_SHOOTER_ENCODER_INVERTED					= true;

	const bool IS_CLIMB_ENCODER_INVERTED					= false;

	//==========================================================================================
	// Drive Encoder conversion rates to convert from counts to feet and feet per second
	//==========================================================================================
//	const float ENCODER_DISTANCE_CONVERSION = 0.0023271056693257; // encoder counts to feet //Comp Bot
	const float ENCODER_DISTANCE_CONVERSION = 0.0038047824046258; //comp bot 4-12 * 2
//	const float ENCODER_DISTANCE_CONVERSION = 0.0019023912023129; //comp bot 4-12
//	const float ENCODER_DISTANCE_CONVERSION = 0.0016622183352327; //comp bot 5-20 (note ratio would be .00232710567)
//	const float ENCODER_DISTANCE_CONVERSION = 0.00083110916761635;
//	const float ENCODER_DISTANCE_CONVERSION = 0.0024375380865326; //Eighty Bot
	const float ENCODER_VELOCITY_CONVERSION = 0.0232710566932577; // encoder counts per 0.1 sec to feet per second
	const float DEGREES_PER_PULSE = (90.0/(1150.0 * 1.0)); //(90.0/(1350.0 * 1.0)) (90.0/(1323.0 * 4.0))  90 degrees divided by delta counts (left - right) from calibrated turn times for to convert to quad encoding. degrees/(counts * encoding)
	//TODO: fix this. remove the ratio at the end of the conversions and figure out the correct conversion
	const float FPS_TO_RPM = 38.197097020626; //conversion from feet per second to rpm for use with talon velocity PID control //TODO: need correct value here
	const float FEET_TO_ROTATIONS = 1.5707963267948966; //conversion from feet to rotations for use witl talon position PID control

	const float DRIVE_COUNTS_PER_REVOLUTION = 450; //encoder counts per rotation of drive motors //360

	const float SHOOTER_COUNTS_PER_ROTATION = 1024; //number of encoder counts per rotation of the shooter wheels
	const float INTAKE_COUNTS_PER_ROTATION = 1024; //number of encoder counts per rotation of the intake

	const float CLIMB_COUNTS_PER_ROTATION = 1024; //number of encoder counts per rotation of the climber

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

	const int PCM_MODULE									= 13; //TODO: Add this to other maps (Eighty must be 0, works w/ default

} /* namespace Team302 */

#endif /* COMPMAP_H_ */
