/*
 * FuelHandlerFactory.h
 *
 *  Created on: Jan 12, 2017
 *      Author: Austin
 */

#ifndef SRC_FuelHandlerFACTORY_H_
#define SRC_FuelHandlerFACTORY_H_

#include <subsys/interfaces/IFuelHandler.h>

namespace Team302 {

class FuelHandlerFactory
{
	public:
    //----------------------------------------------------------------------------------
    // Method:      GetInstance
    // Description: If there isn't an instance, create it.
    //              Otherwise, hand out the single instance.
    // Returns:     FuelHandlerFactory*    This class
    //----------------------------------------------------------------------------------
	static FuelHandlerFactory* GetInstance();

    //----------------------------------------------------------------------------------
    // Method:      GetIFuelHandler
    // Description: If there isn't an instance of desired IFuelHandler class, create it.
    //              Otherwise, hand out the single instance.
    // Returns:     IFuelHandler*   Chassis class
    //----------------------------------------------------------------------------------
	IFuelHandler* GetIFuelHandler();

	private:
    //--------------------------------------------------------------------
    // Method:      FuelHandlerFactory <<constructor>>
    // Description: This method creates and initializes the objects
    //--------------------------------------------------------------------
	FuelHandlerFactory(); //this thing is a constructor.

    //--------------------------------------------------------------------
    // Method:      ~FuelHandlerFactory <<destructor>>
    // Description: This method is called to delete these objects
    //--------------------------------------------------------------------
	virtual ~FuelHandlerFactory();

	//these are some things I don't really understand
	static FuelHandlerFactory* m_instance;
	IFuelHandler* m_FuelHandler;

	//I kind of know what this stuff does but I don't really care
    // Default methods we don't want the compiler to implement for us
    FuelHandlerFactory( const FuelHandlerFactory& ) = delete;
    FuelHandlerFactory& operator= ( const FuelHandlerFactory& ) = delete;
    explicit FuelHandlerFactory( FuelHandlerFactory* other ) = delete;
};

} /* namespace Team302 */

#endif /* SRC_FuelHandlerFACTORY_H_ */
