/** ****************************************************************************
** @brief
** <h2>COPYRIGHT &copy; 2017 ESBOK, All Rights Reserved </h2>
**
** The above copyright notice, subsequent disclaimer and any permission notice
** shall be included in all copies or substantial portions of the Template. 
**
*******************************************************************************/

/**
 *  @defgroup MAIN
 */

/** ****************************************************************************
** @brief Title          Main Code file
** @file                 main.c
** @author               Benjamin D. Sweet, Teknowledge LLC, ESBOK
** @date                 09/26/2017
** @version              2.0.0
**
** Module Description:
** @brief
**   Provides main() function, System_Init() and System_Task() function for project.
**
** @attention <b>DISCLAIMER:</b>
** THIS SOFTWARE IS PROVIDED BY Teknowledge, LLC "AS IS" AND ANY EXPRESSED OR IMPLIED 
** WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
** OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
** IN NO EVENT SHALL THE AUTHOR, TEKNOWLEDGE LLC, ESBOK OR THEIR CONTRIBUTORS
** BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, 
** OR CONSEQUENTIAL DAMAGES
** (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
** SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
** HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
** STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
** IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
** THE POSSIBILITY OF SUCH DAMAGE.
**
*******************************************************************************/

/** ****************************************************************************
** @paragraph
** <b> Revision History: </b><br>
**
** Revision: 2.0.0  26-Sep-2017   B. Sweet
** - Removed System_Init() and System_Task().
** - Added printProductName() and printVersionNumber().
** - Replaced "Forever" loop [for ( ; ; ) ] with
**   do{}while (HMI_Prompt_ContinueState() == TRUE);
**
** Revision: 1.8.0  18-Mar-2017   B. Sweet
** - Applied ESBOK file format.
**
** Revision: 1.7    16-May-2013   B. Sweet
** - Update comment blocks for Doxygen.
**
** Revision: 1.6    26-May-2012   B. Sweet
** - Move #includes and prototypes to main.h for consistency.
**
** Revision: 1.5    04-May-2012   B. Sweet
** - Add multiple rate System Tasks: 1 ms, 5 ms, 10 ms.
**
** Revision: 1.4    21-Apr-2012   B. Sweet
** - Replace "Dumb" Wait loop with Task Timer.
** - Adjust Path for Driver components (TARGET_S12UB).
**
** Revision: 1.3    26-Sep-2010   B. Sweet
** - For TARGET_PC, before "forever" loop call IO_Mgr_OutputTask() to display
**   initial values for system states, inputs, and outputs.
**
** Revision: 1.2    11-Sep-2010   B. Sweet
** - Add Keyboard Simulation components.
** - Add MMC (Main Machine Controller) application component.
**
** Revision: 1.1    10-Jun-2008   B. Sweet
** - In main(), added varialble "wait" loop after calling System_Task() to 
**   allow for time to pass between Task iterations.
**
** Revision: 1.0     6-Jun-2008   B. Sweet
** - Working baseline.
**
*******************************************************************************/

/******************************************************************************
* Includes
*******************************************************************************/
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
/*
** Access to System components:
*/
#include "_Version\version.h"


using namespace std;


/** @addtogroup PROJ_SD1
 *  @{
 */

/** @addtogroup MAIN
 *  @{
 */

/*******************************************************************************
* Module Typedefs
*******************************************************************************/

/*******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/*******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/*******************************************************************************
* Module Constants
*******************************************************************************/

/*******************************************************************************
* Module Private Variables
*******************************************************************************/

/*******************************************************************************
* Module Private Function Prototypes
*******************************************************************************/
bool chooseFile(string[10]);
int LOCCounter(ifstream&);
bool HMI();
string parser(string&);

/*******************************************************************************
* Module Private Function Definitions
*******************************************************************************/

/*******************************************************************************
* Module Public Function Definitions
*******************************************************************************/


