/*
 * ChassisFactory.h
 *
 *  Created on: Jan 16, 2017
 *      Author: Jonah Shader
 */

#ifndef SRC_CHASSISFACTORY_H_
#define SRC_CHASSISFACTORY_H_

#include <subsys/interfaces/IChassis.h>
#include "RobotDefn.h"

namespace Team302
{

class ChassisFactory
{
public:
	//Returns and instance of this. If it doesn't exist, create it.
	static ChassisFactory* GetInstance();
	//Creates desired IChassis instance if it doesn't exist.
	//Returns it
	IChassis* GetIChassis();

private:
	//Constructor/destructors
	ChassisFactory();
	virtual ~ChassisFactory();

	static ChassisFactory* m_instance; //The factory
	IChassis*               m_chassis;

	ChassisFactory(const ChassisFactory&) = delete;
	ChassisFactory& operator = (const ChassisFactory* other) = delete;
	explicit ChassisFactory(ChassisFactory* other) = delete;
};

} /* namespace Team302 */

#endif /* SRC_CHASSISFACTORY_H_ */
