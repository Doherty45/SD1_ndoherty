#include <iostream>
#include <string>
#include "parse.h"
using namespace std;

string parse(string & names)
{
	string temp;

	temp = names.substr(0, names.find_first_of('/', 0));
	names.erase(0, names.find_first_of('/', 0) + 1);
	return temp;
}