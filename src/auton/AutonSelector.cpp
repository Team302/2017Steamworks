/*
 * AutonSelector.cpp
 *
 *  Created on: Jan 24, 2017
 *      Author: The Realest of Authors and Magic Mike, The destroyer of minds, creator of bad code, and P S Y C H O L O G I C A L	M U R D E R E R.
 */
#include <auton/AutonSelector.h>

#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

#include <dirent.h>
#include <string>
#include <vector>

using namespace std;

namespace Team302
{
	//---------------------------------------------------------------------
	// Method: 		<<constructor>>
	// Description: This creates this object and reads the auto script (CSV)
	//  			files and displays a list on the dashboard.
	//---------------------------------------------------------------------
	AutonSelector::AutonSelector() : m_csvFiles(),
									 m_chooser()
	{
		FindCSVFileNames();
		PutChoicesOnDashboard();
	}

	//---------------------------------------------------------------------
	// Method: 		GetSelectedAutoFile
	// Description: This returns the selected auton file to run.  If it
	//  			returns "Do Nothing", it is indicating no auton should
	//				be run.
	// Returns:		std::string			auton file to run
	//---------------------------------------------------------------------
	std::string AutonSelector::GetSelectedAutoFile()
	{
		return m_chooser.GetSelected();
	}

	//---------------------------------------------------------------------
	// Method: 		FindCSVFileNames
	// Description: This builds up a list of CSV files in the directory and
	//				stores them in the m_csvFiles attribute.
	// Returns:		void
	//---------------------------------------------------------------------
	void AutonSelector::FindCSVFileNames()
	{
		DIR* directory;
		struct dirent* files;

		directory = opendir("/home/lvuser/auton/");
		if (directory != nullptr)
		{
			bool moreFiles = true;
			while (moreFiles)
			{
				files = readdir(directory);
				if (files == nullptr)
				{
					moreFiles = false;
					break;
				}
				// TODO:: validate it is a CSV files
				m_csvFiles.emplace_back(string(files->d_name));
			}
		}
		else
		{
			// error condition need to handle
		}
	}

	//---------------------------------------------------------------------
	// Method: 		PutChoicesOnDashboard
	// Description: This puts the list of files in the m_csvFiles attribute
	//				up on the dashboard for selection.
	// Returns:		void
	//---------------------------------------------------------------------
	void AutonSelector::PutChoicesOnDashboard()
	{
		m_chooser.AddDefault(DEFAULT_TO_PEG, DEFAULT_TO_PEG);
		for (unsigned int inx = 0; inx < m_csvFiles.size(); ++inx)
		{
			if(m_csvFiles[inx] != "." && m_csvFiles[inx] != "..")
			{
				m_chooser.AddObject( m_csvFiles[inx], m_csvFiles[inx]);
			}
		}

		frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
	}
}
