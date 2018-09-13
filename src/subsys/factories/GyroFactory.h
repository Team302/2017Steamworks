/*
 * GyroFactory.h
 *
 *  Created on: Mar 27, 2017
 *      Author: Tumtu
 */

#ifndef SRC_SUBSYS_FACTORIES_GYROFACTORY_H_
#define SRC_SUBSYS_FACTORIES_GYROFACTORY_H_

#include <subsys/interfaces/IGyro.h>

namespace Team302 {

class GyroFactory
{
public:

	static GyroFactory* GetInstance();

	IGyro* GetIGyro();

private:

	GyroFactory();
	virtual ~GyroFactory();

	static GyroFactory* m_instance;
		IGyro* m_gyro;

	GyroFactory( const GyroFactory& ) = delete;
	GyroFactory& operator= ( const GyroFactory& ) = delete;
	explicit GyroFactory( GyroFactory* other ) = delete;
};

} /* namespace Team302 */

#endif /* SRC_SUBSYS_FACTORIES_GYROFACTORY_H_ */
