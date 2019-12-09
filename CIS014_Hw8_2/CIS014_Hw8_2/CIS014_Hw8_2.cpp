/*
Assignment 8.2
DUE: 11/3/19
PURPOSE: Converts string to integer
*/

#include <string>
#include <iostream>
using namespace std;

int convertString2Integer(string str);

int main()
{
	string str = "-001011";
	cout << convertString2Integer(str);
}

/*
PURPOSE: Converts a string to an integer
PARAMETERS: string str to be converted
RETURN VALUES: integer of converted string
*/

int convertString2Integer(string str)
{
	int newInt = 0, startPos = 0;
	bool isNegative = false; //negative flag

	if (str[0] == '-') //handle negative numbers
	{
		isNegative = true;
		startPos = 1; //increment start point to skip '-' sign
	}

	for (int i = startPos; i < str.length(); i++) //iterate through string
	{
		newInt *= 10; //create space for new int
		newInt += (str[i] - 48); //convert char val to int and add to newInt
	}
	
	return isNegative ? -newInt : newInt; //return newInt or -newInt dependent on isNegative flag
}

/*
Test Cases:
string str = "123";
123

string str = "-123";
-123

string str = "0000012";
12

string str = "-0000000000000124";
-124
*/