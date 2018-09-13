/*
 * AutonSelector.h
 *
 *  Created on: Jan 24, 2017
 *      Author: The Realest of Authors and Magic Mike Wazowski, creator of bad code, and destroyer of minds.
 */

#include <string>
#include <vector>
#include <SmartDashboard/SendableChooser.h>

#ifndef SRC_AUTON_AUTONSELECTOR_H_
#define SRC_AUTON_AUTONSELECTOR_H_

//#define AUTON_DIRECTORY "/home/lvuser/auton/"

namespace Team302
{
	class AutonSelector
	{
		public:
			//---------------------------------------------------------------------
			// Method: 		<<constructor>>
			// Description: This creates this object and reads the auto script (CSV)
			//  			files and displays a list on the dashboard.
			//---------------------------------------------------------------------
			AutonSelector();

			//---------------------------------------------------------------------
			// Method: 		<<destructor>>
			// Description: default cleanup
			//---------------------------------------------------------------------
			virtual ~AutonSelector() = default;

			//---------------------------------------------------------------------
			// Method: 		GetSelectedAutoFile
			// Description: This returns the selected auton file to run.  If it
			//  			returns "Do Nothing", it is indicating no auton should
			//				be run.
			// Returns:		std::string			auton file to run
			//---------------------------------------------------------------------
			std::string GetSelectedAutoFile();
			//This is the directory that the auton sequence files are stored in

		private:

			//---------------------------------------------------------------------
			// Method: 		FindCSVFileNames
			// Description: This builds up a list of CSV files in the directory and
			//				stores them in the m_csvFiles attribute.
			// Returns:		void
			//---------------------------------------------------------------------
			void FindCSVFileNames();

			//---------------------------------------------------------------------
			// Method: 		PutChoicesOnDashboard
			// Description: This puts the list of files in the m_csvFiles attribute
			//				up on the dashboard for selection.
			// Returns:		void
			//---------------------------------------------------------------------
			void PutChoicesOnDashboard();

			// Attributues
			std::vector<std::string> m_csvFiles;
			frc::SendableChooser<std::string> m_chooser;
			const std::string DEFAULT_TO_PEG = "DON'T USE ME PLEASE!!!!!!!!";
	};
}

#endif