/*******************************************************************************
* Module Public Function Definitions
*******************************************************************************/
/** ****************************************************************************
** @function  main()
**
** @brief <b> Function Description: </b><br>
** - System initialization and "forever" loop.
**
********************************************************************************
** PRE-CONDITIONS:
** - \todo  Update list of Pre-Conditions before executing main().
**
** POST-CONDITIONS:
** - none
**
** @param [in]      None
**
** @param [out]     None
**
** @param [in,out]  None
**
** @return          None
**
********************************************************************************
** @description <b> Detailed Description: </b><br>
** main(): Main program loop.
** - Returns (void)
**
********************************************************************************
** <b> Usage Example: </b>
** @code
**    main();
**
** @endcode
**
********************************************************************************
** Called Functions:
** @see printProductName()
** @see printVersionNumber()
** @see HMI_Prompt_ContinueState()
**
*******************************************************************************/
int main()
{


	//Declarations
	int lines;
	bool selected;
	string fileNames[10];
	ifstream inputFile;

	do
	{
		cout << "Please choose the file(s) you would like to count. (Limit of 10)" << endl << "*Note: If more than 10 files are selected, the program will count only the first 10!" << endl;
		system("pause");
		system("cls");

		selected = chooseFile(fileNames);

		if (selected == 1)
		{
			cout << endl << endl << "Ready to begin counting" << endl;
			system("pause");
			system("cls");

			for (int i = 0; i < 10; i++)
			{
				if (fileNames[i] != "")
				{
					cout << "*Counting " << fileNames[i] << endl;
					inputFile.open(fileNames[i]);
					if (inputFile.fail())
					{
						cout << fileNames[i] << " could not be opened" << endl;
					}
					else
					{
						cout << "File opened successfully" << endl;
						lines = LOCCounter(inputFile);
						inputFile.close();
						cout << "Closing file" << endl;
						cout << "*Total LOC: " << lines << endl << endl << endl;
					}

				}
				else
				{
					cout << "All files counted" << endl;
					break;
				}
			}
		}

		else
		{
			cout << "No files selected" << endl;
		}

		//reset variables
		selected = 0;
		for (int c = 0; c < 10; c++)
		{
			fileNames[c] = "";
		}

		system("pause");
	} while (HMI() == true);
	return 0;
}

bool chooseFile(string names[10])
{
	bool flag;
	string unparsed, tempName, directory;
	char filename[1024] = { 0 };
	OPENFILENAME openfile = { 0 };
	openfile.lStructSize = sizeof(openfile);
	openfile.lpstrFile = filename;
	openfile.nMaxFile = 1024;
	openfile.lpstrFilter = "All\0*.*\0C Main\0*.C\0C++ Main\0*.cpp\0Text\0*.TXT\0Header\0*.h";
	openfile.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_ALLOWMULTISELECT | OFN_EXPLORER;

	flag = GetOpenFileName(&openfile);
	if (flag == 0)
	{
		cout << "Process cancelled by user" << endl;
	}
	else
	{
		//ifstream file(openfile.lpstrFile, ios::in);

		//getline(openfile.lpstrFile, unparsed);

		//Grab the file path
		int x = 0;
		bool nullFlag = 0;
		int fileAmount = 0;
		do
		{
			if (openfile.lpstrFile[x] == '\0')
			{
				if (nullFlag == 1)
				{
					break;
				}

				openfile.lpstrFile[x] = '/';
				nullFlag = 1;
				fileAmount++;
			}
			else
				nullFlag = 0;
			x++;
		} while (x <= strlen(openfile.lpstrFile));
		unparsed = openfile.lpstrFile;

		//Grab the directory path
		directory = unparsed.substr(0, unparsed.find_first_of('/', 0));
		unparsed.erase(0, unparsed.find_first_of('/', 0) + 1);

		cout << "You selected:" << endl;
		if (fileAmount > 1)
		{
			for (int i = 0; i < 10; i++)
			{
				tempName = parser(unparsed);
				if (tempName == "")
					break;
				else
				{
					names[i] = directory + '\\' + tempName;
					cout << names[i].c_str() << endl;
				}
			}
		}
		else
		{
			names[0] = directory;
			cout << names[0].c_str() << endl;
		}


	}
	return flag;
}

