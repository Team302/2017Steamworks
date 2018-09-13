/*
 * OI.cpp
 *
 *  Created on: Jan 14, 2017
 *      Author: Tumtu
 */

#include <driverInputs/OI.h>
#include <driverInputs/DragonXbox.h>
#include <DriverStation.h>
#include <SmartDashboard/SmartDashboard.h>



namespace Team302
{
    //----------------------------------------------------------------------------------
    // Method:      GetInstance
    // Description: If there isn't an instance of this class, it will create one.  The
    //              single class instance will be returned.
    // Returns:     OI*  instance of this class
    //----------------------------------------------------------------------------------
    OI* OI::m_instance = nullptr; // initialize the instance variable to nullptr
    OI* OI::GetInstance()
    {
        if ( OI::m_instance == nullptr ) //checks if an instance of OI has been made yet
        {
            OI::m_instance = new OI(); //create an instance of OI if none exist yet
        }
        return OI::m_instance;
    }

    //----------------------------------------------------------------------------------
    // Method:      OI <<constructor>>
    // Description: This creates the driver controller and the co-pilot controller and
    //              maps the functions to the buttons/axis.
    //----------------------------------------------------------------------------------
    OI::OI() : m_gamePads()
    {
        m_gamePads [DRIVER_PAD] = new DragonXbox(DRIVER_PAD);
        m_gamePads [COPILOT_PAD] = new DragonXbox(COPILOT_PAD);
        Mapper(); //call mapper function to map all the functions after creating sticks
    }

    //----------------------------------------------------------------------------------
    // Method:      Mapper
    // Description: This maps the enums, such as driving axis
    //              to the actual axis/buttons to control it
    //----------------------------------------------------------------------------------
    void OI::Mapper()
    {
        //this sets all of the button, joystick, and axis IDs to not defined so we can set them later
        for ( int inx=0; inx<MAX_FUNCTIONS; ++inx )
        {
            m_gamePadIDs[inx] = UNDEFINED_MAPPING;
            m_axisIDs[inx]    = NULL_AXIS;
            m_buttonIDs[inx]  = NULL_BUTTON;
        }

        //----------------------------------------------------------------------------
        // Driver Controls
        //  declare which physical controller this action is on
        //  declare which axis/button that action is on
        //----------------------------------------------------------------------------
        m_gamePadIDs[ TANK_DRIVE_LEFT_CONTROL ]     = DRIVER_PAD;
        m_axisIDs[ TANK_DRIVE_LEFT_CONTROL ]        = DragonXbox::Y_AXIS_LEFT_JOYSTICK;

        m_gamePadIDs[ TANK_DRIVE_RIGHT_CONTROL ]    = DRIVER_PAD;
        m_axisIDs[ TANK_DRIVE_RIGHT_CONTROL ]       = DragonXbox::Y_AXIS_RIGHT_JOYSTICK;

        m_gamePadIDs[ ARCADE_DRIVE_THROTTLE ]       = DRIVER_PAD;
        m_axisIDs[ ARCADE_DRIVE_THROTTLE ]          = DragonXbox::Y_AXIS_LEFT_JOYSTICK;

        m_gamePadIDs[ ARCADE_DRIVE_STEER ]          = DRIVER_PAD;
        m_axisIDs[ ARCADE_DRIVE_STEER ]             = DragonXbox::X_AXIS_RIGHT_JOYSTICK;

        //----------------------------------------------------------------------------
        // Co-Pilot Controls
        //  declare which physical controller this action is on
        //  declare which axis/button that action is on
        //----------------------------------------------------------------------------
        m_gamePadIDs[ ACTIVATE_INTAKE ]             = COPILOT_PAD;
        m_buttonIDs[ACTIVATE_INTAKE ]               = DragonXbox::LEFT_BUMPER;

        m_gamePadIDs[ ACTIVATE_INTAKE2 ]            = COPILOT_PAD;
        m_buttonIDs[ACTIVATE_INTAKE2 ]              = DragonXbox::LEFT_TRIGGER_PRESSED;

        m_gamePadIDs[ ACTIVATE_SHOOTER ]       		= COPILOT_PAD;
        m_buttonIDs[ ACTIVATE_SHOOTER]         		= DragonXbox::RIGHT_BUMPER;

        m_gamePadIDs[ CONTROL_SHOOTER_SPEED ]       = COPILOT_PAD;
        m_buttonIDs[ CONTROL_SHOOTER_SPEED]         = DragonXbox::RIGHT_TRIGGER_PRESSED;

        // TODO: this should be part of shoot / may need a jostle command
        m_gamePadIDs[ ACTIVATE_LOAD ]               = COPILOT_PAD;
        m_buttonIDs[ACTIVATE_LOAD ]                 = DragonXbox::A_BUTTON;

        m_gamePadIDs[ DEPLOY_GEAR]                  = COPILOT_PAD;
        m_buttonIDs[ DEPLOY_GEAR ]                  = DragonXbox::X_BUTTON;

        m_gamePadIDs[ OPEN_UPPER_FLAP]              = COPILOT_PAD;
        m_buttonIDs[ OPEN_UPPER_FLAP ]              = DragonXbox::Y_BUTTON;

        m_gamePadIDs[ START_WINCH]                  = COPILOT_PAD;
        m_buttonIDs[ START_WINCH ]                  = DragonXbox::B_BUTTON;

#if 0
        for ( int inx=0; inx<MAX_FUNCTIONS; ++inx )
        {
            std::string label = "OI - GamePad " + std::to_string(inx);
            SmartDashboard::PutNumber( label, m_gamePadIDs[inx] );
            label = "OI - axis id " + std::to_string(inx);
            SmartDashboard::PutNumber( label, m_axisIDs[inx] );
            label = "OI - button id " + std::to_string(inx);
            SmartDashboard::PutNumber( label, m_buttonIDs[inx] );
        }
#endif
    }

