/*
 *	CIS014 HW3
 *	Andrew Lam
 *	DUE: 9-22-19
 *	PURPOSE: Separate all of the 'a' and 'b' in a string to that all the 'a' appear before the 'b' in it.
 */


#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

/*
 *  NAME: separateLetters
 *	PURPOSE: This function separates all 'a' and 'b' in a string so that all 'a' appear before 'b'
 *	PARAMETERS: string containing 'a' and 'b'
 *	RETURN VALUES: sorted string containing 'a' and 'b'
*/
string separateLetters(string input)
{
	int aCounter = 0;
	string result = "";

	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == 'a')
		{
			aCounter++;
		}
	}

	for (int j = 0; j < aCounter; j++)
	{
		result += "a";
	}

	for (int k = input.length() - aCounter; k > 0; k--)
	{
		result += "b";
	}
	
	return result;
}

int main()
{
	string testString = "aaababbaba"; //6a4b
//	cout << testString << endl;
	cout << bool(separateLetters(testString) == "aaaaaabbbb");
}