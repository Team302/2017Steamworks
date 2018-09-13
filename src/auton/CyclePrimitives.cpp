/*
 * CyclePrimitives.cpp
 *
 *  Created on: Jan 21, 2017
 *      Author: Tyler the bad man :)
 */

#include <auton/CyclePrimitives.h>
#include <auton/PrimitiveFactory.h>
#include <auton/AutonSelector.h>
#include<SmartDashboard/SmartDashboard.h>

namespace Team302
{
    CyclePrimitives::CyclePrimitives() : m_primParams(),
                                         m_currentPrimSlot(0),
                                         m_currentPrim(nullptr),
                                         m_primFactory(PrimitiveFactory::GetInstance()),
                                         m_doNothing(nullptr),
                                         m_autonSelector(new AutonSelector())
    {
    }

    void CyclePrimitives::Init()
    {
        m_currentPrimSlot = 0; //Reset current prim
        m_primParams.clear();
//        frc::SmartDashboard::PutString("wat is in the default do nothing? NOBODEY KNEOWS", m_autonSelector->GetSelectedAutoFile());
        m_primParams = PrimitiveParser::Parse(m_autonSelector->GetSelectedAutoFile());
//        frc::SmartDashboard::PutNumber("Number of Steps in the Sequence", m_primParams.size());
        if (!m_primParams.empty())
        {
//            frc::SmartDashboard::PutNumber("Running Prim Number ", m_currentPrimSlot );
            GetNextPrim();
        }
//        m_currentPrim->Init()
    }

    void CyclePrimitives::RunCurrentPrimitive()
    {
        if (m_currentPrim != nullptr)
        {
//            frc::SmartDashboard::PutNumber("Running Prim Number ", m_currentPrimSlot );
            m_currentPrim->Run();
            if (m_currentPrim->IsDone())
            {
               GetNextPrim();
            }
        }
        else
        {
//            frc::SmartDashboard::PutString("End of Prims ", "Do Nothing" );
            m_primParams.clear();	// clear the primitive params vector
            m_currentPrimSlot = 0;  //Reset current prim slot
            RunDoNothing();
        }

    	SmartDashboard::PutBoolean("IsDone" , m_currentPrim->IsDone());
    }

    void CyclePrimitives::GetNextPrim()
    {
        PrimitiveParams* currentPrimParam = (m_currentPrimSlot < (int)m_primParams.size()) ? m_primParams[m_currentPrimSlot] : nullptr;

        m_currentPrim = (currentPrimParam != nullptr) ? m_primFactory->GetIPrimitive(currentPrimParam) : nullptr;
        if (m_currentPrim != nullptr)
        {
            m_currentPrim->Init(currentPrimParam);
        }

        m_currentPrimSlot++;
    }

    void CyclePrimitives::RunDoNothing()
    {
        if (m_doNothing == nullptr)
        {
            auto params = new PrimitiveParams(PrimitiveFactory::DO_NOTHING, 100000, 0.0, 0.0, 0.0, false, 0.0, false, false);
            m_doNothing = m_primFactory->GetIPrimitive(params);
            m_doNothing->Init(params);
        }

        m_doNothing->Run();
    }

} /* namespace Team302 */
