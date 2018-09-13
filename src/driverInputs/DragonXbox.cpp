/*
 * DragonXBox.cpp
 *
 *  Created on: Jan 14, 2017
 *      Author: jonah shader
 */
#include <XboxController.h>
#include <GenericHID.h>
#include <driverInputs/DragonXbox.h>
#include <utils/LimitValue.h>

namespace Team302 
{
	DragonXbox* DragonXbox::m_driver = nullptr;//Init the instance to nullptr
	DragonXbox* DragonXbox::m_copilot = nullptr;//Init the instance to nullptr
	

	//----------------------------------------------------------------------------------
	// Method:      GetDriver
	// Description: If there isn't an instance, create it.
	//              Otherwise, hand out the single instance.
	// Returns:     DragonXbox*    driver game pad
	//----------------------------------------------------------------------------------
	DragonXbox* DragonXbox::GetDriver()
	{
		if (DragonXbox::m_driver == nullptr)
		{
			DragonXbox::m_driver = new DragonXbox( DRIVER_SLOT );
		}
		return DragonXbox::m_driver;
	}

	//----------------------------------------------------------------------------------
	// Method:      GetCopilot
	// Description: If there isn't an instance, create it.
	//              Otherwise, hand out the single instance.
	// Returns:     DragonXbox*    copilot game pad
	//----------------------------------------------------------------------------------
	DragonXbox* DragonXbox::GetCopilot()
	{
		if (DragonXbox::m_copilot == nullptr)
		{
			DragonXbox::m_copilot = new DragonXbox( COPILOT_SLOT );
		}
		return DragonXbox::m_copilot;
	}

	//-------------------------------------------------------------------------------------------------
	// Method:      <<Constructor>>      
	// Description: Create a DragonXbox object .
	//-------------------------------------------------------------------------------------------------
	DragonXbox::DragonXbox
	(
		int 	port					// <I> - port for the xbox controller
	) : m_controller( new XboxController( port ) ) ,
		m_axisScale(),
		m_axisInversionFactor(),
		m_axisCurve( 1.0 )
	{
		// Initialize the attributes for all of the axis to the defaults
		for ( auto inx=0; inx<MAX_XBOX_AXIS; ++inx )
		{
			m_axisScale.emplace_back( STD_RANGE_SCALING );			// range is -1.0 to 1.0
			m_axisInversionFactor.emplace_back( DONT_INVERT_AXIS );	// values are whatever is read from the axis
			m_axisCurve.emplace_back( CUBIC_SCALE_CURVE );			// scaling curve is 1.0
		}
		
		// Modify the axis without default values
		// - Y axis are inverted
		m_axisInversionFactor[Y_AXIS_LEFT_JOYSTICK]  = INVERT_AXIS;
		m_axisInversionFactor[Y_AXIS_RIGHT_JOYSTICK] = INVERT_AXIS;
	}



	//----------------------------------------------------------------------------------
	// Method:      GetAxis
	// Description: This returns the scaled and curve profiled axis value for the specified axis
	//	
	//				NOTE:  the order of operations is important because if deadband is
	//				done, last, for instance, the output would lose a lot of the benefit
	//				of the scaling curve (power).  For instance, if a value of 0.5 were read
	//				from the axis and 0.2 was the deadband, if the curve was cubic, it 
	//				would calculate a value of 0.125 which would be below the deadband
	//				threshold, so it would return 0.0.  On the otherhand, if deadbanding
	//				is done on the raw value, 0.125 would be returned.  In fact, in
	//				the first scenario, the axis would need to read almost 0.6 before
	//				a non-zero value would be returned (at which point 0.2 is returned), so
	//				only 0.4 of the range is returning non-zero numbers.  Comparing this
	//				to the second case, at 0.2 a value of .008 is calculated and returned.
	// Returns:     double output - scaled, deadbanded, and curve profiled output of axis
	//----------------------------------------------------------------------------------
	float DragonXbox::GetAxis
	(	
		int			axis			// <I> - axis identifier to read
	) const
	{
		double output = 0.0;	//zero output to start
		if ( axis < MAX_XBOX_AXIS )
		{
			// read the appropriate value from the xbox controller & multiply it by the inversion factor
			switch ( axis )
			{
				case X_AXIS_LEFT_JOYSTICK:
					output = m_controller->GetX( GenericHID::kLeftHand ) * m_axisInversionFactor[ axis ];
					break;
				
				case Y_AXIS_LEFT_JOYSTICK:
					output = m_controller->GetY( GenericHID::kLeftHand ) * m_axisInversionFactor[ axis ];
					break;
				
				case LEFT_TRIGGER:
					output = m_controller->GetTriggerAxis( GenericHID::kLeftHand ) * m_axisInversionFactor[ axis ];
					break;
				
				case RIGHT_TRIGGER:
					output = m_controller->GetTriggerAxis( GenericHID::kRightHand ) * m_axisInversionFactor[ axis ];
					break;
				
				case X_AXIS_RIGHT_JOYSTICK:
					output = m_controller->GetX( GenericHID::kRightHand ) * m_axisInversionFactor[ axis ];
					break;
				
				case Y_AXIS_RIGHT_JOYSTICK:
					output = m_controller->GetY( GenericHID::kRightHand ) * m_axisInversionFactor[ axis ];
					break;
					
				default:
					break;
			}
			
			// Check if less than deadband value and if so, set the output to zero
			// otherwise, apply the curve and scale modifiers
			if ( std::abs( output ) < DEAD_BAND_THRESH )
			{
				output = 0.0;		// Remove the deadband
			}
			else
			{	// TODO:: for performance, should eliminate std::pow
				output = std::pow( output, m_axisCurve[ axis ] ) * m_axisScale[ axis ];  // first apply the axis curve scaling and then the scale factor 				
			}
		}
		return output; //returns scaled, profiled, deadbanded joystick output
	}

