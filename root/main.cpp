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
#include "app\HMI\chooseFile.h"
#include "app\HMI\HMI.h"
#include "parse.h"
/*
** Access to System components:
*/


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
//bool chooseFile(string[10]);
int countLOC(ifstream & file);
//bool HMI();
//string parser(string&);

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
	int total = 0;
	int totals[10] = { {0} };
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
						lines = countLOC(inputFile);
						inputFile.close();
						cout << "Closing file" << endl;
						totals[i] = lines;
						cout << "*Total LOC: " << lines << endl << endl << endl;
					}

				}
				else
				{
					for (int x = 0; x < 10; x++)
					{
						total += totals[x];
					}
					cout << "All files counted" << endl << "Total LOC: " << total << endl;
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


int countLOC(ifstream & content)
{
	int count = 0;
	int line = 0;
	string current;
	bool block = 0;
	string valid = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!#%^&()-_=+{}*[]\\|\'\"<>,.?";
	string blockStart = "/*";
	string blockEnd = "*/";
	string lineComment = "//";
	int nul = 999;
	do
	{
		//Get current line
		getline(content, current);

		//cout << current << endl;

		int blockStartPos = current.find(blockStart, 0);
		if (blockStartPos == -1)
		{
			blockStartPos = nul;
		}
		int blockEndPos = current.find(blockEnd, 0);
		if (blockEndPos == -1)
		{
			blockEndPos = nul;
		}
		int lineCommentPos = current.find(lineComment, 0);
		if (lineCommentPos == -1)
		{
			lineCommentPos = nul;
		}
		int validChar = current.find_first_of(valid, 0);
		if (validChar == -1)
		{
			validChar = nul;
		}
		

		//Line comment supersedes all else
		if (lineCommentPos != nul && (lineCommentPos < validChar))
		{
			line++;
		}

		//Block comments need to be sorted out
		else if (blockStartPos != nul && block == false)
		{
			if (blockEndPos != nul && blockEndPos > blockStartPos)
			{
				if (current.find_first_of(valid, blockEndPos + 1) != -1)
				{
					line++;
					count++;
				}
				else if (validChar < blockStartPos)
				{
					line++;
					count++;
				}
				else
				{
					line++;
				}
			}
			else if(blockStartPos < lineCommentPos && blockStartPos < validChar)
			{
				line++;
				block = true;
			}
			else
			{
				line++;
				count++;
				block = true;
			}
		}

		//Current block comment
		else if (block == true)
		{
			if (blockEndPos != nul)
			{
				if (blockEndPos < validChar && validChar != nul)
				{
					line++;
					count++;
				}
				else
				{
					line++;
				}
				block = false;
			}
			
			else
			{
				line++;
			}
		}

		//blank line
		else if (block == false && blockStartPos == nul && lineCommentPos == nul && validChar == nul)
		{
			line++;
		}

		//If not all of the above, line must be valid
		else
		{
			line++;
			count++;
		}

	} while (!content.eof());
	return count;
}

/**
 * @}
 */ // group MAIN

/**
 * @}
 */ // group PROJ_SD1

/******************************* END OF FILE **********************************/