    //------------------------------------------------------------------
    // Method:      SetCurve
    // Description: Sets the axis curve profile for the specified axis
    // Parameters:  function: action we want to set curve on
    //              curve: curve profile to use
    //------------------------------------------------------------------
    void OI::SetCurve(FUNCTION_IDENTIFIER function, AXIS_SENSITIVITY_CURVE curve)
    {
        DragonXbox* stick = GetStick( function );
        if ( stick != nullptr )
        {
            if ( m_axisIDs[ function ] != NULL_AXIS )
            {
                //this uses the function identifier to apply the curve to the desired action, regardless of which physical axis is being used
                stick->SetCurve( m_axisIDs[ function ], curve );
            }
        }
    }

    //------------------------------------------------------------------
    // Method:      SetScaleFactor
    // Description: Sets the scale factor for the specified axis
    // Parameters:  function: whichever function, such as ARCADE_DRIVE_THROTTLE, that we want the factor on
    //              scaleFactor: value of factor. 0.0 to 1.0
    //------------------------------------------------------------------
    void OI::SetScaleFactor(FUNCTION_IDENTIFIER function, float scaleFactor)
    {
        DragonXbox* stick = GetStick( function );
        if ( stick != nullptr )
        {
            if ( m_axisIDs[ function ] != NULL_AXIS )
            {
                //uses function identifier to set scale factor to specified action, regardless of physical axis being used
                stick->SetScale( m_axisIDs[ function ], scaleFactor );
            }
        }
    }

    //------------------------------------------------------------------
    // Method:      GetAxis
    // Description: Reads the joystick axis, returns value with scale factor and curve profile
    // Parameters:  FUNCTION_IDENTIFIER  -  function on axis to get
    // Returns:     float   -  scaled axis value with curve profile
    //------------------------------------------------------------------
    float OI::GetAxis(FUNCTION_IDENTIFIER function) const
    {
        float value = 0.0;
        DragonXbox* stick = GetStick( function );
        if ( stick != nullptr )
        {
            if ( m_axisIDs[ function ] != NULL_AXIS )
            {
                //this gets the axis value based on which function we want the value for
                value = stick->GetAxis( m_axisIDs[ function ] );
            }
        }
        return value;
    }

    //------------------------------------------------------------------
    // Method:      GetButton
    // Description: Reads the button, POV, or trigger as button
    // Parameters:  FUNCTION_IDENTIFIER  -  function on button to get
    // Returns:     bool - true of button pressed
    //------------------------------------------------------------------
    bool OI::GetButton(FUNCTION_IDENTIFIER function) const
    {
        bool isPressed = false; //default button to not pressed
        DragonXbox* stick = GetStick( function );
        if ( stick != nullptr )
        {
            if ( m_buttonIDs[function] != NULL_BUTTON)
            {
                //gets the bool for if the specified button is pressed.
                //uses function identifier from mapping so this is independent of different controllers and layouts
                isPressed = stick -> GetButton(m_buttonIDs[function]);
            }
            else
            {
                SmartDashboard::PutNumber( "Function button not found ", function );
            }
        }
        SmartDashboard::PutBoolean( "Function button " + std::to_string( function ), isPressed );
        return isPressed;
    }

    //This thing is used to get the correct joystick for whichever function you want
    //It is passed a FUNCTION_IDENTIFIER enum
    DragonXbox* OI::GetStick(FUNCTION_IDENTIFIER function) const
    {
        DragonXbox* stick = nullptr;
        if (  m_gamePadIDs[ function ] ==  DRIVER_PAD )
        {
        	stick = m_gamePads[ DRIVER_PAD ];
        }
        else if ( m_gamePadIDs[ function ] == COPILOT_PAD )
        {
            stick = m_gamePads[ DRIVER_PAD ];
        }
        return stick;
    }

    //----------------------------------------------------------------------------------
    // Method:      ~OI <<destructor>>
    // Description: This will clean up the object
    //----------------------------------------------------------------------------------
    OI::~OI()
    {
        delete m_gamePads[DRIVER_PAD];
        m_gamePads[DRIVER_PAD] = nullptr;

        delete m_gamePads[DRIVER_PAD];
        m_gamePads[DRIVER_PAD] = nullptr;
    }

} /* namespace Team302 */
