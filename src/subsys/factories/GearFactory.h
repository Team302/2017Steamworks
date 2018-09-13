/*
 * GearFactory.h
 *
 *  Created on: Jan 16, 2017
 *      Author: Tumtu
 */

#ifndef SRC_GEARFACTORY_H_
#define SRC_GEARFACTORY_H_

#include <subsys/interfaces/IGearer.h>

namespace Team302 {

class GearFactory
{
public:

	static GearFactory* GetInstance();

	IGearer* GetIGearer();

private:

	GearFactory();
	virtual ~GearFactory();

	static GearFactory* m_instance;
		IGearer* m_gearer;

	GearFactory( const GearFactory& ) = delete;
	GearFactory& operator= ( const GearFactory& ) = delete;
	explicit GearFactory( GearFactory* other ) = delete;
};

} /* namespace Team302 */

#endif /* SRC_GEARFACTORY_H_ */
