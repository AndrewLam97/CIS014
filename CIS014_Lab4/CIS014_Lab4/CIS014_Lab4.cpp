/*
Lab 4.2
DUE: 9-29-19
PURPOSE: Given a string consisting of lowercase alphanumeric characters, find the character that occurs length L/2 times.
*/

#include <iostream>
#include <map>
#include <string>
using namespace std;

/*
PURPOSE: Finds and returns lowercase alphanumeric character that occurs L/2 times in the string
PARAMETERS: string s
RETURN VALUES: char
*/
char findHalfDuplicate(string s)
{
	for (int j = 48; j < 58; j++) //numbers
	{
		int counter = 0;

		for (int i = 0; i < s.length(); i++)//increment along string
		{
			if (s[i] == char(j))//check against current char
			{
				counter++;
			}
		}
		if (counter == s.length() / 2) {
			return char(j);
		}
	}
	for(int j= 97; j < 123; j++)//letters
	{
		int counter = 0;

		for (int i = 0; i<s.length(); i++)//increment along string
		{
			if (s[i] == char(j))//check against current char
			{
				counter++;
			}
		}
		if (counter == s.length() / 2) {
			return char(j);
		}
	}
}

int main()
{
	string s = "a2a3a1";
	cout << "Length: " << s.length() << ", '" << findHalfDuplicate(s) << "' appears " << s.length() / 2 << " times." << endl;

}
/*
TEST CASES
INPUT: 1zz23z4z5z67zz
EXPECTED: L=14, z, 7
OUTPUT: Length: 14, 'z' appears 7 times.

INPUT: 1a2a3a4a
EXPECTED: L=8, a, 4
OUTPUT: Length: 8, 'a' appears 4 times.

INPUT: a2a3a1
EXPECTED: L=6, a, 3
OUTPUT: Length: 6, 'a' appears 3 times.
*/

