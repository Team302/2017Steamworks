/*
 * DragonXbox.h
 *
 *  Created on: Jan 14, 2017
 *      Author: jonah shader
 */

#ifndef SRC_DRAGONXBOX_H_
#define SRC_DRAGONXBOX_H_

#include <XboxController.h>


#define DRIVER_SLOT 0
#define COPILOT_SLOT 1


namespace Team302 
{
// TODO:  JW document the methods: what do they do, what are the inputs


	
	class DragonXbox
	{
		public:

			enum XBOX_AXIS_IDENTIFIER
			{
				X_AXIS_LEFT_JOYSTICK,
				Y_AXIS_LEFT_JOYSTICK,
				LEFT_TRIGGER,
				RIGHT_TRIGGER,
				X_AXIS_RIGHT_JOYSTICK,
				Y_AXIS_RIGHT_JOYSTICK,
				MAX_XBOX_AXIS					// used for looping
			};

			enum BUTTON_IDENTIFIER
			{
				A_BUTTON,
				B_BUTTON,
				X_BUTTON,
				Y_BUTTON,
				LEFT_BUMPER,
				RIGHT_BUMPER,
				BACK_BUTTON,
				START_BUTTON,
				PRESS_LEFT_STICK,
				PRESS_RIGHT_STICK,
				LEFT_TRIGGER_PRESSED,
				RIGHT_TRIGGER_PRESSED,
/*				POV_0_PRESSED,
				POV_45_PRESSED,
				POV_90_PRESSED,
				POV_135_PRESSED,
				POV_180_PRESSED,
				POV_225_PRESSED,
				POV_270_PRESSED,
				POV_315_PRESSED,
*/				MAX_XBOX_BUTTONS					// used for looping
			};

			enum AXIS_SENSITIVITY_CURVE //enum for selecting linear or cubic axis profile
			{
				AXIS_LINEAR,
				AXIS_CUBIC,
				MAX_SENS_OPTIONS
			};

			static DragonXbox* GetDriver();
			static DragonXbox* GetCopilot();

			//-------------------------------------------------------------------------------------------------
			// Method:      <<Constructor>>      
			// Description: Create a DragonXbox object .
			//-------------------------------------------------------------------------------------------------
			DragonXbox
			(
				const int 							port				// <I> - port for the xbox controller
			);

			//-------------------------------------------------------------------------------------------------
			// Method:      <<Destructor>>      
			// Description: Destroy a DragonXbox object .
			//-------------------------------------------------------------------------------------------------
			virtual ~DragonXbox() = default;

			//getters
			//-------------------------------------------------------------------------------------------------
			// Method:      GetAxis     
			// Description: Return the current value (between -1.0 and 1.0) for the requested axis.
			// Returns:		float 	- current axis value
			//-------------------------------------------------------------------------------------------------
			float GetAxis
			(	
				int 						axis			// <I> - axis identifier to read
			) const;
			
			//-------------------------------------------------------------------------------------------------
			// Method:      GetButton     
			// Description: Return whether the requested button is selected (true) or not (false) 
			// Returns:		bool 	true  - button is pressed
			//						false - button is not pressed
			//-------------------------------------------------------------------------------------------------
			bool GetButton
			(	
				int 						button			// <I> - button to check
			) const;
			
			
			//setters
			//-------------------------------------------------------------------------------------------------
			// Method:      SetCurve     
			// Description: Specify the profile curve used for setting the sensitivity of the axis.  By default, 
			//				this is linear, but a cubic curve would give more control when the axis is barely 
			//				pressed (e.g. if it were moved 50% forward, instead of returning 0.5, it would 
			//				return 0.5 * 0.5 * 0.5 or .125, but when the axis was moved all the way forward, 
			//				it would return the same value -- 1.0.  Since it is cubed, it retains the sign.
			//
			//				This affects values returned from GetAxis calls.
			// Returns:		void
			//-------------------------------------------------------------------------------------------------			
			void SetCurve
			(
				int 							axis,		// <I> - axis identifier to modify
				int								curve		// <I> - the definition of the sensitivity
			);

			
			//-------------------------------------------------------------------------------------------------
			// Method:      SetScale     
			// Description: Scale the returned value to a range between the specified negative scale factor and 
			//				the scale factor.  This is used to reduce the maximum value returned.
			//
			//				This affects values returned from GetAxis calls.
			// Returns:		void
			//-------------------------------------------------------------------------------------------------			
			void SetScale
			(	
				int	 				axis,		// <I> - axis identifier to modify
				float					scaleFactor	// <I> - value  (0 < scale <= 1.0) to scale the axis value
			);
			//Method: SetRumble
			//rumbles
			void SetRumble( double left, double right);

			
	private:

			static DragonXbox* m_driver; 
			static DragonXbox* m_copilot;
			
			const float DEAD_BAND_THRESH = 0.2; 		// Minimum value joystick must be past to actually return value to prevent drift
			const float TRIGGER_PRESSED_THRESH = 0.4;	// When triggers are treated as buttons, it must be pressed more than this value to be considered pressed
			const float DONT_INVERT_AXIS = 1.0;			// Scale factor for inverting the axis
			const float INVERT_AXIS = -1.0;				// Scale factor for inverting the axis
			const float LINEAR_SCALE_CURVE = 1.0;       // Linear profile power
			const float CUBIC_SCALE_CURVE = 3.0;		// Cubic profile power
			const float STD_RANGE_SCALING = 1.0;        // Range is between -1.0 and 1.0

			// Methods not being implemented
			DragonXbox() = delete;
			DragonXbox( DragonXbox* other ) =  delete;
			
			// Attributes
			XboxController*						m_controller;			// xbox controller this is managing
			std::vector<float>          		m_axisScale;			// scale factor used to limit the range of axis values returned

			std::vector<float>          		m_axisInversionFactor;	// scale factors used to invert the axis values (always 1.0 or -1.0)
																		// the index into the vector is AXIS_IDENTIFIER.

			std::vector<float>					m_axisCurve;			// the definition for "scaling" the axis values
																		// the index into the vector is AXIS_IDENTIFIER.

};

} /* namespace Team302 */
#endif /* SRC_DRAGONXBOX_H_ */