int LOCCounter(ifstream & content)
{
	int count = 0;
	int line = 0;
	string current;
	int block = 0;
	do
	{
		//Get current line
		getline(content, current);
		string valid = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890`~!@#$%^&*()-_=+{}[]\\|\'\"<>,./?";
		char blockStart = '/*';
		char blockEnd = '*/';
		char lineComment = '//';



		//block comments
		if (current.find(blockStart, 0) != NULL || current.find(blockEnd, 0) != NULL)
		{
			//block comment starting after valid line
			if (current.find_first_of(blockStart, 0) > current.find_first_of(valid, 0))
			{
				line++;
				block++;
				count++;
				cout << "Line " << line << "is a block comment starting after valid code\t" << current << endl;
			}
			//Beginning of a block comment
			else if (current.find_first_of(blockStart, 0) < current.find_first_of(valid, 0) && block < 1)
			{
				line++;
				block++;
				cout << "Line " << line << " is the start of a block comment" << "\t" << current << endl;
			}
			//Starting another block within the block
			else if (current.find_first_of('/*', 0) >= 0 && block > 0)
			{
				line++;
				block++;
				cout << "Line " << line << "is a block comment starting another block comment\t" << current << endl;
			}
			//block comment ending before more text
			else if (current.find_first_of('*/', 0) < current.find_first_of(valid, 0))
			{
				line++;
				block--;
				count++;
				cout << "Line " << line << "is a block comment ending before valid code\t" << current << endl;
			}
			//Ending a block comment within a block comment
			else if (current.find_first_of(blockEnd, 0) != NULL && block > 1)
			{
				line++;
				block--;
				cout << "Line " << line << "is a block comment ending another block comment\t" << current << endl;
			}
			//regular block comment
			else if (current.find_first_of("\'/*\', \'*/\'", 0) == NULL)
			{
				line++;
				cout << "Line " << line << "is a block comment\t" << current << endl;
			}
		}

		//line comment
		else if (current.find_first_of(valid, 0) > current.find_first_of(lineComment, 0))
		{
			line++;
			cout << "Line " << line << " is a line comment" << "\t" << current << endl;
		}

		//line comment after valid line
		else if (current.find_first_of(valid, 0) < current.find_first_of("//", 0) || current.find_first_of(valid, 0) < current.find_first_of("///", 0))
		{
			line++;
			count++;
			cout << "Line " << line << " is valid with comment" << "\t" << current << endl;
		}

		//empty line
		else if (current.find(valid) == NULL && current.find(blockStart) == NULL && current.find(blockEnd) == NULL)
		{
			line++;
			cout << "Line " << line << " is empty" << "\t" << current << endl;
		}

		//valid line
		else
		{
			line++;
			count++;
			cout << "Line " << line << " is valid code\t\t" << current << endl;
		}

	} while (!content.eof());
	return count;
}

bool HMI()
{
	/*bool not;
	string input;
	cout << endl << endl;
	cout << "Would you like to submit more files for counting?" << endl;
	cin.clear();
	getline(cin, input);*/
	if (MessageBoxA(NULL, "Would you like to count more files?", "Continue?", MB_YESNO) == IDYES)
	{
		return true;
	}
	else
		return false;
}

string parser(string & names)
{
	string temp;

	temp = names.substr(0, names.find_first_of('/', 0));
	names.erase(0, names.find_first_of('/', 0) + 1);
	return temp;
}

/**
 * @}
 */ // group MAIN

/**
 * @}
 */ // group PROJ_SD1

/******************************* END OF FILE **********************************/
