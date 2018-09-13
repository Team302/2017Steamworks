/*
 * TestFactories.h
 *
 *  Created on: Feb 18, 2017
 *      Author: derekw
 */

#ifndef SRC_TEST_TESTFACTORIES_H_
#define SRC_TEST_TESTFACTORIES_H_

namespace Team302
{

	class TestFactories
	{
		public:

			//----------------------------------------------------------------------------------
			// Method:      GetInstance
			// Description: If there isn't an instance of desired class, create it.
			//              Otherwise, hand out the single instance.
			// Returns:     TestFactories*    TestDragonStick singleton
			//----------------------------------------------------------------------------------
			static TestFactories* GetInstance();

			//-----------------------------------------------------------------------
			// Method:		Run
			// Description:	This displays the pass/fail with the factory
			// Returns:		void
			//-----------------------------------------------------------------------
			void Run();


		private:
			static TestFactories* 							m_instance; //make a singleton

			TestFactories() = default;
			virtual ~TestFactories() = default;


	};

} /* namespace Team302 */

#endif /* SRC_TEST_TESTFACTORIES_H_ */
