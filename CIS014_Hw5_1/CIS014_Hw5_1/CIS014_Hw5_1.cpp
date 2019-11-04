/*
 Assignment 5.1
 DUE: 10/6/19
 PURPOSE:function that compares the two version strings, ver1 and ver2,
 of a software product to determine which product version is the latest 
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
PURPOSE: compares two version strings ver1 and ver2, returns 1 if ver1 is newer, -1 if ver2 is newer, and 0 if they're the same
PARAMETERS: strings ver1 and ver2
RETURN VALUES: int 1, -1 or 0
*/
int compareVersions(string ver1, string ver2)
{
	vector<int> vecV1  = {}; //initialize empty vectors
	vector<int> vecV2 = {};

	string temp1 = "0"; //initialize temp strings
	string temp2 = "0";
	
	for (int i = 0; i < ver1.length(); i++) //iterate along version string
	{
		temp1 += ver1[i]; //add first number to temp string

		if (ver1[i] == '.') //detect token '.'
		{
			vecV1.emplace_back(stoi(temp1)); //convert string to int and add to vector
			temp1 = "0"; //reset temp string
		}
	}
	vecV1.emplace_back(stoi(temp1)); //handles last version number in string

	for (int i = 0; i < ver2.length(); i++)
	{
		temp2 += ver2[i];

		if (ver2[i] == '.')
		{
			vecV2.emplace_back(stoi(temp2));
			temp2 = "0";
		}
	}
	vecV2.emplace_back(stoi(temp2));

	/*cout << "Vector1: " << endl;
	for (int i = 0; i < vecV1.size(); i++)
	{
		cout << vecV1[i] << endl;
	}
	cout << "Vector2: " << endl;
	for (int i = 0; i < vecV2.size(); i++)
	{
		cout << vecV2[i] << endl;
	}*/

	for (int i = 0; i < vecV1.size(); i++) { //iterate along vector vecV1
		if (vecV1[i] > vecV2[i]) //compare version numbers between dots
		{
			return 1;
		}
		if (vecV1[i] < vecV2[i])
		{
			return -1;
		}
	}
	return 0;
}

int main()
{
	string str1 = ".9";
	string str2 = ".9.1";
	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl;
	cout << "Version compare returned: " << compareVersions(str1, str2) << endl;
}

/*
TEST CASES
str1: .1.4.3.0.1
str2: 0.1.4.3.0.2
Version compared return: -1

str1: 0.3
str2: 0.2
Version compare returned: 1

str1: 3.1.1
str2: 4
Version compare returned: -1

str1: .2
str2: .1.1
Version compare returned: 1

str1: .0.4
str2: .1.
Version compare returned: -1

str1: 1.1
str2: 1.1.0
Version compare returned: 0
*/