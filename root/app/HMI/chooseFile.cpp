#include <iostream>
#include <string>
#include <Windows.h>
#include "chooseFile.h"
#include "\Users\great\Documents\GitHub\SD1_ndoherty\root\parse.h"
using namespace std;

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
				tempName = parse(unparsed);
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