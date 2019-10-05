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

int compareVersions(string ver1, string ver2)
{
	vector<int> vecV1  = {};
	vector<int> vecV2 = {};

	string temp1 = "0";
	string temp2 = "0";
	

	for (int i = 0; i < ver1.length(); i++)
	{
		temp1 += ver1[i];

		if (ver1[i] == '.')
		{
			vecV1.emplace_back(stoi(temp1));
			temp1 = "0";
		}
	}
	vecV1.emplace_back(stoi(temp1));

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

	cout << "Vector1: " << endl;
	for (int i = 0; i < vecV1.size(); i++)
	{
		cout << vecV1[i] << endl;
	}
	cout << "Vector2: " << endl;
	for (int i = 0; i < vecV2.size(); i++)
	{
		cout << vecV2[i] << endl;
	}

	if (vecV1 == vecV2)
	{
		return 0;
	}

	for (int i = 0; i < vecV1.size(); i++) {
		if (vecV1[i] > vecV2[i])
		{
			return 1;
		}
		if (vecV1[i] < vecV2[i])
		{
			return -1;
		}
	}
}

int main()
{
	string str1 = ".1.4.3.0.1";
	string str2 = "0.1.4.3.0.1";
	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl;
	cout << "Version compared return: " << compareVersions(str1, str2) << endl;
}
