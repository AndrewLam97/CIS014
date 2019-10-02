/*
Assignment #4.2
DUE: 9-29-19
PURPOSE: Iteratively sanitize all consecutive duplicates in a C++ string. Run as many iterations as needed until no consecutive duplicates remain.
If the string is empty, return "Empty"
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
PURPOSE: Sanitizes consecutive duplicates in a C++ string
PARAMETERS: string
RETURN VALUES: sanitized string or "Empty"
*/
string deduplicate(string input)
{
	vector<char> inputVector(input.begin(), input.end()); //create vector from string

	while (true)
	{
		vector<char> origVector(inputVector); //create copy of vector to compare against

		for (int i = 0; i < inputVector.size() - 1; i++) //iterate along vector 
		{
			if (inputVector.empty() == 1) //if empty vector, return "Empty" string
			{
				return "Empty";
			}
			if (inputVector[i] == inputVector[i + 1]) //if consecutive elements are identical, remove elements
			{
				inputVector.erase(inputVector.begin() + i);
				inputVector.erase(inputVector.begin() + i);
			}
		}
		if (origVector == inputVector) //if original vector and subsequent vector are the same, create and return string from vector
		{
			string str(inputVector.begin(), inputVector.end());

			return str;
		}
	}
}


int main()
{
    cout << deduplicate("ZZZAA");
}

/*
TEST CASES
INPUT: ACAABABABBA
EXPECTED: ACBAB
OUTPUT: ACBAB

INPUT: KCCK
EXPECTED: Empty
OUTPUT: Empty

INPUT: KKCCD
EXPECTED: D
OUTPUT: D

INPUT: ZZZAA
EXPECTED: Z
OUTPUT: Z
*/