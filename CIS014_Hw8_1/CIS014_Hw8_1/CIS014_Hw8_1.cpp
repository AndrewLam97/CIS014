/*
Assignment 8.1
DUE: 11/3/19
PURPOSE: Class with member function to reverse an integer while handling overflows
*/

#include <iostream>
#include <climits>
using namespace std;

class CIS14 {
public:
	int reverseInt(int input);
};

/*
PURPOSE: Reverses an integer
PARAMETERS: Integer i to be reversed
RETURN VALUES: integer of reversed value
*/
int CIS14::reverseInt(int input)
{
	bool isNegative = false; //negative flag
	if (input < 0)//make input positive
	{
		isNegative = true; //set negative flag
		input *= -1;
	}

	int prev = 0, temp = 0;
	long long newNum = 0;
	while (input != 0) //iterate until num = 0
	{
		temp = input % 10; //create temp value with last digit
		newNum *= 10; //create space in newNum for temp val
		newNum += temp;
		input /= 10; //truncuate input num using integer division

		if (newNum > INT_MAX) //handles overflow
			return 0;
	}

	return isNegative == 1 ? (int)-newNum : (int)newNum;
}

int main()
{
	int input = 1000000119;
	CIS14 cis14;
	cout << cis14.reverseInt(input);
}

/*
Test Cases:
int input = -1000;
-1

int input = 1000000119;
0

int input = 1234;
4321
*/
