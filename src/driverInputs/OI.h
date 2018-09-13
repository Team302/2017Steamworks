/*
 * OI.h
 *
 *  Created on: Jan 14, 2017
 *      Author: Austin and Jonah
 */

#ifndef SRC_OI_H_
#define SRC_OI_H_

#include <DriverStation.h>

namespace frc
{
    class DriverStation;
}

namespace Team302
{


    class DragonXbox;

    class OI
    {
        public:

            enum CONTROLLER_CONFIGURATION
            {
                DRIVER_XBOX, //Both drivers xbox
                DRIVER_STICKS, //Driver two sticks, copilot on xbox
                MAX_CONTROLLER_CONFIGS
            };

            enum FUNCTION_IDENTIFIER
            {
                TANK_DRIVE_LEFT_CONTROL, // Controls left drive side
                TANK_DRIVE_RIGHT_CONTROL, // Controls right drive side
                ARCADE_DRIVE_THROTTLE,
                ARCADE_DRIVE_STEER,
                SWITCH_DRIVE_MODE, // Toggles between tank and arcade
                ACTIVATE_INTAKE,
                ACTIVATE_INTAKE2,
                ACTIVATE_LOAD,
                ACTIVATE_SHOOTER,
				CONTROL_SHOOTER_SPEED,
                DEPLOY_GEAR,
                START_WINCH,
                OPEN_UPPER_FLAP,
                MAX_FUNCTIONS
            };

            enum AXIS_SENSITIVITY_CURVE //enum for selecting linear or cubic axis profile
            {
                AXIS_LINEAR,
                AXIS_CUBIC,
                MAX_SENS_OPTIONS
            };

            //----------------------------------------------------------------------------------
            // Method:      GetInstance
            // Description: If there isn't an instance of this class, it will create one.  The
            //              single class instance will be returned.
            // Returns:     OperatorInterface*  instance of this class
            //----------------------------------------------------------------------------------
            static OI* GetInstance();

            //------------------------------------------------------------------
            // Method:      SetScaleFactor
            // Description: Allow the range of values to be set smaller than
            //              -1.0 to 1.0.  By providing a scale factor between 0.0
            //              and 1.0, the range can be made smaller.  If a value
            //              outside the range is provided, then the value will
            //              be set to the closest bounding value (e.g. 1.5 will
            //              become 1.0)
            // Returns:     void
            //------------------------------------------------------------------
            void SetScaleFactor
            (
                FUNCTION_IDENTIFIER     axis,          // <I> - axis number to update
                float                   scaleFactor    // <I> - scale factor used to limit the range
            );

            //------------------------------------------------------------------
            // Method:      SetCurve
            // Description: Sets the axis curve profile for the specified axis
            // Returns:     void
            //------------------------------------------------------------------
            void SetCurve
            (
                FUNCTION_IDENTIFIER     axis,           // <I> - axis number to update
                AXIS_SENSITIVITY_CURVE  curve         // <I> - curve profile to use
            );

            //------------------------------------------------------------------
            // Method:      GetRawAxis
            // Description: Reads the joystick axis, removes any deadband (small
            //              value) and then scales as requested.
            // Returns:     float   -  scaled axis value
            //------------------------------------------------------------------
            float GetAxis
            (
                FUNCTION_IDENTIFIER     axis          // <I> - axis number to update
            ) const;

            //------------------------------------------------------------------
            // Method:      GetButton
            // Description: Reads the button value.  Also allows POV, bumpers,
            //              and triggers to be treated as buttons.
            // Returns:     bool   -  scaled axis value
            //------------------------------------------------------------------
            bool GetButton
            (
                FUNCTION_IDENTIFIER button           // <I> - button number to query
            ) const;

            //----------------------------------------------------------------------------------
            // Method:      OI <<constructor>>
            // Description: This will construct and initialize the object
            // Parameters:  enum CONTROLLER_COMBINATIONS - select which combination
            //              of controllers to use
            //----------------------------------------------------------------------------------
            OI();

            //----------------------------------------------------------------------------------
            // Method:      ~OI <<destructor>>
            // Description: This will clean up the object
            //----------------------------------------------------------------------------------
            virtual ~OI();

        private:
            //----------------------------------------------------------------------------------
            // Method:      Mapper
            // Description: This will map the external enums to the actual control button/axis
            // Returns:     void
            //----------------------------------------------------------------------------------
            void Mapper();

            DragonXbox* GetStick( FUNCTION_IDENTIFIER function ) const;

            //----------------------------------------------------------------------------------
            // Attributes
            //----------------------------------------------------------------------------------
            static OI*   m_instance; // Singleton instance of this class

            // Array index for gamepads && also the Port ID for the constructors
            const int                   DRIVER_PAD = 0;
            const int                   COPILOT_PAD = 1;

            // Port IDs for constructors
//            const int                   DRIVER_PORT = 0;
//          const int                   COPILOT_PORT = 1;

            // Gamepads
            DragonXbox*                 m_gamePads[2];

            const int                   UNDEFINED_MAPPING = -1000;
            const int                   NULL_AXIS = -999;
            const int                   NULL_BUTTON = -999;

            int                         m_gamePadIDs[100];       //
            int                         m_axisIDs[100];          //
            int                         m_buttonIDs[100];        //
        };

} /* namespace Team302 */

#endif /* SRC_OI_H_ */
