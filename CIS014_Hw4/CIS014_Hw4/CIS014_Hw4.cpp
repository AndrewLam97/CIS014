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
	vector<int> inputDigits;

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
		while (input)
		{
			inputDigits.push_back(input % 10);
			input /= 10;
		}
		reverse(inputDigits.begin(), inputDigits.end());

		for (int i = 0; i < inputDigits.size(); i++)
		{
			if (inputDigits[i] != inputDigits[inputDigits.size() - i])
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
	}
}

int getShortestLength(int n)
{
	return 0;
}

int main()
{
	int x = 123;
	cout << palindromeChecker(x);
}


