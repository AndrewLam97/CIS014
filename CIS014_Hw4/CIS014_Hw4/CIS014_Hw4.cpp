// CIS014_Hw4.cpp
// Check if initial input is palindrome
// Check from right to left for largest sub-palindrome
// Find pivot point, check +/- around pivot
// Find # of digits before largest sub palindrome * 2 + sub-palindrome length
// If none, shortest possible is 2x-1
// 

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool palindromeChecker(int input) //returns 1 if palindrome or single digit, 0 if negative or not palindrome
{
	if (input < 0) //less than 0
	{
		return 0;
	}
	else if (input / 10 == 0) //single digit
	{
		return 1;
	}
	else
	{
		int reverseNum = 0, val = input;
		while (input > 0)
		{
			reverseNum = reverseNum * 10 + input % 10;
			input /= 10;
		}
		if (val == reverseNum) //is palindrome
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
	if (palindromeChecker(n) == 1) //if palindrome, calculate and return digits
	{
		int numDigits = 0;
		do
		{
			++numDigits;
			n /= 10;
		} while (n);
		cout << "The shortest palindrome is " << numDigits;
		return numDigits;
	}

	else if (n < 0) //return 0 for negative numbers
	{
		cout << "Negative number" << endl;
		return 0;
	}

	else //subpalindrome finder 
	{
		string numString = to_string(n);
		int pivot = 0;

		cout << "Numstring length: " << numString.length() << endl;
		/*		
		for (int i = numString.length() - 1; i > 0; i--)
		{
			for (int j = 0; j < numString.length() - i; j++)
			{
				cout << i << j << endl;
				if (numString[i - j] != numString[i + j])
				{
					pivot = i;
					cout << "Pivot index " << numString.length() - i << endl;
					cout << "Size around " << j << endl;
					break;
				}
			}
		}
		*/

		for (int i = numString.length() - 2; i > numString.length() / 2; i--)
		{
			for (int j = 1; j < numString.length() - i; j++)
			{
				if (numString[i + j] != numString[i - j])
				{
					cout << "Pivot not found at i= " << i << " and size j= " << j << endl;
				}
				else
				{
					cout << "Pivot FOUND at pivot index i = " << i << " and size j = " << j << endl;
				}
			}
		}
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


