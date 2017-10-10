#include <Windows.h>
#include "chooseFile.h"
using namespace std;
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