	//----------------------------------------------------------------------------------
	// Method:      GetButton
	// Description: This returns the scaled and curve profiled axis value for the specified axis
	// Parameters:	button - BUTTON_IDENTIFIER enum to select which button to check
	// Returns:     bool - true for button pressed
	//----------------------------------------------------------------------------------
	bool DragonXbox::GetButton
	(
		int	 							button			// <I> - button to check
	) const
	{
		bool pressed = false;
		//switch statement to check if button is pressed depending on which button is identified
		switch(button)
		{
			case A_BUTTON:
				pressed = m_controller->GetAButton();
				break;

			case B_BUTTON:
				pressed = m_controller->GetBButton();
				break;

			case X_BUTTON:
				pressed = m_controller->GetXButton();
				break;

			case Y_BUTTON:
				pressed = m_controller->GetYButton();
				break;

			case LEFT_BUMPER:
				pressed = m_controller->GetBumper( GenericHID::kLeftHand );
				break;

			case RIGHT_BUMPER:
				pressed = m_controller->GetBumper( GenericHID::kRightHand );
				break;

			case BACK_BUTTON:
				pressed = m_controller->GetBackButton();
				break;

			case START_BUTTON:
				pressed = m_controller->GetStartButton();
				break;

			case PRESS_LEFT_STICK:
				pressed = m_controller->GetStickButton( GenericHID::kLeftHand );
				break;

			case PRESS_RIGHT_STICK:
				pressed = m_controller->GetStickButton( GenericHID::kRightHand );
				break;

			case LEFT_TRIGGER_PRESSED:
				pressed = (m_controller->GetTriggerAxis( GenericHID::kLeftHand )) > TRIGGER_PRESSED_THRESH; //if trigger value is greater than threshold return true
				break;

			case RIGHT_TRIGGER_PRESSED:
				pressed = (m_controller->GetTriggerAxis( GenericHID::kRightHand )) > TRIGGER_PRESSED_THRESH; //if trigger value is greater than threshold return true
				break;

/*			case POV_0_PRESSED:
				pressed = !(m_controller->GetPOV(0));
				break;

			case POV_45_PRESSED:
				pressed = !(m_controller->GetPOV(45));
				break;

			case POV_90_PRESSED:
				pressed = !(m_controller->GetPOV(90));
				break;

			case POV_135_PRESSED:
				pressed = !(m_controller->GetPOV(135));
				break;

			case POV_180_PRESSED:
				pressed = !(m_controller->GetPOV(180));
				break;

			case POV_225_PRESSED:
				pressed = !(m_controller->GetPOV(225));
				break;

			case POV_270_PRESSED:
				pressed = !(m_controller->GetPOV(270));
				break;

			case POV_315_PRESSED:
				pressed = !(m_controller->GetPOV(315));
				break;
*/
			default:
				pressed = false;
				break;
		}

		return pressed; //returns bool for is button pressed
	}

	//----------------------------------------------------------------------------------
	// Method:      SetScale
	// Description: This returns the scaled and curve profiled axis value for the specified axis
	// Parameters:	axis - AXIS_IDENTIFIER enum to choose which axis to get value of
	//				scaleFactor - float to set desired scale factor on specified axis. Should be 0.0 to 1.0
	// Returns:     void
	//----------------------------------------------------------------------------------
	void DragonXbox::SetScale
	(
		int	 					axis,		// <I> - axis identifier to modify
		float 					scaleFactor	// <I> - value  (0 < scale <= 1.0) to scale the axis value
	)
	{
		if ( axis < MAX_XBOX_AXIS )				// valid axis
		{
			m_axisScale[ axis ] = LimitValue::ForceInRange( scaleFactor, -0.98, 0.98 ); // set the scale factor limiting it to the valid range
		}
	}

	//----------------------------------------------------------------------------------
	// Method:      SetCurve
	// Description: This returns the scaled and curve profiled axis value for the specified axis
	// Parameters:	axis - AXIS_IDENTIFIER enum to choose which axis to get value of
	//				curve -CURVE enum to select curve profile type
	// Returns:     void
	//----------------------------------------------------------------------------------
	void DragonXbox::SetCurve
	(
		int	 			axis,		// <I> - axis identifier to modify
		int				curve		// <I> - the definition of the sensitivity
	)
	{
		if ( axis < MAX_XBOX_AXIS )				// valid axis
		{
			m_axisCurve[ axis ] = ( curve == AXIS_SENSITIVITY_CURVE::AXIS_CUBIC ) ? 3.0 : 1.0; 	// update the power
		}
	}

	void DragonXbox::SetRumble(double left, double right)
	{
		m_controller->SetRumble(GenericHID::kLeftRumble, left);
		m_controller->SetRumble(GenericHID::kRightRumble, right);
	}

} /* namespace Team302 */
