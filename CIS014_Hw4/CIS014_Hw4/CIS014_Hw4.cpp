/* 
Assignment #4
DUE: 9-29-19
PURPOSE: Take any arbitrary number, n, and append zero (0) or more numeric digits at the end of it to obtain a palindrome. 
The numeric palindrome should be the shortest, namely having the least number of digits, possible.
Return the integral length of your shortest possible palindrome (NOT your new palindrome) per given input, n. For any non-palindrome n, the function returns 0.
*/
#include <iostream>
#include <string>
using namespace std;

/*
PURPOSE: determines if integer is palindrome, single digit, negative, or not a palindrome
PARAMETERS: integer
RETURN VALUES: bool, true(1) if palindrome or single digit, false(0) if not palindrome or negative
*/
bool palindromeCheckerInt(int input)
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

/*
PURPOSE: determines if string is palindrome
PARAMETERS: string
RETURN VALUES: bool, true if palindrome, false if not palindrome
*/
bool palindromeCheckerString(string s)
{
	if (equal(s.begin(), s.begin() + s.size() / 2, s.rbegin())) //compare first half to second half
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
PURPOSE: determines length of shortest possible palindrome
PARAMETERS: integer
RETURN VALUES: integer value of length of shortest possible palindrome
*/
int getShortestLength(int n)
{
	if (palindromeCheckerInt(n) == 1) //if palindrome already, calculate and return digits
	{
		int numDigits = 0;
		do
		{
			++numDigits;
			n /= 10;
		} while (n);
		return numDigits;
	}

	else if (n < 0) //return 0 for negative numbers
	{
		return 0;
	}

	else //subpalindrome finder 
	{
		string numString = to_string(n); //convert int to string
		string numSubString = "";

		for (int i = 0; i < numString.length() - 1; i++) //iterate starting value along string
		{
			string numSubString = "";

			for (int j = i; j < numString.length(); j++) //create substring of values right of starting value
			{
				numSubString += numString[j];
			}

			if (palindromeCheckerString(numSubString) == 1) //evaluate if substring is palindrome
			{
				return (numString.length() - numSubString.length()) * 2 + numSubString.length(); //if yes, calculate resulting length
			}
		}
		return 2 * numString.length() - 1; //if no subpalindromes
	}
	return 0;
}

int main()
{
	int n;
	cout << "Enter integer: " << endl;
	cin >> n;

	cout << "Shortest palindrome is length: " << getShortestLength(n) << endl;

}

/*
TEST CASES
Enter integer:
-1
Shortest palindrome is length: 0

Enter integer:
7
Shortest palindrome is length: 1

Enter integer:
123454321
Shortest palindrome is length: 9

Enter integer:
985737|589 expect 9
Shortest palindrome is length: 9

Enter integer:
123456|54321 expect 11
Shortest palindrome is length: 11
*/
