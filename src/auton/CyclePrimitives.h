/*
 * CyclePrimitives.h
 *
 *  Created on: Jan 21, 2017
 *      Author: Tyler
 */

#ifndef SRC_CYCLEPRIMITIVES_H_
#define SRC_CYCLEPRIMITIVES_H_

#include <auton/IPrimitive.h>
#include <auton/PrimitiveFactory.h>
#include <auton/AutonSelector.h>
#include <string>

namespace Team302
{

    class CyclePrimitives
    {
        public:
            CyclePrimitives();
            virtual ~CyclePrimitives() = default;

            void Init();
            void RunCurrentPrimitive();

        protected:
            void GetNextPrim();
            void RunDoNothing();

        private:
            std::vector<PrimitiveParams*>   m_primParams;
            int                     		m_currentPrimSlot;
            IPrimitive*             		m_currentPrim;
            PrimitiveFactory*       		m_primFactory;
            IPrimitive*             		m_doNothing;
            AutonSelector*          		m_autonSelector;
    };

} /* namespace Team302 */

#endif /* SRC_CYCLEPRIMITIVES_H_ */
