// CIS014_Hw4.cpp
// Check if initial input is palindrome
// Check from right to left for largest sub-palindrome
// Find pivot point, check +/- around pivot
// Find # of digits before largest sub palindrome * 2 + sub-palindrome length
// If none, shortest possible is 2x-1
// 

#include <iostream>
#include <vector>
using namespace std;

bool palindromeChecker(int input)
{
	if (input < 0)
	{
		return 0;
	}
	else if (input / 10 == 0)
	{
		return 1;
	}
	else
	{
		int reverseNum = 0, val = input;
		while (input > 0)
		{
			reverseNum = reverseNum * 10 + input % 10;
			input = input / 10;
		}
		if (val == reverseNum)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

int getShortestLength(int n)
{
	if (palindromeChecker(n) == 1)
	{
		int numDigits = 0;
		do
		{
			++numDigits;
			n /= 10;
		} while (n);
		cout << "The shortest palindrome is " << numDigits;
	}
	return 0;
}

int main()
{
	int n;
	cout << "Enter integer: " << endl;
	cin >> n;

	getShortestLength(n);
	/*
	int x = -12;
	cout << endl << palindromeChecker(x); //expect 0
	x = 0;
	cout << endl << palindromeChecker(x); //expect 1
	x = 3;
	cout << endl << palindromeChecker(x); //expect 1
	x = 12321;
	cout << endl << palindromeChecker(x); //expect 1
	x = 1231;
	cout << endl << palindromeChecker(x); //expect 0
	*/
}


